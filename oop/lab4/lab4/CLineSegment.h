#pragma once
#include "CShape.h"
#include <optional>

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t outlineColor);
    double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	~CLineSegment() {};
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};