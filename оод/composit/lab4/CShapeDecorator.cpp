#include "CShapeDecorator.h"

void CShapeDecorator::Draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
};

CShapeDecorator::CShapeDecorator(ShapePtr&& shape, sf::Color fillColor, sf::Color outlineColor)
	: m_shape(std::move(shape)),
      m_fillColor(fillColor),
      m_outlineColor(outlineColor)
{
}

void CShapeDecorator::setBorderColor(sf::Color color)
{
	m_borderColor = color;
};

sf::Color CShapeDecorator::getBorderColor()
{
	return m_borderColor;
};