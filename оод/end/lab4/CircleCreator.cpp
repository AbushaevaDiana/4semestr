#include "CircleCreator.h"
#include "CCircle.h"
#include <iostream>

CShapeDecorator* CCircleCreator::CreateShape(std::istringstream& args)
{
	sf::Vector2f centerPoint;
	float radius;
	std::string outlineColorStr;
	std::string fillColorStr;

	args >> centerPoint.x >> centerPoint.y >> radius >> outlineColorStr >> fillColorStr;

	sf::CircleShape* circle = new sf::CircleShape();
	sf::Color outlineColor = GetColor(std::stoul(outlineColorStr, nullptr, 16));
	sf::Color fillColor = GetColor(std::stoul(fillColorStr, nullptr, 16));

	circle->setPosition(centerPoint.x - radius, centerPoint.y - radius);
	circle->setRadius(radius);
	circle->setOutlineThickness(borderThickness);
	circle->setOutlineColor(outlineColor);
	circle->setFillColor(fillColor);

	CShapeDecorator* circleDec = new CCircle(circle, radius);

	return circleDec;
}