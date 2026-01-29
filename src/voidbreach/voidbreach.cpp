#include "voidbreach.hpp"

#include <SDL3/SDL_render.h>

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
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

   

  }
}

} // namespace vb
