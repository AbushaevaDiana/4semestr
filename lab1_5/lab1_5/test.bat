@echo off

set PROGRAM="%~1"

::все границы закрыты, начальные точки внутри границ
set IN1="test1.txt"
set OUT1="1output.txt"
set CORRECT1="test1_out.txt"
%PROGRAM% %IN1% %OUT1% || goto err
fc %OUT1% %CORRECT1% || goto err

::все границы закрыты, есть начальная точка вне контура
set IN2="test2.txt"
set OUT2="2output.txt"
set CORRECT2="test2_out.txt"
%PROGRAM% %IN2% %OUT2% || goto err
fc %OUT2% %CORRECT2% || goto err

::граница не замкнута, начальные точки внутри границ
set IN3="test3.txt"
set OUT3="3output.txt"
set CORRECT3="test3_out.txt"
%PROGRAM% %IN3% %OUT3% || goto err
fc %OUT3% %CORRECT3% || goto err

::нет начальных точек
set IN4="test4.txt"
set OUT4="4output.txt"
set CORRECT4="test4_out.txt"
%PROGRAM% %IN4% %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err

::неверное колличество параметров
set IN5="test1.txt"
%PROGRAM% %IN5% && goto err

::есть элементы за пределлами 100 столбца
set IN6="test6.txt"
set OUT6="6output.txt"
set CORRECT6="test6_out.txt"
%PROGRAM% %IN6% %OUT6% || goto err
fc %OUT6% %CORRECT6% || goto err

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1