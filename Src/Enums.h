#ifndef STANDALONE_HEADERS_H
#define STANDALONE_HEADERS_H

#include <map>

enum class DamageType
{
    PURE,
    PHYSICAL,
    MAGICAL,
    _COUNT
};

enum class DamageFlags
{
    NONE = 0,
    NO_ARMOR = 1 << 0, // Ignore armor
    NO_MAGIC_RESIST = 1 << 1, // Ignore magic resistance
    NO_DAMAGE_BLOCK = 1 << 2, // Ignore damage block
    NON_LETHAL = 1 << 3, // Cannot kill target
    REFLECTION = 1 << 4, // Is reflection damage (cannot be reflected)
};

enum class Attribute
{
    // Health
    // Health Regeneration Amplification
    // Status Resistance
        STRENGTH,
    // Armor = Physical Resistance
    // Movement Speed
    // Attack Speed
        AGILITY,
    // Mana
    // Mana Regeneration Amplification
    // Spell Amplification
        INTELLIGENCE,
    // Cooldown Reduction
    // Cast Range Increase
    // Magic Resistance
        WILL,
    _COUNT
};

enum class Team : unsigned int
{
    NEUTRAL = 0,
    SPECTATOR = NEUTRAL, // Spectators are players assigned to Neutrals
    //TEAM_0 = NEUTRAL, // Neutrals, better not provide for confusion
    TEAM_1 = 1,
    TEAM_2 = 2,
    TEAM_3 = 3,
    TEAM_4 = 4,
    TEAM_5 = 5,
    TEAM_6 = 6,
    TEAM_7 = 7,
    TEAM_8 = 8,
    TEAM_9 = 9,
    TEAM_10 = 10,
    TEAM_11 = 11,
    TEAM_12 = 12,
    TEAM_13 = 13,
    TEAM_14 = 14,
    TEAM_15 = 15,
    TEAM_16 = 16,
    TEAM_17 = 17,
    TEAM_18 = 18,
    TEAM_19 = 19,
    TEAM_20 = 20,
    TEAM_21 = 21,
    TEAM_22 = 22,
    TEAM_23 = 23,
    TEAM_24 = 24,
    TEAM_25 = 25,
    _COUNT
    // must be < 32 for TeamFlags to be maximum of 1 << 31 to fit into int
};

enum class TeamFlags : unsigned int
{
    ANY = 0xFFffFFff,
    NEUTRAL = 1 << (unsigned int) Team::NEUTRAL,
    TEAM_1 = 1 << (unsigned int) Team::TEAM_1,
    TEAM_2 = 1 << (unsigned int) Team::TEAM_2,
    TEAM_3 = 1 << (unsigned int) Team::TEAM_3,
    TEAM_4 = 1 << (unsigned int) Team::TEAM_4,
    TEAM_5 = 1 << (unsigned int) Team::TEAM_5,
    TEAM_6 = 1 << (unsigned int) Team::TEAM_6,
    TEAM_7 = 1 << (unsigned int) Team::TEAM_7,
    TEAM_8 = 1 << (unsigned int) Team::TEAM_8,
    TEAM_9 = 1 << (unsigned int) Team::TEAM_9,
    TEAM_10 = 1 << (unsigned int) Team::TEAM_10,
    TEAM_11 = 1 << (unsigned int) Team::TEAM_11,
    TEAM_12 = 1 << (unsigned int) Team::TEAM_12,
    TEAM_13 = 1 << (unsigned int) Team::TEAM_13,
    TEAM_14 = 1 << (unsigned int) Team::TEAM_14,
    TEAM_15 = 1 << (unsigned int) Team::TEAM_15,
    TEAM_16 = 1 << (unsigned int) Team::TEAM_16,
    TEAM_17 = 1 << (unsigned int) Team::TEAM_17,
    TEAM_18 = 1 << (unsigned int) Team::TEAM_18,
    TEAM_19 = 1 << (unsigned int) Team::TEAM_19,
    TEAM_20 = 1 << (unsigned int) Team::TEAM_20,
    TEAM_21 = 1 << (unsigned int) Team::TEAM_21,
    TEAM_22 = 1 << (unsigned int) Team::TEAM_22,
    TEAM_23 = 1 << (unsigned int) Team::TEAM_23,
    TEAM_24 = 1 << (unsigned int) Team::TEAM_24,
    TEAM_25 = 1 << (unsigned int) Team::TEAM_25,
};

