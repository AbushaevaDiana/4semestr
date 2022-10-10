#pragma once
#include "ICanvas.h"

/* Холст. Вместо фактического рисования выводит в cout команды рисования и их параметры */
class CoutCanvas: public ICanvas
{
	void DrawLine(CPoint const& startPoint, CPoint const& endPoint) const override;
    void DrawCircle(CPoint const& center, const double radius) const override;
	~CoutCanvas() {};
};