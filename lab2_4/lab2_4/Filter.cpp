#include "Filter.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

std::set<std::string> MakeDictionary(std::set<std::string> &dictionary, std::ifstream& fileIn)
{
	setlocale(LC_ALL, "rus");
	while (fileIn.peek() != EOF)
	{
		std::string str;
		getline(fileIn, str);
		transform(str.begin(), str.end(), str.begin(), tolower);
		dictionary.insert(str);
	}

	return dictionary;
}

std::vector<std::string> FilterStrings(std::set<std::string>& dictionary, std::vector<std::string>& words, std::string& strIn)
{
	std::string strOut;
	words = MakeSetOfWords(words, strIn);

	for (size_t i = 0; i < words.size(); i++)
	{
		std::string word = words[i];
		transform(word.begin(), word.end(), word.begin(), tolower);
		if (dictionary.find(word) != dictionary.end())
		{
			words.erase(words.begin() + i);
		}
	}

	return words;
}

std::vector<std::string> MakeSetOfWords(std::vector<std::string>& words, std::string &strIn)
{
	if (strIn == "")
	{
		return words;
	}
	std::string word;
	for (size_t i = 0; i < strIn.length(); i++)
	{
		if (strIn[i] == ' ' || strIn[i] == ',' || strIn[i] == '.' || strIn[i] == '!' || strIn[i] == '?' || strIn[i] == ')' || strIn[i] == '(')
		{
			words.push_back(word);
			word = "";
			word += strIn[i];
			words.push_back(word);
			word = "";

		}
		else
		{
			word += strIn[i];
		}
	}
	words.push_back(word);
	return words;
}

