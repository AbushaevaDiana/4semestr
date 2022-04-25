#include "CTriangel.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CTriangel::CTriangel(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t const& outlineColor, uint32_t const& fillColor) :
	m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3),
	CSolidShape(outlineColor, fillColor)
{
};

double CTriangel::GetArea() const
{
	// 
	double halfOfPerimeter = GetPerimeter() / 2;
	double line1 = GetLineSize(m_vertex1, m_vertex2);
	double line2 = GetLineSize(m_vertex2, m_vertex3);
	double line3 = GetLineSize(m_vertex3, m_vertex1);
	double area = sqrt(halfOfPerimeter * (halfOfPerimeter - line1) * (halfOfPerimeter - line2) * (halfOfPerimeter - line3));

	return area;
};

double CTriangel::GetPerimeter() const
{
	double line1Size = GetLineSize(m_vertex1, m_vertex2);
	double line2Size = GetLineSize(m_vertex2, m_vertex3);
	double line3Size = GetLineSize(m_vertex3, m_vertex1);

	double perimeter = line1Size + line2Size + line3Size;
	return perimeter;
};

std::string CTriangel::ToString() const
{
	std::ostringstream strm;
	// для вывода числе с точкой fixed << setprecision(2)
	strm
		<< ">Triangel:\n"
		<< "  vertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		<< "  vertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		<< "  vertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n"
		<< "  fill color: " << std::hex << GetFillColor() << "\n"
		<< "  line color: " << std::hex << GetOutlineColor() << "\n";

	return strm.str();
};


CPoint CTriangel::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangel::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangel::GetVertex3() const
{
	return m_vertex3;
}