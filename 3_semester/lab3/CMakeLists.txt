cmake_minimum_required(VERSION 3.19)
project(lab3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)

enable_testing()

add_executable(lab3 main.cpp graph.h extrafunctions.h)
add_executable(run_main_tests test/actual_tests/main.cpp)
target_link_libraries(run_main_tests gtest gtest_main)
target_link_libraries(run_main_tests gmock gmock_main)