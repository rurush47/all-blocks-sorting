cmake_minimum_required(VERSION 3.7)
project(all_blocks_sorting)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(algorithm)

set(SOURCE_FILES main.cpp ${ALGORITHM_FILES})
add_executable(all_blocks_sorting ${SOURCE_FILES} algorithm)