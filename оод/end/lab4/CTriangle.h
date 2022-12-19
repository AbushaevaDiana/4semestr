#pragma once
#include <iomanip>
#include <sstream>
#include "CSingleShapeDecorator.h"

class CTriangle : public CSingleShapeDecorator
{
public:
	CTriangle(sf::ConvexShape* shape, sf::Vector2f firstVertex, sf::Vector2f secondVertex, sf::Vector2f thirdVertex)
		: m_firstVertex(firstVertex),
		m_secondVertex(secondVertex),
		m_thirdVertex(thirdVertex)
	{
		m_shape = shape;
	}

	CTriangle(const CTriangle& src)
	{
		sf::ConvexShape* shape = static_cast<sf::ConvexShape*>(src.m_shape);

		sf::ConvexShape* triangleShape = new sf::ConvexShape();
		triangleShape->setPointCount(3);
		triangleShape->setPoint(0, sf::Vector2f(src.m_firstVertex.x, src.m_firstVertex.y));
		triangleShape->setPoint(1, sf::Vector2f(src.m_secondVertex.x, src.m_secondVertex.y));
		triangleShape->setPoint(2, sf::Vector2f(src.m_thirdVertex.x, src.m_thirdVertex.y));
		triangleShape->setOutlineThickness(shape->getOutlineThickness());
		triangleShape->setOutlineColor(shape->getOutlineColor());
		triangleShape->setFillColor(shape->getFillColor());

		m_shape = triangleShape;
		m_firstVertex = src.m_firstVertex;
		m_secondVertex = src.m_secondVertex;
		m_thirdVertex = src.m_thirdVertex;
	}

	sf::Vector2f GetVertex1() const;
	sf::Vector2f GetVertex2() const;
	sf::Vector2f GetVertex3() const;

	void SetPosition();

protected:
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string Tostring() const override;

private:
	sf::Vector2f m_firstVertex;
	sf::Vector2f m_secondVertex;
	sf::Vector2f m_thirdVertex;
};