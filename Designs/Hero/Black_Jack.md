# Black Jack

## Info
Sex: `Male`

Wears black suit.

## Lore

## Attributes

**Will**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    17    | 1.1  |
| Agility      |    19    | 2.4  |
| Intelligence |    25    | 2.1  |
| Will         |    29    | 2.7  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     400     |
| Attack Type      |    Ranged   |
| Projectile Speed |     600     |
| Vision           | 1,600 / 800 |
| Damage           |   21 - 31   |
| Base Attack Time |     1.5     |
| Movement Speed   |     310     |
| Original Armor   |     -2      |

## Abilities

### Snake Eyes

Type: `Enemy Unit`

Throws 2 dice on target dealing damage based on initial random value.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | ? |
| Cast Range | 400 |
| Cast Point | 0.4 |
| Duration | 10 |
| Min Damage | 5 / 10 / 15 / 20 / 25 / 30 |
| Max Damage | 20 / 30 / 40 / 50 / 70 / 90 |
| Min Total Damage | 50 / 100 / 150 / 200 / 250 / 300 |
| Max Total Damage | 200 / 300 / 400 / 500 / 700 / 900 |

Note:
- Rolls 2 6-sided dices
  - Damage is lineary scaled based on sum of value on dices
    - 3 = min
    - 12 = 90% of damage
  - "Snake Eyes" (1 + 1) triggers maximum damage

### Bluf

Type: `Active`

Disappears from map for a short time coming back with multiple illusions of self.

Appear in predefined shape (1 inside, rest around).
Caster can appear at random position instead of one of illusions (the illusion goes into center).

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 30 |
| Cast Point | 0.15 |
| Hidden Time | 0.15 |
| Illusion Count | 2 / 3 / 4 / 5 / 5 / 5 |
| Illusion Damage Taken | 400% |
| Illusion Damage Dealt | 20% / 40% / 60% / 80% / 100% / 125% |
| Illusion Duration | 5 |

Note:
- Rotation of the shape depends on caster's rotation

### Experienced Player

Type: `Passive`

Can see through obstacles and on highground.
Because of experience.

| Key | Value |
|-----|:-----:|
| Vision Increase | 0 / 100 / 200 / 300 / 400 / 500 |

Note:
- First level only provides unobstructed vision

### Joker
**__Ultimate__**

Type: `Active`

While active, provides Status Resistance and All Damage Reduction.

Hard Dispell on activation.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 60 |
| Cast Point | 0 |
| Status Resistance | 25% / 50% / 75% / 100% |
| Incoming Damage Reduction | 50% |
| Duration | 4 / 6 / 8 / 10 |

Note:
- Changes his clothes into purple

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | ? | ? |
| 20 | ? | ? |
| 25 | ? | ? |
| 30 | ? | ? |
