#ifndef STANDALONE_UNIT_H
#define STANDALONE_UNIT_H

class Unit;

#include <glm/glm.hpp>
#include <cmath>

#include <vector>


#include "Enums.h"
#include "Ability.h"
#include "Modifier.h"

using namespace std;
using namespace glm;

class Unit
{
public:
    Unit(string name);

// Apply Config
public:
    //virtual void LoadConfig();//TODO

// Unit ID
public:
    int GetUnitId() { return _UnitId; }

private:
    int _UnitId;
    static int _NextUnitId;

public:
    string GetName() { return _Name; }

private:
    string _Name;

// Position
public:
    vec3 GetPosition() { return _Position; }

    vec3 GetAbsOrigin() { return GetPosition(); }

    void Teleport(vec2 position) { Teleport(vec3(position, 0.0)); }

    void Teleport(vec3 position);

private:
    vec3 _Position = vec3(0, 0, 0);

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
    int *_ExperiencePerLevel = nullptr;
public:
    int GetLevel() { return _Level; }

    void SetLevel(int level);

    float GetCurrentXp() { return _LevelXp; }

    float GetCurrentXpPercentage()
    {
        if(_Level >= _MaxLevel)
            return 100;
        return GetCurrentXp() / GetXpPerLevel(_Level + 1) / 100.0f;
    }

    float ClearCurrentXp();

    void SetCurrentXp(float xp)
    {
        ClearCurrentXp();
        AddXp(xp, false);
    }

    float GetXpToNextLevel()
    {
        if(_Level >= _MaxLevel)
            return 0;
        return GetXpPerLevel(_Level + 1) - _LevelXp;
    }

    float GetTotalXp() { return GetXpPerLevelTotal(_Level) + _LevelXp; }

    void SetTotalXp(float xp, bool affectedByModifiers = false);

    void AddXp(float xp, bool affectedByModifiers = true);

    float GetPercentageBonusXp();

    float GetXpAfterBonus(float xp) { return xp * (GetPercentageBonusXp() / 100.0f); }

private:
    int _Level = 0; // 0+
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
        switch(GetMainAttribute())
        {
            default:
                return 0;
            case Attribute::STRENGTH:
                return GetTotalStrengthAttribute();
            case Attribute::AGILITY:
                return GetTotalAgilityAttribute();
            case Attribute::INTELLIGENCE:
                return GetTotalIntelligenceAttribute();
            case Attribute::WILL:
                return GetTotalWillAttribute();
        }
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

    int GetTotalBonusDamage() { return (int) (GetFlatBonusDamage() + GetBaseRealDamage() * (GetPercentageBonusDamage() / 100.0f)); }

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
    Attribute _MainAttribute = Attribute::STRENGTH;

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
    int GetBaseStrengthAttribute() { return GetOriginalStrengthAttribute() + (int) (GetStrengthAttributeGrow() * GetLevel()); }

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
    int GetBaseAgilityAttribute() { return GetOriginalAgilityAttribute() + (int) (GetAgilityAttributeGrow() * GetLevel()); }

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
    int GetBaseIntelligenceAttribute() { return GetOriginalIntelligenceAttribute() + (int) (GetIntelligenceAttributeGrow() * GetLevel()); }

    int GetBonusIntelligenceAttribute();

    int GetTotalIntelligenceAttribute() { return GetBaseIntelligenceAttribute() + GetBonusIntelligenceAttribute(); }

// Attribute - Will
public:
    int GetOriginalWillAttribute() { return _OriginalWillAttribute; }

    void SetOriginalWillAttribute(int attribute);

private:
    int _OriginalWillAttribute = 0;
public:
    float GetWillAttributeGrow() { return _WillAttributeGrow; }

    void SetWillAttributeGrow(float attributeGrow);

private:
    float _WillAttributeGrow = 1.0;
public:
    int GetBaseWillAttribute() { return GetOriginalWillAttribute() + (int) (GetWillAttributeGrow() * GetLevel()); }

    int GetBonusWillAttribute();

    int GetTotalWillAttribute() { return GetBaseWillAttribute() + GetBonusWillAttribute(); }


// Health Pool
public:
    int GetOriginalHealthPool() { return _OriginalHealthPool; }

    void SetOriginalHealthPool(int baseHealth);

private:
    int _OriginalHealthPool = 200;
public:
    int GetAttributeHealthPool() { return (int) (GetHealthPoolPerStrength() * GetTotalStrengthAttribute()); }

