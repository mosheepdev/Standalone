# Hero Designs

For Alpha phase of the game, there should be 5 heroes per each attribute (20 total).

## By Attribute

Attributes:
- Strength = tank or defensive carry/support, often melee
- Agility = full agro (high attack speed) carry
- Intelligence = strong casters
- Charisma = defensive casters, fast casters

### Strength
- [Undead Queen](Undead_Queen.md)
- [Riders of Apocalypse](Riders_of_Apocalypse.md)
- [Dwarf](Dwarf.md)

### Agility
- [Sniper](Sniper.md)
- [Ice Shard](Ice_Shard.md)
- Harpy

### Intelligence
- Mori
- Plague Doctor

### Charisma
- [Succubus](Succubus.md)
- [Sun Lord](Sun_Lord.md)
- [Black Jack](Black_Jack.md)

## By Attack Type

### Melee
- [Undead Queen](Undead_Queen.md)
- [Riders of Apocalypse](Riders_of_Apocalypse.md)
- [Dwarf](Dwarf.md)
- [Ice Shard](Ice_Shard.md)
- Harpy
- Plague Doctor
- [Succubus](Succubus.md) (With Ultimate)

### Ranged
- [Sniper](Sniper.md)
- Mori
- [Succubus](Succubus.md) (Without Ultimate)
- [Sun Lord](Sun_Lord.md)
- [Black Jack](Black_Jack.md)

## By Sex

### Male
- [Riders of Apocalypse](Riders_of_Apocalypse.md)
- [Dwarf](Dwarf.md)
- Plague Doctor
- [Succubus](Succubus.md) (Without Ultimate)
- [Sun Lord](Sun_Lord.md)
- [Black Jack](Black_Jack.md)

### Female
- [Undead Queen](Undead_Queen.md)
- [Sniper](Sniper.md)
- [Ice Shard](Ice_Shard.md)
- Harpy
- [Succubus](Succubus.md) (With Ultimate)

### Other
- Mori

## Ideas

- Mori
  - Sex: `Other`
  - Abilities
    - Q
      - ``
        - ?
    - W
      - ``
        - ?
    - E
      - `Presence of Death`
        - Aura, Enemy Unit
        - Percentage damage based on unit's maximum health
        - If unit dies under effect of this aura, the unit looses X points of strength and this hero gains them
    - R
      - `Memento Mori`
        - Creates ghost on death
          - Invisible
            - Can be revealed
          - Untargettable
          - Invincible
          - Cannot attack
          - No items
          - Respawn ability
            - Goes on cooldown
              - Same as hero's respawn time
              - Not affected by `Cooldown Reduction`
            - Must be cast for the hero to respawn
            - Hero respawns on position of the ghost (replaces it)
          - Does not leave corpse on death
            - Hero is `Hidden` and moving with the ghost
        - Increases Attack Damage per dead enemy
- Plague Doctor
  - Sex: `Male`
  - Doctor but also tool of the Plague
  - Appearance
    - White Plague Doctor mask
    - Top Hat
    - Long Coat
    - Cosmetics
      - Crow Set
  - Abilities
    - Q
      - ``
        - ?
    - W
      - `The Doctor`
        - Single Unit Target
        - Heal
        - Soft dispell
        - Lore: `Trust me, I am the Doctor.`
    - E
      - ``
        - ?
    - R
      - `Plague`
        - Single Unit Target
        - Damage over time
        - Applies same Damage Debuff on all hit (damaged) units
        - Base Damage + Damage Increase per unit around
