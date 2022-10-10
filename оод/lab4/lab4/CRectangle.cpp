#include "CRectangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CRectangle::CRectangle(SapePtr&& shape, CPoint const& leftTop, float heigth, float width):
	CShapeDecorator(std::move(shape)),
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
		<< "  heigth: " << m_heigth << "\n"
		<< "  width: " << m_width << "\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n";

	return strm.str();
}
CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}
CPoint CRectangle::GetRightBottom() const
{
	CPoint rigthBottom = { m_leftTop.x + m_width, m_leftTop.y + m_heigth};
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

std::size_t CRectangle::getPointCount() const
{
	return 1;
}

sf::Vector2f CRectangle::getPoint(std::size_t index) const
{
	return m_leftTop;
}

