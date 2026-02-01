#include "object3D.hpp"

#include <string>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <fstream>
#include <cstdio>

namespace mkit {

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
};

glm::vec3 object3D::parseVec3(const std::string& line) {
  glm::vec3 vertex;
  sscanf(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
  return vertex;
}

glm::vec2 object3D::parseVec2(const std::string& line) {
  glm::vec2 uv;
  sscanf(line.c_str(), "vt %f %f", &uv.x, &uv.y);
  return uv;
}

bool object3D::loadOBJ(const std::string& path, std::vector<Vertex>& out_vertices) {
    std::vector<glm::vec3> temp_vertices, temp_normals;
    std::vector<glm::vec2> temp_uvs;
    
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, 2) == "v ") {
            temp_vertices.push_back(parseVec3(line));
        } else if (line.substr(0, 3) == "vt ") {
            temp_uvs.push_back(parseVec2(line));
        } else if (line.substr(0, 3) == "vn ") {  // ✅ ФИКС!
            temp_normals.push_back(parseVec3(line));
        } else if (line[0] == 'f') {
            unsigned int v[3]={0}, t[3]={0}, n[3]={0};
            sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", 
                   &v[0],&t[0],&n[0], &v[1],&t[1],&n[1], &v[2],&t[2],&n[2]);
            
            for (int i = 0; i < 3; i++) {
                if (v[i] && v[i]-1 < temp_vertices.size()) {
                    Vertex vert;
                    vert.position = temp_vertices[v[i]-1];
                    vert.normal = (n[i] && n[i]-1 < temp_normals.size()) ? 
                                 temp_normals[n[i]-1] : glm::vec3(0,1,0);
                    out_vertices.push_back(vert);
                }
            }
        }
    }
    printf("temp_vertices=%zu, temp_normals=%zu, final=%zu\n", 
           temp_vertices.size(), temp_normals.size(), out_vertices.size());
    return true;
}


void object3D::init(const std::string& path) {
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glBindVertexArray(vao_);

  std::vector<Vertex> vertices;
  loadOBJ(path, vertices);

  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    
  size_t stride = 6 * sizeof(float);
    
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));  
  glEnableVertexAttribArray(1);
    
  glBindVertexArray(0);
  vertices_count_ = vertices.size();
}

object3D::~object3D() {
    glDeleteBuffers(1, &vbo_);
    glDeleteVertexArrays(1, &vao_);
}

}

