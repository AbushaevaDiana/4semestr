﻿#include <iostream>
#include <set>
#include <fstream>
#include <windows.h>
#include "Filter.h"


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		std::cout << "Invalid input format";
		return 1;
	}

	std::string file = argv[1];
	std::ifstream fileIn;
	fileIn.open(file);
	if (!(fileIn.is_open()))
	{
		std::cout << "File error";
		return 1;
	}
	
    std::set <std::string> dictionary;
	dictionary = MakeDictionary(dictionary, fileIn);
	
	while (std::cin.peek() != EOF)
	{
		std::vector<std::string> words;
		std::string str;

		//std::cin.ignore();
		getline(std::cin, str);
		words = FilterStrings(dictionary, words, str);

		std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, ""));
	}
	
	fileIn.close();
	std::cout << std::flush;
    return 0;
}