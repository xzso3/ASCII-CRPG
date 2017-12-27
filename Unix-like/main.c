#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>            // Library ncurses (For Unix-like OS)
//#include <curses.h>           // Library PDcurses (For Windows OS)
#define _KEY_ACTION_ESC 0x1B
#define _KEY_ACTION_UP 0x77
#define _KEY_ACTION_DOWN 0x73
#define _KEY_ACTION_LEFT 0x61
#define _KEY_ACTION_RIGHT 0x64
#define _KEY_ACTION_ENTER 0x0D

/*
 *    ASCII CRPG - Main Program Entrance
 *    -------------------------------------------------------
 *    Author:           Renjie Zhu
 *    Student ID:       f17011135 
 *    Test environment: 
 *         - Clang 6.0 i686-pc-windows-msvc (LLVM) Windows
 *         - CLang Apple LLVM version 9.0.0 macOS
 *                      
 *    Adapted OS:       Windows
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
    _sys_showScenario(0);
    

    return 0;
}
