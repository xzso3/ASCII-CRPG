#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>            // Library ncurses (For Unix-like OS)
#include <curses.h>           // Library PDcurses (For Windows OS)
#define _KEY_ACTION_ESC 0x1B
#define _KEY_ACTION_UP 0x77
#define _KEY_ACTION_DOWN 0x73
#define _KEY_ACTION_LEFT 0x61
#define _KEY_ACTION_RIGHT 0x64
#define _KEY_ACTION_ENTER 0x0D

/*
 *    ASCII CRPG
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

int menuScenario();
int _sys_keyboardEvent();




int main(){
    // Clear the console screen.

    // Display the menu scenario.
    menuScenario();

    int _key_value;
    while((_key_value = _sys_keyboardEvent()) != _KEY_ACTION_ESC){
        printf("[Debug]INPUT CONFIRMED! KEY CODE: 0x%02x\n", _key_value);
    }
    printf("[Debug]END KEY EVENT. KEY CODE: 0x1B\n");
    return 0;
}


int menuScenario(){
    int FUNC_RETURN_VALUE = 0x00;
    printf("-----------------------------------------------------\n");
    printf("                                                     \n");
    printf("        JUST A SIMPLE CLANG ROLE-PLAYING-GAME        \n");
    printf("                                                     \n");
    printf("                   # GAME_TITLE                      \n");
    printf("                                                     \n");
    printf("                # ASCII_TITLE_IMAGE                  \n");
    printf("                                                     \n");
    printf("-----------------------------------------------------\n");
    printf("                                                     \n\n");
    printf("          *-------------------------------*\n");
    printf("          |                               |\n");
    printf("          |          START  GAME          |\n");
    printf("          |                               |\n");
    printf("          |          LOAD   GAME          |\n");
    printf("          |                               |\n");
    printf("          |          EXIT   GAME          |\n");
    printf("          |                               |\n");
    printf("          *-------------------------------*\n");
    return FUNC_RETURN_VALUE;
}

int _sys_keyboardEvent(){
    int FUNC_RETURN_VALUE = 0x00;
    FUNC_RETURN_VALUE = getchar();
    return FUNC_RETURN_VALUE;
}
