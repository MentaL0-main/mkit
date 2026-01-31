#include "controller.hpp"
#include "camera.hpp"

#include <SDL3/SDL.h>

namespace mkit {

void controller::process(camera& cam, float speed, const bool* state) {
  if (state[SDL_SCANCODE_W]) {
    cam.move_forward(speed);
  }

  else if (state[SDL_SCANCODE_S]) {
    cam.move_backward(speed);
  }

  if (state[SDL_SCANCODE_A]) {
    cam.move_left(speed);
  }

  else if (state[SDL_SCANCODE_D]) {
    cam.move_right(speed);
  }

  if (state[SDL_SCANCODE_LSHIFT]) {
    cam.move_down(speed);
  }

  else if (state[SDL_SCANCODE_SPACE]) {
    cam.move_up(speed);
  }
}

} // namespace mkit
