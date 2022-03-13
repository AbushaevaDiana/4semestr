// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Vector.h"
#include <iostream>
#include <vector>

//Разделить элементы массива на половину максимального элемента

int main()
{
    std::vector<float> v;
    inputVector(v, std::cin);
    processingVector(v);
    outputVector(v, std::cout);
    return 0;
}

