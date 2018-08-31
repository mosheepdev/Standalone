# Addon Info

Each and every Addon must contain this file.

## Examples

Unranked, Ranked, Debug-only example can be found [here](Addon_Info.kv).

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
            "Respect_Party"             "True" // Optional to "False"
            "Script_File"               "Adon.lua"
            "Allowed_In_Debug"          "Yes" // Optional to "Yes" 
            "Twitch_Chat"               "Yes" // Optional to "No"
            "Dedicated_Server"          "Yes" // Optional to "No"
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
            "Respect_Party"             "True"
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
            "Respect_Party"             "True"
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
            "Respect_Party"             "True"
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
Set to `True` for joining party will be matched into same team.

Values can be (not case sensitive):
- `Yes` or `True` = Keep party together
- `No` or `False` = Ignore party (still will try to get the together but not require it)

When not possible
- If joining directly to the lobby, it will try to keep the party in as less teams as possible
- If joining from matchmaking, the lobby will be ignored
  - Cannot search when amount of players exceeds maximum number of players in any team.

### Script File
Initial script file to be called after starting the lobby.

Relative path to Addon's directory.

### Allowed In Debug
Values can be (not case sensitive):
- `Yes` or `True` = Can be played in Debug Mode
- `No` or `False` = **Cannot** be played in Debug Mode
- `Only` = Can **only** be played in Debug Mode

### Twitch Chat
Allows integration with Twitch.

Requires host of the lobby to have Twitch Account linked with the game one.

Values can be (not case sensitive):
- `Yes` or `True` = Allows Twitch API to load for the mode (if available)
- `No` or `False` = Do not allow Twitch API

### Dedicated Servers
Determine where to host the lobby.

Values can be (not case sensitive):
- `Require` or `Dedicated` = Can only be run on Dedicated Server 
- `Yes` or `True` or `Both` = Can be run on both Local and Dedicated Server
- `No` or `False` or `Local` = Can only be run on Local Server

Note: When the Game Mode is set to Dedicated-only and does not have any Dedicated server available, the Game Mode cannot be hosted.
