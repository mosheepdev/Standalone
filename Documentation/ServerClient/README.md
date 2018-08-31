# Server / Client

## Client
- Runs GUI
- Allows interactions
- Owns 1 instance of [`Player`](../Lua_Api/Player/README.md)

## Server

### Local
- Started after start of the lobby (when not connecting to dedicated server)
  
### Dedicated
- Running all the time with a specified game (and Game Mode)
- May start both password-protected and public lobby
- Can be controlled from Console
  
#### Name Pool

```
FooBar
Skynet
Wooden Box
Datapoint
```