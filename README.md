# Standalone

Versatile Game and Custom-game Engine written in [C++](https://en.wikipedia.org/wiki/C%2B%2B).

All game logic (both official and custom) is scripted in [LUA](https://www.lua.org/).

## Work-in-Progress

This project is not done yet but is being worked-on.

Game Engine has multiple parts:
- Client
- Dedicated Server
- Editor

There is currently only 1 programmer working on all of this.

Any help is welcomed.
Contact [Abit Gray](https://github.com/AbitTheGray/) for more info.

## Team

- [Abit Gray](https://github.com/AbitTheGray/)
  - Programmer
  - Project Leader
- Snowflake Gray
- Haxxepod
  - Game Design + Balance
  - Community

## Origins

This started as own standalone implementation of OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)) from [Thinking Bottle](https://www.thinkingbottle.com/).

Started from same idea but this project is going different route from them.
They have money for development and do it for money. That is not what this projects aims to.

## AI / Bots

There is 100% chance we will make bots... when the time comes (probably in `Beta`).

Current idea of how to make those is:
- Simple AI for 10 heroes
- Simple AI for all heroes
- Hero-specific AI for all heroes

The idea is not to replace players but allow players to practise even without time for full match.

## Game Modes

- Moba ([DotA](https://en.wikipedia.org/wiki/Defense_of_the_Ancients))
  - 5v5
    - Ranked
    - Unranked
  - 10v10
    - Unranked
- Arena (Similar to [Warcraft 3](https://en.wikipedia.org/wiki/Warcraft_III:_Reign_of_Chaos)'s [Angel Arena](https://gaming-tools.com/warcraft-3/angel-arena/))
  - 5v5
    - Ranked
    - Unranked
  - 10v10
    - Unranked
- Boss Battle
  - 5v5

## Languages

|   Name   | Text | Voice | Priority |
|----------|-----:|------:|:--------:|
| English  |  WIP |    0% |   High   |
| Czech    |   0% |   -   |  Normal  |
| Russian  |   0% |   -   |   Low    |
| Japanese |   0% |   -   |   Low    |
| Chinese  |   0% |   -   |   Low    |

Czech has `Normal` priority instead of `Low` because we can do that one with our dev team.

We do not have translators for `Russian`, `Japanese` and `Chinese`.

Voice language is currently planned only `English`.

## Libraries

- [SDL 2](https://www.libsdl.org/) - Window management
- [OpenGL](https://www.opengl.org/) - 3D Rendering
- [GLEW](http://glew.sourceforge.net/) - OpenGL Extension Wrangler
- [GLM](https://glm.g-truc.net/) - OpenGL Mathematics
- [LUA](https://www.lua.org/) 5.3 - Scripting Language ([Manual](https://www.lua.org/manual/5.3/) + [Source](https://www.lua.org/source/5.3/))

## Command-Line Arguments

|                     Argument                    | Description |
|-------------------------------------------------|-------------|
| -h, --help                                      | Display help.
| -v, --version                                   | Show version info.
| -e, --editor                                    | Starts [Editor Tools](Documentation/Editor/README.md).
| -s, --server                                    | Start as Dedicated Server.
| -d, --debug                                     | Start in debug mode.
| --language &lt;name&gt;                         | Start in specified language.
| -f, --fullscreen                                | Start client in Fullscreen mode.
| -w, --windowed                                  | Start client in Windowed mode.
| --resolution &lt;width&gt; &lt;height&gt;       | Start client in Windowed mode.
| --join_lobby &lt;lobby_id&gt;                   | Join specified lobby.
| --join_lobby &lt;lobby_id&gt; &lt;password&gt;  | Join specified lobby using password.
| --join_party &lt;party_id&gt;                   | Join specified party.

## Usage

Not even in `Alpha` state yet.

### Compilation

#### Required libraries
```bash
apt install -y build-essential
apt install -y liblua5.3-dev libsdl2-dev libglew-dev libglm-dev
```

#### Compile
```bash
cmake CMakeLists.txt
```
Is is recommended to compile from [CLion](https://www.jetbrains.com/clion/).

### Run

#### Client

```bash
./Standalone.exe
```

#### Editor

```bash
./Standalone.exe --editor
```

#### Dedicated Server

```bash
./Standalone.exe --server
```
