include_directories(../lib/googletest/googletest/include
        ../lib/googletest/googletest)

add_executable(runGeneratorTests
        GeneratorTest.cpp)

target_link_libraries(runGeneratorTests gtest gtest_main)
target_link_libraries(runGeneratorTests algorithm)