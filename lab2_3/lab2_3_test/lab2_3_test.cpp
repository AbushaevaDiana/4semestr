#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab2_3/Dictionary.h"

SCENARIO("Valid data with one word")
{
	std::wifstream fileIn;
	fileIn.open("dictionary1.txt");
	std::wstring word = L"cat";
	REQUIRE(fileIn.is_open());
};

