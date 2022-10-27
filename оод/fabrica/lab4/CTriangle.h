#pragma once
#include "CShapeDecorator.h"

class CTriangle: public CShapeDecorator
{
public:
	CTriangle(ShapePtr&& shape, sf::Vector2f const& vertex1, sf::Vector2f const& vertex2, sf::Vector2f const& vertex3, sf::Color fillColor, sf::Color outlineColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	sf::Vector2f GetVertex1() const;
	sf::Vector2f GetVertex2() const;
	sf::Vector2f GetVertex3() const;
	~CTriangle() {};

	sf::FloatRect getGlobalBounds() const override;
private:
	sf::Vector2f m_vertex1;
	sf::Vector2f m_vertex2;
	sf::Vector2f m_vertex3;
};