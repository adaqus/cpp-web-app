cmake_minimum_required(VERSION 3.2.0)
project(simpleWebApp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Crow/include)

add_executable(simpleWebApp main.cpp)
