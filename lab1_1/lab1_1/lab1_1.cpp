// lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

bool isParameterTrue(int argc, char* argv[])
{
	if (argc != 5) { return false; }
	return true;
}

int main(int argc, char* argv[])

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_ALL, "Russian");
	setlocale(0, "Rus");

	if (isParameterTrue(argc, argv)) {

		//Открытие файлов
		std::string file = argv[1];
		std::ifstream fileIn;
		fileIn.open(file);
		file = argv[2];
		std::ofstream fileOut;
		fileOut.open(file);

		if (fileIn.is_open() && fileOut.is_open())
		{
			std::string strIn = argv[3];
			std::string strOut = argv[4];


			if (strIn == "")
			{
				while (fileIn.peek() != EOF)
				{
					std::string word;
					fileIn >> word;
					fileOut << word;
				}
			}
			else {
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
			};
			//		fileOut << std::endl << strOut << std::endl << strIn;

					//Закрытие файлов
			fileIn.close();
			fileOut.close();
		}
		else
			std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else
	{
		std::cout << "Invalid input format";
	}

	return 0;

}