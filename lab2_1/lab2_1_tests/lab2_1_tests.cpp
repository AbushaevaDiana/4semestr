
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../main/Vector.h"

SCENARIO("Empty entered - input")
{
	std::istringstream input("");
	std::vector<float> v;
	std::vector<float> out = { };
	REQUIRE(inputVector(v, input) == out);
};

SCENARIO("One number entered - input")
{
	std::istringstream input("1.0");
	std::vector<float> v;
	std::vector<float> out = {1.0};
	REQUIRE(inputVector(v, input) == out);
};

SCENARIO("Some numbers entered - input")
{
	std::istringstream input("1.0 2.009 3.454 2.333");
	std::vector<float> v;
	std::vector<float> out = { 1.0,  2.009, 3.454, 2.333 };
	REQUIRE(inputVector(v, input) == out);
};

SCENARIO("Output")
{
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		THEN("output stream is empty")
		{
			std::ostringstream output;
			std::vector<float> v;
			outputVector(inputVector(v, input), output);
			CHECK(output.str().empty());
		}
	}

	WHEN("input stream include one number")
	{
		std::istringstream input("-2.333");
		THEN("output stream include one number")
		{
			std::ostringstream output;
			std::vector<float> v;
			outputVector(inputVector(v, input), output);
			CHECK(output.str() == "-2.333 ");
		}
	}

	WHEN("input stream include some numbers")
	{
		std::istringstream input("-2.333 5.909 5.333 111.333 4.0");
		THEN("output stream include some numbers")
		{
			std::ostringstream output;
			std::vector<float> v;
			outputVector(inputVector(v, input), output);
			CHECK(output.str() == "-2.333 5.909 5.333 111.333 4.000 ");
		}
	}
};

SCENARIO("Processing")
{
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		THEN("output stream is empty")
		{
			std::ostringstream output;
			std::vector<float> v;
			std::vector<float> out;
			out = processingVector(inputVector(v, input));
			outputVector(out, output);
			CHECK(output.str().empty());
		}
	}

	WHEN("input stream include one number")
	{
		std::istringstream input("-2.444");
		THEN("output stream include one number")
		{
			std::ostringstream output;
			std::vector<float> v;
			std::vector<float> out;
			out = processingVector(inputVector(v, input));
			outputVector(out, output);
			CHECK(output.str() == "2.000 ");
		}
	}

	WHEN("input stream include some numbers")
	{
		std::istringstream input("-2.886 3.278 7.0 4.0");
		THEN("output stream include some numbers")
		{
			std::ostringstream output;
			std::vector<float> v;
			std::vector<float> out;
			out = processingVector(inputVector(v, input));
			outputVector(out, output);
			CHECK(output.str() == "-0.825 0.937 2.000 1.143 ");
		}
	}
};



