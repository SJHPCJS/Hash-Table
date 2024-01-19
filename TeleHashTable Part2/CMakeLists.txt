cmake_minimum_required(VERSION 3.27)
project(TeleHashTable_Part2)

set(CMAKE_CXX_STANDARD 17)

add_executable(TeleHashTable_Part2 test1.cpp
        HashNode.h
        HashNodeTemplate.h
        HashTable.h
        HashTableTemplate.h
        List.h
        ListTemplate.h
        test2.cpp
        test3.cpp)
