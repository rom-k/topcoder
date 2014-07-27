@echo off

cd /d %~dp0

if exist %USERPROFILE%\contestapplet.conf (
    del %USERPROFILE%\contestapplet.conf
)
if exist %USERPROFILE%\contestapplet.conf.bak (
    del %USERPROFILE%\contestapplet.conf.bak
)

if exist conf\contestapplet.conf (
    copy conf\contestapplet.conf %USERPROFILE%\contestapplet.conf >nul
)
if exist conf\contestapplet.conf.bak (
    copy conf\contestapplet.conf.bak %USERPROFILE%\contestapplet.conf.bak >nul
)

conf\ContestAppletProd.jnlp
