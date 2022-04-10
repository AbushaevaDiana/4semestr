#include "CarComands.h"

int main()
{
	Car customerCar;
	CarControl carControl(customerCar, std::cin, std::cout);

	while (!std::cin.eof())
	{
		std::cout << "> ";
		if (!carControl.Command())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}