cmake_minimum_required(VERSION 3.23)
project(stock)

set(CMAKE_CXX_STANDARD 14)

add_executable(stock include/stock00.h stock00.cpp usestock0.cpp)
