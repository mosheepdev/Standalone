# Riders of Apocalypse

## Info

All riders share same attributes but has different main attribute (2 agility and 2 strength).

Riders are:
- War = Agility
- Famine (Hunger) = Strength
- Death = Agility
- Pestilence (Disease) = Strength

## Lore

## Attributes

|  Attribute   | Original | Grow |
|--------------|----------|------|
| Strength     |    21    | 2.4  |
| Agility      |    20    | 2.4  |
| Intelligence |    18    | 1.5  |
| Charisma     |    12    | 1.3  |


|  Attribute   | Moba Value | Angel Arena Value |
|--------------|------------|-------------------|
| Attack Range |    150     |        150        |
| Vision       | 1600 / 800 |     1600 / 800    |
| Damage       |  19 - 25   |      19 - 25      |

## War Abilities

Strength

### To Battle

Type: `Cast Aura, Autocast`

Inspires allies into battle.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 | 30 / 30 / 30 / 30 / 25 / 20 |
| Duration | 10 | 10 |
| Cast Point | 0.25 | 0.25 |
| Cast Radius | 500 | 500 / 500 / 500 / 500 / 550 / 650 |
| Movement Increase | 10% / 15% / 20% / 25% | 10% / 15% / 20% / 25% / 30% / 30% |
| Bonus Health Regeneration | 1 / 2 / 4 / 8 | 1 / 2 / 4 / 8 / 16 / 32 |

### Rider's Legacy (War)

Type: `Passive`

Applies debuff on attacks (when off Cooldown).
After `Required Attacks` amount of attacks land on the target, it gets Stunned `Duration`.
Trigger also removes the attack-counting debuff and sets the ability on Cooldown.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Cooldown | 4 | 4 |
| Required Attacks | 8 | 8 |
| Duration | 0.2 / 0.3 / 0.4 / 0.5 | 0.2 / 0.3 / 0.4 / 0.5 / 0.75 / 1.0 |

## Famine Abilities

Agility

### Lust for Food

Type: `Enemy Unit`

Bites into target unit dealing damage based on its current health over time.
Heals self for percentage of own maximum health.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 | 30 |
| Duration | 4 | 4 / 6 / 8 |
| Cast Point | 0.35 | 0.35 |
| Damage of Target's Current Health | 0.8% / 1.6% / 2.3% / 3% | 0.6% / 1.4% / 2.2% / 3% / 3.4% / 3.6% |
| Self Heal | 5% / 10% / 15% / 20% | 5% / 10% / 15% / 20% / 25% / 35% | 

### Rider's Legacy (Famine)

Type: `Passive`

Applies debuff on attacks (when off Cooldown).
After `Required Attacks` amount of attacks land on the target, it gets Silenced for `Duration`.
Trigger also removes the attack-counting debuff and sets the ability on Cooldown.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Cooldown | 4 | 4 |
| Required Attacks | 8 | 8 |
| Duration | 2 / 3 / 4 / 5 | 1 / 2 / 3 / 4 / 6 / 8 |

## Death Abilities

Strength

### Presence of Death

Type: `Passive`

Whenever a units dies around, gains stack.
Stacks last for `Duration` seconds and provides `Lifesteal` percent of lifesteal on all of his attacks per stack.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Duration | 15 | 10 / 10 / 10 / 10 / 25 / 45 |
| Lifesteal | 2% / 4% / 6% / 8% | 2% / 4% / 6% / 8% / 10% / 10% |

### Rider's Legacy (Death)

Type: `Passive`

Applies Slow an Break on attacks.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Duration | 2 | 2 |
| Slow | 15% / 20% / 25% / 35% | 15% / 20% / 25% / 30% / 40% / 50% |

## Pestilence Abilities

Agility

### Plague Cough

Type: `Direction`

Shouts in cone in front of him.
Hit enemies loose armor based on their distance (closer = more armor lost) and take some damage.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 15 | 15 |
| Cast Point | 0.4 | 0.4 |
| Cast Range | 400 | 400 |
| Start Radius | 100 | 100 |
| End Radius | 400 | 400 |
| Max Armor Reduction | 4 / 6 / 8 / 10 | 4 / 6 / 8 / 10 / 14 / 20 |
| Min Armor Reduction | 1 / 1 / 1 / 2 | 1 / 1 / 2 / 2 / 4 / 8 |
| Armor Reduction Duration | 6 | 6 |
| Damage | 50 / 75 / 100 / 125 | 50 / 75 / 100 / 125 / 200 / 300 | 

### Rider's Legacy (Pestilence)

Type: `Passive`

Has chance to do Critical Damage.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Cooldown | 1 | 1 |
| Critical Chance | 20% | 20% |
| Critical Damage | 150% / 175% / 200% / 225% | 150% / 175% / 200% / 225% / 250% / 300% |
| Average Damage Increase | 10% / 15% / 20% / 25% | 10% / 15% / 20% / 25% / 30% / 40% |

## Shared Abilities

### Call of Riders

Type: `Ally Hero or Enemy Unit`

After a short delay (`Fadeout Time`), teleports to target Rider.

Only works on other Riders (Ally, Global) or Enemy Units in `Cast Range`.

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Manacost | ? | ? |
| Cooldown | 30 / 28 / 26 / 24 | 30 / 28 / 26 / 24 / 21 / 18 |
| Cast Range | 400 / 450 / 500 / 550 | 400 / 450 / 500 / 550 / 650 / 800 |
| Cast Point | ? | ? |
| Fadeout Time | 0.2 | 0.2 |
| Fadein Time | 0.2 | 0.2 |

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

| Key | Moba Value | Angel Arena Value |
|-----|------------|-------------------|
| Total Riders | 2 / 3 / 4 | 2 / 3 / 4 |
| Max Health Lost Per Dead Rider | 25% | 25% |
| Ally Search Radius | 0 | 600 |
| Health Increase Per Ally Rider | 0 | 0 / 0 / 0 / 5% / 7.5% |
| Movement Speed Increase Per Ally Rider | 0 | 0 / 0 / 0 / 7.5% / 10% | 

Note:
- All Riders share items
  - Cooldown of those items is also shared
- Leveling ability of any Rider will level equivalent (same slot) ability of other Riders
- Ally Rider Buff is only for `Angel Arena` Game Mode