#pragma once
#include "CSolidShape.h"
#define M_PI 3.14159265358979323846

class CCircle: public CSolidShape
{
public:
	CCircle(CPoint const& center, double const& radius, uint32_t const& outlineColor, uint32_t const& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
private:
	CPoint m_center;
	double m_radius;
};