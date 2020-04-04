cmake_minimum_required(VERSION 3.15)
project(MatrixMulti)

set(CMAKE_CXX_STANDARD 14)

add_executable(MatrixMulti main.cpp normal.h normal.cpp sorted.h sorted.cpp)