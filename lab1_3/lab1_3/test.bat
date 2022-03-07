@echo off

set PROGRAM="%~1"

::
set OUT1="output1.txt"
set IN1="input1.txt"
set CORRECT1="test1-out.txt"
%PROGRAM% %IN1% > %OUT1% || goto err
fc %OUT1% %CORRECT1% || goto err
echo Test 1 passed

::
set OUT2="output2.txt"
set IN2="input2.txt"
set CORRECT2="test2-out.txt"
%PROGRAM% %IN2% > %OUT2% || goto err
fc %OUT2% %CORRECT2% || goto err
echo Test 2 passed

::������������ ���������� ����������
set OUT3="output3.txt"
set CORRECT3="test3-out.txt"
%PROGRAM%  > %OUT3% || goto err
fc %OUT3% %CORRECT3% || goto err
echo Test 3 passed

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1