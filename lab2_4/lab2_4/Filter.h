#include <set>
#include <string>
#include <vector>

std::set <std::string> MakeDictionary(std::set <std::string> &dictionary, const std::string& file, bool& wasError);

std::vector<std::string> FilterStrings(std::set <std::string> &dictionary, std::vector<std::string>& words, std::string &strIn);

std::vector <std::string> MakeSetOfWords(std::vector <std::string>& words, std::string &strIn);