#ifndef STANDALONE_MODIFIER_H
#define STANDALONE_MODIFIER_H

class Modifier;

#include "Enums.h"
#include "Unit.h"

class Modifier {
public:
    int GetFlags();
    ModifierPriority GetPriority();
    Unit GetParent();
    Ability GetAbility();

// Damage
public:
    int GetFlatBonusDamage();
    float GetPercentageBonusDamage(); // + 100

// Attributes
public:
    int GetBonusStrength();
    int GetBonusAgility();
    int GetBonusIntelligence();
    int GetBonusCharisma();

// Health
public:
    int GetFlatHealthBonus();
    float GetPercentageHealthBonus();

// Health Regen
public:
    float GetFlatBonusHealthRegeneration();
    float GetPercentageBonusHealthRegeneration();

// Mana
public:
    int GetFlatManaBonus();
    float GetPercentageManaBonus();

// Mana Regen
public:
    float GetFlatBonusManaRegeneration();
    float GetPercentageBonusManaRegeneration();

// Armor (Physical Resist)
public:
    float GetBonusArmor();

// Magic Resistance
public:
    float GetBonusMagicResistance();

// Status Resistance
public:
    float GetBonusStatusResistance();

// Cooldown Reduction
public:
    float GetBonusCooldownReduction();

// Cast Range
public:
    float GetFlatBonusCastRange();
    float GetPercentageBonusCastRange();

// Movement Speed
public:
    float GetFlatBonusMovementSpeed();
    float GetPercentageBonusMovementSpeed();

// Attack Speed
public:
    float GetFlatBonusAttackSpeed();
    float GetPercentageBonusAttackSpeed();

// Attack Range
public:
    int GetBonusAttackRange();

// Attack Projectile
public:
    char* GetProjectileParticle();

// XP / Experience
public:
    float GetPercentageBonusXp();

// Gold
public:
    float GetPercentageBonusGold();
};


#endif //STANDALONE_MODIFIER_H
