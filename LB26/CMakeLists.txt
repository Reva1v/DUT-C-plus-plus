cmake_minimum_required(VERSION 3.31)
project(LB26)

set(CMAKE_CXX_STANDARD 20)

add_executable(LB26 main.cpp
        IPAddress.h
        IPAddress.cpp
        IPAddressChecked.h
        IPAddressChecked.cpp)
