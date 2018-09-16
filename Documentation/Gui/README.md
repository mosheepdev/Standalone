# Gui

## XML Elements

### Gui
```xml
<Gui ScriptClass="" StyleFile="">

</Gui>
```
Root element. Do not use it anywhere else.

Can have attributes `ScriptClass` and `StyleFile` to define interaction scripts and appearance.
This can also be extended by `<Script />` and `<Style />` elements.

### Script
```xml
<Script ScriptClass="" />
```
Add LUA script file to affect whole functionality.

All child nodes are ignored.

### Style
```xml
<Style StyleFile="" />
```
Add CSS file to affect whole design.

All child nodes are ignored.

### Panel
```xml
<Panel>

</Panel>
```
Equivalent to HTML's `div`.

### Button

### Text

### Numeric
```xml
<Numeric Decimal="0" Min="0" Max="10" Step="1" Value="0"/>
```

### Slider
```xml
<Slider Decimal="0" Min="0" Max="10" Step="1" Value="0" />
```

### Double Slider
```xml
<DoubleSlider Decimal="0" Min="0" Max="10" Step="1" LeftValue="0" RightValue="10" />
```

### Image

### Chat

### Ability Icon

### Hero Icon

### Hero Preview

### Hero Portrait

### Ability

### Bar
Those bars are used for Health and Mana.

### Inventory Slot

### Item
Both as buyable (not owned) or child of `<InventorySlot />`
