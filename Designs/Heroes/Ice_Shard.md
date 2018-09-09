# Ice Shard

## Info
Sex: `Female`

Cute feral [Snow Leopard](https://en.wikipedia.org/wiki/Snow_leopard).

## Lore

## Attributes

**Agility**

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    12    | 1.9  |
| Agility      |    27    | 2.9  |
| Intelligence |    14    | 1.6  |
| Charisma     |    13    | 1.7  |


|    Attribute     | Moba Value | Angel Arena Value |
|------------------|------------|-------------------|
| Attack Range     |    150     |        150        |
| Vision           | 1600 / 800 |     1600 / 800    |
| Damage           |  25 - 31   |      25 - 31      |
| Base Attack Time |    1.7     |        1.7        |
| Movement Speed   |    300     |        300        |
| Original Armor   |      1     |          1        |

## Abilities

### Scared Jump

Type: `Active`

Jumps back from current facing direction.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 45 | 45 / 40 / 35 / 30 / 25 / 20 |
| Cast Point | 0.1 | 0.1 |
| Duration | 0.15 | 0.15 |
| Range | 150 / 300 / 450 / 600 | 100 / 200 / 300 / 400 / 500 / 600 |

Notes:
- Provides invincibility frames during the jump
- The hero ends facing same direction as the jump
  - Rotated by 180° during the jump

### Thrill of the Hunt

Type: `Active`, `Aura`

Aura which need to be activated.

Provides self and allies with Attack Speed and Lifestal.

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 45 | 45 |
| Cast Point | 0.1 | 0.1 |
| Cast Radius | 600 | 600 |
| Attack Speed | 10 / 20 / 30 / 40 | 10 / 20 / 30 / 40 / 50 / 60 |
| Lifesteal | 5.0% / 7.5% / 10.0% / 15.0% | 5.0% / 7.5% / 10.0% / 15.0% / 20.0% / 25.0% |
| Duration | 4 / 6 / 8 / 10 | 4 / 6 / 8 / 10 / 12 / 16 |

### Bleeding Wounds

Type: `Passive`

Each attack applies debuff on enemies.
Deals bonus **Pure** damage.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Bonus Damage Per Stack | 10 / 15 / 20 / 25 | 10 / 15 / 20 / 25 / 35 / 50 |
| Duration | 5 / 10 / 15 / 20 | 5 / 10 / 15 / 20 / 25 / 30 |

Note:
- Not Affected by `Status Resistance`
- Removed on respawn
- Damage is deals after the attack but before adding new stack
  - First attack does 0 damage from stacks

Think:
- Increase bonus damage but after geting healed for more then X, the debuff is purged

### Stealthy Cat
**__Ultimate__**

Type: `Active`

Goes into invisibility.

When not seen by enemies, gains increased movement speed and bonus damage for next attack.

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Manacost | ? | ? |
| Cooldown | ? | ? |
| Duration | ? | ? |
| Not Seen Bonus Damage | ? | ? |
| Not Seen Bonus Movement Speed | ? | ? |
| Not Seen Cooldown | 6 | 6 |

Notes:
- Neutrals are not counted
- Both `Cooldown` and `Not Seen Cooldown` are affected by `Cooldown Reduction`