    float GetHealthPoolPerStrength() { return _HealthPoolPerStrength; }

    void SetHealthPoolPerStrength(float healthPoolPerStrength);

private:
    float _HealthPoolPerStrength = 20;
public:
    int GetBaseHealthPool() { return GetOriginalHealthPool() + GetAttributeHealthPool(); }

    int GetFlatBonusHealthPool();

    float GetPercentageBonusHealthPool();

    int GetBonusHealthPool() { return GetFlatBonusHealthPool() + (int) (GetBaseHealthPool() * GetPercentageBonusHealthPool() / 100.0f); }

    int GetTotalHealthPool() { return GetBaseHealthPool() + GetBonusHealthPool(); }

// Health - Current
public:
    float GetCurrentHealth() { return _CurrentHealth; } //TODO count with change of health pool
    void SetCurrentHealth(float health);

private:
    float _CurrentHealth = GetTotalHealthPool();
public:
    float GetCurrentHealthPercentage() { return ((float) GetCurrentHealth()) / GetTotalHealthPool(); }

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
    float GetAttributePercentageHealthRegeneration() { return (1 - pow(1 - _PercentageHealthRegenerationPerStrength, (float) GetTotalStrengthAttribute())) * 100; }

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
    inline void TakeDamage(float amount) { TakeDamage(amount, DamageType::PURE); }

    inline void TakeDamage(float amount, DamageType type) { TakeDamage(amount, type, DamageFlags::NONE); }

    inline void TakeDamage(float amount, DamageType type, DamageFlags flags) { TakeDamage(amount, type, flags, nullptr); }

    inline void TakeDamage(float amount, DamageType type, DamageFlags flags, Unit *damager) { TakeDamage(amount, type, flags, nullptr, nullptr); }

    void TakeDamage(float amount, DamageType type, DamageFlags flags, Unit *damager, Ability *ability);

// Heal
    inline void Heal(float amount) { Heal(amount, nullptr); }

    inline void Heal(float amount, Unit *healer) { Heal(amount, nullptr, nullptr); }

    void Heal(float amount, Unit *healer, Ability *ability);

// Mana Pool
public:
    int GetOriginalManaPool() { return _OriginalManaPool; } //TODO count with change of mana pool
    void SetOriginalManaPool(int baseMana);

private:
    int _OriginalManaPool = 50;
public:
    int GetAttributeManaPool() { return (int) (GetManaPoolPerIntelligence() * GetTotalIntelligenceAttribute()); }

    float GetManaPoolPerIntelligence() { return _ManaPoolPerIntelligence; }

    void SetManaPoolPerIntelligence(float manaPoolPerIntelligence);

private:
    float _ManaPoolPerIntelligence = 15;
public:
    int GetBaseManaPool() { return GetOriginalManaPool() + GetAttributeManaPool(); }

    int GetFlatBonusManaPool();

    float GetPercentageBonusManaPool();

    int GetBonusManaPool() { return GetFlatBonusManaPool() + (int) (GetBaseManaPool() * GetPercentageBonusManaPool() / 100.0f); }

    int GetTotalManaPool() { return GetBaseManaPool() + GetBonusManaPool(); }

// Mana - Current
public:
    int GetCurrentMana() { return (int) _CurrentMana; }

    void SetCurrentMana(float health);

private:
    float _CurrentMana = GetTotalManaPool();
public:
    float GetManaPercentage() { return ((float) GetCurrentMana()) / GetTotalManaPool(); }

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
    float GetAttributePercentageManaRegeneration() { return (1 - pow(1 - _PercentageManaRegenerationAmplificationPerIntelligence, (float) GetTotalIntelligenceAttribute())) * 100; }

    float GetPercentageManaRegenerationPerIntelligence() { return _PercentageManaRegenerationAmplificationPerIntelligence * 100; }

    void SetPercentageManaRegenerationAmplificationPerIntelligence(float percentageManaRegenerationPerIntelligence);

private:
    float _PercentageManaRegenerationAmplificationPerIntelligence = 2.00f; // 2.0%
public:
    float GetBonusPercentageManaRegeneration();

