cmake_minimum_required(VERSION 3.15)
project(OpenCLMatrixCalc)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCL REQUIRED)

add_executable(OpenCLMatrixCalc main.cpp matrixcalc.h matrixcalc.cpp info.h info.cpp)

target_link_libraries(OpenCLMatrixCalc ${OpenCL_LIBRARIES})