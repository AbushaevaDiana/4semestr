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
	std::vector<std::string> correct = { "Word", " " };
	std::string str = "Word is perfect! Yes yes";
	words = MakeSetOfWords(words, str);
	//std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, ""));
	REQUIRE(words[1] == correct[1]);
};

SCENARIO("Make set dictionary")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::set<std::string> dictionary;
	std::set<std::string> correct = { "блин", "дурак" };
	dictionary = MakeDictionary(dictionary, fileIn);
	REQUIRE(dictionary == correct);
};

SCENARIO("Filter srting")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, fileIn);
	std::vector<std::string> words;
	std::vector<std::string> correct = { "Ну", " ", ",", "", " ", "нет"};
	std::string str = "Ну блин, нет";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};

SCENARIO("Filter srting witout bad words")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, fileIn);
	std::vector<std::string> words;
	std::vector<std::string> correct = { "Привет", ",", "", " ", "мир", "!", "", " ", "Я", " ", "рад", " ", "вам", "!", "" };
	std::string str = "Привет, мир! Я рад вам!";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};