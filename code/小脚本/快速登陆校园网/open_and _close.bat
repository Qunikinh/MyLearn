@echo off
start "" "http://1.1.1.1"

timeout /t 5 /nobreak >nul

taskkill  /im msedge.exe /f /t