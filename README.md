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


## Money

The one big thing which moves the world.
How to get as much of it from players?:

- Skins
  - Hero
    - Parts of items which makes the full set
    - Can buy whole set or just an item (total price of items at about 120% to 140% of full-set price)
  - Ingame GUI
  - Loading Screen
  - Map (and ambient models)
  - Announcers
  - Chests (Lootboxes)
    - Cannot get item which you already own
    - Chests with specified content (Hero items, GUIs, Announcers...)
    - 90% of weighted average of cost of its items
- Bottlepass
  - For tournaments (part of price pool)
  - Payed levels
  - Closed after 3/6/12 months
  - Challenges with rewards
- (Temporary) dedicated server
  - For custom games to allow hosting on dedicated server, payment per dedicated server
- Percentage from all payments to other custom games
  - 10% to 30% (up to 50% can be discussed)
  - Allow custom-made cosmetics for other games
- Collector's case
  - Item from game as statue + Art book
  - High price
  - After going out of Beta to Release

I strongly disagree with payed heroes + Hero Pool.
Yes, it allows for more rotation of meta in for beginner players and take some money from them (to keep their hero which they are getting used to).

It also forces you to assign price to the hero. That is often done by having different price for each hero which is like saying - you want stronger hero? Pay for it or wait.

This was biggest reason for me to switch from [League of Legends](https://leagueoflegends.com/) to [Dota 2](http://www.dota2.com).
