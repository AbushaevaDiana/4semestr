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
		std::cerr << "Invalid input format\n";
		return 1;
	}

	std::string file = argv[1];
	bool wasError = false;
	std::set <std::string> dictionary = MakeDictionary(file, wasError);
	
	if (wasError)
	{
		return 1;
	}

	DoFiltration(dictionary, std::cin, std::cout);
	
	
	std::cout << std::flush;
    return 0;
}