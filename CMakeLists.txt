cmake_minimum_required(VERSION 2.8)
project(gprint CXX)

file(GLOB_RECURSE gprintSrc src/main/*.cpp)
add_library(gprintLib ${gprintSrc})
target_include_directories(gprintLib PUBLIC src/main)
target_link_libraries(gprintLib gtest)

add_library(gprintGtestMainLib src/gtestMain.cpp)
target_link_libraries(gprintGtestMainLib gprintLib gtest)

add_library(gprintGmockMainLib src/gmockMain.cpp)
target_link_libraries(gprintGmockMainLib gprintLib gtest gmock)
