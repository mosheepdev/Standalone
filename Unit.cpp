#include <stdexcept>
#include "Unit.h"

Unit::Unit() {
    _UnitId = _NextUnitId++;
}

int Unit::_NextUnitId = 1;

void Unit::Teleport(vec2 position)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetMaxLevel(int maxLevel)
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetXpPerLevel(int level, int xp)
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetLevel(int level)
{
    level = level;
    if(level <= 0)
        level = 1;
    if(level > _MaxLevel)
        level = _MaxLevel;

    _Level = level;
    _LevelXp = 0;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetTotalXp(float xp)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalDamage(int min, int max)
{
    throw std::logic_error("Not Implemented");
}

int Unit::GetBonusDamage()
{
    throw std::logic_error("Not Implemented");
}

float Unit::GetBonusDamagePercent()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetMainAttribute(Attribute mainAttribute)
{
    _MainAttribute = mainAttribute;

    throw std::logic_error("Not Implemented Over Network");
}

//-----------------------------------------------------------------

void Unit::SetOriginalStrengthAttribute(int attribute)
{
    _OriginalStrengthAttribute = attribute;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetStrengthAttributeGrow(float attributeGrow)
{
    _StrengthAttributeGrow = attributeGrow;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetBonusStrengthAttribute()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalAgilityAttribute(int attribute)
{
    _OriginalAgilityAttribute = attribute;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetAgilityAttributeGrow(float attributeGrow)
{
    _AgilityAttributeGrow = attributeGrow;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetBonusAgilityAttribute()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalIntelligenceAttribute(int attribute)
{
    _OriginalIntelligenceAttribute = attribute;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetIntelligenceAttributeGrow(float attributeGrow)
{
    _IntelligenceAttributeGrow = attributeGrow;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetBonusIntelligenceAttribute()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalCharismaAttribute(int attribute)
{
    _OriginalCharismaAttribute = attribute;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetCharismaAttributeGrow(float attributeGrow)
{
    _CharismaAttributeGrow = attributeGrow;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetBonusCharismaAttribute()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalHealthPool(int baseHealth)
{
    _OriginalHealthPool = baseHealth < 1 ? 1 : baseHealth;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetHealthPoolPerStrength(float healthPoolPerStrength)
{
    _HealthPoolPerStrength = healthPoolPerStrength;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetFlatBonusHealthPool()
{
    throw std::logic_error("Not Implemented");
}

float Unit::GetPercentageBonusHealthPool()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetCurrentHealth(float health)
{
    float pool = GetTotalHealthPool();
    if(health > pool)
        health = pool;
    if(health < 0)
        health = 0;
    _CurrentHealth = health;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetHealthPercentage(float percentage)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetBaseHealthRegeneration(float regeneration)
{
    _BaseHealthRegeneration = regeneration;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusHealthRegeneration()
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetPercentageHealthRegenerationAmplificationPerStrength(float percentageHealthRegenerationPerStrength)
{
    _PercentageHealthRegenerationAmplificationPerStrength = percentageHealthRegenerationPerStrength;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetPercentageBonusHealthRegeneration()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::TakeDamage(float amount, DamageType type, Unit *damager, Ability *ability)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::Heal(float amount, Unit *healer, Ability *ability)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalManaPool(int baseMana)
{
    _OriginalManaPool = baseMana < 1 ? 1 : baseMana;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetManaPoolPerIntelligence(float manaPoolPerIntelligence)
{
    _ManaPoolPerIntelligence = manaPoolPerIntelligence;

    throw std::logic_error("Not Implemented Over Network");
}

int Unit::GetFlatBonusManaPool()
{
    throw std::logic_error("Not Implemented");
}

float Unit::GetPercentageBonusManaPool()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetCurrentMana(float mana)
{
    float pool = GetTotalManaPool();
    if(mana > pool)
        mana = pool;
    if(mana < 0)
        mana = 0;
    _CurrentMana = mana;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetManaPercentage(float percentage)
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetBaseManaRegeneration(float regeneration)
{
    _BaseManaRegeneration = regeneration;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusManaRegeneration()
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetPercentageManaRegenerationAmplificationPerIntelligence(float percentageManaRegenerationPerIntelligence)
{
    _PercentageManaRegenerationAmplificationPerIntelligence = percentageManaRegenerationPerIntelligence;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetPercentageBonusManaRegeneration()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalArmor(float armor)
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetArmorPerAgility(float armorPerAgility)
{
    throw std::logic_error("Not Implemented");
}

float Unit::GetBonusArmor()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetPercentageOriginalMagicResistance(float magicResistance)
{
    _PercentageOriginalMagicResistance = magicResistance;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetPercentageMagicResistancePerCharisma(float percentageMagicResistancePerCharisma)
{
    _PercentageMagicResistancePerCharisma = percentageMagicResistancePerCharisma;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetPercentageBonusMagicResistance()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalStatusResistance(float statusResistance)
{
    _OriginalStatusResistance = statusResistance;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetStatusResistancePerStrength(float statusResistancePerStrength)
{
    _StatusResistancePerStrength = statusResistancePerStrength;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusStatusResistance()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetPercentageOriginalCooldownReduction(float percentageCooldownReduction)
{
    _PercentageOriginalCooldownReduction = percentageCooldownReduction;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetPercentageCooldownReductionPerCharisma(float percentageCooldownReductionPerCharisma)
{
    _PercentageCooldownReductionPerCharisma = percentageCooldownReductionPerCharisma;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetPercentageBonusCooldownReduction()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetPercentageOriginalManacostReduction(float percentageManacostReduction)
{
    _PercentageOriginalManacostReduction = percentageManacostReduction;

    throw std::logic_error("Not Implemented Over Network");
}

/*
void Unit::SetPercentageManacostReductionPerCharisma(float percentageManacostReductionPerCharisma)
{
    _PercentageManacostReductionPerCharisma = percentageManacostReductionPerCharisma;

    throw std::logic_error("Not Implemented Over Network");
}
*/

float Unit::GetPercentageBonusManacostReduction()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetPercentageOriginalGoldcostReduction(float percentageGoldcostReduction)
{
    _PercentageOriginalGoldcostReduction = percentageGoldcostReduction;

    throw std::logic_error("Not Implemented Over Network");
}

/*
void Unit::SetPercentageGoldcostReductionPerCharisma(float percentageGoldcostReductionPerCharisma)
{
    _PercentageGoldcostReductionPerCharisma = percentageGoldcostReductionPerCharisma;

    throw std::logic_error("Not Implemented Over Network");
}
*/

float Unit::GetPercentageBonusGoldcostReduction()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetOriginalCastRangeIncrease(float castRangeIncrease)
{
    _OriginalCastRangeIncrease = castRangeIncrease;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusCastRangeIncrease()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetBaseCastRangeAmplification(float castRangeAmplification)
{
    _BaseCastRangeAmplification = castRangeAmplification;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusCastRangeAmplification()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

//TODO Spell Amplification

//-----------------------------------------------------------------

//TODO Movement Speed Increase

//-----------------------------------------------------------------

//TODO Movement Speed Amplification

//-----------------------------------------------------------------

void Unit::SetOriginalAttackSpeed(float attackSpeed)
{
    _OriginalAttackSpeed = attackSpeed;

    throw std::logic_error("Not Implemented Over Network");
}

void Unit::SetAttributeAttackSpeedPerAgility(float attackSpeedPerAgility)
{
    _AttackSpeedPerAgility = attackSpeedPerAgility;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusAttackSpeed()
{
    throw std::logic_error("Not Implemented");
}

void Unit::SetAttackSpeedLimit(int min, int max)
{
    _MinAttackSpeed = min < 1 ? 1 : min;
    _MaxAttackSpeed = max < min ? min : max;

    throw std::logic_error("Not Implemented Over Network");
}

//-----------------------------------------------------------------

void Unit::SetBaseAttackSpeedAmplification(float attackSpeedAmplification)
{
    _BaseAttackSpeedAmplification = attackSpeedAmplification;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusAttackSpeedAmplification()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetBaseAttackTime(float attackTime)
{
    _BaseAttackTime = attackTime;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusAttackTime()
{
    throw std::logic_error("Not Implemented");
}

//-----------------------------------------------------------------

void Unit::SetBaseAttackRange(float attackRange)
{
    _BaseAttackRange = attackRange;

    throw std::logic_error("Not Implemented Over Network");
}

float Unit::GetBonusAttackRange()
{
    throw std::logic_error("Not Implemented");
}