cmake_minimum_required(VERSION 3.22)
project(faster lighter)

add_subdirectory(pybind11)
pybind11_add_module(trial test.cpp)