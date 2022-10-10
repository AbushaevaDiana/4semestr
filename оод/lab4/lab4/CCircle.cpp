#include "CCircle.h"
#include "math.h"
#include <sstream>
#include <cstdint>
#include "Line.h"

CCircle::CCircle(SapePtr&& shape, CPoint const& center, float const& radius):
	CShapeDecorator(std::move(shape)),
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
		<< "  radius: " << m_radius << "\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n";

	return strm.str();
};


float CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

std::size_t CCircle::getPointCount() const
{
	return 1;
}

sf::Vector2f CCircle::getPoint(std::size_t index) const
{
	return m_center;
}
