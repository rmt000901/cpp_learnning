cmake_minimum_required(VERSION 3.23)
project(mytime)

set(CMAKE_CXX_STANDARD 14)

add_executable(mytime usetime.cpp include/mytime.h mytime.cpp)
