#version 330 core
out vec4 FragColor;

void main() {
  vec3 color = vec3(0.4, 0.4, 1.1);
  FragColor = vec4(color, 1.0);
}
