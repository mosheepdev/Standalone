#ifndef STANDALONE_GAME_H
#define STANDALONE_GAME_H

#include <string>
using namespace std;

#include <map>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include "lua.hpp"
#include "Player.h"

// There can be one or two instances of this running at a same time.
// Separating Client and Server
class Game {

// Client / Server
// Only one of IsClient() or IsServer() can return true
public:
    virtual bool IsClient() { return false; }
    virtual Game* GetClient() { return nullptr; }
    virtual bool IsServer() { return false; }
    virtual bool IsDedicatedServer() { return false; }
    virtual Player* GetHostingPlayer() { return nullptr; }

// Ticks
public:
    virtual void Tick() {}

// LUA
public:
    virtual bool InitLua();
    lua_State* GetLua() { return _Lua; }
protected:
    lua_State *_Lua = nullptr;

// Script Init + Register
public:
    bool TryGetAbility(string name, int *ref);
    bool TryGetItem(string name, int *ref);
    bool TryGetModifier(string name, int *ref);
    int GetOrCreateAbility(string name);
    int GetOrCreateItem(string name);
    int GetOrCreateModifier(string name);
private:
    map<string, int> _LuaRef_Ability;
    map<string, int> _LuaRef_Item;
    map<string, int> _LuaRef_Modifier;

// Linking
private:
    map<string, vector<string>> _AllAbilities;
    map<string, vector<string>> _AllItems;
    map<string, vector<string>> _AllModifiers;
    map<string, vector<string>> _AllUnits;
public:
    void LinkAbility(string name, string path);
    void LinkItem(string name, string path);
    void LinkModifier(string name, string path);
    void LinkUnit(string name, string path);
};


#endif //STANDALONE_GAME_H
