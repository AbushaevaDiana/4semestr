#include "CircleCreator.h"
#include "CCircle.h"


std::unique_ptr<CShapeDecorator> CircleCreator::CreateShape(std::vector<std::string>& input)
{
	sf::Vector2f center = { std::stof(input[0]), std::stof(input[1]) };
	float radius = std::stof(input[2]);
	uint32_t outlineColor = std::stoul(input[3], nullptr, 16);
	uint32_t fillColor = std::stoul(input[4], nullptr, 16);

	auto circle = std::make_unique<sf::CircleShape>();

	circle->setPosition(center);
	circle->setRadius(radius);
	circle->setOutlineThickness(outlineThickness);
	circle->setOutlineColor(GetColor(outlineColor));
	circle->setFillColor(GetColor(fillColor));

	auto shape = std::make_unique<CCircle>(std::move(circle), center, radius, GetColor(fillColor), GetColor(outlineColor));
	return shape;

};