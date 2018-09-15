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
    NO_ARMOR, // Ignore armor
    NO_MAGIC_RESIST, // Ignore magic resistance
    NO_DAMAGE_BLOCK, // Ignore damage block
    NON_LETHAL, // Cannot kill target
    REFLECTION, // Is reflection damage (cannot be reflected)
    _COUNT
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

enum TypeFilter
{

};

enum FlagFilter
{

};

enum FindOrder
{
    FIND_ORDER_RANDOMIZED = 0,
    FIND_ORDER_CLOSEST = 1,
    FIND_ORDER_FARTHEST = 2,
    FIND_ORDER_ANY = 3, // Ordered by internal order
};

enum ModifierPriority
{
    MODIFIER_PRIORITY_MINIMAL = -3,
    MODIFIER_PRIORITY_LOWEST = -2,
    MODIFIER_PRIORITY_LOW = -1,
    MODIFIER_PRIORITY_NORMAL = 0, // Normal, should be default value
    MODIFIER_PRIORITY_HIGH = 1,
    MODIFIER_PRIORITY_ULTRA = 2,
    MODIFIER_PRIORITY_SUPER_ULTRA = 3
};

enum ModifierFlags : unsigned int
{
    MODIFIER_FLAG_NONE = 0,

    MODIFIER_FLAG_STATUS_STUN = 1 << 0, // Cannot do anything
    MODIFIER_FLAG_STATUS_ROOT = 1 << 1, // Cannot move (and cast some abilities)
    MODIFIER_FLAG_STATUS_SILENCE = 1 << 2, // No casting of abilities
    MODIFIER_FLAG_STATUS_MUTE = 1 << 3, // No casting of items
    MODIFIER_FLAG_STATUS_BREAK = 1 << 4, // No passives (abilities and items)
    MODIFIER_FLAG_STATUS_HIDDEN = 1 << 5, // Out of game - cannot be targeted

    MODIFIER_FLAG_ABILITY_STOP_COOLDOWN = 1 << 6, // No cooldown progress on abilities
    MODIFIER_FLAG_ABILITY_NO_COOLDOWN = 1 << 7, // No ability cost cooldown
    MODIFIER_FLAG_ABILITY_NO_MANA = 1 << 8, // No ability cost mana
    MODIFIER_FLAG_ABILITY_NO_GOLD = 1 << 9, // No ability cost gold

    MODIFIER_FLAG_IMMUNITY_MAGIC = 1 << 10, // Cannot take magic damage
    MODIFIER_FLAG_IMMUNITY_PHYSICAL = 1 << 11, // Cannot take physical damage
    MODIFIER_FLAG_IMMUNITY_PURE = 1 << 12, // Cannot take pure damage
    MODIFIER_FLAG_IMMUNITY_ALL = 1 << 13, // Cannot take damage
    MODIFIER_FLAG_IMMUNITY_DEATH = 1 << 14, // Cannot die
    MODIFIER_FLAG_IMMUNITY_HEAL = 1 << 15, // Cannot be healed

    MODIFIER_FLAG_INVISIBLE = 1 << 16, // Cannot be seen by enemies, can be revealed
    MODIFIER_FLAG_INVISIBLE_RAW = 1 << 17, // Cannot be seen by enemies, cannot be revealed

    MODIFIER_FLAG_ATTACK_GLOBAL = 1 << 18, // Has global attack
    MODIFIER_FLAG_ATTACK_UNABLE = 1 << 19, // Cannot attack
};

enum AbilityTargeting
{
    ABILITY_TARGETTING_PASSIVE = 0,
    ABILITY_TARGETTING_NONE = 1 << 0,
    ABILITY_TARGETTING_POINT = 1 << 1,
    ABILITY_TARGETTING_UNIT = 1 << 2,
    ABILITY_TARGETTING_AOE = 1 << 3,
    ABILITY_TARGETTING_AURA = ABILITY_TARGETTING_PASSIVE | ABILITY_TARGETTING_AOE,
    ABILITY_TARGETTING_VECTOR = 1 << 4,
    ABILITY_TARGETTING_ATTACK = 1 << 5,
    ABILITY_TARGETTING_TREE = 1 << 6
};

enum AttackType
{
    ATTACK_TYPE_MELEE = 0,
    ATTACK_TYPE_RANGED = 1
};

#endif //STANDALONE_HEADERS_H
