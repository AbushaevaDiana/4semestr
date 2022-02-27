@echo off

set PROGRAM="%~1"

set IN1="input1.txt"
set OUT1="1output.txt"
set CORRECT1="test1_out.txt"

%PROGRAM% %IN1% %OUT1% ma pa || goto err
fc %OUT1% %CORRECT1% || goto err

set IN2="input2.txt"
set OUT2="2output.txt"
set CORRECT2="test2-out.txt"

%PROGRAM% %IN2% %OUT2% 1231234 * || goto err
fc %OUT2% %CORRECT2% || goto err

set IN1="input3.txt"
set OUT1="3output.txt"
set CORRECT1="test3-out.txt"

%PROGRAM% %IN1% %OUT1% dog cat || goto err
fc %OUT1% %CORRECT1% || goto err

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1