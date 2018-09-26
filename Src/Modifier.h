#ifndef STANDALONE_MODIFIER_H
#define STANDALONE_MODIFIER_H

class Modifier;

#include "Enums.h"
#include "Unit.h"

class Modifier
{
public:
    virtual int GetFlags();

public:
    Unit GetParent();

    Ability GetAbility();

public:
    virtual ModifierPriority GetPriority();

    virtual PurgeType GetPurgeType();

    virtual bool IsDebuff();
    //TODO Duration

// XP / Experience
public:
    virtual float GetPercentageBonusXp();

// Damage
public:
    virtual int GetFlatBonusDamage();

    virtual float GetPercentageBonusDamage();

// Attributes
public:
    virtual int GetBonusStrength();

    virtual int GetBonusAgility();

    virtual int GetBonusIntelligence();

    virtual int GetBonusWill();

// Health
public:
    virtual int GetFlatBonusHealth();

    virtual float GetPercentageBonusHealth();

// Health Regen
public:
    virtual float GetFlatBonusHealthRegeneration();

    virtual float GetPercentageBonusHealthRegeneration();

// Mana
public:
    virtual int GetFlatBonusMana();

    virtual float GetPercentageBonusMana();

// Mana Regen
public:
    virtual float GetFlatBonusManaRegeneration();

    virtual float GetPercentageBonusManaRegeneration();

// Armor (Physical Resist)
public:
    virtual int GetBonusArmor();

// Magic Resistance
public:
    virtual float GetBonusMagicResistance();

// Status Resistance
public:
    virtual float GetBonusStatusResistance();

// Cooldown Reduction
public:
    virtual float GetBonusCooldownReduction();

// Cast Range
public:
    virtual float GetFlatBonusCastRange();

    virtual float GetPercentageBonusCastRange();

// Movement Speed
public:
    virtual float GetFlatBonusMovementSpeed();

    virtual float GetPercentageBonusMovementSpeed();

// Attack Speed
public:
    virtual float GetFlatBonusAttackSpeed();

    virtual float GetPercentageBonusAttackSpeed();

// Attack Range
public:
    virtual int GetBonusAttackRange();

// Attack Projectile
public:
    virtual char *GetProjectileParticle();

// Gold
public:
    virtual float GetPercentageBonusGold();
};


#endif //STANDALONE_MODIFIER_H
