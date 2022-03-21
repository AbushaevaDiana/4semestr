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
	std::map<std::string, std::string> dictionaryCorrect = { {"cat", "кошка"},
							 {"sun", "солнце"},
							 {"dog", "собака"} };
	std::string word = "cat";
	dictionary = MakeDictionary(dictionary, fileIn);
	REQUIRE(dictionary == dictionaryCorrect);
};

SCENARIO("Make an empty map")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../empty.txt");
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std::string> dictionaryCorrect = { };
	dictionary = MakeDictionary(dictionary, fileIn);
	REQUIRE(dictionary == dictionaryCorrect);
};

SCENARIO("Find correct word")
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
	REQUIRE(word == "кошка");
};

SCENARIO("Find russian word")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::string word = "солнце";
	dictionary = MakeDictionary(dictionary, fileIn);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "sun");
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
	REQUIRE(word == "кошка");
};

SCENARIO("Find word not from dictionary")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::string word = "frog";
	dictionary = MakeDictionary(dictionary, fileIn);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "");
};

SCENARIO("Find empty string")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::ifstream fileIn;
	fileIn.open("../dictionary.txt");
	std::map<std::string, std::string> dictionary;
	std::string word = "";
	dictionary = MakeDictionary(dictionary, fileIn);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "");
};