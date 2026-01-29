#pragma once

#include "shader.hpp"
#include "object2D.hpp"
#include "object3D.hpp"
#include "types.hpp"

#include <SDL3/SDL.h>

namespace mkit {

class renderer {
public:
  renderer(SDL_Window* window);
  ~renderer();

  [[deprecated]] void triangle();
  void draw(object2D& object, shader id) {}
  void draw(object3D& object, shader id) {}

  void clear();
  void clear_color(color clr);
  void swap_buffers(SDL_Window* window);
  
private:
  SDL_GLContext gl_context_;
};

}
