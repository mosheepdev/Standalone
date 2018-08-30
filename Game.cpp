#include "Game.h"

#include "AppConfiguration.h"

#include <iostream>
using namespace std;

bool Game::InitLua()
{
    _Lua = luaL_newstate();
    { // Open default libraries
        luaopen_base(_Lua);
        luaopen_math(_Lua);
        luaopen_string(_Lua);
        luaopen_utf8(_Lua);
        luaopen_table(_Lua);
    }

    return true;
}