cmake_minimum_required(VERSION 3.28)
project(myfetch)

set(CMAKE_CXX_STANDARD 20)

add_executable(myfetch main.cpp
        TextLine.h
        entities/Title.cpp
        entities/Title.h
        helper/Color.cpp
        helper/Color.h
        entities/Module.cpp
        entities/Module.h)
