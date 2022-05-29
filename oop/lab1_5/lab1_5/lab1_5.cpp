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

const int MATRIX_SIZE = 100;
typedef Symbols Matrix[MATRIX_SIZE][MATRIX_SIZE];
struct Field
{
	Matrix items;
};
struct Point
{
	int x;
	int y;
};

bool InitializeField(Field& field, std::deque<Point>& start, std::string& strIn);
Field Fill(Field& field, std::deque<Point>& start);
bool PrintField(std::string& const strOut, Field& field);
void FillPoint(Field& field, int y, int x, std::deque<Point>& start);

void FillPoint(Field& field, int y, int x, std::deque<Point>& start)
{
	if (y < MATRIX_SIZE && x < MATRIX_SIZE && y >= 0 && x >= 0 && field.items[y][x] == Symbols::Empty)
	{
		field.items[y][x] = Symbols::Filled;
		start.push_back({ x, y });
	}
}
//TODO: наименование lowerCamelCase X Y -> x y +
//TODO: i2 убрать(лишнее действие, можно сразу push_back({ x, y }))  +
Field Fill(Field& field, std::deque<Point>& start)
{
	while(!start.empty())
	{
		Point i1 = start[0];
		FillPoint(field, i1.y, i1.x + 1, start);
		FillPoint(field, i1.y + 1, i1.x, start);
		FillPoint(field, i1.y, i1.x - 1, start);
		FillPoint(field, i1.y - 1, i1.x, start);

		start.pop_front();
	}
	
	return field;
};

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
				start.push_back({ j, i });
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
	return true;
}

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