#pragma once

#include "types.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_keyboard.h>

namespace mkit {

class input {
public:
  input() {}
  ~input() {}

  [[nodiscard]] inline bool is_key_pressed(SDL_Scancode scancode) const {
    return SDL_GetKeyboardState(NULL)[scancode];
  }

  [[nodiscard]] inline point mouse_position() const {
    float x, y;
    SDL_GetMouseState(&x, &y);

      return point{x, y};
    }
  };

  }
