#ifndef SCENARIO_H
#define SCENARIO_H
#define _KEY_MBP_DOWN 0x102
#define _KEY_MBP_UP 0x103
#define _KEY_MBP_LEFT 0x104
#define _KEY_MBP_RIGHT 0x105

/*
 *    ASCII CRPG - Scenario Header
 *    -------------------------------------------------------
 *    Author:           Renjie Zhu
 *    Student ID:       f17011135 
 *    Test environment: 
 *         - Clang 6.0 i686-pc-windows-msvc (LLVM) Windows
 *         - CLang Apple LLVM version 9.0.0 macOS
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

unsigned int _sys_showScenario(int scenarioType);
unsigned int _tmp_testCursesInit();

#endif