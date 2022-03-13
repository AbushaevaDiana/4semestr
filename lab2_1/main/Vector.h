#pragma once
#include<vector>
#include <iosfwd>

std::vector<float> inputVector(std::vector<float> v, std::istream& cin);

void outputVector(const std::vector<float>& v, std::ostream& cout);

std::vector<float> processingVector(std::vector<float> v);