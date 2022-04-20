#include <iostream>
#include "../lab2_2/Encode.h"
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

SCENARIO("Empty string input")
{
	std::string input = "";
	REQUIRE(HtmlEncode(input) == input);
};

SCENARIO("String without replace")
{
	std::string input = "Cat Cat Cat Cat";
	REQUIRE(HtmlEncode(input) == "Cat Cat Cat Cat");
};

// TODO: покрыть тестами все позитивные кейсы

SCENARIO("String with replace")
{
	std::string input = "Cat <says> \"Meow\". M&M\'s";
	REQUIRE(HtmlEncode(input) == "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
};

SCENARIO(" (двойная кавычка) заменяется на &quot;")
{
	std::string input = "\"Hello\"";
	REQUIRE(HtmlEncode(input) == "&quot;Hello&quot;");
};

SCENARIO(" (апостроф) заменяется на &apos;")
{
	std::string input = "\'A\'";
	REQUIRE(HtmlEncode(input) == "&apos;A&apos;");
};

SCENARIO("(знак меньше) заменяется на &lt;")
{
	std::string input = "small < big";
	REQUIRE(HtmlEncode(input) == "small &lt; big");
};

SCENARIO("(знак больше) заменяется на &gt;")
{
	std::string input = "sun > ball";
	REQUIRE(HtmlEncode(input) == "sun &gt; ball");
};

SCENARIO("(амперсанд) заменяется на &amp;")
{
	std::string input = "blue&green";
	REQUIRE(HtmlEncode(input) == "blue&amp;green");
};