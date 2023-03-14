cmake_minimum_required(VERSION 3.23)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack stacker.cpp include/stack.h stack.cpp)
