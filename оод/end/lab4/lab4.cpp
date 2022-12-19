#include <fstream>
#include "const.h"
#include "CHendler.h"

int main()
{
	std::ifstream fileIn(fileInConst);
	std::ofstream fileOut(fileOutConst);

	sf::RenderWindow window(sf::VideoMode(windowW, windowH), windowTitle, windowStyle);

	CHendler* Hendler = CHendler::GetInstance(fileIn, fileOut, window);

	Hendler->ReadShapes();

	Hendler->Draw();

	while (window.isOpen())
	{
		sf::Event event;
		if (window.waitEvent(event))
		{
			Hendler->HandleEvent(event);
		}
	}

	Hendler->PrintInfoAboutShapes();

	return 0;
}