#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab7_1/FindMaxEx.h"

TEST_CASE("correct")
{
	SECTION("int")
	{
		std::vector<int> arr = { 1, 67, 4, 9, 34 };
		int max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(max == 67);
		REQUIRE(isFunctionWork == true);
	}

	SECTION("double")
	{
		std::vector<double> arr = { 1.1 , 67.4 , 67.4, 67.9, 34.0 };
		double max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(max == 67.9);
		REQUIRE(isFunctionWork == true);
	}

	SECTION("srting")
	{
		std::vector<std::string> arr = { "1", "12", "1234"};
		std::string max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(max == "1234");
		REQUIRE(isFunctionWork == true);
	}

	SECTION("const char*")
	{

		std::vector<const char*> arr = { "a", "", "ac", "ab", "Ab" };
		const char* max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(max == "ac");
		REQUIRE(isFunctionWork == true);
	}

	SECTION("only one number in array")
	{
		std::vector<int> arr = { 1 };
		int max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(max == 1);
		REQUIRE(isFunctionWork == true);
	}

	SECTION("Sportsman")
	{
		std::vector<Sportsman> arr = { {"Peter", 170, 90}, {"James", 180, 87}, {"Williams", 178, 98}};
		Sportsman max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max, [](Sportsman a, Sportsman b) {return a.height < b.height;});
		REQUIRE(isFunctionWork == true);
		REQUIRE(max.name == "James");
		isFunctionWork = FindMaxEx(arr, max, [](Sportsman a, Sportsman b) {return a.weight < b.weight;});
		REQUIRE(isFunctionWork == true);
		REQUIRE(max.name == "Williams");
	}

}

TEST_CASE("incorrect data")
{
	SECTION("empty array of int")
	{
		std::vector<int> arr = {};
		int max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max);
		REQUIRE(isFunctionWork == false);
	}

	SECTION(" empty array of Sportsman")
	{
		std::vector<Sportsman> arr = { };
		Sportsman max;
		bool isFunctionWork;
		isFunctionWork = FindMaxEx(arr, max, [](Sportsman a, Sportsman b) {return a.height < b.height;});
		REQUIRE(isFunctionWork == false);
		isFunctionWork = FindMaxEx(arr, max, [](Sportsman a, Sportsman b) {return a.weight < b.weight;});
		REQUIRE(isFunctionWork == false);
	}

}