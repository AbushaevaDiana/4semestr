#pragma once
#include "CShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& outlineColor);
    double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToSting() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};