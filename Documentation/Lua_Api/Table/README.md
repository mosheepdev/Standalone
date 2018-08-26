# Table

All indices start at `0` and __not__ `1` as is common for most LUA implementations.

## Insert
```
void Table:Insert(table table, object element)
void Table:Insert(table table, int index, object element)
```

## Sort
```
void Table:Sort(table table)
void Table:Sort(table table, function comparer)
```
Usage
```
Table:Sort(table, function(item0, item1)
    return item0 < item1
end)
```

## Remove
Remove last (or specified) element. Shifting following elements when necessary.
Returns value of removed element.
```
object Table:Remove(table table)
object Table:Remove(table table, int index)
```

## Max Number
Returns maximum numeric key or `0` when none found.
```
int Table:MaxN(table table)
```

## Concat
```
int Table:Concat(table table)
int Table:Concat(table table, string separator)
int Table:Concat(table table, string separator, int startIndex)
int Table:Concat(table table, string separator, int startIndex, int endIndex)
```
### Arguments
- `separator` = `""`
- `startIndex` = `0`
- `endIndex` = `Table:MaxN(table)`
