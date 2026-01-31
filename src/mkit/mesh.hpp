#pragma once

#include <glm/ext/vector_float3.hpp>
#include <vector>
#include <GL/glew.h>

namespace mkit {

class mesh {
public:
  void init(std::vector<float>& vertices);
  inline void set_position(glm::vec3 pos) { position_ = pos; }

  [[nodiscard]] inline GLuint vao() const {
    return vao_;
  } 

  [[nodiscard]] inline GLuint vbo() const {
    return vbo_;
  }

  [[nodiscard]] inline glm::vec3 position() const {
    return position_;
  }

  [[nodiscard]] inline unsigned int vertices_count() const {
    return vertices_count_;
  }

  ~mesh();

private:
  glm::vec3 position_{};
  unsigned int vertices_count_{};
  GLuint vao_{}, vbo_{};
};

}
