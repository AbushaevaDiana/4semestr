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
	return 0;
};

double CTriangel::GetPerimeter() const
{
	long double line1SizeIn2;
	line1SizeIn2 = pow((m_vertex1.x - m_vertex2.x), 2) + pow((m_vertex1.y - m_vertex2.y), 2);
	double line1Size = sqrt(line1SizeIn2);

	long double line2SizeIn2;
	line2SizeIn2 = pow((m_vertex2.x - m_vertex3.x), 2) + pow((m_vertex2.y - m_vertex3.y), 2);
	double line2Size = sqrt(line2SizeIn2);

	long double line3SizeIn2;
	line3SizeIn2 = pow((m_vertex3.x - m_vertex1.x), 2) + pow((m_vertex3.y - m_vertex1.y), 2);
	double line3Size = sqrt(line3SizeIn2);

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