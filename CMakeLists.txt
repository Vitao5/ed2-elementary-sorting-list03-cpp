cmake_minimum_required(VERSION 4.2)
project(Lista03_ED2)

set(CMAKE_CXX_STANDARD 20)


# Cada arquivo .cpp com sua própria função main ganha seu próprio executável independente:
add_executable(ex01-bubbleSorting src/ex01-bubbleSorting.cpp
        src/Exer03_InsertionKSorted.cpp)
add_executable(Exer02_SelectionSort_Min src/Exer02_SelectionSort_Min.cpp)

# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(main_app main.cpp)