# Harpy

## Info
Sex: `Other`



## Lore

## Attributes

**Strength**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    20    | 3.0  |
| Agility      |    12    | 1.9  |
| Intelligence |    11    | 1.4  |
| Will         |    18    | 1.6  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     150     |
| Attack Type      |    Melee    |
| Projectile Speed |     600     |
| Vision           | 1,600 / 800 |
| Damage           |   18 - 28   |
| Base Attack Time |     2.0     |
| Movement Speed   |     280     |
| Original Armor   |     -1      |

## Abilities

### Acid Spit

Type: `Direction`, `Enemy Unit`

Spits acid in direction cone.
Decreases Armor, Silence and deal DoT.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | ? |
| Cast Range | ? |
| Cast Point | 0.1 |
| Projectile Speed | 1,800 |
| Duration | 1 / 2 / 3 / 4 / 5 / 6 |
| Damage Per Second | 20 |
| Total Damage | 20 / 40 / 60 / 80 / 100 / 120 |
| Reduced Armor | 2 / 3 / 4 / 5 / 6 / 7 |

### Strong Grab

Type: `Enemy Unit`

Holds target and pulls it towards self.

| Key | Value |
|-----|:-----:|
| Manacost | 100 |
| Cooldown | 30 / 28 / 26 / 24 / 22 / 20 |
| Cast Range | `Melee Attack Range` or 200 |
| Cast Point | 0.25 |
| Channel Time | 3 / 4 / 5 / 6 / 7 / 8 |
| Pull Speed | 100 |

Notes:
- If distance exceeds Cast Range, the channel is interrupted.
- Target is stunned during the channel.

### Possession

Type: `Ally Hero`, `Creep`

Attaches to unit and takes control of it (in case of creeps).

While on the unit, takes percentage of damage done to it.

Shares Attack Type with the host.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | ? |
| Cast Range | ? |
| Cast Point | ? |
| Taken Damage | 50% |
| Attack Damage Percentage | ? |

Notes:
- Single-Target abilities target the Living Armor
- If the host dies (or goes into Hide = Out of Map), drops from the host
  - Does not interrupt channels
- Does not work on Bosses, Hero-Creep or Ancients
- Shares not only Attack Type but also Attack Range
  - Has own Projectile Speed and Projectile Particle
- When on creep
  - Converts it to own unit
    - Has full control over it
  - Kills it after leaving it
  - Move commands are given to the creep instead
  - Attacks are from both the creep and hero
    - Attacks are independent on each other
- If the host goes invisible, so does the Living Armor
  - When Living Armor goes into invisibility, host is not affected
  

### Symbiosis
**__Ultimate__**

Type: `Passive`

Provides own Health Regeneration to the host

| Key | Value |
|-----|:-----:|
| Health Regeneration | 4 / 8 / 12 / 20 |
| Health Regeneration Bonus | 6.25% / 12.5% / 18.75% / 25% |
| Shared Heal | 100% |

Notes:
- Shares both Health Regeneration and Heal with host
- Does not share Mana
- `Health Regeneration Bonus` is not shared
  - Amplifies only own Health Regeneration

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | Takes +25% damage instead of the host | Gains host's Base Attack Time |
| 20 | `Posesion` can affect Ancient Creeps | ? |
| 25 | ? | ? |
| 30 | +100% `Symbiosis` Shared Heal | `Possesion` Always attacks with host, Independent on own attacks |
