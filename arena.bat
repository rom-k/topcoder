@echo off

cd /d %~dp0

if exist %USERPROFILE%\contestapplet.conf (
    del %USERPROFILE%\contestapplet.conf
)
if exist %USERPROFILE%\contestapplet.conf.bak (
    del %USERPROFILE%\contestapplet.conf.bak
)

if exist conf\contestapplet.conf.win (
    copy conf\contestapplet.conf.win %USERPROFILE%\contestapplet.conf >nul
)

conf\ContestAppletProd.jnlp

doskey clexe=cl.exe $1.cpp $t$t $1.exe

%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86_amd64

