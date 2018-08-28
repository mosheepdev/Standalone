
#include "Game.h"

#include <iostream>

extern "C"
{
#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>
};

#include "AppConfiguration.h"

using namespace std;

bool Game::InitGui()
{
    if(_SdlWindow != nullptr)
    {
        cerr << "Window already initialized." << endl;
        return true;
    }

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    //Create window
    _SdlWindow = SDL_CreateWindow( APP_NAME " - " APP_VERSION, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
    if( _SdlWindow == nullptr )
    {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void Game::TickRender()
{
    if(_SdlWindow == nullptr)
        return;

    SDL_UpdateWindowSurface( _SdlWindow );

    throw std::logic_error("Not Implemented");
}

void Game::TickUpdate()
{
    if(_SdlWindow != nullptr)
    {
        //Handle events on queue
        {
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if (e.type == SDL_QUIT)
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

bool Game::InitLuaClient()
{
    _LuaClient = luaL_newstate();

    return true;
}

bool Game::InitLuaServer()
{
    _LuaServer = luaL_newstate();

    return true;
}