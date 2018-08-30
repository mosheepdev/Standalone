# Global

`Global` API is different from the rest because it is not called with `Global.` or `Global:` prefix.
All functions are static (does not require instance) because there is no instance of `Global`.

## Functions

### Print
Send message to Standard Output (Console) and append New Line (`\n`) at the end.

Use [`Write(string)`](#Write) instead for not adding `\n`.
```
void Print(string message)
void print(string message)
```

### Print Debug
Same as [`Print(string)`](#Print) but has prefix to determine server and start time from beginning of the match.
```
void PrintDebug(string message)
void printDebug(string message)
void print_debug(string message)
```

### Write
Send message to Standard Output (Console).

Use [`Print(string)`](#Print) instead for adding `\n` to the end.
```
void Write(string message)
void write(string message)
```

### Is Client
Returns `true` if LUA Environment is running on client (has access to GUI and has control over a [`Player`](../Player))

To check for server, use [`IsServer()`](#Is_Server) instead of `!IsClient()`.
```
bool IsClient()
```

### Is Server
Returns `true` if LUA Environment is running on server (dedicated or client hosting a game).
No access to GUI.

To check for client, use [`IsClient()`](#Is_Client) instead of `!IsServer()`.

To check for dedicated server, use [`IsDedicatedServer()`](#Is_Dedicated_Server).
```
bool IsServer()
```

### Is Dedicated Server
Check whenever this game is hosted on dedicated server (not at one of the clients)

Returns false in case of [`IsServer()`](#Is_Server) returning false.
```
bool IsDedicatedServer()
```

### Get Host Player
Get handle to player hosting the game.
Does not work for Dedicated Servers.

Returns `nil` if [`IsDedicatedServer()`](#Is_Dedicated_Server)`== true`. 
```
handle GetHostPlayer()
```

### Get Host Name
Get name of the host (server).

For Dedicated Servers, returns their Human-friendly Codename.
For Local games, returns name of the hosting player.
```
string GetHostName()
```

### Get Match Id
Get Unique ID of this match.

Should be valid by Regex `^[a-zA-Z0-9_\-]+$` (at least 1 of those characters: numbers, letters, underscores, dash).
```
string GetMatchId()
```

### Get Delta Time
Total amount of seconds (usually `<1.0`) from start of previous tick.
```
float GetDeltaTime()
```

### Get System Date
Returns current system's date in format `yyyy/mm/dd` (4 digits of year, 2 digits of month, 2 digits of day).

To get date at start of the match use [`GetMatchDate()`](#Get_Match_Date).
```
string GetSystemDate()
```

### Get System Time
Returns current system's time in format `hh:mm:ss` (2 digits of hour, 2 digits of minutes, 2 digits of seconds).
Uses 24-hours format.

To get time at start of the match use [`GetMatchTime()`](#Get_Match_Time).
```
string GetSystemTime()
```

### Get System DateTime
Returns current systems' date and time stored in a single table.

Keys are:
- For Date
  - `Year`
  - `Month`
  - `MonthName`
  - `Day`
  - `DayOfWeek`
- For Time
  - `Hours`
  - `Minutes`
  - `Seconds`
  - `Milliseconds`
  - `AmPm` - surfix for 12-hours format
    - `="AM"` for `Hours < 12`
    - `="PM"` for `Hours >= 12`
  - `HoursAmPm` - same as `Hours` but 12-hours format
    - `= Hours % 12 == 0 ? 12 : Hours % 12`

To get date and time at start of the match use [`GetMatchDateTime()`](#Get_Match_DateTime) (uses same structure)(uses same structure).
```
table GetSystemDateTime()
```

### Get Match Date
Returns system's date at start of the match in format `yyyy/mm/dd` (4 digits of year, 2 digits of month, 2 digits of day).

For current date use [`GetSystemDate()`](#Get_System_Date).
```
string GetMatchDate()
```

### Get Match Time
Returns system's time at start of the match in format `hh:mm:ss` (2 digits of hour, 2 digits of minutes, 2 digits of seconds).
Uses 24-hours format.

For current time use [`GetSystemTime()`](#Get_System_Time).
```
string GetMatchTime()
```

### Get Match DateTime
Get system's date and time at beginning of the match.

For current date and time use [`GetSystemDateTime()`](#Get_System_DateTime) (uses same structure).
```
table GetMatchDateTime()
```
