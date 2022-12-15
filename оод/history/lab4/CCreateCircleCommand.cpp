#include "CCreateCircleCommand.h"

void CCreateCircleCommand::Execute()
{
	std::string args = circleXD + " " + circleYD + " " + circleRD +
		+" " + circleOutlineD + " " + circleFillD;
	std::istringstream strm(args);
	m_userInterface->m_shapeHandler->CreateCircle(strm);
}