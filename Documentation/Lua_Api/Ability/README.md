# Ability

Abilities are passive or active spells.
Every unit can only have 1 of each ability.

## Functions

### Get Id
Get ID of this ability.
All instances share this id = type ID.

**Should not be overloaded.** (no effect on C++ code)
```
int GetId()
```

### Get Name
Codename of the ability.
Used for adding the ability to [Unit](../Unit/README.md), referencing it or translations.

**Should not be overloaded.** (no effect on C++ code)
```
string GetName()
```

### Get Level
Current level of the ability.

`0` = not learned

**Should not be overloaded.** (no effect on C++ code)
```
int GetLevel()
```

### Is Learned
Utility function which checks [`GetLevel()`](#get-level) for being `> 0`.

**Should not be overloaded.** (no effect on C++ code)
```
bool IsLearned()
```
Implemented as:
```lua
function Ability:IsLearned()
    return self:GetLevel() > 0
end
```

### Upgrade
Perform upgrade of this ability.
Does not spend ability point.

Returns `true` on success.

To run code on upgrade, override [`OnUpgrade()`](#on-upgrade). To determine whenever to show GUI selection, override [`CanBeUpgraded()`](#can-be-upgraded).

**Should not be overloaded.** (no effect on C++ code)
```
bool Upgrade()
```

### On Upgrade
Called from [`Upgrade()`](#upgrade) to allow custom code on ability upgrade.

Return `true` if everything is OK.
Return `false` (or `nil`) to prevent the ability to be upgraded.
```
bool OnUpgrade()
```
Implemented as:
```lua
function Ability:OnUpgrade()
    return true
end
```

### Can Be Upgraded
Determine whenever to show GUI to allow upgrade of this ability.

Without `true` from this, `Upgrade()` will have no way to be called from player. Does not prevent `Upgrade()` to be called from code.
```
bool CanBeUpgraded()
```
Implemented as:
```lua
function Ability:CanUpgrade()
    return self:GetOwner():GetLevel() < (self:GetValue("MinLevel") or 0)
end
```

### Get Texture
Get ability's current texture
```
string GetTexture(int level)
```

### On Cast
Perform effect of the ability.

Called at animation's Cast Point.
```
void OnCast(vec3 position, vec3 direction, Unit unit)
```
May have different variants:
- `nil, nil, nil` = No Target
- `position, nil, nil` = Point / AoE Target
- `nil, direction, nil` = Direction Target
- `position, direction, nil` = Vector Target
- `position, nil, unit` = Unit Target
- `position, direction, unit` = Unit Vector Target

### Cast
Perform cast of the ability without animation but still consume resources.

To still perform animation, use [`PerformCast(vec3, vec3, Unit)`](#perform-cast)
```
void Cast()
void Cast(vec3 position)
void Cast(vec3 position, vec3 direction)
void Cast(vec3 position, vec3 direction, Unit unit)
```
Implemented as:
```lua
function Ability:Cast(position, direction, unit)
    self:ConsumeResources(true, true, true);
    self:OnCast(position, direction, unit)
end
```

### Perform Cast
Perform cast of the ability with animation and consume resources.

To not perform animation, use [`Cast(vec3, vec3, Unit)`](#cast)
```
void PerformCast(vec3 position, vec3 direction, Unit unit)
```
Implemented as:
```lua
function Ability:PerformCast(position, direction, unit)
    
    -- Start Animation
    
    -- At Cast Point
    self:Cast(position, direction, unit)
end
```

### Get Cast Point
Get time (in seconds) afte start of animation at which this ability should be cast.
```
float GetCastPoint()
float GetCastPoint(int level)
```
Implemented as:
```lua
function Ability:GetChannelTime(level)
    return self:GetValue("CastPoint", level or self:GetLevel()) or 0
end
```

### Get Channel Time
Get channel time for the ability.
```
float GetChannelTime()
float GetChannelTime(int level)
```
Implemented as:
```lua
function Ability:GetChannelTime(level)
    return self:GetValue("ChannelTime", level or self:GetLevel()) or 0
end
```

### Is Channel
Utility function for channel abilities.
Simple check of [`GetChannelTime()`](#get-channel-time) being `= 0`.
```
bool IsChannel()
bool IsChannel(int level)
```
Implemented as:
```lua
function Ability:IsChannel(level)
    return self:GetChannelTime(level) == 0
end
```

### Get Animation
Get name of animation for this ability.
If `nil` (or empty string) is returned, animation for this slot is used.
```
string GetAnimation()
```

### Get Base Cooldown
Get cooldown time for specified level of the ability.
The `level` parameter is same as `GetLevel()` at start of the ability (should not change anyway during cast).

Value for `level = 0` is not defined and should not be called at any time (no cooldown required when the ability is not learned).

Should not count with Cooldown Reduction because (in base implementation) is called from [`GetCooldown()`](#get-cooldown) where is modified by Cooldown Reduction.
```
float GetBaseCooldown(int level)
```
Implemented as:
```lua
function Ability:GetBaseCooldown(level)
    return self:GetValue("Cooldown", level or self:GetLevel()) or 0
end
```

### Get Cooldown
Get cooldown time for specified level of the ability after Cooldown Reduction.
The `level` parameter is same as `GetLevel()` at start of the ability (should not change anyway during cast).

Value for `level = 0` is not defined and should not be called at any time (no cooldown required when the ability is not learned).

Base implementation counts with Cooldown Reduction.
For custom implementation, don't forget to count with Cooldown Reduction or use [`GetBaseCooldown`](#get-base-cooldown).
```
float GetCooldown(int level)
```
Implemented as:
```lua
function Ability:GetCooldown(level)
    return self:GetOwner():GetCooldown(self:GetBaseCooldown(level))
end
```

### Get Current Cooldown (Elapsed)
Get elapsed time of cooldown.

**Should not be overloaded.** (no effect on C++ code)
```
float GetCurrentCooldownElapsed()
```
Implemented as:
```lua
function Ability:GetCurrentCooldownElapsed()
    return self:GetCooldown() - self:GetCurrentCooldownRemaining()
end
```

### Get Current Cooldown (Remaining)
Get remaining time of the cooldown.

To change this value, use [`StartCooldown(float)`](#start-cooldown).

**Should not be overloaded.** (no effect on C++ code)
```
float GetCurrentCooldownRemaining()
```

### Get Current Cooldown Percentage
Utility function to convert (current) absolute cooldown values into percentage.

**Should not be overloaded.** (no effect on C++ code)
```
float GetCurrentCooldownPercentage(int level)
```
Implemented as:
```lua
function Ability:GetCurrentCooldownPercentage(level)
    local max = self:GetCooldown(level)
    local value = self:GetCurrentCooldown() / max
    if value < 0 then
        return 0
    end
    if value > 1 then
        return 100
    end
    return value * 100
end
```
```lua
function Ability:GetCurrentCooldownPercentage(level)
    local max = self:GetCooldown(level)
    local value = self:GetCurrentCooldown() / max
    return clamp(value * 100, 0, 100)
end
```

### Start Cooldown
This function forces the ability to go on specified cooldown.

Value can be above [`GetCooldown()`](#get-cooldown) but will be displayed as `100%` of the ability's cooldown (cannot go `>100%` visually).
Displayed numeric value is affected by [`GetCurrentCooldownRemaining()`](#get-current-cooldown-remaining) which can be above [`GetCooldown()`](#get-cooldown) (for case of level-up of change in Cooldown Reduction). 

**Should not be overloaded.** (no effect on C++ code)
```
void StartCooldown(float cooldown)
```

### Get Base Manacost

```
int GetBaseManacost(int level)
```
Implemented as:
```lua
function Ability:GetBaseManacost(level)
    return self:GetValue("Manacost", level or self:GetLevel()) or 0
end
```

### Get Manacost

```
int GetManacost(int level)
```
Implemented as:
```lua
function Ability:GetManacost(level)
    return self:GetOwner():GetManacost(self:GetBaseManacost(level))
end
```

### Get Base Goldcost

```
int GetBaseGoldcost(int level)
```
Implemented as:
```lua
function Ability:GetBaseGoldcost(level)
    return self:GetValue("Goldcost", level or self:GetLevel()) or 0
end
```

### Get Goldcost

```
int GetGoldcost(int level)
```
Implemented as:
```lua
function Ability:GetGoldcost(level)
    return self:GetOwner():GetGoldcost(self:GetGoldcost(level))
end
```

### Consume Resources

**Should not be overloaded.** (no effect on C++ code)
```
void ConsumeResources(bool cooldown, bool mana, bool gold)
```
Implemented as:
```lua
function Ability:ConsumeResources(cooldown, mana, gold)
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
end
```

### Get Owner

**Should not be overloaded.** (no effect on C++ code)
```
handle GetOwner()
```

### Get Original Owner

**Should not be overloaded.** (no effect on C++ code)
```
handle GetOriginalOwner()
```

### Is Stolen

**Should not be overloaded.** (no effect on C++ code)
```
bool IsStolen()
```
Implemented as:
```lua
function Ability:IsStolen()
    local originalOwner = self:GetOriginalOwner()
    return originalOwner and originalOwner ~= self:GetOwner()
end
```

### Can Be Stolen

```
bool CanBeStolen()
```
Implemented as:
```lua
function Ability:CanBeStolen()
    return true
end
```

### Get Value
Get Ability's value for specified level.
To get raw data, use [`GetValueRaw(string)`](#get-value-raw). 

**Should not be overloaded.** (no effect on C++ code)
```
string GetValue(string key)
string GetValue(string key, int level)
```
Implemented as:
```lua
function Ability:GetValue(key, level)
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
end
```

### Get Value Raw


**Should not be overloaded.** (no effect on C++ code)
```
string GetValueRaw(string key)
```

### Set Value Raw


**Should not be overloaded.** (no effect on C++ code)
```
void SetValueRaw(string key, string value)
```

### Get Ability Base Damage

```
float GetAbilityBaseDamage(int level)
```
Implemented as:
```lua
function Ability:GetAbilityBaseDamage(level)
    return self:GetValue("Damage", level or self:GetLevel()) or 0
end
```

### Get Ability Damage

```
float GetAbilityDamage(int level)
```
Implemented as:
```lua
function Ability:GetAbilityDamage(level)
    return self:GetOwner():GetTotalDamageIncreasedBySpellAmplification(self:GetBaseAbilityDamage(level))
end
```

### Get Ability Damage Type

```
DamageType GetAbilityDamageType(int level)
```
Implemented as:
```lua
function Ability:GetAbilityDamageType(level)
    return self:GetValue("DamageType", level or self:GetLevel()) or 0
end
```

### Get Ability Damage Flags

```
DamageFlags GetAbilityDamageFlags(int level)
```
Implemented as:
```lua
function Ability:GetAbilityDamageFlags(level)
    return self:GetValue("DamageFlags", level or self:GetLevel()) or 0
end
```

### Get Ability Target Team

```
Team_Flags GetAbilityTargetTeam(int level)
```
Implemented as:
```lua
function Ability:GetAbilityTargetTeam(level)
    return self:GetValue("TargetTean", level or self:GetLevel()) or 0
end
```

### Get Ability Target Type

```
TypeFilter GetAbilityTargetType(int level)
```
Implemented as:
```lua
function Ability:GetAbilityTargetTtype(level)
    return self:GetValue("TargetType", level or self:GetLevel()) or 0
end
```

### Get Ability Target Flags

```
FlagFilter GetAbilityTargetFlags(int level)
```
Implemented as:
```lua
function Ability:GetAbilityTargetFlags(level)
    return self:GetValue("TargetFlags", level or self:GetLevel()) or 0
end
```

### Get Ability Targeting

```
AbilityTargetting GetAbilityTargetting(int level)
```
Implemented as:
```lua
function Ability:GetAbilityTargetting(level)
    return self:GetValue("Targetting", level or self:GetLevel()) or 0
end
```

### Get Ability Base Cast Range
Maximum radius to cast a spell. 

Not affecter by owner's Cast Range Increase.
Affected version is [`GetAbilityCastRange(int)`](#get-ability-cast-range).
```
Team_Flags GetAbilityBaseCastRange(int level)
```
Implemented as:
```lua
function Ability:GetAbilityBaseCastRange(level)
    return self:GetValue("CastRange", level or self:GetLevel()) or 0
end
```

### Get Ability Cast Range
Maximum radius to cast a spell. 

Affected by owner's Cast Range Increase.
Not affected version is [`GetAbilityBaseCastRange(int)`](#get-ability-base-cast-range).
```
Team_Flags GetAbilityCastRange(int level)
```
Implemented as:
```lua
function Ability:GetAbilityCastRange(level)
    return self:GetOwner():GetTotalCastRange(self:GetAbilityBaseCastRange(level))
end
```

### Get Ability Base Radius
Radius of effect for AoE spells and auras.

Not affected by owner's Radius Increase.
Affected version is [`GetAbilityRadius(int)`](#get-ability-radius).
```
Team_Flags GetAbilityBaseRadius(int level)
```
Implemented as:
```lua
function Ability:GetAbilityBaseRadius(level)
    return self:GetValue("Radius", level or self:GetLevel()) or 0
end
```

### Get Ability Radius
Radius of effect for AoE spells and auras.

Affected by owner's Radius Increase.
Not affected version is [`GetAbilityBaseRadius(int)`](#get-ability-base-radius).
```
Team_Flags GetAbilityRadius(int level)
```
Implemented as:
```lua
function Ability:GetAbilityRadius(level)
    return self:GetOwner():GetTotalCastRadius(self:GetAbilityBaseRadius(level))
end
```