    float GetTotalPercentageManaRegeneration() { return GetBonusPercentageManaRegeneration() + GetAttributePercentageManaRegeneration(); }

public:
    float GetTotalManaRegeneration() { return (GetTotalPercentageManaRegeneration() / 100.0f) * GetTotalManaRegenerationWithoutAmplification(); }

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
    int GetBaseArmor() { return GetOriginalArmor() + GetAttributeArmor(); }

    int GetBonusArmor();

    int GetTotalArmor() { return GetBaseArmor() + GetBonusArmor(); }

public:
    float GetReceivedPhysicalDamageMultiplier()
    {
        float armor = GetTotalArmor();
        return 1 - (0.05f * armor / (1 + 0.05f * abs(armor)));
    }

    float GetPercentagePhysicalDamageResistance() { return (1 - GetReceivedPhysicalDamageMultiplier()) * 100.0f; }

    float GetPhysicalDamageAfterReduction(float damage) { return damage * GetReceivedPhysicalDamageMultiplier(); } //{ return damage * (1 - GetPercentagePhysicalDamageResistance()/100.0f); }

// Magic Resistance
public:
    float GetOriginalMagicResistance() { return _OriginalMagicResistance; }

    void SetOriginalMagicResistance(float magicResistance);

private:
    float _OriginalMagicResistance = 20.00; // 20%
public:
    float GetAttributeMagicResistance() { return (1 - pow(1 - _MagicResistancePerWill, (float) GetTotalWillAttribute())) * 100.0f; }

    float GetMagicResistancePerWill() { return _MagicResistancePerWill * 100; }

    void SetMagicResistancePerWill(float percentageMagicResistancePerWill);

private:
    float _MagicResistancePerWill = 0.20;// 0.20%
public:
    float GetBaseMagicResistance() { return (1 - ((1 - GetOriginalMagicResistance() / 100.0f) * (1 - GetAttributeMagicResistance() / 100.0f))) * 100.0f; }

    float GetBonusMagicResistance();

    float GetTotalMagicResistance() { return (1 - ((1 - GetBaseMagicResistance() / 100.0f) * (1 - GetBonusMagicResistance() / 100.0f))) * 100.0f; }

    float GetMagicDamageAfterReduction(float damage) { return damage * (1 - GetTotalMagicResistance() / 100.0f); }

// Status Resistance
public:
    float GetOriginalStatusResistance() { return _OriginalStatusResistance; }

    void SetOriginalStatusResistance(float statusResistance);

private:
    float _OriginalStatusResistance = 0.00; // 0%
public:
    float GetAttributeStatusResistance() { return (1 - pow(1 - _StatusResistancePerStrength, (float) GetTotalStrengthAttribute())) * 100; }

    float GetStatusResistancePerStrength() { return _StatusResistancePerStrength * 100; }

    void SetStatusResistancePerStrength(float statusResistancePerStrength);

private:
    float _StatusResistancePerStrength = 0.10;// 0.10%
public:
    float GetBaseStatusResistance() { return 1 - ((1 - GetOriginalStatusResistance()) * (1 - GetAttributeStatusResistance())); }

    float GetBonusStatusResistance();

    float GetTotalStatusResistance() { return 1 - ((1 - GetBaseStatusResistance()) * (1 - GetBonusStatusResistance())); }

    float GetDurationAfterStatusResistance(float duration) { return duration * (1 - GetTotalStatusResistance() / 100.0f); }

// Cooldown Reduction
public:
    float GetOriginalCooldownReduction() { return _OriginalCooldownReduction; }

    void SetOriginalCooldownReduction(float percentageCooldownReduction);

private:
    float _OriginalCooldownReduction = 0; // 0.00%
public:
    float GetAttributeCooldownReduction() { return (1 - pow(1 - _CooldownReductionPerWill / 100.0f, (float) GetTotalWillAttribute())) * 100; }

    float GetCooldownReductionPerWill() { return _CooldownReductionPerWill; }

    void SetCooldownReductionPerWill(float cooldownReductionPerWill);

private:
    float _CooldownReductionPerWill = 0.10; // 0.10%
public:
    float GetBaseCooldownReduction() { return (1 - ((1 - GetOriginalCooldownReduction() / 100.0f) * (1 - GetAttributeCooldownReduction() / 100.0f))) * 100; }

    float GetBonusCooldownReduction();

    float GetTotalCooldownReduction() { return (1 - ((1 - GetBaseCooldownReduction() / 100.0f) * (1 - GetBonusCooldownReduction() / 100.0f))) * 100; }

