#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::string LookForWord(std::string word, const std::multimap<std::string, std::string> &dictionary)
{
	//������� ����� ����������� �������� ������� �������� word (���������)
	//������� �� ����������� ������ (���������)
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
	fileOut << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������: ";
	getline(fileIn, str);
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

void Dialog(std::multimap<std::string, std::string>& dictionary, bool& changesDone, std::istream& input, std::ostream& output)
{
	//changesDone �������� ��������, ����� ����������
	bool endOfProgamm = false;
	std::string word;
	std::string translation;
	output << "    ��� ������������ ��������� �������. �������� ����������� �� ������. ��� ��������� �������� ������� ��� ����� - \"...\"\n";

	output << "������� �����: ";
	getline(input, word);
	//��������� ������������ ���� �� �������� ����� �������
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
			output << "�������: " << translation << "\n";
		}

		output << "������� �����: ";
		getline(input, word);
		if (word == "...")
		{
			endOfProgamm = true;
		}
	}
}

std::multimap<std::string, std::string> MakeDictionary(const std::string& file, std::ostream& err, bool& wasError)
{
	//wasError false ������������� �� true
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
		//check 2 open, name of new dictionary like in input (���������)
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
	//changesDone �������� ��������, ����� ����������
	setlocale(LC_ALL, "rus");
	std::string translation;
	fileOut << "����������� ����� \"" << word << "\".\n ������� ������� ��� ������ ������ ��� ������: ";
	getline(fileIn, translation);
	if (translation == "")
	{
		fileOut << "C���� \"" << word << "\" ����������������.\n";
	}
	else
	//������� ����� ����������� �������� ������� �������� word (���������)
	{
		changesDone = true;
		fileOut << "����� \"" << word << "\" ���������� � ������� ��� \"" << translation << "\"\n";
		transform(word.begin(), word.end(), word.begin(), tolower);
		dictionary.insert(std::make_pair(word, translation));
	}
}
