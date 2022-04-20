#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string LookForWord(std::string word, const std::multimap<std::string, std::string> &dictionary)
{
	//функция имеет неочевидные побочные эффекты изменяет word (исправила)
	//словарь по константной ссылке (исправила)
	transform(word.begin(), word.end(), word.begin(), tolower); 
	std::string str;
	for (auto& pair : dictionary)
	{
		if (pair.first == word)
		{
			str += pair.second + " ";
		}
		if (pair.second == word)
		{
			str += pair.first + " ";
		}
	}

	return str;
}

void SaveTheChanges(const std::string& file, std::multimap<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut)
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

void Dialog(std::multimap<std::string, std::string>& dictionary, bool& changesDone, std::istream& input, std::ostream& output)
{
	//changesDone выходной параметр, нужно возвращать
	bool endOfProgamm = false;
	std::string word;
	std::string translation;
	output << "    Вас приветствует программа словарь. Следуйте инструкциям на экране. Для окончания прграммы введите три точки - \"...\"\n";

	output << "Введите слово: ";
	getline(input, word);
	//устранить дублирование кода по проверке конца диалога
	if (word == "...")
	{
		endOfProgamm = true;
	}

	while (!endOfProgamm)
	{
		translation = LookForWord(word, dictionary);
		if (translation == "")
		{
			AddNewWordToDictionary(word, dictionary, input, output, changesDone);

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

std::multimap<std::string, std::string> MakeDictionary(const std::string& file, std::ostream& err, bool& wasError)
{
	//wasError false устанавливать до true
	std::ifstream fileIn;
	fileIn.open(file);
	if (!(fileIn.is_open()))
	{
		std::fstream fileIn("file.txt", std::ios::in | std::ios::out | std::ios::app);
		fileIn.open(file);
		if (!(fileIn.is_open()))
		{
			wasError = true;
			err << "File error";
		}
		//check 2 open, name of new dictionary like in input (исправила)
	}
	std::multimap<std::string, std::string> dictionary;
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

	wasError = false;
	fileIn.close();
	return dictionary;
}

void AddNewWordToDictionary(std::string word, std::multimap<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone)
{
	//changesDone выходной параметр, нужно возвращать
	setlocale(LC_ALL, "rus");
	std::string translation;
	fileOut << "Неизвестное слово \"" << word << "\".\n Введите перевод или пустую строку для отказа: ";
	getline(fileIn, translation);
	if (translation == "")
	{
		fileOut << "Cлово \"" << word << "\" проигнорированно.\n";
	}
	else
	//функция имеет неочевидные побочные эффекты изменяет word (исправила)
	{
		changesDone = true;
		fileOut << "Слово \"" << word << "\" сохраненно в словаре как \"" << translation << "\"\n";
		transform(word.begin(), word.end(), word.begin(), tolower);
		dictionary.insert(std::make_pair(word, translation));
	}
}
