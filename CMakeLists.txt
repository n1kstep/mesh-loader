cmake_minimum_required(VERSION 3.20)
project(cpp_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_lab1 main.cpp MeshLoader.cpp MeshLoader.h AneuMeshLoader.cpp AneuMeshLoader.h Structures.h)