enum class PurgeType
{
    NONE,
    SOFT,
    HARD,
    RESPAWN, // Some modifiers may not want to be purged but want to disappear on death
    _COUNT
};

enum class FlagFilter
{

};

enum class FindOrder
{
    RANDOMIZED = 0,
    CLOSEST = 1,
    FARTHEST = 2,
    ANY = 3, // Ordered by internal order
};

enum class ModifierPriority
{
    MINIMAL = -3,
    LOWEST = -2,
    LOW = -1,
    NORMAL = 0, // Normal, should be default value
    HIGH = 1,
    ULTRA = 2,
    SUPER_ULTRA = 3
};

enum class ModifierFlags : unsigned int
{
    NONE = 0,

    STATUS_STUN = 1 << 0, // Cannot do anything
    STATUS_ROOT = 1 << 1, // Cannot move (and cast some movement abilities), can still attack
    STATUS_SILENCE = 1 << 2, // No casting of abilities
    STATUS_MUTE = 1 << 3, // No casting of items
    STATUS_BREAK = 1 << 4, // No passives (abilities and items)
    STATUS_HIDDEN = 1 << 5, // Out of game - cannot be targeted

    ABILITY_STOP_COOLDOWN = 1 << 6, // No cooldown progress on abilities
    ABILITY_NO_COOLDOWN = 1 << 7, // No ability cost cooldown
    ABILITY_NO_MANA = 1 << 8, // No ability cost mana
    ABILITY_NO_GOLD = 1 << 9, // No ability cost gold

    IMMUNITY_MAGIC = 1 << 10, // Cannot take magic damage
    IMMUNITY_PHYSICAL = 1 << 11, // Cannot take physical damage
    IMMUNITY_PURE = 1 << 12, // Cannot take pure damage
    IMMUNITY_ALL = IMMUNITY_MAGIC | IMMUNITY_PHYSICAL | IMMUNITY_PURE, // Cannot take damage
    IMMUNITY_DEATH = 1 << 13, // Cannot die
    IMMUNITY_HEAL = 1 << 14, // Cannot be healed

    INVISIBLE = 1 << 15, // Cannot be seen by enemies, can be revealed
    INVISIBLE_RAW = 1 << 16, // Cannot be seen by enemies, cannot be revealed

    ATTACK_GLOBAL = 1 << 17, // Has global attack
    ATTACK_UNABLE = 1 << 18, // Cannot attack
};

enum class AbilityTargeting
{
    PASSIVE = 0,
    NONE = 1 << 0,
    POINT = 1 << 1,
    UNIT = 1 << 2,
    AOE = 1 << 3,
    VECTOR = 1 << 4,
    TOGGLE = 1 << 5,
    TREE = 1 << 6,
    AURA = TOGGLE | AOE,
};

enum class AttackType
{
    MELEE = 0,
    RANGED = 1
};

enum class UnitType
{
    CREEP = 0,
    HERO, // Heroes (have attributes)
    HERO_CREEP, // Higher-level creep summons
    BOSS,
    BUILDING,
    _COUNT
};

enum class UnitTypeFlag
{
    CREEP = 1 << (int)UnitType::CREEP,
    HERO = 1 << (int)UnitType::HERO,
    HERO_CREEP = 1 << (int)UnitType::HERO_CREEP,
    BOSS = 1 << (int)UnitType::BOSS,
    BUILDING = 1 << (int)UnitType::BUILDING
};

#endif //STANDALONE_HEADERS_H
