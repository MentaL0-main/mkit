#pragma once

#include "shader.hpp"

#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

namespace mkit {

void shader::init(const std::string& vertex_path, const std::string& fragment_path) {
  auto readShaderFile = [](const std::string& path) -> std::string {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
      file.open(path);
      std::stringstream stream;
      stream << file.rdbuf();
      file.close();
      return stream.str();
    } catch (std::exception& e) {
      std::cerr << "ERROR::SHADER::FILE_NOT_READ: " << path << std::endl;
      return "";
    }
  };

  std::string vertexCode = readShaderFile(vertex_path);
  std::string fragmentCode = readShaderFile(fragment_path);
    
  if (vertexCode.empty() || fragmentCode.empty()) {
    std::cerr << "Failed to read shader files!" << std::endl;
    return;
  }

  const char* vertexSource = vertexCode.c_str();
  const char* fragmentSource = fragmentCode.c_str();

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);
    
  GLint vSuccess;
  GLchar vInfoLog[1024];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vSuccess);
  if (!vSuccess) {
    glGetShaderInfoLog(vertexShader, 1024, NULL, vInfoLog);
    std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vInfoLog << std::endl;
  }

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);
    
  GLint fSuccess;
  GLchar fInfoLog[1024];
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fSuccess);
  if (!fSuccess) {
    glGetShaderInfoLog(fragmentShader, 1024, NULL, fInfoLog);
    std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fInfoLog << std::endl;
  }

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  GLint linkSuccess;
  GLchar linkInfoLog[1024];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
  if (!linkSuccess) {
    glGetProgramInfoLog(shaderProgram, 1024, NULL, linkInfoLog);
    std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << linkInfoLog << std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  id_ = std::move(shaderProgram);
}

void shader::set(const std::string& name, glm::mat4& data) {
  GLint location = glGetUniformLocation(id_, name.c_str());
        
  if (location == -1) {
    std::cerr << "Uniform '" << name << "' not found in program!" << std::endl;
    return;
  }
        
  glUseProgram(id_);
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
}

void shader::set(const std::string& name, float data) {
  GLint location = glGetUniformLocation(id_, name.c_str());

  if (location == -1) {
    std::cerr << "Uniform '" << name << "' not found in program!" << std::endl;
    return;
  }

  glUseProgram(id_);
  glUniform1f(location, data);
}

} // namespace mkit
