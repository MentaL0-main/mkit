#version 330 core

in vec3 Normal;
in vec3 WorldPos;

uniform vec3 lightDir = normalize(vec3(2.7, 2.4, 2.0));
uniform vec3 color;

out vec4 FragColor;

void main() {
  vec3 N = normalize(Normal);
  vec3 L = normalize(lightDir);

  float diff = max(dot(N, L), 0.0) * 0.5;

  vec3 ambient = vec3(0.45, 0.4, 0.4) * 1.2;
  vec3 finalColor = color * (ambient + diff * 1.5);
    
  FragColor = vec4(finalColor, 1.0);
}

