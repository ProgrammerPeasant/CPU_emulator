cmake_minimum_required(VERSION 3.27)
project(CPUemulator)

set(CMAKE_CXX_STANDARD 17)

add_library(CPUemulator SHARED library.cpp)
