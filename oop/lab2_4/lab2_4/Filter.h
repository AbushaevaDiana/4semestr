#include <set>
#include <string>
#include <vector>
#include <iostream>

std::set <std::string> MakeDictionary(const std::string& file, bool& wasError);

std::vector<std::string> FilterStrings(const std::set <std::string> &dictionary, std::vector<std::string>& words, const std::string &strIn);

std::vector <std::string> MakeSetOfWords(std::vector <std::string>& words, const std::string &strIn);

void DoFiltration(const std::set <std::string>& dictionary,  std::istream& input, std::ostream& output);