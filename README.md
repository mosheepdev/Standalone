# Standalone

**DEVELOPMENT HALTED**

Reason is that I am working alone on this with minimum help while Thinking Bottle has full team of ` !@#$%^ `.

I spend far too much time on this and it will result in nothing.
At least I learned how to work with LUA.

I am not saying that I will not return to this... but I won't.

---

I am making this as versatile as possible while keeping base mechanics in C++ code.
That would provide easy support for modders because even the main game (games) will be using the same API and be scripted in LUA.

Some things (2D GUI, Map Editor, Animations...) will take some time to be done.

## Games

Because this started as Angel Arena engine, there will be a game for it.

I would expect first community-made game be a Moba (DotA = [Defense of the Ancients](https://en.wikipedia.org/wiki/Defense_of_the_Ancients)).
That means I need to make one myself.

Concepts:
 - [Items](Designs/Item/README.md)
 - Units
   - [Creeps](Designs/Creep/README.md)
   - [Heroes](Designs/Hero/README.md)
   - [Bosses](Designs/Boss/README.md)

## Open Angel Arena

At first, this was my attempt on creating Game Engine for OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)).
Because I (Abit Gray) did not get into [Thinking Bottle](https://www.thinkingbottle.com/) Team and before this will be in working stage (`Alpha`), they will have their own at least at same stage.

My view at OAA itself and their ideas about Standalone is at [`OAA.md`](OAA.md). 

## Contributors

This is currently Single-person project of [Abit Gray](https://github.com/AbitTheGray/).

Any help is welcomed. 


## Important links

- [Documentation](Documentation/README.md)
  - [LUA API](Documentation/Lua_Api/README.md)
  - [Tutorial](Documentation/Tutorials/README.md)
  - [Mechanics](Documentation/Mechanics/README.md)
- [Designs](Designs/README.md)


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

## Usage

Is not in state where it can be run.

### Compilation

```

```

### Client

```
Standalone.exe
```

### Dedicated Server

```
Standalone.exe --server
```
