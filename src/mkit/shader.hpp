#pragma once

#include <glm/ext/matrix_float4x4.hpp>
#include <string>
#include <GL/glew.h>

namespace mkit {

class shader {
public:
  ~shader() {
    glDeleteProgram(id_);
  }

  void init(const std::string& vertex_path, const std::string& fragment_path);
  void set(const std::string& name, glm::mat4 data);
  void set(const std::string& name, float data);
  void set(const std::string& name, glm::vec3 data);

  inline void use() const {
    glUseProgram(id_);
  }

private:
  GLuint id_{};
};

}
