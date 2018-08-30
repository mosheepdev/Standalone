#ifndef STANDALONE_GAMECLIENT_H
#define STANDALONE_GAMECLIENT_H

#include "Game.h"

class GameClient : Game
{

// GUI (Window)
public:
    bool HasGui() { return _SdlWindow != nullptr; }
private:
    bool InitGui();
    SDL_Window* _SdlWindow = nullptr;

// Tick
public:
    void Tick()
    {
        TickUpdate();
        TickRender();
    }
private:
    void TickRender();
    void TickUpdate();

// Closing
public:
    bool IsClosing() { return _IsClosing; }
    void Close() { _IsClosing = true; }
private:
    bool _IsClosing = false;
};


#endif //STANDALONE_GAMECLIENT_H
