cmake_minimum_required(VERSION 3.20)

project(CICD_lab)

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(tests_work tests.cpp)

target_link_libraries(tests_work PRIVATE gtest)