#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab2_4/Filter.h"



SCENARIO("Make set of words")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	//std::ifstream fileIn;
	//fileIn.open("../dictionary.txt");
	std::vector<std::string> words;
	std::vector<std::string> correct = {"", "4"};
	std::string str = "Word is perfect! Yes yes";
	words = MakeSetOfWords(words, str);
	REQUIRE(words[1] == correct[1]);
};