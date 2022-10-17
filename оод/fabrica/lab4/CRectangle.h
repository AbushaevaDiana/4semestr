#pragma once
#include "CShapeDecorator.h"

class CRectangle: public CShapeDecorator
{
public:
	CRectangle(ShapePtr&& shape, sf::Vector2f const& leftTop, float heigth, float width, sf::Color fillColor, sf::Color outlineColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	sf::Vector2f GetLeftTop() const;
	sf::Vector2f GetRightBottom() const;
	float GetHeigth() const;
	float GetWidth() const;
	~CRectangle() {};
private:
	sf::Vector2f m_leftTop;
	float m_heigth;
	float m_width;
};