cmake_minimum_required(VERSION 2.8)
project(conditional_compilation C CXX)
set(name conditional_compilation)

if(CONDITIONAL_FLAG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
