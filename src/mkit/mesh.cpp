#include "mesh.hpp"

#include <vector>

namespace mkit {

void mesh::init(std::vector<float>& vertices) {
  vertices_count_ = vertices.size() / 3;

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);

  glBindVertexArray(vao_);

  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0);
}

mesh::~mesh() {
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
}

}
