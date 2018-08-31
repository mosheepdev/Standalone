#ifndef STANDALONE_UNIT_H
#define STANDALONE_UNIT_H

class Unit;

#include <glm/glm.hpp>
#include <cmath>


#include "Enums.h"
#include "Ability.h"

using namespace glm;

class Unit
{
public:
    Unit();

// Apply Config
public:
    //virtual void LoadConfig();//TODO

// Unit ID
public:
    int GetUnitId() { return _UnitId;}
private:
    int _UnitId;
    static int _NextUnitId;

// Position
public:
    vec3 GetPosition() { return _Position;  }
    vec3 GetAbsOrigin() { return GetPosition(); }
    void Teleport(vec2 position) { Teleport(vec3(position, 0.0)); }
    void Teleport(vec3 position);
private:
    vec3 _Position = vec3(0,0,0);

// Rotation


// Level
public:
    int GetMaxLevel() { return _MaxLevel; }
    void SetMaxLevel(int maxLevel);
    int GetXpPerLevel(int level)
    {
        if(level > _MaxLevel || level <= 0)
            return -1;
        return _ExperiencePerLevel[level - 1];
    }
    int GetXpPerLevelTotal(int level)
    {
        if(level <= 0)
            return -1;
        if(level > _MaxLevel)
            level = _MaxLevel;

        int totalXp = 0;
        for(int i = 0; i < level; i++)
            totalXp += _ExperiencePerLevel[i];
        return totalXp;
    }
    void SetXpPerLevel(int level, int xp);
private:
    int _MaxLevel = 0;
    int* _ExperiencePerLevel = nullptr;
public:
    int GetLevel() { return _Level; }
    void SetLevel(int level);
    float GetCurrentXp() { return _LevelXp; }
    float GetCurrentXpPercentage();
    float ClearCurrentXp();
    void SetCurrentXp(float xp)
    {
        ClearCurrentXp();
        AddXp(xp, false);
    }
    float GetXpToNextLevel();
    float GetTotalXp() { return GetXpPerLevelTotal(_Level) + _LevelXp; }
    void SetTotalXp(float xp);
    void SetTotalXp(float xp, bool affectedByModifiers);
    void AddXp(float xp);
    void AddXp(float xp, bool affectedByModifiers);
    float GetPercentageBonusXp();
    float GetXpAfterBonus(float xp) { return xp * (GetPercentageBonusXp() / 100.0f); }
private:
    int _Level = 1; // 1+
    float _LevelXp = 0;


// Damage
public:
    int GetOriginalMinDamage() { return _OriginalDamage_Min; }
    int GetOriginalMaxDamage() { return _OriginalDamage_Max; }
    int GetOriginalRealDamage()
    {
        int min = GetOriginalMinDamage();
        return min + (GetOriginalMaxDamage() - min) / 2;
    }
    void SetOriginalDamage(int min, int max);
    /*{
        _OriginalDamage_Min = min;
        _OriginalDamage_Max = max;
    }*/
private:
    int _OriginalDamage_Min = 0;
    int _OriginalDamage_Max = 0;
public:
    int GetAttributeDamage()
    {
        Attribute attr = GetMainAttribute();
        if (attr == ATTRIBUTE_STRENGTH)
            return GetTotalStrengthAttribute();
        if (attr == ATTRIBUTE_AGILITY)
            return GetTotalAgilityAttribute();
        if (attr == ATTRIBUTE_INTELLIGENCE)
            return GetTotalIntelligenceAttribute();
        if (attr == ATTRIBUTE_CHARISMA)
            return GetTotalCharismaAttribute();
        return 0;
    }
    int GetBaseMinDamage() { return GetOriginalMinDamage() + GetAttributeDamage(); }
    int GetBaseMaxDamage() { return GetOriginalMaxDamage() + GetAttributeDamage(); }
    int GetBaseRealDamage()
    {
        int min = GetBaseMinDamage();
        return min + (GetBaseMaxDamage() - min) / 2;
    }
    int GetFlatBonusDamage();
    float GetPercentageBonusDamage();
    int GetTotalBonusDamage() { return (int)(GetFlatBonusDamage() + GetBaseRealDamage() * (GetPercentageBonusDamage() / 100.0f)); }
    int GetTotalMinDamage() { return GetBaseMinDamage() + GetFlatBonusDamage(); }
    int GetTotalMaxDamage() { return GetBaseMaxDamage() + GetFlatBonusDamage(); }
    int GetTotalRealDamage()
    {
        int min = GetTotalMinDamage();
        return min + (GetTotalMaxDamage() - min) / 2;
    }

// Main Attributes
public:
    Attribute GetMainAttribute() { return _MainAttribute; }
    void SetMainAttribute(Attribute mainAttribute);
private:
    Attribute _MainAttribute = ATTRIBUTE_STRENGTH;

// Attribute - Strength
public:
    int GetOriginalStrengthAttribute() { return _OriginalStrengthAttribute; }
    void SetOriginalStrengthAttribute(int attribute);
private:
    int _OriginalStrengthAttribute = 0;
public:
    float GetStrengthAttributeGrow() { return _StrengthAttributeGrow; }
    void SetStrengthAttributeGrow(float attributeGrow);
private:
    float _StrengthAttributeGrow = 1.0;
public:
    int GetBaseStrengthAttribute() { return GetOriginalStrengthAttribute() + (int)( GetStrengthAttributeGrow() * GetLevel() ); }
    int GetBonusStrengthAttribute();
    int GetTotalStrengthAttribute() { return GetBaseStrengthAttribute() + GetBonusStrengthAttribute(); }

// Attribute - Agility
public:
    int GetOriginalAgilityAttribute() { return _OriginalAgilityAttribute; }
    void SetOriginalAgilityAttribute(int attribute);
private:
    int _OriginalAgilityAttribute = 0;
public:
    float GetAgilityAttributeGrow() { return _AgilityAttributeGrow; }
    void SetAgilityAttributeGrow(float attributeGrow);
private:
    float _AgilityAttributeGrow = 1.0;
public:
    int GetBaseAgilityAttribute() { return GetOriginalAgilityAttribute() + (int)( GetAgilityAttributeGrow() * GetLevel() ); }
    int GetBonusAgilityAttribute();
    int GetTotalAgilityAttribute() { return GetBaseAgilityAttribute() + GetBonusAgilityAttribute(); }

// Attribute - Intelligence
public:
    int GetOriginalIntelligenceAttribute() { return _OriginalIntelligenceAttribute; }
    void SetOriginalIntelligenceAttribute(int attribute);
private:
    int _OriginalIntelligenceAttribute = 0;
public:
    float GetIntelligenceAttributeGrow() { return _IntelligenceAttributeGrow; }
    void SetIntelligenceAttributeGrow(float attributeGrow);
private:
    float _IntelligenceAttributeGrow = 1.0;
public:
    int GetBaseIntelligenceAttribute() { return GetOriginalIntelligenceAttribute() + (int)( GetIntelligenceAttributeGrow() * GetLevel() ); }
    int GetBonusIntelligenceAttribute();
    int GetTotalIntelligenceAttribute() { return GetBaseIntelligenceAttribute() + GetBonusIntelligenceAttribute(); }

// Attribute - Charisma
public:
    int GetOriginalCharismaAttribute() { return _OriginalCharismaAttribute; }
    void SetOriginalCharismaAttribute(int attribute);
private:
    int _OriginalCharismaAttribute = 0;
public:
    float GetCharismaAttributeGrow() { return _CharismaAttributeGrow; }
    void SetCharismaAttributeGrow(float attributeGrow);
private:
    float _CharismaAttributeGrow = 1.0;
public:
    int GetBaseCharismaAttribute() { return GetOriginalCharismaAttribute() + (int)( GetCharismaAttributeGrow() * GetLevel() ); }
    int GetBonusCharismaAttribute();
    int GetTotalCharismaAttribute() { return GetBaseCharismaAttribute() + GetBonusCharismaAttribute(); }


// Health Pool
public:
    int GetOriginalHealthPool() { return _OriginalHealthPool; }
    void SetOriginalHealthPool(int baseHealth);
private:
    int _OriginalHealthPool = 200;
public:
    int GetAttributeHealthPool() { return (int)(GetHealthPoolPerStrength() * GetTotalStrengthAttribute()); }
    float GetHealthPoolPerStrength() { return _HealthPoolPerStrength; }
    void SetHealthPoolPerStrength(float healthPoolPerStrength);
private:
    float _HealthPoolPerStrength = 20;
public:
    int GetBaseHealthPool() { return GetOriginalHealthPool() + GetAttributeHealthPool(); }
    int GetFlatBonusHealthPool();
    float GetPercentageBonusHealthPool();
    int GetBonusHealthPool() { return GetFlatBonusHealthPool() + (int)(GetBaseHealthPool() * GetPercentageBonusHealthPool() / 100.0f); }
    int GetTotalHealthPool() { return GetBaseHealthPool() + GetBonusHealthPool(); }

// Health - Current
public:
    float GetCurrentHealth() { return _CurrentHealth; } //TODO count with change of health pool
    void SetCurrentHealth(float health);
private:
    float _CurrentHealth = GetTotalHealthPool();
public:
    float GetHealthPercentage() { return ((float)GetCurrentHealth()) / GetTotalHealthPool(); }
    void SetHealthPercentage(float percentage);

// Health Regeneration
public:
    float GetBaseHealthRegeneration() { return _BaseHealthRegeneration; }
    void SetBaseHealthRegeneration(float regeneration);
private:
    float _BaseHealthRegeneration = 1.0;
public:
    float GetBonusHealthRegeneration();
    float GetTotalHealthRegenerationWithoutAmplification() { return GetBaseHealthRegeneration() + GetBonusHealthRegeneration(); }

public:
    float GetAttributePercentageHealthRegeneration() { return (1-pow(1-_PercentageHealthRegenerationAmplificationPerStrength, (float)GetTotalStrengthAttribute())) * 100; }
    float GetPercentageHealthRegenerationPerStrength() { return _PercentageHealthRegenerationAmplificationPerStrength; }
    void SetPercentageHealthRegenerationAmplificationPerStrength(float percentageHealthRegenerationPerStrength);
private:
    float _PercentageHealthRegenerationAmplificationPerStrength = 0.80f; // 0.80%
public:
    float GetPercentageBonusHealthRegeneration();
    float GetPercentageTotalHealthRegeneration() { return GetPercentageBonusHealthRegeneration() + GetAttributePercentageHealthRegeneration(); }
public:
    float GetTotalHealthRegeneration() { return (GetPercentageTotalHealthRegeneration() / 100.0f + 1) * GetTotalHealthRegenerationWithoutAmplification(); }

// Damage
    inline void TakeDamage(float amount) { TakeDamage(amount, DAMAGE_PURE, nullptr); }
    inline void TakeDamage(float amount, DamageType type) { TakeDamage(amount, type, nullptr); }
    inline void TakeDamage(float amount, DamageType type, Unit* damager) { TakeDamage(amount, type, nullptr, nullptr); }
    void TakeDamage(float amount, DamageType type, Unit* damager, Ability* ability);

// Heal
    inline void Heal(float amount) { Heal(amount, nullptr); }
    inline void Heal(float amount, Unit* healer) { Heal(amount, nullptr, nullptr); }
    void Heal(float amount, Unit* healer, Ability* ability);

// Mana Pool
public:
    int GetOriginalManaPool() { return _OriginalManaPool; } //TODO count with change of mana pool
    void SetOriginalManaPool(int baseMana);
private:
    int _OriginalManaPool = 50;
public:
    int GetAttributeManaPool() { return (int)(GetManaPoolPerIntelligence() * GetTotalIntelligenceAttribute()); }
    float GetManaPoolPerIntelligence() { return _ManaPoolPerIntelligence; }
    void SetManaPoolPerIntelligence(float manaPoolPerIntelligence);
private:
    float _ManaPoolPerIntelligence = 15;
public:
    int GetBaseManaPool() { return GetOriginalManaPool() + GetAttributeManaPool(); }
    int GetFlatBonusManaPool();
    float GetPercentageBonusManaPool();
    int GetBonusManaPool() { return GetFlatBonusManaPool() + (int)(GetBaseManaPool() * GetPercentageBonusManaPool() / 100.0f); }
    int GetTotalManaPool() { return GetBaseManaPool() + GetBonusManaPool(); }

// Mana - Current
public:
    int GetCurrentMana() { return (int) _CurrentMana; }
    void SetCurrentMana(float health);
private:
    float _CurrentMana = GetTotalManaPool();
public:
    float GetManaPercentage() { return ((float)GetCurrentMana()) / GetTotalManaPool(); }
    void SetManaPercentage(float percentage);

// Mana Regeneration
public:
    float GetBaseManaRegeneration() { return _BaseManaRegeneration; }
    void SetBaseManaRegeneration(float regeneration);
private:
    float _BaseManaRegeneration = 1.0;
public:
    float GetBonusManaRegeneration();
    float GetTotalManaRegenerationWithoutAmplification() { return GetBaseManaRegeneration() + GetBonusManaRegeneration(); }

public:
    float GetAttributePercentageManaRegeneration() { return (1-pow(1-_PercentageManaRegenerationAmplificationPerIntelligence, (float)GetTotalIntelligenceAttribute())) * 100; }
    float GetPercentageManaRegenerationPerIntelligence() { return _PercentageManaRegenerationAmplificationPerIntelligence * 100; }
    void SetPercentageManaRegenerationAmplificationPerIntelligence(float percentageManaRegenerationPerIntelligence);
private:
    float _PercentageManaRegenerationAmplificationPerIntelligence = 2.00f; // 2.0%
public:
    float GetPercentageBonusManaRegeneration();
    float GetPercentageTotalManaRegeneration() { return GetPercentageBonusManaRegeneration() + GetAttributePercentageManaRegeneration(); }
public:
    float GetTotalManaRegeneration() { return (GetPercentageTotalManaRegeneration() / 100.0f + 1) * GetTotalManaRegenerationWithoutAmplification(); }

// All Damage Resistance
//TODO

// Armor + Physical Resistance
public:
    float GetOriginalArmor() { return _OriginalArmor; }
    void SetOriginalArmor(float armor); //{ _OriginalArmor = armor; }
private:
    float _OriginalArmor = 0;
public:
    float GetAttributeArmor() { return GetTotalAgilityAttribute() * _ArmorPerAgility; }
    float GetArmorPerAgility() { return _ArmorPerAgility; }
    void SetArmorPerAgility(float armorPerAgility); //{ _ArmorPerAgility = armorPerAgility; }
private:
    float _ArmorPerAgility = 0.20;
public:
    float GetBaseArmor() { return GetOriginalArmor() + GetAttributeArmor(); }
    float GetBonusArmor();
    float GetTotalArmor() { return GetBaseArmor() + GetBonusArmor(); }

public:
    float GetReceivedPhysicalDamageMultiplier()
    {
        float armor = GetTotalArmor();
        return 1 - (0.05f * armor / (1 + 0.05f * abs(armor)));
    }
    float GetPercentagePhysicalDamageResistance() { return (1 - GetReceivedPhysicalDamageMultiplier()) * 100; }
    float GetPhysicalDamageAfterReductionByResistance(float damage) { return damage * (1 - GetPercentagePhysicalDamageResistance()/100.0f); }//TODO all damage reduction

// Magic Resistance
public:
    float GetPercentageOriginalMagicResistance() { return _PercentageOriginalMagicResistance; }
    void SetPercentageOriginalMagicResistance(float magicResistance);
private:
    float _PercentageOriginalMagicResistance = 20.00; // 20%
public:
    float GetPercentageAttributeMagicResistance() { return (1-pow(1-_PercentageMagicResistancePerCharisma, (float)GetTotalCharismaAttribute())) * 100.0f; }
    float GetPercentageMagicResistancePerCharisma() { return _PercentageMagicResistancePerCharisma * 100; }
    void SetPercentageMagicResistancePerCharisma(float percentageMagicResistancePerCharisma);
private:
    float _PercentageMagicResistancePerCharisma = 0.20;// 0.20%
public:
    float GetPercentageBaseMagicResistance() { return (1 - ((1 - GetPercentageOriginalMagicResistance()/100.0f) * (1 - GetPercentageAttributeMagicResistance()/100.0f))) * 100.0f; }
    float GetPercentageBonusMagicResistance();
    float GetTotalPercentageMagicResistance() { return (1 - ((1 - GetPercentageBaseMagicResistance()/100.0f) * (1 - GetPercentageBonusMagicResistance()/100.0f))) * 100.0f; }
    float GetMagicDamageAfterReductionByResistance(float damage) { return damage * (1 - GetTotalPercentageMagicResistance()/100.0f); }//TODO all damage reduction

// Status Resistance
public:
    float GetOriginalStatusResistance() { return _OriginalStatusResistance; }
    void SetOriginalStatusResistance(float statusResistance);
private:
    float _OriginalStatusResistance = 0.00; // 0%
public:
    float GetAttributeStatusResistance() { return (1-pow(1-_StatusResistancePerStrength, (float)GetTotalStrengthAttribute())) * 100; }
    float GetStatusResistancePerStrength() { return _StatusResistancePerStrength * 100; }
    void SetStatusResistancePerStrength(float statusResistancePerStrength);
private:
    float _StatusResistancePerStrength = 0.10;// 0.10%
public:
    float GetBaseStatusResistance() { return 1 - ((1 - GetOriginalStatusResistance()) * (1 - GetAttributeStatusResistance())); }
    float GetBonusStatusResistance();
    float GetTotalStatusResistance() { return 1 - ((1 - GetBaseStatusResistance()) * (1 - GetBonusStatusResistance())); }
    float GetDurationReducedByStatusResistance(float duration) { return duration * (1 - GetTotalStatusResistance()/100.0f); }

// Cooldown Reduction
public:
    float GetPercentageOriginalCooldownReduction() { return _PercentageOriginalCooldownReduction; }
    void SetPercentageOriginalCooldownReduction(float percentageCooldownReduction);
private:
    float _PercentageOriginalCooldownReduction = 0; // 0.00%
public:
    float GetPercentageAttributeCooldownReduction() { return (1-pow(1-_PercentageCooldownReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetPercentageCooldownReductionPerCharisma() { return _PercentageCooldownReductionPerCharisma; }
    void SetPercentageCooldownReductionPerCharisma(float percentageCooldownReductionPerCharisma);
private:
    float _PercentageCooldownReductionPerCharisma = 0.10; // 0.10%
public:
    float GetPercentageBonusCooldownReduction();
    float GetTotalPercentageCooldownReduction() { return (1 - ((1 - GetPercentageOriginalCooldownReduction()/100.0f) * (1 - GetPercentageAttributeCooldownReduction()/100.0f) * (1 - GetPercentageBonusCooldownReduction()/100)))*100; }
    float GetCooldown(float cooldown) { return cooldown * (GetTotalPercentageCooldownReduction() / 100.0f); }

// Manacost Reduction
public:
    float GetPercentageOriginalManacostReduction() { return _PercentageOriginalManacostReduction; }
    void SetPercentageOriginalManacostReduction(float percentageManacostReduction);
private:
    float _PercentageOriginalManacostReduction = 0; // 0.00%
    /*
public:
    float GetPercentageAttributeManacostReduction() { return (1-pow(1-_PercentageManacostReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetPercentageManacostReductionPerCharisma() { return _PercentageManacostReductionPerCharisma; }
    void SetPercentageManacostReductionPerCharisma(float percentageManacostReductionPerCharisma);
private:
    float _PercentageManacostReductionPerCharisma = 0.00; // 0.10%
     */
public:
    float GetPercentageBonusManacostReduction();
    float GetTotalPercentageManacostReduction() { return (1 - ((1 - GetPercentageOriginalManacostReduction()/100.0f) /** (1 - GetPercentageAttributeManacostReduction()/100.0f)*/ * (1 - GetPercentageBonusManacostReduction()/100)))*100; }
    float GetManacost(float manacost) { return manacost * (GetTotalPercentageManacostReduction() / 100.0f); }

// Goldcost Reduction
public:
    float GetPercentageOriginalGoldcostReduction() { return _PercentageOriginalGoldcostReduction; }
    void SetPercentageOriginalGoldcostReduction(float percentageGoldcostReduction);
private:
    float _PercentageOriginalGoldcostReduction = 0; // 0.00%
    /*
public:
    float GetPercentageAttributeGoldcostReduction() { return (1-pow(1-_PercentageGoldcostReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetPercentageGoldcostReductionPerCharisma() { return _PercentageGoldcostReductionPerCharisma; }
    void SetPercentageGoldcostReductionPerCharisma(float percentageGoldcostReductionPerCharisma);
private:
    float _PercentageGoldcostReductionPerCharisma = 0.10; // 0.10%
     */
public:
    float GetPercentageBonusGoldcostReduction();
    float GetTotalPercentageGoldcostReduction() { return (1 - ((1 - GetPercentageOriginalGoldcostReduction()/100.0f) /** (1 - GetPercentageAttributeGoldcostReduction()/100.0f)*/ * (1 - GetPercentageBonusGoldcostReduction()/100)))*100; }
    float GetGoldcost(float goldcost) { return goldcost * (GetTotalPercentageGoldcostReduction() / 100.0f); }

// Cast Range Increase
public:
    float GetOriginalCastRangeIncrease() { return _OriginalCastRangeIncrease; }
    void SetOriginalCastRangeIncrease(float castRangeIncrease);
private:
    float _OriginalCastRangeIncrease = 0;
public:
    float GetAttributeCastRangeIncrease() { return GetAttributeCastRangeIncreasePerCharisma() * GetTotalCharismaAttribute(); }
    float GetAttributeCastRangeIncreasePerCharisma() { return _CastRangeIncreasePerCharisma; }
    void SetAttributeCastRangeIncreasePerCharisma(float castRangeIncreasePerCharisma) { _CastRangeIncreasePerCharisma = castRangeIncreasePerCharisma; }
private:
    float _CastRangeIncreasePerCharisma = 1;
public:
    float GetBaseCastRangeIncrease() { return GetOriginalCastRangeIncrease() + GetAttributeCastRangeIncrease(); }
    float GetBonusCastRangeIncrease();
    // Without amplification!!!
    float GetTotalCastRangeIncrease() { return GetBaseCastRangeIncrease() + GetBonusCastRangeIncrease(); }

// Cast Range Amplification
public:
    float GetBaseCastRangeAmplification() { return _BaseCastRangeAmplification; }
    void SetBaseCastRangeAmplification(float castRangeAmplification);
private:
    float _BaseCastRangeAmplification = 0;
public:
    float GetBonusCastRangeAmplification();
    // Without flat increase!!!
    float GetTotalCastRangeAmplification() { return GetBaseCastRangeAmplification() + GetBonusCastRangeAmplification(); }

// Cast Range
public:
    float GetTotalCastRange(float castRange) { return (castRange + GetTotalCastRangeIncrease()) * (1 + GetTotalCastRangeAmplification()); }

// Spell Amplification
public:
    float GetPercentageBaseSpellAmplification() { return _PercentageBaseSpellAmplification; }
    void SetPercentageBaseSpellAmplification(float percentageSpellAmplification);
private:
    float _PercentageBaseSpellAmplification = 1.0f;
public:
    float GetPercentageBonusSpellAmplification();
    float GetTotalPercentageSpellAmplification() { return GetPercentageBaseSpellAmplification() * GetPercentageBonusSpellAmplification() / 100.0f; }
    float GetTotalDamageIncreasedBySpellAmplification(float damage) { return damage * (GetTotalPercentageSpellAmplification() / 100.0f); }

// Ability Radius
public:
    float GetTotalRadius(float radius);

// Movement Speed Increase
//TODO

// Movement Speed Amplification
//TODO

// Movement Speed
//TODO

// Attack Speed
//TODO min/max attackspeed (clamp)
public:
    float GetOriginalAttackSpeed() { return _OriginalAttackSpeed; }
    void SetOriginalAttackSpeed(float attackSpeed);
private:
    float _OriginalAttackSpeed = 100;
public:
    float GetAttributeAttackSpeed() { return GetTotalAgilityAttribute() * GetAttributeAttackSpeedPerAgility(); }
    float GetAttributeAttackSpeedPerAgility() { return _AttackSpeedPerAgility; }
    void SetAttributeAttackSpeedPerAgility(float attackSpeedPerAgility);
private:
    float _AttackSpeedPerAgility = 1;
public:
    float GetBaseAttackSpeed() { return GetOriginalAttackSpeed() + GetAttributeAttackSpeed(); }
    float GetBonusAttackSpeed();
    float GetTotalAttackSpeedWithoutAmplification() { return GetBaseAttackSpeed() + GetBonusAttackSpeed(); }
    float GetTotalAttackSpeed() { return GetTotalAttackSpeedWithoutAmplification() * GetTotalAttackSpeedAmplification(); }
public:
    int GetMinAttackSpeedLimit() { return _MinAttackSpeed; }
    int GetMaxAttackSpeedLimit() { return _MaxAttackSpeed; }
    void SetAttackSpeedLimit(int min, int max);
private:
    int _MinAttackSpeed = 20;
    int _MaxAttackSpeed = 600;
public:
    float GetTotalAttackSpeedInLimits()
    {
        float attackSpeed = GetTotalAttackSpeed();
        if(attackSpeed < _MinAttackSpeed)
            return _MinAttackSpeed;
        if(attackSpeed > _MaxAttackSpeed)
            return _MaxAttackSpeed;
        return attackSpeed;
    }

// Attack Speed Amplification
public:
    float GetBaseAttackSpeedAmplification() { return _BaseAttackSpeedAmplification; }
    void SetBaseAttackSpeedAmplification(float attackSpeedAmplification);
private:
    float _BaseAttackSpeedAmplification = 1.0f;
public:
    float GetBonusAttackSpeedAmplification();
    float GetTotalAttackSpeedAmplification() { return GetBaseAttackSpeedAmplification() * GetBonusAttackSpeedAmplification(); }

// Attack Time
public:
    float GetBaseAttackTime() { return _BaseAttackTime; }
    void SetBaseAttackTime(float attackTime);
private:
    float _BaseAttackTime = 1.7;
public:
    float GetBonusAttackTime();
    float GetTotalAttackTimeWithoutAttackSpeed() { return GetBaseAttackTime() + GetBonusAttackTime(); }
    float GetTotalAttackTime() { return GetTotalAttackTimeWithoutAttackSpeed() / ( GetTotalAttackSpeedInLimits() / 100 ); }
    float GetAttacksPerSecond() { return 1 / GetTotalAttackTime(); }

// Attack Range
public:
    float GetBaseAttackRange() { return _BaseAttackRange; }
    void SetBaseAttackRange(float attackRange);
private:
    float _BaseAttackRange = 100;
public:
    float GetBonusAttackRange();
    float GetTotalAttackRange() { return GetBaseAttackRange() + GetBonusAttackRange(); }

// Inventory
//TODO

// Model Collision Size + Scale
//TODO

};


#endif //STANDALONE_UNIT_H
