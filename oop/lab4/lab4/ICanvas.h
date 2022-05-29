#pragma once
#include <vector>

class CPoint
{
public:
	double x = 0;
	double y = 0;
};

class ICanvas
{
public:
	virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint, uint32_t lineColor) const = 0;
	virtual void FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor) const = 0;
	virtual void DrawCircle(CPoint const& center, const double radius, uint32_t lineColor, uint32_t fillColor) const = 0;
	//virtual void FillCircle(CPoint const& center, const double radius, uint32_t fillColor) const = 0;
	virtual ~ICanvas() {};
};