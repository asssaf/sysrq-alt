# sysrq-alt
Assign SysRq button to an alternative scancode using EVIOCSKEYCODE, useful for keyboards without SysRq (e.g. macbooks)

## Why is this needed?
Activating the Magic SysRq facility in linux requires the SysRq button (or Pause) using the alt+SysRq+h key combination. However, the SysRq button just doesn't exist in some keyboard, notably the macbook's keyboard. 

Using the EVIOCSKEYCODE an alternative key's scancode can be assigned to the SysRq key (normally 99).

Once this command is executed (probably in startup scripts) the Magic SysRq facility can be used with the alternative combination (I like using the left command button as SysRq, and so alt+left cmd+h to activate magic SysRq). This way I can still use the left cmd key for other uses in X by assigning global shortcuts to it in my window manager (e.g. for cut&paste).

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

## Installing
Releases are here: https://github.com/asssaf/sysrq-alt/releases

Source can compiled with make and make install with the supplied Makefile. There's also an ebuild for gentoo in the contrib directory.

```
  $ make && make -n prefix=/usr/local install
```
    
