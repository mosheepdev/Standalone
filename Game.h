#ifndef STANDALONE_GAME_H
#define STANDALONE_GAME_H


#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#define LUA_LIB
#include "lua.h"

class Game {
// GUI (Window)
public:
    bool InitGui();
    bool HasGui() { return _SdlWindow != nullptr; }
private:
    SDL_Window* _SdlWindow = nullptr;

// Ticks
public:
    void TickRender();
    void TickUpdate();

// Closing
public:
    bool IsClosing() { return _IsClosing; }
    void Close() { _IsClosing = true; }
private:
    bool _IsClosing = false;
};


#endif //STANDALONE_GAME_H
