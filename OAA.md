# Open Angel Arena

This is my attempt on creating Game Engine for OAA ([Open Angel Arena](https://github.com/OpenAngelArena/oaa/)).

They decided on using Amazon's [Lumberyard](https://aws.amazon.com/lumberyard/) because it has native support for LUA (so you cannot modify as I did here or have any control on its version) and is said to be in C++ (which no-one is using unless LUA is too slow for something).
I even think I have more documentation here than they have.

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
  - For tournaments (part of Price Pool)
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

## Hero Rotation

I strongly disagree with payed heroes + Hero Rotation.
Yes, it allows for more rotation of meta in for beginner players and take some money from them (to keep their hero which they are getting used to).

It also forces you to assign price to the hero. That is often done by having different price for each hero which is like saying - you want stronger hero? Pay for it or wait.

This was biggest reason for me to switch from [League of Legends](https://leagueoflegends.com/) to [Dota 2](http://www.dota2.com).

Even when you consider Hero Rotation:
- Allow new players to **chose** 1 or 2 heroes which they will be able to keep as if they payed for them
  - Long-time learning of the hero (for casual players, often with a coach)
  - May wait few games to use Hero Rotation's heroes to figure out favorite hero to learn
- Make new heroes temporary free
  - Will allow for better balance because of more played matches with him
- Add reward for versatility
- Allow all heroes in tournaments
  - Unique (temporary) tournament key
  - Tournaments may be required to pay fee based of amount of players/team

## What I would like to see in Standalone

### Proper documentation

When you look at my WIP documentation here, there is a lot of functions which cannot be overloaded in LUA because they will not have effect on C++ code.
But those are marked by bold text saying `Should not be overloaded. (no effect on C++ code)`.

Reason for this are either utility functions (calculating [`GetCurrentCooldownPercentage()`](Documentation/Lua_Api/Ability/README.md#Get_Current_Cooldown_Percentage)) or functions interacting directly with internal mechanics ([`GetOwner()`](Documentation/Lua_Api/Ability/README.md#Get_Owner) or [`GetCurrentCooldownRemaining()`](Documentation/Lua_Api/Ability/README.md#Get_Current_Cooldown_Remaining)).
Using overloaded versions of those functions could cause instabilities in game.

Some of abilities even have `Implemented as` block to show their base (default) implementation.
This also applies for some functions which cannot be overloaded to show their functionality in LUA even if they are C++ only.