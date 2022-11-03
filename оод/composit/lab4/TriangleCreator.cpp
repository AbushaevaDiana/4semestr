#include "TriangleCreator.h"
#include "CTriangle.h"


std::unique_ptr<CShapeDecorator> TriangleCreator::CreateShape(std::vector<std::string>& input)
{
	sf::Vector2f vertex1 = { stof(input[0]), stof(input[1]) };
	sf::Vector2f vertex2 = { stof(input[2]), stof(input[3]) };
	sf::Vector2f vertex3 = { stof(input[4]), stof(input[5]) };
	uint32_t outlineColor = stoul(input[6], nullptr, 16);
	uint32_t fillColor = stoul(input[7], nullptr, 16);
	input.clear();

	auto triangle = std::make_unique<sf::ConvexShape>();

	triangle->setPointCount(3);
	triangle->setPoint(0, vertex1);
	triangle->setPoint(1, vertex2);
	triangle->setPoint(2, vertex3);
	triangle->setOutlineThickness(outlineThickness);
	triangle->setOutlineColor(GetColor(outlineColor));
	triangle->setFillColor(GetColor(fillColor));

	auto shape = std::make_unique<CTriangle>(std::move(triangle), vertex1, vertex2, vertex3, GetColor(fillColor), GetColor(outlineColor));
	return shape;

};