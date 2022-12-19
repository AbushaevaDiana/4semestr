#include "CRectangle.h"

float CRectangle::GetArea() const
{
	return m_width * m_height;
}

float CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

std::string CRectangle::Tostring() const
{
	std::ostringstream strm;

	strm << "Rectangle: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

float CRectangle::GetWidth() const
{
	return m_width;
}

float CRectangle::GetHeight() const
{
	return m_height;
}