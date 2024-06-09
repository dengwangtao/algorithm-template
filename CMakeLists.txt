cmake_minimum_required(VERSION 3.15)

project(algorithm_template)


set (CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/线段树)
include_directories(${PROJECT_SOURCE_DIR}/字符串哈希)
include_directories(${PROJECT_SOURCE_DIR}/堆_heap)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(main main.cpp)

