cmake_minimum_required(VERSION 3.12)
project(Standalone)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/lua5.3/)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -lSDL2 -lGLEW -lGLU -lGL -Wall")

add_executable(Standalone main.cpp Enums.h Unit.cpp Unit.h Ability.cpp Ability.h Modifier.cpp Modifier.h Item.cpp Item.h Game.cpp Game.h AppConfiguration.h Lua/lapi.c Lua/lauxlib.c Lua/lbaselib.c Lua/lbitlib.c Lua/lcode.c Lua/lcorolib.c Lua/lctype.c Lua/ldblib.c Lua/ldebug.c Lua/ldo.c Lua/ldump.c Lua/lfunc.c Lua/lgc.c Lua/linit.c Lua/liolib.c Lua/llex.c Lua/lmathlib.c Lua/lmem.c Lua/loadlib.c Lua/lobject.c Lua/lopcodes.c Lua/loslib.c Lua/lparser.c Lua/lstate.c Lua/lstring.c Lua/lstrlib.c Lua/ltable.c Lua/ltablib.c Lua/ltm.c Lua/lua.c Lua/luac.c Lua/lundump.c Lua/lutf8lib.c Lua/lvm.c Lua/lzio.c Lua/lapi.h Lua/lauxlib.h Lua/lcode.h Lua/lctype.h Lua/ldebug.h Lua/ldo.h Lua/lfunc.h Lua/lgc.h Lua/llex.h Lua/llimits.h Lua/lmem.h Lua/lobject.h Lua/lopcodes.h Lua/lparser.h Lua/lprefix.h Lua/lstate.h Lua/lstring.h Lua/ltable.h Lua/ltm.h Lua/lua.h Lua/lua.hpp Lua/luaconf.h Lua/lualib.h Lua/lundump.h Lua/lvm.h Lua/lzio.h)