#include "CCreateRectangleCommand.h"

void CCreateRectangleCommand::Execute()
{
	std::string args = rectangleXD + " " + rectangleYD + " " + rectangleWD + " " + rectangleHD +
		+" " + rectangleOutlineD + " " + rectangleFillD;
	std::istringstream strm(args);
	m_userInterface->m_shapeHendler->CreateRectangle(strm);
}