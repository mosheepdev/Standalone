# Standalone

This is my attempt on creating Game Engine for OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)).

My view at OAA and their ideas about Standalone is at [`OAA.md`](OAA.md).

I am making this to as versatile as possible while keeping base mechanics in C++ code.
That would provide easy support for modders because even the main game will be using the same API and be scripted in LUA.

Some things (2D GUI, Map Editor, Animations...) will take some time.

Meanwhile, feel free to look into this project and take inspiration from it.   


## Important links

- [Standalone Documentation](Documentation/README.md)


- [Open Angel Arena](https://github.com/OpenAngelArena/oaa/)
- [Thinking Bottle](https://thinkingbottle.com)
- [Lumberyard](https://aws.amazon.com/lumberyard/)


## Libraries

- [SDL 2](https://www.libsdl.org/) - Window management
- [OpenGL](https://www.opengl.org/) - 3D Rendering
- [GLEW](http://glew.sourceforge.net/) - OpenGL Extension Wrangler
- [GLM](https://glm.g-truc.net/) - OpenGL Mathematics
- [LUA](https://www.lua.org/) - Scripting Language (Modified)

## Command-Line Arguments

|                     Argument                    |               Description            |
|-------------------------------------------------|--------------------------------------|
| -h, --help                                      | Display help.                        |
| -v, --version                                   | Show version info.                   |
| -d, --debug                                     | Start in debug mode.                 |
| -s, --server                                    | Start as Dedicated Server.           |
| --language &lt;name&gt;                         | Start in specified language.         |
| -f, --fullscreen                                | Start client in Fullscreen mode.     |
| -w, --windowed                                  | Start client in Windowed mode.       |
| --resolution &lt;width&gt; &lt;height&gt;       | Start client in Windowed mode.       |
| --join_lobby &lt;lobby_id&gt;                   | Join specified lobby.                |
| --join_lobby &lt;lobby_id&gt; &lt;password&gt;  | Join specified lobby using password. |
| --join_party &lt;party_id&gt;                   | Join specified party.                |