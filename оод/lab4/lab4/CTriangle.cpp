#include "CTriangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>
#include "Line.h"

CTriangle::CTriangle(SapePtr&& shape, CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3):
	CShapeDecorator(std::move(shape)),
	m_vertex1(vertex1),
	m_vertex2(vertex2),
	m_vertex3(vertex3)
{
};

float CTriangle::GetArea() const
{
	float halfOfPerimeter = GetPerimeter() / 2;
	float line1 = GetLineSize(m_vertex1, m_vertex2);
	float line2 = GetLineSize(m_vertex2, m_vertex3);
	float line3 = GetLineSize(m_vertex3, m_vertex1);
	float area = sqrt(halfOfPerimeter * (halfOfPerimeter - line1) * (halfOfPerimeter - line2) * (halfOfPerimeter - line3));

	return area;
};

float CTriangle::GetPerimeter() const
{
	float line1Size = GetLineSize(m_vertex1, m_vertex2);
	float line2Size = GetLineSize(m_vertex2, m_vertex3);
	float line3Size = GetLineSize(m_vertex3, m_vertex1);

	float perimeter = line1Size + line2Size + line3Size;
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
		<< "  area: " << GetArea() << "\n";

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

std::size_t CTriangle::getPointCount() const
{
	return 1;
}

sf::Vector2f CTriangle::getPoint(std::size_t index) const
{
	return m_vertex1;
}

