#include "camera.hpp"
#include "shader.hpp"

#include <algorithm>
#include <glm/common.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mkit {

void camera::init(glm::vec3 position, float fov, float max_view_distance,
                                      float min_view_distance, float aspect) {
  position_ = position;
  yaw_ = 0.0f;
  pitch_ = 0.0f;
  fov_ = fov;
  max_view_distance_ = max_view_distance;
  min_view_distance_ = min_view_distance;
  aspect_ = aspect;

  update_vectors();
}

void camera::rotate(float yaw_delta, float pitch_delta) {
  yaw_ += yaw_delta;
  pitch_ += pitch_delta;
  
  pitch_ = std::clamp(pitch_, -glm::half_pi<float>() + 0.1f, 
                      glm::half_pi<float>() - 0.1f);
  
  update_vectors();
}

void camera::update_vectors() {
  forward_.x = cos(yaw_) * cos(pitch_);
  forward_.y = sin(pitch_);
  forward_.z = sin(yaw_) * cos(pitch_);
  
  left_ = glm::normalize(glm::cross(forward_, glm::vec3(0,1,0)));
  up_ = glm::cross(left_, forward_);
}

void camera::push(shader& sd) {
  update_vectors();
  view_ = glm::lookAt(position_, position_ + forward_, up_);
  projection_ = glm::perspective(fov_, aspect_, min_view_distance_, max_view_distance_);

  sd.use();
  sd.set("view", view_);
  sd.set("projection", projection_);
}

} // namespace mkit
