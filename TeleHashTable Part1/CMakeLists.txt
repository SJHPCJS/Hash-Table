cmake_minimum_required(VERSION 3.27)
project(TeleHashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(TeleHashTable test.cpp
        HashTable.cpp
        HashTable.h
        HashNode.cpp
        HashNode.h)
