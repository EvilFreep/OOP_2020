@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

echo too many args of cmd
%MyProgram% 1 2 3 && goto err
echo success!

echo not enought args of cmd
%MyProgram% && goto err
echo success!

echo incorrect sym as arg
%MyProgram% lfg1 && goto err
echo success!

echo incorrect number
%MyProgram% 1000 && goto err
echo success!

echo incorrect number
%MyProgram% -1000 && goto err
echo success!

echo correct input
%MyProgram% 23 || goto err
echo success!

REM tests are finished success
echo Tests are passed
exit /B 0

REM error
:err 
echo Test failed
exit /B 1