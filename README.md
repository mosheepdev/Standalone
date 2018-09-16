# Standalone

Versatile Game and Custom-game Engine written in [C++](https://en.wikipedia.org/wiki/C%2B%2B).

All game logic (official and custom) is scripted in [LUA](https://www.lua.org/).

This started as own implementation of OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)) from [Thinking Bottle](https://www.thinkingbottle.com/).
Started from same idea but this project is going different route from them.
They have money for development and do it for money. That is not what this projects aims to.


Still **Work-In-Progress**.
Some things (2D GUI, Map Editor, Animations...) will take some time to be done.

## Game Modes

- Moba ([DotA](https://en.wikipedia.org/wiki/Defense_of_the_Ancients))
- Arena (Similar to [Warcraft 3](https://en.wikipedia.org/wiki/Warcraft_III:_Reign_of_Chaos)' [Angel Arena](https://gaming-tools.com/warcraft-3/angel-arena/))

## Concepts
- [Items](Designs/Item/README.md)
- Units
  - [Creeps](Designs/Creep/README.md)
  - [Heroes](Designs/Hero/README.md)
  - [Bosses](Designs/Boss/README.md)

## Languages

| Name | Progress | Priority |
|------|---------:|:--------:|
| English  |   0% |   High   |
| Czech    |   0% |  Normal  |
| Russian  |   0% |   Low    |
| Japanese |   0% |   Low    |
| Chinese  |   0% |   Low    |

## Contributors

This project is made by small group of friends.

Any help is welcomed.
Contact [Abit Gray](https://github.com/AbitTheGray/) for more info.


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

Not even in `Alpha` state yet.

### Compilation

```
cmake CMakeLists.txt
```
Is is recommended to compile from [CLion](https://www.jetbrains.com/clion/).

### Client

```
Standalone.exe
```

### Dedicated Server

```
Standalone.exe --server
```
