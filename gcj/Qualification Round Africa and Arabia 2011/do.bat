@echo off
cd %~dp0
gcc -oa "%1" -lstdc++
if "%3"=="" goto noout
a.exe < "%2" > "%3"
goto end
:noout
a.exe < "%2"
:end
