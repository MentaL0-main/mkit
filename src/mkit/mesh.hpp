#pragma once

#include <glm/detail/qualifier.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <GL/glew.h>

namespace mkit {

class mesh {
public:
  void init(std::vector<float>& vertices);

  inline void set_scale(float scale) {
    model_ = glm::scale(model_, glm::vec3(scale));
  }

  inline void move(glm::vec3 pos_delta) {
    model_ = glm::translate(model_, pos_delta);
  }

  [[nodiscard]] inline GLuint vao() const {
    return vao_;
  } 

  [[nodiscard]] inline GLuint vbo() const {
    return vbo_;
  }

  [[nodiscard]] inline unsigned int vertices_count() const {
    return vertices_count_;
  }

  [[nodiscard]] inline glm::mat4 model() const {
    return model_;
  }

  ~mesh();

private:
  glm::mat4 model_{glm::mat4(1.0f)};
  unsigned int vertices_count_{};
  GLuint vao_{}, vbo_{};
};

}
