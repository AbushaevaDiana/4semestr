#pragma once
#include "IShapeDecorator.h"
#define M_PI 3.14159265358979323846

class CCircle: public CShapeDecorator
{
public:
	CCircle(SapePtr&& shape, CPoint const& center, float const& radius);
	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetCenter() const;
	float GetRadius() const;
	~CCircle() {};
private:
	CPoint m_center;
	float m_radius;
};
