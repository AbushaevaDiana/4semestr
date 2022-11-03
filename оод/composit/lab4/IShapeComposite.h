#pragma once
#include "CShapeDecorator.h"

class CShapeComposite: CShapeDecorator {
public:
	CShapeComposite(std::unique_ptr<CShapeDecorator> shape, float width, float heigth, sf::Vector2f leftTop);
	sf::FloatRect getGlobalBounds() const override {};
	float GetArea() const override {};
	float GetPerimeter() const override {};
	std::string ToString() const override {};
private:
	std::unique_ptr<CShapeDecorator> m_shape;
	std::vector<std::unique_ptr<CShapeDecorator>> m_shapes;
	float m_width; 
	float m_heigth;
	sf::Vector2f m_leftTop;
};