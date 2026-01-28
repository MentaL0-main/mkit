#include "voidbreach/voidbreach.hpp"
#include <exception>

int main() {
  try {
    voidbreach::Voidbreach vb;
  } catch (std::exception& error_) {
    std::cerr << error_.what() << std::endl;
    return 1;
  }

  return 0;
}
