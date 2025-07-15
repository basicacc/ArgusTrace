@echo off
REM Unified Build Script for API Tracer Project - FIXED VERSION
setlocal enabledelayedexpansion

echo.
echo ==================== UNIFIED BUILD SYSTEM ====================
echo This script builds both:
echo 1. Regular API Tracer (breakpoint-based)
echo 2. DynamoRIO Enhanced Tracer (instruction-level)
echo ==============================================================
echo.

REM Visual Studio paths
set "VS_ROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
set "VS_TOOLS=%VS_ROOT%\VC\Tools\MSVC"
set "VS_BUILDTOOLS=%VS_ROOT%\VC\Auxiliary\Build"

REM Find the latest MSVC version
for /f "delims=" %%i in ('dir "%VS_TOOLS%" /b /od') do set "MSVC_VERSION=%%i"
set "MSVC_PATH=%VS_TOOLS%\%MSVC_VERSION%"

echo Using Visual Studio 2022 Community at: %VS_ROOT%
echo Using MSVC version: %MSVC_VERSION%

REM Check if we have the required source files
if not exist "src\main.cpp" (
    echo Error: src\main.cpp not found!
    pause
    exit /b 1
)

if not exist "src\apienumwithbp.cpp" (
    echo Error: src\apienumwithbp.cpp not found!
    pause
    exit /b 1
)

echo Choose what to build:
echo 1) Regular API Tracer only (Visual Studio build)
echo 2) DynamoRIO Enhanced Tracer only
echo 3) Both (recommended)
echo.
set /p build_choice="Enter choice (1-3): "

if "%build_choice%"=="1" goto build_regular_only
if "%build_choice%"=="2" goto build_dynamorio_only
if "%build_choice%"=="3" goto build_both
echo Invalid choice. Building both...
goto build_both

:build_both
echo.
echo ===============================================
echo Building Both Tracers
echo ===============================================
call :build_regular_tracer
echo.
call :build_dynamorio_tracer
goto final_summary

:build_regular_only
echo.
echo ===============================================
echo Building Regular API Tracer Only
echo ===============================================
call :build_regular_tracer
goto final_summary

:build_dynamorio_only
echo.
echo ===============================================
echo Building DynamoRIO Enhanced Tracer Only
echo ===============================================
call :build_dynamorio_tracer
goto final_summary

:build_regular_tracer
echo.
echo Building Regular API Tracer...
echo ================================

REM Setup Visual Studio environment for x64
echo Setting up Visual Studio x64 environment...
call "%VS_BUILDTOOLS%\vcvars64.bat" >nul 2>&1
if errorlevel 1 (
    echo ✗ Failed to setup Visual Studio x64 environment
    goto build_32bit
)

echo Building 64-bit regular tracer...
cl /EHsc /std:c++20 /D_UNICODE /DUNICODE /MT /O2 /Fe:tracer64.exe src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp psapi.lib
if errorlevel 1 (
    echo ✗ 64-bit regular tracer build failed
) else (
    echo ✓ 64-bit regular tracer built: tracer64.exe
    del *.obj >nul 2>&1
)

:build_32bit
REM Setup Visual Studio environment for x86
echo Setting up Visual Studio x86 environment...
call "%VS_BUILDTOOLS%\vcvars32.bat" >nul 2>&1
if errorlevel 1 (
    echo ✗ Failed to setup Visual Studio x86 environment
    goto build_analyzer
)

echo Building 32-bit regular tracer...
cl /EHsc /std:c++20 /D_UNICODE /DUNICODE /MT /O2 /Fe:tracer32.exe src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp psapi.lib
if errorlevel 1 (
    echo ✗ 32-bit regular tracer build failed
) else (
    echo ✓ 32-bit regular tracer built: tracer32.exe
    del *.obj >nul 2>&1
)

:build_analyzer
REM Build instruction analyzer
echo Building instruction analyzer...
if exist "src\instruction_analyzer.cpp" (
    call "%VS_BUILDTOOLS%\vcvars64.bat" >nul 2>&1
    cl /EHsc /std:c++17 /O2 /Fe:instruction_analyzer.exe src\instruction_analyzer.cpp
    if errorlevel 1 (
        echo ✗ Instruction analyzer build failed
    ) else (
        echo ✓ Instruction analyzer built: instruction_analyzer.exe
        del *.obj >nul 2>&1
    )
) else (
    echo ✗ instruction_analyzer.cpp not found in src\ folder
    echo   Please add the instruction_analyzer.cpp code to src\ directory
)

