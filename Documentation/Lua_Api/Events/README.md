# Events

## Functions

### Register Listener

```
function Events.RegisterListener(string eventName, function callback)
```

#### Usage
```lua
Events.RegisterListener("game.start", function(event) print("Game Start") end)

function OnGameEnd(event)
    print("Game End") 
end
Events.RegisterListener("game.end", OnGameEnd)
```

### Call Event

```
function Events.CallEvent(string eventName, table eventData)
```

#### Usage
```lua
Events.CallEvent("custom.tick", {})
```

### Remove All Listeners

```
function Events.RemoveAllListeners()
function Events.RemoveAllListeners(string eventName)
```

#### Usage
```lua
Events.RemoveAllListeners()

Events.RemoveAllListeners("game.start")
```

## All Default Events

- **game**
  - `game.start`
  - `game.end`
    - `float time` = total time in seconds of the game
  - `game.tick` = may have different tick rate on client and server
- **unit**
  - `unit.create` = unit created but not yet spawned
  - `unit.spawn` = unit spawned
  - `unit.death` = unit died
  - `unit.cast.start` = unti started casting an ability
    - `handle unit`
    - `int unitId`
    - `string abilityName`
    - `string abilityLevel`
    - `vec2 targetPosition`
    - `handle targetUnit`
  - `unit.cast.end` = unit casted ability
    - `handle unit`
    - `int unitId`
    - `string abilityName`
    - `string abilityLevel`
    - `vec2 targetPosition`
    - `handle targetUnit`
  - `unit.cast.channel.start` = unit started channeling
  - `unit.cast.channel.end` = unit ended channeling
- **hero**
  - all from **unit** but replace `unit.` by `hero.`
  - `hero.intentory.change`
  - `hero.intentory.drop` = on item drop
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