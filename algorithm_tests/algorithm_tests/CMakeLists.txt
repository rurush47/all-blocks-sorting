include_directories(../lib/googletest/googletest/include
        ../lib/googletest/googletest)

add_executable(runAlgorithmTests
        AlgorithmTest.cpp)

target_link_libraries(runAlgorithmTests gtest gtest_main)
target_link_libraries(runAlgorithmTests algorithm)