#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

typedef std::unique_ptr<sf::Shape>  ShapePtr;

class CShapeDecorator: public sf::Shape
{
public:
	std::size_t getPointCount() const override { return 0; };
	sf::Vector2f getPoint(std::size_t index) const override { return { 0, 0 }; };
	virtual sf::FloatRect getGlobalBounds() const = 0;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	void Draw(sf::RenderWindow& window);
	void setBorderColor(sf::Color color);
	sf::Color getBorderColor();
protected:
	CShapeDecorator(ShapePtr&& shape, sf::Color fillColor, sf::Color outlineColor);
	ShapePtr m_shape;
private:
	 sf::Color m_fillColor;
	 sf::Color m_outlineColor;
	 sf::Color m_borderColor = sf::Color::Transparent;
};
