#pragma once
#include <string>
#include <iostream>
#include <map>


std::string LookForWord(std::string& word, std::map<std::string, std::string> &dictionary);

std::map<std::string, std::string> MakeDictionary(std::map<std::string, std::string> &dictionary, std::ifstream& fileIn);

std::map<std::string, std::string> AddNewWordToDictionary(std::string& word, std::map<std::string, std::string>& dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone);

void SaveTheChanges(std::string& file, std::map<std::string, std::string> &dictionary, std::istream& fileIn, std::ostream& fileOut);