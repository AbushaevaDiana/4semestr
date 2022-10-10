#pragma once
#include "ICanvas.h"

/* ��������� ��������, ������� ����� ���� ���������� (Draw) �� ������ (canvas) */
class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas& canvas) const = 0;
};