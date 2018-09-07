#include "Game.h"

#include "AppConfiguration.h"

#include <iostream>

using namespace std;

#include "Lua/lua.hpp"
#include "Enums.h"
#include "Utils.h"

bool Game::InitLua()
{
    _Lua = luaL_newstate();

    // Open default libraries
    {
        luaopen_base(_Lua);
        luaopen_math(_Lua);
        luaopen_string(_Lua);
        luaopen_utf8(_Lua);
        luaopen_table(_Lua);
    }

    // Load Enums
    {
        // Damage Type
        {
            lua_pushinteger(_Lua, (int) DamageType::PURE);
            lua_setglobal(_Lua, "DAMAGE_TYPE_PURE");

            lua_pushinteger(_Lua, (int) DamageType::PHYSICAL);
            lua_setglobal(_Lua, "DAMAGE_TYPE_PHYSICAL");

            lua_pushinteger(_Lua, (int) DamageType::MAGICAL);
            lua_setglobal(_Lua, "DAMAGE_TYPE_MAGICAL");
            lua_pushinteger(_Lua, (int) DamageType::MAGICAL);
            lua_setglobal(_Lua, "DAMAGE_TYPE_MAGIC");

            lua_pushinteger(_Lua, (int) DamageType::_COUNT);
            lua_setglobal(_Lua, "DAMAGE_TYPE__COUNT");
        }
        // Damage Flags
        {
            lua_pushinteger(_Lua, (int) DamageFlags::NONE);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_NONE");

            lua_pushinteger(_Lua, (int) DamageFlags::NO_ARMOR);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_NO_ARMOR");

            lua_pushinteger(_Lua, (int) DamageFlags::NO_MAGIC_RESIST);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_NO_MAGIC_RESIST");

            lua_pushinteger(_Lua, (int) DamageFlags::NO_DAMAGE_BLOCK);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_NO_DAMAGE_BLOCK");

            lua_pushinteger(_Lua, (int) DamageFlags::NON_LETHAL);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_NON_LETHAL");

            lua_pushinteger(_Lua, (int) DamageFlags::REFLECTION);
            lua_setglobal(_Lua, "DAMAGE_FLAGS_REFLECTION");
        }
        // Attribute
        {
            lua_pushinteger(_Lua, (int) Attribute::STRENGTH);
            lua_setglobal(_Lua, "ATTRIBUTE_STRENGTH");

            lua_pushinteger(_Lua, (int) Attribute::AGILITY);
            lua_setglobal(_Lua, "ATTRIBUTE_AGILITY");

            lua_pushinteger(_Lua, (int) Attribute::INTELLIGENCE);
            lua_setglobal(_Lua, "ATTRIBUTE_INTELLIGENCE");

            lua_pushinteger(_Lua, (int) Attribute::CHARISMA);
            lua_setglobal(_Lua, "ATTRIBUTE_CHARISMA");

            lua_pushinteger(_Lua, (int) Attribute::_COUNT);
            lua_setglobal(_Lua, "ATTRIBUTE__COUNT");
        }
        // Team + TeamFlags
        {
            lua_pushinteger(_Lua, (int) Team::NEUTRAL);
            lua_setglobal(_Lua, "TEAM_NEUTRAL");
            lua_pushinteger(_Lua, (unsigned int) TeamFlags::NEUTRAL);
            lua_setglobal(_Lua, "TEAMFLAGS_NEUTRAL");

            lua_pushinteger(_Lua, (int) Team::SPECTATOR);
            lua_setglobal(_Lua, "TEAM_SPECTATOR");

            // Numbers
            {
                lua_pushinteger(_Lua, (int) Team::TEAM_1);
                lua_setglobal(_Lua, "TEAM_1");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_1);
                lua_setglobal(_Lua, "TEAMFLAGS_1");

                lua_pushinteger(_Lua, (int) Team::TEAM_2);
                lua_setglobal(_Lua, "TEAM_2");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_2);
                lua_setglobal(_Lua, "TEAMFLAGS_2");

                lua_pushinteger(_Lua, (int) Team::TEAM_3);
                lua_setglobal(_Lua, "TEAM_3");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_3);
                lua_setglobal(_Lua, "TEAMFLAGS_3");

                lua_pushinteger(_Lua, (int) Team::TEAM_4);
                lua_setglobal(_Lua, "TEAM_4");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_4);
                lua_setglobal(_Lua, "TEAMFLAGS_4");

                lua_pushinteger(_Lua, (int) Team::TEAM_5);
                lua_setglobal(_Lua, "TEAM_5");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_5);
                lua_setglobal(_Lua, "TEAMFLAGS_5");

                lua_pushinteger(_Lua, (int) Team::TEAM_6);
                lua_setglobal(_Lua, "TEAM_6");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_6);
                lua_setglobal(_Lua, "TEAMFLAGS_6");

                lua_pushinteger(_Lua, (int) Team::TEAM_7);
                lua_setglobal(_Lua, "TEAM_7");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_7);
                lua_setglobal(_Lua, "TEAMFLAGS_7");

                lua_pushinteger(_Lua, (int) Team::TEAM_8);
                lua_setglobal(_Lua, "TEAM_8");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_8);
                lua_setglobal(_Lua, "TEAMFLAGS_8");

                lua_pushinteger(_Lua, (int) Team::TEAM_9);
                lua_setglobal(_Lua, "TEAM_9");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_9);
                lua_setglobal(_Lua, "TEAMFLAGS_9");

                lua_pushinteger(_Lua, (int) Team::TEAM_10);
                lua_setglobal(_Lua, "TEAM_10");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_10);
                lua_setglobal(_Lua, "TEAMFLAGS_10");

                lua_pushinteger(_Lua, (int) Team::TEAM_11);
                lua_setglobal(_Lua, "TEAM_11");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_11);
                lua_setglobal(_Lua, "TEAMFLAGS_11");

                lua_pushinteger(_Lua, (int) Team::TEAM_12);
                lua_setglobal(_Lua, "TEAM_12");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_12);
                lua_setglobal(_Lua, "TEAMFLAGS_12");

                lua_pushinteger(_Lua, (int) Team::TEAM_13);
                lua_setglobal(_Lua, "TEAM_13");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_13);
                lua_setglobal(_Lua, "TEAMFLAGS_13");

                lua_pushinteger(_Lua, (int) Team::TEAM_14);
                lua_setglobal(_Lua, "TEAM_14");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_14);
                lua_setglobal(_Lua, "TEAMFLAGS_14");

                lua_pushinteger(_Lua, (int) Team::TEAM_15);
                lua_setglobal(_Lua, "TEAM_15");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_15);
                lua_setglobal(_Lua, "TEAMFLAGS_15");

                lua_pushinteger(_Lua, (int) Team::TEAM_16);
                lua_setglobal(_Lua, "TEAM_16");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_16);
                lua_setglobal(_Lua, "TEAMFLAGS_16");

                lua_pushinteger(_Lua, (int) Team::TEAM_17);
                lua_setglobal(_Lua, "TEAM_17");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_17);
                lua_setglobal(_Lua, "TEAMFLAGS_17");

                lua_pushinteger(_Lua, (int) Team::TEAM_18);
                lua_setglobal(_Lua, "TEAM_18");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_18);
                lua_setglobal(_Lua, "TEAMFLAGS_18");

                lua_pushinteger(_Lua, (int) Team::TEAM_19);
                lua_setglobal(_Lua, "TEAM_19");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_19);
                lua_setglobal(_Lua, "TEAMFLAGS_19");

                lua_pushinteger(_Lua, (int) Team::TEAM_20);
                lua_setglobal(_Lua, "TEAM_20");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_20);
                lua_setglobal(_Lua, "TEAMFLAGS_20");

                lua_pushinteger(_Lua, (int) Team::TEAM_21);
                lua_setglobal(_Lua, "TEAM_21");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_21);
                lua_setglobal(_Lua, "TEAMFLAGS_21");

                lua_pushinteger(_Lua, (int) Team::TEAM_22);
                lua_setglobal(_Lua, "TEAM_22");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_22);
                lua_setglobal(_Lua, "TEAMFLAGS_22");

                lua_pushinteger(_Lua, (int) Team::TEAM_23);
                lua_setglobal(_Lua, "TEAM_23");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_23);
                lua_setglobal(_Lua, "TEAMFLAGS_23");

                lua_pushinteger(_Lua, (int) Team::TEAM_24);
                lua_setglobal(_Lua, "TEAM_24");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_24);
                lua_setglobal(_Lua, "TEAMFLAGS_24");

                lua_pushinteger(_Lua, (int) Team::TEAM_25);
                lua_setglobal(_Lua, "TEAM_25");
                lua_pushinteger(_Lua, (unsigned int) TeamFlags::TEAM_25);
                lua_setglobal(_Lua, "TEAMFLAGS_25");
            }

            lua_pushinteger(_Lua, (int) Team::_COUNT);
            lua_setglobal(_Lua, "TEAM__COUNT");
        }
        // Purge Type
        {
            lua_pushinteger(_Lua, (int) PurgeType::NONE);
            lua_setglobal(_Lua, "PURGE_NONE");

            lua_pushinteger(_Lua, (int) PurgeType::SOFT);
            lua_setglobal(_Lua, "PURGE_SOFT");

            lua_pushinteger(_Lua, (int) PurgeType::HARD);
            lua_setglobal(_Lua, "PURGE_HARD");

            lua_pushinteger(_Lua, (int) PurgeType::RESPAWN);
            lua_setglobal(_Lua, "PURGE_RESPAWN");

            lua_pushinteger(_Lua, (int) PurgeType::_COUNT);
            lua_setglobal(_Lua, "PURGE__COUNT");
        }
    }

    // Open custom libraries
    {

    }

    return true;
}

