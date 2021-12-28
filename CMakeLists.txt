cmake_minimum_required(VERSION 3.20)
project(Proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj1 main.cpp Person.h Course.h Student.h Records.h LinkedList.h Node.h DoubleLinkedList.h DNode.h default.csv)
