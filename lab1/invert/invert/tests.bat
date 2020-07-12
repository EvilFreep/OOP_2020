@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

echo correct input
%MyProgram% "tests/input1.txt"
fc "output.txt" "tests/output1.txt" || goto err
echo success!

echo non exist file
%MyProgram% "tests/input0.txt"
fc "output.txt" "tests/output0.txt" || goto err
echo success!

echo determ is equal 0
%MyProgram% "tests/input2.txt"
fc "output.txt" "tests/output2.txt" || goto err
echo success!

REM tests are finished success
echo Tests are passed
exit /B 0

REM error
:err 
echo Test failed
exit /B 1