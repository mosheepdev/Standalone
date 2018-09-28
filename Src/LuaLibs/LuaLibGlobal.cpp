#include "LuaLibGlobal.h"

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

LuaLibGlobal::LuaLibGlobal(Game *game) : _Game(game)
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
    } else // Client or local server
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
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::ostringstream stringStream;
    // Year
    stringStream << ltm->tm_year;
    stringStream << "/";
    // Month
    if(ltm->tm_mon < 10)
        stringStream << "0" << ltm->tm_mon;
    else
        stringStream << ltm->tm_mon;
    stringStream << "/";
    // Day
    if(ltm->tm_mday < 10)
        stringStream << "0" << ltm->tm_mday;
    else
        stringStream << ltm->tm_mday;

    string str = stringStream.str();

    lua_pushstring(Lua, str.c_str());// yyyy/MM/ss
    return 1;
}

int LuaLibGlobal::GetSystemTime(lua_State *Lua)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::ostringstream stringStream;
    // Hour
    if(ltm->tm_hour < 10)
        stringStream << "0" << ltm->tm_hour;
    else
        stringStream << ltm->tm_mon;
    stringStream << ":";
    // Minutes
    if(ltm->tm_min < 10)
        stringStream << "0" << ltm->tm_min;
    else
        stringStream << ltm->tm_min;
    stringStream << ":";
    // Seconds
    if(ltm->tm_sec < 10)
        stringStream << "0" << ltm->tm_sec;
    else
        stringStream << ltm->tm_sec;

    string str = stringStream.str();

    lua_pushstring(Lua, str.c_str());// hh:mm:ss
    return 1;
}

int GetDateTimeLen(lua_State *Lua)
{
    if(!lua_istable(Lua, -1))
        luaL_error(Lua, "First argument of `__len` must be table.");

    lua_pushnumber(Lua, 6);
    return 1;
}

int GetDateTimeType(lua_State *Lua)
{
    if(lua_istable(Lua, -1))
        lua_pushstring(Lua, "DateTime");
    else
        lua_pushstring(Lua, "Unknown");
    return 1;
}

int GetDateTimeToString(lua_State *Lua)
{
    if(!lua_istable(Lua, -1))
        luaL_error(Lua, "First argument of `__tostring` must be table.");

    std::ostringstream stringStream;
    // Year
    {
        int year = 0;
        lua_pushstring(Lua, "year");
        if(lua_isnumber(Lua, -1))
        {
            year = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(year < 1000)
        {
            stringStream << 0;
            if(year < 100)
            {
                stringStream << 0;
                if(year < 10)
                {
                    stringStream << 0;
                }
            }
        }
        stringStream << year;
    }
    stringStream << "/";
    // Month
    {
        int month = 0;
        lua_pushstring(Lua, "month");
        if(lua_isnumber(Lua, -1))
        {
            month = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(month < 10)
        {
            stringStream << 0;
        }
        stringStream << month;
    }
    stringStream << "/";
    // Day
    {
        int day = 0;
        lua_pushstring(Lua, "day");
        if(lua_isnumber(Lua, -1))
        {
            day = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(day < 10)
        {
            stringStream << 0;
        }
        stringStream << day;
    }
    stringStream << " ";
    // Hour
    {
        int hour = 0;
        lua_pushstring(Lua, "hour");
        if(lua_isnumber(Lua, -1))
        {
            hour = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(hour < 10)
        {
            stringStream << 0;
        }
        stringStream << hour;
    }
    stringStream << ":";
    // Minute
    {
        int minute = 0;
        lua_pushstring(Lua, "minute");
        if(lua_isnumber(Lua, -1))
        {
            minute = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(minute < 10)
        {
            stringStream << 0;
        }
        stringStream << minute;
    }
    stringStream << ":";
    // Second
    {
        int second = 0;
        lua_pushstring(Lua, "second");
        if(lua_isnumber(Lua, -1))
        {
            second = (int)lua_tonumber(Lua, -1);
        }
        lua_pop(Lua, 1);

        if(second < 10)
        {
            stringStream << 0;
        }
        stringStream << second;
    }

    string str = stringStream.str();

    lua_pushstring(Lua, str.c_str());// yy/mm/dd hh:MM:ss
    return 1;
}

int LuaLibGlobal::GetSystemDateTime(lua_State *Lua)
{
    if(luaL_newmetatable(Lua, "DateTime"))
    {
        lua_pushstring(Lua, "__len");
        lua_pushcfunction(Lua, GetDateTimeLen);
        lua_settable(Lua, -3);

        lua_pushstring(Lua, "__type");
        lua_pushcfunction(Lua, GetDateTimeType);
        lua_settable(Lua, -3);

        lua_pushstring(Lua, "__tostring");
        lua_pushcfunction(Lua, GetDateTimeToString);
        lua_settable(Lua, -3);

        lua_pop(Lua, -1);
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);

    lua_createtable(Lua, 0, 6);

    lua_pushstring(Lua, "year");
    lua_pushinteger(Lua, ltm->tm_year);
    lua_settable(Lua, -3);

    lua_pushstring(Lua, "month");
    lua_pushinteger(Lua, ltm->tm_mon);
    lua_settable(Lua, -3);

    lua_pushstring(Lua, "day");
    lua_pushinteger(Lua, ltm->tm_mday);
    lua_settable(Lua, -3);

    lua_pushstring(Lua, "hour");
    lua_pushinteger(Lua, ltm->tm_hour);
    lua_settable(Lua, -3);

    lua_pushstring(Lua, "minute");
    lua_pushinteger(Lua, ltm->tm_min);
    lua_settable(Lua, -3);

    lua_pushstring(Lua, "second");
    lua_pushinteger(Lua, ltm->tm_sec);
    lua_settable(Lua, -3);

    luaL_setmetatable(Lua, "DateTime");

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
    const char *name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}

int LuaLibGlobal::_Item(lua_State *Lua)
{
    // 1st attribute, string
    if(!lua_isstring(Lua, 1))
        luaL_error(Lua, "This function requires 1 attribute 'name' of type 'string'.");
    const char *name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}

int LuaLibGlobal::_Modifier(lua_State *Lua)
{
    // 1st attribute, string
    if(!lua_isstring(Lua, 1))
        luaL_error(Lua, "This function requires 1 attribute 'name' of type 'string'.");
    const char *name = lua_tostring(Lua, 1);

    //TODO Push table
    return 1;
}
