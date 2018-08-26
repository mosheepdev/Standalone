# Modifier Values

## Damage

### Get Flat Bonus Damage
Flat bonus to damage.
```
int GetFlatBonusDamage()
```

### Get Percentage Bonus Damage
```
float GetPercentageBonusDamage()
```
- 0.0 = Do not modify
- 100.0 = Double Damage

## Attributes

### Get Bonus Strength
Each points give:
- 20 Max Health
- 0.80% Health Regeneration
- 0.10% Status Resistance
```
int GetBonusStrength()
```

### Get Bonus Agility
Each points give:
- 1 Attack Speed
- 0.20 Armor
- 0.10% Movement Speed
```
int GetBonusAgility()
```

### Get Bonus Intelligence
Each points give:
- 15 Max Mana
- 2.00% Mana Regeneration
- 0.10% Spell Amplification (both Damage and Heal)
```
int GetBonusIntelligence()
```

### Get Bonus Charisma
Each points give:
- 1 Cast Range Increase
- 0.20% Magic Resistance
- 0.10% Cooldown Reduction
```
int GetBonusCharisma()
```

## Health

### Get Flat Health Bonus
```
int GetFlatHealthBonus()
```

### Get Percentage Health Bonus
Increase Base Health (Original Health + from Strength) by this percentage. 
```
float GetPercentageHealthBonus()
```

## Health Regeneration

### Get Flat Bonus Health Regeneration
```
float GetFlatBonusHealthRegeneration()
```

### Get Percentage Bonus Health Regeneration
```
float GetPercentageBonusHealthRegeneration()
```

## Mana

### Get Flat Mana Bonus
```
int GetFlatManaBonus()
```

### Get Percentage Mana Bonus
Increase Base Mana (Original Mana + from Intelligence) by this percentage. 
```
float GetPercentageManaBonus()
```

## Mana Regeneration

### Get Flat Bonus Mana Regeneration
```
float GetFlatBonusManaRegeneration()
```

### Get Percentage Bonus Mana Regeneration
```
float GetPercentageBonusManaRegeneration()
```

## Armor (Physical Resistance)

### Get Bonus Armor
As armor value.
Final value (from all modifiers) is floored.
```
float GetBonusArmor()
```

## Magic Resistance

### Get Bonus Magic Resistance
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusMagicResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusMagicResistance()/100))`
```
float GetBonusMagicResistance()
```

## Status Resistance

### Get Bonus Status Resistance
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusStatusResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusStatusResistance()/100))`
```
float GetBonusStatusResistance()
```

## Cooldown Reduction

### Get Bonus Cooldown Reduction
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusCooldownReduction()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusCooldownReduction()/100))`
```
float GetBonusCooldownReduction()
```

## Cast Range

### Get Flat Bonus Cast Range
```
float GetFlatBonusCastRange()
```

### Get Percentage Bonus Cast Range
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusMagicResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusCastRange()/100))`
```
float GetPercentageBonusCastRange()
```

## Movement Speed

### Get Flat Bonus Movement Speed
```
float GetFlatBonusMovementSpeed()
```

### Get Percentage Bonus Movement Speed
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetPercentageBonusMovementSpeed()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusMovementSpeed()/100))`
```
float GetPercentageBonusMovementSpeed()
```

## Attack Speed

### Get Flat Bonus Attack Speed
```
float GetFlatBonusAttackSpeed()
```

### Get Percentage Bonus Attack Speed
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetPercentageBonusAttackSpeed()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusAttackSpeed()/100))`
```
float GetPercentageBonusAttackSpeed()
```

## Attack Range

### Get Bonus Attack Range
```
int GetBonusAttackRange()
```
