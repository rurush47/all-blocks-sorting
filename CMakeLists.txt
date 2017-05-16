cmake_minimum_required(VERSION 3.7)
project(all_blocks_sorting)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp)
include_directories(algorithm)
add_executable(all_blocks_sorting ${SOURCE_FILES})

add_subdirectory(algorithm)
add_subdirectory(algorithm_tests)

target_link_libraries(all_blocks_sorting algorithm)