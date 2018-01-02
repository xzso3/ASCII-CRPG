#include <time.h>
#include <string.h>
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
    char* titleASCII[7];
    titleASCII[0] = " .d8888b.                    d8888   888     888    .d8888b.  ";
    titleASCII[1] = "888    888                 d88P888   888     888   888    888 ";
    titleASCII[2] = "888                       d88P 888   Y88b   d88P   888        ";
    titleASCII[3] = "888          8888888     d88P  888    Y88b d88P    888  88888 ";
    titleASCII[4] = "888    888              d88P   888     Y88o88P     888    888 ";
    titleASCII[5] = "Y88b  d88P             d8888888888      Y888P      Y88b  d88P ";
    titleASCII[6] = " \"Y8888P\"             d88P     888       Y8P        \"Y8888P88 ";

    wchar_t* tmp = L"江德医院故事 ";

    int i;
    for(i=0; i<7; i++){
        mvwprintw(stdscr, i+3, 4, titleASCII[i]);
        wrefresh(stdscr);
        clock_t curTime = clock();
        while (clock() < curTime + 150);
    }

    int j, wcLen = wcslen(tmp);

    for(j = 0; j < wcLen * 2; j++){
        if(j % 2 == 0){
            move(11, j + 5);
            addnwstr(tmp + j / 2, 1);
        }else{
            move(11, j + 5);
            addstr(" ");
        }
    }

    //mvwaddwstr(stdscr, 8, 5, tmp);
    wrefresh(stdscr);    
    
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
    wchar_t* menuSelection[3] = {L"开 始 游 戏 ", L"读 取 游 戏 ", L"退 出 游 戏 "};
    
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
            _scene_titleExit(_G_SYS_RES_Y, _G_SYS_RES_X);
            break;
    }

    return FUNC_RETURN_VALUE;
}

int _scene_titleStart(){
    int FUNC_RETURN_VALUE = 0x01;
    clear();
    getch();
    endwin();
    return FUNC_RETURN_VALUE;
}

int _scene_titleLoad(){
    int FUNC_RETURN_VALUE = 0x01;
    clear();
    getch();
    endwin();
    return FUNC_RETURN_VALUE;
}

int _scene_titleExit(int _G_SYS_RES_Y, int _G_SYS_RES_X){
    int FUNC_RETURN_VALUE = 0x01;
    char* caption = "Exiting...";
    clear();
    mvwprintw(stdscr, _G_SYS_RES_Y/2, (_G_SYS_RES_X - strlen(caption)) / 2, caption);
    clock_t curTime = clock();
    while (clock() < curTime + 1500) wrefresh(stdscr);
    endwin();
    return FUNC_RETURN_VALUE;
}

/// <Summary>
/// Temporary Function
/// </Summary>

// Debug Function 
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
            case KEY_UP:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO AHEAD ONE STEP!     ");
                wrefresh(_tmp_wInput);
                break;

            case KEY_DOWN:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO DOWN ONE STEP!      ");
                wrefresh(_tmp_wInput);
                break;

            case KEY_RIGHT:
                mvwprintw(_tmp_wInput, 4, 4, "YOU GO RIGHT ONE STEP!     ");
                wrefresh(_tmp_wInput);
                break;

            case KEY_LEFT:
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