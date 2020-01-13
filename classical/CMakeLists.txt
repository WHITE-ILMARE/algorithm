cmake_minimum_required(VERSION 3.15)
project(classical)

set(CMAKE_CXX_STANDARD 14)

add_executable(classical main.cpp)
add_executable(KMP KMP.cpp)
add_executable(testreg test-reg.cpp)
add_executable(testreg2 test-reg2.cpp)