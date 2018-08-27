#include <iostream>
#include <cstring>

using namespace std;

#include "AppConfiguration.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    if(argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0))
    {
        cout << APP_NAME << endl;
        cout << APP_VERSION << endl;
        return 0;
    }

    cout << "This program comes AS IS with NO WARRANTY." << endl;
    cout << endl;
    cout << "Copyright (C) 2018 Abit Gray" << endl;
    cout << "AbitTheGray@gmail.com" << endl;
    cout << "All rights reserved" << endl;
    cout << endl;
    cout << endl;

    if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << "Start new instance of the game." << endl;
        cout << "Only one instance can run at a time." << endl;
        cout << endl;
        cout << endl;
        cout << "Arguments:" << endl;
        cout << "\t--help\t\t\tDisplay this help." << endl;
        cout << "\t -h" << endl;
        cout << "\t--version\t\t\tShow version info." << endl;
        cout << "\t -v" << endl;
        cout << "\t--debug\t\t\tStart in debug mode. This turns on debugging messages into console." << endl;
        cout << "\t--language <name>\t\t\tChange game language." << endl;
        cout << "\t--fullscreen\t\t\tStart in Fullscreen mode." << endl;
        cout << "\t--windowed\t\t\tStart in Windowed mode." << endl;
        cout << "\t--resolution <width> <height>\t\t\tForce window/fullscreen resolution to <width>x<height>." << endl;
        cout << "\t--no-gui\t\t\tStart without OpenGL Frontend (for dedicated servers)" << endl;
        cout << "\t--lobby <lobby_id>\t\t\tInstantly join specified lobby." << endl;
        cout << "\t -l <lobby_id>" << endl;
        cout << "\t--party <party_id>\t\t\tInstantly join specified party." << endl;
        cout << "\t -p <party_id>" << endl;
        cout << "\t--add-friend <friend_id>\t\t\tShow popup to add friend." << endl;
        cout << "\t -f <friend_id>" << endl;
        cout << "\t--host <game_id> <map> <dedicated> <settings>\t\t\tHost a new lobby. Set <dedicated> to TRUE if this player is not playing." << endl;
        cout << endl;
        cout << endl;
        cout << "Libraries:" << endl;
        cout << "\tSDL 2      Window management" << endl;
        cout << "\t               https://www.libsdl.org/" << endl;
        cout << "\tOpenGL     3D Rendering" << endl;
        cout << "\t               https://www.opengl.org/" << endl;
        cout << "\tGLEW       OpenGL Extension Wrangler" << endl;
        cout << "\t               http://glew.sourceforge.net/" << endl;
        cout << "\tGLM        OpenGL Mathematics" << endl;
        cout << "\t               https://glm.g-truc.net/" << endl;
        cout << "\tLUA        Scripting Language" << endl;
        cout << "\t               https://www.lua.org/" << endl;
        return 0;
    }

    Game* game = new Game();

    while(!game->IsClosing())
    {
        game->TickRender();
        game->TickUpdate();
    }

    return 0;
}
