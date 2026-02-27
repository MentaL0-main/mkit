#pragma once

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

  void mouse_position(float& x, float& y) const {
    SDL_GetMouseState(&x, &y);
  }

};

} // namespace mkit
