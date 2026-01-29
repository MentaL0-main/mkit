#pragma once

namespace mkit {

struct vec2 {
  float x, y;
};

struct vec3 {
  float x, y, z;
};

struct vec4 {
  float x, y, z, a;
};

struct point : public vec2 {};
struct size2 : public vec2 {};
struct color : public vec4 {};

} // namespace mkit
