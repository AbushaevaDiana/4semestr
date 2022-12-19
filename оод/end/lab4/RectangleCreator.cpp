#include "RectangleCreator.h"
#include "CRectangle.h"

CShapeDecorator* CRectangleCreator::CreateShape(std::istringstream& args)
{
	sf::Vector2f leftTop;
	float width;
	float height;
	std::string outlineColorStr;
	std::string fillColorStr;

	args >> leftTop.x >> leftTop.y >> width >> height >> outlineColorStr >> fillColorStr;

	sf::RectangleShape* rectangle = new sf::RectangleShape();
	sf::Color outlineColor = GetColor(std::stoul(outlineColorStr, nullptr, 16));
	sf::Color fillColor = GetColor(std::stoul(fillColorStr, nullptr, 16));

	rectangle->setPosition(leftTop.x, leftTop.y);
	rectangle->setSize(sf::Vector2f(width, height));
	rectangle->setOutlineThickness(borderThickness);
	rectangle->setOutlineColor(outlineColor);
	rectangle->setFillColor(fillColor);

	CRectangle* rectangleDec = new CRectangle(rectangle, width, height);

	return rectangleDec;
}