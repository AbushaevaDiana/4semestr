#pragma once
#include "CShapeDecorator.h"

class CSingleShapeDecorator : public CShapeDecorator
{
public:
	void SetOutlineThickness(float thickness) const override;
	void SetOutlineColor(sf::Color color) const override;
	void SetFillColor(sf::Color color) const override;

	void SetPosition(sf::Vector2f position) const override;
	sf::Vector2f GetPosition() const override;

	void Draw(sf::RenderWindow& window) const override;

	sf::FloatRect GetGlobalBounds() const override;

protected:
	sf::Shape* m_shape;
};
