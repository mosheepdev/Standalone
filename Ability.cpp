#include <stdexcept>

#include "Ability.h"

bool Ability::Upgrade()
{
    throw std::logic_error("Not Implemented");
}

void Ability::OnCast(vec3 position, vec3 direction, Unit unit)
{
    throw std::logic_error("Not Implemented");
}

void Ability::Cast(vec3 position, vec3 direction, Unit unit)
{
    throw std::logic_error("Not Implemented");
}

void Ability::PerformCast(vec3 position, vec3 direction, Unit unit)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetCooldown(int level)
{
    throw std::logic_error("Not Implemented");
}

void Ability::StartCooldown(float cooldown)
{
    throw std::logic_error("Not Implemented");
}

int Ability::GetManacost(int level)
{
    throw std::logic_error("Not Implemented - Connect to LUA");
}

int Ability::GetGoldcost(int level)
{
    throw std::logic_error("Not Implemented - Connect to LUA");
}

void Ability::ConsumeResources(bool cooldown, bool mana, bool gold)
{
    // Cooldown
    StartCooldown(cooldown);

    // Mana
    throw std::logic_error("Not Implemented");

    // Gold
    throw std::logic_error("Not Implemented");
}

bool Ability::CanBeStolen()
{
    throw std::logic_error("Not Implemented - Connect to LUA");
}

string Ability::GetValue_String(string key, int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityDamage(int level)
{
    throw std::logic_error("Not Implemented");
}

DamageType Ability::GetAbilityDamageType(int level)
{
    throw std::logic_error("Not Implemented");
}

DamageFlags Ability::GetAbilityDamageFlags(int level)
{
    throw std::logic_error("Not Implemented");
}

Team_Flags Ability::GetAbilityTargetTeam(int level)
{
    throw std::logic_error("Not Implemented");
}

TypeFilter Ability::GetAbilityTargetType(int level)
{
    throw std::logic_error("Not Implemented");
}

FlagFilter Ability::GetAbilityTargetFlags(int level)
{
    throw std::logic_error("Not Implemented");
}

AbilityTargetting Ability::GetAbilityTargetting(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityRange(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityRadius(int level)
{
    throw std::logic_error("Not Implemented");
}