cmake_minimum_required(VERSION 3.23)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue bank.cpp queue.cpp include/queue.h)
