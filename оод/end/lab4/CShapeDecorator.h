#pragma once
#include "const.h"
#include <string>
#include <memory>

class CShapeDecorator
{
public:
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string Tostring() const = 0;

	virtual void SetOutlineThickness(float thickness) const = 0;
	virtual void SetOutlineColor(sf::Color color) const = 0;
	virtual void SetFillColor(sf::Color color) const = 0;

	virtual void SetPosition(sf::Vector2f position) const = 0;
	virtual sf::Vector2f GetPosition() const = 0;

	virtual sf::FloatRect GetGlobalBounds() const = 0;

	bool IsPointInShape(sf::Vector2f point) const;

	virtual void Draw(sf::RenderWindow& window) const = 0;

	void SetSelect(bool state);
	bool GetSelect() const;

protected:
	sf::RectangleShape GetBounds(sf::Vector2f position, sf::Vector2f size) const;

	bool m_selected = false;
};