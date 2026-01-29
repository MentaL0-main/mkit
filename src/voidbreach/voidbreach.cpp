#include "voidbreach.hpp"

namespace vb {

Voidbreach::Voidbreach() {
  window_.init("MKit", 1200, 900);
}

void Voidbreach::run() {
  mainloop();
}

void Voidbreach::mainloop() {
  window_.events();
}

} // namespace vb
