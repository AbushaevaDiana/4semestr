#include <iostream>
#include <fstream>

//уменьшить вложенность
//другой способ перевода
//константы глобально
//камел кейс всех переменных и функций

const int baseMax = 36;
const int baseMin = 2;
unsigned int max = 2147483648;

unsigned int StringToInt(const std::string &str, int base, bool& wasError)
{
    unsigned int result = 0;
    const std::string k_base_symbols = "0123456789ABCDEFGHIJKLMNOPQRASUVWXYZ";
    int sign = 0;

    if (!(baseMin <= base && base <= baseMax))
    {
        wasError = true;
        return result;
    };
    for (int i = sign, counter = str.length() - 1; i < str.length(); ++i, --counter) 
    {
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
    const std::string base_symbols[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H",
    "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "A", "S", "U", "V", "W", "X", "Y", "Z" };
        
    do 
    {
        int pos = number % base;
            //массив строк убрать, перегон инт в чар
        std::string s = base_symbols[number % base];
        result.insert(0, s);
        number /= base;
    } while (number != 0);
   
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
    
    if (wasError)
    {
        std::cout << "Invalid notation format";
        return 0;
    };
    
    std::string numStr = argv[3];
    std::string minus;
        //минус в функцию перевода
        
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