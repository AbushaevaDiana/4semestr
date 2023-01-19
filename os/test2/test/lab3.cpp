#include "ReadWriteTable.h"
#include <map>
#include <algorithm>

//1 часть задания

using namespace std;

struct Eclose {
    string state;
    int column;
    bool fin;
    vector<string> eStates;
};

struct State {
    string name;
    bool fin;
    vector<string> arrOfStates;
    vector<vector<string>> transitions;
    vector<string> transitionsName;
};

bool isInVector(vector<vector<string>>& allStatesVector, vector<string>& newVector)
{
    if (allStatesVector.empty())
    {
        return false;
    }
    for (auto i = 0; i < allStatesVector.size(); i++)
    {
        if (allStatesVector[i].size() == newVector.size() && is_permutation(allStatesVector[i].begin(), allStatesVector[i].end(), newVector.begin()))
        {
            return true;
        }
    }
    return false;
}

void makeTransitions(map<string, Eclose>& ecloses, vector<vector<string>>& inputAutomaton,
    vector<vector<string>>& outputAutomaton, int eStr, int line, int column, State& outputState)
{
    if (outputState.transitions.empty())
    {
        for (auto i = 2; i < inputAutomaton.size() - 1; i++)
        {
            vector<string> strVector;
            if (inputAutomaton[i][column] == "-")
            {
                outputState.transitions.push_back(strVector);
                outputState.transitionsName.push_back("");
                continue;
            }
            
            string item;
            istringstream strStream(inputAutomaton[i][column]);
            outputState.transitionsName.push_back("");
           
            while (getline(strStream, item, ','))
            {
                if ((find(strVector.begin(), strVector.end(), item) == strVector.end())) 
                {
                    strVector.push_back(item);
                    outputState.transitionsName[i - 2] = outputState.transitionsName[i - 2] + item;
                }
            }
            outputState.transitions.push_back(strVector);
        }
    }
    else
    {
        for (auto i = 2; i < inputAutomaton.size() - 1; i++)
        {
            if (inputAutomaton[i][column] == "-")
            {
                continue;
            }
            string item;
            istringstream strStream(inputAutomaton[i][column]);
            while (getline(strStream, item, ','))
            {
                if ((find(outputState.transitions[i - 2].begin(), outputState.transitions[i - 2].end(), item) == outputState.transitions[i - 2].end())) 
                {
                    outputState.transitions[i - 2].push_back(item);
                    outputState.transitionsName[i - 2] = outputState.transitionsName[i - 2] + item;
                }
            }
        }
    }

}

int makeState(map<string, Eclose>& ecloses, vector<vector<string>>& inputAutomaton, 
    vector<vector<string>>& outputAutomaton, int eStr, int line, int column, State& outputState)
{
    string newState = inputAutomaton[line][column];
    if (std::count(outputState.arrOfStates.begin(), outputState.arrOfStates.end(), newState))
    {
        //уже есть такое состояние
        return 0;
    }
    outputState.arrOfStates.push_back(newState);
    outputState.name = outputState.name + newState;
    if (ecloses[newState].fin)
    {
        outputState.fin = true;
    }

    makeTransitions(ecloses, inputAutomaton, outputAutomaton, eStr, line, column, outputState);

    if (ecloses[newState].eStates.empty())
    {
        return 0;
    }
    
    for (auto i = 0; i < ecloses[newState].eStates.size(); i++)
    {
        makeState(ecloses, inputAutomaton, outputAutomaton, eStr, 1, ecloses[ecloses[newState].eStates[i]].column, outputState);
    }

    return 0;

}

