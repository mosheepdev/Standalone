# Riders of Apocalypse

## Info
Sex: `Male`

All riders share same attributes but has different main attribute (2 agility and 2 strength).

Riders are:
- War = Agility
- Famine (Hunger) = Strength
- Death = Agility
- Pestilence (Disease) = Strength

## Lore

## Attributes

**Strength** (+Agility)

|  Attribute   | Original | Grow |
|--------------|:--------:|:----:|
| Strength     |    21    | 2.4  |
| Agility      |    20    | 2.4  |
| Intelligence |    18    | 1.5  |
| Will         |    12    | 1.3  |


|    Attribute     |    Value    |
|------------------|:-----------:|
| Attack Range     |     150     |
| Attack Type      |    Melee    |
| Projectile Speed |      -      |
| Vision           | 1,600 / 800 |
| Damage           |   19 - 25   |
| Base Attack Time |     1.7     |
| Movement Speed   |     280     |
| Original Armor   |     -1      |

## War Abilities

Strength

### To Battle

Type: `Cast Aura, Autocast`

Inspires allies into battle.

| Key | Value |
|-----|:-----:|
| Manacost | ? | ? |
| Cooldown | 45 / 40 / 35 / 30 / 25 / 20 |
| Duration | 10 |
| Cast Point | 0.25 |
| Cast Radius | 500 |
| Movement Increase | 10% / 15% / 20% / 25% / 30% / 30% |
| Bonus Health Regeneration | 1 / 2 / 4 / 8 / 16 / 32 |

### Rider's Legacy (War)

Type: `Passive`

Applies debuff on attacks (when off Cooldown).
After `Required Attacks` amount of attacks land on the target, it gets Stunned `Duration`.
Trigger also removes the attack-counting debuff and sets the ability on Cooldown.

| Key | Value |
|-----|:-----:|
| Cooldown | 4 |
| Required Attacks | 8 |
| Duration | 0.2 / 0.3 / 0.4 / 0.5 / 0.75 / 1.0 |

## Famine Abilities

Agility

### Lust for Food

Type: `Enemy Unit`

Bites into target unit dealing damage based on its current health over time.
Heals self for percentage of own maximum health.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 30 |
| Duration | 3 / 4 / 5 / 6 / 7 / 8 |
| Cast Point | 0.35 |
| Damage of Target's Current Health | 0.6% / 1.4% / 2.2% / 3% / 3.4% / 3.6% |
| Self Heal | 5% / 10% / 15% / 20% / 25% / 35% | 

### Rider's Legacy (Famine)

Type: `Passive`

Applies debuff on attacks (when off Cooldown).
After `Required Attacks` amount of attacks land on the target, it gets Silenced for `Duration`.
Trigger also removes the attack-counting debuff and sets the ability on Cooldown.

| Key | Value |
|-----|:-----:|
| Cooldown | 4 |
| Required Attacks | 8 |
| Duration | 1 / 2 / 3 / 4 / 6 / 8 |

## Death Abilities

Strength

### Presence of Death

Type: `Passive`

Whenever a hero, hero-creep or ancient dies around, gains stack.
Stacks last for `Duration` seconds and provides `Lifesteal` percent of lifesteal on all of his attacks per stack.

| Key | Value |
|-----|:-----:|
| Duration | 10 / 10 / 10 / 10 / 25 / 45 |
| Lifesteal | 2% / 4% / 6% / 8% / 10% / 10% |

### Rider's Legacy (Death)

Type: `Passive`

Applies Slow an Break on attacks.

| Key | Value |
|-----|:-----:|
| Duration | 2 |
| Slow | 15% / 20% / 25% / 30% / 40% / 50% |

## Pestilence Abilities

Agility

### Plague Cough

Type: `Direction`

Shouts in cone in front of him.
Hit enemies loose armor based on their distance (closer = more armor lost) and take some damage.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 15 |
| Cast Point | 0.4 |
| Cast Range | 400 |
| Start Radius | 100 |
| End Radius | 400 |
| Max Armor Reduction | 4 / 6 / 8 / 10 / 14 / 20 |
| Min Armor Reduction| 1 / 1 / 2 / 2 / 4 / 8 |
| Armor Reduction Duration | 6 |
| Damage | 50 / 75 / 100 / 125 / 200 / 300 | 

### Rider's Legacy (Pestilence)

Type: `Passive`

Has chance to do Critical Damage.

| Key | Value |
|-----|:-----:|
| Cooldown | 1 |
| Critical Chance | 20% |
| Critical Damage | 150% / 175% / 200% / 225% / 250% / 300% |
| Average Damage Increase | 10% / 15% / 20% / 25% / 30% / 40% |

## Shared Abilities

### Call of Riders

Type: `Ally Hero or Enemy Unit`

After a short delay (`Fadeout Time`), teleports to target Rider.

Only works on other Riders (Ally, Global) or Enemy Units in `Cast Range`.

| Key | Value |
|-----|:-----:|
| Manacost | ? |
| Cooldown | 30 / 28 / 26 / 24 / 21 / 18 |
| Cast Range | 400 / 450 / 500 / 550 / 650 / 800 |
| Cast Point | ? |
| Fadeout Time | 0.2 |
| Fadein Time | 0.2 |

Note:
- Animation is running into invisibility (transparency, `Fadeout Time`) and coming from it (`Fadein Time`)
- Stun does not interrupt the teleportation after `Fadeout Time`
  - Can still be stopped before `Fadeout Time`
- Always comes from direction of original position
- If target Rider is currently attacking a unit, teleported Rider will teleport to it instead and start attacking it 

### Four Riders

**__Ultimate__**

Type: `Passive`

When one of Riders die, maximum health of rest is decreased by `Max Health Lost Per Dead Rider` (1 dead = 75%, 2 dead = 50%, 3 dead = 25%).

Riders cannot heal over this limit.
On death of the rider, others do not take damage but their current health is decreased (cannot be changed by modifiers).

Riders appear in order:
- War (Original, no level required)
- Famine
- Death
- Pestilence

| Key | Value |
|-----|:-----:|
| Total Riders | 2 / 3 / 4 / 4 |
| Max Health Lost Per Dead Rider | 25% |
| Ally Search Radius | 600 |
| Health Regeneration Per Ally Rider | 1 / 2 / 4 / 8 |
| Armor Per Ally Rider | 1 / 2 / 4 / 8 |
| Movement Speed Increase Per Ally Rider | 0% / 0% / 0% / 10% | 

Note:
- All Riders share items
  - Cooldown of those items is also shared
- Leveling ability of any Rider will level equivalent (same slot) ability of other Riders
- Does not provide additional rider on last level

## Talents

| Level | Left | Right |
|:-----:|:----:|:-----:|
| 10 | ? | ? |
| 15 | ? | ? |
| 20 | ? | ? |
| 25 | ? | ? |
| 30 | ? | ? |

