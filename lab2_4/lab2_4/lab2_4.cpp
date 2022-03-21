#include <iostream>
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
	
	bool wasError = false;
    std::set <std::string> dictionary;
	dictionary = MakeDictionary(dictionary, file, wasError);
	
	if (wasError)
	{
		return 1;
	}

	while (std::cin.peek() != EOF)
	{
		std::vector<std::string> words;
		std::string str;

		getline(std::cin, str);
		words = FilterStrings(dictionary, words, str);

		std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, ""));
	}
	
	
	std::cout << std::flush;
    return 0;
}