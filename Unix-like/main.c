#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>            // Library ncurses (For Unix-like OS)
//#include <curses.h>         // Library PDcurses (For Windows OS)
#include "scenario.h"  
#include "io.h"

#define _KEY_ACTION_ESC 0x1B
#define _KEY_ACTION_UP 0x77
#define _KEY_ACTION_DOWN 0x73
#define _KEY_ACTION_LEFT 0x61
#define _KEY_ACTION_RIGHT 0x64
#define _KEY_ACTION_ENTER 0x0D

/*
 *    ASCII CAVG - Main Program Entrance
 *
 *    Current Version : For Unix-like OS    
 *
 *    -------------------------------------------------------
 *    Author:           Renjie Zhu
 *    Student ID:       f17011135 
 *    Test environment: 
 *         Compiler:
 *         - Clang 6.0 i686-pc-windows-msvc (LLVM) Windows
 *         - CLang Apple LLVM version 9.0.0 macOS
 *         Test OS Env:
 *         - macOS 10.13.1 
 *         - Windows 7 (x64) Utimate SP1 Build 7601
 *         - Windows 10 Pro Version 1709 Build 16299.125
 *                      
 *    Adapted OS:       Universal
 *    -------------------------------------------------------
 *    License:      GPL-v2
 *    
 *    Used Extensive Library:
 *    - (Windows)       Public Domain Curses
 *    - (Unix-Like)     New Curses
 * 
 * 
 */


int main(){

    // Display the menu scenario.
    int _sys_resY, _sys_resX;
    _sys_initialize(&_sys_resY, &_sys_resX);
    _sys_showScenario(0, &_sys_resY, &_sys_resX);
    _sys_showScenario(666, &_sys_resY, &_sys_resX);
    

    return 0;
}