void makeAllStates(map<string, Eclose>& ecloses, vector<vector<string>>& inputAutomaton, vector<vector<string>>& outputAutomaton, int eStr, vector<State>& allStates)
{
    vector<vector<string>> allStatesVector;
    State outputState = {};
    outputState.fin = false;
    makeState(ecloses, inputAutomaton, outputAutomaton, eStr, 1, 1, outputState);
    allStates.push_back(outputState);
    allStatesVector.push_back(outputState.arrOfStates);

    for (auto i = 0; i < allStates.size(); i++)
    {   
        for (auto j = 0; j < allStates[i].transitions.size(); j++)
        {
            if (allStates[i].transitions[j].empty())
            {
                continue;
            }
            
          //сравнение массивов
            if (isInVector(allStatesVector, allStates[i].transitions[j]) == false && i<3)
            {
                State newState;
                newState.fin = false;
           
                for (auto z = 0; z < allStates[i].transitions[j].size(); z++)
                {
                    cout << "cf\n";
                    int column = ecloses[allStates[i].transitions[j][z]].column;
                    makeState(ecloses, inputAutomaton, outputAutomaton, eStr, 1, column, newState);
                }
                allStatesVector.push_back(newState.arrOfStates);

                allStates.push_back(newState);
            }
        }
    }

    for (auto i = 0; i < allStatesVector.size(); i++)
    {
        for (auto j = 0; j < allStatesVector[i].size(); j++)
        {
            cout << allStatesVector[i][j] << " ";
        }
        cout << "-\n";
    }

}

void processAutomaton(map<string, Eclose>& ecloses, vector<vector<string>>& inputAutomaton, vector<vector<string>>& outputAutomaton, int eStr)
{
    vector<string> line;
    line.push_back("");
    outputAutomaton.push_back(line);
    outputAutomaton.push_back(line);
    for (auto i = 2; i < inputAutomaton.size() - 1; i++)
    {
        line.pop_back();
        line.push_back(inputAutomaton[i][0]);
        outputAutomaton.push_back(line);
    }

    bool end = false;

    vector<State> allStates;
    makeAllStates(ecloses, inputAutomaton, outputAutomaton, eStr, allStates);

    for (auto st = 0; st < allStates.size(); st++)
    {
        if (allStates[st].fin)
        {
            outputAutomaton[0].push_back("F");
        }
        else
        {
            outputAutomaton[0].push_back("");
        }
        outputAutomaton[1].push_back(allStates[st].name);
        for (auto i = 2; i < outputAutomaton.size(); i++)
        {
            if (allStates[st].transitionsName[i - 2] == "")
            {
                outputAutomaton[i].push_back("-");
            }
            else
            {
                outputAutomaton[i].push_back(allStates[st].transitionsName[i - 2]);
            }
        }

    }
    
};

bool MakeEcloses(map<string, Eclose>& ecloses, vector<vector<string>>& inputAutomaton, int eStr)
{
    if (inputAutomaton[inputAutomaton.size() - 1][0] == "e")
    {
        eStr = inputAutomaton.size() - 1;
    }
    else
    {
        return false;
    }
    for (auto i = 1; i < inputAutomaton[1].size(); i++)
    {
        bool fin = false;
        if (inputAutomaton[0][i] == "F")
        {
            fin = true;
        }
        Eclose eclose = {};
        eclose.state = inputAutomaton[1][i];
        eclose.column = i;
        eclose.fin = fin;

        if (inputAutomaton[eStr][i] != "" && inputAutomaton[eStr][i] != "-")
        {
            std::string item;
            std::istringstream strStream(inputAutomaton[eStr][i]);
            while (getline(strStream, item, ','))
            {
                eclose.eStates.push_back(item);
            }
        }

        ecloses.insert(make_pair(inputAutomaton[1][i], eclose));
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid input format";
        return 0;
    }
    std::string type = argv[1];
    std::string file = argv[2];
    std::ifstream fileIn;
    fileIn.open(file);
    file = argv[3];
    std::ofstream fileOut;
    fileOut.open(file);

    if (!(fileIn.is_open() && fileOut.is_open()))
    {
        cerr << "Error open files!\n";
        return 1;
    }
    if (type != "left" && type != "right")
    {
        cerr << "You should enter type of gramma: left or right\n";
        return 1;
    }
    int eStr = 0;
    vector<vector<string>> inputAutomaton;
    vector<vector<string>> outputAutomaton;
    map<string, Eclose> ecloses;
    if (type == "left")
    {
        ReadLeftTable(fileIn, inputAutomaton);
    }
    if (type == "right")
    {
        ReadRightTable(fileIn, inputAutomaton);
    }

    if (!MakeEcloses(ecloses, inputAutomaton, eStr))
    {
       cerr << "Error file format. There isn't empty sybols!\n";
       return 1;
    };
    processAutomaton(ecloses, inputAutomaton, outputAutomaton, eStr);
    WriteTable(fileOut, outputAutomaton);

    fileIn.close();
    fileOut.close();
    
    return 0;
}