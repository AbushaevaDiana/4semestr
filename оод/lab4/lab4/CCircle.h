#pragma once
#include "CShapeDecorator.h"
#define _USE_MATH_DEFINES
#include <cmath>

class CCircle: public CShapeDecorator
{
public:
	CCircle(ShapePtr&& shape, sf::Vector2f const& center, float const& radius, sf::Color fillColor, sf::Color outlineColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	sf::Vector2f GetCenter() const;
	float GetRadius() const;
	~CCircle() {};
private:
	sf::Vector2f m_center;
	float m_radius;
};
