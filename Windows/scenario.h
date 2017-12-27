#ifndef SCENARIO_H
#define SCENARIO_H
#define _KEY_MBP_DOWN 0x102
#define _KEY_MBP_UP 0x103
#define _KEY_MBP_LEFT 0x104
#define _KEY_MBP_RIGHT 0x105
#include <time.h>

/*
 *    ASCII CRPG - Scenario Header
 *
 *    Current Version : For Windows    
 *
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

unsigned int _sys_initialize(int* _G_SYS_RES_Y, int* _G_SYS_RES_X);
unsigned int _sys_showScenario(int scenarioType, int* _G_SYS_RES_Y, int* _G_SYS_RES_X);
unsigned int _sys_mainScenario();
unsigned int _tmp_testCursesInit();


#endif