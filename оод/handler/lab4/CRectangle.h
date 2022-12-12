#pragma once
#include <iomanip>
#include <sstream>
#include "CSingleShapeDecorator.h"

class CRectangle: public CSingleShapeDecorator
{
public:
	CRectangle(sf::RectangleShape* shape, float width, float height, sf::Vector2f leftTop)
		: m_width(width),
		m_height(height),
		m_leftTop(leftTop)
	{
		m_shape = shape;
	}

	CRectangle(const CRectangle& src)
	{
		sf::RectangleShape* shape = static_cast<sf::RectangleShape*>(src.m_shape);

		sf::RectangleShape* rectangleShape = new sf::RectangleShape();
		rectangleShape->setPosition(src.m_leftTop.x, src.m_leftTop.y);
		rectangleShape->setSize(sf::Vector2f(src.m_width, src.m_height));
		rectangleShape->setOutlineThickness(shape->getOutlineThickness());
		rectangleShape->setOutlineColor(shape->getOutlineColor());
		rectangleShape->setFillColor(shape->getFillColor());

		m_shape = rectangleShape;
		m_width = src.m_width;
		m_height = src.m_height;
		m_leftTop = src.m_leftTop;
	}

protected:
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;

	sf::Vector2f GetLeftTop() const;
	sf::Vector2f GetRightTop() const;
	sf::Vector2f GetLeftBottom() const;
	sf::Vector2f GetRightBottom() const;
	float GetWidth() const;
	float GetHeight() const;

private:
	float m_width = 0;
	float m_height = 0;
	sf::Vector2f m_leftTop;
};