#pragma once

#include "../mkit/window.hpp"
#include "../mkit/input.hpp"
#include "../mkit/renderer.hpp"
#include "../mkit/mesh.hpp"
#include "../mkit/camera.hpp"
#include "../mkit/controller.hpp"

namespace vb {

class Voidbreach {
public:
  Voidbreach();
  ~Voidbreach();
  void run();

private:
  float sens_ = 0.002f;

  bool running_ = true;
  
  mkit::window window_{};
  
  mkit::input input_{};
  
  mkit::renderer renderer_{};
  
  mkit::shader skybox_shader_{}, shader_{};
  
  mkit::camera camera_{};
  
  mkit::controller controller_{};
  
  mkit::mesh skybox_{};
  mkit::mesh box_{};
  
  mkit::object3D object_{};

  void mainloop();
  void render_graphics();
};

} // namespace vb
