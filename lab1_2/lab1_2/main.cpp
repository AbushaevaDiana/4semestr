#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

int FromBase(const std::string str, int base, bool& wasError) {
    int result = 0;
    const std::string k_base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";
    const int base_max = 36;
    const int base_min = 2;
    if (base_min <= base && base <= base_max)
    {
        for (int i = str.length() - 1, counter = 0; i >= 0; --i, ++counter) {
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
    }
    else
    {
        wasError = true;
    }
    return result;
}

std::string IntToString(int number, int base, bool& wasError) {
    std::string result;
    const int base_max = 36;
    const int base_min = 2;
    if (base_min <= base && base <= base_max)
    {
        const std::string base_symbols[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H",
    "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "A", "S", "U", "V", "W", "X", "Y", "Z" };
        do {
            int pos = number % base;
            std::string s = base_symbols[number % base];
            result.insert(0, s);
            number /= base;
        } while (number != 0);
    }
    else
    {
        wasError = true;
    }
    return result;
}

int main(int argc, char* argv[]) {
    bool wasError = false;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_ALL, "Russian");
    setlocale(0, "Rus");


        int in_notation = FromBase(argv[1], 10, wasError);
        int out_notation = FromBase(argv[2], 10, wasError);
        if (!wasError) {
            std::string numStr = argv[3];
            std::string minus;
            if (numStr[0] == '-')
            {
                minus = "-";
                numStr.erase(0, 1);
            }
            int num = FromBase(numStr, in_notation, wasError);
            if (!wasError)
            {
                std::string result = IntToString(num, out_notation, wasError);
                if (!wasError) { std::cout << minus << result; }
                else { std::cout << "Invalid notation"; }
            }
            else
            {
                std::cout << "Invalid number format or notation";
            }

        }
        else
        {
             std::cout << "Invalid notation format";
        }


    return 0;
}