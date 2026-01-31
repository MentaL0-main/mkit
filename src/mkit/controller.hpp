#pragma once

#include "camera.hpp"

namespace mkit {

class controller {
public:
  void process(camera& cam, float speed, const bool* state);

};

}
