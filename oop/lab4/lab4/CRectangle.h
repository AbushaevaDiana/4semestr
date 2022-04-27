#pragma once
#include "CSolidShape.h"

class CRectangle: public CSolidShape
{
public:
	CRectangle(CPoint const& leftTop, double heigth, double width, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetHeigth() const;
	double GetWidth() const;
	~CRectangle() {};
private:
	CPoint m_leftTop;
	double m_heigth;
	double m_width;
};