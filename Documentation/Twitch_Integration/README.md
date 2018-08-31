# Twitch

- [Official Website](https://www.twitch.tv/)
- [Official Documentation](https://dev.twitch.tv/start/)
- [Official GIT](https://github.com/twitchdev/developer-rig)

## Chat
Access to Twitch chat allows host of the game to allow his chat to modify game behavior.

Users in chat can trigger special events (rewards).
In official Angel Arena, it can be bonus reward for winner of duels (Gold, Cores...).

To access [Twitch's Chat](https://dev.twitch.tv/docs/irc/), they provide it as [IRC](https://en.wikipedia.org/wiki/Internet_Relay_Chat) Channel.

## Technical Details

- Maxmimum Message Length
  - 512 characters with CRLF (`\r\n`)
  - 510 characters without CRLF (`\r\n`)
  - 513 characters with CRLF (`\r\n`) and `\0` 