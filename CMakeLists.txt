cmake_minimum_required(VERSION 3.20)
project(miraly-tool-kit VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE ALL_SOURCES 
    "src/main.cpp"
    "src/mkit/*.cpp"
    "src/voidbreach/*.cpp"
)

add_executable(mkit ${ALL_SOURCES})

target_include_directories(mkit PUBLIC 
    src/
    include/
    third_party/glm
    third_party/glew/include
)

target_link_libraries(mkit 
    SDL3::SDL3
    GLEW::GLEW
    OpenGL::GL
)

target_compile_definitions(mkit PRIVATE SDL_MAIN_HANDLED)

add_custom_command(TARGET mkit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:mkit>/assets
)
