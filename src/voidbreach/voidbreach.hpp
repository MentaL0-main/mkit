#pragma once

#include "../mkit/window.hpp"
#include "../mkit/input.hpp"
#include "../mkit/renderer.hpp"
#include "../mkit/mesh.hpp"
#include "../mkit/camera.hpp"

#include <vector>

namespace vb {

class Voidbreach {
public:
  Voidbreach();
  ~Voidbreach();
  void run();

private:
  void mainloop();

  bool running_{true};
  
  mkit::window window_{};
  mkit::input input_{};
  mkit::renderer renderer_{};
  mkit::shader shader_{};
  mkit::camera camera_{};
  mkit::mesh mh{};

  std::vector<float> vertices_ {
    // Передняя грань
    -0.5f, -0.5f,  0.5f,  // 0
     0.5f, -0.5f,  0.5f,  // 1
     0.5f,  0.5f,  0.5f,  // 2
     0.5f,  0.5f,  0.5f,  // 2
    -0.5f,  0.5f,  0.5f,  // 3
    -0.5f, -0.5f,  0.5f,  // 0

    // Задняя грань
    -0.5f, -0.5f, -0.5f,  // 4
     0.5f, -0.5f, -0.5f,  // 5
     0.5f,  0.5f, -0.5f,  // 6
     0.5f,  0.5f, -0.5f,  // 6
    -0.5f,  0.5f, -0.5f,  // 7
    -0.5f, -0.5f, -0.5f,  // 4

    // Левая грань
    -0.5f, -0.5f, -0.5f,  // 4
    -0.5f, -0.5f,  0.5f,  // 0
    -0.5f,  0.5f,  0.5f,  // 3
    -0.5f,  0.5f,  0.5f,  // 3
    -0.5f,  0.5f, -0.5f,  // 7
    -0.5f, -0.5f, -0.5f,  // 4

    // Правая грань
     0.5f, -0.5f, -0.5f,  // 5
     0.5f, -0.5f,  0.5f,  // 1
     0.5f,  0.5f,  0.5f,  // 2
     0.5f,  0.5f,  0.5f,  // 2
     0.5f,  0.5f, -0.5f,  // 6
     0.5f, -0.5f, -0.5f,  // 5

    // Верхняя грань
    -0.5f,  0.5f, -0.5f,  // 7
    -0.5f,  0.5f,  0.5f,  // 3
     0.5f,  0.5f,  0.5f,  // 2
     0.5f,  0.5f,  0.5f,  // 2
     0.5f,  0.5f, -0.5f,  // 6
    -0.5f,  0.5f, -0.5f,  // 7

    // Нижняя грань
    -0.5f, -0.5f, -0.5f,  // 4
     0.5f, -0.5f, -0.5f,  // 5
     0.5f, -0.5f,  0.5f,  // 1
     0.5f, -0.5f,  0.5f,  // 1
    -0.5f, -0.5f,  0.5f,  // 0
    -0.5f, -0.5f, -0.5f   // 4
  };

  void render_graphics();
};

} // namespace vb