goto :eof

:build_dynamorio_tracer
echo.
echo Building DynamoRIO Enhanced Tracer...
echo ====================================

REM Check if instruction_tracer.cpp exists
if not exist "src\instruction_tracer.cpp" (
    echo Error: src\instruction_tracer.cpp not found!
    echo Please ensure the enhanced instruction_tracer.cpp is in the src\ directory
    goto :eof
)

REM Clean up any previous build directories to avoid conflicts
if exist dynamorio_build_x64 rmdir /s /q dynamorio_build_x64
if exist dynamorio_build_x86 rmdir /s /q dynamorio_build_x86

REM Prompt user to enter DynamoRIO installation path
set /p DYNAMORIO_HOME=Enter DynamoRIO installation path: 

REM Verify the path exists
if not exist "%DYNAMORIO_HOME%\cmake" (
    echo Error: DynamoRIO not found at %DYNAMORIO_HOME%
    echo Please check the path and try again.
    pause
    exit /b 1
)

echo DynamoRIO found at: %DYNAMORIO_HOME%
goto found_dynamorio

:found_dynamorio

echo.
echo Select DynamoRIO tracer architecture:
echo 1) 64-bit (x64)
echo 2) 32-bit (x86)
echo 3) Both architectures
echo.
set /p arch_choice="Enter choice (1-3): "

if "%arch_choice%"=="1" goto build_dr_x64
if "%arch_choice%"=="2" goto build_dr_x86
if "%arch_choice%"=="3" goto build_dr_both
echo Invalid choice. Building 64-bit...
goto build_dr_x64

:build_dr_both
call :build_dr_x64_internal
call :build_dr_x86_internal
call :create_dr_wrappers
goto :eof

:build_dr_x64
call :build_dr_x64_internal
call :create_dr_wrapper_x64
goto :eof

:build_dr_x86
call :build_dr_x86_internal
call :create_dr_wrapper_x86
goto :eof

:build_dr_x64_internal
echo Building DynamoRIO 64-bit version...

REM Create separate build directory for x64
if not exist dynamorio_build_x64 mkdir dynamorio_build_x64
cd dynamorio_build_x64

