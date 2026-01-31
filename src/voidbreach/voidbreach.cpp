#include "voidbreach.hpp"
#include <glm/trigonometric.hpp>

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
  renderer_.init(window_.native_window());
  renderer_.clear_color({0.2f, 0.3f, 0.2f, 1.0f});
  shader_.init("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
  camera_.init({0.0f, 1.0f, 2.0f}, glm::radians(45.0f), 100.0f, 0.1f, window_.size().x / window_.size().y);
  mh.init(vertices_);
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
 
    camera_.move_down(0.01f);
    camera_.move_backward(0.01f);
    render_graphics();
  }
}

void Voidbreach::render_graphics() {
  renderer_.clear();
  
  renderer_.draw(mh, shader_);
  
  camera_.push(shader_);

  renderer_.swap_buffers(window_.native_window());
}

} // namespace vb
