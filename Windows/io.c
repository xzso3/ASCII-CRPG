#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "io.h"

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

dNode* head ;
dNode* t;
int chapterLen[2];

void _io_addDNode(int inputChapterNo, int inputDialogueNo, wchar_t* inputContent){
	t->chapterNo = inputChapterNo;
	t->dialogueNo = inputDialogueNo;
	wcscpy(t->dialogueContent, inputContent);
	t->pNext = malloc(sizeof(dNode));
	t = t->pNext;
	t->pNext = NULL;
}

void _io_initializeScript(){
	FILE* fStream;
	wchar_t line[513];
	if(_wfopen_s(&fStream, L"data\\scripts\\main.tss", L"r") == 0){

		chapterLen[0] = 0;
		chapterLen[1] = 0;
		int chapter = 1;
		head = malloc(sizeof(dNode));
		head->pNext = NULL;
		t = head;
		while(fgetws(line, 256, fStream) != NULL)
		{
			if(wcscmp(line, L"#SCENE\n") != 0){
				chapterLen[chapter - 1]++;
				_io_addDNode(chapter, chapterLen[chapter - 1], line);
			}else{
				chapter++;
			}
			
		}
		
	}
}

int _io_getChapterLen(int chapterNo){
	return chapterLen[chapterNo - 1];
}

dNode* _io_getHeadNodePtr(){
	return head;
}