#include "CSingleShapeDecorator.h"

void CSingleShapeDecorator::SetOutlineThickness(float thickness) const
{
	m_shape->setOutlineThickness(thickness);
}

void CSingleShapeDecorator::SetOutlineColor(sf::Color color) const
{
	m_shape->setOutlineColor(color);
}

void CSingleShapeDecorator::SetFillColor(sf::Color color) const
{
	m_shape->setFillColor(color);
}

void CSingleShapeDecorator::SetPosition(sf::Vector2f position) const
{
	m_shape->setPosition(position);
}

sf::Vector2f CSingleShapeDecorator::GetPosition() const
{
	return m_shape->getPosition();
}

void CSingleShapeDecorator::Draw(sf::RenderWindow& window) const
{
	if (m_selected)
	{
		sf::FloatRect bounds = m_shape->getGlobalBounds();
		window.draw(GetBounds({ bounds.left, bounds.top }, { bounds.width, bounds.height }));
	}
	window.draw(*m_shape);
}

sf::FloatRect CSingleShapeDecorator::GetGlobalBounds() const
{
	return m_shape->getGlobalBounds();
}