#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::wstring LookForWord(std::wstring word, std::wifstream& fileIn)
{
	std::wstring translation;

	while (fileIn.peek() != EOF)
	{
		//transform(word.begin(), word.end(), word.begin(), tolower);
			//- превращает все большие символы строки в маленькие.

		std::wstring str;
		std::getline(fileIn, str);
		if (str.find(word) != std::string::npos)
		{
			translation = str.substr(str.find(word) + word.length() + 1);
			return str;
		}

	}
	
	return translation;
}
