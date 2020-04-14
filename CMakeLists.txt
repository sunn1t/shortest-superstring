cmake_minimum_required(VERSION 3.5)

project(ShortestSuperstring)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -std=c++17 -march=native")

include_directories(./)

add_library(lib STATIC algorithms.h algorithms.cpp graph.h graph.cpp common.h common.cpp tcp.h tcp.cpp)

add_executable(exec tests.cpp main.cpp)

target_link_libraries(exec lib gtest gtest_main pthread)

