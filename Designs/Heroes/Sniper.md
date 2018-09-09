# Sniper

## Info
Sex: `Female`

## Lore

During great war, even Time can be damaged.
Those caught in can be moved in time.

## Attributes

**Agility**

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    16    | 2.4  |
| Agility      |    20    | 2.9  |
| Intelligence |    14    | 2.1  |
| Charisma     |    13    | 1.7  |


|    Attribute     | Moba Value | Angel Arena Value |
|------------------|------------|-------------------|
| Attack Range     |    800     |        800        |
| Vision           | 1600 / 800 |     1600 / 800    |
| Damage           |  32 - 34   |      32 - 34      |
| Base Attack Time |    1.9     |        1.9        |
| Movement Speed   |    280     |        280        |
| Original Armor   |      0     |          0        |

## Abilities

### Mark

Type: `Any Unit`

Marks target unit.
Marked units are visible to caster's team (even when invisible = `True Sight`).

Provides vision on hit target (no `True Sight`) as passive component.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | 50 / 60 / 70 / 80 | 50 / 60 / 70 / 80 / 90 / 100 |
| Cooldown | 30.0 | 30.0 / 30.0 / 30.0 / 30.0 / 20.0 / 10.0 |
| Cast Range | `Global` | `Global` |
| Cast Point | 0 | 0 |
| Duration | 5.0 / 10.0 / 20.0 / 30.0 | 10.0 / 20.0 / 30.0 / 40.0 / 50.0 / 60.0 |
| Vision After Hit Duration | 0.8 | 0.8 |

Notes:
- Can target:
  - Creeps
  - Neutrals
  - Bosses
- Has same `Cast Range` as hero's current `Vision Range`

Talents:
- Can target buildings

### Medical Training

Type: `Channel AoE` (Self)

After the channel, heal all allies (including creeps) for `Heal` percentage of his health or `Min Heal` (which is higher).
Total heal is calculated and is split between all affected units.

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Manacost | 120 | 100 / 110 / 120 / 130 / 160 / 200 |
| Cooldown | 45 | 45 |
| Cast Point | 0.2 | 0.2 |
| Cast Radius | 200 | 200 |
| Channel Time | 1.0 | 1.0 |
| Heal | 2.5% / 5% / 7.5% / 10% | 2% / 4% / 6% / 8% / 12% / 15%  |
| Min Heal * | 100 / 200 / 300 / 400 | 100 / 200 / 300 / 400 / 600 / 800 |

`*` Affected by `Spell Amplification`

Talents:
- `Cast Point` instead of channel
  - Does not go on cooldown when interrupted

### Military Ammo

Type: `Toggle`

Some special ammo are... more effective then the others.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | 10 | 10 |
| Bonus Damage | 10 / 20 / 35 / 50 | 10 / 25 / 40 / 60 / 100 / 150 |

Lore: `Dum Dum!`

### Long Barrel
**__Ultimate__**

Type: `Passive`

Lowers Attack Speed but increases Attack Range.

|     Key     |   Moba Value   | Angel Arena Value |
|-------------|----------------|-------------------|
| Attack Speed Reduction |  20 /  40 /  80 |  20 /  40 /  80 / 120 / 160 |
| Attack Range Increase  | 200 / 300 / 600 | 150 / 250 / 400 / 600 / 800 |
| Vision Increase        | 200 / 300 / 600 | 150 / 250 / 400 / 600 / 800 |

Notes:
- Same `Vision Increase` as `Attack Range Increase`
  - Thanks to Sniper's `Night Vision` being equal to `Attack Range`, vision at night is same as `Attack Range`
- Forces the hero's Attack Type to be Ranged
  - In case of Ability Swapping
   
Talents:
- `+200` `Attack Range`
