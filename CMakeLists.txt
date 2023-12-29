cmake_minimum_required(VERSION 3.24)
project(cluster_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(cluster_cpp main.cpp DataReader.cpp ./json/json.h ./json/json-forwards.h jsoncpp.cpp FelixnGroup.h)
