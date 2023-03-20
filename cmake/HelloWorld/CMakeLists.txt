cmake_minimum_required(VERSION 3.5)
project(HelloWorld)

message("CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
message("CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(HelloWorld main.cpp)
