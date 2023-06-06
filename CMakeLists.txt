cmake_minimum_required(VERSION 3.23)
project(LeetCodeSolutions)

set(CMAKE_CXX_STANDARD 20)

find_package(benchmark REQUIRED)

if(benchmark_FOUND)
    message("hello")
ENDIF()

add_executable(LeetCodeSolutions 1502CanMakeArithmeticProgressionFromSequence.cpp)

target_link_libraries(LeetCodeSolutions benchmark::benchmark)


