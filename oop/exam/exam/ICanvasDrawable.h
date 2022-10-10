#pragma once
#include "ICanvas.h"

/* Интерфейс объектов, которые могут быть нарисованы (Draw) на холсте (canvas) */
class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas& canvas) const = 0;
};