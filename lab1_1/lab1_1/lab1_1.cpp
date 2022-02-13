// lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;

int main(int argc, char* argv[])

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_ALL, "Russian");
	setlocale(0, "Rus");

	//Открытие файлов
	string file = argv[1];
	ifstream fileIn;
	fileIn.open(file);
	ofstream fileOut;
	fileOut.open("../output.txt");

	if (fileIn.is_open() && fileOut.is_open())
	{
		string strIn = argv[2];
		string strOut = argv[3];


		if (strIn == "")
		{
			while (fileIn.peek() != EOF)
			{
				string word;
				fileIn >> word;
				fileOut << word;
			}
		}
		else {
			while (fileIn.peek() != EOF)
			{
				char ch;
				fileIn >> ch;

				if (ch == strIn[0])
				{
					string str = "";
					str = str + ch;
					for (int i = 1; i < strIn.length(); i++)
					{
						fileIn >> ch;
						if (ch == strIn[i])
						{
							str = str + ch;
						}
						else
						{
							break;
						};
					};
					if (str == strIn)
					{
						fileOut << strOut;
					}
					else
					{
						fileOut << str;
					}
				}
				else
				{
					fileOut << ch;
				}
			};
		};
		fileOut << endl << strOut << endl << strIn;

		//Закрытие файлов
		fileIn.close();
		fileOut.close();
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	return 0;

}