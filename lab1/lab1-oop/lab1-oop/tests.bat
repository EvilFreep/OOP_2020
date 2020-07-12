@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM copy empty file
echo copy empty file
%MyProgram% Empty.txt output.txt "1" "2" || goto err
fc Empty.txt output.txt || goto err
echo success!

REM not enough arguments
echo not enough arguments
%MyProgram% input.txt output.txt && goto err
echo success!

REM not exist input file
echo not exist input file
%MyProgram% input1.txt output.txt "pa" "papa" && goto err
echo success!

REM проверка замены повтор€ющихс€ символов (а на аа)
echo check replace repeat syms
%MyProgram% input.txt output.txt "pa" "papa" || goto err
echo success!

REM tests are finished success
echo Tests are passed
exit/B 0

REM error
:err 
echo Test failed
exit /B 1