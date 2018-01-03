#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "curses.h"
#include "io.h"

/*
 *    ASCII CAVG - IO
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
wchar_t dialogueList[8][128][513];
int chapterLen[2];

void _io_addDNode(int inputChapterNo, int inputDialogueNo, wchar_t* inputContent){
	t->chapterNo = inputChapterNo;
	t->dialogueNo = inputDialogueNo;
	wcscpy(t->dialogueContent, inputContent);
	//addnwstr(inputContent, 1);
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
		int chapter = 0;
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
	_io_initializeConvertToArray();
}

void _io_initializeConvertToArray(){
	dNode* curNode = head;
	/*
	while(curNode != NULL){
		//if(curNode->dialogueContent == NULL)
			//break;
		//addwstr(curNode->dialogueContent);
		//printw("%d, %d", curNode->chapterNo, curNode->dialogueNo);
		//wcscpy(dialogueList[curNode->chapterNo-1][curNode->dialogueNo-1], curNode->dialogueContent);
		//curNode = curNode->pNext;
	}*/
}

wchar_t* _io_getDialogueContent(int chapterNo, int dialogueNo){
	return dialogueList[chapterNo][dialogueNo]; 
}

int _io_getChapterLen(int chapterNo){
	return chapterLen[chapterNo - 1];
}

dNode* _io_getHeadNodePtr(){
	return head;
}