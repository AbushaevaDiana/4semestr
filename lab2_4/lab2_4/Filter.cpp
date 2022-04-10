#include "Filter.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

std::set<std::string> MakeDictionary(const std::string& file, bool &wasError)
{
	std::set<std::string> dictionary;
	std::ifstream fileIn;
	fileIn.open(file);
	if (!(fileIn.is_open()))
	{
		wasError = true;
		return dictionary;
	}

	while (fileIn.peek() != EOF)
	{
		std::string str;
		getline(fileIn, str);
		transform(str.begin(), str.end(), str.begin(), tolower);
		// TODO: use std::move and emplace
		// TODO: пробеллы и табы для разделения слов
		dictionary.insert(str);
	}

	fileIn.close();

	wasError = false;
	return dictionary;
}

std::vector<std::string> FilterStrings(const std::set<std::string>& dictionary, std::vector<std::string>& words, const std::string& strIn)
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

std::vector<std::string> MakeSetOfWords(std::vector<std::string>& words, const std::string &strIn)
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

void DoFiltration(const std::set <std::string>& dictionary,  std::istream& input, std::ostream& output)
{
	while (input.peek() != EOF)
	{
		std::vector<std::string> words;
		std::string str;

		getline(input, str);
		words = FilterStrings(dictionary, words, str);

		std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(output, ""));
	}
}

