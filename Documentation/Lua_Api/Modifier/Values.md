# Modifier Values

## Experience

### Get Percentage Bonus Xp
```
float GetPercentageBonusXp()
```
Default: `nil` or `0`

## Damage

### Get Flat Bonus Damage
Flat bonus to damage.
```
int GetFlatBonusDamage()
```
Default: `nil` or `0`

### Get Percentage Bonus Damage
```
float GetPercentageBonusDamage()
```
Default: `nil` or `0`
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
Default: `nil` or `0`

### Get Bonus Agility
Each points give:
- 1 Attack Speed
- 0.20 Armor
- 0.10% Movement Speed
```
int GetBonusAgility()
```
Default: `nil` or `0`

### Get Bonus Intelligence
Each points give:
- 15 Max Mana
- 2.00% Mana Regeneration
- 0.10% Spell Amplification (both Damage and Heal)
```
int GetBonusIntelligence()
```
Default: `nil` or `0`

### Get Bonus Will
Each points give:
- 1 Cast Range Increase
- 0.20% Magic Resistance
- 0.10% Cooldown Reduction
```
int GetBonusWill()
```
Default: `nil` or `0`

## Health

### Get Flat Health Bonus
```
int GetFlatBonusHealth()
```
Default: `nil` or `0`

### Get Percentage Health Bonus
Increase Base Health (Original Health + from Strength) by this percentage. 
```
float GetPercentageBonusHealth()
```
Default: `nil` or `0`

## Health Regeneration

### Get Flat Bonus Health Regeneration
```
float GetFlatBonusHealthRegeneration()
```
Default: `nil` or `0`

### Get Percentage Bonus Health Regeneration
```
float GetBonusPercentageHealthRegeneration()
```
Default: `nil` or `0`

## Mana

### Get Flat Mana Bonus
```
int GetFlatBonusMana()
```
Default: `nil` or `0`

### Get Percentage Mana Bonus
Increase Base Mana (Original Mana + from Intelligence) by this percentage. 
```
float GetPercentageBonusMana()
```
Default: `nil` or `0`

## Mana Regeneration

### Get Flat Bonus Mana Regeneration
```
float GetFlatBonusManaRegeneration()
```
Default: `nil` or `0`

### Get Percentage Bonus Mana Regeneration
```
float GetBonusPercentageManaRegeneration()
```
Default: `nil` or `0`

## Armor (Physical Resistance)

### Get Bonus Armor
As armor value.
Final value (from all modifiers) is floored.
```
float GetBonusArmor()
```
Default: `nil` or `0`

## Magic Resistance

### Get Bonus Magic Resistance
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusMagicResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusMagicResistance()/100))`
```
float GetBonusMagicResistance()
```
Default: `nil` or `0`

## Status Resistance

### Get Bonus Status Resistance
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusStatusResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusStatusResistance()/100))`
```
float GetBonusStatusResistance()
```
Default: `nil` or `0`

## Cooldown Reduction

### Get Bonus Cooldown Reduction
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusCooldownReduction()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetBonusCooldownReduction()/100))`
```
float GetBonusCooldownReduction()
```
Default: `nil` or `0`

## Manacost

//////////////////////////////////

## Goldcost

//////////////////////////////////

## Spell Amplification

//////////////////////////////////

## Cast Range

### Get Flat Bonus Cast Range
```
float GetFlatBonusCastRange()
```
Default: `0`

### Get Percentage Bonus Cast Range
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetBonusMagicResistance()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusCastRange()/100))`
```
float GetPercentageBonusCastRange()
```
Default: `nil` or `0`

## Cast Radius

//////////////////////////////////

## Movement Speed

### Get Flat Bonus Movement Speed
```
float GetFlatBonusMovementSpeed()
```
Default: `nil` or `0`

### Get Percentage Bonus Movement Speed
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetPercentageBonusMovementSpeed()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusMovementSpeed()/100))`
```
float GetPercentageBonusMovementSpeed()
```
Default: `nil` or `0`

## Attack Speed

### Get Flat Bonus Attack Speed
```
float GetFlatBonusAttackSpeed()
```
Default: `nil` or `0`

### Get Percentage Bonus Attack Speed
As percentage from -100.0 to 100.0.

`Current = 10000 - ((100 - Current) * ( 100 - GetPercentageBonusAttackSpeed()) / 100000)`

`Current = 1 - ((1 - Current/100) * ( 1 - GetPercentageBonusAttackSpeed()/100))`
```
float GetPercentageBonusAttackSpeed()
```
Default: `nil` or `0`

## Attack Time

//////////////////////////////////

## Attack Range

### Get Bonus Attack Range
```
int GetBonusAttackRange()
```
Default: `nil` or `0`

## Attack Projectile

### Get Projectile Particle
```
string GetProjectileParticle()
```
Default: `nil`

## Attack Type

//////////////////////////////////

## Gold

### Get Percentage Bonus Gold
```
float GetPercentageBonusGold()
```
Default: `nil` or `0`
