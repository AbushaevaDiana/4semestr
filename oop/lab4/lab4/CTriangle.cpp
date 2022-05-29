#include "CTriangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor) :
	CSolidShape(outlineColor, fillColor),
	m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3)
	//родительский класс в начало списка везде	+
{
};

double CTriangle::GetArea() const
{
	double halfOfPerimeter = GetPerimeter() / 2;
	double line1 = GetLineSize(m_vertex1, m_vertex2);
	double line2 = GetLineSize(m_vertex2, m_vertex3);
	double line3 = GetLineSize(m_vertex3, m_vertex1);
	double area = sqrt(halfOfPerimeter * (halfOfPerimeter - line1) * (halfOfPerimeter - line2) * (halfOfPerimeter - line3));

	return area;
};

double CTriangle::GetPerimeter() const
{
	double line1Size = GetLineSize(m_vertex1, m_vertex2);
	double line2Size = GetLineSize(m_vertex2, m_vertex3);
	double line3Size = GetLineSize(m_vertex3, m_vertex1);

	double perimeter = line1Size + line2Size + line3Size;
	return perimeter;
};

std::string CTriangle::ToString() const
{
	std::ostringstream strm;
	strm
		<< ">Triangle:\n"
		<< "  vertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		<< "  vertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		<< "  vertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n"
		<< "  fill color: " << std::hex << GetFillColor() << "\n"
		<< "  line color: " << std::hex << GetOutlineColor() << "\n";

	return strm.str();
};


CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

bool CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = 
	{
	    GetVertex1(),
	    GetVertex2(),
	    GetVertex3()
	};

	canvas.FillPolygon(points, GetFillColor());

	uint32_t outlineColor = GetOutlineColor();
	canvas.DrawLine(points[0], points[1], outlineColor);
	canvas.DrawLine(points[1], points[2], outlineColor);
	canvas.DrawLine(points[0], points[2], outlineColor);
	return true;
}
