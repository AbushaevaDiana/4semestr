#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab7_1/FindMaxEx.h"

struct Sportsman
{
	std::string name;
	int height;
	int weight;
};

TEST_CASE("correct")
{
	SECTION("int")
	{
		std::vector<int> arr = { 1, 67, 4, 9, 34 };
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b;});
		REQUIRE(max == 67);
		REQUIRE(isArrayNotEmpty == true);
	}

	SECTION("double")
	{
		std::vector<double> arr = { 1.1 , 67.4 , 67.4, 67.9, 34.0 };
		double max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](double a, double b) {return a < b;});
		REQUIRE(max == 67.9);
		REQUIRE(isArrayNotEmpty == true);
	}

	SECTION("srting")
	{
		std::vector<std::string> arr = { "1", "12", "1234"};
		std::string max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](std::string const& a, std::string const& b) {return a < b;});
		REQUIRE(max == "1234");
		REQUIRE(isArrayNotEmpty == true);
	}

	SECTION("only one number in array")
	{
		std::vector<int> arr = { 1 };
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b;});
		REQUIRE(max == 1);
		REQUIRE(isArrayNotEmpty == true);
	}

	SECTION("Sportsman")
	{
		std::vector<Sportsman> arr = { {"Peter", 170, 90}, {"James", 180, 87}, {"Williams", 178, 98}};
		Sportsman max;
		bool isArrayNotEmpty;
		//спортсменов по константной ссылке +
		//переименовать isFunctionWork +
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.height < b.height;});
		REQUIRE(isArrayNotEmpty == true);
		REQUIRE(max.name == "James");
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.weight < b.weight;});
		REQUIRE(isArrayNotEmpty == true);
		REQUIRE(max.name == "Williams");
	}

}

TEST_CASE("incorrect data")
{
	SECTION("empty array of int")
	{
		std::vector<int> arr = {};
		int max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](int a, int b) {return a < b;});
		REQUIRE(isArrayNotEmpty == false);
	}

	SECTION(" empty array of Sportsman")
	{
		std::vector<Sportsman> arr = { };
		Sportsman max;
		bool isArrayNotEmpty;
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.height < b.height;});
		REQUIRE(isArrayNotEmpty == false);
		isArrayNotEmpty = FindMaxEx(arr, max, [](Sportsman const& a, Sportsman const& b) {return a.weight < b.weight;});
		REQUIRE(isArrayNotEmpty == false);
	}

}