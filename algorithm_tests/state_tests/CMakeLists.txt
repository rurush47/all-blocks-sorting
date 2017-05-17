include_directories(../lib/googletest/googletest/include
        ../lib/googletest/googletest)

add_executable(runStateTests
        StateTest.cpp)

target_link_libraries(runStateTests gtest gtest_main)
target_link_libraries(runStateTests algorithm)