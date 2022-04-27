#pragma once
#include "IShape.h"

//virtual ������������� ��� ����, �������� � ����� ��������� +
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