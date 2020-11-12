cmake_minimum_required(VERSION 3.17)
project(selection C)

set(CMAKE_C_STANDARD 11)

add_executable(selection main.c stdlist.h stdlist.c)