REM Create CMakeLists.txt for x64 build
echo cmake_minimum_required(VERSION 3.10) > CMakeLists.txt
echo project(instruction_tracer_x64) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo find_package(DynamoRIO 9.0 REQUIRED) >> CMakeLists.txt
echo if (NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo   message(FATAL_ERROR "DynamoRIO package required to build") >> CMakeLists.txt
echo endif(NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo add_library(instruction_tracer_x64 SHARED ../src/instruction_tracer.cpp) >> CMakeLists.txt
echo configure_DynamoRIO_client(instruction_tracer_x64) >> CMakeLists.txt
echo use_DynamoRIO_extension(instruction_tracer_x64 drmgr) >> CMakeLists.txt
echo use_DynamoRIO_extension(instruction_tracer_x64 drx) >> CMakeLists.txt
echo set_property(TARGET instruction_tracer_x64 PROPERTY CXX_STANDARD 11) >> CMakeLists.txt
echo set_property(TARGET instruction_tracer_x64 PROPERTY OUTPUT_NAME instruction_tracer) >> CMakeLists.txt
echo if(WIN32) >> CMakeLists.txt
echo   target_compile_definitions(instruction_tracer_x64 PRIVATE WINDOWS=1) >> CMakeLists.txt
echo endif() >> CMakeLists.txt

cmake . -DDynamoRIO_DIR="%DYNAMORIO_HOME%\cmake" -G "Visual Studio 17 2022" -A x64
if errorlevel 1 (
    echo ✗ CMake configuration failed for 64-bit
    cd ..
    goto :eof
)

cmake --build . --config Release
if errorlevel 1 (
    echo ✗ DynamoRIO 64-bit build failed
    cd ..
    goto :eof
)

cd ..
if exist dynamorio_build_x64\Release\instruction_tracer.dll (
    if not exist build_x64 mkdir build_x64
    if not exist build_x64\Release mkdir build_x64\Release
    copy dynamorio_build_x64\Release\instruction_tracer.dll build_x64\Release\
    echo ✓ DynamoRIO 64-bit build successful: build_x64\Release\instruction_tracer.dll
) else (
    echo ✗ DynamoRIO 64-bit build failed - DLL not found
)
goto :eof

:build_dr_x86_internal
echo Building DynamoRIO 32-bit version...

REM Create separate build directory for x86
if not exist dynamorio_build_x86 mkdir dynamorio_build_x86
cd dynamorio_build_x86

REM Create CMakeLists.txt for x86 build with different target name
echo cmake_minimum_required(VERSION 3.10) > CMakeLists.txt
echo project(instruction_tracer_x86) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo find_package(DynamoRIO 9.0 REQUIRED) >> CMakeLists.txt
echo if (NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo   message(FATAL_ERROR "DynamoRIO package required to build") >> CMakeLists.txt
echo endif(NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo add_library(instruction_tracer_x86 SHARED ../src/instruction_tracer.cpp) >> CMakeLists.txt
echo configure_DynamoRIO_client(instruction_tracer_x86) >> CMakeLists.txt
echo use_DynamoRIO_extension(instruction_tracer_x86 drmgr) >> CMakeLists.txt
echo use_DynamoRIO_extension(instruction_tracer_x86 drx) >> CMakeLists.txt
echo set_property(TARGET instruction_tracer_x86 PROPERTY CXX_STANDARD 11) >> CMakeLists.txt
echo set_property(TARGET instruction_tracer_x86 PROPERTY OUTPUT_NAME instruction_tracer) >> CMakeLists.txt
echo if(WIN32) >> CMakeLists.txt
echo   target_compile_definitions(instruction_tracer_x86 PRIVATE WINDOWS=1) >> CMakeLists.txt
echo endif() >> CMakeLists.txt

cmake . -DDynamoRIO_DIR="%DYNAMORIO_HOME%\cmake" -G "Visual Studio 17 2022" -A Win32
if errorlevel 1 (
    echo ✗ CMake configuration failed for 32-bit
    cd ..
    goto :eof
)

cmake --build . --config Release
if errorlevel 1 (
    echo ✗ DynamoRIO 32-bit build failed
    cd ..
    goto :eof
)

cd ..
if exist dynamorio_build_x86\Release\instruction_tracer.dll (
    if not exist build_x86 mkdir build_x86
    if not exist build_x86\Release mkdir build_x86\Release
    copy dynamorio_build_x86\Release\instruction_tracer.dll build_x86\Release\
    echo ✓ DynamoRIO 32-bit build successful: build_x86\Release\instruction_tracer.dll
) else (
    echo ✗ DynamoRIO 32-bit build failed - DLL not found
)
goto :eof

:create_dr_wrappers
echo Creating DynamoRIO wrapper batch files...

REM Create 64-bit wrapper
if exist build_x64\Release\instruction_tracer.dll (
    echo @echo off > tracer_dynamorio_x64.bat
    echo echo Starting 64-bit DynamoRIO enhanced instruction trace... >> tracer_dynamorio_x64.bat
    echo "%DYNAMORIO_HOME%\bin64\drrun.exe" -c "%CD%\build_x64\Release\instruction_tracer.dll" -- %%* >> tracer_dynamorio_x64.bat
    echo ✓ Created: tracer_dynamorio_x64.bat
)

REM Create 32-bit wrapper
if exist build_x86\Release\instruction_tracer.dll (
    echo @echo off > tracer_dynamorio_x86.bat
    echo echo Starting 32-bit DynamoRIO enhanced instruction trace... >> tracer_dynamorio_x86.bat
    echo "%DYNAMORIO_HOME%\bin32\drrun.exe" -c "%CD%\build_x86\Release\instruction_tracer.dll" -- %%* >> tracer_dynamorio_x86.bat
    echo ✓ Created: tracer_dynamorio_x86.bat
)

REM Create auto-detection wrapper
echo @echo off > tracer_dynamorio.bat
echo if "%%1"=="" goto usage >> tracer_dynamorio.bat
echo file "%%1" ^| find /i "PE32+" ^>nul >> tracer_dynamorio.bat
echo if errorlevel 1 goto use_32bit >> tracer_dynamorio.bat
echo :use_64bit >> tracer_dynamorio.bat
echo call tracer_dynamorio_x64.bat %%* >> tracer_dynamorio.bat
echo goto end >> tracer_dynamorio.bat
echo :use_32bit >> tracer_dynamorio.bat
echo call tracer_dynamorio_x86.bat %%* >> tracer_dynamorio.bat
echo goto end >> tracer_dynamorio.bat
echo :usage >> tracer_dynamorio.bat
echo echo Usage: tracer_dynamorio.bat your_program.exe [args...] >> tracer_dynamorio.bat
echo :end >> tracer_dynamorio.bat

echo ✓ Created: tracer_dynamorio.bat (auto-detection)
goto :eof

:create_dr_wrapper_x64
echo Creating DynamoRIO 64-bit wrapper...
echo @echo off > tracer_dynamorio.bat
echo echo Starting 64-bit DynamoRIO enhanced instruction trace... >> tracer_dynamorio.bat
echo "%DYNAMORIO_HOME%\bin64\drrun.exe" -c "%CD%\build_x64\Release\instruction_tracer.dll" -- %%* >> tracer_dynamorio.bat
echo ✓ Created: tracer_dynamorio.bat
goto :eof

:create_dr_wrapper_x86
echo Creating DynamoRIO 32-bit wrapper...
echo @echo off > tracer_dynamorio.bat
echo echo Starting 32-bit DynamoRIO enhanced instruction trace... >> tracer_dynamorio.bat
echo "%DYNAMORIO_HOME%\bin32\drrun.exe" -c "%CD%\build_x86\Release\instruction_tracer.dll" -- %%* >> tracer_dynamorio.bat
echo ✓ Created: tracer_dynamorio.bat
goto :eof

:final_summary
echo.
echo ================================================================
echo                        BUILD SUMMARY
echo ================================================================
echo.
echo Regular API Tracer (breakpoint-based):
if exist tracer64.exe echo   ✓ tracer64.exe (64-bit)
if exist tracer32.exe echo   ✓ tracer32.exe (32-bit)
if exist instruction_analyzer.exe echo   ✓ instruction_analyzer.exe (post-processor for DynamoRIO)
if not exist tracer64.exe if not exist tracer32.exe echo   ✗ No regular tracers built

echo.
echo DynamoRIO Enhanced Tracer (instruction-level):
if exist build_x64\Release\instruction_tracer.dll echo   ✓ 64-bit DLL built
if exist build_x86\Release\instruction_tracer.dll echo   ✓ 32-bit DLL built
if exist tracer_dynamorio.bat echo   ✓ tracer_dynamorio.bat (wrapper)
if not exist build_x64\Release\instruction_tracer.dll if not exist build_x86\Release\instruction_tracer.dll echo   ✗ No DynamoRIO tracers built

echo.
echo Usage:
echo ------
echo Regular API Tracer:
echo   tracer64.exe  (choose option 1 for breakpoint tracing)
echo   tracer32.exe  (choose option 1 for breakpoint tracing)
echo.
echo DynamoRIO Enhanced Tracer:
echo   tracer64.exe  (choose option 2 for DynamoRIO tracing)
echo   OR directly: tracer_dynamorio.bat target.exe
echo   THEN run: instruction_analyzer.exe (to analyze the output)
echo.
echo Complete DynamoRIO Workflow:
echo   1. tracer_dynamorio.bat target.exe
echo   2. instruction_analyzer.exe
echo   3. Check api_calls_detected.log for results
echo.
echo Output files (DynamoRIO):
echo   - instructions.log (full instruction trace)
echo   - all_modules_functions.log (module information)
echo   - api_calls_detected.log (analyzed API calls - run instruction_analyzer.exe)
echo.

REM Cleanup temporary build directories
if exist dynamorio_build_x64 (
    echo Cleaning up temporary x64 build files...
    rmdir /s /q dynamorio_build_x64
)
if exist dynamorio_build_x86 (
    echo Cleaning up temporary x86 build files...
    rmdir /s /q dynamorio_build_x86
)

pause