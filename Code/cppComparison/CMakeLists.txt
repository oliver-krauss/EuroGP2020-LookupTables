cmake_minimum_required(VERSION 3.14)
project(cbrtCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(sqrtCpp sqrt.cpp)
add_executable(cbrtCpp cbrt.cpp)
add_executable(surtCpp surt.cpp)

add_executable(sqrtCppBench benchSqrt.cpp)
add_executable(cbrtCppBench benchCbrt.cpp)
add_executable(surtCppBench benchSurt.cpp)