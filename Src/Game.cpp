#include "Game.h"

#include "AppConfiguration.h"

#include <iostream>

using namespace std;

#include <lua5.3/lua.hpp>
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

            lua_pushinteger(_Lua, (int) Attribute::WILL);
            lua_setglobal(_Lua, "ATTRIBUTE_WILL");

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

            lua_pushinteger(_Lua, (unsigned int) TeamFlags::ANY);
            lua_setglobal(_Lua, "TEAMFLAGS_ANY");

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
        // Flag Filter
        {

        }
        // Find Order
        {
            lua_pushinteger(_Lua, (int) FindOrder::RANDOMIZED);
            lua_setglobal(_Lua, "FIND_ORDER_RANDOMIZED");

            lua_pushinteger(_Lua, (int) FindOrder::CLOSEST);
            lua_setglobal(_Lua, "FIND_ORDER_CLOSEST");

            lua_pushinteger(_Lua, (int) FindOrder::FARTHEST);
            lua_setglobal(_Lua, "FIND_ORDER_FARTHEST");

            lua_pushinteger(_Lua, (int) FindOrder::ANY);
            lua_setglobal(_Lua, "FIND_ORDER_ANY");
        }
        // Modifier Priority
        {
            lua_pushinteger(_Lua, (int) ModifierPriority::MINIMAL);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_MINIMAL");

            lua_pushinteger(_Lua, (int) ModifierPriority::LOWEST);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_LOWEST");

            lua_pushinteger(_Lua, (int) ModifierPriority::LOW);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_LOW");

            lua_pushinteger(_Lua, (int) ModifierPriority::NORMAL);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_NORMAL");

            lua_pushinteger(_Lua, (int) ModifierPriority::HIGH);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_HIGH");

            lua_pushinteger(_Lua, (int) ModifierPriority::ULTRA);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_ULTRA");

            lua_pushinteger(_Lua, (int) ModifierPriority::SUPER_ULTRA);
            lua_setglobal(_Lua, "MODIFIER_PRIORITY_SUPER_ULTRA");
        }
        // Modifier Flags
        {
            lua_pushinteger(_Lua, (int) ModifierFlags::NONE);
            lua_setglobal(_Lua, "MODIFIER_FLAGS_NONE");

            // Status
            {
                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_STUN);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_STUN");

                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_ROOT);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_ROOT");

                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_SILENCE);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_SILENCE");

                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_MUTE);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_MUTE");

                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_BREAK);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_BREAK");

                lua_pushinteger(_Lua, (int) ModifierFlags::STATUS_HIDDEN);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_STATUS_HIDDEN");
            }

            // Ability
            {
                lua_pushinteger(_Lua, (int) ModifierFlags::ABILITY_STOP_COOLDOWN);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ABILITY_STOP_COOLDOWN");

                lua_pushinteger(_Lua, (int) ModifierFlags::ABILITY_NO_COOLDOWN);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ABILITY_NO_COOLDOWN");

                lua_pushinteger(_Lua, (int) ModifierFlags::ABILITY_NO_MANA);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ABILITY_NO_MANA");

                lua_pushinteger(_Lua, (int) ModifierFlags::ABILITY_NO_GOLD);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ABILITY_NO_GOLD");
            }

            // Immunity
            {
                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_MAGIC);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_MAGIC");

                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_PHYSICAL);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_PHYSICAL");

                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_PURE);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_PURE");

                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_ALL);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_ALL");

                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_DEATH);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_DEATH");

                lua_pushinteger(_Lua, (int) ModifierFlags::IMMUNITY_HEAL);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_IMMUNITY_HEAL");
            }

            // Invisible
            {
                lua_pushinteger(_Lua, (int) ModifierFlags::INVISIBLE);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_INVISIBLE");

                lua_pushinteger(_Lua, (int) ModifierFlags::INVISIBLE_RAW);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_INVISIBLE_RAW");
            }

            // Attack
            {
                lua_pushinteger(_Lua, (int) ModifierFlags::ATTACK_GLOBAL);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ATTACK_GLOBAL");

                lua_pushinteger(_Lua, (int) ModifierFlags::ATTACK_UNABLE);
                lua_setglobal(_Lua, "MODIFIER_FLAGS_ATTACK_UNABLE");
            }
        }
        // Ability Targeting
        {
            lua_pushinteger(_Lua, (int) AbilityTargeting::PASSIVE);
            lua_setglobal(_Lua, "ABILITY_TARGETING_PASSIVE");

            lua_pushinteger(_Lua, (int) AbilityTargeting::NONE);
            lua_setglobal(_Lua, "ABILITY_TARGETING_NONE");

            lua_pushinteger(_Lua, (int) AbilityTargeting::POINT);
            lua_setglobal(_Lua, "ABILITY_TARGETING_POINT");

            lua_pushinteger(_Lua, (int) AbilityTargeting::UNIT);
            lua_setglobal(_Lua, "ABILITY_TARGETING_UNIT");

            lua_pushinteger(_Lua, (int) AbilityTargeting::AOE);
            lua_setglobal(_Lua, "ABILITY_TARGETING_AOE");

            lua_pushinteger(_Lua, (int) AbilityTargeting::VECTOR);
            lua_setglobal(_Lua, "ABILITY_TARGETING_VECTOR");

            lua_pushinteger(_Lua, (int) AbilityTargeting::TOGGLE);
            lua_setglobal(_Lua, "ABILITY_TARGETING_TOGGLE");

            lua_pushinteger(_Lua, (int) AbilityTargeting::TREE);
            lua_setglobal(_Lua, "ABILITY_TARGETING_TREE");

            lua_pushinteger(_Lua, (int) AbilityTargeting::AURA);
            lua_setglobal(_Lua, "ABILITY_TARGETING_AURA");
        }
        // Attack Type
        {
            lua_pushinteger(_Lua, (int) AttackType::MELEE);
            lua_setglobal(_Lua, "ATTACK_TYPE_MELEE");

            lua_pushinteger(_Lua, (int) AttackType::RANGED);
            lua_setglobal(_Lua, "ATTACK_TYPE_RANGED");
        }
        // Unit Type
        {
            lua_pushinteger(_Lua, (int) UnitType::CREEP);
            lua_setglobal(_Lua, "UNIT_TYPE_CREEP");

            lua_pushinteger(_Lua, (int) UnitType::HERO);
            lua_setglobal(_Lua, "UNIT_TYPE_HERO");

            lua_pushinteger(_Lua, (int) UnitType::HERO_CREEP);
            lua_setglobal(_Lua, "UNIT_TYPE_HERO_CREEP");

            lua_pushinteger(_Lua, (int) UnitType::BOSS);
            lua_setglobal(_Lua, "UNIT_TYPE_BOSS");

            lua_pushinteger(_Lua, (int) UnitType::BUILDING);
            lua_setglobal(_Lua, "UNIT_TYPE_BUILDING");

            lua_pushinteger(_Lua, (int) UnitType::_COUNT);
            lua_setglobal(_Lua, "UNIT_TYPE__COUNT");
        }
        // Unit Type Flag
        {
            lua_pushinteger(_Lua, (int) UnitTypeFlag::CREEP);
            lua_setglobal(_Lua, "UNIT_TYPE_FLAG_CREEP");

            lua_pushinteger(_Lua, (int) UnitTypeFlag::HERO);
            lua_setglobal(_Lua, "UNIT_TYPE_FLAG_HERO");

            lua_pushinteger(_Lua, (int) UnitTypeFlag::HERO_CREEP);
            lua_setglobal(_Lua, "UNIT_TYPE_FLAG_HERO_CREEP");

            lua_pushinteger(_Lua, (int) UnitTypeFlag::BOSS);
            lua_setglobal(_Lua, "UNIT_TYPE_FLAG_BOSS");

            lua_pushinteger(_Lua, (int) UnitTypeFlag::BUILDING);
            lua_setglobal(_Lua, "UNIT_TYPE_FLAG_BUILDING");
        }
    }

    // Open custom libraries
    {
        // Math
        {
            lua_getglobal(_Lua, "math");
            lua_setglobal(_Lua, "Math");
        }
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
