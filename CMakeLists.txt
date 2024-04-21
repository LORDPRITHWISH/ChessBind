cmake_minimum_required(VERSION 3.22)
project(chess_Brain)

add_subdirectory(pybind11)
pybind11_add_module(brain computation.cpp)