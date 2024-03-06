cmake_minimum_required(VERSION 3.27)
project(GenericLinkedList C)

set(CMAKE_C_STANDARD 17)

add_library(GenericLinkedList STATIC
        include/LinkedList.h
        src/LinkedList.c
)
