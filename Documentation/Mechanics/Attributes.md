# Attributes

## Types

### Strength

Color: Red

Per `1` Strength:
- `20` Max Health (`20 * Strength`)
- `0.80%` Health Regeneration Amplification (`1 - (1-0.0080) ^ Strength`)
- `0.10%` Status Resistance (`1 - (1-0.0010) ^ Strength`)

### Agility

Color: Green

Per `1` Agility:
- `1` Attack Speed (`1 * Agility`)
- `0.20` Armor (Physical Resistance) (`0.20 * Agility`)
- `0.10%` Movement Speed (`1 - (1-0.0010) ^ Agility`)

### Intelligence

Color: Blue

Per `1` Intelligence:
- `15` Max Mana (`15 * Intelligence`)
- `2.00%` Mana Regeneration Amplification (`1 - (1-0.0200) ^ Intelligence`)
- `0.10%` Spell Amplification (`1 - (1-0.0010) ^ Intelligence`, both Damage and Healing)

### Will

Color: White

Per `1` Will:
- `1` Cast Range (`1 * Will`)
- `0.20%` Magic Resistance (`1 - (1-0.0020) ^ Will`)
- `0.10%` Cooldown Reduction (`1 - (1-0.0010) ^ Will`)

## Effect on Gameplay

### Primary Attribute
One attribute is always selected as Primary.
This attribute provides base damage equal to its value.

### Defence
- **Strength** (Health + Status Resistance)
- Agility (**Armor**)
- Will (**Magic Resistance**)

### Offence
- Agility (**Attack Speed** + Movement)
- **Intelligence** (Mana + Spell Amplification)
- Will (Cast Range + Cooldown Reduction)
