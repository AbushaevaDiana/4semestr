#include "Vector.h"
#include <iostream>
#include <iomanip>

std::vector<float> inputVector(std::vector<float> v, std::istream& cin)
{
    while (true)
    {
        float inputVectorFl;
        cin >> inputVectorFl;

        if (!cin)
            break;

        v.push_back(inputVectorFl);
    }

    return v;
}

void outputVector(const std::vector<float>& v, std::ostream& cout)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << std::fixed << std::setprecision(3) << std::fixed << std::setprecision(3) << v[i] << " ";
    }
}

std::vector<float> processingVector(std::vector<float> v)
{
    std::vector<float> emptyV = {};
    if (v == emptyV)
    {
        return v;
    }

    float max = v[0];
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    };

    max = max / 2;

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = v[i] / max;
    }

    return v;
}
