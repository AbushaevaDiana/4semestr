#pragma once
#include <string>
#include <iostream>
#include <map>


std::string LookForWord(std::string word, const std::multimap<std::string, std::string> &dictionary);

std::multimap<std::string, std::string> MakeDictionary(const std::string& file, std::ostream& err, bool& wasError);

void AddNewWordToDictionary(std::string word, std::multimap<std::string, std::string> &dictionary, std::istream& fileIn, std::ostream& fileOut, bool& changesDone);

void SaveTheChanges(const std::string& file, std::multimap<std::string, std::string> &dictionary, std::istream& fileIn, std::ostream& fileOut);

void Dialog(std::multimap<std::string, std::string>& dictionary, bool& changesDone, std::istream& input, std::ostream& output);