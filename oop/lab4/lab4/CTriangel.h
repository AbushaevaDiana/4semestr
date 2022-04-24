#pragma once
#include "CSolidShape.h"

class CTriangel: public CSolidShape
{
public:
	CTriangel(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t const& outlineColor, uint32_t const& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};