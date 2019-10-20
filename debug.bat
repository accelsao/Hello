@echo off  
:loop  
    data.exe %random% > data.in
    std.exe < data.in > std.out
    bob.exe < data.in > bob.out
    fc std.out bob.out 
if not errorlevel 1 goto loop  
pause
goto loop
