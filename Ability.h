#ifndef STANDALONE_ABILITY_H
#define STANDALONE_ABILITY_H

class Ability;

#include <glm/glm.hpp>
#include "Unit.h"
#include "Enums.h"

using namespace glm;

class Ability
{
public:
    Ability(int id, const char* name, Unit* owner) : _Id(id),_Name(name), _Owner(owner) {}
    Ability(int id, const char* name, Unit* owner, Unit* originalOwner) : _Id(id),_Name(name), _Owner(owner), _OriginalOwner(originalOwner) {}
public:
    int GetId() { return _Id; }
    const char* GetName() { return _Name; }
private:
    const int _Id;
    const char* _Name;

// Info
public:
    int GetLevel() { return _Level; }
    bool IsLearned() { return _Level > 0; }
    bool Upgrade();
private:
    int _Level = 0;

// Cast
public:
    virtual void OnCast(vec3 position, vec3 direction, Unit unit);
    void Cast(); // Instant, without animation
    void PerformCast(); // With animation

// Resources
public:
    virtual float GetCooldown(int level);
    void StartCooldown(float cooldown);
    virtual int GetManacost(int level);
    virtual int GetGoldcost(int level);
    void ConsumeResources(bool cooldown, bool mana, bool gold);

// Ownership
public:
    Unit* GetOwner() { return _Owner; }
    Unit* GetOriginalOwner() { return _OriginalOwner; }
private:
    Unit* _Owner = nullptr;
    Unit* _OriginalOwner = nullptr;
public:
    bool IsStolen()
    {
        return _OriginalOwner != nullptr && _Owner != _OriginalOwner;
    }
    virtual bool CanBeStolen();

// Special Values
public:
    int GetValue_Int(char* key) { return GetValue_Int(key, GetLevel()); }
    int GetValue_Int(char* key, int level);
    float GetValue_Float(char* key) { return GetValue_Float(key, GetLevel()); }
    float GetValue_Float(char* key, int level);
    char* GetValue_String(char* key) { return GetValue_String(key, GetLevel()); }
    char* GetValue_String(char* key, int level);

// Basic Ability Info
public:
    float GetAbilityDamage(int level);
    DamageType GetAbilityDamageType(int level);
    DamageFlags GetAbilityDamageFlags(int level);
    Team_Flags GetAbilityTargetTeam(int level);
    TypeFilter GetAbilityTargetType(int level);
    FlagFilter GetAbilityTargetFlags(int level);
    AbilityTargetting GetAbilityTargetting(int level);
    float GetAbilityRange(int level);
    float GetAbilityRadius(int level);
    //TODO channel
    //TODO Toggle (Pressing the ability just toggles it)
    //TODO Autocast (Toggle but can still be casted)
    //TODO Can be learned?
    //TODO Is Hidden?
    //TODO Is Disabled By Root
    //TODO Can Be Cast While Stunned
    //TODO Immediate Cast
    //TODO Don't Cancel Orders (Move to queue before current order)
    //TODo Don't Cancel Channel (Can be cast while channeling)
    //TODo Don't Alert Target (Do not show in FoW as attacker)
    //TODO Don't Follow With Attack (Prevent automatic attacks after cast)
    //TODO No Ability Upgrade
};


#endif //STANDALONE_ABILITY_H
