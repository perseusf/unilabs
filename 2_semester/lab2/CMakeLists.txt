cmake_minimum_required(VERSION 3.15)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_executable(lab2 main.cpp src/arraysequence.h src/dynamicarray.h src/linkedlist.h src/listsequence.h src/sequence.h src/vector.h)
add_executable(run_main_tests test/actual_tests/main.cpp)
target_link_libraries(run_main_tests gtest gtest_main)
target_link_libraries(run_main_tests gmock gmock_main)