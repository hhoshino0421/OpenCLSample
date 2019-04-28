cmake_minimum_required(VERSION 3.14)
project(OpenCLTest)

find_package(OpenCL REQUIRED)

include_directories(${OpenCL_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenCLTest main.cpp LinearSample.cpp Const.h LinearSample.h CLSample.h CLSample.cpp)

target_link_libraries(OpenCLTest ${OpenCL_LIBRARIES})
