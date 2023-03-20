cmake_minimum_required(VERSION 3.23)
project(TV)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(TV
        include/tv.h
        src/tv.cpp
        use_tv.cpp)
