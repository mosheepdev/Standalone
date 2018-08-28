#ifndef STANDALONE_HEADERS_H
#define STANDALONE_HEADERS_H

enum DamageType
{
    DAMAGE_PURE = 0,
    DAMAGE_PHYSICAL = 1,
    DAMAGE_MAGICAL = 2
};

enum Attribute
{
    // Health
    // Health Regeneration Amplification
    // Status Resistance
    ATTRIBUTE_STRENGTH = 0,
    // Armor = Physical Resistance
    // Movement Speed
    // Attack Speed
    ATTRIBUTE_AGILITY = 1,
    // Mana
    // Mana Regeneration Amplification
    // Spell Amplification
    ATTRIBUTE_INTELLIGENCE = 2,
    // Cooldown Reduction
    // Cast Range Increase
    // Magic Resistance
    ATTRIBUTE_CHARISMA = 3
};

enum Team : unsigned int
{
    TEAM_NEUTRAL = 0,
    TEAM_ANGELS = 1, // Radiant
    TEAM_DEMONS = 2, // Dire
    //TEAM_0 = TEAM_NEUTRAL, // Neutrals, better not provide for confusion
    TEAM_1 = TEAM_ANGELS,
    TEAM_2 = TEAM_DEMONS,
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
    TEAM_25 = 25
    // must be < 32 for Team_Flags to be maximum of 1 << 31 to fit into int
};

enum Team_Flags : unsigned int
{
    TEAM_FILTER_ANY = 0,
    TEAM_FILTER_NEUTRAL = 1 << TEAM_NEUTRAL,
    TEAM_FILTER_ANGELS = 1 << TEAM_ANGELS,
    TEAM_FILTER_DEMONS = 1 << TEAM_DEMONS,
    TEAM_FILTER_1 = TEAM_FILTER_ANGELS,
    TEAM_FILTER_2 = TEAM_FILTER_DEMONS,
    TEAM_FILTER_3 = 1 << TEAM_3,
    TEAM_FILTER_4 = 1 << TEAM_4,
    TEAM_FILTER_5 = 1 << TEAM_5,
    TEAM_FILTER_6 = 1 << TEAM_6,
    TEAM_FILTER_7 = 1 << TEAM_7,
    TEAM_FILTER_8 = 1 << TEAM_8,
    TEAM_FILTER_9 = 1 << TEAM_9,
    TEAM_FILTER_10 = 1 << TEAM_10,
    TEAM_FILTER_11 = 1 << TEAM_11,
    TEAM_FILTER_12 = 1 << TEAM_12,
    TEAM_FILTER_13 = 1 << TEAM_13,
    TEAM_FILTER_14 = 1 << TEAM_14,
    TEAM_FILTER_15 = 1 << TEAM_15,
    TEAM_FILTER_16 = 1 << TEAM_16,
    TEAM_FILTER_17 = 1 << TEAM_17,
    TEAM_FILTER_18 = 1 << TEAM_18,
    TEAM_FILTER_19 = 1 << TEAM_19,
    TEAM_FILTER_20 = 1 << TEAM_20,
    TEAM_FILTER_21 = 1 << TEAM_21,
    TEAM_FILTER_22 = 1 << TEAM_22,
    TEAM_FILTER_23 = 1 << TEAM_23,
    TEAM_FILTER_24 = 1 << TEAM_24,
    TEAM_FILTER_25 = 1 << TEAM_25
};

enum PurgeType
{
    PURGE_NONE = 0,
    PURGE_SOFT = 1,
    PURGE_HARD = 2,
    PURGE_RESPAWN = 3 // Some modifiers may not want to be purged but want to disappear on death
};

enum DamageFlags
{
    DAMAGE_FLAGS_NONE = 0,
    DAMAGE_FLAGS_NO_ARMOR,
    DAMAGE_FLAGS_NO_MAGIC_RESIST,
    DAMAGE_FLAGS_NO_DAMAGE_BLOCK,
    DAMAGE_FLAGS_NON_LETHAL,
    DAMAGE_FLAGS_REFLECTION,
};

enum TypeFilter
{

};

enum FlagFilter
{

};

enum FindOrder
{
    FIND_ORDER_ANY = 0,
    FIND_ORDER_CLOSEST = 1,
    FIND_ORDER_FARTHEST = 2,
    FIND_ORDER_RANDOMIZED = 3
};

enum ModifierPriority
{
    MODIFIER_PRIORITY_MINIMAL     = -3,
    MODIFIER_PRIORITY_LOWEST      = -2,
    MODIFIER_PRIORITY_LOW         = -1,
    MODIFIER_PRIORITY_NORMAL      = 0, // Normal, should be default value
    MODIFIER_PRIORITY_HIGH        = 1,
    MODIFIER_PRIORITY_ULTRA       = 2,
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

    MODIFIER_FLAG_ABILITY_STOP_COOLDOWN = 1 << 6,
    MODIFIER_FLAG_ABILITY_NO_COOLDOWN = 1 << 7,
    MODIFIER_FLAG_ABILITY_NO_MANA = 1 << 8,
    MODIFIER_FLAG_ABILITY_NO_GOLD = 1 << 9,
    MODIFIER_FLAG_ABILITY_GLOBAL = 1 << 10,

    MODIFIER_FLAG_IMMUNITY_MAGIC = 1 << 11,
    MODIFIER_FLAG_IMMUNITY_PHYSICAL = 1 << 12,
    MODIFIER_FLAG_IMMUNITY_ALL = 1 << 13,

    MODIFIER_FLAG_INVISIBLE = 1 << 14,
    MODIFIER_FLAG_INVISIBLE_RAW = 1 << 15,

    MODIFIER_FLAG_ATTACK_GLOBAL = 1 << 16,
    MODIFIER_FLAG_ATTACK_UNABLE = 1 << 17
};

enum AbilityTargetting
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

#endif //STANDALONE_HEADERS_H
