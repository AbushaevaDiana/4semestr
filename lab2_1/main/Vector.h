#pragma once
#include<vector>
#include <iosfwd>

std::vector<float> inputVector(std::vector<float> v, std::istream& cin);

void outputVector(std::vector<float> v, std::ostream& cout);

std::vector<float> processingVector(std::vector<float> v);