cmake_minimum_required(VERSION 2.8)
project(gtest-output CXX)

set(DIR_SRC_MAIN src/main)
file(GLOB_RECURSE files_src_main ${DIR_SOURCE_MAIN}/*.cpp)
add_library(gtest_output2 ${files_src_main})
include_directories(gtest_output2 ${DIR_SOURCE_MAIN})
target_link_libraries(gtest_output2 gtest gtest)

add_library(gtest_output_main src/Main.cpp)
target_link_libraries(gtest_output_main gtest_output)
