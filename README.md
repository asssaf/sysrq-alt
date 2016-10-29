# sysrq-alt
Assign SysRq button to an alternative scancode using EVIOCSKEYCODE, useful for keyboards without SysRq (e.g. macbooks)

## Usage
```
Usage: sysrq -d device -s scancode

  -d            keyboard event input device
  -s            decimal scan code

Example:

  $ sysrq \
    -d /dev/input/by-id/usb-Apple_Inc._Apple_Internal_Keyboard___Trackpad_XXXXXX-if01-event-kbd \
    -s 458979

458979 (0x700e3) is the scancode obtained for the left cmd key
You can get getscancodes source at: http://keytouch.sourceforge.net/dl-getscancodes.php
```
