cmake_minimum_required(VERSION 3.15)
project(PANG)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS graphics)

set(SOURCES src/main.cpp)

add_executable(PANG ${SOURCES})

target_link_libraries(PANG sfml-graphics)