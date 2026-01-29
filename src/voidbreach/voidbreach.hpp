#pragma once

#include "../mkit/window.hpp"
#include "../mkit/input.hpp"
#include "../mkit/renderer.hpp"

#include <memory>

namespace vb {

class Voidbreach {
public:
  Voidbreach();
  ~Voidbreach();
  void run();

private:
  void mainloop();

  bool running_{true};
  
  mkit::window window_;
  mkit::input input_;
  std::unique_ptr<mkit::renderer> renderer_;
};

} // namespace vb
