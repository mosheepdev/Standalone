# Succubus

## Info
Sexy female demon with human appearance. Can change own sex to male when needed.

Wields dagger in main hand and whip in offhand (in male form whip in main hand and empty offhand). 

## Lore

## Attributes

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    14    | 1.2  |
| Agility      |    11    | 2.4  |
| Intelligence |    22    | 2.0  |
| Charisma     |    27    | 2.8  |


|  Attribute   | Moba Value | Angel Arena Value |
|--------------|------------|-------------------|
| Attack Range |    600     |        600        |
| Vision       | 1600 / 800 |     1600 / 800    |
| Damage       |  23 - 29   |      23 - 29      |

## Abilities

### Whip

#### Female Form

Type: `Direction (Point or Unit)`

Cracks her ship in direction hitting all units on its path.
Hit enemies take percentage of caster's damage (`Critical Damage` lowered by `Critical Damage Decrease Per Unit` up to `Min Critical Damage`) and `Stun` for `Stun Duration` seconds.

Does not trigger `Cleave` or `Critics` from other sources but triggers other OnAttack modifiers.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | ? | ? |
| Cast Point | 0.25 | 0.25 |
| Cast Radius | 600 | 600 |
| Critical Damage | 200% | 170% / 180% / 190% / 200% / 250% / 300% |
| Min Critical Damage | 100% | 100% |
| Critical Damage Decrease Per Unit | 20% | 15% |
| Units Until Minimal Critical Damage | 5 | 5 / 6 / 6 / 7 / 10 / 14 |
| Stun Duration | 0.1 / 0.2 / 0.4 / 0.5 | 0.1 / 0.2 / 0.4 / 0.5 / 0.5 / 0.5 |
| Projectile Speed | 2400 | 2400 |
| Projectile Travel Time | 0.25 | 0.25 |
| Projectile Radius | 100 | 100 |
| Projectile Distance | `Cast Radius` | `Cast Radius` |

Note:
- Can only trigger once per each unit

#### Male Form

Type: `Passive`

Grants critical chance.

Causes critical attacks to explode on landing (`Splash Attack`).

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Critical Chance | 15% / 25% / 40% / 50% | 10% / 20% / 30% / 40% / 50% / 50% |
| Critical Damage | 150% | 150% / 150% / 150% / 150% / 175% / 200% |
| Average Damage Increase | 7.5% / 12.5% / 20% / 25% | 5% / 10% / 15% / 20% / 37.5% / 50% |
| Explosion Damage | 50% | 10% / 20% / 30% / 40% / 50% / 50% |
| Explosion Radius | 100 | 100 |

Note:
- Also works from other sources of critics

### Enchant

#### Female Form

Type: `Enemy Hero`

Forces target hero to walk towards caster.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 60 | 60 / 60 / 60 / 60 / 40 / 15 |
| Cast Point | 0.4 | 0.4 |
| Duration | 2 / 3 / 4 / 5 | 2 / 3 / 4 / 5 / 5 / 5 |

#### Male Form

Type: `Enemy or Neutral Creep`

Gain control of a creep for limited duration.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 60 | 60 |
| Cast Point | 0.4 | 0.4 |
| Duration | 30 / 60 / 90 / 120 | 30 / 60 / 90 / 120 / 120 / 120 |

Notes:
- Cannot target Buildings, Bosses, Creep-Heroes or Heroes
- Maximum of `2` units __without__ `Cooldown Reduction`

### Demon Wings

#### Female Form

Type: `Point`

Jumps into air for `Air Time` seconds and then lands at target point.
Destroys trees and stuns enemies on landing.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 / 25 / 20 / 15 | 30 / 25 / 20 / 15 / 15 / 15 |
| Cast Point | 0 | 0 |
| Cast Range | 200 / 300 / 400 / 500 | 200 / 300 / 400 / 500 / 500 / 500 |
| Air Time | 0.25 | 0.25 |
| Tree Destroy Radius | 150 | 150 |
| Stun Radius | 200 | 200 / 200 / 200 / 200 / 275 / 350 |
| Stun Duration | 0.25 | 0.20 / 0.25 / 0.30 / 0.35 / 0.50 / 0.75 |

Note:
- Creates black wings on her back
  - While in air
  - Cosmetics!
- Can be recast while in air to change target position
  - Goes on cooldown after landing
  - Getting stunned changes target position to start location (below the caster)
- Double-tap to be cast below self

#### Male Form

Type: `Point`

Dashes forward.
Invulnerable during the dash.

Stuns all units it dashes through.
Hit (stunned) units take `Hit Damage` percentage of attack damage.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 / 25 / 20 / 15 | 30 / 25 / 20 / 15 / 15 / 15 |
| Cast Point | 0 | 0 |
| Cast Range | 200 / 300 / 400 / 500 | 200 / 300 / 400 / 500 / 500 / 500 |
| Tree Destroy Radius | `Model Size` | `Model Size` |
| Dash Speed | 800 / 1200 / 1600 / 2000 | 800 / 1200 / 1600 / 2000 / 2000 / 2000 |
| Max Dash Time | 0.25 | 0.25 |
| Stun Radius | 200 | 200 |
| Stun Duration | 0.25 | 0.25 |
| Hit Damage | 100% | 100% |

Note:
- Creates black wings on his back
  - At start of push forward
  - Cosmetics!
- Double-tap to be cast in current facing direction for maximum range

### Succubus / Incubus
**__Ultimate__**

Type: `Toggle`

Transforms into Incubus (male form).

Exchanges dagger (throw projectile) to whip (in offhand before).

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 4 | 4 |
| Attack Range Increase | -450 | -450 |
| Attack Type | Melee | Melee |

Notes:
- Changes:
  - Model
  - Attack Type
  - Attack Range