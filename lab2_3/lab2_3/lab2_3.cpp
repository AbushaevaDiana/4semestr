#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Dictionary.h"

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
		std::cout << "������ ����� �� ����������, ������ ������ �������\n";
	}

	bool endOfProgamm = false, changesDone = false;
	std::map<std::string, std::string> dictionary;
	std::string word;
	std::string translation;
	dictionary = MakeDictionary(dictionary, fileIn);
	std::cout << "    ��� ������������ ��������� �������. �������� ����������� �� ������. ��� ��������� �������� ������� ��� ����� - \"...\"\n";

	std::cout << "������� �����: ";
	getline(std::cin, word);
	if (word == "...")
	{
		endOfProgamm = true;
	}

	while (!endOfProgamm)
	{
		translation = LookForWord(word, dictionary);
		if (translation == "")
		{
			dictionary = AddNewWordToDictionary(word, dictionary, std::cin, std::cout, changesDone);

		}
		else 
		{
			std::cout << "�������: " << translation << "\n";
		}
		
		std::cout << "������� �����: ";
		getline(std::cin, word);
		if (word == "...")
		{
			endOfProgamm = true;
		}
	}

	fileIn.close();
	if (changesDone)
	{
		SaveTheChanges(file, dictionary, std::cin, std::cout);
	}
	

	std::cout << "�� ��������\n";
	std::cout << std::flush;

	return 0;
}