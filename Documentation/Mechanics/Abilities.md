# Abilities

## Execute Order

- `CanBeCast(...)`
  - Check cooldown
  - Check mana
  - Check gold
- `PerformCast(...)`
  - Animation Start
    - Store Cast Point from `GetCastPoint()`
  - Wait until Cast Point
  - `Cast(...)`
    - `ConsumeResources(true, true, true)`
      - Start Cooldown
      - Spend Mana
      - Spend Gold
    - `OnCast(...)`
  - if `GetChannelTime() > 0`
    - Store Channel Time (`GetChannelTime()` is called only once)
    - Wait Channel Time
    - `OnChannelEnd()`
  - Cast backswing time
  - Animation end
  
### Notes

- May consume less mana
  - Mana is checked only at start of the spell
  - Cannot consume mana below 0 of owner
  - Same applies to gold
  
## Ability types

### By Targeting

- None
- Point
- Unit (at point)
- Direction (from caster)
- Vector (point + direction)
- Unit Vector (from unit + direction)

### By Target

- None
- Point
- Unit
  - Creep
  - Hero
  - Boss
  - Building
- Tree

## Levels

| Type | Levels |
|------|:------:|
| Hero - Normal | 6 |
| Hero - Ultimate | 4 |
| Boss | 5 |
| Creep | 1 |

Required levels for Hero Abilities are at [Levels](Levels.md) page.