    float GetCooldown(float cooldown) { return cooldown * (GetTotalCooldownReduction() / 100.0f); }

// Manacost Reduction
public:
    float GetOriginalManacostReduction() { return _OriginalManacostReduction; }

    void SetOriginalManacostReduction(float manacostReduction);

private:
    float _OriginalManacostReduction = 0; // 0.00%
public:
    float GetAttributeManacostReduction() { return (1 - pow(1 - _ManacostReductionPerWill / 100.0f, (float) GetTotalWillAttribute())) * 100; }

    float GetManacostReductionPerWill() { return _ManacostReductionPerWill; }

    void SetManacostReductionPerWill(float manacostReductionPerWill);

private:
    float _ManacostReductionPerWill = 0.00;
public:
    float GetBaseManacostReduction() { return (1 - ((1 - GetOriginalManacostReduction() / 100.0f) * (1 - GetAttributeManacostReduction() / 100.0f))) * 100; }

    float GetBonusManacostReduction();

    float GetTotalManacostReduction() { return (1 - ((1 - GetBaseManacostReduction() / 100.0f) * (1 - GetBonusManacostReduction() / 100.0f))) * 100; }

    float GetManacost(float manacost) { return manacost * (GetTotalManacostReduction() / 100.0f); }

// Goldcost Reduction
public:
    float GetOriginalGoldcostReduction() { return _originalGoldcostReduction; }

    void SetOriginalGoldcostReduction(float goldcostReduction);

private:
    float _originalGoldcostReduction = 0; // 0.00%
public:
    float GetAttributeGoldcostReduction() { return (1 - pow(1 - _GoldcostReductionPerWill / 100.0f, (float) GetTotalWillAttribute())) * 100; }

    float GetGoldcostReductionPerWill() { return _GoldcostReductionPerWill; }

    void SetGoldcostReductionPerWill(float goldcostReductionPerWill);

private:
    float _GoldcostReductionPerWill = 0.10; // 0.10%
public:
    float GetBaseGoldcostReduction() { return (1 - ((1 - GetOriginalGoldcostReduction() / 100.0f) * (1 - GetAttributeGoldcostReduction() / 100.0f))) * 100; }

    float GetBonusGoldcostReduction();

    float GetTotalGoldcostReduction() { return (1 - ((1 - GetBaseGoldcostReduction() / 100.0f) * (1 - GetBonusGoldcostReduction() / 100.0f))) * 100; }

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
    int GetOriginalCastRangeIncrease() { return _OriginalCastRangeIncrease; }

    void SetOriginalCastRangeIncrease(int castRangeIncrease);

private:
    int _OriginalCastRangeIncrease = 0;
public:
    int GetAttributeCastRangeIncrease() { return GetCastRangeIncreasePerWill() * GetTotalWillAttribute(); }

    float GetCastRangeIncreasePerWill() { return _CastRangeIncreasePerWill; }

    void SetCastRangeIncreasePerWill(float castRangeIncreasePerWill);

private:
    float _CastRangeIncreasePerWill = 1;
public:
    int GetBaseCastRangeIncrease() { return GetOriginalCastRangeIncrease() * GetAttributeCastRangeIncrease() / 100.0f; }

    int GetBonusCastRangeIncrease();

    // Without percentage!!!
    float GetTotalCastRangeIncrease() { return GetBaseCastRangeIncrease() * GetBonusCastRangeIncrease() / 100.0f; }

// Cast Range Percentage
public:
    float GetOriginalCastRangePercentage() { return _OriginalCastRangePercentage; }

    void SetOriginalCastRangePercentage(float castRangeAmplification);

private:
    float _OriginalCastRangePercentage = 100;
public:
    float GetAttributeCastRangePercentage() { return 100 + GetCastRangePercentagePerWill() * GetTotalWillAttribute(); }

    float GetCastRangePercentagePerWill() { return _CastRangePercentagePerWill; }

    void SetCastRangePercentagePerWill(float castRangePercentagePerWill);

private:
    float _CastRangePercentagePerWill = 0;
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
    float GetAttributeCastRadiusPercentage() { return 100 + GetCastRadiusPercentagePerWill() * GetTotalWillAttribute(); }

    float GetCastRadiusPercentagePerWill() { return _CastRadiusPercentagePerWill; }

