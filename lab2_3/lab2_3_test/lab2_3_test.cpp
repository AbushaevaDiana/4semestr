#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab2_3/Dictionary.h"



SCENARIO("Make a correct map")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std::string> dictionaryCorrect = { {"cat", "кошка, кот"},
							 {"sun", "солнце"},
							 {"dog", "собака"} };
	std::string word = "cat";
	dictionary = MakeDictionary(dictionary, fileIn);
	//for (auto elem : dictionary) { std::cout << "map[" << elem.first << "]=" << elem.second << std::endl; }
	REQUIRE(dictionary["cat"] == dictionaryCorrect["cat"]);
};

SCENARIO("Find one correct word")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::string word = "cat";
	dictionary = MakeDictionary(dictionary, fileIn);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "кошка, кот");
};

SCENARIO("Find one word with general letter")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::string word = "cAt";
	dictionary = MakeDictionary(dictionary, fileIn);
	word = LookForWord(word, dictionary);
	//for (auto elem : dictionary) { std::cout << "map[" << elem.first << "]=" << elem.second << std::endl; }
	REQUIRE(word == "кошка, кот");
};

