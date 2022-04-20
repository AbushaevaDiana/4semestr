#include "CControler.h"

int main()
{
	CControler controler(std::cin, std::cout);

	while (!std::cin.eof())
	{
		std::cout << "> ";
		if (!controler.Command())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}