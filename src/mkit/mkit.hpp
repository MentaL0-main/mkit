#pragma once

#include "scenemanager.hpp"

#include <SDL3/SDL.h>

namespace mkit {

class MKit {
public:
  MKit();
  ~MKit();

  void mainloop();
  void load_scene(Scene* scene);

  SDL_Window* window() const { return window_; }
  SDL_GLContext gl_context() const { return gl_context_; }

private:
  SDL_Window* window_ = nullptr;
  SDL_GLContext glContext_ = nullptr;
  Scene* currentScene_ = nullptr;
  bool running_ = true;
    
  void init();
  void processEvents();
  void update(float delta);
  void render();
  void cleanup();
};

} // namespace mkit
