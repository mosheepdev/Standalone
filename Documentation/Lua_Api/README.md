# Lua Api

LUA [5.3](https://www.lua.org/versions.html#5.3).5
- [Official Manual](https://www.lua.org/manual/5.3/)
- [Download](https://www.lua.org/ftp/lua-5.3.5.tar.gz) (`.tar.gz`)
- [Readme](https://www.lua.org/manual/5.3/readme.html) ([Changes since 5.2](https://www.lua.org/manual/5.3/readme.html#changes))
- [Online Source](https://www.lua.org/source/5.3/)

Instances of LUA are separated for Client and Server.

## API

Only [`Ability`](Ability/README.md) (+[`Item`](Item/README.md)) and [`Modifier`](Modifier/README.md) (+ [`Modifier_Ability`](Modifier/Ability/README.md) and [`Modifier_Item`](Modifier/Item/README.md)) can be overloaded in LUA.

C++ [Enums](Enums/README.md) are implemented as global variables with unique name based on the enum name.

- [`Global`](Global/README.md)
  - TeamFlags GetTeamFlag(Team team)
  - bool HasTeam(TeamFlags flags, Team team)
- [`Map`](Map/README.md)
  - Current Map (Client Only)
    - Map.GetCurrentMap()
    - Map ["CurrentMap"]
  - Map for Entity
    - Map.GetMapFor(handle entity)
    - Map.GetMapFor(int entityId)
  - Map.GetMap(string name)
  - Map.GetAllMaps()
  - Map.LoadMap(string name)
  - Map.UnloadMap(string name)
- [`Player`](Player/README.md)
  - Gold
    - int GetGoldPerMinute()
    - void SetGoldPerMinute(int gpm)
    - int ["GPM"]
  - Team GetTeam()
  - bool IsLocal()
  - Units
    - Unit GetMainHero()
    - Unit[] GetAllUnit()
    - Unit[] GetAllHeroes()
    - Unit[] GetAllNonHeroUnits()
  - long GetUserId() -- Global database-based ID of the user/player, does not change
  - string GetName() -- User-defined name of the player
  - string GetDisplayName() -- [ GetClanTag() ] GetName()
  - Clan
    - bool HasClan()
    - string GetClanName()
    - string GetClanTag() -- Prefix before name
  - bool IsPaidUser() -- Gave some money into the game
  - bool IsTrustedUser() -- Was marked by developers as trust-worthy
- [`Unit`](Unit/README.md)
  - XP
    - int GetExperiencePerMinute()
    - void SetExperiencePerMinute(int xmp)
  - [`Hero`](Hero/README.md)
  - [`Boss`](Boss/README.md)
- [`Ability`](Ability/README.md)
  - [`Item`](Item/README.md) 
- [`Modifier`](Modifier/README.md)
  - [`Modifier_Ability`](Modifier/Ability/README.md)
  - [`Modifier_Item`](Modifier/Item/README.md)

## Utility
- [`Timers`](Timers/README.md)
  - int Timers.CreateTimer(float seconds, function callback)
  - int Timers.CreateTimer(function callback) - every tick
  - void Timers.RemoveAll()
  - void Timers.Remove(int timerId)
- [`Events`](Events/README.md)
- [`Math`](https://www.lua.org/manual/5.3/manual.html#6.7)
- [`Table`](https://www.lua.org/manual/5.3/manual.html#6.6)
- [`Bit`](Bit/README.md)
  - int Bit.BinOr(int num0, int num1)
  - int Bit.BinAnd(int num0, int num1)
  - int Bit.BinNand(int num0, int num1)
  - int Bit.BinNor(int num0, int num1)
  - int Bit.BinXor(int num0, int num1)
  - int Bit.BinNot(int num)
  - int Bit.LeftShift(int num, int shift)
  - int Bit.RightShift(int num, int shift)
  - int Bit.ToHex(int num)
  - int Bit.ToBin(int num)
- [`ParticleManager`](ParticleManager/README.md)
  - int CreateParticles(string name)
  - int CreateParticles(string name, handle entity) - Create particles with cosmetics on the entity in count (some cosmetics may say that cosmetics X is redirected to Y)
  - void SetParticleVariable(int particleId, string key, int value)
  - void SetParticleVariable(int particleId, string key, float value)
  - void SetParticleVariable(int particleId, string key, Vector2 value)
  - void SetParticleVariable(int particleId, string key, Vector3 value)
  - void SetParticleVariable(int particleId, string key, Vector4 value)
  - void SetParticleVariable(int particleId, string key, handle value)
  - void DestroyParticle(int particleId)
- [`ProjectileManager`](ProjectileManager/README.md)
  - int CreateHomingProjectile(table projectileInfo, function onHit)
  - int CreateLinearProjectile(table projectileInfo, function onHit)
  - Vector3 GetProjectilePosition(int projectileId)
  - void DestroyProjectile(int projectileId)
- [`SharedTable`](SharedTable/README.md) = Data accessible from both Client and Server
  - void SharedTable.Set(string name, int key, object value)
  - void SharedTable.Set(string name, string key, object value)
  - void SharedTable.Remove(string name, int key) => :Set(name, key, nil)
  - void SharedTable.Remove(string name, string key) => :Set(name, key, nil)
  - object SharedTable.Get(string name, int key)
  - object SharedTable.Get(string name, string key)

## Client Only
- [`Gui`](Gui/README.md)
  - RemoveAllGui()
  - CreateElement(string tagName, table attributes, handle parentElement)
  - FindElementById(string elementId)
  - GetPlayer()

## Server Only
- [`Http`](Http/README.md)
  - Request(string url, table parametersGet, table parametersPost)

## Storage
- Vectors
  - [`Vector2`](Vector2/README.md)
    - float Length()
    - Vector2 Normalized()
    - Vector2 *(Vector2 v, float mult)
    - Vector2 +(Vector2 v1, Vector2 v2)
    - float .x
    - float ["x"]
    - float .y
    - float ["y"]
  - [`Vector3`](Vector3/README.md)
    - float Length()
    - Vector3 Normalized()
    - Vector3 *(Vector3 v, float mult)
    - Vector3 +(Vector3 v1, Vector3 v2)
    - float .x
    - float ["x"]
    - float .y
    - float ["y"]
    - float .z
    - float ["z"]
  - [`Vector4`](Vector4/README.md)
    - float Length()
    - Vector4 Normalized()
    - Vector4 *(Vector4 v, float mult)
    - Vector4 +(Vector4 v1, Vector4 v2)
    - float .x
    - float ["x"]
    - float .y
    - float ["y"]
    - float .z
    - float ["z"]
    - float .w
    - float ["w"]
- [`QAngle`](QAngle/README.md) = Euler's Angles stored in `Vector3` (Pitch, Yaw, Roll)
- [`Quaternion`](Quaternion/README.md)
