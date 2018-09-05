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
    float GetCurrentHealthPercentage() { return ((float)GetCurrentHealth()) / GetTotalHealthPool(); }
    void SetCurrentHealthPercentage(float percentage);

// Health Regeneration
public:
    float GetBaseHealthRegeneration() { return _BaseHealthRegeneration; }
    void SetBaseHealthRegeneration(float regeneration);
private:
    float _BaseHealthRegeneration = 1.0;
public:
    float GetBonusHealthRegeneration();
    float GetFlatHealthRegeneration() { return GetBaseHealthRegeneration() + GetBonusHealthRegeneration(); } // WithoutAmplification

public:
    float GetAttributePercentageHealthRegeneration() { return (1-pow(1-_PercentageHealthRegenerationPerStrength, (float)GetTotalStrengthAttribute())) * 100; }
    float GetPercentageHealthRegenerationPerStrength() { return _PercentageHealthRegenerationPerStrength; }
    void SetPercentageHealthRegenerationPerStrength(float percentageHealthRegenerationPerStrength);
private:
    float _PercentageHealthRegenerationPerStrength = 0.80f; // 0.80%
public:
    float GetBonusPercentageHealthRegeneration();
    float GetPercentageTotalHealthRegeneration() { return GetBonusPercentageHealthRegeneration() + GetAttributePercentageHealthRegeneration(); }
public:
    float GetTotalHealthRegeneration() { return (GetPercentageTotalHealthRegeneration() / 100.0f) * GetFlatHealthRegeneration(); }

// Damage
    inline void TakeDamage(float amount) { TakeDamage(amount, DAMAGE_PURE); }
    inline void TakeDamage(float amount, DamageType type) { TakeDamage(amount, type, DAMAGE_FLAGS_NONE); }
    inline void TakeDamage(float amount, DamageType type, DamageFlags flags) { TakeDamage(amount, type, DAMAGE_FLAGS_NONE, nullptr); }
    inline void TakeDamage(float amount, DamageType type, DamageFlags flags, Unit* damager) { TakeDamage(amount, type, flags, nullptr, nullptr); }
    void TakeDamage(float amount, DamageType type, DamageFlags flags, Unit* damager, Ability* ability);

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
    float GetTotalManaRegeneration() { return (GetPercentageTotalManaRegeneration() / 100.0f) * GetTotalManaRegenerationWithoutAmplification(); }

// Mana Manipulation
public:
    void ConsumeMana(float amount);

// All Damage Resistance
public:
    float GetDamageAfterAllReduction(float damage);
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
    float GetPercentagePhysicalDamageResistance() { return (1 - GetReceivedPhysicalDamageMultiplier()) * 100.0; }
    float GetPhysicalDamageAfterReduction(float damage) { return damage * GetReceivedPhysicalDamageMultiplier(); } //{ return damage * (1 - GetPercentagePhysicalDamageResistance()/100.0f); }

// Magic Resistance
public:
    float GetOriginalMagicResistance() { return _OriginalMagicResistance; }
    void SetOriginalMagicResistance(float magicResistance);
private:
    float _OriginalMagicResistance = 20.00; // 20%
public:
    float GetAttributeMagicResistance() { return (1 - pow(1 - _MagicResistancePerCharisma, (float)GetTotalCharismaAttribute())) * 100.0f; }
    float GetMagicResistancePerCharisma() { return _MagicResistancePerCharisma * 100; }
    void SetMagicResistancePerCharisma(float percentageMagicResistancePerCharisma);
private:
    float _MagicResistancePerCharisma = 0.20;// 0.20%
public:
    float GetBaseMagicResistance() { return (1 - ((1 - GetOriginalMagicResistance()/100.0f) * (1 - GetAttributeMagicResistance()/100.0f))) * 100.0f; }
    float GetBonusMagicResistance();
    float GetTotalMagicResistance() { return (1 - ((1 - GetBaseMagicResistance()/100.0f) * (1 - GetBonusMagicResistance()/100.0f))) * 100.0f; }
    float GetMagicDamageAfterReduction(float damage) { return damage * (1 - GetTotalMagicResistance()/100.0f); }

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
    float GetDurationAfterStatusResistance(float duration) { return duration * (1 - GetTotalStatusResistance()/100.0f); }

// Cooldown Reduction
public:
    float GetOriginalCooldownReduction() { return _OriginalCooldownReduction; }
    void SetOriginalCooldownReduction(float percentageCooldownReduction);
