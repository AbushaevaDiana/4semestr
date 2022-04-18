#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//убрать непонятные числа(как вариант, через enum)
const int MATRIX_SIZE = 100;
typedef int Matrix[MATRIX_SIZE][MATRIX_SIZE];
struct Pole
{
	Matrix items;
};
struct Point
{
	int X;
	int Y;
};
bool ThereIsNotFillNear(Pole& pole, Point i1);
Pole InitializePole(std::ifstream& fileIn, Pole& pole, vector<Point>& start);
bool WaveAlgoritm(Pole& pole, vector<Point>& start);
void PrintResult(std::ofstream& fileOut, Pole& pole);
bool OpenFiles(std::ofstream& fileOut, std::ifstream& fileIn, char*& strIn, char*& strOut);

//непонятно, что функцию надо вызывать мнногократно
bool WaveAlgoritm(Pole& pole, vector<Point>& start)
{
	bool end;
	end = true;
	for (size_t i = 0; i < start.size(); i++)
	{
		Point i1 = start[i];
		//устранить дублирование кода
		if (i1.X + 1 < MATRIX_SIZE && pole.items[i1.Y][i1.X + 1] == 0)
		{
			pole.items[i1.Y][i1.X + 1] = 3;
		}
		if (i1.Y + 1 < MATRIX_SIZE && pole.items[i1.Y + 1][i1.X] == 0)
		{
			pole.items[i1.Y + 1][i1.X] = 3;
		}
		if (i1.X - 1 >= 0 && pole.items[i1.Y][i1.X - 1] == 0)
		{
			pole.items[i1.Y][i1.X - 1] = 3;
		}
		if (i1.Y - 1 >= 0 && pole.items[i1.Y - 1][i1.X] == 0)
		{
			pole.items[i1.Y - 1][i1.X] = 3;
		}
	}

	//устранить полный обход массива
	start.clear();
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			if (pole.items[j][i] == 3)
			{
				Point i2;
				i2.Y = j;
				i2.X = i;
				start.push_back(i2);
				if (!(ThereIsNotFillNear(pole, i2)))
				{
					end = false;
				}
				
			}
		}
	}

	return end;
};
//не передавать размер поля, есть константа +
bool ThereIsNotFillNear(Pole& pole, Point i1)
{
	if (i1.X + 1 < MATRIX_SIZE && pole.items[i1.Y][i1.X + 1] == 0)
	{
		return false;
	}
	if (i1.Y + 1 < MATRIX_SIZE && pole.items[i1.Y + 1][i1.X] == 0)
	{
		return false;
	}
	if (i1.X - 1 >= 0 && pole.items[i1.Y][i1.X - 1] == 0)
	{
		return false;
	}
	if (i1.Y - 1 >= 0 && pole.items[i1.Y - 1][i1.X] == 0)
	{
		return false;
	}
	return true;
}
//istream лучше передовать
Pole InitializePole(std::ifstream& fileIn, Pole& pole, vector<Point>& start)
{
	string str;
	
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			pole.items[j][i] = 0;
		}
	}

	int j = 0;
	while (!fileIn.eof() && j < MATRIX_SIZE)
	{
		getline(fileIn, str);
		for (auto i = 0; i < str.length()  && i < MATRIX_SIZE; i++)
		{
			if (str[i] == '0')
			{
				pole.items[i][j] = 1;
				Point point;
				point.Y = i;
				point.X = j;
				start.push_back(point);
			}
			if (str[i] == '#')
			{
				pole.items[i][j] = 5;
			}
			if (str[i] == '*')
			{
				pole.items[i][j] = 3;
			}
		}
		j++;
	}

	return pole;
}

void PrintResult(std::ofstream& fileOut, Pole& pole)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			if (pole.items[j][i] == 0)
			{
				fileOut << ' ';
			}
			if (pole.items[j][i] == 1)
			{
				fileOut << '0';
			}
			if (pole.items[j][i] == 5)
			{
				fileOut << '#';
			}
			if (pole.items[j][i] == 3)
			{
				fileOut << '*';
			}
		}
		fileOut << "\n";
	}
}

bool OpenFiles(std::ofstream& fileOut, std::ifstream& fileIn, char*& strIn, char*& strOut)
{
	
	fileIn.open(strIn);
	fileOut.open(strOut);

	if (!(fileIn.is_open() && fileOut.is_open()))
	{
		std::cerr << "File error!" << endl;
		return false;
	}
	
	return true;
}

//add fuction to load pole
int main(char argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "Invalid input format";
		return 1;
	}

	std::ofstream fileOut;
	//подобрать другое название для pole
	std::ifstream fileIn;
	if (!OpenFiles(fileOut, fileIn, argv[1], argv[2]))
	{
		return 1;
	}

	Pole pole;
	vector<Point> start;
	pole = InitializePole(fileIn, pole, start);

	bool end = false;
	while (!end)
	{
		end = WaveAlgoritm(pole, start);
	}

	PrintResult(fileOut, pole);

	fileIn.close();
	fileOut.close();

	return 0;
}