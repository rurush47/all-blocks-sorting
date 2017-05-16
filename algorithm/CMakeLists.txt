cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(ALGORITHM_FILES Algorithm.cpp Algorithm.h Box.cpp Box.h State.cpp State.h)
add_library(algorithm ${ALGORITHM_FILES})