@echo off

set PROGRAM="%~1"

::обычный перевод
set OUT1="output1.txt"
set CORRECT1="test1-out.txt"
::4
echo Ч4Ч
%PROGRAM% 16 10 1F > %OUT1% || goto err
fc %OUT1% %CORRECT1% || goto err
echo Ч---

::число не удовлетвор€ет первичной системе счислени€
set OUT2="2output.txt"
set CORRECT2="test2-out.txt"
::4
echo Ч4Ч
%PROGRAM% 3 16 56 > %OUT2% || goto err
fc %OUT2% %CORRECT2% || goto err
echo Ч---

::система счислени€ задана неверно
set OUT3="output3.txt"
set CORRECT3="test3-out.txt"
::4
echo Ч4Ч
%PROGRAM% f 8 11 > %OUT3% || goto err
fc %OUT3% %CORRECT3% || goto err
echo Ч---

::перевод с минусом
set OUT4="output4.txt"
set CORRECT4="test4-out.txt"
::4
echo Ч4Ч
%PROGRAM% 16 10 -F > %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err
echo Ч---


::граничное значени системы счислени€
set OUT5="output5.txt"
set CORRECT5="test5-out.txt"
::4
echo Ч4Ч
%PROGRAM% 37 10 13 > %OUT5% || goto err
fc %OUT5% %CORRECT5% || goto err
echo Ч---

::граничное значени системы счислени€
set OUT6="output6.txt"
set CORRECT6="test6-out.txt"
::4
echo Ч4Ч
%PROGRAM% 10 1 13 > %OUT6% || goto err
fc %OUT6% %CORRECT6% || goto err
echo Ч---

::ноль
set OUT7="output7.txt"
set CORRECT7="test7-out.txt"
::4
echo Ч4Ч
%PROGRAM% 10 2 0 > %OUT7% || goto err
fc %OUT7% %CORRECT7% || goto err
echo Ч---

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1