#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

int FromBase(const std:: string str, int base, bool& wasError) {
    int result = 0;
    const std::string k_base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";
    const int base_max = 36;
    const int base_min = 2;
    if (base_min <= base && base <= base_max)
    {
        for (size_t i = str.length()-1, counter = 0; i >= 0; --i, ++counter) {
            signed int digit = -1;
            for (int j = 0; j < base; j++)
            {
                if (str[i] == k_base_symbols[j])
                {
                    digit = j;
                    break;
                };
            };
            if (digit != -1)
            {
                int stepB = 1;
                if (counter > 0)
                {
                    for (int a = 1; a <= counter; a++)
                    {
                        stepB = stepB * base;
                    }
                }
                result += digit * stepB;
            }
            else
            {
                wasError = true;
                break;
            }
        }
    };
    return result;
}

std:: string IntToString(int number, int base) {
    std::string result;
    const std::string base_symbols[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H",
"I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "A", "S", "U", "V", "W", "X", "Y", "Z" };
    do {
        int pos = number % base;
        std::string s = base_symbols[number % base];
        result.insert(0, s);
        number /= base;
    } while (number != 0);

    return result;
}

int main(int argc, char* argv[]) {
    bool wasError = false;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_ALL, "Russian");
    setlocale(0, "Rus");

    //Открытие файлов
    std::ofstream fileOut;
    fileOut.open("output.txt");

    if (fileOut.is_open())
    {
        int in_notation = FromBase(argv[1], 10, wasError);
        int out_notation = FromBase(argv[2], 10, wasError);
        if (!wasError) {
            int num = FromBase(argv[3], in_notation, wasError);
            if (!wasError) 
            { 
                fileOut << IntToString(num, out_notation);
            }
            else
            {
                fileOut << "Invalid number format";
            }
        }
        else
        {
            fileOut << "Invalid notation format";
        }
        //Закрытие файлов
        fileOut.close();
    }
    else
        std::cout << "Ошибка открытия файла!" << std::endl;

    return 0;
}