# Gui

## XML Elements

### Gui
```xml
<Gui scriptClass="" styleFile="">

</Gui>
```
Root element. Do not use it anywhere else.

Can have attributes `scriptClass` and `styleFile` to define interaction scripts and appearance.
This can also be extended by `<Script />` and `<Style />` elements.

### Script
```xml
<Script scriptClass="" />
```
Add LUA script file to affect whole functionality.

All child nodes are ignored.

### Style
```xml
<Style styleFile="" />
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
