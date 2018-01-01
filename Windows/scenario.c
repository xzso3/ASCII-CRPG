#include <time.h>
#include <wchar.h>
#include "scenario.h"
//#include <ncurses.h>            // Library ncurses (For Unix-like OS)
#include "curses.h"           // Library PDcurses (For Windows OS)

/*
 *    ASCII CAVG - Scenario Program Entrance
 *
 *    Current Version : For Windows    
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

/// <Summary>
/// System Function
/// </Summary>

// Curses screen initialize function
int _sys_initialize(int* _G_SYS_RES_Y, int* _G_SYS_RES_X){
    int FUNC_RETURN_VALUE = 0x01;

    // Initialize curses
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_WHITE);   

    // get screen spec
    getmaxyx(stdscr, *_G_SYS_RES_Y, *_G_SYS_RES_X);
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 1, 3, "[DEBUG] Console Res: %dx%d", *_G_SYS_RES_X, *_G_SYS_RES_Y);
    attroff(COLOR_PAIR(1));
    
    return FUNC_RETURN_VALUE;
}

// Scenario switch
int _sys_showScenario(int scenarioType, int _G_SYS_RES_Y, int _G_SYS_RES_X){
    int FUNC_RETURN_VALUE = 0x01;
    switch(scenarioType){
        case 0:
            _sys_mainScenario();            
            break;

        case 1:
            _scene_titleMenu(_G_SYS_RES_Y, _G_SYS_RES_X);
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

int _sys_mainScenario(){
    int FUNC_RETURN_VALUE = 0x01;
    char* titleASCII[6];
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
        while (clock() < curTime + 150);
    }
        
    
    return FUNC_RETURN_VALUE;
}

int _sys_canvasPrint(char** canvas){
    int FUNC_RETURN_VALUE = 0x01;


    return FUNC_RETURN_VALUE;
}

/// <Summary>
/// Scenario Function
/// </Summary>

int _scene_titleMenu(int _G_SYS_RES_Y, int _G_SYS_RES_X){
    int FUNC_RETURN_VALUE = 0x01;
    int keySelection, hlSelection = 0; // hl means highlighted
    wchar_t* menuSelection[3] = {L"开 始 游 戏 ", L"读 取 游 戏 ", L"保 存 游 戏 "};
    
    // Set Window Spec
    int resX = _G_SYS_RES_X,
        resY = _G_SYS_RES_Y;
       

    // create a window for input
    WINDOW* titleSelector = newwin(7, resX-12, resY-9, 7);
    box(titleSelector, 0, 0);
    keypad(titleSelector, 1);

    // selector loop
    while(1){
        int i;
        for(i = 0; i < 3; i++){
            if(i == hlSelection)      wattron(titleSelector, A_REVERSE);
            mvwaddwstr(titleSelector, i+2, resX/2-12, menuSelection[i]);
            wrefresh(titleSelector);
            wattroff(titleSelector, A_REVERSE);
        }

        keySelection = wgetch(titleSelector);

        switch(keySelection){
            case KEY_UP:
                if(hlSelection != 0) hlSelection--;
                break;

            case KEY_DOWN:
                if(hlSelection != 2) hlSelection++;
                break;

            default:
                break;
        }

        if(keySelection == 0x0a)
            break;

    }

    switch(hlSelection){
        case 0:
            mvwprintw(titleSelector, 0, 2, " GAME Loading ... ");
            wrefresh(titleSelector);
            _scene_titleStart();
            break;

        case 1:
            mvwprintw(titleSelector, 0, 2, " SAV Loading ... ");
            wrefresh(titleSelector);
            _scene_titleLoad();
            break;

        case 2:
            mvwprintw(titleSelector, 0, 2, " Exiting ... ");
            wrefresh(titleSelector);
            _scene_titleExit();
            break;
    }

    return FUNC_RETURN_VALUE;
}

int _scene_titleStart(){
    int FUNC_RETURN_VALUE = 0x01;
    getch();
    endwin();
    return FUNC_RETURN_VALUE;
}

int _scene_titleLoad(){
    int FUNC_RETURN_VALUE = 0x01;
    getch();
    endwin();
    return FUNC_RETURN_VALUE;
}

int _scene_titleExit(){
    int FUNC_RETURN_VALUE = 0x01;
    getch();
    endwin();
    return FUNC_RETURN_VALUE;
}

/// <Summary>
/// Temporary Function
/// </Summary>

int _tmp_testCursesInit(int _G_SYS_RES_Y, int _G_SYS_RES_X){

    int FUNC_RETURN_VALUE = 0x00;
    
    int resX = _G_SYS_RES_X,
        resY = _G_SYS_RES_Y;
       

    // create a window for input
    WINDOW* _tmp_wInput = newwin(7, resX-12, resY-9, 5);
    
    box(_tmp_wInput, 0, 0);
    
    wrefresh(_tmp_wInput);

    keypad(_tmp_wInput, 1);
    mvwprintw(_tmp_wInput, 0, 3, "[System]");
    mvwprintw(_tmp_wInput, 2, 4, "Debug Mode Actived!");
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