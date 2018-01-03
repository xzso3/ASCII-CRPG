#ifndef SCENARIO_H
#define SCENARIO_H
#include "curses.h"
/*
 *    ASCII CAVG - Scenario Header
 *
 *    Current Version : For Windows    
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
#define SPC 0x20
/* System Functions */
int 	_sys_initialize(int*, int* );
int 	_sys_showScenario(int, int, int);
int 	_sys_mainScenario();
int 	_sys_canvasPrint(WINDOW*, char**);

/* Scenario Functions */
int 	_scene_titleMenu(int, int);
int 	_scene_titleStart();
int 	_scene_titleLoad();
int 	_scene_titleExit(int, int);
int 	_scene_controller(int, int);
int 	_scene_chapterTitleDisplay(int);
int 	_scene_chapterDialogueDisplay(WINDOW*, int, int);

/* Temporary Functions */
int _tmp_testCursesInit();

#endif