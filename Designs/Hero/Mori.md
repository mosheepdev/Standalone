# Mori

## Info
Sex: `Other`



## Lore

## Attributes

**Intelligence**

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    14    | 1.2  |
| Agility      |    24    | 2.6  |
| Intelligence |    23    | 1.9  |
| Will         |    17    | 1.1  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     170     |
| Attack Type      |    Melee    |
| Projectile Speed |      -      |
| Vision           | 1,600 / 800 |
| Damage           |   25 - 26   |
| Base Attack Time |     1.6     |
| Movement Speed   |     290     |
| Original Armor   |      0      |

## Abilities

### Moment Before Death

Type: `Enemy Unit`

Deals damage, disarms and slows target.

Slow is increasing over time.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 10 |
| Cast Range | 400 |
| Cast Point | 0.15 |
| Damage | 40 / 80 / 120 / 160 / 200 / 250 |
| Duration | 6 |
| Start Slow | 0% |
| End Slow | 10% / 15% / 20% / 25% / 30% / 40% |

### Other Side

Type: `Toggle`

When any unit around takes damage, they also take additional magic damage.

| Key | Value |
|-----|:-----:|
| Manacost | 5 / 10 / 15 / 20 / 25 / 30 |
| Range | 200 |
| Damage | 10 / 20 / 30 / 45 / 65 / 90 |

### Presence of Death

Type: `Aura, Enemy Unit`

Units around take damage based on percentage of their maximum health.

When unit dies under this effect, looses 1 `Strength` + 1 `Intelligence` and this hero gains it.

| Key | Value |
|-----|:-----:|
| Damage of Max Health | 0.5% / 1.0% / 1.5% / 2.0% / 2.8% / 3.8% |
| Radius | ? |
| Strength Loss | 1 |
| Intelligence Loss | 1 |

### Memento Mori
**__Ultimate__**

Type: `Passive`

Increases Attack Damage for every enemy unit dying around.

Each stack has own duration.

Percentage of the damage is shared with allies.

| Key | Value |
|-----|:-----:|
| Hero Bonus | 10 / 20 / 30 / 40 |
| Boss Bonus | 20 / 40 / 70 / 100 |
| Creep Bonus | 1 / 1 / 2 / 3 |
| Duration | 30 |
| Shared Percentage | 50% |

Creates ghost on death.
Does not leave corpse.

Ghost is Invisible, cannot attack and when takes damage, gets rooted.
Has no abilities or items except `Respawn` and `Call of home`.

Ghost keeps collecting stacks for the ability.

Damage is multiplied by `Spell Amplification`

### Respawn

`Respawn` goes on cooldown for same time as normal respawn would be.
Then can be activated to respawn the hero (in place of the ghost).

Invulnerable while casting.

| Key | Value |
|-----|:-----:|
| Cooldown | `Respawn Time` |
| Cast Point | 0.5 |

Note:
- Not affected by `Cooldown Reduction`

### Call of Home

`Call of Home` teleports ghost go base (normal respawn location).
Cannot be cast while rooted.

| Key | Value |
|-----|:-----:|
| Cooldown | 4 |
| Cast Point | 0.5 |

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | +300 `Other Side` Renge | ? |
| 15 | ? | ? |
| 20 | ? | ? |
| 25 | +25% `Memento Mori` Shared Damage | +30s `Memento Mori` Damage Duration |
| 30 | ? | ? |
