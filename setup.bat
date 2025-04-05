REM filepath: c:\Dev\Projects\Setuav\Setuav\setup.bat
:: This script will be used to set up the environment for the project. 
:: Install necessary dependencies and set up the build environment.
:: This script is intended to be run in a Windows environment with Visual Studio installed.
:: For Linux or Mac, use the appropriate shell script (setup.sh).
:: For building the project, use build.bat or build.sh as appropriate.

@echo off
setlocal

set LIB_DIR=Source\Lib
set OPENCASCADE_DIR=%LIB_DIR%\OpenCASCADE

:: Define URLs and file paths for OpenCASCADE and dependencies
set OCCT_URL=https://github.com/Open-Cascade-SAS/OCCT/releases/download/V7_8_0/occt-vc143-64.zip
set OCCT_DEPS_URL=https://github.com/Open-Cascade-SAS/OCCT/releases/download/V7_8_0/3rdparty-vc14-64.zip

set OCCT_ZIP=%TEMP%\occt-vc143-64.zip
set OCCT_DEPS_ZIP=%TEMP%\3rdparty-vc14-64.zip

set OCCT_DIR=%OPENCASCADE_DIR%\occt
set OCCT_DEPS_DIR=%OPENCASCADE_DIR%\3rdparty

:: Create directories if they don't exist
if not exist %LIB_DIR% mkdir %LIB_DIR%
if not exist %OPENCASCADE_DIR% mkdir %OPENCASCADE_DIR%
if not exist %OCCT_DIR% mkdir %OCCT_DIR%
if not exist %OCCT_DEPS_DIR% mkdir %OCCT_DEPS_DIR%

echo ======================================
echo Downloading OpenCASCADE 7.8 Package...
echo ======================================
powershell -Command "& {[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri '%OCCT_URL%' -OutFile '%OCCT_ZIP%'}"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to download OpenCASCADE package.
    exit /b %ERRORLEVEL%
)

echo Extracting OpenCASCADE package...
powershell -Command "& {Expand-Archive -Path '%OCCT_ZIP%' -DestinationPath '%OCCT_DIR%' -Force}"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to extract OpenCASCADE package.
    exit /b %ERRORLEVEL%
)

echo =========================================
echo Downloading OpenCASCADE 7.8 Dependencies...
echo =========================================
powershell -Command "& {[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri '%OCCT_DEPS_URL%' -OutFile '%OCCT_DEPS_ZIP%'}"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to download OpenCASCADE dependencies.
    exit /b %ERRORLEVEL%
)

echo Extracting OpenCASCADE dependencies...
powershell -Command "& {Expand-Archive -Path '%OCCT_DEPS_ZIP%' -DestinationPath '%OCCT_DEPS_DIR%' -Force}"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to extract OpenCASCADE dependencies.
    exit /b %ERRORLEVEL%
)

echo =========================================
echo Installation completed successfully!
echo =========================================
echo OpenCASCADE package installed to: %OCCT_DIR%
echo OpenCASCADE dependencies installed to: %OCCT_DEPS_DIR%
echo.
echo You can now build the project with build.bat

endlocal