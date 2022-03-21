#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab2_4/Filter.h"

SCENARIO("Make set of words")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::vector<std::string> words;
	std::vector<std::string> correct = { "Word", " " };
	std::string str = "Word is perfect! Yes yes";
	words = MakeSetOfWords(words, str);
	REQUIRE(words[1] == correct[1]);
};

SCENARIO("Make set of words from empty string")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::vector<std::string> words;
	std::vector<std::string> correct = {};
	std::string str = "";
	words = MakeSetOfWords(words, str);
	REQUIRE(words == correct);
};

SCENARIO("Make set dictionary")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::string file = "../dictionary.txt";
	bool wasError = false;
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	std::set<std::string> correct = { "блин", "дурак" };
	REQUIRE(dictionary == correct);
};

SCENARIO("Make set dictionary from empty file")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::set<std::string> dictionary;
	std::set<std::string> correct = { };
	std::string file = "../empty.txt";
	bool wasError = false;
	dictionary = MakeDictionary(dictionary, file, wasError);
	REQUIRE(dictionary == correct);
};

SCENARIO("Filter srting")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::string file = "../dictionary.txt";
	bool wasError = false;
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	std::vector<std::string> words;
	std::vector<std::string> correct = { "Ну", " ", ",", "", " ", "нет"};
	std::string str = "Ну блин, нет";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};

SCENARIO("Filter srting with general and ordinar letters")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::string file = "../dictionary.txt";
	bool wasError = false;
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	std::vector<std::string> words;
	std::vector<std::string> correct = { ",", "", " ", "ты", " ", "Прошка", ",", "", " ", "!", "" };
	std::string str = "Дурак, ты Прошка, дурак!";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};

SCENARIO("Filter srting witout bad words")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::string file = "../dictionary.txt";
	bool wasError = false;
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	std::vector<std::string> words;
	std::vector<std::string> correct = { "Привет", ",", "", " ", "мир", "!", "", " ", "Я", " ", "рад", " ", "вам", "!", "" };
	std::string str = "Привет, мир! Я рад вам!";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};

SCENARIO("Filter empty srting")
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	std::string file = "../dictionary.txt";
	bool wasError = false;
	std::set<std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	std::vector<std::string> words;
	std::vector<std::string> correct = { };
	std::string str = "";
	words = FilterStrings(dictionary, words, str);
	REQUIRE(words == correct);
};