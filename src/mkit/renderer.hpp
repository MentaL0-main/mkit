#pragma once

#include "shader.hpp"
#include "object2D.hpp"
#include "object3D.hpp"
#include "mesh.hpp"
#include "types.hpp"

#include <GL/glew.h>
#include <SDL3/SDL.h>

namespace mkit {

class renderer {
public:
  renderer() {}
  ~renderer();

  void init(SDL_Window* window);

  [[deprecated]] void triangle();
  
  void draw(object2D& object, shader& sd) {}
  void draw(object3D& object, shader& sd) {}
  void draw(mesh& mh, shader& sd, bool is_skybox=false);

  void clear();
  void clear_color(color clr);
  void swap_buffers(SDL_Window* window);
  
private:
  SDL_GLContext gl_context_;
};

} // namespace mkit
