#include "window.hpp"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <stdexcept>

namespace mkit {

window::window() {}

window::~window() {
  if (native_window_) SDL_DestroyWindow(native_window_);
  SDL_Quit();
}

void window::init(const std::string& title, int width, int height) {
  title_ = title;
  size_ = size2{(float)width, (float)height};

  // check for initing and init sdl3
  if (!SDL_WasInit(SDL_INIT_VIDEO)) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      throw std::runtime_error(std::string("SDL_Init(): Failed. ") + SDL_GetError());
    }
  }

  native_window_ = SDL_CreateWindow(title_.c_str(), size_.x, size_.y, SDL_WINDOW_OPENGL);
  if (!native_window_) {
    throw std::runtime_error(std::string("SDL_CreateWindow(): Failed. ") + SDL_GetError());
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
}

} // namespace mkit
