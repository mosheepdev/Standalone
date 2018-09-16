# First Ability

## Files

First of all, you need to have your files in place.
Create those files in your Game Mode directory.
```
/KeyValue/Ability/Generic/Magic_Missile.kv
/Script/Ability/Generic/Magic_Missile.lua
```

Your icon should be located at:
```
/Icon/Ability/Generic/Magic_Missile.png
```

## KeyValue File

Those `.kv` (`.txt` work too) files store values for the ability.

We need right scope for data of the ability.
The scope is `Ability`.`<ability_name>`.
Scope is same for all abilities (generic, hero...) which means all ability names should be unique (and cannot contain `.` character).
```
"Ability"
{
    "Magic_Missile"
    {
        
    }
}
```

First specified information should be location of LUA file.

This path is relative to `/Scripts/` folder.
```
        "Script_File"                   "Ability/Generic/Magic_Missile.lua"
```

Next defined are levels.

Default values are:
```
        "Max_Level"                     "1"
        "Levels"
        {
            "1"                         "0"
        }
```
Those values specify that this ability has only 1 level and can be leveled at any time (no level requirement).

For this ability, let's change them to:
```
        "Max_Level"                     "6"
        "Levels"
        {
            "1"                         "1"
            "2"                         "3"
            "3"                         "5"
            "4"                         "9"
            "5"                         "15"
            "6"                         "23"
        }
```
Those are default values for all Normal Hero Abilities.

Next are values which are required for all active abilities but are handled by default:
```
        "Manacost"                  "90 100 110 120 135 150"
        "Cooldown"                  "13"
        "Cast_Point"                "0.16"
        "Cast_Range"                "500"
```
Those values are split by ` ` (empty space) to columns.
When retrieving, column equivalent to Ability's current level (or last, which is lower).

Followed by ability-specific values which will be handled in the `"Script_File"`.
```
        "Damage"                    "100 120 140 170 200 250"
        "Damage_Type"               "DAMAGE_TYPE_MAGIC"
        "Stun"                      "0.5 0.7 0.9 1.1 1.3 1.5"
``` 

Whole KeyValue file is:
```
"Ability"
{
    "Magic_Missile"
    {
        "Script_File"                   "Ability/Generic/Magic_Missile.lua"
        
        "Max_Level"                     "6"
        "Levels"
        {
            "1"                         "1"
            "2"                         "3"
            "3"                         "5"
            "4"                         "9"
            "5"                         "15"
            "6"                         "23"
        }

        "Manacost"                      "90 100 110 120 135 150"
        "Cooldown"                      "13"
        "Cast_Point"                    "0.16"
        "Cast_Range"                    "500"
        
        "Damage"                        "100 120 140 170 200 250"
        "Damage_Type"                   "DAMAGE_TYPE_MAGIC"
        "Stun"                          "0.5 0.7 0.9 1.1 1.3 1.5"
    }
}
```

## Script File

Scripts are `.lua` code files.

First of all, we need "header" of the ability.
This allows the ability to register its functions.

