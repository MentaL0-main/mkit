#version 330 core

out vec4 FragColor;
uniform mat4 view;

void main() {
  vec3 dir = normalize((inverse(view) * vec4(0,0,1,0)).xyz);
  
  // Градиент: низ темнее, верх светлее
  float t = dir.y * 0.5 + 0.5;  // 0=темно, 1=светло
  
  vec3 darkSky   = vec3(0.4, 0.6, 1.0);  // Темно-голубой низ
  vec3 lightSky  = vec3(0.8, 0.9, 1.0);  // Светло-голубой верх
  
  vec3 sky = mix(darkSky, lightSky, t);
  
  FragColor = vec4(sky, 1.0);
}

