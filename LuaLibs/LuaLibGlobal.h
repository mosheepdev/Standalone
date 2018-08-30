#ifndef STANDALONE_LUALIBGLOBAL_H
#define STANDALONE_LUALIBGLOBAL_H

#include <string>
#include "../Lua/lua.hpp"
#include "../Game.h"

using namespace std;

class LuaLibGlobal
{
public:
    LuaLibGlobal(Game* game);
private:
    Game* _Game;

// Print + Write
public:
    int Print(lua_State *Lua);
    int PrintDebug(lua_State *Lua);
    int Write(lua_State *Lua);

// IsClient, IsServer and IsDedicatedServer
public:
    int IsClient(lua_State *Lua);
    int IsServer(lua_State *Lua);
    int IsDedicatedServer(lua_State *Lua);

// Host Player Handle + Name
public:
    int GetHostPlayer(lua_State *Lua);
    int GetHostName(lua_State *Lua);

// Match
public:
    int GetMatchId(lua_State *Lua);

// Time
public:
    int GetDeltaTime(lua_State *Lua);
    int GetSystemDate(lua_State *Lua);
    int GetSystemTime(lua_State *Lua);
    int GetSystemDateTime(lua_State *Lua);
    int GetMatchDate(lua_State *Lua);
    int GetMatchTime(lua_State *Lua);
    int GetMatchDateTime(lua_State *Lua);

};


#endif //STANDALONE_LUALIBGLOBAL_H
