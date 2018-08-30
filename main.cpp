#include <iostream>
#include <cstring>

using namespace std;

#include "AppConfiguration.h"
#include "GameClient.h"

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
        cout << "\t-h, --help\t\t\tDisplay this help." << endl;
        cout << "\t-v, --version\t\t\tShow version info." << endl;
        cout << endl;
        cout << "\t-d, --debug\t\t\tStart in debug mode. This turns on debugging messages into console." << endl;
        cout << "\t-s, --server\t\t\tStart as Dedicated Server (without OpenGL Frontend)" << endl;
        cout << "\t--language <name>\t\t\tChange game language." << endl;
        cout << endl;
        cout << "\t-f, --fullscreen\t\t\tStart in Fullscreen mode." << endl;
        cout << "\t-w, --windowed\t\t\tStart in Windowed mode." << endl;
        cout << "\t--resolution <width> <height>\t\t\tForce window/fullscreen resolution to <width>x<height>." << endl;
        cout << endl;
        cout << "\t--join_lobby <lobby_id>\t\t\tJoin specified lobby." << endl;
        cout << "\t--join_lobby_pwd <lobby_id> <password>\t\t\tJoin specified lobby using password." << endl;
        cout << "\t--join_party <party_id>\t\t\tJoin specified party." << endl;
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

    bool startDedicatedServer = false;
    {
        for(int i = 1; i < argc; i++)
            if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--server") == 0)
                startDedicatedServer = true;
    }

    if(startDedicatedServer)
    {
        throw std::logic_error("Not Implemented");
    }
    else
    {
        GameClient *client = new GameClient();

        while (!client->IsClosing())
        {
            client->Tick();
        }
        return 0;
    }
}
