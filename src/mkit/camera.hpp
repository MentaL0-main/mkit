#pragma once

#include "shader.hpp"

#include <glm/common.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <ctime>

namespace mkit {

class camera {
public:
  void init(glm::vec3 position, float fov,
            float max_view_distance, float min_view_distance, float aspect);
  
  inline void set_position(glm::vec3 position) {
    position_ = position;
  }

  inline void set_fov(float fov) {
    fov_ = fov;
  }

  inline void set_aspect(float min, float max) {
    min_view_distance_ = min;
    max_view_distance_ = max;
  }

  void push(shader sd);

  [[nodiscard]] inline float aspect() const {
    return aspect_;
  }

  [[nodiscard]] inline float max_view_distance() const {
    return max_view_distance_;
  }

  [[nodiscard]] inline float min_view_distance() const {
    return min_view_distance_;
  }

  [[nodiscard]] inline glm::vec3 position() const {
    return position_;
  }

  inline void move_forward(float speed) {
    position_ += forward_ * speed;
  };

  inline void move_backward(float speed) {
    position_ += -forward_ * speed;
  }

  inline void move_left(float speed) {
    position_ += left_ * speed;
  }

  inline void move_right(float speed) {
    position_ += -left_ * speed;
  }

  inline void move_up(float speed) {
    position_ += up_ * speed;
  }

  inline void move_down(float speed) {
    position_ += -up_ * speed;
  }

private:
  glm::vec3 position_{};
  glm::mat4 view_{};
  glm::mat4 projection_{};
  glm::mat4 model_ = glm::mat4(1.0f);
  glm::vec3 forward_{0.0f, 0.0f, -1.0f};
  glm::vec3 left_{-1.0f, 0.0f, 0.0f};
  glm::vec3 up_{0.0f, 1.0f, 0.0f};

  float fov_ = 0.0f;
  float min_view_distance_ = 0.0f;
  float max_view_distance_ = 0.0f;
  float aspect_ = 0.0f;
  float time_{(float)time(NULL)};
};

} // namespace mkit
