#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string LookForWord(std::string word, std::map<std::string,const std::string> &dictionary)
{
	//функция имеет неочевидные побочные эффекты +
	//словарь по константной ссылке +
	transform(word.begin(), word.end(), word.begin(), tolower); 

	for (auto& pair : dictionary)
	{
		if (pair.first == word)
		{
			return dictionary[word];
		}
		if (pair.second == word)
		{
			return pair.first;
		}
	}

	return "";
}

void SaveTheChanges(std::string& file, std::map<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut)
{
	setlocale(LC_ALL, "rus");
	std::string str;
	fileOut << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом: ";
	getline(fileIn, str);
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

void Dialog(std::map<std::string, std::string>& dictionary, bool& changesDone, std::istream& input, std::ostream& output)
{
	bool endOfProgamm = false;
	std::string word;
	std::string translation;
	output << "    Вас приветствует программа словарь. Следуйте инструкциям на экране. Для окончания прграммы введите три точки - \"...\"\n";

	output << "Введите слово: ";
	getline(input, word);
	if (word == "...")
	{
		endOfProgamm = true;
	}

	while (!endOfProgamm)
	{
		translation = LookForWord(word, dictionary);
		if (translation == "")
		{
			dictionary = AddNewWordToDictionary(word, dictionary, input, output, changesDone);

		}
		else
		{
			output << "Перевод: " << translation << "\n";
		}

		output << "Введите слово: ";
		getline(input, word);
		if (word == "...")
		{
			endOfProgamm = true;
		}
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
			dictionary.insert(std::make_pair(word, translation));
		}
	}
	return dictionary;
}

std::map<std::string, std::string> AddNewWordToDictionary(std::string &word, std::map<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone)
{
	setlocale(LC_ALL, "rus");
	std::string translation;
	fileOut << "Неизвестное слово \"" << word << "\".\n Введите перевод или пустую строку для отказа: ";
	getline(fileIn, translation);
	if (translation == "")
	{
		fileOut << "Cлово \"" << word << "\" проигнорированно.\n";
	}
	else
	{
		changesDone = true;
		fileOut << "Слово \"" << word << "\" сохраненно в словаре как \"" << translation << "\"\n";
		transform(word.begin(), word.end(), word.begin(), tolower);
		dictionary[word] = translation;
	}
	return dictionary;
}
