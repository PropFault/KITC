cmake_minimum_required(VERSION 3.23)
project(KITC)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(KITC ./source/main.cpp source/stblibs.cpp)
target_link_libraries(KITC ${CONAN_LIBS})