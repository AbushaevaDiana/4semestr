#pragma once
#include "IShapeDecorator.h"

class CRectangle: public CShapeDecorator
{
public:
	CRectangle(SapePtr&& shape, CPoint const& leftTop, float heigth, float width);
	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	float GetHeigth() const;
	float GetWidth() const;
	~CRectangle() {};
private:
	CPoint m_leftTop;
	float m_heigth;
	float m_width;
};