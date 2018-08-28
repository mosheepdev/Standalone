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
Used for adding the ability to [Unit](../Unit/), referencing it or translations.

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
Utility function which checks [`GetLevel()`](#Get_Level) for being `> 0`.

**Should not be overloaded.** (no effect on C++ code)
```
bool IsLearned()
```

### Upgrade
Perform upgrade of this ability.
Does not spend ability point.

Returns `true` on success.

To run code on upgrade, override [`OnUpgrade()`](#On_Upgrade). To determine whenever to show GUI selection, override [`CanBeUpgraded()`](#Can_Be_Upgraded).

**Should not be overloaded.** (no effect on C++ code)
```
bool Upgrade()
```

### On Upgrade
Called from [`Upgrade()`](#Upgrade) to allow custom code on ability upgrade.

Return `false` to prevent the ability to be upgraded.
```
bool OnUpgrade()
```

### Can Be Upgraded
Determine whenever to show GUI to allow upgrade of this ability.

Without `true` from this, `Upgrade()` will have no way to be called from player. Does not prevent `Upgrade()` to be called from code.
```
bool CanBeUpgraded()
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

To still perform animation, use [`PerformCast(vec3, vec3, Unit)`](#Perform_Cast)
```
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

To not perform animation, use [`Cast(vec3, vec3, Unit)`](#Cast)
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

### Get Base Cooldown
Get cooldown time for specified level of the ability.
The `level` parameter is same as `GetLevel()` at start of the ability (should not change anyway during cast).

Value for `level = 0` is not defined and should not be called at any time (no cooldown required when the ability is not learned).

Should not count with Cooldown Reduction because (in base implementation) is called from [`GetCooldown()`](#Get_Cooldown) where is modified by Cooldown Reduction.
```
float GetBaseCooldown(int level)
```

### Get Cooldown
Get cooldown time for specified level of the ability after Cooldown Reduction.
The `level` parameter is same as `GetLevel()` at start of the ability (should not change anyway during cast).

Value for `level = 0` is not defined and should not be called at any time (no cooldown required when the ability is not learned).

Base implementation counts with Cooldown Reduction.
For custom implementation, don't forget to count with Cooldown Reduction or use [`GetBaseCooldown`](#Get_Base_Cooldown).
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
    return self:GetCooldown(self:GetLevel()) - self:GetCurrentCooldownRemaining()
end
```

### Get Current Cooldown (Remaining)
Get remaining time of the cooldown.

To change this value, use [`StartCooldown(float)`](#Start_Cooldown).

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

Value can be above [`GetCooldown()`](#Get_Cooldown) but will be displayed as `100%` of the ability's cooldown (cannot go `>100%` visually).
Displayed numeric value is affected by [`GetCurrentCooldownRemaining()`](#Get_Current_Cooldown_Remaining) which can be above [`GetCooldown()`](#Get_Cooldown) (for case of level-up of change in Cooldown Reduction). 

**Should not be overloaded.** (no effect on C++ code)
```
void StartCooldown(float cooldown)
```

### Get Base Manacost

```
int GetBaseManacost(int level)
```

### Get Manacost

```
int GetManacost(int level)
```
Implemented as:
```lua
function Ability:GetManacost()
    return self:GetOwner():GetManacost(self:GetBaseManacost(level))
end
```

### Get Base Goldcost

```
int GetBaseGoldcost(int level)
```

### Get Goldcost

```
int GetGoldcost(int level)
```
Implemented as:
```lua
function Ability:GetGoldcost()
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
        if player ~= nil then
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
    return originalOwner ~= nil and GetOwner() ~= originalOwner
end
```

### Can Be Stolen

```
bool CanBeStolen()
```