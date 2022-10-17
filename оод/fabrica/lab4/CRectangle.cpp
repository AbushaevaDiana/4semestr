#include "CRectangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CRectangle::CRectangle(ShapePtr&& shape, sf::Vector2f const& leftTop, float heigth, float width, sf::Color fillColor, sf::Color outlineColor):
	CShapeDecorator(std::move(shape), fillColor, outlineColor),
	m_leftTop(leftTop),
	m_heigth(heigth),
	m_width(width)
{
};

float CRectangle::GetArea() const
{
	return (m_heigth * m_width);
};

float CRectangle::GetPerimeter() const
{
	float perimeter = (m_heigth + m_width) * 2;
	return perimeter;
};

std::string CRectangle::ToString() const
{
	std::ostringstream strm;
	strm
		<< ">Rectangle:\n"
		<< "  leftTop(" << m_leftTop.x << ", " << m_leftTop.y << ")\n"
		<< "  heigth: " << m_heigth << std::endl
		<< "  width: " << m_width << std::endl
		<< "  perimeter: " << GetPerimeter() << std::endl
		<< "  area: " << GetArea() << std::endl;

	return strm.str();
}
sf::Vector2f CRectangle::GetLeftTop() const
{
	return m_leftTop;
}
sf::Vector2f CRectangle::GetRightBottom() const
{
	sf::Vector2f rigthBottom = { m_leftTop.x + m_width, m_leftTop.y + m_heigth};
	return rigthBottom;
}

float CRectangle::GetHeigth() const
{
	return m_heigth;
}
float CRectangle::GetWidth() const
{
	return m_width;
}


