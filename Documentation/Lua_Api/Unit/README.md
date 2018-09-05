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
  - [Magical](#magic-resistance)
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
void ["TotalXp"].set = float xp
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
        <td>
            <pre lang="lua">function Unit:GetFlatBonusDamage()
    local damage = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetFlatBonusDamage then
            local m_damage = m:GetFlatBonusDamage()
            if m_damage then
                damage = damage + m_damage
            end
        end
    end
    return damage
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetPercentageBonusDamage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetPercentageBonusDamage()
    local damage = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetPercentageBonusDamage then
            local m_damage = m:GetPercentageBonusDamage()
            if m_damage then
                damage = damage + m_damage
            end
        end
    end
    return damage
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetBaseStrengthAttribute()
    return self:GetOriginalStrengthAttribute() + math.floor( self:GetStrengthAttributeGrow() * self:GetLevel() )
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusStrengthAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBonusStrengthAttribute()
    local attribute = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetBonusStrength then
            local m_attribute = m:GetBonusStrength()
            if m_attribute then
                attribute = attribute + m_attribute
            end
        end
    end
    return attribute
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalStrengthAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalStrengthAttribute()
    return self:GetBaseStrengthAttribute() + self:GetBonusStrengthAttribute()
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetBaseAgilityAttribute()
    return self:GetOriginalAgilityAttribute() + math.floor( self:GetAgilityAttributeGrow() * self:GetLevel() )
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusAgilityAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBonusAgilityAttribute()
    local attribute = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetBonusAgility then
            local m_attribute = m:GetBonusAgility()
            if m_attribute then
                attribute = attribute + m_attribute
            end
        end
    end
    return attribute
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalAgilityAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAgilityAttribute()
    return self:GetBaseAgilityAttribute() + self:GetBonusAgilityAttribute()
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetBaseIntelligenceAttribute()
    return self:GetOriginalIntelligenceAttribute() + math.floor( self:GetIntelligenceAttributeGrow() * self:GetLevel() )
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusIntelligenceAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBonusIntelligenceAttribute()
    local attribute = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetBonusIntelligence then
            local m_attribute = m:GetBonusIntelligence()
            if m_attribute then
                attribute = attribute + m_attribute
            end
        end
    end
    return attribute
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalIntelligenceAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalIntelligenceAttribute()
    return self:GetBaseIntelligenceAttribute() + self:GetBonusIntelligenceAttribute()
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetBaseCharismaAttribute()
    return self:GetOriginalCharismaAttribute() + math.floor( self:GetCharismaAttributeGrow() * self:GetLevel() )
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetBonusCharismaAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBonusCharismaAttribute()
    local attribute = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetBonusCharisma then
            local m_attribute = m:GetBonusCharisma()
            if m_attribute then
                attribute = attribute + m_attribute
            end
        end
    end
    return attribute
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void GetTotalCharismaAttribute()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCharismaAttribute()
    return self:GetBaseCharismaAttribute() + self:GetBonusCharismaAttribute()
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetFlatBonusHealthPool()
    local pool = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetFlatHealthBonus then
            local m_pool = m:GetFlatHealthBonus()
            if m_pool then
                pool = pool + m_pool
            end
        end
    end
    return pool
end</pre>
        </td>
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
        <td>
            Simple implementation (not real):
            <pre lang="lua">function Unit:TakeDamage(amount, type)
    if type == DAMAGE_PHYSICAL then
        amount = self:GetPhysicalDamageAfterReduction(amount)
    end
    if type == DAMAGE_MAGICAL then
        amount = self:GetMagicDamageAfterReduction(amount)
    end
    
    amount = self:GetDamageAfterAllReduction(amount)
    
    self:SetCurrentHealth(self:GetCurrentHealth() - amount)
end</pre>
        </td>
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
        <td>
            <pre lang="lua">function Unit:GetFlatBonusManaPool()
    local pool = 0
    for i,m in pairs(self:GetAllModifiers()) do
        if m and m.GetFlatManaBonus then
            local m_pool = m:GetFlatManaBonus()
            if m_pool then
                pool = pool + m_pool
            end
        end
    end
    return pool
end</pre>
        </td>
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
            <pre>float GetOriginalArmor()
float ["OriginalArmor"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalArmor(float armor)
["OriginalArmor"].set = float armor</pre>
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
            <pre>float GetArmorPerAgility()
float ["ArmorPerAgility"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetArmorPerAgility(float armorPerAgility)
["ArmorPerAgility"].set = float armorPerAgility</pre>
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
    return damage * (1 - self:GetPercentagePhysicalDamageResistance() / 100.0)
end</pre>
            <pre lang="lua">function Unit:GetPhysicalDamageAfterReduction(damage)
    return damage * self:GetReceivedPhysicalDamageMultiplier()
end</pre>
        </td>
    </tr>
</table>

#### Magic Resistance

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalMagicResistance()
float ["OriginalMagicResistance"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalMagicResistance(float magicResistance)
["OriginalMagicResistance"].set = float magicResistance</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMagicResistance()
   return (1 - math.pow(1 - self:GetMagicResistancePerCharisma(), self:GetTotalCharismaAttribute())) * 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetMagicResistancePerCharisma()
float ["MagicResistancePerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetMagicResistancePerCharisma(float magicResistancePerCharisma)
["MagicResistancePerCharisma"].set = float magicResistancePerCharisma</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMagicResistance()
   return (1 - ((1 - self:GetOriginalMagicResistance() / 100.0) * (1 - self:GetAttributeMagicResistance() / 100.0))) * 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalMagicResistance()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMagicResistance(damage)
   return (1 - ((1 - self:GetBaseMagicResistance() / 100.0) * (1 - self:GetBonusMagicResistance() / 100.0))) * 100.0
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
   return damage * (1 - self:GetTotalMagicResistance() / 100.0)
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
            <pre>float GetOriginalStatusResistance()
float ["OriginalStatusResistance"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalStatusResistance(float statusResistance)
["OriginalStatusResistance"].set = float statusResistance</pre>
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
            <pre>float GetStatusResistancePerStrength()
float ["StatusResistancePerStrength"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetStatusResistancePerStrength(float statusResistancePerStrength)
["StatusResistancePerStrength"].set = float statusResistancePerStrength</pre>
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
    return duration * (1 - self:GetTotalStatusResistance() / 100.0) 
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
            <pre>float GetOriginalCooldownReduction()
float ["OriginalCooldownReduction"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCooldownReduction(float statusResistance)
["OriginalCooldownReduction"].set = float statusResistance</pre>
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
            <pre>float GetCooldownReductionPerCharisma()
float ["CooldownReductionPerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCooldownReductionPerCharisma(float statusResistancePerCharisma)
["CooldownReductionPerCharisma"].set = float statusResistancePerCharisma</pre>
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
            <pre>float GetBonusCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCooldownReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCooldownReduction()
    return 1 - ((1 - self:GetBaseCooldownReduction()) * (1 - self:GetBonusCooldownReduction())) 
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
    return duration * (1 - self:GetTotalCooldownReduction() / 100.0) 
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
            <pre>float GetOriginalManacostReduction()
float ["OriginalManacostReduction"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalManacostReduction(float manacostReduction)
float ["OriginalManacostReduction"].get</pre>
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
            <pre>float GetManacostReductionPerCharisma()
float ["ManacostReductionPerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetManacostReductionPerCharisma(float statusResistancePerCharisma)
["ManacostReductionPerCharisma"].set = float statusResistancePerCharisma</pre>
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
            <pre>float GetBonusManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalManacostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalManacostReduction()
    return 1 - ((1 - self:GetBaseManacostReduction()) * (1 - self:GetBonusManacostReduction())) 
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
    return duration * (1 - self:GetTotalManacostReduction() / 100.0) 
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
            <pre>float GetOriginalGoldcostReduction()
float ["OriginalGoldcostReduction"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalGoldcostReduction(float goldcostReduction)
["OriginalGoldcostReduction"].set = float goldcostReduction</pre>
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
            <pre>float GetGoldcostReductionPerCharisma()
float ["GoldcostReductionPerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetGoldcostReductionPerCharisma(float statusResistancePerCharisma)
["GoldcostReductionPerCharisma"].set = float statusResistancePerCharisma</pre>
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
            <pre>float GetBonusGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalGoldcostReduction()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalGoldcostReduction()
    return 1 - ((1 - self:GetBaseGoldcostReduction()) * (1 - self:GetBonusGoldcostReduction())) 
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
    return duration * (1 - self:GetTotalGoldcostReduction() / 100.0) 
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
            <pre>float GetOriginalSpellAmplification()
float ["OriginalSpellAmplification"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalSpellAmplification(float spellAmplification)
["OriginalSpellAmplification"].set = float spellAmplification</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeSpellAmplification()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeSpellAmplification()
    return 100 + self:GetSpellAmplificationPerIntelligence() * self:GetTotalIntelligenceAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetSpellAmplificationPerIntelligence()
float ["SpellAmplificationPerIntelligence"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetSpellAmplificationPerIntelligence(float spellAmplificationPerIntelligence)
["SpellAmplificationPerIntelligence"].set = float spellAmplificationPerIntelligence</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseSpellAmplification()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseSpellAmplification()
    return self:GetOriginalSpellAmplification() * self:GetAttributeSpellAmplification() / 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusSpellAmplification()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalSpellAmplification()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalSpellAmplification()
    return self:GetBaseSpellAmplification() * self:GetBonusSpellAmplification() / 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetDamageAfterSpellAmplification(float damage)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetDamageAfterSpellAmplification(damage)
    return damage * (self:GetTotalSpellAmplification() / 100.0)
end</pre>
        </td>
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
            <pre>float GetOriginalCastRangeIncrease()
float ["OriginalCastRangeIncrease"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCastRangeIncrease(float castRangeIncrease)
["OriginalCastRangeIncrease"].set = float castRangeIncrease</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeCastRangeIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeCastRangeIncrease()
    return self:GetCastRangeIncreasePerCharisma() * self:GetTotalCharismaAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCastRangeIncreasePerCharisma()
float ["CastRangeIncreasePerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCastRangeIncreasePerCharisma(float castRangeIncreasePerCharisma)
["CastRangeIncreasePerCharisma"].set = float castRangeIncreasePerCharisma</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseCastRangeIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseCastRangeIncrease()
    return self:GetOriginalCastRangeIncrease() * self:GetAttributeCastRangeIncrease() / 100.0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusCastRangeIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCastRangeIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCastRangeIncrease()
    return self:GetBaseCastRangeIncrease() * self:GetBonusCastRangeIncrease() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalCastRangePercentage()
float ["OriginalCastRangePercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCastRangePercentage(float castRangeAmplification)
["OriginalCastRangePercentage"].set = float castRangeAmplification</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeCastRangePercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeCastRangePercentage()
    return 100 + self:GetCastRangePercentagePerCharisma() * self:GetTotalCharismaAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCastRangePercentagePerCharisma()
float ["CastRangePercentagePerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCastRangePercentagePerCharisma(float castRangePercentagePerCharisma)
["CastRangePercentagePerCharisma"].set = float castRangePercentagePerCharisma</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseCastRangePercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseCastRangePercentage()
    return self:GetOriginalCastRangePercentage() * self:GetAttributeCastRangePercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusCastRangePercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCastRangePercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCastRangePercentage()
    return self:GetBaseCastRangePercentage() * self:GetBonusCastRangePercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCastRange(float castRange)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCastRange(castRange)
    return (castRange + self:GetTotalCastRangeIncrease()) * (self:GetTotalCastRangePercentage() / 100)
end</pre>
        </td>
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
            <pre>float GetOriginalCastRadiusPercentage()
float ["OriginalCastRadiusPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalCastRadiusPercentage(float castRadius)
["OriginalCastRadiusPercentage"].set = float castRadius</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeCastRadiusPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeCastRadiusPercentage()
    return 100 + self:GetCastRadiusPercentagePerCharisma() * self:GetTotalCharismaAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCastRadiusPercentagePerCharisma()
float ["CastRadiusPercentagePerCharisma"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetCastRadiusPercentagePerCharisma(float castRadiusPercentagePerCharisma)
["CastRadiusPercentagePerCharisma"].set = float castRadiusPercentagePerCharisma</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseCastRadiusPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseCastRadiusPercentage()
    return self:GetOriginalCastRadiusPercentage() * self:GetAttributeCastRadiusPercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusCastRadiusPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCastRadiusPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCastRadiusPercentage()
    return self:GetBaseCastRadiusPercentage() * self:GetBonusCastRadiusPercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalCastRadius(float radius)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalCastRadius(radius)
    return radius * (self:GetTotalCastRadiusPercentage() / 100.0f)
end</pre>
        </td>
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
            <pre>float GetOriginalMovementSpeedIncrease()
float ["OriginalMovementSpeedIncrease"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalMovementSpeedIncrease(float castRangeIncrease)
["OriginalMovementSpeedIncrease"].set = float castRangeIncrease</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeMovementSpeedIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeMovementSpeedIncrease()
    return self:GetMovementSpeedIncreasePerAgility() + self:GetTotalAgilityAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetMovementSpeedIncreasePerAgility()
float ["MovementSpeedIncreasePerAgility"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetMovementSpeedIncreasePerAgility(float castRangeIncreasePerAgility)
["MovementSpeedIncreasePerAgility"].set = float castRangeIncreasePerAgility</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseMovementSpeedIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMovementSpeedIncrease()
    return self:GetOriginalMovementSpeedIncrease() + self:GetAttributeMovementSpeedIncrease()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusMovementSpeedIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalMovementSpeedIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMovementSpeedIncrease()
    return self:GetBaseMovementSpeedIncrease() + self:GetBonusMovementSpeedIncrease()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalMovementSpeedPercentage()
float ["OriginalMovementSpeedPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalMovementSpeedPercentage(float movementSpeedAmplification)
["OriginalMovementSpeedPercentage"].set = float movementSpeedAmplification</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeMovementSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeMovementSpeedPercentage()
    return 100 + self:GetMovementSpeedPercentagePerAgility() * self:GetTotalAgilityAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetMovementSpeedPercentagePerAgility()
float ["MovementSpeedPercentagePerAgility"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetMovementSpeedPercentagePerAgility(float movementSpeedPercentagePerAgility)
["MovementSpeedPercentagePerAgility"].set = float movementSpeedPercentagePerAgility</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseMovementSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseMovementSpeedPercentage()
    return self:GetOriginalMovementSpeedPercentage() * self:GetAttributeMovementSpeedPercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusMovementSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalMovementSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMovementSpeedPercentage()
    return self:GetBaseMovementSpeedPercentage() * self:GetBonusMovementSpeedPercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalMovementSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalMovementSpeed()
    return self:GetTotalMovementSpeedIncrease() * self:GetTotalMovementSpeedPercentage() / 100.0f
end</pre>
        </td>
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
            <pre>float GetOriginalAttackSpeed()
float ["OriginalAttackSpeed"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalAttackSpeed(float attackSpeed)
["OriginalAttackSpeed"].set = float attackSpeed</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeAttackSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttackSpeedPerAgility()
float ["AttackSpeedPerAgility"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttackSpeedPerAgility()
    return self:GetTotalAgilityAttribute() * self:GetAttackSpeedPerAgility()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void SetAttackSpeedPerAgility(float attackSpeedPerAgility)
["AttackSpeedPerAgility"].set = float attackSpeedPerAgility</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseAttackSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseAttackSpeed()
    return self:GetOriginalAttackSpeed() + self:GetAttributeAttackSpeed()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusAttackSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackSpeedWithoutPercentageIncrease()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackSpeedWithoutPercentageIncrease()
    return self:GetBaseAttackSpeed() + self:GetBonusAttackSpeed()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetOriginalAttackSpeedPercentage()
float ["OriginalAttackSpeedPercentage"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalAttackSpeedPercentage(float attackSpeedPercentage)
["OriginalAttackSpeedPercentage"].set = float attackSpeedPercentage</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttributeAttackSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttributeAttackSpeedPercentage()
    return 100 + self:GetAttackSpeedPercentagePerAgility() * self:GetTotalAgilityAttribute()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttackSpeedPercentagePerAgility()
float ["AttackSpeedPercentagePerAgility"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetAttackSpeedPercentagePerAgility(float attackSpeedPercentagePerAgility)
["AttackSpeedPercentagePerAgility"].set = float attackSpeedPercentagePerAgility</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseAttackSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetBaseAttackSpeedPercentage()
    return self:GetOriginalAttackSpeedPercentage() * self:GetAttributeAttackSpeedPercentage() / 100.0f
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusAttackSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackSpeedPercentage()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackSpeedPercentage()
    return self:GetBaseAttackSpeedPercentage() * (self:GetBonusAttackSpeedPercentage() / 100.0f)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackSpeed()
    return self:GetTotalAttackSpeedWithoutPercentageIncrease() * self:GetTotalAttackSpeedPercentage()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetMinAttackSpeedLimit()
int ["MinAttackSpeedLimit"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetMaxAttackSpeedLimit()
int ["MaxAttackSpeedLimit"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetAttackSpeedLimit(int min, int max)
["MinAttackSpeedLimit"].set = int limit
["MaxAttackSpeedLimit"].set = int limit</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackSpeedInLimits()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackSpeedInLimits()
    local attackSpeed = self:GetTotalAttackSpeed();
    if attackSpeed < self:GetMinAttackSpeedLimit() then
        return self:GetMinAttackSpeedLimit();
    end
    if attackSpeed > self:GetMaxAttackSpeedLimit() then
        return self:GetMaxAttackSpeedLimit();
    end
    return attackSpeed;
end</pre>
        </td>
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
            <pre>float GetBaseAttackTime()
float ["BaseAttackTime"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetBaseAttackTime(float attackTime)
["BaseAttackTime"].set = float attackTime</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusAttackTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackTimeWithoutAttackSpeed()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackTimeWithoutAttackSpeed()
    return return self:GetBaseAttackTime() + self:GetBonusAttackTime()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackTime()
    return self:GetTotalAttackTimeWithoutAttackSpeed() / ( self:GetTotalAttackSpeedInLimits() / 100.0f )
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetAttacksPerSecond()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAttacksPerSecond()
    return 1 / self:GetTotalAttackTime()
end</pre>
        </td>
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
            <pre>float GetBaseAttackRange()
float ["BaseAttackRange"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetBaseAttackRange(float attackRange)
["BaseAttackRange"].set = float attackRange</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetBonusAttackRange()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetTotalAttackRange()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetTotalAttackRange()
    return self:GetBaseAttackRange() + self:GetBonusAttackRange()
end</pre>
        </td>
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
            <pre>AttackType GetOriginalAttackType()
AttackType ["OriginalAttackType"].get</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetOriginalAttackType(AttackType attackType)
["OriginalAttackType"].set = AttackType attackType</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>AttackType GetAttackType()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool IsMelee()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:IsMelee()
    return self:GetAttackType() == ATTACK_TYPE_MELEE
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool IsRanged()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:IsRanged()
    return self:GetAttackType() != ATTACK_TYPE_MELEE
end</pre>
        </td>
    </tr>
</table>

### Modifiers

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>Modifier[] GetAllModifiers()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>Modifier[] GetAllBuffs()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAllBuffs()
    local buffs = {}
    for k,m in pairs(self:GetAllModifiers()) do
        if m and ((not m.IsDebuff) or (not m.IsDebuff())) then
            buffs:insert(m)
        end
    end
    return buffs;
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>Modifier[] GetAllDebuffs()</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Unit:GetAllDebuffs()
    local debuffs = {}
    for k,m in pairs(self:GetAllModifiers()) do
        if m and m.IsDebuff and m.IsDebuff() then
            debuffs:insert(m)
        end
    end
    return debuffs;
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>Modifier AddNewModifier(string name)
Modifier AddNewModifier(string name, Unit sourceUnit)
Modifier AddNewModifier(string name, Unit sourceUnit, Ability sourceAbility)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool HasModifier(string name)
bool HasModifier(string name, Unit sourceUnit)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetModifierCount(string name)
int GetModifierCount(string name, Unit sourceUnit)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get amount of modifiers of specified name (and from specified Unit).
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetModifierStackCount(string name)
int GetModifierStackCount(string name, Unit sourceUnit)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get total amount of stacks from modifiers of specified name (and from specified Unit).<br>
            <br>
            Same as `GetModifierStackCount(...)` but summary of their stacks.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>Modifier GetModifier(string name)
Modifier GetModifier(string name, Unit sourceUnit)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void RemoveModifier(Modifier modifier)</pre>
        </td>
        <td>
            Server
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int RemoveModifiers(string name)
int RemoveModifiers(string name, Unit sourceUnit)
int RemoveModifiers(string name, Unit sourceUnit, Ability sourceAbility)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Remove modifiers by specified name (and source Unit + Ability).<br>
            <br>
            Returns amount of removed modifiers.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int PurgeModifiers(PurgeType purgeType)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            Remove all modifiers which can be purged by `purgeType`.<br>
            <br>
            `PurgeType.None` does nothing.<br>
            <br>
            Returns amount of removed modifiers.
        </td>
        <td></td>
    </tr>
</table>