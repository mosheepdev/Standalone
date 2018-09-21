# Ability

Abilities are passive or active spells.
Every unit can only have 1 of each ability.

## Functions

### Base Info

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>int GetId()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get ID of this ability.<br/>
            All instances share this id = type ID.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetName()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Codename of the ability.<br/>
            Used for adding the ability to <a href="../Unit/README.md">Unit</a>, referencing it or translations.
        </td>
        <td></td>
    </tr>
</table>

### Level + Experience

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
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
        <td>
            No
        </td>
        <td>
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetLevel()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Current level of the ability.<br/>
            <code>< 0</code> = not learned
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool IsLearned()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Utility function which checks <code>GetLevel()</code> for being <code>> 0</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:IsLearned()
    return self:GetLevel() > 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetMaxLevel()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Maximum level of the ability.<br/>
            <code><= 0</code> = cannot be upgraded
        </td>
        <td>
            <pre lang="lua">function Ability:GetMaxLevel()
    return max(self:GetLevel(), self:GetValue("Max_Level", "Integer") or 1)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool Upgrade()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Perform upgrade of this ability.<br/>
            Does not spend ability point.<br/>
            <br/>
            Returns <code>true</code> on success.<br/>
            <br/>
            To run code on upgrade, override <code>OnUpgrade()</code>. To determine whenever to show GUI selection, override <code>CanBeUpgraded()</code>.
        </td>
        <td>
            <pre lang="lua">function Upgrade()
    if not self:CanBeUpgraded() then
        return false
    end
    local level = self:GetLevel()
    if level >= self:GetMaxLevel() then
        return false
    end
    _Level = level + 1
    if not self:CanBeUpgraded() then
        _Level = level
        return false
    end
    return true
end
-- _Level is internal variable behind self:GetLevel()</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool OnUpgrade()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Called from <code>Upgrade()</code> to allow custom code on ability upgrade.<br/>
            <br/>
            Return <code>true</code> if everything is OK.<br/>
            Return <code>false</code> (or <code>nil</code>) to prevent the ability to be upgraded.
        </td>
        <td>
            <pre lang="lua">function Ability:OnUpgrade()
    return true
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool CanBeUpgraded()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Yes
        </td>
        <td>
            Determine whenever to show GUI to allow upgrade of this ability.</br>
            <br/>
            Without <code>true</code> from this, <code>Upgrade()</code> will have no way to be called from player. Does not prevent <code>Upgrade()</code> to be called from code.
        </td>
        <td>
            <pre lang="lua">function Ability:CanUpgrade()
    local minLevel = self:GetValue("Level."..(self:GetLevel() + 1))
    return minLevel and self:GetOwner():GetLevel() >= minLevel
end</pre>
        </td>
    </tr>
</table>

