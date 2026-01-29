#include "voidbreach.hpp"

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <iostream>

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

    if (input_.is_key_pressed(SDL_SCANCODE_ESCAPE)) {
      std::cout << "Hello, World\n";
    }

    if (input_.mouse_position().x > 100) {
      std::cout << input_.mouse_position().x << ' ' << input_.mouse_position().y << std::endl;
    }

  }
}

} // namespace vb
