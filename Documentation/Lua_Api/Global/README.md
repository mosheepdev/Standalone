# Global

`Global` API is different from the rest because it is not called with `Global.` or `Global:` prefix.
All functions are static (does not require instance) because there is no instance of `Global`.

## Functions

### Print

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void Print(string message)
void print(string message)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Send message to Standard Output (Console) and append New Line (`\n`) at the end.<br>
            <br>
            Use `Write(string)` instead for not adding `\n`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void PrintDebug(string message)
void printDebug(string message)
void print_debug(string message)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Same as `Print(string)` but has prefix to determine server and start time from beginning of the match.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void Write(string message)
void write(string message)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Send message to Standard Output (Console).<br>
            <br>
            Use `Print(string)` instead for adding `\n` to the end.
        </td>
        <td></td>
    </tr>
</table>

### Side

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>bool IsClient()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns `true` if LUA Environment is running on client (has access to GUI and has control over a [`Player`](../Player/README.md))<br>
            <br>
            To check for server, use `IsServer()` instead of `!IsClient()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool IsServer()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns `true` if LUA Environment is running on server (dedicated or client hosting a game).
            No access to GUI.<br>
            <br>
            To check for client, use `IsClient()` instead of `!IsServer()`.<br>
            <br>
            To check for dedicated server, use `IsDedicatedServer()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>bool IsDedicatedServer()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Check whenever this game is hosted on dedicated server (not at one of the clients).<br>
            <br>
            Returns false in case of `IsServer()` returning false.
        </td>
        <td></td>
    </tr>
</table>

### Host

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>handle GetHostPlayer()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get handle to player hosting the game.<br>
            Does not work for Dedicated Servers.<br>
            <br>
            Returns `nil` if `IsDedicatedServer() == true`. 
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetHostName()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get name of the host (server).<br>
            <br>
            For Dedicated Servers, returns their Human-friendly Codename.<br>
            For Local games, returns name of the hosting player.
        </td>
        <td></td>
    </tr>
</table>

### Match

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>string GetMatchId()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get Unique ID of this match.<br>
            <br>
            Should be valid by Regex `^[a-zA-Z0-9_\-]+$` (at least 1 of those characters: numbers, letters, underscores, dash).
        </td>
        <td></td>
    </tr>
</table>

