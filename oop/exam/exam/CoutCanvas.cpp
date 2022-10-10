#include "CoutCanvas.h"
#include <iostream>
#include <string>


void CoutCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint) const
{
	std::string sPoint = "(" + std::to_string(startPoint.x) + " " + std::to_string(startPoint.y) + ")";
	std::string ePoint = "(" + std::to_string(endPoint.x) + " " + std::to_string(endPoint.y) + ")";
	std::cout << "DrawLine(" + sPoint + ";" + ePoint + ")";
}

void CoutCanvas::DrawCircle(CPoint const& center, const double radius) const
{
	std::string centerP = "(" + std::to_string(center.x) + " " + std::to_string(center.y) + ")";
	std::string rad = std::to_string(radius);
	std::cout << "DrawCircle(" + center + ";" + rad + ")";
}
