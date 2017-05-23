cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(ALGORITHM_FILES Algorithm.h Algorithm.cpp Box.h Box.cpp State.h State.cpp Generator.h Generator.cpp)
add_library(algorithm ${ALGORITHM_FILES})