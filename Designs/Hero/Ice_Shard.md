# Ice Shard

## Info
Sex: `Female`

Cute feral [Snow Leopard](https://en.wikipedia.org/wiki/Snow_leopard).

## Lore

## Attributes

**Agility**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    12    | 1.9  |
| Agility      |    27    | 2.9  |
| Intelligence |    14    | 1.6  |
| Will         |    13    | 1.7  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     150     |
| Attack Type      |    Melee    |
| Projectile Speed |      -      |
| Vision           | 1,600 / 800 |
| Damage           |   25 - 31   |
| Base Attack Time |     1.7     |
| Movement Speed   |     300     |
| Original Armor   |      1      |

## Abilities

### Scared Jump

Type: `Active`

Jumps back from current facing direction.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 45 / 40 / 35 / 30 / 25 / 20 |
| Cast Point | 0.1 |
| Duration | 0.15 |
| Range | 100 / 200 / 300 / 400 / 500 / 600 |

Notes:
- Provides invincibility frames during the jump
- The hero ends facing same direction as the jump
  - Rotates by 180° during the jump

### Thrill of the Hunt

Type: `Active`, `Aura`

Aura which need to be activated.

Provides self and allies with Attack Speed and Lifestal.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 45 |
| Cast Point | 0.1 |
| Cast Radius | 600 |
| Attack Speed | 10 / 20 / 30 / 40 / 50 / 60 |
| Lifesteal | 5.0% / 7.5% / 10.0% / 15.0% / 20.0% / 25.0% |
| Duration | 4 / 6 / 8 / 10 / 12 / 16 |

### Bleeding Wounds

Type: `Passive`

Each attack applies debuff on enemies.
Deals bonus **Pure** damage.

| Key | Value |
|-----|:-----:|
| Bonus Damage Per Stack | 10 / 15 / 20 / 25 / 35 / 50 |
| Duration | 5 / 10 / 15 / 20 / 25 / 30 |

Note:
- Not Affected by `Status Resistance`
- Removed on respawn
- Damage is deals after the attack but before adding new stack
  - First attack does 0 damage from stacks
- Refreshes previous stack

Think:
- Increase bonus damage but after getting healed for more then X, the debuff is purged

### Stealthy Cat
**__Ultimate__**

Type: `Active`

Goes into invisibility.

When not seen by enemies, gains increased movement speed and bonus damage for next attack.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | ? |
| Duration | ? |
| Not Seen Bonus Damage | ? |
| Not Seen Bonus Movement Speed | ? |
| Not Seen Cooldown | 6 |

Notes:
- Neutrals are not counted
- Both `Cooldown` and `Not Seen Cooldown` are affected by `Cooldown Reduction`

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | ? | ? |
| 20 | ? | ? |
| 25 | ? | ? |
| 30 | ? | ? |

