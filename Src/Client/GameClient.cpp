#include "GameClient.h"

#include "../AppConfiguration.h"

#include <iostream>

using namespace std;

GameClient::GameClient()
{
}

GameClient::~GameClient()
{
    lua_close(_Lua);
}

void GameClient::Init()
{
    InitGui();

    // Lua last for custom libraries to be able to link the rest
    InitLua();
}

bool GameClient::InitGui()
{
    if(_SdlWindow != nullptr)
    {
        cerr << "Window already initialized." << endl;
        return true;
    }

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    //Create window
    _SdlWindow = SDL_CreateWindow(APP_NAME " - " APP_VERSION, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if(_SdlWindow == nullptr)
    {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void GameClient::TickRender()
{
    if(_SdlWindow == nullptr)
        return;

    SDL_UpdateWindowSurface(_SdlWindow);

    throw std::logic_error("Not Implemented");
}

void GameClient::TickUpdate()
{
    if(_SdlWindow != nullptr)
    {
        //Handle events on queue
        {
            SDL_Event e;
            while(SDL_PollEvent(&e) != 0)
            {
                //User requests quit
                if(e.type == SDL_QUIT)
                    Close();
                if(e.type == SDL_KEYDOWN)
                {

                }
                if(e.type == SDL_KEYUP)
                {

                }
                if(e.type == SDL_MOUSEBUTTONDOWN)
                {

                }
                if(e.type == SDL_MOUSEBUTTONUP)
                {

                }
                if(e.type == SDL_MOUSEMOTION)
                {

                }
            }
        }
    }

    throw std::logic_error("Not Implemented");
}

bool GameClient::InitLua()
{
    if(!Game::InitLua())
        return false;

    //TODO custom libraries
    return true;
}
