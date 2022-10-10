#pragma once
#include <vector>

class CPoint
{
public:
	double x = 0;
	double y = 0;
};

/* Интерфейс холста. Позволяет рисовать отрезки прямых линий и эллипсы */

class ICanvas
{
public:
	virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint) const = 0;
	virtual void DrawCircle(CPoint const& center, const double radius) const = 0;
	virtual ~ICanvas() {};
};