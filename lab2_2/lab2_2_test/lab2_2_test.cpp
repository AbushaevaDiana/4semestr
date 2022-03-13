#include <iostream>
#include "../lab2_2/Encode.h"
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

SCENARIO("Empty string input")
{
	std::string input = "";
	REQUIRE(HtmlEncode(input) == input);
};

SCENARIO("String with replace")
{
	std::string input = "Cat <says> \"Meow\". M&M\'s";
	REQUIRE(HtmlEncode(input) == "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
};

SCENARIO("String without replace")
{
	std::string input = "Cat Cat Cat Cat";
	REQUIRE(HtmlEncode(input) == "Cat Cat Cat Cat");
};