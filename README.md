# Custom C++ Game Engine - MKit

[![Gameplay Demo](videos/gameplay.mp4)](videos/gameplay.mp4)

A lightweight, modern C++ game engine built from scratch. Features a modular renderer, shader loader, camera system, window abstraction, and renderable meshes.

## Features
- Core Renderer - Efficient OpenGL rendering pipeline
- Camera System - Smooth FPS/perspective controls  
- Shader Loader - Hot-reload GLSL shaders
- Window Abstraction - Cross-platform window + input handling
- Mesh Renderer - Load & render 3D models seamlessly

## Tech Stack
C++20 | OpenGL 3.3 | GLM | SDL3 | GLEW | GLSL
CMake | Git Submodules

## Quick Start

```bash
git clone https://github.com/mental0-main/mkit.git
cd mkit
mkdir build && cd build
cmake .. 
make -j$(nproc)
./mkit
```

## Structure
```
.
├── assets
│   ├── mesh
│   │   └── vertices.hpp
│   ├── models
│   │   └── suzanne.obj
│   └── shaders
│       ├── fragment.glsl
│       ├── skybox_fragment.glsl
│       └── vertex.glsl
├── CMakeLists.txt
├── LINCESE.txt
├── README.md
├── src
│   ├── main.cpp
│   ├── mkit
│   │   ├── camera.cpp
│   │   ├── camera.hpp
│   │   ├── controller.cpp
│   │   ├── controller.hpp
│   │   ├── input.hpp
│   │   ├── mesh.cpp
│   │   ├── mesh.hpp
│   │   ├── object2D.cpp
│   │   ├── object2D.hpp
│   │   ├── object3D.cpp
│   │   ├── object3D.hpp
│   │   ├── renderer.cpp
│   │   ├── renderer.hpp
│   │   ├── shader.cpp
│   │   ├── shader.hpp
│   │   ├── types.hpp
│   │   ├── window.cpp
│   │   └── window.hpp
│   └── voidbreach
│       ├── voidbreach.cpp
│       └── voidbreach.hpp
├── tests
└── videos
    └── gameplay.mp4
```

## Controls

**WASD - Movement**
**UP/DOWN - Down/Up move**
**Mouse - Look around**

## License

**MIT**  
