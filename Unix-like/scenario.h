#ifndef SCENARIO_H
#define SCENARIO_H
#define _KEY_MBP_DOWN 0x102
#define _KEY_MBP_UP 0x103
#define _KEY_MBP_LEFT 0x104
#define _KEY_MBP_RIGHT 0x105
#include <time.h>

/*
 *    ASCII CAVG - Scenario Header
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

/* System Functions */
unsigned int _sys_initialize(int* _G_SYS_RES_Y, int* _G_SYS_RES_X);
unsigned int _sys_showScenario(int scenarioType, int* _G_SYS_RES_Y, int* _G_SYS_RES_X);
unsigned int _sys_mainScenario();

/* Scenario Functions  */
int _scene_title();
int _scene_start();
int _scene_load();
int _scene_exit();
/*  */
unsigned int _tmp_testCursesInit();

#endif