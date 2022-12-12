#include "CShapeDecorator.h"

bool CShapeDecorator::IsPointInShape(sf::Vector2f point) const
{
	return GetGlobalBounds().contains(point);
}

void CShapeDecorator::SetSelect(bool state)
{
	m_selected = state;
}

bool CShapeDecorator::GetSelect() const
{
	return m_selected;
}

sf::RectangleShape CShapeDecorator::GetBounds(sf::Vector2f position, sf::Vector2f size) const
{
	sf::RectangleShape rectangle = sf::RectangleShape();
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setOutlineThickness(frameThickness);
	rectangle.setOutlineColor(frameOutlineColor);
	rectangle.setFillColor(frameFillColor);

	return rectangle;
}
