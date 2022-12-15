#include <fstream>
#include "const.h"
#include "CControler.h"

int main()
{
	std::ifstream fileIn(FILE_IN);
	std::ofstream fileOut(FILE_OUT);
	setlocale(LC_ALL, "Russian");

	sf::RenderWindow window(sf::VideoMode(windowW, windowH), windowTitle, windowStyle);

	CControler* handler = CControler::GetInstance(fileIn, fileOut, window);

	handler->ReadShapes();

	handler->Draw();

	while (window.isOpen())
	{
		sf::Event event;
		if (window.waitEvent(event))
		{
			handler->HandleEvent(event);
		}
	}

	handler->PrintInfoAboutShapes();

	return 0;
}