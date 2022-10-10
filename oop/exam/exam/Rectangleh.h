#pragma once
#include "ISerializable.h"
#include "ICanvasDrawable.h"


/* Прямоугольник. Может быть нарисован на холсте, а также является сериализуемым */
class Rectangle: public ICanvasDrawable, ISerializable

{
    /* Написать недостающий код */
public:
	Rectangle(CPoint const& leftTop, double heigth, double width);
	bool Draw(CoutCanvas& canvas) const override;
	bool SaveTo() const override;
	bool RestoreFrom() const override;
private:
	CPoint m_leftTop;
	double m_heigth;
	double m_width;
};