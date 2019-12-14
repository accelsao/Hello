@echo off  
:loop  
    data.exe %random% > data.in
    participant.exe < data.in > participant.out
    jury.exe < data.in > jury.out
    fc jury.out participant.out 
if not errorlevel 1 goto loop  
pause
goto loop
