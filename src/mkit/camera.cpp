#include "camera.hpp"
#include "shader.hpp"

#include <glm/common.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mkit {

void camera::init(glm::vec3 position, float fov, float max_view_distance,
                                      float min_view_distance, float aspect) {
  position_ = position;
  fov_ = fov;
  max_view_distance_ = max_view_distance;
  min_view_distance_ = min_view_distance;
  aspect_ = aspect;

}

void camera::push(shader sd) {
  view_ = glm::lookAt(position_, position_ + forward_, up_);
  projection_ = glm::perspective(fov_, aspect_, min_view_distance_, max_view_distance_);

  sd.set("model", model_);
  sd.set("view", view_);
  sd.set("projection", projection_);
  sd.set("time", time_);
}

} // namespace mkit
