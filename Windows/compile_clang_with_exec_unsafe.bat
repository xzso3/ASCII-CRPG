clang io.c main.c scenario.c -lpdcurses -o bin\c-avg_tmp.exe -lgdi32 -lcomdlg32
@echo off
pause
bin\c-avg.exe
pause