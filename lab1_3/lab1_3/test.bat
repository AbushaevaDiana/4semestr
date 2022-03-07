@echo off

set PROGRAM="%~1"

::матрица с сложными числами
set OUT1="matrix_with_complex_numbers_output.txt"
set IN1="matrix_with_complex_numbers.txt"
set CORRECT1="matrix_with_complex_numbers_test_out.txt"
%PROGRAM% %IN1% > %OUT1% || goto err
fc %OUT1% %CORRECT1% || goto err
echo Test 1 passed

::матрица с простыми числами
set OUT2="simple_matrix_output.txt"
set IN2="simple_matrix.txt"
set CORRECT2="simple_matrix_test_out.txt"
%PROGRAM% %IN2% > %OUT2% || goto err
fc %OUT2% %CORRECT2% || goto err
echo Test 2 passed

::неправильное количество параметров
set OUT3="wrong_parameters_output.txt"
set CORRECT3="wrong_parameters_test_out.txt"
%PROGRAM%  > %OUT3% || goto err
fc %OUT3% %CORRECT3% || goto err
echo Test 3 passed

:: матрица с 0 определителем
set OUT4="determinant_0_output.txt"
set IN4="determinant_0.txt"
set CORRECT4="determinant_0_test_out.txt"
%PROGRAM% %IN4% > %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err
echo Test 4 passed

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1