### Texture

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>string GetTexture(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Yes
        </td>
        <td>
            Get ability's current texture
        </td>
        <td></td>
    </tr>
</table>

### Cast

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void OnCast(vec3 position, vec3 direction, Unit unit)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Yes
        </td>
        <td>
            Perform effect of the ability.<br/>
            <br/>
            Called at animation's Cast Point.<br/>
            <br/>
            May have different variants:<br/>
            <ul>
                <li>
                    <code>nil, nil, nil</code> = No Target
                </li>
                <li>
                    <code>position, nil, nil</code> = Point / AoE Target
                </li>
                <li>
                    <code>nil, direction, nil</code> = Direction Target
                </li>
                <li>
                    <code>position, direction, nil</code> = Vector Target
                </li>
                <li>
                    <code>position, nil, unit</code> = Unit Target
                </li>
                <li>
                    <code>position, direction, unit</code> = Unit Vector Target
                </li>
            </ul>
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void Cast()
void Cast(vec3 position)
void Cast(vec3 position, vec3 direction)
void Cast(vec3 position, vec3 direction, Unit unit)</pre>
        </td>
        <td>
            Server
        </td>
        <td>
            No
        </td>
        <td>
            Perform cast of the ability without animation but still consume resources.<br/>
            <br/>
            To still perform animation, use <code>PerformCast(vec3, vec3, Unit)</code>
        </td>
        <td>
            <pre lang="lua">function Ability:Cast(position, direction, unit)
    self:ConsumeResources(true, true, true);
    self:OnCast(position, direction, unit)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void PerformCast(vec3 position, vec3 direction, Unit unit)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Perform cast of the ability with animation and consume resources.<br/>
            <br/>
            To not perform animation, use <code>Cast(vec3, vec3, Unit)</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:PerformCast(position, direction, unit)
    
    -- Start Animation
    
    -- At Cast Point
    self:Cast(position, direction, unit)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCastPoint()
float GetCastPoint(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get time (in seconds) after start of animation at which this ability should be cast.
        </td>
        <td>
            <pre lang="lua">function Ability:GetChannelTime(level)
    return self:GetValue("Cast_Point", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetChannelTime()
float GetChannelTime(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get channel time for the ability.
        </td>
        <td>
            <pre lang="lua">function Ability:GetChannelTime(level)
    return self:GetValue("Channel_Time", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool IsChannel()
bool IsChannel(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Utility function for channel abilities.<br/>
            Simple check of <code>GetChannelTime()</code> being <code>= 0</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:IsChannel(level)
    return self:GetChannelTime(level) == 0
end</pre>
        </td>
    </tr>
</table>

### Animation

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>string GetAnimation()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get name of animation for this ability.<br/>
            If <code>nil</code> (or empty string) is returned, animation for this slot is used.
        </td>
        <td></td>
    </tr>
</table>

### Resources

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetBaseCooldown(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get cooldown time for specified level of the ability.<br/>
            The <code>level</code> parameter is same as <code>GetLevel()</code> at start of the ability (should not change anyway during cast).<br/>
            <br/>
            Value for <code>level = 0</code> is not defined and should not be called at any time (no cooldown required when the ability is not learned).<br/>
            <br/>
            Should not count with Cooldown Reduction because (in base implementation) is called from <code>GetCooldown()</code> where is modified by Cooldown Reduction.
        </td>
        <td>
            <pre lang="lua">function Ability:GetBaseCooldown(level)
    return self:GetValue("Cooldown", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCooldown(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get cooldown time for specified level of the ability after Cooldown Reduction.<br/>
            The <code>level</code> parameter is same as <code>GetLevel()</code> at start of the ability (should not change anyway during cast).<br/>
            <br/>
            Value for <code>level = 0</code> is not defined and should not be called at any time (no cooldown required when the ability is not learned).<br/>
            <br/>
            Base implementation counts with Cooldown Reduction.<br/>
            For custom implementation, don't forget to count with Cooldown Reduction or use <code>GetBaseCooldown</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:GetCooldown(level)
    return self:GetOwner():GetCooldown(self:GetBaseCooldown(level))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentCooldownElapsed()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get elapsed time of cooldown.
        </td>
        <td>
            <pre lang="lua">function Ability:GetCurrentCooldownElapsed()
    return self:GetCooldown() - self:GetCurrentCooldownRemaining()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentCooldownRemaining()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get remaining time of the cooldown.<br/>
            <br/>
            To change this value, use <code>StartCooldown(float)</code>.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>float GetCurrentCooldownPercentage(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Utility function to convert (current) absolute cooldown values into percentage.
        </td>
        <td>
            <pre lang="lua">function Ability:GetCurrentCooldownPercentage(level)
    local max = self:GetCooldown(level)
    local value = self:GetCurrentCooldown() / max
    if value < 0 then
        return 0
    end
    if value > 1 then
        return 100
    end
    return value * 100
end</pre>
            <pre lang="lua">function Ability:GetCurrentCooldownPercentage(level)
    local max = self:GetCooldown(level)
    local value = self:GetCurrentCooldown() / max
    return clamp(value * 100, 0, 100)
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void StartCooldown(float cooldown)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            This function forces the ability to go on specified cooldown.<br/>
            <br/>
            Value can be above <code>GetCooldown()</code> but will be displayed as <code>100%</code> of the ability's cooldown (cannot go <code>>100%</code> visually).<br/>
            Displayed numeric value is affected by <code>GetCurrentCooldownRemaining()</code> which can be above <code>GetCooldown()</code> (for case of level-up of change in Cooldown Reduction).
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseManacost(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetBaseManacost(level)
    return self:GetValue("Manacost", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetManacost(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetManacost(level)
    return self:GetOwner():GetManacost(self:GetBaseManacost(level))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetBaseGoldcost(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
        </td>
        <td>
            <pre lang="lua">function Ability:GetBaseGoldcost(level)
    return self:GetValue("Goldcost", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>int GetGoldcost(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
        </td>
        <td>
            <pre lang="lua">function Ability:GetGoldcost(level)
    return self:GetOwner():GetGoldcost(self:GetBaseGoldcost(level))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>void ConsumeResources(bool cooldown, bool mana, bool gold)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
        </td>
        <td>
            <pre lang="lua">function Ability:ConsumeResources(cooldown, mana, gold)
    local level = self:GetLevel()
    -- Cooldown
    if cooldown then
        self:StartCooldown(self:GetCooldown(level))
    end
    -- Mana
    if mana then
        self:GetOwner():ConsumeMana(mana)
    end
    -- Gold
    if gold then
        local player = self:GetOwner():GetPlayer()
        if player then
            player:ConsumeGold(mana)
        end
    end
end</pre>
        </td>
    </tr>
</table>

### Ownership

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>handle GetOwner()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>handle GetOriginalOwner()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool IsStolen()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:IsStolen()
    local originalOwner = self:GetOriginalOwner()
    return originalOwner and originalOwner ~= self:GetOwner()
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>bool CanBeStolen()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:CanBeStolen()
    return true
end</pre>
        </td>
    </tr>
</table>

### Special Values

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>string GetValue(string key)
string GetValue(string key, int level)
string GetValue(string key, string type)
string GetValue(string key, string type, int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Get Ability's value for specified level.<br/>
            To get raw data, use <code>GetValueRaw(string)</code>. 
        </td>
        <td>
            <pre lang="lua">function Ability:GetValue(key, level)
    level = level or self:GetLevel()
    
    local words = {}
    for word in self:GetValueRaw(key):gmatch(ABILITY_VALUE_SEPARATOR) do
        table.insert(words, word)
    end
    
    if #words == 0 then
        return 0
    end
    if #words == 1 or level <= 0 then
        return words[0]
    end
    if #words < level then
        return words[words - 1]
    else
        return words[level - 1]
    end
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>string GetValueRaw(string key)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void SetValueRaw(string key, string value)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

### Base Ability Info

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Can be overloaded</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetAbilityBaseDamage(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityBaseDamage(level)
    return self:GetValue("Damage", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>float GetAbilityDamage(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityDamage(level)
    return self:GetOwner():GetDamageAfterSpellAmplification(self:GetBaseAbilityDamage(level))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>DamageType GetAbilityDamageType(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityDamageType(level)
    return self:GetValue("DamageType", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>DamageFlags GetAbilityDamageFlags(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityDamageFlags(level)
    return self:GetValue("DamageFlags", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TeamFlags GetAbilityTargetTeam(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityTargetTeam(level)
    return self:GetValue("TargetTean", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TypeFilter GetAbilityTargetType(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityTargetTtype(level)
    return self:GetValue("TargetType", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>FlagFilter GetAbilityTargetFlags(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityTargetFlags(level)
    return self:GetValue("TargetFlags", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>AbilityTargetting GetAbilityTargeting(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td></td>
        <td>
            <pre lang="lua">function Ability:GetAbilityTargeting(level)
    return self:GetValue("Targetting", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TeamFlags GetAbilityBaseCastRange(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Maximum radius to cast a spell.<br/> 
            <br/>
            Not affected by owner's Cast Range Increase.<br/>
            Affected version is <code>GetAbilityCastRange(int)</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:GetAbilityBaseCastRange(level)
    return self:GetValue("CastRange", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TeamFlags GetAbilityCastRange(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Maximum radius to cast a spell.<br/> 
            <br/>
            Affected by owner's Cast Range Increase.<br/>
            Not affected version is <code>GetAbilityBaseCastRange(int)</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:GetAbilityCastRange(level)
    return self:GetOwner():GetTotalCastRange(self:GetAbilityBaseCastRange(level))
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TeamFlags GetAbilityBaseRadius(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Radius of effect for AoE spells and auras.<br/>
            <br/>
            Not affected by owner's Radius Increase.<br/>
            Affected version is <code>GetAbilityRadius(int)</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:GetAbilityBaseRadius(level)
    return self:GetValue("Radius", level or self:GetLevel()) or 0
end</pre>
        </td>
    </tr>
    <tr>
        <td>
            <pre>TeamFlags GetAbilityRadius(int level)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            No
        </td>
        <td>
            Radius of effect for AoE spells and auras.<br/>
            <br/>
            Affected by owner's Radius Increase.<br/>
            Not affected version is <code>GetAbilityBaseRadius(int)</code>.
        </td>
        <td>
            <pre lang="lua">function Ability:GetAbilityRadius(level)
    return self:GetOwner():GetTotalCastRadius(self:GetAbilityBaseRadius(level))
end</pre>
        </td>
    </tr>
</table>
