#pragma once
#include "ISerializable.h"
#include "ICanvasDrawable.h"

/* Треугольник. Может быть нарисован на холсте, а также является сериализуемым */
class Triangle: public ICanvasDrawable, ISerializable
{
public:
	Triangle(CPoint const& leftTop, double heigth, double width);
	bool Draw(CoutCanvas& canvas) const override;
	bool SaveTo() const override;
	bool RestoreFrom() const override;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};