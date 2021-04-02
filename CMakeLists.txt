cmake_minimum_required(VERSION 3.17)
project(daima)

set(CMAKE_CXX_STANDARD 14)

add_executable(daima main.cpp fun1.cpp menu.cpp menu.h teacher.cpp student.cpp )

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
