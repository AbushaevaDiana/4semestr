#include "CRectangle.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CRectangle::CRectangle(CPoint const& leftTop, double heigth, double width, uint32_t outlineColor, uint32_t fillColor):
	CSolidShape(outlineColor, fillColor),
	m_leftTop(leftTop),
	m_heigth(heigth),
	m_width(width)
{
};

double CRectangle::GetArea() const
{
	return (m_heigth * m_width);
};

double CRectangle::GetPerimeter() const
{
	double perimeter = (m_heigth + m_width) * 2;
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
		<< "  area: " << GetArea() << "\n"
		<< "  fill color: " << std::hex << GetFillColor() << "\n"
		<< "  line color: " << std::hex << GetOutlineColor() << "\n";

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

double CRectangle::GetHeigth() const
{
	return m_heigth;
}
double CRectangle::GetWidth() const
{
	return m_width;
}
bool CRectangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = {
		m_leftTop,
		{ m_leftTop.x + m_width, m_leftTop.y},
		GetRightBottom(),
		{ m_leftTop.x, m_leftTop.y + m_heigth}
	};

	canvas.FillPolygon(points, GetFillColor());

	uint32_t outlineColor = GetOutlineColor();
	canvas.DrawLine(points[0], points[1], outlineColor);
	canvas.DrawLine(points[1], points[2], outlineColor);
	canvas.DrawLine(points[2], points[3], outlineColor);
	canvas.DrawLine(points[3], points[0], outlineColor);
	return true;
}
;
