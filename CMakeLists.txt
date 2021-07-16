cmake_minimum_required(VERSION 3.15)
project(PANG)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS graphics)

set(SOURCES src/main.cpp
            src/pang.cpp
            src/states/game-state.cpp
            src/states/splashscreen-state.cpp
            src/states/menu-state.cpp
            src/states/playing-state.cpp
            src/objects/visible-object.cpp
            src/objects/visible-object-manager.cpp
            src/objects/gui/splashscreen.cpp
            src/objects/gui/play-button.cpp
            src/objects/gui/exit-button.cpp
            src/objects/entities/field.cpp
            src/objects/entities/paddle.cpp
            src/objects/entities/ball.cpp
)

add_executable(PANG ${SOURCES})

target_link_libraries(PANG sfml-graphics)