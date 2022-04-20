
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../main/Vector.h"

// 10 Признаков того, что программирование не для вас
//  - 3. Нехватка настойчивости при возникновении проблемы
//  - 7. Вы не можете думать самостоятельно
//  - 10. Вы не уделяете внимания к деталям

SCENARIO("Empty entered - input")
{
	std::istringstream input("");
	std::vector<float> v;
	std::vector<float> out = { };
	v = inputVector(v, input);
	REQUIRE(v== out);
};

SCENARIO("One number entered - input")
{
	std::istringstream input("1.0");
	std::vector<float> v;
	std::vector<float> out = {1.0};
	v = inputVector(v, input);
	REQUIRE(v == out);
};

SCENARIO("Some numbers entered - input")
{
	std::istringstream input("1.0 2.009 3.454 2.333");
	std::vector<float> v;
	// TODO: fix warning about casting double to float
	std::vector<float> out = {1.0f,  2.009f, 3.454f, 2.333f};
	v = inputVector(v, input);
	REQUIRE(v == out);
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
			v = inputVector(v, input);
			outputVector(v, output);
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
			v = inputVector(v, input);
			outputVector(v, output);
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
			v = inputVector(v, input);
			outputVector(v, output);
			CHECK(output.str() == "-2.333 4.000 5.333 5.909 111.333 ");
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
			//TODO: передавать в процессинг не результат вызова функции, а переменную
			v = inputVector(v, input);
			out = processingVector(v);
			sortVector(out);
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
			v = inputVector(v, input);
			out = processingVector(v);
			sortVector(out);
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
			v = inputVector(v, input);
			out = processingVector(v);
			sortVector(out);
			outputVector(out, output);
			CHECK(output.str() == "-0.825 0.937 1.143 2.000 ");
		}
	}
};



