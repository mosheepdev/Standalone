# Events

## Functions

### Register Listener

```
void Events.RegisterListener(Ability ability, string eventName, function callback)
void Events.RegisterListener(Modifier modifier, string eventName, function callback)
```
```
void Callback(table event)
```
`event` will alway contain `.name` equal to `eventName`

#### Usage
```lua
Events.RegisterListener(self, "game.start", function(event) print("Game Start") end)

function OnGameEnd(event)
    print("Game End") 
end
Events.RegisterListener(self, "game.end", OnGameEnd)
```

### Call Event

```
void Events.CallEvent(string eventName, table eventData)
```

#### Usage
```lua
Events.CallEvent("custom.tick", {})
```

### Remove All Listeners

```
void Events.RemoveAllListeners(Ability ability)
void Events.RemoveAllListeners(Ability ability, string eventName)

void Events.RemoveAllListeners(Modifier modifier)
void Events.RemoveAllListeners(Modifier modifier, string eventName)
```

#### Usage
```lua
Events.RemoveAllListeners(self)

Events.RemoveAllListeners(self, "game.start")
```

## All Default Events

- **game**
  - `game.start`
  - `game.end`
    - `float time` = total time in seconds of the game
  - `game.tick` = may have different tick rate on client and server
- **unit**
  - `unit.create` = unit created but not yet spawned
    - `Unit unit`
  - `unit.spawn` = unit spawned
    - `Unit unit`
  - `unit.death` = unit died
    - `Unit unit`
    - `Unit killerUnit`
  - `unit.cast.start` = unit started casting an ability
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `unit.cast.end` = unit casted ability
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `unit.cast.channel.start` = unit started channeling
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `unit.cast.channel.end` = unit ended channeling
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
    - `float elapsedDuration`
    - `bool fullDuration` = false if stopped by user or other interrupt
- **hero**
  - all from **unit** but replace `unit.` by `hero.`
  - `hero.intentory.change`
    - `Unit unit`
  - `hero.intentory.drop` = on item drop
    - `Unit unit`
    - `Item item`
- **boss**
  - all from **unit** but replace `unit.` by `hero.`
- hero_picking
  - `hero_picking.select`
    - `string heroName` = unit name of the selected hero
  - `hero_picking.pick`
    - `string heroName` = unit name of the selected hero
    - `bool random` = `true` if hero was assigned by random (either by RANDOM button or time-out) 
  - `hero_picking.ban`
    - `string heroName` = unit name of the banned hero