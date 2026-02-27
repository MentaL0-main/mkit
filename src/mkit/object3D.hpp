#pragma once

#include <GL/glew.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace mkit {

class object3D {
public:
  ~object3D();

  void init(const std::string& path);

  inline void move(glm::vec3 delta_pos) {
    model_ = glm::translate(model_, delta_pos);
  }

  inline void rotate(glm::vec3 axis, float delta) {
    model_ = glm::rotate(model_, delta, axis);
  }

  inline void set_color(glm::vec3 color) {
    color_ = color;
  }

  [[nodiscard]] inline GLuint vao() const {
    return vao_;
  }

  [[nodiscard]] inline unsigned int vertices_count() const {
    return vertices_count_;
  }

  [[nodiscard]] inline glm::mat4 model() const {
    return model_;
  }

  [[nodiscard]] inline glm::vec3 color() const {
    return color_;
  }

private:
  struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
  };

  GLuint vao_{}, vbo_{};
  unsigned int vertices_count_{};

  glm::mat4 model_{glm::mat4(1.0f)};

  glm::vec3 color_{1.0f, 0.0f, 0.0f};
  
  glm::vec3 parseVec3(const std::string& line);
  glm::vec2 parseVec2(const std::string& line);

  bool loadOBJ(const std::string& path,
                       std::vector<Vertex>& vertices);
};

} // namespace mkit
