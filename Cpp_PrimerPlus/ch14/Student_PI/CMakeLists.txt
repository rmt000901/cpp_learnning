cmake_minimum_required(VERSION 3.23)
project(Student)

set(CMAKE_CXX_STANDARD 14)

add_executable(Student use_stuc.cpp include/studentc.h src/student.cpp)
