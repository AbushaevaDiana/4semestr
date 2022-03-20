#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string LookForWord(std::string& word, std::map<std::string, std::string> &dictionary)
{
	transform(word.begin(), word.end(), word.begin(), tolower);
	return dictionary[word];
}

std::map<std::string, std::string> AddNewWordToDictionary(std::string& word, std::map<std::string, std::string> &dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone)
{
	setlocale(LC_ALL, "rus");
	std::string translation;
	fileOut << "����������� ����� \"" << word << "\".\n" << "������� ������� ��� ������ ������ ��� ������: ";
	//fileIn.ignore();
	getline(fileIn, translation);
	//getline(fileIn, translation);
	if (translation != "")
	{
		changesDone = true;
		transform(word.begin(), word.end(), word.begin(), tolower);
		dictionary.insert(make_pair(word, translation));
		fileOut << "����� \"" << word << "\" ���������� � ������� ��� \"" << translation << "\"\n";
	}
	else
	{
		fileOut << "C���� \"" << word << "\" ����������������.\n";
	}

	return std::map<std::string, std::string>();
}

void SaveTheChanges(std::string& file, std::map<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut)
{
	std::string str;
	fileOut << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������: ";
	//fileIn.ignore();
	getline(fileIn, str);
	//fileIn >> str;
	if (str == "Y" || str == "y")
	{
		std::ofstream newDictionary;
		newDictionary.open(file);
		for (auto elem : dictionary) 
		{ 
			newDictionary << elem.first << ">" << elem.second << std::endl; 
		}
		fileOut << "��������� ����������. ";
	}

}

std::map<std::string, std::string> MakeDictionary(std::map<std::string, std::string>& dictionary, std::ifstream& fileIn)
{
	std::string translation;
	std::string word;

	while (fileIn.peek() != EOF)
	{
		std::string str;
		std::getline(fileIn, str);
		size_t positionOfCenter = str.find(">");
		if (positionOfCenter != std::string::npos)
		{
			word = str.substr(0, positionOfCenter);
			translation = str.substr(positionOfCenter+1);
			dictionary.insert(make_pair(word, translation));
		}
	}
	return dictionary;
}