#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

typedef sf::Vector2f CPoint;
typedef std::unique_ptr<sf::Shape>  SapePtr;

class CShapeDecorator : public sf::Shape
{
public:
	virtual std::size_t getPointCount() const = 0;
	virtual sf::Vector2f getPoint(std::size_t index) const = 0;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;

protected:
	CShapeDecorator( SapePtr&& shape)
		: m_shape(std::move(shape))
	{
	}

private:
	 SapePtr m_shape;
};
