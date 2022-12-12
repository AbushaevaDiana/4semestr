#pragma once
#define _USE_MATH_DEFINES
#include <iomanip>
#include <sstream>
#include <math.h>
#include "CSingleShapeDecorator.h"

class CCircle: public CSingleShapeDecorator
{
public:
	CCircle(sf::CircleShape* shape, sf::Vector2f centerPoint, float radius)
		: m_centerPoint(centerPoint),
		m_radius(radius)
	{
		m_shape = shape;
	}

	CCircle(const CCircle& src)
	{
		sf::CircleShape* shape = static_cast<sf::CircleShape*>(src.m_shape);

		sf::CircleShape* circleShape = new sf::CircleShape();
		circleShape->setPosition(src.m_centerPoint);
		circleShape->setRadius(src.m_radius);
		circleShape->setOutlineThickness(shape->getOutlineThickness());
		circleShape->setOutlineColor(shape->getOutlineColor());
		circleShape->setFillColor(shape->getFillColor());

		m_shape = circleShape;
		m_centerPoint = src.m_centerPoint;
		m_radius = src.m_radius;
	}

protected:
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string Tostring() const override;

	sf::Vector2f GetCenter() const;
	float GetRadius() const;
private:
	sf::Vector2f m_centerPoint;
	float m_radius;
};