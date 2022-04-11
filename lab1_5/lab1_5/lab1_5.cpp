#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MATRIX_SIZE = 100;

typedef char Matrix[MATRIX_SIZE][MATRIX_SIZE];

struct cletka
{
	int X;
	int Y;
};

bool volna(Matrix& pole, int starts, int poleN, vector<cletka>& start)
{
	bool end;
	end = true;
	for (int i = 0; i < start.size(); i++)
	{
		cletka i1 = start[i];
		if (i1.X + 1 < poleN)
		{
			pole[i1.Y][i1.X + 1] += 1;
		}
		if (i1.Y + 1 < poleN)
		{
			pole[i1.Y + 1][i1.X] += 1;
		}
		if (i1.X - 1 >= 0)
		{
			pole[i1.Y][i1.X - 1] += 1;
		}
		if (i1.Y - 1 >= 0)
		{
			pole[i1.Y - 1][i1.X] += 1;
		}
	}

	start.clear();
	for (int i = 0; i < poleN; i++)
	{
		for (int j = 0; j < poleN; j++)
		{
			if (pole[i][j] != 0)
			{
				cletka i2;
				i2.Y = i;
				i2.X = j;
				start.push_back(i2);
			}
			if (pole[i][j] == 0)
			{
				end = false;
			}

		}
	}
	return end;
};

void inputPole(std::ifstream& fileIn, Matrix& pole, vector<cletka>& start)
{
	string str;
	int j = 0;
	//ввод из файла клеток и начальных клеток
	while (!fileIn.eof())
	{
		getline(fileIn, str);
		for (size_t i = 0; i < str.length(); i++)
		{
			pole[j][i] = str[i];
			if (str[i] = '0')
			{
				cletka point;
				point.Y = i;
				point.X = j;
				start.push_back(point);
			}
		}
		j++;
	}
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid input format";
		return 0;
	}

	//Инициализация входной файла
	string strIn = argv[1];
	string strOut = argv[2];

	//Открытие файлов
	ifstream fileIn;
	fileIn.open(strIn);
	ofstream fileOut;
	fileOut.open(strOut);

	if (!(fileIn.is_open() && fileOut.is_open()))
	{
		std::cout << "File error!" << endl;
		return 1;
	}

	int poleN, starts;
	

	Matrix pole;
	vector<cletka> start;
	inputPole(fileIn, pole, start);

	bool end;
	int result = 0;
	if (starts < poleN * poleN)
	{
		result += 1;
		end = volna(pole, starts, poleN, start);
	}

	while (end == false)
	{
		result += 1;
		end = volna(pole, starts, poleN, start);
	}

	cout << "\n" << result;
	fileOut << result;


	//Закрытие файлов
	fileIn.close();
	fileOut.close();

	return 0;
}