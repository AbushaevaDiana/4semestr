#pragma once
#include "IShapeDecorator.h"

class CTriangle: public CShapeDecorator
{
public:
	CTriangle(SapePtr&& shape, CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3);
	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	~CTriangle() {};
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};