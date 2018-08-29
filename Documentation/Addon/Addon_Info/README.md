# Addon Info

Each and every Addon must contain this file.

## Examples

### Default

```
"Addon_Info"
{
    "Name"                              "Addon Info Example"
    "Game_Modes"
    {
        "Default"
        {
            "Teams"
            {
                "Angels"                "5"
                "Demons"                "5"
            }
            "Map"                       "default"
            "Respect_Party"             "True" // Optional to false
            "Script_File"               "Adon.lua"
        }
    }
}
```

### 10 vs 10
```
"Addon_Info"
{
    "Name"                              "Addon Info Example"
    "Game_Modes"
    {
        "10 vs 10"
        {
            "Teams"
            {
                "Angels"                "10"
                "Demons"                "10"
            }
            "Map"                       "10v10"
            "Respect_Party"             "True" // Optional to false
        }
    }
}
```

### 5 vs 5 vs 5 vs 5
```
"Addon_Info"
{
    "Name"                              "Addon Info Example"
    "Game_Modes"
    {
        "5 vs 5 vs 5 vs 5"
        {
            "Teams"
            {
                "North"                 "5"
                "South"                 "5"
                "West"                  "5"
                "East"                  "5"
            }
            "Map"                       "5v5v5v5"
            "Respect_Party"             "True" // Optional to false
        }
    }
}
```

### 1v5
```
"Addon_Info"
{
    "Name"                              "Addon Info Example"
    "Game_Modes"
    {
        "1 vs 5"
        {
            "Teams"
            {
                "Angels"                "1"
                "Demons"                "5"
            }
            "Map"                       "1v10"
            "Respect_Party"             "True" // Optional to false
        }
    }
}
```

## Values

## Name
Display name of this Addon.

**Cannot be translated.**

## Game Modes
List of all game modes.
`Keys` are used as display names for them (and reference to LUA).

**Cannot be translated.**

**Cannot contain non-ASCII characters.**

Each Game Mode must contain `"Teams"` and `"Map"` to be valid.
Addons with no valid Game Mode cannot be played.

There can be additional optional keys specified (listed below).
Also supports custom keys (accessable from init function).

### Teams
`Key` is name of the team (both Display Name and reference in LUA).

Total amount of players (`Value`) define maximum players in the lobby (+possible dedicated server).

**Cannot be translated.**

**Cannot contain non-ASCII characters.**

### Map
Specifies name of map/level to load players into.

**Cannot be translated.**

**Cannot contain non-ASCII characters.**

### Respect Party
Set to `true` (or `True` or `TRUE`) for joining party will be matched into same team.

When not possible
- If joining directly to the lobby, it will try to keep the party in as less teams as possible
- If joining from matchmaking, the lobby will be ignored
  - Cannot search when amount of players exceeds maximum number of players in any team.

### Script_File 