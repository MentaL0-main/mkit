#version 330 core

out vec4 FragColor;

uniform float time;

void main() {
  vec3 color = vec3(0.5, 0.3, 0.3) * (1.0 + 0.2 * sin(time));
  FragColor = vec4(color, 1.0);
}
