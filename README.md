# steam game overlay (GameOverlayUI.exe) hook example⚡

## vgui2.dll hook example

use any usermode injector to inject into gameoverlayui. then using memory share to render your items.

## screenshot
![demo](https://i.loli.net/2020/03/27/5HgNOzxLbwKks6M.png)

## NOTE

1. hook VGUI_Surface039->**PaintTraverse** to render on screen.

2. source is building on **Visual Studio 2017 Release x86**. not sure about other platform.

3. alloc a free memory to create a shared memory field for communication.

4. the original steam overlay are not support DrawLine or DrawOutlinedCircle and some functions, so in this source DrawLine and **DrawCircle** is based on **DrawFilledRect**.(Bresenham algorithm)

5. do not using too much draw-functions in one loop maybe cause GameOverlayUI.exe crash.

## inject a specific game

1.  on usermode inject `GameOverlayUIHook.dll` from directory `\Release` to `GameOverlayUI.exe`.

## todo
1.  is this can bypass BE/EAC anti-cheat system? the answer is: idk.

2.  this is an example. there are lots of ways to achieve hook PaintTraverse. using veh or other virtual table.