    void SetCastRadiusPercentagePerWill(float castRadiusPercentagePerWill);

private:
    float _CastRadiusPercentagePerWill = 0;
public:
    float GetBaseCastRadiusPercentage() { return GetOriginalCastRadiusPercentage() * GetAttributeCastRadiusPercentage() / 100.0f; }

    float GetBonusCastRadiusPercentage();

    float GetTotalCastRadiusPercentage() { return GetBaseCastRadiusPercentage() * GetBonusCastRadiusPercentage() / 100.0f; }

    float GetTotalCastRadius(float radius) { return radius * (GetTotalCastRadiusPercentage() / 100.0f); }

// Movement Speed Increase
public:
    int GetOriginalMovementSpeedIncrease() { return _OriginalMovementSpeedIncrease; }

    void SetOriginalMovementSpeedIncrease(int castRangeIncrease);

private:
    int _OriginalMovementSpeedIncrease = 0;
public:
    int GetAttributeMovementSpeedIncrease() { return (int) (GetMovementSpeedIncreasePerAgility() * GetTotalAgilityAttribute()); }

    float GetMovementSpeedIncreasePerAgility() { return _MovementSpeedIncreasePerAgility; }

    void SetMovementSpeedIncreasePerAgility(float castRangeIncreasePerAgility);

private:
    float _MovementSpeedIncreasePerAgility = 1;
public:
    int GetBaseMovementSpeedIncrease() { return GetOriginalMovementSpeedIncrease() + GetAttributeMovementSpeedIncrease(); }

    int GetBonusMovementSpeedIncrease();

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
    int GetOriginalAttackSpeed() { return _OriginalAttackSpeed; }

    void SetOriginalAttackSpeed(int attackSpeed);

private:
    int _OriginalAttackSpeed = 100;
public:
    int GetAttributeAttackSpeed() { return (int) (GetTotalAgilityAttribute() * GetAttackSpeedPerAgility()); }

    float GetAttackSpeedPerAgility() { return _AttackSpeedPerAgility; }

    void SetAttackSpeedPerAgility(float attackSpeedPerAgility);

private:
    float _AttackSpeedPerAgility = 1;
public:
    int GetBaseAttackSpeed() { return GetOriginalAttackSpeed() + GetAttributeAttackSpeed(); }

    int GetBonusAttackSpeed();

    int GetTotalAttackSpeedWithoutPercentageIncrease() { return GetBaseAttackSpeed() + GetBonusAttackSpeed(); }

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

    float GetTotalAttackTime() { return GetTotalAttackTimeWithoutAttackSpeed() / (GetTotalAttackSpeedInLimits() / 100.0f); }

    float GetAttacksPerSecond() { return 1 / GetTotalAttackTime(); }

// Attack Range
public:
    int GetBaseAttackRange() { return _BaseAttackRange; }

    void SetBaseAttackRange(int attackRange);

private:
    int _BaseAttackRange = 100;
public:
    int GetBonusAttackRange();

    int GetTotalAttackRange() { return GetBaseAttackRange() + GetBonusAttackRange(); }

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

// Modifiers
public:
    // Returns array of Modifier*
    Modifier **GetAllModifiers(int *count)
    {
        *count = (int) _AllModifiers.size();
        return &_AllModifiers[0];
    }

private:
    std::vector<Modifier *> _AllModifiers;
public:
    Modifier *AddNewModifier(string name) { return AddNewModifier(name, nullptr); }

    Modifier *AddNewModifier(string name, Unit *sourceUnit) { return AddNewModifier(name, nullptr, nullptr); }

    Modifier *AddNewModifier(string name, Unit *sourceUnit, Ability *sourceAbility);

public:
    bool HasModifier(string name);

    bool HasModifier(string name, Unit *sourceUnit);

public:
    int GetModifierCount(string name);

    int GetModifierCount(string name, Unit *sourceUnit);

    int GetModifierStackCount(string name);

    int GetModifierStackCount(string name, Unit *sourceUnit);

public:
    Modifier *GetModifier(string name);

    Modifier *GetModifier(string name, Unit *sourceUnit);

public:
    void RemoveModifier(Modifier *modifier);

    int RemoveModifiers(string name);

    int RemoveModifiers(string name, Unit *sourceUnit);

    int RemoveModifiers(string name, Unit *sourceUnit, Ability *sourceAbility);

public:
    int PurgeModifiers(PurgeType purgeType);
};


#endif //STANDALONE_UNIT_H
