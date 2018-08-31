# Discord

- [Official Website](https://discordapp.com)
- [Official Documentation](https://discordapp.com/developers/docs/rich-presence/how-to)
- [Official GIT](https://github.com/discordapp/discord-rpc)

## Callback functions

- `ready(const DiscordUser* request)`
- `disconnected(int errorCode, const char* message)`
- `errored(int errorCode, const char* message)`
- `joinGame(const char* joinSecret)`
- `spectateGame(const char* spectateSecret)`
- `joinRequest(const DiscordUser* request)`

## Approval
Approval is only needed to display `Ask to Join` and `Spectate` buttons.

Official [How to get Approval](https://discordapp.com/developers/docs/rich-presence/getting-approved).

`Ask to Join` would be nice feature for joining parties.

`Spactate` is bad for non-dedicated servers and even Dedicated servers would need extended support to get over predefined amount of spectators.

## Display Data

- `state` (`char*`, max 128 bytes) = the user's current party status
- `details` (`char*`, max 128 bytes) = what the player is currently doing
- `startTimestamp` (`int64_t`) = epoch seconds for game start - including will show time as "elapsed"
- `endTimestamp` (`int64_t`) = epoch seconds for game end - including will show time as "remaining"
- `largeImageKey` (`char*`, max 32 bytes) = name of the uploaded image for the large profile artwork
- `largeImageText` (`char*`, max 128 bytes) = tooltip for the `largeImageKey`
- `smallImageKey` (`char*`, max 32 bytes) = name of the uploaded image for the small profile artwork
- `smallImageText` (`char*`, max 128 bytes) = tootltip for the `smallImageKey`
- `partyId` (`char*`, max 128 bytes) = id of the player's party, lobby, or group
- `partySize` (`int`) = current size of the player's party, lobby, or group
- `partyMax` (`int`) = maximum size of the player's party, lobby, or group
- `joinSecret` (`char*`, max 128 bytes) = unique hashed string for chat invitations and `Ask to Join`
- `spectateSecret` (`char*`, max 128 bytes) = unique hashed string for `Spectate` button

### Expected Usage

- `largeImage` = Icon of the custom game or Standalone Logo (when not in game or lobby)
- `smallImage` = Standalone icon or nothing (when `largeImage` has Standalone logo)
- `startTimestamp` = Start of the match
- `endTimestamp` = End of the match, if the match has time limit (hides `startTimestamp`)
- `partySize`, `partyMax`, `partyId` = Lobby and its info (current players + max players)
- `state` = `Main Menu`, `Main Menu (Party)`, `In Lobby`, `Playing Solo`, `Playing In Party`
- `details` = Custom Game + map (separated by ` | `)
