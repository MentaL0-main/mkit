#include "voidbreach.hpp"

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
  renderer_.init(window_.native_window());
  renderer_.clear_color({0.2f, 0.3f, 0.2f, 1.0f});
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
    
    
    
    render_graphics();
  }
}

void Voidbreach::render_graphics() {
  renderer_.clear();


  
  renderer_.swap_buffers(window_.native_window());
}

} // namespace vb
