#include "Line.h"

float GetLineSize(sf::Vector2f startLOfLine, sf::Vector2f endLOfLine)
{
	long float lineSizeIn2;
	lineSizeIn2 = pow((endLOfLine.x - startLOfLine.x), 2) + pow((endLOfLine.y - startLOfLine.y), 2);
	float lineSize = sqrt(lineSizeIn2);

	return lineSize;
}

