cmake_minimum_required(VERSION 3.15)
project(OpenCLSample)

# add
# https://qiita.com/trairia/items/cff20cdb779f5ed21437
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
#add_executable(opencl_app src.cpp)
#target_link_libraries(OpenCLSample ${OpenCL_LIBRARIES})
# add end

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenCLSample main.cpp opencl_1.cpp opencl_1.h opencl_0.cpp opencl_0.h opencl_2.h opencl_2.cpp)

# add
target_link_libraries(OpenCLSample ${OpenCL_LIBRARIES})
