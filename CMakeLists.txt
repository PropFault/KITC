cmake_minimum_required(VERSION 3.23)
project(KITC)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(KITC ./source/main.cpp source/libs/stb/stb_image.h source/libs/stb/stb_macro.cpp source/libs/math/random.h source/libs/ecs/component_pool_hash_map.h source/components/data_component.h)
target_link_libraries(KITC ${SDL2_LIBRARIES})