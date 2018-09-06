#include <stdexcept>
#include "Unit.h"

Unit::Unit()
{
    _UnitId = _NextUnitId++;
}

int Unit::_NextUnitId = 1;

//-----------------------------------------------------------------

float Unit::GetPercentageBonusXp()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusXp() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetFlatBonusDamage()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusDamage();
    return bonus;
}

float Unit::GetPercentageBonusDamage()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetFlatBonusDamage() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetBonusStrengthAttribute()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusStrength();
    return bonus;
}

int Unit::GetBonusAgilityAttribute()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusAgility();
    return bonus;
}

int Unit::GetBonusIntelligenceAttribute()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusIntelligence();
    return bonus;
}

int Unit::GetBonusCharismaAttribute()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusCharisma();
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetFlatBonusHealthPool()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusHealth();
    return bonus;
}

float Unit::GetPercentageBonusHealthPool()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusHealth() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusHealthRegeneration()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    float bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusHealthRegeneration();
    return bonus;
}

float Unit::GetBonusPercentageHealthRegeneration()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusHealthRegeneration() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetFlatBonusManaPool()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusMana();
    return bonus;
}

float Unit::GetPercentageBonusManaPool()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusMana() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusManaRegeneration()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    float bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusManaRegeneration();
    return bonus;
}

float Unit::GetBonusPercentageManaRegeneration()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusManaRegeneration() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetBonusArmor()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 0;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusArmor();
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusMagicResistance()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetBonusMagicResistance() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusStatusResistance()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus = 1 - ((100 - bonus) * (100 - modifiers[i]->GetBonusStatusResistance()) / 100.0f);
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusCooldownReduction()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus = 1 - ((100 - bonus) * (100 - modifiers[i]->GetBonusCooldownReduction()) / 100.0f);
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusManacostReduction()
{
throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

float Unit::GetBonusGoldcostReduction()
{
throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

float Unit::GetBonusSpellAmplification()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

int Unit::GetBonusCastRangeIncrease()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusCastRange();
    return bonus;
}

float Unit::GetBonusCastRadiusPercentage()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusCastRange() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetBonusMovementSpeedIncrease()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusMovementSpeed();
    return bonus;
}

float Unit::GetBonusMovementSpeedPercentage()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusMovementSpeed() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

int Unit::GetBonusAttackSpeed()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetFlatBonusAttackSpeed();
    return bonus;
}

float Unit::GetBonusAttackSpeedPercentage()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    float bonus = 100;
    for(int i = 0; i < modifierCount; i++)
        bonus *= modifiers[i]->GetPercentageBonusAttackSpeed() / 100.0f;
    return bonus;
}

//-----------------------------------------------------------------

float Unit::GetBonusAttackTime()
{
throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

int Unit::GetBonusAttackRange()
{
    int modifierCount = 0;
    Modifier** modifiers = GetAllModifiers(&modifierCount);
    if(modifierCount == 0)
        return 100;

    int bonus = 0;
    for(int i = 0; i < modifierCount; i++)
        bonus += modifiers[i]->GetBonusAttackRange();
    return bonus;
}

//-----------------------------------------------------------------

AttackType Unit::GetAttackType()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------
