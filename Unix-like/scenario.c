#include "scenario.h"
#include <time.h>
#include <ncurses.h>            // Library ncurses (For Unix-like OS)
//#include "curses.h"           // Library PDcurses (For Windows OS)

/*
 *    ASCII CRPG - Scenario Program Entrance
 *
 *    Current Version : For Unix-like OS    
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

// Curses screen initialize function
unsigned int _sys_initialize(int* _G_SYS_RES_Y, int* _G_SYS_RES_X){
    unsigned int FUNC_RETURN_VALUE = 0x01;

    // Initialize curses
    initscr();
    noecho();
    cbreak();
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_WHITE);   

    // get screen spec
    getmaxyx(stdscr, *_G_SYS_RES_Y, *_G_SYS_RES_X);
    attron(COLOR_PAIR(1));

    mvwprintw(stdscr, 1, 3, "[DEBUG] Console Res: %dx%d", *_G_SYS_RES_X, *_G_SYS_RES_Y);
    attroff(COLOR_PAIR(1));
    
    return FUNC_RETURN_VALUE;
}
ss
unsigned int _sys_showScenario(int scenarioType, int* _G_SYS_RES_Y, int* _G_SYS_RES_X){
    unsigned int FUNC_RETURN_VALUE = 0x01;
    switch(scenarioType){
        case 0:
            _sys_mainScenario();            
            break;
        
        case 666:
            _tmp_testCursesInit(_G_SYS_RES_Y, _G_SYS_RES_X);
            break;

        default:
            FUNC_RETURN_VALUE = 0x00;
            break;
    }

    return FUNC_RETURN_VALUE;
}

unsigned int _sys_mainScenario(){
    unsigned int FUNC_RETURN_VALUE = 0x01;
    char* titleASCII[5];
    titleASCII[0] = "     _    ____   ____ ___ ___       ____ ____  ____   ____ ";
    titleASCII[1] = "    / \\  / ___| / ___|_ _|_ _|     / ___|  _ \\|  _ \\ / ___|";
    titleASCII[2] = "   / _ \\ \\___ \\| |    | | | |     | |   | |_) | |_) | |  _ ";
    titleASCII[3] = "  / ___ \\ ___) | |___ | | | |     | |___|  _ <|  __/| |_| |";
    titleASCII[4] = " /_/   \\_\\____/ \\____|___|___|     \\____|_| \\_\\_|    \\____|";

    int i;
    for(i=0; i<5; i++){
        mvwprintw(stdscr, i+3, 5, titleASCII[i]);
        wrefresh(stdscr);
        clock_t curTime = clock();
        mvwprintw(stdscr, i+8, 3, "[DEBUG] curTime: %ld", curTime);
        wrefresh(stdscr);
        while (clock() < curTime + 600000);
    }
        
    
    return FUNC_RETURN_VALUE;
}


unsigned int _tmp_testCursesInit(int* _G_SYS_RES_Y, int* _G_SYS_RES_X){

    unsigned int FUNC_RETURN_VALUE = 0x00;
    
    int resX = *_G_SYS_RES_X,
        resY = *_G_SYS_RES_Y;
       

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