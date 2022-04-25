#include "CShape.h"

CShape::CShape(uint32_t outlineColor):
	m_outlineColor(outlineColor)
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

double CShape::GetLineSize(CPoint startLOfLine, CPoint endLOfLine) const
{
	long double lineSizeIn2;
	lineSizeIn2 = pow((endLOfLine.x - startLOfLine.x), 2) + pow((endLOfLine.y - startLOfLine.y), 2);
	double lineSize = sqrt(lineSizeIn2);

	return lineSize;
}

