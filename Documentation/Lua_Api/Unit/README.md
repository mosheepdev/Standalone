# Unit

## Functions

Set functions are Server-side only.
They can still be called from Client but will have no effect.

### Summary

- [Base Info](#base-info)
- [Position](#position)
- [Levels And Experience](#levels-and-experience)
- [Attributes](#attributes)
  - [Strength](#strength)
  - [Agility](#agility)
  - [Intelligence](#intelligence)
  - [Charisma](#charisma)
- [Health](#health)
  - [Pool](#health-pool)
  - [Regeneration](#health-regeneration)
  - [Manipulation](#health-manipulation)
- [Mana](#mana)
  - [Pool](#mana-pool)
  - [Regeneration](#mana-regeneration)
  - [Manipulation](#mana-manipulation)
- [Resistance](#resistance)
  - [All](#all-resistance)
  - [Physical](#armor) (Armor)
  - [Magical](#magical-resistance)
- [Reductions](#reductions)
- [Attack](#attack)
  - [Speed](#attack-speed)
  - [Time](#attack-time)
  - [Range](#attack-range)
  - [Type](#attack-type)
    
### Base Info

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetUnitId()
int ["UnitId"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Unique ID for this entity.
        </td>
        <td></td>
    </tr>
</table>

### Position

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>Vector3 GetPosition()
Vector3 GetAbsOrigin()
Vector3 ["Position"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Position of this entity.<br>This is where [0,0,0] of this entity is.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void Teleport(vec2 position)
void Teleport(vec3 position)
["Position"].set = vec3 position</pre>
        </td>
        <td>Server</td>
        <td>Teleport this entity to target point.</td>
        <td></td>
    </tr>
</table>

### Levels And Experience

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetMaxLevel()
int ["MaxLevel"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetMaxLevel(int maxLevel)
["MaxLevel"].set = int maxLevel</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetXpPerLevel()
int GetXpPerLevel(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td><pre>int GetXpPerLevelTotal()
int GetXpPerLevelTotal(int level)</pre></td>
        <td>Both</td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetXpPerLevelTotal(level)
    level = level or self:GetLevel()
    local xp = 0;
    for lvl = 1, level do
        xp = xp + self:GetXpPerLevel(lvl)
    end
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void SetXpPerLevel(int level, int xp)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Set experience needed to reach level `level` from lower level (`level - 1`).<br>
            <br>
            `level <= 0` returns `0`.<br>
            <br>
            Value of `0` means as soon as the player gets to `level-1`, he also gains `level`.<br>
            Often used for `level=1` to allow unit to start at `level=1` instead of `level=0`.<br>
            <br>
            Forces Current XP to recalculate and can add 1 (or more) levels.<br>
            Cannot lower level because level is stored as Current Level + XP.<br>
            <br>
            To recalculate full XP, use `GetTotalXp()`, call this and then `SetTotalXP(float, boolean)` with 2nd parameter set to `false`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetLevel()
 int ["Level"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetLevel(int level)
["Level"].set = int level</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentXp()
float ["CurrentXp"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentXpPercentage()
float ["CurrentXpPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetCurrentXpPercentage()
    local level = self:GetLevel()
    if level == self:GetMaxLevel() then
        return 100
    end
    return (self:GetCurrentXp() / self:GetXpPerLevel(level)) / 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void ClearCurrentXp()</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Sets Current XP (retrievable from `GetCurrentXp()`) to 0.<br>
            <br>
            To set it to other value, use `Set_Current_Xp(float)`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCurrentXp(float xp)
void ["CurrentXp"].set = xp</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:SetCurrentXp(xp)
    self:ClearCurrentXp()
    self:AddXp(xp, false)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetXpToNextLevel()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetXpToNextLevel()
    local level = self:GetLevel()
    local maxLevel = self:getMaxLevel()
    
    if level >= maxLevel then
        return 0
    end
     
    return self:GetXpPerLevel(level + 1) - self:GetCurrentXp() 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalXp()
float ["TotalXp"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalXp()
    return self:GetCurrentXp() + self:GetXpPerLevelTotal(self:GetLevel())
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void SetTotalXp(float xp) 
void ["TotalXp"].set = xp
void SetTotalXp(float xp, bool affectedByModifiers = false)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Set total Experience points.<br>
            <br>
            Always recalculates level.<br>
            <br>
            If second attribute (`affectedByModifiers`) is present and value is `true` (or can be converted to it), the `xp` value is multiplied by Percentage Bonus XP.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float AddXp(float xp)
float AddXp(float xp, bool affectedByModifiers = true)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Add (give) XP to the unit.<br>
            <br>
            Second parameter (defaults to `true`) determines whenever the `xp` should be affected by percentage XP increase from modifiers.<br>
            <br>
            Return value are remaining XPs without the increase from modifiers.
        </td>
        <td>
            <pre lang="lua">-- Note: self.CurrentXp is hidden variable behind self:GetCurrentXp()
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
        -- Call self (recursion using tail call) with remaining XP after the level-up
        return self:AddXp(xp - xpNext, affectedByModifiers)
    else -- Not enough for next level
        self.CurrentXp = self.CurrentXp + xp * xpBonusMult
        return 0 -- No remaining XP, all used
    end
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusXp()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Retrieve and calculate total percentage bonus from all active modifiers on this unit.<br>
            <br>
            Uses value of [`Modifier:GetPercentageBonusXp`](../Modifier/README.md).
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetXpAfterBonus(float xp)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Utility function to get XP multiplied by `GetPercentageBonusXp`.
        </td>
        <td>
            <pre lang="lua">function Unit:GetXpAfterBonus(xp)
    return xp * (self:GetPercentageBonusXp() / 100.0)
end</pre>
        </td>
    </tr>
</table>

### Damage

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalMinDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Minimum Damage defined in Unit's KV file.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalMaxDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Maximum Damage defined in Unit's KV file.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalRealDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Average value between `GetOriginalMinDamage()` and `GetOriginalMaxDamage()`.<br>
            <br>
            Original Damage is damage defined in Unit's KV file.<br>
            <br>
            Usually used to display unit's damage on GUI.
        </td>
        <td>
            <pre lang="lua">function Unit:GetOriginalRealDamage()
    local min = self:GetOriginalMinDamage();
    return min + (self:GetOriginalMaxDamage() - min) / 2;
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalDamage(int min, int max)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Set value for `GetOriginalMinDamage()` and `GetOriginalMaxDamage()`.<br>
            <br>
            Original Damage is damage defined in Unit's KV file.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetAttributeDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get damage from `GetMainAttribute()`.<br>
            <br>
            This plus Original Damage makes Base Damage.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseMinDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMinDamage()
    return self:GetOriginalMinDamage() + self:GetAttributeDamage()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseMaxDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMaxDamage()
    return self:GetOriginalMaxDamage() + self:GetAttributeDamage()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseRealDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseRealDamage()
    local min = self:GetBaseMinDamage();
    return min + (self:GetBaseMaxDamage() - min) / 2;
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetFlatBonusDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalBonusDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalBonusDamage()
    return (self:GetFlatBonusDamage() + self:GetBaseRealDamage() * (self:GetPercentageBonusDamage() / 100.0))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalMinDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMinDamage()
    return self:GetTotallMinDamage() + self:GetFlatBonusDamage()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalMaxDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMaxDamage()
    return self:GetTotallMaxDamage() + self:GetFlatBonusDamage()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalRealDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalRealDamage()
    local min = self:GetTotalMinDamage();
    return min + (self:GetTotalMaxDamage() - min) / 2;
end</pre>
        </td>
    </tr>
</table>

### Attributes

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>Attribute GetMainAttribute()
Attribute ["MainAttribute"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Main Attribute is attribute which provides damage equal to its value.<br>
            <br>
            Every unit can only have 1 main attribute.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetMainAttribute(Attribute mainAttribute)
["MainAttribute"].set = Attribute mainAttribute</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Strength

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalStrengthAttribute()
int ["OriginalStrengthAttribute"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalStrengthAttribute(int attribute)
["OriginalStrengthAttribute"].set = int attribute</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetStrengthAttributeGrow()
int ["StrengthAttributeGrow"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetStrengthAttributeGrow(float attributeGrow)
["StrengthAttributeGrow"].set = float attributeGrow</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBaseStrengthAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusStrengthAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalStrengthAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Agility

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalAgilityAttribute()
int ["OriginalAgilityAttribute"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalAgilityAttribute(int attribute)
["OriginalAgilityAttribute"].set = int attribute</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetAgilityAttributeGrow()
int ["AgilityAttributeGrow"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetAgilityAttributeGrow(float attributeGrow)
["AgilityAttributeGrow"].set = float attributeGrow</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBaseAgilityAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusAgilityAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalAgilityAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Intelligence

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalIntelligenceAttribute()
int ["OriginalIntelligenceAttribute"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalIntelligenceAttribute(int attribute)
["OriginalIntelligenceAttribute"].set = int attribute</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetIntelligenceAttributeGrow()
int ["IntelligenceAttributeGrow"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetIntelligenceAttributeGrow(float attributeGrow)
["IntelligenceAttributeGrow"].set = float attributeGrow</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBaseIntelligenceAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusIntelligenceAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalIntelligenceAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Charisma

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalCharismaAttribute()
int ["OriginalCharismaAttribute"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCharismaAttribute(int attribute)
["OriginalCharismaAttribute"].set = int attribute</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetCharismaAttributeGrow()
int ["CharismaAttributeGrow"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCharismaAttributeGrow(float attributeGrow)
["CharismaAttributeGrow"].set = float attributeGrow</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBaseCharismaAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusCharismaAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalCharismaAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

### Health

#### Health Pool

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalHealthPool()
int ["OriginalHealthPool"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalHealthPool(int healthPool)
["OriginalHealthPool"].set = int healthPool</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetAttributeHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetHealthPoolPerStrength()
float ["HealthPoolPerStrength"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetHealthPoolPerStrength(float healthPoolPerStrength)
["HealthPoolPerStrength"].set = float healthPoolPerStrength</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetFlatBonusHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetPercentageBonusHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBonusHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalHealthPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentHealth()
float ["CurrentHealth"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCurrentHealth(float health)
["CurrentHealth"].set = float health</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentHealthPercentage()
float ["CurrentHealthPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCurrentHealthPercentage(float healthPercentage)
 ["CurrentHealthPercentage"].set = float healthPercentage</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Health Regeneration

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseHealthRegeneration()
float ["BaseHealthRegeneration"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetBaseHealthRegeneration(float healthRegeneration)
["BaseHealthRegeneration"].set = float healthRegeneration</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusHealthRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetFlatHealthRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageHealthRegenerationPerStrength()
float ["PercentageHealthRegenerationPerStrength"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetPercentageHealthRegenerationPerStrength(float percentageHealthRegeneration)
["PercentageHealthRegenerationPerStrength"].set = float percentageHealthRegeneration</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusPercentageHealthRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageHealthRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalHealthRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Health Manipulation

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void TakeDamage(float amount)
void TakeDamage(float amount, DamageType type = DamageType.Pure)
void TakeDamage(float amount, DamageType type, Unit* damager = NULL)
void TakeDamage(float amount, DamageType type, Unit* damager, Ability* ability = NULL)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void Heal(float amount)
void Heal(float amount, Unit* healer = NULL)
void Heal(float amount, Unit* healer, Ability* ability = NULL)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

### Mana

#### Mana Pool

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetOriginalManaPool()
int ["OriginalManaPool"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalManaPool(int healthPool)
["OriginalManaPool"].set = int healthPool</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetAttributeManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetManaPoolPerStrength()
float ["ManaPoolPerStrength"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetManaPoolPerStrength(float healthPoolPerStrength)
["ManaPoolPerStrength"].set = float healthPoolPerStrength</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetFlatBonusManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetPercentageBonusManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBonusManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetTotalManaPool()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentMana()
float ["CurrentMana"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCurrentMana(float health)
["CurrentMana"].set = float health</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentManaPercentage()
float ["CurrentManaPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCurrentManaPercentage(float healthPercentage)
 ["CurrentManaPercentage"].set = float healthPercentage</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Mana Regeneration

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseManaRegeneration()
float ["BaseManaRegeneration"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetBaseManaRegeneration(float healthRegeneration)
["BaseManaRegeneration"].set = float healthRegeneration</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusManaRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetFlatManaRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageManaRegenerationPerStrength()
float ["PercentageManaRegenerationPerStrength"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetPercentageManaRegenerationPerStrength(float percentageManaRegeneration)
["PercentageManaRegenerationPerStrength"].set = float percentageManaRegeneration</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusPercentageManaRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageManaRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalManaRegeneration()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Mana Manipulation

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void ConsumeMana(float amount)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:ConsumeMana(amount)
    local mana = self:GetCurrentMana() - amount
    if mana > 0 then
        self:SetCurrentMana(mana)
    else
        self:SetCurrentMana(0)
    end
end</pre>
        </td>
    </tr>
</table>

### Resistance

#### All Resistance

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Armor

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalArmor()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalArmor(float armor)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeArmor()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeArmor()
    return self:GetTotalAgilityAttribute() * self:GetArmorPerAgility()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetArmorPerAgility()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetArmorPerAgility(float armorPerAgility)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseArmor()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseArmor()
    return self:GetOriginalArmor() + self:GetAttributeArmor()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusArmor()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalArmor()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalArmor()
    return self:GetBaseArmor() + self:GetBonusArmor()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetReceivedPhysicalDamageMultiplier()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentagePhysicalDamageResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetPercentagePhysicalDamageResistance()
    return (1 - self:GetReceivedPhysicalDamageMultiplier()) * 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPhysicalDamageAfterReduction(float damage)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetPhysicalDamageAfterReduction(damage)
    return damage * (1 - self:GetPercentagePhysicalDamageResistance() / 100.0f)
end</pre>
            <pre lang="lua">function Unit:GetPhysicalDamageAfterReduction(damage)
    return damage * self:GetReceivedPhysicalDamageMultiplier()
end</pre>
        </td>
    </tr>
</table>

#### Magical Resistance

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageOriginalMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetPercentageOriginalMagicResistance(float magicResistance)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageAttributeMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetPercentageBaseMagicResistance()
   return (1 - math.pow(1 - self:GetPercentageMagicResistancePerCharisma(), self:GetTotalCharismaAttribute())) * 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageMagicResistancePerCharisma()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetPercentageMagicResistancePerCharisma(float percentageMagicResistancePerCharisma)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBaseMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetPercentageBaseMagicResistance()
   return (1 - ((1 - self:GetPercentageOriginalMagicResistance() / 100.0f) * (1 - self:GetPercentageAttributeMagicResistance() / 100.0f))) * 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalPercentageMagicResistance(damage)
   return (1 - ((1 - self:GetPercentageBaseMagicResistance() / 100.0f) * (1 - self:GetPercentageBonusMagicResistance() / 100.0f))) * 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetMagicDamageAfterReduction(float damage)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetMagicDamageAfterReduction(damage)
   return damage * (1 - self:GetTotalPercentageMagicResistance() / 100.0f)
end</pre>
        </td>
    </tr>
</table>

### Reductions

#### Status Resistance

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalStatusResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalStatusResistance(float statusResistance)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeStatusResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseStatusResistance()
    return (1 - pow(1 - self:GetStatusResistancePerStrength(), self:GetTotalStrengthAttribute())) * 100 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetStatusResistancePerStrength()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetStatusResistancePerStrength(float statusResistancePerStrength)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseStatusResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseStatusResistance()
    return 1 - ((1 - self:GetOriginalStatusResistance()) * (1 - self:GetAttributeStatusResistance())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusStatusResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalStatusResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalStatusResistance()
    return 1 - ((1 - self:GetBaseStatusResistance()) * (1 - self:GetBonusStatusResistance())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetDurationAfterStatusResistance(float duration)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetDurationAfterStatusResistance(duration)
    return duration * (1 - self:GetTotalStatusResistance() / 100.0f) 
end</pre>
        </td>
    </tr>
</table>

#### Cooldown Reduction

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCooldownReduction(float statusResistance)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseCooldownReduction()
    return (1 - pow(1 - self:GetCooldownReductionPerCharisma(), self:GetTotalCharismaAttribute())) * 100 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCooldownReductionPerCharisma()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCooldownReductionPerCharisma(float statusResistancePerCharisma)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseCooldownReduction()
    return 1 - ((1 - self:GetOriginalCooldownReduction()) * (1 - self:GetAttributeCooldownReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalPercentageCooldownReduction()
    return 1 - ((1 - self:GetBaseCooldownReduction()) * (1 - self:GetPercentageBonusCooldownReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCooldown(float cooldown)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetCooldown(cooldown)
    return duration * (1 - self:GetTotalPercentageCooldownReduction() / 100.0f) 
end</pre>
        </td>
    </tr>
</table>

#### Manacost Reduction
<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalManacostReduction(float statusResistance)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseManacostReduction()
    return (1 - pow(1 - self:GetManacostReductionPerCharisma(), self:GetTotalCharismaAttribute())) * 100 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetManacostReductionPerCharisma()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetManacostReductionPerCharisma(float statusResistancePerCharisma)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseManacostReduction()
    return 1 - ((1 - self:GetOriginalManacostReduction()) * (1 - self:GetAttributeManacostReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalPercentageManacostReduction()
    return 1 - ((1 - self:GetBaseManacostReduction()) * (1 - self:GetPercentageBonusManacostReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetManacost(float cooldown)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetManacost(cooldown)
    return duration * (1 - self:GetTotalPercentageManacostReduction() / 100.0f) 
end</pre>
        </td>
    </tr>
</table>

#### Goldcost Reduction
<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalGoldcostReduction(float statusResistance)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseGoldcostReduction()
    return (1 - pow(1 - self:GetGoldcostReductionPerCharisma(), self:GetTotalCharismaAttribute())) * 100 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetGoldcostReductionPerCharisma()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetGoldcostReductionPerCharisma(float statusResistancePerCharisma)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseGoldcostReduction()
    return 1 - ((1 - self:GetOriginalGoldcostReduction()) * (1 - self:GetAttributeGoldcostReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalPercentageGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalPercentageGoldcostReduction()
    return 1 - ((1 - self:GetBaseGoldcostReduction()) * (1 - self:GetPercentageBonusGoldcostReduction())) 
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetGoldcost(float cooldown)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetGoldcost(cooldown)
    return duration * (1 - self:GetTotalPercentageGoldcostReduction() / 100.0f) 
end</pre>
        </td>
    </tr>
</table>

#### Spell Amplification

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Cast Range

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Cast Radius

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Movement Speed

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

### Attack

#### Attack Speed

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Attack Time

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Attack Range

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

#### Attack Type

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre></pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>