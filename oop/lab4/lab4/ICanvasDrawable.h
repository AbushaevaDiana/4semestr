#pragma once
#include "ICanvas.h"

class ICanvasDrawable
{
public:
	virtual bool Draw(ICanvas& canvas) const = 0;
	virtual ~ICanvasDrawable() {};
	//��������� ��� ����������� ����������, ����� �� �����
};