#include "renderer.hpp"
#include "mesh.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <stdexcept>
#include <string>
#include <GL/glew.h>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mkit {

void renderer::init(SDL_Window* window) {
  if (!SDL_WasInit(SDL_INIT_VIDEO)) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      throw std::runtime_error("SDL_Init(): Failed. " + std::string(SDL_GetError()));
    }
  }

  gl_context_ = SDL_GL_CreateContext(window);
  if (!gl_context_) {
    throw std::runtime_error("SDL_GL_CreateContext(): failed. " + std::string(SDL_GetError()));
  }

  SDL_GL_MakeCurrent(window, gl_context_);
  if (SDL_GL_GetCurrentContext() != gl_context_) {
    throw std::runtime_error("SDL_GL_MakeCurrent(): Failed. " + std::string(SDL_GetError()));
  }

  glewExperimental = true;
  auto err = glewInit();
  if (err != GLEW_OK) {
    throw std::runtime_error("glewInit(): Failed.");
  }

  glEnable(GL_DEPTH_TEST);
}

renderer::~renderer() {
  SDL_GL_DestroyContext(gl_context_);
}

void renderer::clear() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer::clear_color(color clr) {
  glClearColor(clr.x, clr.y, clr.z, clr.a);
}

void renderer::swap_buffers(SDL_Window* window) {
  SDL_GL_SwapWindow(window);
}

void renderer::triangle() {
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
  glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
  glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);
  glEnd();
}

void renderer::draw(mesh& mh, shader& sd) {
  sd.use();
  sd.set("model", mh.model());
  glBindVertexArray(mh.vao());
  glDrawArrays(GL_TRIANGLES, 0, mh.vertices_count());
  glBindVertexArray(0);
} 

} // namespace mkit
