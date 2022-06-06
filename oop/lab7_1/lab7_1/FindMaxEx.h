#pragma once
#include <string>
#include <vector>

struct Sportsman
{
	std::string name;
    int height;
	int weight;
};

template < typename T >
bool FindMaxEx(std::vector<T> const& arr, T& maxValue)
{
	if (arr.empty())
	{
		return false;
	}

	maxValue = arr[0];

	for (auto i = 1; i < arr.size(); i++)
	{
		if (maxValue < arr[i])
		{
			maxValue = arr[i];
		}
	}

	return true;
}

template <>
bool FindMaxEx<const char*>(std::vector<const char*> const& arr, const char*& maxValue)
{
	if (arr.empty())
	{
		return false;
	}

	maxValue = arr[0];

	for (auto i = 1; i < arr.size(); i++)
	{
		if (std::strcmp(arr[i], maxValue) > 0)
		{
		    maxValue = arr[i];
		}
	}
	return true;
}

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	maxValue = arr[0];

	for (auto i = 1; i < arr.size(); i++)
	{
		if (less(maxValue, arr[i]))
		{
			maxValue = arr[i];
		}
	}
	return true;
}

