#include "LuaLibGlobal.h"

#include <iostream>

using namespace std;

LuaLibGlobal::LuaLibGlobal(Game* game) : _Game(game)
{
}
//-----------------------------------------------------------------

int LuaLibGlobal::Print(lua_State *Lua)
{
    const char *message = luaL_checkstring(Lua, 1);

    cout << message << endl;

    return 0;
}

int LuaLibGlobal::PrintDebug(lua_State *Lua)
{
    const char *message = luaL_checkstring(Lua, 1);

    if(_Game->IsClient())
        cout << "[CLIENT]   " << message << endl;
    else
    {
        if(_Game->IsDedicatedServer())
            cout << "[D_SERVER] " << message << endl;
        else
            cout << "[SERVER]   " << message << endl;
    }

    return 0;
}

int LuaLibGlobal::Write(lua_State *Lua)
{
    const char *message = luaL_checkstring(Lua, 1);

    cout << message;

    return 0;
}

//-----------------------------------------------------------------

int LuaLibGlobal::IsClient(lua_State *Lua)
{
    lua_pushboolean(Lua, _Game->IsClient());
    return 1;
}

int LuaLibGlobal::IsServer(lua_State *Lua)
{
    lua_pushboolean(Lua, _Game->IsServer());
    return 1;
}

int LuaLibGlobal::IsDedicatedServer(lua_State *Lua)
{
    lua_pushboolean(Lua, _Game->IsDedicatedServer());
    return 1;
}

//-----------------------------------------------------------------

int LuaLibGlobal::GetHostPlayer(lua_State *Lua)
{
    //TODO Push handle
    return 1;
}

int LuaLibGlobal::GetHostName(lua_State *Lua)
{
    if(_Game->IsDedicatedServer())
    {
        //TODO Push string
    }
    else // Client or local server
    {
        Player *player = _Game->GetHostingPlayer();
        lua_pushstring(Lua, player->GetDisplayName().c_str());
    }
    return 1;
}

//-----------------------------------------------------------------

int LuaLibGlobal::GetMatchId(lua_State *Lua)
{
    //TODO Push string
    return 1;
}

//-----------------------------------------------------------------

int LuaLibGlobal::GetDeltaTime(lua_State *Lua)
{
    //TODO Push float
    return 1;
}

int LuaLibGlobal::GetSystemDate(lua_State *Lua)
{
    //TODO Push string
    return 1;
}

int LuaLibGlobal::GetSystemTime(lua_State *Lua)
{
    //TODO Push string
    return 1;
}

int LuaLibGlobal::GetSystemDateTime(lua_State *Lua)
{
    //TODO Push table
    return 1;
}

int LuaLibGlobal::GetMatchDate(lua_State *Lua)
{
    //TODO Push string
    return 1;
}

int LuaLibGlobal::GetMatchTime(lua_State *Lua)
{
    //TODO Push string
    return 1;
}

int LuaLibGlobal::GetMatchDateTime(lua_State *Lua)
{
    //TODO Push table
    return 1;
}

//-----------------------------------------------------------------

int LuaLibGlobal::_Ability(lua_State *Lua)
{
    // 1st attribute, string
    if(!lua_isstring(Lua, 1))
        luaL_error(Lua, "This function requires 1 attribute 'name' of type 'string'.");
    const char* name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}

int LuaLibGlobal::_Item(lua_State *Lua)
{
    // 1st attribute, string
    if(!lua_isstring(Lua, 1))
        luaL_error(Lua, "This function requires 1 attribute 'name' of type 'string'.");
    const char* name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}

int LuaLibGlobal::_Modifier(lua_State *Lua)
{
    // 1st attribute, string
    if(!lua_isstring(Lua, 1))
        luaL_error(Lua, "This function requires 1 attribute 'name' of type 'string'.");
    const char* name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}
