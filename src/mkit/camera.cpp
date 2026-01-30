#include "camera.hpp"
#include "shader.hpp"

#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ctime>

namespace mkit {

void camera::push(shader sd) {
  sd.set("model", model_);
  sd.set("view", view_);
  sd.set("rpojection", projection_);
  sd.set("time", (float)time(NULL));
}

} // namespace mkit
