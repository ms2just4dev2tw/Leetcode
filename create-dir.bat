
@echo off

set absPath=%~dp0

set srcPath=%absPath%src\
if not exist %srcPath% (
    md %srcPath%
    echo created: %srcPath%
)

@REM 启用变量延迟
setlocal enabledelayedexpansion

@REM biweekly
set biweeklyPath=%srcPath%biweekly\
if not exist %biweeklyPath% (
    md %biweeklyPath%
    echo created: %biweeklyPath%
)
call:createDir %biweeklyPath% 1 1 20

@REM weekly
set weeklyPath=%srcPath%weekly\
if not exist %weeklyPath% (
    md %weeklyPath%
    echo created: %weeklyPath%
)
call:createDir  %weeklyPath% 100 1 330

@REM end
goto:eof


@REM create direction
:createDir
echo %1
for /l %%x in (%2, %3, %4) do (
    set once=%%x
    set last4once=!once:~-1!

    if !last4once! equ 1 (
        set start=00%%x
        set start=!start:~-3!
    
        set /a end=%%x+9
        set end=00!end!
        set end=!end:~-3!

        set totalPath10=%1!start!-!end!\
        if not exist !totalPath10! (
            md !totalPath10!
            echo created: !totalPath10!
        )
    )

    set once=00%%x
    set once=!once:~-3!
    set oncePath=!totalPath10!!once!\
    if not exist !oncePath! (
        md !oncePath!
        echo created: !oncePath!
    )
)
goto:eof
