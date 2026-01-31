#version 330 core

out vec4 FragColor;

void main() {
  vec3 dir = normalize(vec3(gl_FragCoord.xy/800.0-0.5, 1.0));
  
  float t = dir.y*0.5+0.5;
  
  vec3 sky = mix(vec3(1,0.7,0.4), vec3(0.2,0.4,0.9), t);
  vec3 sunDir = normalize(vec3(0.7,0.4,1.0));
  
  float sun = smoothstep(0.995,1.0,dot(dir,sunDir))*0.8;
  
  FragColor = vec4(sky + sun*vec3(1,1,0.8), 1.0);
}
