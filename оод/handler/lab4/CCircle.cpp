#include "CCircle.h"

float CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

float CCircle::GetPerimeter() const
{
	return M_PI * m_radius * 2;
}

std::string CCircle::ToString() const
{
	std::ostringstream strm;

	strm << "Circle: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

sf::Vector2f CCircle::GetCenter() const
{
	return m_centerPoint;
}

float CCircle::GetRadius() const
{
	return m_radius;
}