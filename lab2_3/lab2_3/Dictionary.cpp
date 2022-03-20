#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string LookForWord(std::string& word, std::map<std::string, std::string> &dictionary)
{
	transform(word.begin(), word.end(), word.begin(), tolower);
	return dictionary[word];
}

std::map<std::string, std::string> AddNewWordToDictionary(std::string word, std::map<std::string, std::string> &dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone)
{
	std::string translation;
	fileOut << "Неизвестное слово \"" << word << "\".\n" << "Введите перевод или пустую строку для отказа: ";
	//fileIn.ignore();
	getline(fileIn, translation);
	//getline(fileIn, translation);
	if (translation != "")
	{
		changesDone = true;
		transform(word.begin(), word.end(), word.begin(), tolower);
		dictionary.insert({ { word, "ckjdj" } });
		//
		for (auto elem : dictionary)
		{
			fileOut << elem.first << ">" << elem.second << std::endl;
		}
		//
		fileOut << "Слово \"" << word << "\" сохраненно в словаре как \"" << translation << "\"\n";
	}
	else
	{
		fileOut << "Cлово \"" << word << "\" проигнорированно.\n";
	}

	return dictionary;
}

void SaveTheChanges(std::string& file, std::map<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut)
{
	std::string str;
	fileOut << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом: ";
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
		fileOut << "Изменения сохраненны. ";
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