#pragma once
#include "CSolidShape.h"

class CTriangle: public CSolidShape
{
public:
	//примитивные типы передавать по значению uint32_t +
	CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
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