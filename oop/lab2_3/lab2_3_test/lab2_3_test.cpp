#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab2_3/Dictionary.h"

SCENARIO("Make a correct multimap")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std:: string file = "../dictionary.txt";
	std::multimap<std::string, std::string> dictionaryCorrect = { {"cat", "кошка"},
							 {"sun", "солнце"},
							 {"dog", "собака"} };
	std::string word = "cat";
	//передавать в создание словаря поток, чтобы тесты не зависли от файла
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	REQUIRE(dictionary == dictionaryCorrect);
};

SCENARIO("Make an empty multimap")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std::string file = "../empty.txt";
	std::multimap<std::string, std::string> dictionaryCorrect = { };
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	REQUIRE(dictionary == dictionaryCorrect);
};

SCENARIO("Find correct word")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std:: string file = "../dictionary.txt";
	std::string word = "cat";
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "кошка ");
};

SCENARIO("Find russian word")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std:: string file = "../dictionary.txt";
	std::string word = "солнце";
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "sun ");
};

SCENARIO("Find one word with general letter")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std:: string file = "../dictionary.txt";
	std::string word = "cAt";
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "кошка ");
};

SCENARIO("Find word not from dictionary")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std::string file = "../dictionary.txt";
	std::string word = "frog";
	//упроситить тесты, не читать лишний раз файлы
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "");
};

SCENARIO("Find empty string")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	bool wasError = false;
	std:: string file = "../dictionary.txt";
	std::string word = "";
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);
	word = LookForWord(word, dictionary);
	REQUIRE(word == "");
};