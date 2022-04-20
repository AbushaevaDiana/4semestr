@echo off

set PROGRAM="%~1"

:: обычный, несколько замен
set IN1="simple.txt"
set OUT1="simple_output.txt"
set CORRECT1="simple_test_out.txt"
%PROGRAM% %IN1% %OUT1% ma pa || goto err
fc %OUT1% %CORRECT1% || goto err

:: случай с сложной подстрокой
set IN2="complex_substring.txt"
set OUT2="complex_substring_output.txt"
set CORRECT2="complex_substring_output_test-out.txt"
%PROGRAM% %IN2% %OUT2% 1231234 * || goto err
fc %OUT2% %CORRECT2% || goto err


::неправильное количесвто параметров
set OUT4="involid_parametrs_out.txt"
set CORRECT4="involid_parametrs-out.txt"
%PROGRAM% cat > %OUT4% || goto err
fc %OUT4% %CORRECT4% || goto err
echo —---

:: в качестве заменяемой строки переданна пустая строка
set IN5="empty_line.txt"
set OUT5="empty_line_output.txt"
set CORRECT5="empty_line_test-out.txt"
%PROGRAM% %IN5% %OUT5% "" cat || goto err
fc %OUT5% %CORRECT5% || goto err

:: много замен
set IN6="big_data.txt"
set OUT6="big_data_out.txt"
set CORRECT6="big_data_test_out.txt"
%PROGRAM% %IN6% %OUT6% ma pa || goto err
fc %OUT6% %CORRECT6% || goto err

echo All tests passed
exit /B 0

:err
echo Program testing faile
exit /B 1