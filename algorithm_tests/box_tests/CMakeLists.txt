include_directories(../lib/googletest/googletest/include
        ../lib/googletest/googletest)

add_executable(runBoxTests
        BoxTest.cpp)

target_link_libraries(runBoxTests gtest gtest_main)
target_link_libraries(runBoxTests algorithm)