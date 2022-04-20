#include <iostream>
#include <fstream>
#include <string>
#include <deque>

enum class Symbols
{
	Empty,
	Start,
	Border, 
	Filled,
};

 //использовать enum +
const int MATRIX_SIZE = 100;
typedef Symbols Matrix[MATRIX_SIZE][MATRIX_SIZE];
struct Field
{
	Matrix items;
};
struct Point
{
	int X;
	int Y;
};

bool InitializeField(Field& field, std::deque<Point>& start, std::string& strIn);
Field Fill(Field& field, std::deque<Point>& start);
bool PrintField(std::string& const strOut, Field& field);
void FillPoint(Field& field, int Y, int X, std::deque<Point>& start);

void FillPoint(Field& field, int Y, int X, std::deque<Point>& start)
{
	if (Y < MATRIX_SIZE && X < MATRIX_SIZE && Y >= 0 && X >= 0 && field.items[Y][X] == Symbols::Empty)
	{
		field.items[Y][X] = Symbols::Filled;
		Point i2;
		i2.Y = Y;
		i2.X = X;
		start.push_back(i2);
	}
}
//TODO: наименование lowerCamelCase
//TODO: i2 убрать, использовать инициализирующий конструктор Point{x, y}
Field Fill(Field& field, std::deque<Point>& start)
{
	
	while(!start.empty())
	{
		Point i1 = start[0];
		//не конца убранно дублирование 
		//уменьшить потребление памяти, двусторонненя очередь
		FillPoint(field, i1.Y, i1.X + 1, start);
		FillPoint(field, i1.Y + 1, i1.X, start);
		FillPoint(field, i1.Y, i1.X - 1, start);
		FillPoint(field, i1.Y - 1, i1.X, start);

		start.pop_front();
	}
	
	return field;
};

//передовать строкой +
bool InitializeField(Field& field, std::deque<Point>& start, std::string& const strIn)
{
	std::ifstream fileIn;
	fileIn.open(strIn);

	if (!fileIn.is_open())
	{
		std::cerr << "File error!" << std::endl;
		return false;
	}

	std::string str;
	
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			field.items[j][i] = Symbols::Empty;
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
				field.items[i][j] = Symbols::Start;
				Point point;
				point.Y = i;
				point.X = j;
				start.push_back(point);
			}
			if (str[i] == '#')
			{
				field.items[i][j] = Symbols::Border;
			}
			if (str[i] == '*')
			{
				field.items[i][j] = Symbols::Filled;
			}
		}
		j++;
	}
	//необязательно закрывать открытый для чтения файл, он закроется автоматически +
	return true;
}

//передавать по константе поле, строкой имя файла +
//переименовать функцию, печать поля +
bool PrintField(std::string& const strOut, Field& const field)
{
	std::ofstream fileOut;
	fileOut.open(strOut);

	if (!fileOut.is_open())
	{
		std::cerr << "File error!" << std::endl;
		return false;
	}

	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			if (field.items[j][i] == Symbols::Empty)
			{
				fileOut << ' ';
			}
			if (field.items[j][i] == Symbols::Start)
			{
				fileOut << '0';
			}
			if (field.items[j][i] == Symbols::Border)
			{
				fileOut << '#';
			}
			if (field.items[j][i] == Symbols::Filled)
			{
				fileOut << '*';
			}
		}
		fileOut << "\n";
	}
	return true;
}

int main(char argc, char* argv[])
{
	//return EXIT_FAILER вместо 1+
	if (argc != 3)
	{
		std::cerr << "Invalid input format";
		return EXIT_FAILURE;
	}

	std::string strIn = argv[1];
	std::string strOut = argv[2];

	Field field;
	std::deque<Point> start;
	if (!InitializeField(field, start, strIn))
	{
		return EXIT_FAILURE;
	}

    field = Fill(field, start);

	if (!PrintField(strOut, field))
	{
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}