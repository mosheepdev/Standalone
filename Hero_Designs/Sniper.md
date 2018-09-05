# Sniper

## Info

## Lore

During great war, even Time can be damaged.
Those caught in can be moved in time.

## Attributes

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    16    | 2.4  |
| Agility      |    20    | 2.9  |
| Intelligence |    14    | 2.1  |
| Charisma     |    13    | 1.7  |


|  Attribute   | Moba Value | Angel Arena Value |
|--------------|------------|-------------------|
| Attack Range |    800     |        800        |
| Vision       | 1600 / 800 |     1600 / 800    |
| Damage       |  22 - 24   |      22 - 24      |

## Abilities

### Mark

Type: `Any Unit`

Marks target unit.
Marked units are visible to caster's team (even when invisible = `True Sight`).

Provides vision on hit target (no `True Sight`) as passive component.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30.0 | 30.0 / 30.0 / 30.0 / 30.0 / 20.0 / 10.0 |
| Cast Range | `Vision` | `Vision` |
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
| Manacost | ? | ? |
| Cooldown | ? | ? |
| Cast Point | 0.2 | 0.2 |
| Channel Time | 1.0 | 1.0 |
| Heal | 2.5% / 5% / 7.5% / 10% | 2% / 4% / 6% / 8% / 12% / 15%  |
| Min Heal * | 100 / 200 / 300 / 400 | 100 / 200 / 300 / 400 / 600 / 800 |
| Radius | 200 | 200 |

`*` Affected by `Spell Amplification`

Talents:
- `Cast Point` instead of channel
  - Does not go on cooldown when interrupted

### ???

Type: ``

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | ? | ? |
| Cast Point | ? | ? |

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