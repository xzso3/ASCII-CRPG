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
#define _KEY_MBP_DOWN 0x102
#define _KEY_MBP_UP 0x103
#define _KEY_MBP_LEFT 0x104
#define _KEY_MBP_RIGHT 0x105

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
int _tmp_testCursesInit();




int main(){
    // Clear the console screen.

    // Display the menu scenario.
    //menuScenario();
    _tmp_testCursesInit();
    
    /*
    int _key_value;
    while((_key_value = _sys_keyboardEvent()) != _KEY_ACTION_ESC){
        printf("[Debug]INPUT CONFIRMED! KEY CODE: 0x%02x\n", _key_value);
    }
    printf("[Debug]END KEY EVENT. KEY CODE: 0x1B\n");
    */

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

int _tmp_testCursesInit(){

    int FUNC_RETURN_VALUE = 0x00;
    
    // Initialize curses
    initscr();
    noecho();
    cbreak();

    // get screen spec
    int resY, resX;
    getmaxyx(stdscr, resY, resX);

    // create a window for input
    WINDOW* _tmp_wInput = newwin(7, resX-12, resY-9, 5);
    box(_tmp_wInput, 0, 0);
    refresh();
    wrefresh(_tmp_wInput);

    keypad(_tmp_wInput, true);
    mvwprintw(_tmp_wInput, 1, 2, "System");
    mvwprintw(_tmp_wInput, 5, 41, "[Press Enter to Continue]");
    int _tmp_cGet;
    int _ch_posX = 0, 
        _ch_posY = 0, 
        _map_maxPosX = 16, 
        _map_maxPosY = 16, 
        _map_minPosX = -16, 
        _map_minPosY = -16;
        
    while((_tmp_cGet = wgetch(_tmp_wInput))){
        mvwprintw(_tmp_wInput, 3, 4, "You pressed [KEY_CODE: 0x%02x]!", _tmp_cGet);
        wrefresh(_tmp_wInput);

        switch(_tmp_cGet){
            case _KEY_MBP_UP:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO AHEAD ONE STEP!     ");
                wrefresh(_tmp_wInput);
                break;

            case _KEY_MBP_DOWN:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO DOWN ONE STEP!      ");
                wrefresh(_tmp_wInput);
                break;

            case _KEY_MBP_RIGHT:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO RIGHT ONE STEP!     ");
                wrefresh(_tmp_wInput);
                break;

            case _KEY_MBP_LEFT:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO LEFT ONE STEP!      ");
                wrefresh(_tmp_wInput);
                break;
        }

        if(_tmp_cGet == 'q' || _tmp_cGet == 'Q'){
            mvwprintw(_tmp_wInput, 4, 4, "SAMPLE PROGRAM EXITED        ");
            wrefresh(_tmp_wInput);
            break;
        }
    }


    getch();
    endwin();

    return FUNC_RETURN_VALUE;
}