#include "CLineSegment.h"
#include "math.h"

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& outlineColor):
	m_startPoint(startPoint),
	m_endPoint(endPoint),
	CShape(outlineColor)
{
};

double CLineSegment::GetArea() const 
{
	return 0;
};

double CLineSegment::GetPerimeter() const 
{
	long double lineSizeIn2;
	lineSizeIn2 = pow((m_endPoint.x - m_startPoint.x), 2) + pow((m_endPoint.y - m_startPoint.y), 2);
	double lineSize = sqrt(lineSizeIn2);
	return lineSize;
};

std::string CLineSegment::ToSting() const
{
	std::string infoOfLineSegment;
	infoOfLineSegment += "  startPoint(" + std::to_string(m_endPoint.x) + " " + std::to_string(m_endPoint.y) + ") \n";
	infoOfLineSegment += "  endPoint(" + std::to_string(m_startPoint.x) + " " + std::to_string(m_startPoint.y) + ")\n";
	infoOfLineSegment += "  outlineColor(" + std::to_string(GetOutlineColor()) + ")\n";
	infoOfLineSegment += "  area = " + std::to_string(GetArea()) + "\n";
	infoOfLineSegment += "  perimeter = " + std::to_string(GetPerimeter()) + "\n";
	return infoOfLineSegment;
};


CPoint CLineSegment::GetStartPoint() const 
{
	return m_startPoint;
};

CPoint CLineSegment::GetEndPoint() const 
{
	return m_endPoint;
};