cmake_minimum_required(VERSION 3.23)
project(Shannon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shannon main.cpp BinWriter.cpp BinReader.cpp)
