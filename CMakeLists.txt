cmake_minimum_required(VERSION 2.8)

project(shortest_superstring)

include_directories(./)
include_directories(./include)
include_directories(./source)

add_library(bjlty-algorithm STATIC bjlty-algorithm.h bjlty-algorithm.cpp)

add_library(graph STATIC graph.h graph.cpp)

add_executable(exec main.cpp)

target_link_libraries(exec bjlty-algorithm)

target_link_libraries(exec graph)
