#include "voidbreach.hpp"
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_video.h>
#include <glm/trigonometric.hpp>

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
  
  renderer_.init(window_.native_window());
  renderer_.clear_color({0.2f, 0.8f, 0.2f, 1.0f});
  
  skybox_shader_.init("../assets/shaders/vertex.glsl", "../assets/shaders/skybox_fragment.glsl");
  shader_.init("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
  
  camera_.init({0.0f, 1.0f, 2.0f}, glm::radians(45.0f), 300.0f, 0.1f, window_.size().x / window_.size().y);
  
  skybox.init(mkit::cube);
  skybox.set_scale(100.0f);

  box1.init(mkit::cube);
  box1.set_scale(2.0f);
  box1.set_color(glm::vec3(0.0f, 0.0f, 1.0f));
  box1.move(glm::vec3(-1.0f, 0.0f, 0.0f));

  box2.init(mkit::cube);
  box2.set_scale(1.0f);
  box2.set_color(glm::vec3(0.0f, 1.0f, 0.0f));
}

Voidbreach::~Voidbreach() {}

void Voidbreach::run() {
  mainloop();
}

void Voidbreach::mainloop() {
  while (running_) {
    while (SDL_PollEvent(&window_.event)) {
      if (window_.event.type == SDL_EVENT_QUIT) {
        running_ = false;
      }
    }

    float mouse_dx, mouse_dy;
    SDL_GetRelativeMouseState(&mouse_dx, &mouse_dy);    
    camera_.rotate(mouse_dx * 0.002f, -mouse_dy * 0.002f);

    const bool* state = SDL_GetKeyboardState(NULL);
    controller_.process(camera_, 0.1f, state);
    if (state[SDL_SCANCODE_ESCAPE]) running_ = false;

    render_graphics();
  }
}

void Voidbreach::render_graphics() {
  renderer_.clear();

  skybox_shader_.use();
  camera_.push(skybox_shader_);

  glDepthMask(GL_FALSE);
  renderer_.draw(skybox, skybox_shader_, true);
  glDepthMask(GL_TRUE);

  camera_.push(shader_);
  renderer_.draw(box1, shader_);
  renderer_.draw(box2, shader_);

  renderer_.swap_buffers(window_.native_window());
}

} // namespace vb
