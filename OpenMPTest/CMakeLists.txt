cmake_minimum_required(VERSION 3.15)
project(OpenMPTest)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenMP REQUIRED)

set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_CXX_LIB_NAMES "omp")

#message(STATUS "OpenMP_C_Found   : ${OpenMP_C_FLAGS}")
#message(STATUS "OpenMP_CXX_Found : ${OpenMP_CXX_FLAGS}")
#message(STATUS "OpenMP_C_LIBRARIES : ${OpenMP_C_LIBRARIES}")
#message(STATUS "OpenMP_CXX_LIBRARIES : ${OpenMP_CXX_LIBRARIES}")

set(CMAKE_C_FLAGS "\${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")

if (CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "\${CMAKE_CXX_FLAGS} -Xpreprocessor ${OpenMP_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS " -Xpreprocessor ${OpenMP_CXX_FLAGS}")
endif(CMAKE_CXX_FLAGS)

#include_directories(/usr/local/opt/libomp/include) #インクルードディレクトリ指定
#link_directories(/usr/local/opt/libomp/lib) #ライブラリディレクトリ指定
#include_directories(${OpenMP_INCLUDE_DIRS})
#message("OpenMP_INCLUDE_DIRS : ${OpenMP_INCLUDE_DIRS}")

#include_directories(/usr/local/include) #インクルードディレクトリ指定
#link_directories(/usr/local/lib) #ライブラリディレクトリ指定

add_executable(OpenMPTest main.cpp normal.h normal.cpp sorted.h sorted.cpp)

target_link_libraries(OpenMPTest ${OpenMP_CXX_LIBRARIES}) #ライブラリとリンク
