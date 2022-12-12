#include <fstream>
#include "const.h"
#include "CControler.h"

int main()
{
	std::ifstream fileIn(FILE_IN);
	std::ofstream fileOut(FILE_OUT);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), WINDOW_TITLE, WINDOW_STYLE);

	CHandler* handler = CHandler::GetInstance(fileIn, fileOut, window);

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