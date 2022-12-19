#pragma once
#include <iomanip>
#include <sstream>
#include "CSingleShapeDecorator.h"

class CRectangle : public CSingleShapeDecorator
{
public:
	CRectangle(sf::RectangleShape* shape, float width, float height)
		: m_width(width),
		m_height(height)
	{
		m_shape = shape;
	}

	CRectangle(const CRectangle& src)
	{
		sf::RectangleShape* shape = static_cast<sf::RectangleShape*>(src.m_shape);

		sf::RectangleShape* rectangleShape = new sf::RectangleShape();
		rectangleShape->setPosition(shape->getPosition());
		rectangleShape->setSize(sf::Vector2f(src.m_width, src.m_height));
		rectangleShape->setOutlineThickness(shape->getOutlineThickness());
		rectangleShape->setOutlineColor(shape->getOutlineColor());
		rectangleShape->setFillColor(shape->getFillColor());

		m_shape = rectangleShape;
		m_width = src.m_width;
		m_height = src.m_height;
	}

	float GetWidth() const;
	float GetHeight() const;

protected:
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string Tostring() const override;

private:
	float m_width = 0;
	float m_height = 0;
};