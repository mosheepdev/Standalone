# Unit

## Functions

Set functions are Server-side only.
They can still be called from Client but will have no effect.

### Summary

- [Base Info](#base-info)
  - [Get Unit ID](#get-unit-id)
- [Position](#position)
  - [Get Position](#get-position)
  - [Teleport](#teleport) (Set Position)
- [Levels And Experience](#levels-and-experience)
  - Max Level
    - [Get](#get-max-level)
    - [Set](#set-max-level)
  - XP Per Level
    - [Get](#get-xp-per-level)
    - [Get Total](#get-xp-per-level-total)
    - [Set](#set-xp-per-level)
  - Level
    - [Get](#get-level)
    - [Set](#set-level)
  - Current XP
    - [Get](#get-current-xp)
    - [Get Percentage](#get-current-xp-percentage)
    - [Clear](#clear-current-xp)
    - [Set](#set-current-xp))
  - [Get XP To Next Level](#get-xp-to-next-level)
  - Total XP
    - [Get](#get-total-xp)
    - [Set](#set-total-xp)
  - [Add XP](#add-xp)
  - [Get Percentage Bonus XP](#get-percentage-bonus-xp) (From Modifiers)
  - [Get XP After Bonus](#get-xp-after-bonus) (Calculation Utility)
- [Damage](#damage)
  - [Original Damage](#original-damage)
    - [Min](#get-original-min-damage)
    - [Max](#get-original-max-damage)
    - [Real](#get-original-real-damage) (Average)
    - [Set ](#set-original-damage)
  - [Attribute Damage](#attribute-damage)
    - [Get](#get-attribute-damage)
  - [Base Damage](#base-damage)
    - [Min](#get-base-min-damage)
    - [Max](#get-base-max-damage)
    - [Real](#get-base-real-damage) (Average)
  - [Bonus Damage](#bonus-damage)
    - [Flat](#get-flat-bonus-damage)
    - [Percentage](#get-percentage-bonus-damage)
    - [Total](#get-total-bonus-damage)
  - [Total Damage](#total-damage)
    - [Min](#get-total-min-damage)
    - [Max](#get-total-max-damage)
    - [Real](#get-total-real-damage) (Average)
- [Attributes](#attributes)
  - [Main Attribute](#main-attribute)
    - [Get](#get-main-attribute)
    - [Set](#set-main-attribute)
  - [Strength](#strength-attribute)
    - [Original](#original-strength-attribute)
      - [Get](#get-original-strength-attribute)
      - [Set](#set-original-strength-attribute)
    - [Grow](#Strength-attribute-grow)
      - [Get](#get-Strength-attribute-grow)
      - [Set](#set-Strength-attribute-grow)
    - [Base](#get-base-Strength-attribute)
    - [Bonus](#get-bonus-Strength-attribute)
    - [Total](#get-total-Strength-attribute)
  - [Agility](#agility-attribute)
    - [Original](#original-agility-attribute)
      - [Get](#get-original-agility-attribute)
      - [Set](#set-original-agility-attribute)
    - [Grow](#agility-attribute-grow)
      - [Get](#get-agility-attribute-grow)
      - [Set](#set-agility-attribute-grow)
    - [Base](#get-base-agility-attribute)
    - [Bonus](#get-bonus-agility-attribute)
    - [Total](#get-total-agility-attribute)
  - [Intelligence](#intelligence-attribute)
    - [Original](#original-intelligence-attribute)
      - [Get](#get-original-intelligence-attribute)
      - [Set](#set-original-intelligence-attribute)
    - [Grow](#intelligence-attribute-grow)
      - [Get](#get-intelligence-attribute-grow)
      - [Set](#set-intelligence-attribute-grow)
    - [Base](#get-base-intelligence-attribute)
    - [Bonus](#get-bonus-intelligence-attribute)
    - [Total](#get-total-intelligence-attribute)
  - [Charisma](#charisma-attribute)
    - [Original](#original-charisma-attribute)
      - [Get](#get-original-charisma-attribute)
      - [Set](#set-original-charisma-attribute)
    - [Grow](#charisma-attribute-grow)
      - [Get](#get-charisma-attribute-grow)
      - [Set](#set-charisma-attribute-grow)
    - [Base](#get-base-charisma-attribute)
    - [Bonus](#get-bonus-charisma-attribute)
    - [Total](#get-total-charisma-attribute)
- [Health](#health)
  - [Pool](#health-pool)
    - [Original](#original-health-pool)
      - [Get](#get-original-health-pool)
      - [Set](#set-original-health-pool)
    - [Attribute](#attribute-health-pool)
      - [Get](#get-attribute-health-pool)
      - [Per Strength](#health-pool-per-strength)
        - [Get](#get-health-pool-per-strength)
        - [Set](#set-health-pool-per-strength)
    - [Base](#get-base-health-pool)
    - [Bonus](#bonus-health-pool)
      - [Flat](#get-flat-bonus-health-pool)
      - [Percentage](#get-percentage-bonus-health-pool)
      - [Total](#get-bonus-health-pool)
    - [Total](#get-total-health-pool)
  - [Current](#current-health)
    - ...
  - [Regeneration](#health-regeneration)
    - ...

### Base Info

#### Get Unit ID

```
int GetUnitId()
int ["UnitId"].get
```

### Position

#### Get Position

```
int GetPosition()
int GetAbsOrigin()
int ["Position"].get
```

#### Teleport


**Server only**
```
void Teleport(vec2 position)
void Teleport(vec3 position)
void ["Position"].set
```

### Levels And Experience

#### Get Max Level

```
int GetMaxLevel()
int ["MaxLevel"].get
```

#### Set Max Level


**Server only**
```
void SetMaxLevel(int maxLevel)
void ["MaxLevel"].set = maxLevel
```

#### Get XP Per Level


For `level <= 0` returns `0`
```
int GetXpPerLevel()
int GetXpPerLevel(int level)
```

#### Get XP Per Level (Total)

```
int GetXpPerLevelTotal()
int GetXpPerLevelTotal(int level)
```
Implemented as:
```lua
function Unit:GetXpPerLevelTotal(level)
    level = level or self:GetLevel()
    local xp = 0;
    for lvl = 1, level do
        xp = xp + self:GetXpPerLevel(lvl)
    end
end
```

#### Set XP Per Level
Set experience needed to reach level `level` from lower level (`level - 1`).

Only works for `level > 0` (does nothing, no error).
Value `< 0` will be changed to `0`.

Value of `0` means as soon as the player gets to `level-1`, he also gains `level`.
Often used for `level=1` to allow unit to start at `level=1` instead of `level=0`. 

Forces Current XP to recalculate and can add 1 (or more) levels.

Cannot lower level because level is stored as Current Level + XP.
You can still store XP from [`GetTotalXp()`](#get-total-xp) and the set it again using [`SetTotalXP(float, boolean)`](#set-total-xp) with 2nd parameter set to `false`.

**Server only**
```
void SetXpPerLevel(int level, int xp)
```

#### Get Level

```
int GetLevel()
int ["Level"].get
```

#### Set Level


**Server only**
```
void SetLevel(int level)
void ["Level"].set = level
```

#### Get Current XP

```
float GetCurrentXp()
float ["CurrentXp"].get
```

#### Get Current XP Percentage

```
float GetCurrentXpPercentage()
float ["CurrentXpPercentage"].get
```
Implemented as:
```lua
function Unit:GetCurrentXpPercentage()
    local level = self:GetLevel()
    if level == self:GetMaxLevel() then
        return 100
    end
    return (self:GetCurrentXp() / self:GetXpPerLevel(level)) / 100.0
end
```

#### Clear Current XP
Sets Current XP (retrievable from [`GetCurrentXp()`](#get-current-xp)) to 0.

To set it to other value, use [`Set_Current_Xp(float)`](#set-current-xp).

**Server only**
```
void ClearCurrentXp()
```

#### Set Current XP
This is only utility function.

Because of implementation of this, it is **Server only**. 
```
void SetCurrentXp(float xp)
void ["CurrentXp"].set = xp
```
Implemented as:
```lua
function Unit:SetCurrentXp(xp)
    self:ClearCurrentXp()
    self:AddXp(xp, false)
end
```

#### Get XP To Next Level

```
float GetXpToNextLevel()
```
Implemented as:
```lua
function Unit:GetXpToNextLevel()
    local level = self:GetLevel()
    local maxLevel = self:getMaxLevel()
    
    if level >= maxLevel then
        return 0
    end
     
    return self:GetXpPerLevel(level + 1) - self:GetCurrentXp() 
end
```

#### Get Total XP

```
float GetTotalXp()
float ["TotalXp"].get
```
Implemented as:
```lua
function Unit:GetTotalXp()
    return self:GetCurrentXp() + self:GetXpPerLevelTotal(self:GetLevel())
end
```

#### Set Total XP
Set total Experience points.

Always recalculates level.

If second attribute (`affectedByModifiers`) is present and value is `true` (or can be converted to it), the `xp` value is multiplied by Percentage Bonus XP.

**Server only**
```
void SetTotalXp(float xp) 
void ["TotalXp"].set = xp
void SetTotalXp(float xp, bool affectedByModifiers = false)
```

#### Add XP
Add (give) XP to the unit.

Second parameter (defaults to `true`) determines whenever the `xp` should be affected by percentage XP increase from modifiers.

Return value are remaining XPs without the increase from modifiers.

**Server only**
```
float AddXp(float xp)
float AddXp(float xp, bool affectedByModifiers = true)
```
Implemented as:
```lua
-- Note: self.CurrentXp is hidden variable behind self:GetCurrentXp()
function Unit:AddXp(xp, affectedByModifiers)
    if affectedByModifiers == nil then -- Not Defined
        affectedByModifiers = true
    end
    
    local xpNext = self:GetXpToNextLevel()
    local xpBonusMult = 1.0
    if affectedByModifiers then
        -- Decrease needed XP instead of amplifying XP (to keep it for return value)
        xpBonusMult = self:GetPercentageBonusXp() / 100.0
        -- Cannot gain XP
        if xpBonusMult <= 0 then
            return xp
        end
        xpNext = xpNext / xpBonusMult
    end
    
    local level = self:GetLevel()
    if level == self:GetMaxLevel() then
        return xp
    end
        
    if xpNext <= xp then -- Enough for next level or xpNext == 0 (instant lvl-up)
        self.CurrentXp = 0
        self:SetLevel(level + 1)
        return self:AddXp(xp - xpNext, affectedByModifiers) -- Call self (recursion using tail call) with remaining XP after the level-up
    else -- Not enough for next level
        self.CurrentXp = self.CurrentXp + xp * xpBonusMult
        return 0 -- No remaining XP, all used
    end
    
end
```

#### Get Percentage Bonus XP
Retrieve and calculate total percentage bonus from all active modifiers on this unit.

Uses value of [`Modifier:GetPercentageBonusXp`](../Modifier/Values.md#get-percentage-bonus-xp).
```
float GetPercentageBonusXp()event
```

#### Get XP After Bonus
Utility function to get XP multiplied by [`GetPercentageBonusXp`](#get-percentage-bonus-xp).
```
float GetXpAfterBonus(float xp)
```
Implemented as:
```lua
function Unit:GetXpAfterBonus(xp)
    return xp * (self:GetPercentageBonusXp() / 100.0)
end
```
### Damage

#### Original Damage

##### Get Original Min Damage
Minimum Damage defined in Unit's KV file.
```
int GetOriginalMinDamage()
```

##### Get Original Max Damage
Maximum Damage defined in Unit's KV file.
```
int GetOriginalMaxDamage()
```

##### Get Original Real Damage
Average value between [`GetOriginalMinDamage`](#get-original-min-damage) and [`GetOriginalMaxDamage`](#get-original-max-damage).

Original Damage is damage defined in Unit's KV file.

Usually used to display unit's damage on GUI.
```
int GetOriginalRealDamage()
```
Implemented as:
```lua
function Unit:GetOriginalRealDamage()
    local min = self:GetOriginalMinDamage();
    return min + (self:GetOriginalMaxDamage() - min) / 2;
end 
```

##### Set Original Damage
Set value for [`GetOriginalMinDamage`](#get-original-min-damage) and [`GetOriginalMaxDamage`](#get-original-max-damage).

Original Damage is damage defined in Unit's KV file.

**Server only**
```
void SetOriginalDamage(int min, int max)
```

#### Attribute Damage

##### Get Attribute Damage
Get damage from [`GetMainAttribute()`](#get-main-attribute).

This plus Original Damage makes Base Damage 

#### Base Damage

##### Get Base Min Damage

```
int GetBaseMinDamage()
```
Implemented as:
```lua
function Unit:GetBaseMinDamage()
    return self:GetOriginalMinDamage() + self:GetAttributeDamage()
end
```

##### Get Base Max Damage

```
int GetBaseMaxDamage()
```
Implemented as:
```lua
function Unit:GetBaseMaxDamage()
    return self:GetOriginalMaxDamage() + self:GetAttributeDamage()
end
```

##### Get Base Real Damage

```
int GetBaseRealDamage()
```
Implemented as:
```lua
function Unit:GetBaseRealDamage()
    local min = self:GetBaseMinDamage();
    return min + (self:GetBaseMaxDamage() - min) / 2;
end
```

#### Bonus Damage

##### Get Flat Bonus Damage

```
int GetFlatBonusDamage()
```

##### Get Percentage Bonus Damage

```
float GetPercentageBonusDamage()
```

##### Get Total Bonus Damage

```
int GetTotalBonusDamage()
```
Implemented as:
```lua
function Unit:GetTotalBonusDamage()
    return (self:GetFlatBonusDamage() + self:GetBaseRealDamage() * (self:GetPercentageBonusDamage() / 100.0))
end
```

#### Total Damage

##### Get Total Min Damage

```
int GetTotalMinDamage()
```
Implemented as:
```lua
function Unit:GetTotalMinDamage()
    return self:GetTotallMinDamage() + self:GetFlatBonusDamage()
end
```

##### Get Total Max Damage

```
int GetTotalMaxDamage()
```
Implemented as:
```lua
function Unit:GetTotalMaxDamage()
    return self:GetTotallMaxDamage() + self:GetFlatBonusDamage()
end
```

##### Get Total Real Damage

```
int GetTotalRealDamage()
```
Implemented as:
```lua
function Unit:GetTotalRealDamage()
    local min = self:GetTotalMinDamage();
    return min + (self:GetTotalMaxDamage() - min) / 2;
end
```