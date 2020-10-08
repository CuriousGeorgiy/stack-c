cmake_minimum_required(VERSION 3.17)
project(stack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(stack)

target_sources(stack PUBLIC main.cpp stack.cpp hash_sum.cpp memory_alloc.cpp canary.cpp)
target_include_directories(stack PUBLIC "${PROJECT_SOURCE_DIR}")
