#include "CCircle.h"

float CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

float CCircle::GetPerimeter() const
{
	return M_PI * m_radius * 2;
}

std::string CCircle::Tostring() const
{
	std::ostringstream strm;

	strm << "Circle: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

float CCircle::GetRadius() const
{
	return m_radius;
}