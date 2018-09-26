cmake_minimum_required(VERSION 3.12)
project(Standalone)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -lSDL2 -lGLEW -lGLU -lGL -llua5.3 -Wall")

add_executable(Standalone Src/main.cpp Src/Enums.h Src/Unit.cpp Src/Unit.h Src/Ability.cpp Src/Ability.h Src/Modifier.cpp Src/Modifier.h Src/Item.cpp Src/Item.h Src/Game.cpp Src/Game.h Src/AppConfiguration.h Src/Player.cpp Src/Player.h Src/Client/GameClient.cpp Src/Client/GameClient.h Src/Utils.cpp Src/Utils.h Src/Map.cpp Src/Map.h)
