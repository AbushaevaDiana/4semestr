#pragma once
#include "IShape.h"

//virtual насследование дл€ чего, вы€снить и уметь обь€снить +
class CShape: virtual public IShape
{
public:
	CShape(uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
	~CShape() {};
private:
	uint32_t m_outlineColor;
};

double GetLineSize(CPoint startLOfLine, CPoint endLOfLine);