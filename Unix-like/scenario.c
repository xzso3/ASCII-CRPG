#include "scenario.h"
#include <ncurses.h>            // Library ncurses (For Unix-like OS)
//#include "curses.h"           // Library PDcurses (For Windows OS)

/*
 *    ASCII CRPG - Scenario Program Entrance
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

unsigned int _sys_showScenario(int scenarioType){
    unsigned int FUNC_RETURN_VALUE = 0x01;
    switch(scenarioType){
        case 0:
            _tmp_testCursesInit();
            break;
        
        default:
            FUNC_RETURN_VALUE = 0x00;
            break;
    }

    return FUNC_RETURN_VALUE;
}

unsigned int _tmp_testCursesInit(){

    unsigned int FUNC_RETURN_VALUE = 0x00;
    
    // Initialize curses
    initscr();
    noecho();
    cbreak();
    
    // get screen spec
    int resY, resX;
    getmaxyx(stdscr, resY, resX);

     mvwprintw(stdscr, 2, 5, "Console Res: %dx%d", resX, resY);

    // create a window for input
    WINDOW* _tmp_wInput = newwin(7, resX-12, resY-9, 5);
    
    box(_tmp_wInput, 0, 0);
    refresh();
    wrefresh(_tmp_wInput);

    keypad(_tmp_wInput, 1);
    mvwprintw(_tmp_wInput, 0, 3, "[System]");
    wrefresh(_tmp_wInput);
    mvwprintw(_tmp_wInput, 5, 41, "[Press Enter to Continue]");
    wrefresh(_tmp_wInput);
    int _tmp_cGet;
    /*
    int _ch_posX = 0, 
        _ch_posY = 0, 
        _map_maxPosX = 16, 
        _map_maxPosY = 16, 
        _map_minPosX = -16, 
        _map_minPosY = -16;
     */

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