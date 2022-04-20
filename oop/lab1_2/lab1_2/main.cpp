#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>

// сравнивать по коду, в отдельных функциях
//массив строк убрать, перегон инт в чар
//уменьшить вложенность
//другой способ перевода
//константы глобально
//камел кейс всех переменных и функций

const int baseMax = 36;
const int baseMin = 2;
unsigned int max = 2147483648;

// убрать ссылку
int CharToInt(const char& ch)
{
    if (ch <= '9' && ch >= '0')
    {
        return (long long)ch - '0';
    }
    return 10 + ch - 'A';
}

//long long на int  убрать ссылку
char IntToChar(long long& num)
{
    if (num <= 9)
    {
        return (char)(num + '0');
    }
    return 'A' + (char)(num - 10);
}


unsigned int StringToInt(const std::string &str, int base, bool& wasError)
{
    unsigned int result = 0;

    if (!(baseMin <= base && base <= baseMax))
    {
        wasError = true;
        return result;
    };

    for (int i = 0, counter = str.length() - 1; i < str.length(); ++i, --counter) 
    {
        int digit = CharToInt(str[i]);

        if (digit >= base)
        {
            wasError = true;
            break;
        }
        //переполнение проверять по другому, из макса вычитать делить    
        if (result + digit > max)
        {
            wasError = true;
            break;
        }
        result += digit;
            
        if (counter > 0 && result * base > max)
        {
            wasError = true;
            break;
        }

        if (counter > 0)
        {
            result *= base;
        };

    }
   
    return result;
}

std::string IntToString(unsigned int number, int base, bool& wasError) {
    std::string result;

    if (!(baseMin <= base && base <= baseMax))
    {
        wasError = true;
        return result;
    };  
    do 
    {
        long long pos = number % base;
        char ch = IntToChar(pos);
        result.insert(0, 1, ch);
        number /= base;
    } while (number != 0);
   
    return result;
}

//ноль только в случае корректной работы, иначе с другим кодом
int main(int argc, char* argv[]) {
    bool wasError = false;

    if (argc != 4)
    {
        std::cout << "Invalid input format";
        return 0;
    }

    int inNotation = StringToInt(argv[1], 10, wasError);
    int outNotation = StringToInt(argv[2], 10, wasError);
    
    if (wasError)
    {
        std::cout << "Invalid notation format";
        return 0;
    };
    
    std::string numStr = argv[3];
    std::string minus;
    //вынести все лишнее из main
    if (numStr[0] == '-')
    {
        minus = "-";
        numStr.erase(0, 1);
    };

    unsigned int num = StringToInt(numStr, inNotation, wasError);
    if (minus != "-" && num > INT_MAX)
    {
        std::cout << "Overflow";
        return 0;
    }

    if (wasError)
    {
        std::cout << "Invalid number format or notation";
        return 0;
    };

    std::string result = IntToString(num, outNotation, wasError);

    if (wasError)
    {
        std::cout << "Invalid notation";
        return 0;
    };

    std::cout << minus << result;
   
    return 0;
}