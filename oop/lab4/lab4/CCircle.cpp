#include "CCircle.h"
#include "math.h"
#include <sstream>
#include <cstdint>


CCircle::CCircle(CPoint const& center, double const& radius, uint32_t const& outlineColor, uint32_t const& fillColor):
	m_center(center),
	m_radius(radius),
	CSolidShape(outlineColor, fillColor)
{
};

double CCircle::GetArea() const
{
	double area = pow(m_radius, 2)* M_PI;
	return area;
};

double CCircle::GetPerimeter() const
{
	double perimeter = M_PI * 2 * m_radius;
	return perimeter;
};

std::string CCircle::ToString() const
{
	std::ostringstream strm;
	// для вывода числе с точкой fixed << setprecision(2)
	strm
		<< ">Circle:\n"
		<< "  center(" << m_center.x << ", " << m_center.y << ")\n"
		<< "  radius: " << m_radius << "\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n"
		<< "  fill color: " << std::hex << GetFillColor() << "\n"
		<< "  line color: " << std::hex << GetOutlineColor() << "\n";

	return strm.str();
};


double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
