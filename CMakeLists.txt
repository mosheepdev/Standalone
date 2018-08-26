cmake_minimum_required(VERSION 3.12)
project(Standalone)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/lua5.3/)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -lSDL2 -lGLEW -lGLU -lGL -Wall")

add_executable(Standalone main.cpp Enums.h Unit.cpp Unit.h Ability.cpp Ability.h Modifier.cpp Modifier.h Item.cpp Item.h Game.cpp Game.h AppConfiguration.h)