private:
    float _OriginalCooldownReduction = 0; // 0.00%
public:
    float GetAttributeCooldownReduction() { return (1-pow(1-_CooldownReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetCooldownReductionPerCharisma() { return _CooldownReductionPerCharisma; }
    void SetCooldownReductionPerCharisma(float cooldownReductionPerCharisma);
private:
    float _CooldownReductionPerCharisma = 0.10; // 0.10%
public:
    float GetBaseCooldownReduction() { return (1 - ((1 - GetOriginalCooldownReduction()/100.0f) * (1 - GetAttributeCooldownReduction()/100.0f)))*100; }
    float GetBonusCooldownReduction();
    float GetTotalCooldownReduction() { return (1 - ((1 - GetBaseCooldownReduction()/100.0f) * (1 - GetBonusCooldownReduction()/100.0f)))*100; }
    float GetCooldown(float cooldown) { return cooldown * (GetTotalCooldownReduction() / 100.0f); }

// Manacost Reduction
public:
    float GetPercentageOriginalManacostReduction() { return _PercentageOriginalManacostReduction; }
    void SetPercentageOriginalManacostReduction(float manacostReduction);
private:
    float _PercentageOriginalManacostReduction = 0; // 0.00%
public:
    float GetPercentageAttributeManacostReduction() { return (1-pow(1-_PercentageManacostReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetPercentageManacostReductionPerCharisma() { return _PercentageManacostReductionPerCharisma; }
    void SetPercentageManacostReductionPerCharisma(float manacostReductionPerCharisma);
private:
    float _PercentageManacostReductionPerCharisma = 0.00;
public:
    float GetBasePercentageManacostReduction() { return (1 - ((1 - GetPercentageOriginalManacostReduction()/100.0f) * (1 - GetPercentageAttributeManacostReduction()/100.0f)))*100; }
    float GetBonusPercentageManacostReduction();
    float GetTotalPercentageManacostReduction() { return (1 - ((1 - GetBasePercentageManacostReduction()/100.0f) * (1 - GetBonusPercentageManacostReduction()/100.0f)))*100; }
    float GetManacost(float manacost) { return manacost * (GetTotalPercentageManacostReduction() / 100.0f); }

// Goldcost Reduction
public:
    float GetOriginalGoldcostReduction() { return _originalGoldcostReduction; }
    void SetOriginalGoldcostReduction(float goldcostReduction);
private:
    float _originalGoldcostReduction = 0; // 0.00%
public:
    float GetAttributeGoldcostReduction() { return (1-pow(1-_GoldcostReductionPerCharisma/100.0f, (float)GetTotalCharismaAttribute())) * 100; }
    float GetGoldcostReductionPerCharisma() { return _GoldcostReductionPerCharisma; }
    void SetGoldcostReductionPerCharisma(float goldcostReductionPerCharisma);
private:
    float _GoldcostReductionPerCharisma = 0.10; // 0.10%
public:
    float GetBaseGoldcostReduction() { return (1 - ((1 - GetOriginalGoldcostReduction()/100.0f) * (1 - GetAttributeGoldcostReduction()/100.0f)))*100; }
    float GetBonusGoldcostReduction();
    float GetTotalGoldcostReduction() { return (1 - ((1 - GetBaseGoldcostReduction()/100.0f) * (1 - GetBonusGoldcostReduction()/100.0f)))*100; }
    float GetGoldcost(float goldcost) { return goldcost * (GetTotalGoldcostReduction() / 100.0f); }

// Spell Amplification
public:
    float GetOriginalSpellAmplification() { return _OriginalSpellAmplification; }
    void SetOriginalSpellAmplification(float spellAmplification);
private:
    float _OriginalSpellAmplification = 1.0f;
public:
    float GetAttributeSpellAmplification() { return 100 + GetSpellAmplificationPerIntelligence() * GetTotalIntelligenceAttribute(); }
    float GetSpellAmplificationPerIntelligence() { return _SpellAmplificationPerIntelligence; }
    void SetSpellAmplificationPerIntelligence(float spellAmplificationPerIntelligence);
private:
    float _SpellAmplificationPerIntelligence = 0.10; // 0.10%
public:
    float GetBaseSpellAmplification() { return GetOriginalSpellAmplification() * GetAttributeSpellAmplification() / 100.0f; }
    float GetBonusSpellAmplification();
    float GetTotalSpellAmplification() { return GetBaseSpellAmplification() * GetBonusSpellAmplification() / 100.0f; }
    float GetDamageAfterSpellAmplification(float damage) { return damage * (GetTotalSpellAmplification() / 100.0f); }

// Cast Range Increase
public:
    float GetOriginalCastRangeIncrease() { return _OriginalCastRangeIncrease; }
    void SetOriginalCastRangeIncrease(float castRangeIncrease);
private:
    float _OriginalCastRangeIncrease = 0;
public:
    float GetAttributeCastRangeIncrease() { return GetAttributeCastRangeIncreasePerCharisma() * GetTotalCharismaAttribute(); }
    float GetAttributeCastRangeIncreasePerCharisma() { return _CastRangeIncreasePerCharisma; }
    void SetAttributeCastRangeIncreasePerCharisma(float castRangeIncreasePerCharisma);
private:
    float _CastRangeIncreasePerCharisma = 1;
public:
    float GetBaseCastRangeIncrease() { return GetOriginalCastRangeIncrease() * GetAttributeCastRangeIncrease() / 100.0f; }
    float GetBonusCastRangeIncrease();
    // Without percentage!!!
    float GetTotalCastRangeIncrease() { return GetBaseCastRangeIncrease() * GetBonusCastRangeIncrease() / 100.0f; }

// Cast Range Percentage
public:
    float GetOriginalCastRangePercentage() { return _OriginalCastRangePercentage; }
    void SetOriginalCastRangePercentage(float castRangeAmplification);
private:
    float _OriginalCastRangePercentage = 100;
public:
    float GetAttributeCastRangePercentage() { return 100 + GetCastRangePercentagePerCharisma() * GetTotalCharismaAttribute(); }
    float GetCastRangePercentagePerCharisma() { return _CastRangePercentagePerCharisma; }
    void SetCastRangePercentagePerCharisma(float castRangePercentagePerCharisma);
private:
    float _CastRangePercentagePerCharisma = 0;
public:
    float GetBaseCastRangePercentage() { return GetOriginalCastRangePercentage() * GetAttributeCastRangePercentage() / 100.0f; }
    float GetBonusCastRangePercentage();
    // Without flat increase!!!
    float GetTotalCastRangePercentage() { return GetBaseCastRangePercentage() * GetBonusCastRangePercentage() / 100.0f; }

// Cast Range
public:
    float GetTotalCastRange(float castRange) { return (castRange + GetTotalCastRangeIncrease()) * (GetTotalCastRangePercentage() / 100); }

// Cast Radius
public:
    float GetOriginalCastRadiusPercentage() { return _OriginalCastRadiusPercentage; }
    void SetOriginalCastRadiusPercentage(float castRadius);
private:
    float _OriginalCastRadiusPercentage = 100.0f;
public:
    float GetAttributeCastRadiusPercentage() { return 100 + GetCastRadiusPercentagePerCharisma() * GetTotalCharismaAttribute(); }
    float GetCastRadiusPercentagePerCharisma() { return _CastRadiusPercentagePerCharisma; }
    void SetCastRadiusPercentagePerCharisma(float castRadiusPercentagePerCharisma);
private:
    float _CastRadiusPercentagePerCharisma = 0;
public:
    float GetBaseCastRadiusPercentage() { return GetOriginalCastRadiusPercentage() * GetAttributeCastRadiusPercentage() / 100.0f; }
    float GetBonusCastRadiusPercentage();
    float GetTotalCastRadiusPercentage() { return GetBaseCastRadiusPercentage() * GetBonusCastRadiusPercentage() / 100.0f; }
    float GetTotalCastRadius(float radius) { return radius * (GetTotalCastRadiusPercentage() / 100.0f); }

// Movement Speed Increase
public:
    float GetOriginalMovementSpeedIncrease() { return _OriginalMovementSpeedIncrease; }
    void SetOriginalMovementSpeedIncrease(float castRangeIncrease);
private:
    float _OriginalMovementSpeedIncrease = 0;
public:
    float GetAttributeMovementSpeedIncrease() { return GetAttributeMovementSpeedIncreasePerAgility() * GetTotalAgilityAttribute(); }
    float GetAttributeMovementSpeedIncreasePerAgility() { return _MovementSpeedIncreasePerAgility; }
    void SetAttributeMovementSpeedIncreasePerAgility(float castRangeIncreasePerAgility);
private:
    float _MovementSpeedIncreasePerAgility = 1;
public:
    float GetBaseMovementSpeedIncrease() { return GetOriginalMovementSpeedIncrease() + GetAttributeMovementSpeedIncrease(); }
    float GetBonusMovementSpeedIncrease();
    // Without amplification!!!
    float GetTotalMovementSpeedIncrease() { return GetBaseMovementSpeedIncrease() + GetBonusMovementSpeedIncrease(); }

// Movement Speed Amplification
public:
    float GetOriginalMovementSpeedPercentage() { return _OriginalMovementSpeedPercentage; }
    void SetOriginalMovementSpeedPercentage(float movementSpeedAmplification);
private:
    float _OriginalMovementSpeedPercentage = 100;
public:
    float GetAttributeMovementSpeedPercentage() { return 100 + GetMovementSpeedPercentagePerAgility() * GetTotalAgilityAttribute(); }
    float GetMovementSpeedPercentagePerAgility() { return _MovementSpeedPercentagePerAgility; }
    void SetMovementSpeedPercentagePerAgility(float movementSpeedPercentagePerAgility);
private:
    float _MovementSpeedPercentagePerAgility = 0;
public:
    float GetBaseMovementSpeedPercentage() { return GetOriginalMovementSpeedPercentage() * GetAttributeMovementSpeedPercentage() / 100.0f; }
    float GetBonusMovementSpeedPercentage();
    // Without flat increase!!!
    float GetTotalMovementSpeedPercentage() { return GetBaseMovementSpeedPercentage() * GetBonusMovementSpeedPercentage() / 100.0f; }

// Movement Speed
public:
    float GetTotalMovementSpeed() { return GetTotalMovementSpeedIncrease() * (GetTotalMovementSpeedPercentage() / 100.0f); }

// Attack Speed
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
    float GetTotalAttackSpeedWithoutPercentageIncrease() { return GetBaseAttackSpeed() + GetBonusAttackSpeed(); }

// Attack Speed Percentage
public:
    float GetOriginalAttackSpeedPercentage() { return _OriginalAttackSpeedPercentage; }
    void SetOriginalAttackSpeedPercentage(float attackSpeedPercentage);
private:
    float _OriginalAttackSpeedPercentage = 100.0f;
public:
    float GetAttributeAttackSpeedPercentage() { return 100 + GetAttackSpeedPercentagePerAgility() * GetTotalAgilityAttribute(); }
    float GetAttackSpeedPercentagePerAgility() { return _AttackSpeedPercentagePerAgility; }
    void SetAttackSpeedPercentagePerAgility(float attackSpeedPercentagePerAgility);
private:
    float _AttackSpeedPercentagePerAgility = 0;
public:
    float GetBaseAttackSpeedPercentage() { return GetOriginalAttackSpeedPercentage() * GetAttributeAttackSpeedPercentage() / 100.0f; }
    float GetBonusAttackSpeedPercentage();
    float GetTotalAttackSpeedPercentage() { return GetBaseAttackSpeedPercentage() * (GetBonusAttackSpeedPercentage() / 100.0f); }

// Attack Speed
public:
    float GetTotalAttackSpeed() { return GetTotalAttackSpeedWithoutPercentageIncrease() * GetTotalAttackSpeedPercentage(); }
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

// Attack Time
public:
    float GetBaseAttackTime() { return _BaseAttackTime; }
    void SetBaseAttackTime(float attackTime);
private:
    float _BaseAttackTime = 1.7;
public:
    float GetBonusAttackTime();
    float GetTotalAttackTimeWithoutAttackSpeed() { return GetBaseAttackTime() + GetBonusAttackTime(); }
    float GetTotalAttackTime() { return GetTotalAttackTimeWithoutAttackSpeed() / ( GetTotalAttackSpeedInLimits() / 100.0f ); }
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

// Attack Type (Ranged / Melee)
public:
    AttackType GetOriginalAttackType() { return _OriginalAttackType; }
    void SetOriginalAttackType(AttackType attackType);
private:
    AttackType _OriginalAttackType;
public:
    AttackType GetAttackType(); // After calculating from modifiers
    bool IsMelee() { return GetAttackType() == ATTACK_TYPE_MELEE; }
    bool IsRanged() { return GetAttackType() != ATTACK_TYPE_MELEE; }

// Inventory
//TODO

// Model Collision Size + Scale
//TODO

};


#endif //STANDALONE_UNIT_H
