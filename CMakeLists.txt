cmake_minimum_required(VERSION 3.16)
project(Calendar)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Calendar src/main.cpp src/kalendarz.cpp src/base.cpp src/menu.cpp
        include/kalendarz.h include/base.h include/menu.h)

