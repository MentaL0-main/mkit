#include "voidbreach/voidbreach.hpp"

#include <exception>
#include <iostream>

int main() {
  try {
    vb::Voidbreach vb;
    vb.run();
  } catch (std::exception& error_) {
    std::cerr << error_.what() << std::endl;
    return 1;
  }

  return 0;
}
