# Unit

## Functions

Set functions are Server-side only.
They can still be called from Client but will have no effect.

### Summary

- [Base Info](#Base_Info)
  - [Get Unit ID](#Get_Unit_ID)
- [Position](#Position)
  - [Get Position](#Get_Position)
  - [Teleport](#Teleport) (Set Position)
- [Levels And Experience](#Levels_And_Experience)
  - Max Level ([Get](#Get_Max_Level) +  [Set](#Set_Max_Level))
  - XP Per Level ([Get](#Get_XP_Per_Level) + [Get Total](#Get_XP_Per_Level_Total) + [Set](#Set_XP_Per_Level))
  - Level ([Get](#Get_Level) + [Set](#Set_Level))
  - Current XP ([Get](#Get_Current_XP) + [Get Percentage](#Get_Current_XP_Percentage) + [Clear](#Clear_Current_XP) + [Set](#Set_Current_XP))
  - [Get XP To Next Level](#Get_XP_To_Next_Level)
  - Total XP ([Get](#Get_Total_XP) + [Set](#Set_Total_XP))
  - [Add XP](#Add_XP)
  - [Get Percentage Bonus XP](#Get_Percentage_Bonus_XP) (From Modifiers)
  - [Get XP After Bonus](#Get_XP_After_Bonus) (Calculation Utility)
- [Damage](#Damage)
  - [Original Damage](#Original_Damage)
    - [Min](#Get_Original_Min_Damage)
    - [Max](#Get_Original_Max_Damage)
    - [Real](#Get_Original_Real_Damage) (Average)
    - [Set ](#Set_Original_Damage)
  - [Attribute Damage](#Attribute_Damage)
    - [Get](#Get_Attribute_Damage)
  - [Base Damage](#Base_Damage)
    - [Min](#Get_Base_Min_Damage)
    - [Max](#Get_Base_Max_Damage)
    - [Real](#Get_Base_Real_Damage) (Average)
  - [Bonus Damage](#Bonus_Damage)
    - [Flat](#Get_Flat_Bonus_Damage)
    - [Percentage](#Get_Percentage_Bonus_Damage)
    - [Total](#Get_Total_Bonus_Damage)
  - [Total Damage](#Total_Damage)
    - [Min](#Get_Total_Min_Damage)
    - [Max](#Get_Total_Max_Damage)
    - [Real](#Get_Total_Real_Damage) (Average)

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
You can still store XP from [`GetTotalXp()`](#Get_Total_Xp) and the set it again using [`SetTotalXP(float, boolean)`](#Set_Total_XP) with 2nd parameter set to `false`.

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
Sets Current XP (retrievable from [`GetCurrentXp()`](#Get_Current_Xp)) to 0.

To set it to other value, use [`Set_Current_Xp(float)`](#Set_Current_Xp).

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

Uses value of [`Modifier:GetPercentageBonusXp`](../Modifier/Values.md#Get_Percentage_Bonus_Xp).
```
float GetPercentageBonusXp()
```

#### Get XP After Bonus
Utility function to get XP multiplied by [`GetPercentageBonusXp`](#Get_Percentage_Bonus_Xp).
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
Average value between [`GetOriginalMinDamage`](#Get_Original_Min_Damage) and [`GetOriginalMaxDamage`](#Get_Original_Max_Damage).

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
Set value for [`GetOriginalMinDamage`](#Get_Original_Min_Damage) and [`GetOriginalMaxDamage`](#Get_Original_Max_Damage).

Original Damage is damage defined in Unit's KV file.

**Server only**
```
void SetOriginalDamage(int min, int max)
```

#### Attribute Damage

##### Get Attribute Damage
Get damage from [`GetPrimaryAttribute()`](#Get_Primary_Attribute).

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