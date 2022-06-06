#pragma once
#include <string>
#include <vector>

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	//i должна иметь тип size_t +
	//присваивать maxValue только, после того как нашли max +
	size_t indexOfMax = 0;
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (less(arr[indexOfMax], arr[i]))
		{
			indexOfMax = i;
		}
	}
	maxValue = arr[indexOfMax];
	return true;
}

