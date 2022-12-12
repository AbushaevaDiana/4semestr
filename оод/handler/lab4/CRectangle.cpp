#include "CRectangle.h"
float CRectangle::GetArea() const
{
	return m_width * m_height;
}

float CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
	std::ostringstream strm;

	strm << "Rectangle: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

sf::Vector2f CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

sf::Vector2f CRectangle::GetRightTop() const
{
	return { m_leftTop.x + m_width, m_leftTop.y };
}

sf::Vector2f CRectangle::GetLeftBottom() const
{
	return { m_leftTop.x, m_leftTop.y + m_height };
}

sf::Vector2f CRectangle::GetRightBottom() const
{
	return { m_leftTop.x + m_width, m_leftTop.y + m_height };
}

float CRectangle::GetWidth() const
{
	return m_width;
}

float CRectangle::GetHeight() const
{
	return m_height;
}
