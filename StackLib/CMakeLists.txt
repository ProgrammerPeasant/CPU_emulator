cmake_minimum_required(VERSION 3.0)
project(StackLibrary)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the header-only library
add_library(Stack INTERFACE)
target_include_directories(Stack INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# You can also specify the C++ features required by your library
target_compile_features(Stack INTERFACE cxx_std_11)