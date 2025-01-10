@echo off

:: Define output file
set outfile="C:\Windows\Temp\MazeRunner.exe"

:: Compile the project using g++
g++ -o %outfile% main.cpp ui.cpp maze.cpp io.cpp levels.cpp timer.cpp score.cpp

:: Check if compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b %errorlevel%
)

:: Run the compiled executable
%outfile%

:: Delete the compiled executable
del %outfile%

:: Pause the terminal
echo.
pause
