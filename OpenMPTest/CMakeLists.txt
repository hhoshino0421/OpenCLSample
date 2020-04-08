cmake_minimum_required(VERSION 3.15)
project(OpenMPTest)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenMP REQUIRED)

set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_CXX_LIB_NAMES "omp")

#message(STATUS "OpenMP_C_Found   : ${OpenMP_C_FLAGS}")
#message(STATUS "OpenMP_CXX_Found : ${OpenMP_CXX_FLAGS}")

set(CMAKE_C_FLAGS "\${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

if (CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "\${CMAKE_CXX_FLAGS} -Xpreprocessor ${OpenMP_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS " -Xpreprocessor ${OpenMP_CXX_FLAGS}")
endif(CMAKE_CXX_FLAGS)

add_executable(OpenMPTest main.cpp normal.h normal.cpp sorted.h sorted.cpp)