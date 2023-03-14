cmake_minimum_required(VERSION 3.23)
project(Brass)

set(CMAKE_CXX_STANDARD 14)

add_executable(Brass usebrass.cpp include/brass.h src/brass.cpp)
