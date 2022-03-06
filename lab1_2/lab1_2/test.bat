@echo off

set PROGRAM="%~1"

::обычный перевод
set OUT1="output1.txt"
set CORRECT1="test1-out.txt"
%PROGRAM% 16 10 1F > %OUT1% || goto err
fc %OUT1% %CORRECT1% || goto err
echo Ч---

::число не удовлетвор€ет первичной системе счислени€
set OUT2="2output.txt"
set CORRECT2="test2-out.txt"
%PROGRAM% 3 16 56 > %OUT2% || goto err
fc %OUT2% %CORRECT2% || goto err
echo Ч---

::система счислени€ задана неверно
set OUT3="output3.txt"
set CORRECT3="test3-out.txt"
%PROGRAM% f 8 11 > %OUT3% || goto err
fc %OUT3% %CORRECT3% || goto err
echo Ч---

::перевод с минусом
set OUT4="output4.txt"
set CORRECT4="test4-out.txt"
%PROGRAM% 16 10 -F > %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err
echo Ч---


::граничное значени системы счислени€
set OUT5="output5.txt"
set CORRECT5="test5-out.txt"
%PROGRAM% 37 10 13 > %OUT5% || goto err
fc %OUT5% %CORRECT5% || goto err
echo Ч---

::граничное значени системы счислени€
set OUT6="output6.txt"
set CORRECT6="test6-out.txt"
%PROGRAM% 10 1 13 > %OUT6% || goto err
fc %OUT6% %CORRECT6% || goto err
echo Ч---

::ноль
set OUT7="output7.txt"
set CORRECT7="test7-out.txt"
%PROGRAM% 10 2 0 > %OUT7% || goto err
fc %OUT7% %CORRECT7% || goto err
echo Ч---

::неправильно количнство параметров
set OUT8="output8.txt"
set CORRECT8="test8-out.txt"
%PROGRAM% 2 0 > %OUT8% || goto err
fc %OUT8% %CORRECT8% || goto err
echo Ч---


::переполнение int
set OUT9="output9.txt"
set CORRECT9="test9-out.txt"
%PROGRAM% 10 16 2147483648 > %OUT9% || goto err
fc %OUT9% %CORRECT9% || goto err
echo Ч---

::max int
set OUT10="output10.txt"
set CORRECT10="test10-out.txt"
%PROGRAM% 10 16 2147483647 > %OUT10% || goto err
fc %OUT10% %CORRECT10% || goto err
echo Ч---

::min int
set OUT11="output11.txt"
set CORRECT11="test11-out.txt"
%PROGRAM% 10 20 -2147483648 > %OUT11% || goto err
fc %OUT11% %CORRECT11% || goto err
echo Ч---

::переполнение отрицательных
set OUT12="output12.txt"
set CORRECT12="test12-out.txt"
%PROGRAM% 10 16 -2147483649 > %OUT12% || goto err
fc %OUT12% %CORRECT12% || goto err
echo Ч---


::самое большое число и самое маленькое, переполнение отрицательных

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1