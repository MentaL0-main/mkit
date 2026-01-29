#pragma once

#include "../mkit/window.hpp"
#include "../mkit/input.hpp"

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
};

} // namespace vb
