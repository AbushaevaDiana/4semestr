@echo off

set PROGRAM="%~1"

set IN1="input1.txt"
set OUT1="1output.txt"
set CORRECT1="test1_out.txt"

:: обычный, несколько замен
%PROGRAM% %IN1% %OUT1% ma pa || goto err
fc %OUT1% %CORRECT1% || goto err

:: случай с сложной под строкой
set IN2="input2.txt"
set OUT2="2output.txt"
set CORRECT2="test2-out.txt"

%PROGRAM% %IN2% %OUT2% 1231234 * || goto err
fc %OUT2% %CORRECT2% || goto err

:: обычный, одно вхождение
set IN3="input3.txt"
set OUT3="3output.txt"
set CORRECT3="test3-out.txt"

%PROGRAM% %IN3% %OUT3% dog cat || goto err
fc %OUT3% %CORRECT3% || goto err

::неправильное количесвто параметров
set OUT4="output4.txt"
set CORRECT4="test4-out.txt"
%PROGRAM% cat > %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err
echo —---

:: в качестве заменяемой строки переданна пустая строка
set IN5="input5.txt"
set OUT5="5output.txt"
set CORRECT5="test5-out.txt"

%PROGRAM% %IN5% %OUT5% "" cat || goto err
fc %OUT5% %CORRECT5% || goto err

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1