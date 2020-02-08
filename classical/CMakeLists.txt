cmake_minimum_required(VERSION 3.15)
project(classical)

set(CMAKE_CXX_STANDARD 14)

add_executable(classical main.cpp)
add_executable(KMP KMP.cpp)
add_executable(correct correct.cpp)
add_executable(dijkstra dijkstra.cpp)
add_executable(bfs-map bfs-map.cpp)