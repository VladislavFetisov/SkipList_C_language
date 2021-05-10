cmake_minimum_required(VERSION 3.19)
project(SkipList C)

set(CMAKE_C_STANDARD 99)

add_executable(SkipList main.c skipList.c Main.h)