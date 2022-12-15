#include "CShapeCreator.h"

sf::Color CShapeCreator::GetColor(uint32_t color)
{
	uint32_t blue = color % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t red = ((color / 256) / 256) % 256;

	return sf::Color(red, green, blue);
}