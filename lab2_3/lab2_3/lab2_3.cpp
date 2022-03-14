#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Dictionary.h"

int wmain(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		std::wcout << "Invalid input format";
		return 1;
	}

	std::string file = argv[1];
	std::wifstream fileIn;
	if (!(fileIn.is_open()))
	{
		std::wcout << "File error!" << std::endl;
		return 0;
	}

	
	std::wstring word;
	std::wcin >> word;
	LookForWord(word, fileIn);

	fileIn.close();
	std::wcout << std::flush;

	return 0;
}