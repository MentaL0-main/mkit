#pragma once

#include "types.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <string>

namespace mkit {

class window {
public:
  window();
  ~window();

  void init(const std::string& caption, int width, int height);
  void set_title(const std::string& title) { title_ = title; }
  void set_size(size2 size) { size_ = size; }
  
  void events();

  [[nodiscard]] SDL_Window* native_window() const { return native_window_; }
  [[nodiscard]] std::string title() const { return title_; };
  [[nodiscard]] size2 size() const { return size_; };

private:
  SDL_Window* native_window_{};
  SDL_Event event_;
  std::string title_{};
  size2 size_{};
};

} // namespace mkit
