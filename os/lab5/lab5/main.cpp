#include <iostream>
#include <set>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

map<string, string> keywords = {
    make_pair("int", "Type"),
    make_pair("void", "Type"),
    make_pair("string", "Type"),
    make_pair("for", "Keyword"),
    make_pair("while", "Keyword"),
    make_pair("false", "Keyword"),
    make_pair("true", "Keyword"),
    make_pair("struct", "Keyword"),
    make_pair("map", "Keyword"),
    make_pair("vector", "Keyword"),
    make_pair("continue", "Keyword"),
    make_pair("break", "Keyword"),
    make_pair("return", "Keyword"),
    make_pair("if", "Keyword"),
    make_pair("else", "Keyword"),
    make_pair("char", "Type"),
    make_pair("bool", "Type"),
    make_pair("auto", "Type"),
    make_pair("const", "Keyword")
};

map<string, string> separators = {
    make_pair("{", "Separator"),
    make_pair("}", "Separator"),
    make_pair("(", "Separator"),
    make_pair(")", "Separator"),
    make_pair("[", "Separator"),
    make_pair("]", "Separator"),
    make_pair(";", "Separator"),
    make_pair(",", "Separator"),
    make_pair("+", "Operator"),
    make_pair("-", "Operator"),
    make_pair("=", "Operator"),
    make_pair(":", "Separator"),
};

map<string, string> types = {
    make_pair("\"", "String"),
    make_pair("\'", "String"),
};

string numbers = "1234567890.";

void DeleteSpaces(string& string)
{
    size_t index;
    size_t strBegin = string.find_first_not_of(' ');
    size_t strEnd = string.find_last_not_of(' ');
    while (((index = string.find(' ')) != std::string::npos) && (index < strBegin))
    {
        string.erase(index, 1);
    }
    while ((index = string.find(' ', strEnd)) != std::string::npos)
    {
        string.erase(index, 1);
    }
}

bool IsItKeyword(string& strInput)
{
    return (keywords.find(strInput) != keywords.end());
}

bool MakeToken(string& word, int indexStr)
{
    if (word == "")
    {
        return false;
    }

    for (auto& item : separators)
    {
        size_t index = word.find(item.first);
        if (index != string::npos)
        {
            word.erase(index, item.first.size());
            string secondStr = word.substr(index, word.size() - index);
            word = word.substr(0, index);
            MakeToken(word, indexStr);
            cout << item.first << " --- " << item.second << " --- " << indexStr << "\n";
            MakeToken(secondStr, indexStr);
            return true;
        }
    }

    //numbers
    if (numbers.find(word[0]) != string::npos)
    {
        for (auto i = 1; i < word.size(); i++)
        {
            if ((numbers.find(word[i]) == string::npos) || word[0] == '.')
            {
                cout << word << " --- Error --- " << indexStr << "\n";
                return true;
            }
        }
        cout << word << " --- Number  --- " << indexStr << "\n";
        return true;
    }

    string output = keywords[word];
    if (output != "")
    {
        cout << word << " --- " << output << " --- " << indexStr << "\n";
        return true;
    }

    output = separators[word];
    if (output != "")
    {
        cout << word << " --- " << output << " --- " << indexStr << "\n"; 
        return true;
    }
    cout << word << " --- Error --- " << indexStr << "\n";
}

void ProcessStr(string& inputStr, int indexStr)
{
    int commentsIndex = 0;
    DeleteSpaces(inputStr);
    if ((commentsIndex = inputStr.find("//", commentsIndex)) != string::npos)
    {
        string comment = inputStr.substr(commentsIndex, inputStr.size() - commentsIndex);
        inputStr = inputStr.substr(0, commentsIndex);
        cout << comment << " --- Comment --- " << indexStr << "\n";
    }
    if (!inputStr.empty())
    {
        vector<string> words;
        string item;
        istringstream strStream(inputStr);
        while (getline(strStream, item, ' '))
        {
            words.push_back(item);
        }
        for (auto i = 0; i < words.size(); i++)
        {
            MakeToken(words[i], indexStr);
        }
    }
}

void Process(ifstream& input, ofstream& output)
{
    string inputStr;
    int indexStr = 0;
    while (getline(input, inputStr))
    {
        indexStr++;
        if (inputStr.empty())
        {
            continue;
        }
        ProcessStr(inputStr, indexStr);
    }
}

int main(int args, char* arsv[])
{
    ifstream inputFile(arsv[1]);
    ofstream outputFile(arsv[2]);
    Process(inputFile, outputFile);
}