// lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>



using namespace std;

int main(int argc, char* argv[])

{
	setlocale(LC_ALL, "Russian");
	
	//Открытие файлов
	string file = argv[1];
	ifstream fileIn;
	fileIn.open(file);
	ofstream fileOut;
	fileOut.open("../output.txt");

	if (fileIn.is_open() && fileOut.is_open())
	{
		string strIn = argv[2];
		int n = 1;
		n =	strIn.length();
		char* strArray = new char[n];

		if (fileIn.peek() != EOF) 
		{
			fileIn >> strArray;
			fileOut << strArray;
		};
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	//Закрытие файлов
	fileIn.close();
	fileOut.close();


	return 0;

}