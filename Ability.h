#ifndef STANDALONE_ABILITY_H
#define STANDALONE_ABILITY_H

class Ability;

#include <glm/glm.hpp>
#include <string>
#include <map>
#include <utility>
#include "Unit.h"
#include "Enums.h"

using namespace glm;
using namespace std;

//TODO when loding from file, parse Enums for _Values

class Ability
{
public:
    Ability(int id, string name, Unit *owner) : _Id(id), _Name(std::move(std::move(name))), _Owner(owner)
    {
    }

    Ability(int id, string name, Unit *owner, Unit *originalOwner)
        : _Id(id), _Name(std::move(std::move(name))), _Owner(owner), _OriginalOwner(originalOwner)
    {
    }

    ~Ability()
    = default;

public:
    int GetId() { return _Id; }

    string GetName() { return _Name; }

private:
    const int _Id;
    string _Name;

// Info
public:
    int GetLevel() { return _Level; }

    bool IsLearned() { return _Level > 0; }

    bool Upgrade();

    virtual bool OnUpgrade();

    virtual bool CanBeUpgraded();

private:
    int _Level = 0;

// Texture
public:
    virtual string GetTexture(int level);

// Cast
public:
    virtual bool CanBeCast(vec3 position, vec3 direction, Unit unit);

    virtual string GetCastError(vec3 position, vec3 direction, Unit unit);

    virtual void OnCast(vec3 position, vec3 direction, Unit unit);

    virtual void Cast(vec3 position, vec3 direction, Unit unit); // Instant, without animation
    void PerformCast(vec3 position, vec3 direction, Unit unit); // With animation

// Cast Point
public:
    float GetCastPoint(int level);

// Channel
public:
    float GetChannelTime(int level);

    bool IsChannel(int level);

// Animation
public:
    string GetAnimation(int level);

// Resources
public:
    virtual float GetBaseCooldown(int level);

    virtual float GetCooldown(int level);

    float GetCurrentCooldownElapsed();

    float GetCurrentCooldownRemaining();

    float GetCurrentCooldownPercentage();

    void StartCooldown(float cooldown);

    virtual int GetBaseManacost(int level);

    virtual int GetManacost(int level);

    virtual int GetBaseGoldcost(int level);

    virtual int GetGoldcost(int level);

    void ConsumeResources(bool cooldown, bool mana, bool gold);

// Ownership
public:
    Unit *GetOwner() { return _Owner; }

    Unit *GetOriginalOwner() { return _OriginalOwner; }

private:
    Unit *_Owner = nullptr;
    Unit *_OriginalOwner = nullptr;
public:
    bool IsStolen()
    {
        return _OriginalOwner != nullptr && _Owner != _OriginalOwner;
    }

    virtual bool CanBeStolen();

// Special Values
public:
    int GetValue_Int(string key) { return GetValue_Int(std::move(key), GetLevel()); }

    int GetValue_Int(string key, int level) { return stoi(GetValue_String(std::move(key), level)); }

    float GetValue_Float(string key) { return GetValue_Float(std::move(key), GetLevel()); }

    float GetValue_Float(string key, int level) { return stof(GetValue_String(std::move(key), level)); }

    string GetValue_String(string key) { return GetValue_String(std::move(key), GetLevel()); }

    string GetValue_String(string key, int level);

    string GetValue_Raw(const string &key) { return _Values[key]; }

    void SetValue_Raw(const string &key, string value) { _Values[key] = std::move(value); }

private:
    map<string, string> _Values;
#define ABILITY_VALUE_SEPARATOR ','

// Basic Ability Info
public:
    virtual float GetAbilityBaseDamage(int level);

    virtual float GetAbilityDamage(int level);

    virtual DamageType GetAbilityDamageType(int level);

    virtual DamageFlags GetAbilityDamageFlags(int level);

    virtual TeamFlags GetAbilityTargetTeam(int level);

    virtual TypeFilter GetAbilityTargetType(int level);

    virtual FlagFilter GetAbilityTargetFlags(int level);

    virtual AbilityTargeting GetAbilityTargeting(int level);

    virtual float GetAbilityBaseRange(int level);

    virtual float GetAbilityRange(int level);

    virtual float GetAbilityBaseRadius(int level);

    virtual float GetAbilityRadius(int level);
    //TODO Toggle (Pressing the ability just toggles it)
    //TODO Autocast (Toggle but can still be casted)
    //TODO Can be learned?
    //TODO Is Hidden?
    //TODO Is Disabled By Root
    //TODO Can Be Cast While Stunned
    //TODO Don't Cancel Orders (Move to queue before current order)
    //TODo Don't Cancel Channel (Can be cast while channeling)
    //TODo Don't Alert Target (Do not show in FoW as attacker)
    //TODO Don't Follow With Attack (Prevent automatic attacks after cast)
};


#endif //STANDALONE_ABILITY_H
