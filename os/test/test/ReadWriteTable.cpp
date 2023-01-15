#include "ReadWriteTable.h"
using namespace std;

void ReadTable(ifstream& input, vector<vector<string>>& inputAutomaton)
{

    string str;
    while (getline(input, str))
    {
        vector<string> arr;
        std::string item;
        std::istringstream strStream(str);
        while (getline(strStream, item, ';'))
        {
            arr.push_back(item);
        }
        inputAutomaton.push_back(arr);
    }

}

void WriteTable(ofstream& output, vector<vector<string>>& outputAutomaton)
{
    for (auto i = 0; i < outputAutomaton.size(); i++)
    {
        for (auto j = 0; j < outputAutomaton[i].size(); j++)
        {
            output << outputAutomaton[i][j];
            if (j + 1 != outputAutomaton[i].size())
            {
                output << ";";
            }
        }
        output << "\n";

    }
}
