#include "CTriangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>
#include "Line.h"

CTriangle::CTriangle(ShapePtr&& shape, sf::Vector2f const& vertex1, sf::Vector2f const& vertex2, sf::Vector2f const& vertex3, sf::Color fillColor, sf::Color outlineColor) :
	CShapeDecorator(std::move(shape), fillColor, outlineColor),
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
		<< "  perimeter: " << GetPerimeter() << std::endl
		<< "  area: " << GetArea() << std::endl;

	return strm.str();
};


sf::Vector2f CTriangle::GetVertex1() const
{
	return m_vertex1;
}

sf::Vector2f CTriangle::GetVertex2() const
{
	return m_vertex2;
}

sf::Vector2f CTriangle::GetVertex3() const
{
	return m_vertex3;
}


