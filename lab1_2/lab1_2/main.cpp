#include <iostream>
#include <fstream>

//константы глобально
//камел кейс всех переменных и функций

const int baseMax = 36;
const int baseMin = 2;

int StringToInt(const std::string &str, int base, bool& wasError) 
{
    int result = 0;
    const std::string k_base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";

    if (baseMin <= base && base <= baseMax)
    {
        for (int i = str.length() - 1, counter = 0; i >= 0; --i, ++counter) {
            int digit = -1;
            // сравнивать по коду, в отдельных функциях
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
                //другой способ перевода
                int stepB = 1;
                if (counter > 0)
                {
                    for (int a = 1; a <= counter; a++)
                    {
                        stepB = stepB * base;
                    }
                }
                if (INT_MAX - result >= digit * stepB)
                {
                    result += digit * stepB;
                }
                else
                {
                    wasError = true;
                    break;
                }
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
    if (baseMin <= base && base <= baseMax)
    {
        const std::string base_symbols[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H",
    "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "A", "S", "U", "V", "W", "X", "Y", "Z" };
        do {
            int pos = number % base;
            //массив строк убрать, перегон инт в чар
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

    if (argc != 4)
    {
        std::cout << "Invalid input format";
        return 0;
    }

    int inNotation = StringToInt(argv[1], 10, wasError);
    int outNotation = StringToInt(argv[2], 10, wasError);
    //уменьшить вложенность
    
    if (!wasError) {
        std::string numStr = argv[3];
        std::string minus;
        //минус в функцию перевода
        if (numStr[0] == '-')
        {
            minus = "-";
            numStr.erase(0, 1);
        }
        int num = StringToInt(numStr, inNotation, wasError);
        if (!wasError)
        {
            std::string result = IntToString(num, outNotation, wasError);
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