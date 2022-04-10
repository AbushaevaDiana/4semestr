#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Dictionary.h"
//функция мейн слишком большая (исправила)
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		std::cerr << "Invalid input format";
		return 1;
	}

	std::string file = argv[1];
	bool changesDone = false;
	bool wasError = true;
	std::multimap<std::string, std::string> dictionary = MakeDictionary(file, std::cerr, wasError);

	if (wasError)
	{
		return 1;
	}
	Dialog(dictionary, changesDone, std::cin, std::cout);
	
	if (changesDone)
	{
		SaveTheChanges(file, dictionary, std::cin, std::cout);
	}
	
	std::cout << "До свидания\n";
	return 0;
}