#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

int replace(const std:: string& strIn, const std::string& strOut, std::ifstream &fileIn, std::ofstream &fileOut)
{
	if (strIn == "")
	{
		while (fileIn.peek() != EOF)
		{
			std::string word;
			fileIn >> word;
			fileOut << word;
		}
		return 0;
	}

	while (fileIn.peek() != EOF)
	{
		std::string str;
		std::getline(fileIn, str);
		size_t pos = str.find(strIn);
		size_t len = strIn.length();
		while (pos != std::string::npos)
		{
			str.replace(pos, len, strOut);
			pos = str.find(strIn);
		};
		fileOut << str;
	};
	return 0;
};

int main(int argc, char* argv[])

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_ALL, "Russian");
	setlocale(0, "Rus");

	if (argc != 5)
	{
		std::cout << "Invalid input format";
		return 0;
	}


	//Открытие файлов
	std::string file = argv[1];
	std::ifstream fileIn;
	fileIn.open(file);
	file = argv[2];
	std::ofstream fileOut;
	fileOut.open(file);

	if (!(fileIn.is_open() && fileOut.is_open()))
	{
		std::cout << "Ошибка открытия файла!" << std::endl;
		return 0;
	}


	std::string strIn = argv[3];
	std::string strOut = argv[4];

	replace(strIn, strOut, fileIn, fileOut);

    //Закрытие файлов
	fileIn.close();
	fileOut.close();



	return 0;

}