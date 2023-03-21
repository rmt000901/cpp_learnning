cmake_minimum_required(VERSION 3.23)
project(queuetp)

set(CMAKE_CXX_STANDARD 14)

add_executable(queuetp nested.cpp include/queuetp.h)
