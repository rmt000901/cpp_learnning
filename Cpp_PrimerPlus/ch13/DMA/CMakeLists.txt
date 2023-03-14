cmake_minimum_required(VERSION 3.23)
project(DMA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DMA usedma.cpp include/dma.h src/dma.cpp)
