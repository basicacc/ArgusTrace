@echo off
setlocal enabledelayedexpansion

echo.
echo ==================== UNIFIED BUILD SYSTEM ====================
echo This script builds both:
echo 1. Regular API Tracer (breakpoint-based)
echo 2. DynamoRIO Enhanced Tracer (instruction-level)
echo ==============================================================
echo.

if not exist "build" mkdir "build"

set "VS_ROOT=C:\Program Files\Microsoft Visual Studio\2022\Community"
set "VS_TOOLS=%VS_ROOT%\VC\Tools\MSVC"
set "VS_BUILDTOOLS=%VS_ROOT%\VC\Auxiliary\Build"

for /f "delims=" %%i in ('dir "%VS_TOOLS%" /b /od') do set "MSVC_VERSION=%%i"
set "MSVC_PATH=%VS_TOOLS%\%MSVC_VERSION%"

echo Using Visual Studio 2022 Community at: %VS_ROOT%
echo Using MSVC version: %MSVC_VERSION%

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

echo Creating resource file for icon...
echo #include ^<windows.h^> > app.rc
echo IDI_ICON1 ICON "src/icons/ArgusTrace.ico" >> app.rc

echo Setting up Visual Studio x64 environment...
call "%VS_BUILDTOOLS%\vcvars64.bat" >nul 2>&1
if errorlevel 1 (
    echo ✗ Failed to setup Visual Studio x64 environment
    goto build_32bit
)

rc app.rc >nul 2>&1
if errorlevel 1 (
    echo ✗ Resource compiler not found, building without icon
    set RESOURCE_FILE_64=
) else (
    echo ✓ Resource file compiled for 64-bit
    set RESOURCE_FILE_64=app.res
)

echo Building 64-bit regular tracer...
cl /EHsc /std:c++20 /D_UNICODE /DUNICODE /MT /O2 /Fe:build\argustrace64.exe src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp psapi.lib %RESOURCE_FILE_64%
if errorlevel 1 (
    echo ✗ 64-bit regular tracer build failed
) else (
    echo ✓ 64-bit regular tracer built: build\argustrace64.exe
    del *.obj >nul 2>&1
)

:build_32bit
echo Setting up Visual Studio x86 environment...
call "%VS_BUILDTOOLS%\vcvars32.bat" >nul 2>&1
if errorlevel 1 (
    echo ✗ Failed to setup Visual Studio x86 environment
    goto build_analyzer
)

rc app.rc >nul 2>&1
if errorlevel 1 (
    echo ✗ Resource compiler not found, building without icon
    set RESOURCE_FILE_32=
) else (
    echo ✓ Resource file compiled for 32-bit
    set RESOURCE_FILE_32=app.res
)

echo Building 32-bit regular tracer...
cl /EHsc /std:c++20 /D_UNICODE /DUNICODE /MT /O2 /Fe:build\argustrace32.exe src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp psapi.lib %RESOURCE_FILE_32%
if errorlevel 1 (
    echo ✗ 32-bit regular tracer build failed
) else (
    echo ✓ 32-bit regular tracer built: build\argustrace32.exe
    del *.obj >nul 2>&1
)

:build_analyzer
echo Building instruction analyzer...
if exist "src\instruction_analyzer.cpp" (
    call "%VS_BUILDTOOLS%\vcvars64.bat" >nul 2>&1
    
    rc app.rc >nul 2>&1
    if errorlevel 1 (
        set RESOURCE_FILE_ANALYZER=
    ) else (
        set RESOURCE_FILE_ANALYZER=app.res
    )
    
    cl /EHsc /std:c++17 /O2 /Fe:build\instruction_analyzer.exe src\instruction_analyzer.cpp %RESOURCE_FILE_ANALYZER%
    if errorlevel 1 (
        echo ✗ Instruction analyzer build failed
    ) else (
        echo ✓ Instruction analyzer built: build\instruction_analyzer.exe
        del *.obj >nul 2>&1
    )
) else (
    echo ✗ instruction_analyzer.cpp not found in src\ folder
    echo   Please add the instruction_analyzer.cpp code to src\ directory
)

del app.rc >nul 2>&1
del app.res >nul 2>&1

goto :eof

:build_dynamorio_tracer
echo.
echo Building DynamoRIO Enhanced Tracer...
echo ====================================

if not exist "src\instruction_tracer.cpp" (
    echo Error: src\instruction_tracer.cpp not found!
    echo Please ensure the enhanced instruction_tracer.cpp is in the src\ directory
    goto :eof
)

