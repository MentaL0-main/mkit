#pragma once

#include "../mkit/window.hpp"

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
};

} // namespace vb
