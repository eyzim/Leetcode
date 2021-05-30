@echo off
setlocal enabledelayedexpansion

for %%F in (*.cpp) do (
    set "filename=%%~nF"
    set "filename=!filename:.= .!"
    set "filename=!filename:-= !"
    set "folder_name=!filename:~0,-4!"
    set /a "number=folder_name / 100 * 100 + 1"
    set /a "end_number=(folder_name / 100 + 1) * 100"
    set "folder_name=!number!-!end_number!"
    mkdir "!folder_name!"
    move "%%F" "!folder_name!"
)
