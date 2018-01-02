clang io.c main.c scenario.c -Wall -Werror -lpdcurses -o bin\tmp.exe -lgdi32 -lcomdlg32
@echo off
pause
bin\tmp.exe
pause