Some IDEs may say `Unused Assignment` (in [CLion](https://www.jetbrains.com/clion/)) but it is right.
You should not call anything on this variable.
```lua
local ability = Ability("Magic_Missile")
```

Next is function which triggers on cast (after `Cast Point` and consuming Mana and Cooldown).

To this function, we will add the damage and stun effect.
```lua
function ability:OnCast(position, direction, unit)
    -- Place code here
end
```

Before actually doing anything, let's retrieve some values. 
```lua
    local damage = self:GetValue("Damage")
    local damageType = self:GetValue("Damage_Type")
    local stunDuration = self:GetValue("Stun")
```
`damage` and `stunDuration` are numeric values while `damageType` is text because we used [Enum](../../Lua_Api/Enums/README.md) value `DAMAGE_TYPE_MAGIC`.
Do not care about this because we will use it in `Unit:TakeDamage(...)` which takes type of `DamageType` which is special type represented by the [Enum](../../Lua_Api/Enums/README.md) value.


Deal damage to the target:
```lua
    unit:TakeDamage(damage, damageType, self:GetOwner(), self)
```

And apply `Stun` modifier:
```lua
    local stunModifier = unit:AddNewModifier("Stun", self:GetOwner(), self)
    stunModifier.duration = stunDuration
```
Adding `self:GetOwner()` for `sourceUnit` has no effect for us (will be displayed in Log and Kill Info) but `self` for `sourceAbility` will allow the modifier to share same icon.

It is common to deal damage first and then apply effects (modifiers).

To have the code right, we should trigger Spell Block because this is Single-Target ability.
```lua
    -- Trigger Spell Block
    if unit:TriggerSpellBlock(self) then
        return
    end
```

Whole LUA file is:
```lua
local ability = Ability("Magic_Missile")

function ability:OnCast(position, direction, unit)
    -- Trigger Spell Block
    if unit:TriggerSpellBlock(self) then
        return
    end
    
    -- Get Ability Values
    local damage = self:GetValue("Damage")
    local damageType = self:GetValue("Damage_Type", "DamageType")
    local stunDuration = self:GetValue("Stun")
    
    -- Deal damage
    unit:TakeDamage(damage, damageType, self:GetOwner(), self)
    
    -- Apply stun
    local stunModifier = unit:AddNewModifier("Stun", self:GetOwner(), self)
    stunModifier.duration = stunDuration
end
```

## Missile Projectile

Because this ability has "Missile" in its name, we should use projectile instead of instant-hit.

First, we should define the projectile particle.
That is done by adding those lines into `.kv` file.
```
        "Precache"
        {
            "Particle"                  "Ability/Generic/Magic_Missile.particle"
        }
```
This will load the projectile particle into memory when this ability is used ("precaches the particle").

Then change `ability:OnCast(...)` to send the projectile.
```lua
    -- Send projectile
    ProjectileManager.CreateProjectile(unit, function(data, target)
        if not target then
            return -- Did not hit the target = disjoined
        end
    
        -- Place on-hit code here
    end, {
        canBeDisjoined=true,
        particle={
            path="Ability/Generic/Magic_Missile.particle"
        }
    })
```
3rd parameter of `ProjectileManager.CreateProjectile(...)` is `additionalData`.

For Linear Projectile, `target` is same as `unit` we passed to it.

And when the projectile hits, do the original code.

Whole files are:

`Magic_Missile.kv`
```
"Ability"
{
    "Magic_Missile"
    {
        "Script_File"                   "Ability/Generic/Magic_Missile.lua"
        
        "Max_Level"                     "6"
        "Levels"
        {
            "1"                         "1"
            "2"                         "3"
            "3"                         "5"
            "4"                         "9"
            "5"                         "15"
            "6"                         "23"
        }

        "Manacost"                      "90 100 110 120 135 150"
        "Cooldown"                      "13"
        "Cast_Point"                    "0.16"
        "Cast_Range"                    "500"
        
        "Damage"                        "100 120 140 170 200 250"
        "Damage_Type"                   "DAMAGE_TYPE_MAGIC"
        "Stun"                          "0.5 0.7 0.9 1.1 1.3 1.5"
        
        "Precache"
        {
            "Particle"                  "Ability/Generic/Magic_Missile.particle"
        }
    }
}
```

`Magic_Missile.lua`
```lua
local ability = Ability("Magic_Missile")

function ability:OnCast(position, direction, unit)
    -- Send projectile
    ProjectileManager.CreateProjectile(unit, function(data, target)
        if not target then
            return -- Did not hit the target = disjoined
        end
    
        -- Trigger Spell Block
        if target:TriggerSpellBlock(self) then
            return
        end
        
        -- Get Ability Values
        local damage = self:GetValue("Damage")
        local damageType = self:GetValue("Damage_Type")
        local stunDuration = self:GetValue("Stun")
        
        -- Deal damage
        target:TakeDamage(damage, damageType, self:GetOwner(), self)
        
        -- Apply stun
        local stunModifier = target:AddNewModifier("Stun", self:GetOwner(), self)
        stunModifier.duration = stunDuration
    end, {
        canBeDisjoined=true,
        particle={
            path="Ability/Generic/Magic_Missile.particle"
        }
    })
end
```

## Homework

This is just an ability prototype.

To make this whole ability, you need:
- Not affect Magic-Immune units
  - Make it configurable in the `.kv` file
  - Use `self:GetValue("Pierce_Spell_Immunity", "Boolean")`
- Move `canBeDisjoined` and `particle.path` to `.kv` file
  - Change `particle.path` based on ability level
