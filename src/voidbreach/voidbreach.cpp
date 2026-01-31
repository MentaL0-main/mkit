#include "voidbreach.hpp"
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_video.h>
#include <glm/trigonometric.hpp>

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
  renderer_.init(window_.native_window());
  renderer_.clear_color({0.2f, 0.3f, 0.2f, 1.0f});
  shader_.init("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
  camera_.init({0.0f, 1.0f, 2.0f}, glm::radians(45.0f), 500.0f, 0.1f, window_.size().x / window_.size().y);
  skybox.init(vertices_);
  skybox.set_scale(100.0f);
  box.init(vertices_);
  box.set_scale(1.0f);
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

    const bool* state = SDL_GetKeyboardState(NULL);
    controller_.process(camera_, 0.1f, state);

    render_graphics();
  }
}

void Voidbreach::render_graphics() {
  camera_.push(shader_);

  renderer_.clear();
  
  renderer_.draw(skybox, shader_);
  renderer_.draw(box, shader_);
  renderer_.triangle();

  renderer_.swap_buffers(window_.native_window());
}

} // namespace vb
