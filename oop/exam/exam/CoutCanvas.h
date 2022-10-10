#pragma once
#include "ICanvas.h"

/* �����. ������ ������������ ��������� ������� � cout ������� ��������� � �� ��������� */
class CoutCanvas: public ICanvas
{
	void DrawLine(CPoint const& startPoint, CPoint const& endPoint) const override;
    void DrawCircle(CPoint const& center, const double radius) const override;
	~CoutCanvas() {};
};