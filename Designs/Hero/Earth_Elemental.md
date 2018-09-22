# Earth Elemental

## Info
Sex: `Other`



## Lore

## Attributes

**Strength**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    34    | 3.2  |
| Agility      |    10    | 1.8  |
| Intelligence |    16    | 1.9  |
| Will         |    12    | 1.3  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     140     |
| Attack Type      |    Melee    |
| Projectile Speed |      -      |
| Vision           | 1,400 / 700 |
| Damage           |   35 - 36   |
| Base Attack Time |     1.9     |
| Movement Speed   |     280     |
| Original Armor   |     -1      |

## Abilities

### Rock Throw

Type: `Point AoE`, `Enemy Unit`

Throws big rock to target point.
Stuns all hit units in target area.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 11 |
| Cast Range | ? |
| Cast Point | 0.19 |
| Land Delay | 0.11 |
| Cast Radius | 300 |
| Damage | 100 / 300 / 500 / 700 / 900 / 1,100 |
| Stun Duration | 0.9 / 1.3 / 1.7 / 2.1 / 2.5 / 2.9 |

Note:
- Deals Physical Damage

### Earth Spike

Type: `Direction`, `Enemy Unit`

Slams into ground creating wave hitting and stunning enemies on its way.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 13 |
| Cast Range | 400 / 450 / 500 / 550 / 600 / 650 |
| Cast Point | 0.13 |
| Projectile Radius | 100 |
| Projectile Speed | 1,300 |
| Damage | 100 / 130 / 160 / 190 / 220 / 250 |
| Stun Duration | 1.3 |

Note:
- Deals Physical Damage

### Rolling Stone

Type: `Point`

Rolls in direction.

Magic immune during the rolling.

All hit enemy units are attacked (instant attack) and stunned.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 35 / 30 / 25 / 20 / 15 / 10 |
| Cast Range | 1,000 |
| Cast Point | 0.27 |
| Stun Duration | 0 / 0.2 / 0.4 / 0.6 / 0.8 / 1 |

Notes:
- Deals damage before the stun
- Stops when hitting high ground
  - Cannot move up or down
  - Can move on stairs

### Earthquake
**__Ultimate__**

Type: `Active AoE`, `Channel`

Smashing earth creates weaves causing holes in the ground.
Enemies around are kept in place and take high damage from it.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 90 / 80 / 70 / 60 |
| Cast Point | 0.27 |
| Cast Radius | 800 / 1,000 / 1,200 / 1,500 |
| Channel Time | 10 |
| Movement Slow | 15% / 20% / 25% / 30% |
| Root Delay | 2 |
| Root Duration | 3 / 4 / 5 / 6 |
| Damage Per Second | 6% / 8% / 10% / 12% |

Notes:
- Deals Physical Damage based on Maximum Health of Earth Elemental
- Keeps refreshing on the unit while inside of the radius

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | `Rolling Stone` can move up and down high ground | +0.5 `Earth Spike` Stun |
| 20 | +1,000 `Rolling Stone` Cast Range | -1s `Earthquake` Root Delay |
| 25 | ? | +5s `Earthquake` Maximum Channel Time |
| 30 | 25% Chance for 1.0s Bash | +5% `Earthquake` Damage Per Second |
