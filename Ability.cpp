#include <stdexcept>

#include "Ability.h"

bool Ability::Upgrade()
{
    throw std::logic_error("Not Implemented");
}

bool Ability::OnUpgrade()
{
    throw std::logic_error("Not Implemented");
}

bool Ability::CanBeUpgraded()
{
    throw std::logic_error("Not Implemented");
}

string Ability::GetTexture(int level)
{
    throw std::logic_error("Not Implemented");
}

bool Ability::CanBeCast(vec3 position, vec3 direction, Unit unit)
{
    throw std::logic_error("Not Implemented");
}

string Ability::GetCastError(vec3 position, vec3 direction, Unit unit)
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

float Ability::GetCastPoint(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetChannelTime(int level)
{
    throw std::logic_error("Not Implemented");
}

bool Ability::IsChannel(int level)
{
    throw std::logic_error("Not Implemented");
}

string Ability::GetAnimation(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetBaseCooldown(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetCooldown(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetCurrentCooldownElapsed()
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetCurrentCooldownRemaining()
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetCurrentCooldownPercentage()
{
    throw std::logic_error("Not Implemented");
}

void Ability::StartCooldown(float cooldown)
{
    throw std::logic_error("Not Implemented");
}

int Ability::GetBaseManacost(int level)
{
    throw std::logic_error("Not Implemented - Connect to LUA");
}

int Ability::GetManacost(int level)
{
    throw std::logic_error("Not Implemented - Connect to LUA");
}

int Ability::GetBaseGoldcost(int level)
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

float Ability::GetAbilityBaseDamage(int level)
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

AbilityTargeting Ability::GetAbilityTargeting(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityBaseRange(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityRange(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityBaseRadius(int level)
{
    throw std::logic_error("Not Implemented");
}

float Ability::GetAbilityRadius(int level)
{
    throw std::logic_error("Not Implemented");
}