# Plague Doctor

## Info
Sex: `Male`

Doctor but also tool of the Plague

Appearance:
- White Plague Doctor mask
- Top Hat
- Long Coat

Cosmetics:
- Crow Set

## Lore

## Attributes

**Intelligence**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    30    | 1.3  |
| Agility      |    13    | 1.6  |
| Intelligence |    20    | 2.7  |
| Will         |    19    | 2.4  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     640     |
| Attack Type      |    Ranged   |
| Projectile Speed |    1,000    |
| Vision           | 1,600 / 800 |
| Damage           |   17 - 19   |
| Base Attack Time |     1.7     |
| Movement Speed   |     285     |
| Original Armor   |    -1.5     |

## Abilities

### The Doctor

Type: `Unit`

Heal on allies, Damage on enemies.

Does `Soft Dispell` on the target (debuffs on allies, buff on enemies).

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 13 |
| Cast Range | 770 |
| Cast Point | 0.18 |
| Damage | 50 / 90  / 130 / 200 / 290 |
| Heal | 80 / 130 / 180 / 250 / 320 |

Notes:
- Both `Heal` and `Damage` are multiplied by `Spell Amplification`

Lore: `Trust me, I am the Doctor.`

### Medicine

Type: `Point AoE, Channel, Units`

Heals and damages around selected point.
Both increase over time of channel.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 20 |
| Cast Range | 400 |
| Cast Point | 0.12 |
| Cast Radius | 400 |
| Max Channel Time | 10 |
| Min Heal | 8 |
| Max Heal | 400 |
| Min Damage | 8 |
| Max Damage | 400 | 

Notes:
- Heal or Damage in 0.25 intervals
- Heal and Damage are increased by `Spell Amplification`

### Don't Trust Him

Type: `Enemy Unit`

Shames target.

Target is silenced and all attacks crit.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 35 |
| Cast Range | 400 |
| Cast Point | 0.24 |
| Duration | 6 |
| Critical Damage | 110% / 120% / 130% / 140% / 150% / 160% |

### Plague
**__Ultimate__**

Type: `Enemy Unit`

Applies `Plague` debuff on enemy unit.

All enemy units around the debuffed one are damaged for `Area Damage`.

Every enemy hero (or hero-creep or boss) taking `Area Damage` also gets the debuff for original duration.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 120 / 110 / 100 / 90 |
| Cast Range | 700 |
| Cast Point | 0.24 |
| Cast Radius | 100 |
| Area Damage | 100 / 150 / 200 / 250 |
| Debuff Damage | 100 / 150 / 200 / 250 |
| Debuff Duration | 3 |

Notes:
- Having 2 heroes (or hero-creep or boss) next to each other keeps the debuff on them forever
- The initial unit does not need to be hero but takes same damage
- Area damage does not affect the original target
- Effect stays in place for rest of the duration even when the unit dies

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | ? | ? |
| 20 | `Plague` can be cast on ally | ? |
| 25 | ? | ? |
| 30 | ? | ? |
