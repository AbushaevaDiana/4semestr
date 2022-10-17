#include "CCircle.h"
#include "math.h"
#include <sstream>
#include <cstdint>
#include "Line.h"

CCircle::CCircle(ShapePtr&& shape, sf::Vector2f const& center, float const& radius, sf::Color fillColor, sf::Color outlineColor):
	CShapeDecorator(std::move(shape), fillColor, outlineColor),
	m_center(center),
	m_radius(radius)
{
};

float CCircle::GetArea() const
{
	float area = pow(m_radius, 2)* M_PI;
	return area;
};

float CCircle::GetPerimeter() const
{
	float perimeter = M_PI * 2 * m_radius;
	return perimeter;
};

std::string CCircle::ToString() const
{
	std::ostringstream strm;
	strm
		<< ">Circle:\n"
		<< "  center(" << m_center.x << ", " << m_center.y << ")\n"
		<< "  radius: " << m_radius << std::endl
		<< "  perimeter: " << GetPerimeter() << std::endl
		<< "  area: " << GetArea() << std::endl;

	return strm.str();
};


float CCircle::GetRadius() const
{
	return m_radius;
}

sf::Vector2f CCircle::GetCenter() const
{
	return m_center;
}