if exist build\dynamorio_build_x64 rmdir /s /q build\dynamorio_build_x64
if exist build\dynamorio_build_x86 rmdir /s /q build\dynamorio_build_x86

set /p DYNAMORIO_HOME=Enter DynamoRIO installation path: 

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

if not exist build\dynamorio_build_x64 mkdir build\dynamorio_build_x64
cd build\dynamorio_build_x64

echo cmake_minimum_required(VERSION 3.10) > CMakeLists.txt
echo project(instruction_tracer_x64) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo find_package(DynamoRIO 9.0 REQUIRED) >> CMakeLists.txt
echo if (NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo   message(FATAL_ERROR "DynamoRIO package required to build") >> CMakeLists.txt
echo endif(NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo add_library(instruction_tracer_x64 SHARED ../../src/instruction_tracer.cpp) >> CMakeLists.txt
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
    cd ..\..
    goto :eof
)

cmake --build . --config Release
if errorlevel 1 (
    echo ✗ DynamoRIO 64-bit build failed
    cd ..\..
    goto :eof
)

cd ..\..
if exist build\dynamorio_build_x64\Release\instruction_tracer.dll (
    if not exist build\x64 mkdir build\x64
    if not exist build\x64\Release mkdir build\x64\Release
    copy build\dynamorio_build_x64\Release\instruction_tracer.dll build\x64\Release\
    echo ✓ DynamoRIO 64-bit build successful: build\x64\Release\instruction_tracer.dll
) else (
    echo ✗ DynamoRIO 64-bit build failed - DLL not found
)
goto :eof

:build_dr_x86_internal
echo Building DynamoRIO 32-bit version...

if not exist build\dynamorio_build_x86 mkdir build\dynamorio_build_x86
cd build\dynamorio_build_x86

echo cmake_minimum_required(VERSION 3.10) > CMakeLists.txt
echo project(instruction_tracer_x86) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo find_package(DynamoRIO 9.0 REQUIRED) >> CMakeLists.txt
echo if (NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo   message(FATAL_ERROR "DynamoRIO package required to build") >> CMakeLists.txt
echo endif(NOT DynamoRIO_FOUND) >> CMakeLists.txt
echo. >> CMakeLists.txt
echo add_library(instruction_tracer_x86 SHARED ../../src/instruction_tracer.cpp) >> CMakeLists.txt
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
    cd ..\..
    goto :eof
)

cmake --build . --config Release
if errorlevel 1 (
    echo ✗ DynamoRIO 32-bit build failed
    cd ..\..
    goto :eof
)

cd ..\..
if exist build\dynamorio_build_x86\Release\instruction_tracer.dll (
    if not exist build\x86 mkdir build\x86
    if not exist build\x86\Release mkdir build\x86\Release
    copy build\dynamorio_build_x86\Release\instruction_tracer.dll build\x86\Release\
    echo ✓ DynamoRIO 32-bit build successful: build\x86\Release\instruction_tracer.dll
) else (
    echo ✗ DynamoRIO 32-bit build failed - DLL not found
)
goto :eof

:create_dr_wrappers
echo Creating DynamoRIO wrapper batch files...

if exist build\x64\Release\instruction_tracer.dll (
    echo @echo off > build\tracer_dynamorio_x64.bat
    echo echo Starting 64-bit DynamoRIO enhanced instruction trace... >> build\tracer_dynamorio_x64.bat
    echo "%DYNAMORIO_HOME%\bin64\drrun.exe" -c "%CD%\build\x64\Release\instruction_tracer.dll" -- %%* >> build\tracer_dynamorio_x64.bat
    echo ✓ Created: build\tracer_dynamorio_x64.bat
)

if exist build\x86\Release\instruction_tracer.dll (
    echo @echo off > build\tracer_dynamorio_x86.bat
    echo echo Starting 32-bit DynamoRIO enhanced instruction trace... >> build\tracer_dynamorio_x86.bat
    echo "%DYNAMORIO_HOME%\bin32\drrun.exe" -c "%CD%\build\x86\Release\instruction_tracer.dll" -- %%* >> build\tracer_dynamorio_x86.bat
    echo ✓ Created: build\tracer_dynamorio_x86.bat
)

echo @echo off > build\tracer_dynamorio.bat
echo if "%%1"=="" goto usage >> build\tracer_dynamorio.bat
echo file "%%1" ^| find /i "PE32+" ^>nul >> build\tracer_dynamorio.bat
echo if errorlevel 1 goto use_32bit >> build\tracer_dynamorio.bat
echo :use_64bit >> build\tracer_dynamorio.bat
echo call "%%~dp0tracer_dynamorio_x64.bat" %%* >> build\tracer_dynamorio.bat
echo goto end >> build\tracer_dynamorio.bat
echo :use_32bit >> build\tracer_dynamorio.bat
echo call "%%~dp0tracer_dynamorio_x86.bat" %%* >> build\tracer_dynamorio.bat
echo goto end >> build\tracer_dynamorio.bat
echo :usage >> build\tracer_dynamorio.bat
echo echo Usage: tracer_dynamorio.bat your_program.exe [args...] >> build\tracer_dynamorio.bat
echo :end >> build\tracer_dynamorio.bat

echo ✓ Created: build\tracer_dynamorio.bat (auto-detection)
goto :eof

:create_dr_wrapper_x64
echo Creating DynamoRIO 64-bit wrapper...
echo @echo off > build\tracer_dynamorio.bat
echo echo Starting 64-bit DynamoRIO enhanced instruction trace... >> build\tracer_dynamorio.bat
echo "%DYNAMORIO_HOME%\bin64\drrun.exe" -c "%CD%\build\x64\Release\instruction_tracer.dll" -- %%* >> build\tracer_dynamorio.bat
echo ✓ Created: build\tracer_dynamorio.bat
goto :eof

:create_dr_wrapper_x86
echo Creating DynamoRIO 32-bit wrapper...
echo @echo off > build\tracer_dynamorio.bat
echo echo Starting 32-bit DynamoRIO enhanced instruction trace... >> build\tracer_dynamorio.bat
echo "%DYNAMORIO_HOME%\bin32\drrun.exe" -c "%CD%\build\x86\Release\instruction_tracer.dll" -- %%* >> build\tracer_dynamorio.bat
echo ✓ Created: build\tracer_dynamorio.bat
goto :eof

:final_summary
echo.
echo ================================================================
echo                        BUILD SUMMARY
echo ================================================================
echo.
echo Regular API Tracer (breakpoint-based):
if exist build\argustrace64.exe echo   ✓ build\argustrace64.exe (64-bit)
if exist build\argustrace32.exe echo   ✓ build\argustrace32.exe (32-bit)
if exist build\instruction_analyzer.exe echo   ✓ build\instruction_analyzer.exe (post-processor for DynamoRIO)
if not exist build\argustrace64.exe if not exist build\argustrace32.exe echo   ✗ No regular tracers built

echo.
echo DynamoRIO Enhanced Tracer (instruction-level):
if exist build\x64\Release\instruction_tracer.dll echo   ✓ 64-bit DLL built
if exist build\x86\Release\instruction_tracer.dll echo   ✓ 32-bit DLL built
if exist build\tracer_dynamorio.bat echo   ✓ build\tracer_dynamorio.bat (wrapper)
if not exist build\x64\Release\instruction_tracer.dll if not exist build\x86\Release\instruction_tracer.dll echo   ✗ No DynamoRIO tracers built

echo.
echo Usage:
echo ------
echo Regular API Tracer:
echo   build\argustrace64.exe  (choose option 1 for breakpoint tracing)
echo   build\argustrace32.exe  (choose option 1 for breakpoint tracing)
echo.
echo DynamoRIO Enhanced Tracer:
echo   build\argustrace64.exe  (choose option 2 for DynamoRIO tracing)
echo   OR directly: build\tracer_dynamorio.bat target.exe
echo   THEN run: build\instruction_analyzer.exe (to analyze the output)
echo.
echo Complete DynamoRIO Workflow:
echo   1. build\tracer_dynamorio.bat target.exe
echo   2. build\instruction_analyzer.exe
echo   3. Check api_calls_detected.log for results
echo.
echo Output files (DynamoRIO):
echo   - instructions.log (full instruction trace)
echo   - all_modules_functions.log (module information)
echo   - api_calls_detected.log (analyzed API calls - run instruction_analyzer.exe)
echo.

if exist build\dynamorio_build_x64 (
    echo Cleaning up temporary x64 build files...
    rmdir /s /q build\dynamorio_build_x64
)
if exist build\dynamorio_build_x86 (
    echo Cleaning up temporary x86 build files...
    rmdir /s /q build\dynamorio_build_x86
)
