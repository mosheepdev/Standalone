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
`event` will __always__ contain `.name` equal to `eventName`

#### Usage
```lua
Events.RegisterListener(self, "Game.Start", function(event) print("Game Started") end)

function OnGameEnd(event)
    print("Game Ended") 
end
Events.RegisterListener(self, "Game.End", OnGameEnd)
```

### Call Event

```
void Events.CallEvent(string eventName, table eventData)
```

#### Usage
```lua
Events.CallEvent("Custom.Tick", {})
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

Events.RemoveAllListeners(self, "Game.Start")
```

## All Default Events

- **game**
  - `Game.Start`
  - `Game.End`
    - `float time` = total time in seconds of the game
  - `Game.Tick` = may have different tick rate on client and server
- **unit**
  - `Unit.Create` = unit created but not yet spawned
    - `Unit unit`
  - `Unit.Spawn` = unit spawned
    - `Unit unit`
  - `Unit.Death` = unit died
    - `Unit unit`
    - `Unit killerUnit`
  - `Unit.Cast.Start` = unit started casting an ability
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `Unit.Cast.End` = unit casted ability
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `Unit.Cast.Channel.Start` = unit started channeling
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
  - `Unit.Cast.Channel.End` = unit ended channeling
    - `Unit unit`
    - `Ability ability`
    - `vec3 targetPosition`
    - `vec3 direction`
    - `Unit targetUnit`
    - `float elapsedDuration`
    - `bool fullDuration` = false if stopped by user or other interrupt
- **hero**
  - all from **unit** but replace `Unit.` by `Hero.`
  - `Hero.Intentory.Change`
    - `Unit unit`
  - `Hero.Intentory.Drop` = on item drop
    - `Unit unit`
    - `Item item`
- **boss**
  - all from **unit** but replace `Unit.` by `Boss.`
- hero_picking
  - `Hero_Picking.Select`
    - `string heroName` = unit name of the selected hero
  - `Hero_Picking.Pick`
    - `string heroName` = unit name of the selected hero
    - `bool random` = `true` if hero was assigned by random (either by RANDOM button or time-out) 
  - `Hero_Picking.Ban`
    - `string heroName` = unit name of the banned hero
