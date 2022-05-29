#include "CLineSegment.h"
#include "math.h"
#include <sstream>
#include <cstdint>

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t outlineColor):
	CShape(outlineColor),
	m_startPoint(startPoint),
	m_endPoint(endPoint)
{
};

double CLineSegment::GetArea() const 
{
	return 0;
};

double CLineSegment::GetPerimeter() const 
{
	double lineSize = GetLineSize(m_startPoint, m_endPoint);
	return lineSize;
};

std::string CLineSegment::ToString() const
{
	std::ostringstream strm;
	strm 
		<< ">Line:\n"
		<< "  startPoint(" << m_startPoint.x << ", " << m_startPoint.y << ")\n"
		<< "  endPoint(" << m_endPoint.x << ", " << m_endPoint.y << ")\n"
		<< "  perimeter: " << GetPerimeter() << "\n"
		<< "  area: " << GetArea() << "\n"
		<< "  line color: " << std::hex << GetOutlineColor() << "\n";

	return strm.str();
};


CPoint CLineSegment::GetStartPoint() const 
{
	return m_startPoint;
};

CPoint CLineSegment::GetEndPoint() const 
{
	return m_endPoint;
}
bool CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine(m_startPoint, m_endPoint, GetOutlineColor());
	return true;
}
;