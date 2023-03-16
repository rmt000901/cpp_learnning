cmake_minimum_required(VERSION 3.23)
project(Worker)

set(CMAKE_CXX_STANDARD 14)

add_executable(Worker worktest.cpp include/Worker0.h src/worker0.cpp)
