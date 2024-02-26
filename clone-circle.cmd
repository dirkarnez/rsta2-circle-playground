@REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

SET PATH=^
%DOWNLOADS_DIR%\PortableGit\bin;

cd /d "%DOWNLOADS_DIR%" &&^
git clone --recurse-submodules https://github.com/rsta2/circle.git && cd circle && git checkout Step45.3.1 &&^
pause