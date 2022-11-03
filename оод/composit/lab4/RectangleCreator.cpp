#include "RectangleCreator.h"
#include "CRectangle.h"


std::unique_ptr<CShapeDecorator> RectangleCreator::CreateShape(std::vector<std::string>& input)
{
	sf::Vector2f leftTop = { stof(input[0]), stof(input[1]) };
	float heigth = stof(input[2]);
	float width = stof(input[3]);
	uint32_t outlineColor = stoul(input[4], nullptr, 16);
	uint32_t fillColor = stoul(input[5], nullptr, 16);
	input.clear();

	auto rectangle = std::make_unique<sf::RectangleShape>();

	rectangle->setSize({ width, heigth });
	rectangle->setPosition(leftTop);
	rectangle->setOutlineThickness(outlineThickness);
	rectangle->setOutlineColor(GetColor(outlineColor));
	rectangle->setFillColor(GetColor(fillColor));

	auto shape = std::make_unique<CRectangle>(std::move(rectangle), leftTop, heigth, width, GetColor(fillColor), GetColor(outlineColor));
	return shape;

};