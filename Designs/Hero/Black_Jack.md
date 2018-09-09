# Black Jack

## Info
Sex: `Male`

Wears black suit.

## Lore

## Attributes

**Charisma**

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    17    | 1.1  |
| Agility      |    19    | 2.4  |
| Intelligence |    25    | 2.1  |
| Charisma     |    29    | 2.7  |


|    Attribute     | Moba Value | Angel Arena Value |
|------------------|------------|-------------------|
| Attack Range     |    400     |        400        |
| Attack Type      |   Ranged   |       Ranged      |
| Vision           | 1600 / 800 |     1600 / 800    |
| Damage           |  21 - 31   |      21 - 31      |
| Base Attack Time |    1.5     |        1.5        |
| Movement Speed   |    310     |        310        |
| Original Armor   |     -2     |         -2        |

## Abilities

### Snake Eyes

Type: `Enemy Unit`

Throws 2 dice on target dealing damage based on initial random value.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | ? | ? |
| Cast Range | 400 | 400 |
| Cast Point | 0.4 | 0.4 |
| Duration | 10 | 10 |
| Min Damage | 5 / 10 / 15 / 20 | 5 / 10 / 15 / 20 / 25 / 30 |
| Max Damage | 20 / 30 / 40 / 50 | 20 / 30 / 40 / 50 / 70 / 90 |
| Min Total Damage | 50 / 100 / 150 / 200 | 50 / 100 / 150 / 200 / 250 / 300 |
| Max Total Damage | 200 / 300 / 400 / 500 | 200 / 300 / 400 / 500 / 700 / 900 |

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

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 | 30 |
| Cast Point | 0.15 | 0.15 |
| Hidden Time | 0.15 | 0.15 |
| Illusion Count | 2 / 3 / 4 / 5 | 2 / 3 / 4 / 5 |
| Illusion Damage Taken | 400% | 400% |
| Illusion Damage Dealt | 20% / 40% / 60% / 80% | 20% / 40% / 60% / 80% / 100% / 125% |
| Illusion Duration | 5 | 5 |

Note:
- Rotation of the shape depends on caster's rotation

### Experienced Player

Type: `Passive`

Can see through obstacles and on highground.
Because of experience.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Vision Increase | 0 / 150 / 300 / 500 | 0 / 100 / 200 / 300 / 400 / 500 |

Note:
- First level only provides unobstructed vision

### Joker
**__Ultimate__**

Type: `Active`

While active, provides Status Resistance and All Damage Reduction.

Hard Dispell on activation.

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 60 | 60 |
| Cast Point | 0 | 0 |
| Status Resistance | 50% / 75% / 100% | 25% / 50% / 75% / 100% / 100% |
| Incoming Damage Reduction | 50% | 50% |
| Duration | 6 | 4 / 5 / 6 / 10 / 15 |

Note:
- Changes his clothes into purple