//-----------------------------------------------------------------

bool Game::TryGetAbility(string name, int *ref)
{
    for(std::map<string, int>::iterator it = _LuaRef_Ability.begin(); it != _LuaRef_Ability.end(); ++it)
    {
        if(Utils::iequals(name, (it->first)))
        {
            *ref = it->second;
            return true;
        }
    }
    *ref = LUA_NOREF;
    return false;
}

bool Game::TryGetItem(string name, int *ref)
{
    for(std::map<string, int>::iterator it = _LuaRef_Item.begin(); it != _LuaRef_Item.end(); ++it)
    {
        if(Utils::iequals(name, (it->first)))
        {
            *ref = it->second;
            return true;
        }
    }
    *ref = LUA_NOREF;
    return false;
}

bool Game::TryGetModifier(string name, int *ref)
{
    for(std::map<string, int>::iterator it = _LuaRef_Modifier.begin(); it != _LuaRef_Modifier.end(); ++it)
    {
        if(Utils::iequals(name, (it->first)))
        {
            *ref = it->second;
            return true;
        }
    }
    *ref = LUA_NOREF;
    return false;
}

//-----------------------------------------------------------------

int Game::GetOrCreateAbility(string name)
{
    int ref = 0;
    if(TryGetAbility(name, &ref))
        return ref;

    lua_newtable(_Lua);

    lua_pushstring(_Lua, "name");
    lua_pushstring(_Lua, name.c_str());
    lua_settable(_Lua, -3);

    lua_pushstring(_Lua, "type");
    lua_pushstring(_Lua, "ability");
    lua_settable(_Lua, -3);

    throw std::logic_error("Not Implemented");
}

