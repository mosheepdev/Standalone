# Hunter

## Info
Sex: `Male`



## Lore

## Attributes

**Agility**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    26    | 2.4  |
| Agility      |    24    | 2.1  |
| Intelligence |    14    | 1.7  |
| Will         |    17    | 1.2  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     170     |
| Attack Type      |    Melee    |
| Projectile Speed |      -      |
| Vision           | 1,800 / 1,200 |
| Damage           |   20 - 26   |
| Base Attack Time |     1.6     |
| Movement Speed   |     300     |
| Original Armor   |     -2      |

## Abilities

### Trap

Type: `Point`,`Enemy Unit`

Places invisible trap on ground.

When triggered by enemy, all enemies in radius are Rooted and take Physical Damage

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 20 / 19 / 18 / 17 / 16 / 15 |
| Cast Range | 100 |
| Cast Point | 0.1 |
| Trap Duration | 30 / 60 / 90 / 120 / 150 / 180 |
| Trigger Radius | 200 |
| Trigger Delay | 0.25 |
| Effect Duration | 6 |
| Damage | 100 / 120 / 140 / 160 / 180 / 200 |

### Hunter's Mark

Type: `Enemy Unit`

Marks unit by shout.
All attackers to the unit have guaranteed Critical hit.

| Key | Value |
|-----|:-----:|
| Manacost | 25 / 35 / 45 / 55 / 70 / 100 |
| Cooldown | 20 |
| Cast Range | 800 / 900 / 1,000 / 1,100 / 1,200 / 1,300 |
| Cast Point | 0.1 |
| Duration | 8 |
| Critical Damage | 115% / 125% / 135% / 145% / 160% / 190% |

### Hunting Hound

Type: `Active`

Summons companion for hunting.

| Key | Value |
|-----|:-----:|
| Manacost | 50 |
| Cooldown | 30 |
| Cast Point | 0.3 |
| Summon Duration | 60 |

Hound Values

| Key | Value |
|-----|:-----:|
| Health | 230 / 340 / 450 / 600 / 800 / 1,000 |
| Base Attack Time | 1.3 |
| Attack Damage | 20 / 30 / 40 / 60 / 90 / 120 |
| Armor | Same as Caster |
| Magic Resistance | Same as Caster |

Notes:
- `Armor` and `Magic Resistance` is copied on summon, not updated later
- Talent doubles only base values

### Tracking
**__Ultimate__**

Type: `Active`

When activated, places debuff on all enemies around.

Debuff makes them visible through Fog of War and Reveal them.

| Key | Value |
|-----|:-----:|
| Manacost | 70 |
| Cooldown | 60 |
| Cast Point | 0.5 |
| Radius | 2,500 / 5,000 / 7,500 / 10,000
| Invisible Radius | 250 / 500 / 750 / 1,000

Notes:
- Affects invisible units in smaller radius then visible
  - When already debuffed, affected unit will keep Reveal
- Ignores FoV

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | +200 `Hunter's Mark` Cast Range | -0.1s `Trap` Trigger Delay |
| 15 | -0.2s `Tracking` Cast Point | +2s `Trap` Effect Duration |
| 20 | +4s `Hunter's Mark` Duration | -20s `Hunting Hound` Cooldown |
| 25 | -30s `Tracking` Cooldown | +120s `Trap` Duration |
| 30 | +25% Critical Damage of `Hunter's Mark` | Double `Health` and `Attack Damage` of `Hunting Hound` |
