#ifndef SCENARIO_H
#define SCENARIO_H

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

/* System Functions */
int _sys_initialize(int* _G_SYS_RES_Y, int* _G_SYS_RES_X);
int _sys_showScenario(int scenarioType, int _G_SYS_RES_Y, int _G_SYS_RES_X);
int _sys_mainScenario();
int _sys_canvasPrint(char** canvas);

/* Scenario Functions */
int _scene_titleMenu(int _G_SYS_RES_Y, int _G_SYS_RES_X);
int _scene_titleStart();
int _scene_titleLoad();
int _scene_titleExit(int _G_SYS_RES_Y, int _G_SYS_RES_X);
int _scene_controller(int chapterNumber, int chapterProgress);
int _scene_chapterTitleDisplay(int chapterNumber);
int _scene_chapterContentDisplay(int chapterNumber, int chapterProgress);

/*
	ONE CHARPTER CHARTFLOW

	SHOW THE CHAPTER TITLE
	>>
	PLAY THE CONTENT
*/


/* Temporary Functions */
int _tmp_testCursesInit();

#endif