int Game::GetOrCreateItem(string name)
{
    int ref = 0;
    if(TryGetItem(name, &ref))
        return ref;

    lua_newtable(_Lua);

    lua_pushstring(_Lua, "name");
    lua_pushstring(_Lua, name.c_str());
    lua_settable(_Lua, -3);

    lua_pushstring(_Lua, "type");
    lua_pushstring(_Lua, "item");
    lua_settable(_Lua, -3);

    throw std::logic_error("Not Implemented");
}

int Game::GetOrCreateModifier(string name)
{
    int ref = 0;
    if(TryGetModifier(name, &ref))
        return ref;

    lua_newtable(_Lua);

    lua_pushstring(_Lua, "name");
    lua_pushstring(_Lua, name.c_str());
    lua_settable(_Lua, -3);

    lua_pushstring(_Lua, "type");
    lua_pushstring(_Lua, "modifier");
    lua_settable(_Lua, -3);

    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Game::LinkAbility(string name, string path)
{
    throw std::logic_error("Not Implemented");
}

void Game::LinkItem(string name, string path)
{
    throw std::logic_error("Not Implemented");
}

void Game::LinkModifier(string name, string path)
{
    throw std::logic_error("Not Implemented");
}

void Game::LinkUnit(string name, string path)
{
    throw std::logic_error("Not Implemented");
}
