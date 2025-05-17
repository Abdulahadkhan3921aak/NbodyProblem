@echo off
setlocal

:: Configuration
set OUTPUT=build\Nbody.exe
set COMPILER=g++
set INCLUDE_DIRS=-Iinclude -IDependencies\GLEW\include -IDependencies\GLFW\include
set LIB_DIRS=-LDependencies\GLEW\lib\Release\Win32 -LDependencies\GLFW\lib
set LIBS=-lglew32 -lglfw3 -lopengl32 -lgdi32
set CFLAGS=-DGLEW_STATIC
set SOURCES=src\main.cpp src\OpenGL.cpp src\body.cpp src\vector2.cpp

:: Create build directory if not exists
if not exist build mkdir build

:: Compile command
echo Compiling...
%COMPILER% %INCLUDE_DIRS% %LIB_DIRS% %CFLAGS% %SOURCES% %LIBS% -o %OUTPUT%

:: Cleanup and error handling
if %ERRORLEVEL% neq 0 (
    echo.
    echo ❌ Compilation failed!
    exit /b %ERRORLEVEL%
) else (
    echo.
    echo ✅ Compilation succeeded. Output: %OUTPUT%
    del /Q *.o 2> nul
)

endlocal