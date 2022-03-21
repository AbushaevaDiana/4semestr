#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Dictionary.h"
//функция мейн слишком большая
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
		std::fstream fileIn("file.txt", std::ios::in | std::ios::out | std::ios::app);
		file = "newDictionary.txt";
		fileIn.open(file);
		std::cout << "Такого файла не существует, создан пустой словарь\n";
		//check 2 open, name of new dictionary like in input
	}

	bool changesDone = false;
	std::map<std::string, std::string> dictionary;
	dictionary = MakeDictionary(dictionary, fileIn);

	Dialog(dictionary, changesDone, std::cin, std::cout);

	fileIn.close();
	if (changesDone)
	{
		SaveTheChanges(file, dictionary, std::cin, std::cout);
	}
	
	std::cout << "До свидания\n";
	std::cout << std::flush;
	//flush зачем?
	return 0;
}