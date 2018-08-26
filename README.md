# Standalone

This is my attempt on creating Game Engine for OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)).

They decided on using Amazon's [Lumberyard](https://aws.amazon.com/lumberyard/) because it has native support for LUA (so you cannot modify as I did here or have any control on its version) and is said to be in C++ (which noone is using unless LUA is too slow for something).
I even think I have more documentation here than they have.

I have experience in [OpenGL](https://www.opengl.org/) and C/[C++](http://www.cplusplus.com/). I am not expert but... see for yourself.

I am making this to as versatile as possible while keeping base mechanics in C++ code.
That would provide easy support for modders because even the main game will be using the same API.

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
- [LUA](https://www.lua.org/) - Scripting Language (Modified to index from `0`)