@echo off
setlocal

:: Set default build variables
set BUILD_DIR=build
set GENERATOR="Visual Studio 17 2022"
set CONFIG=Release

:: Parse command-line arguments
if "%1"=="--debug" (
    set CONFIG=Debug
    echo Building in Debug mode...
) else if "%1"=="--release" (
    set CONFIG=Release
    echo Building in Release mode...
) else if "%1"=="" (
    echo No build mode specified. Using default: %CONFIG%
) else (
    echo Unknown argument: %1
    echo Usage: build.bat [--debug^|--release]
    echo Defaulting to: %CONFIG%
)

:: Create build directory if it doesn't exist
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

:: Navigate to build directory
cd %BUILD_DIR%

:: Run CMake to configure the project
cmake -G %GENERATOR% -DCMAKE_BUILD_TYPE=%CONFIG% ..

:: Build the project
cmake --build . --config %CONFIG%

:: Return to the original directory
cd ..

echo Build process completed for %CONFIG% configuration.
