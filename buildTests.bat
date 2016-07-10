@echo off

gcc src\bowling_game_test.c  ^
    src\bowling_game.c       ^
    -std=c99                 ^
    -o bin\bowling_tests.exe ^
    -Wall                    ^
    -Wextra                  ^
    -Werror                  ^
    -fmax-errors=5

if NOT ERRORLEVEL 1 (
    echo.
    .\bin\bowling_tests.exe
)
