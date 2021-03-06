#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <wchar.h>

/*
 *    ASCII CAVG - IO Header
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
typedef struct dialCData{
	int chapterNo;
	int dialogueNo;
	wchar_t dialogueContent[513];
	struct dialCData* pNext;
}dNode;

void _io_addDNode(int, int, wchar_t*);
void _io_getDialogueScript();
void _io_initializeScript();
void _io_initializeConvertToArray();

int _io_getChapterLen(int); 

dNode* _io_getHeadNodePtr();

wchar_t* _io_getDialogueContent(int, int);

#endif