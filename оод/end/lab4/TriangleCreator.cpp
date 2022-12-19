#include "TriangleCreator.h"
#include "CTriangle.h"

CShapeDecorator* CTriangleCreator::CreateShape(std::istringstream& args)
{
	sf::Vector2f vertex1;
	sf::Vector2f vertex2;
	sf::Vector2f vertex3;
	std::string outlineColorStr;
	std::string fillColorStr;

	args >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> outlineColorStr >> fillColorStr;

	sf::ConvexShape* triangle = new sf::ConvexShape();
	sf::Color outlineColor = GetColor(std::stoul(outlineColorStr, nullptr, 16));
	sf::Color fillColor = GetColor(std::stoul(fillColorStr, nullptr, 16));

	triangle->setPointCount(3);
	triangle->setPoint(0, sf::Vector2f(vertex1.x, vertex1.y));
	triangle->setPoint(1, sf::Vector2f(vertex2.x, vertex2.y));
	triangle->setPoint(2, sf::Vector2f(vertex3.x, vertex3.y));
	triangle->setOutlineThickness(borderThickness);
	triangle->setOutlineColor(outlineColor);
	triangle->setFillColor(fillColor);

	CTriangle* triangleDec = new CTriangle(triangle, vertex1, vertex2, vertex3);

	return triangleDec;
}