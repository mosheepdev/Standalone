#include <iostream>
#include <cstring>

using namespace std;

#include "AppConfiguration.h"
#include "GameClient.h"

bool HasArg(int argc, char *argv[], char arg_short, string arg_long);

int main(int argc, char *argv[])
{
    if(HasArg(argc, argv, 'v', "version"))
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

    if(HasArg(argc, argv, 'h', "help"))
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

    if(HasArg(argc, argv, 's', "server")) // Start dedicated server
    {
        throw std::logic_error("Not Implemented");
    }
    else // Start client
    {
        GameClient *client = new GameClient();

        while (!client->IsClosing())
            client->Tick();
        return 0;
    }
}

bool HasArg(int argc, char *argv[], char arg_short, string arg_long)
{
    for(int i = 1; i < argc; i++)
    {
        char* arg = argv[i];
        if(arg[0] != '-')
            continue;
        if(arg[1] == '\0') // Only 1 minus char
            continue;
        if(arg[1] == '-') // Long argument
        {
            if(strcmp(arg, ("--" + arg_long).c_str()) == 0)
                return true;
        }
        else // Short argument
        {
            for(int j = 1; arg[j] != '\0'; j++)
                if(arg[j] == arg_short)
                    return true;
        }
    }
    return false;
}