### Date and Time

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>float GetDeltaTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Total amount of seconds (usually `<1.0`) from start of previous tick.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetSystemDate()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns current system's date in format `yyyy/mm/dd` (4 digits of year, 2 digits of month, 2 digits of day).<br>
            <br>
            To get date at start of the match use `GetMatchDate()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetSystemTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns current system's time in format `hh:mm:ss` (2 digits of hour, 2 digits of minutes, 2 digits of seconds).<br>
            Uses 24-hours format.<br>
            <br>
            To get time at start of the match use `GetMatchTime()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>table GetSystemDateTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns current systems' date and time stored in a single table.<br>
            <br>
            Keys are:
            <ul>
                <li>
                    For Date
                    <ul>
                        <li>`Year`</li>
                        <li>`Month`</li>
                        <li>`MonthName`</li>
                        <li>`Day`</li>
                        <li>`DayOfWeek`</li>
                    </ul>
                </li>
                <li>
                    For Time
                    <ul>
                        <li>`Hours`</li>
                        <li>`Minutes`</li>
                        <li>`Seconds`</li>
                        <li>`Milliseconds`</li>
                        <li>
                            `AmPm` - surfix for 12-hours format
                            <ul>
                                <li>`="AM"` for `Hours < 12`</li>
                                <li>`="PM"` for `Hours >= 12`</li>
                            </ul>
                        </li>
                        <li>
                            `HoursAmPm` - same as `Hours` but 12-hours format
                            <ul>
                                <li>`= Hours % 12 == 0 ? 12 : Hours % 12`</li>
                            </ul>
                        </li>
                    </ul>
                </li>
            </ul>
            <br>
            To get date and time at start of the match use `GetMatchDateTime()` (uses same structure).
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetMatchDate()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns system's date at start of the match in format `yyyy/mm/dd` (4 digits of year, 2 digits of month, 2 digits of day).</br>
            <br>
            For current date use `GetSystemDate()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>string GetMatchTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Returns system's time at start of the match in format `hh:mm:ss` (2 digits of hour, 2 digits of minutes, 2 digits of seconds).<br>
            Uses 24-hours format.<br>
            <br>
            For current time use `GetSystemTime()`.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>table GetMatchDateTime()</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get system's date and time at beginning of the match.<br>
            <br>
            For current date and time use `GetSystemDateTime()` (uses same structure).
        </td>
        <td></td>
    </tr>
</table>

### Script Init

Can be considered constructors but returns same `Dummy Instance` for same `name`.

`Dummy Instance` should not be used for calling any function (should only define them).
Reason is that `Dummy Instance` has no `Owner` (`GetOwner() == nil`).

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>table Ability(string name)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get or create [Ability](../Ability/README.md) by its name.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>table Item(string name)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get or create [Item](../Item/README.md) by its name.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>table Modifier(string name)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Get or create [Modifier](../Modifier/README.md) by its name.
        </td>
        <td></td>
    </tr>
</table>

### Linking

`LinkAbility(...)` and `LinkItem(...)` should be called from `Addon.lua` (or other `"Script_File"` from [Addon_Info.kv](../../Addon/Addon_Info/README.md)). 

If `path` ends with `.lua` it is considered a LUA Script.
`path` ending by any other extension (`.kv` and `.txt` are preferred) is considered to be KV File storing values for it.

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void LinkAbility(string name, string path)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void LinkItem(string name, string path)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void LinkModifier(string name, string path)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Can also be called in Ability's (or Item's) code.<br>
            <br>
            No need to call when the LUA file was already called - when Ability (or Item) share LUA file with their Modifiers.<br>
            <br>
            No nee for KeyValue files for Modifiers.
        </td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void LinkUnit(string name, string path)</pre>
        </td>
        <td>
            Both
        </td>
        <td>
            Cannot link LUA code - will print error into Console but throw no exception.
        </td>
        <td></td>
    </tr>
</table>

#### Default

Those directories are linked by default.
There is no other way to link directories.

All directories below start from Addon's base directory.

<table>
    <tr>
        <th>Type</th>
        <th>Directories</th>
    </tr>
    <tr>
        <td>
            Ability
        </td>
        <td>
            <pre>/Scripts/Ability/*.lua
/Scripts/Unit/*/Ability/*.lua
/Scripts/Hero/*/Ability/*.lua
/Scripts/Boss/*/Ability/*.lua</pre>
            <pre>/KeyValue/Ability/*.kv
/KeyValue/Ability/*.txt
/KeyValue/Unit/*/Ability/*.kv
/KeyValue/Unit/*/Ability/*.txt
/KeyValue/Hero/*/Ability/*.kv
/KeyValue/Hero/*/Ability/*.txt
/KeyValue/Boss/*/Ability/*.kv
/KeyValue/Boss/*/Ability/*.txt</pre>
        </td>
    </tr>
    <tr>
        <td>
            Item
        </td>
        <td>
            <pre>/Scripts/Items/*.lua</pre>
            <pre>/KeyValue/Items/*.kv
/KeyValue/Items/*.txt</pre>
        </td>
    </tr>
    <tr>
        <td>
            Modifier
        </td>
        <td>
            <pre>/Scripts/Modifier/*.lua</pre>
            <pre>/KeyValue/Modifier/*.kv
/KeyValue/Modifier/*.txt</pre>
        </td>
    </tr>
    <tr>
        <td>
            Unit
        </td>
        <td>
            <pre>/KeyValue/Units/*.kv
/KeyValue/Units/*.txt</pre>
        </td>
    </tr>
</table>

To link default abilities, items, modifiers and units, there are 2 groups of functions.

All default abilities (and items) have their modifiers referenced (or even implemented) in respective LUA file.
Therefore, `LinkDefault___Modifier(string)` and `LinkDefault___Modifiers()` will not link them.

<table>
    <tr>
        <th>Definition</th>
        <th>Side</th>
        <th>Description</th>
        <th>Implemented as</th>
    </tr>
    <tr>
        <td>
            <pre>void LinkDefaultMoba()
void LinkDefaultMobaAbilities()
void LinkDefaultMobaAbility(string name)
void LinkDefaultMobaItems()
void LinkDefaultMobaItem(string name)
void LinkDefaultMobaModifiers()
void LinkDefaultMobaModifier(string name)
void LinkDefaultMobaUnits()
void LinkDefaultMobaUnit(string name)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>
            <pre>void LinkDefaultAngelArena()
void LinkDefaultAngelArenaAbilities()
void LinkDefaultAngelArenaAbility(string name)
void LinkDefaultAngelArenaItems()
void LinkDefaultAngelArenaItem(string name)
void LinkDefaultAngelArenaModifier()
void LinkDefaultAngelArenaModifier(string name)
void LinkDefaultAngelArenaUnits()
void LinkDefaultAngelArenaUnit(string name)</pre>
        </td>
        <td>
            Both
        </td>
        <td></td>
        <td></td>
    </tr>
</table>