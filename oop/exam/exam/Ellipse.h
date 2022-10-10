#pragma once
#include "ISerializable.h"
#include "ICanvasDrawable.h"

/* Эллипс. Может быть нарисован на холсте, а также является сериализуемым */
class Ellipse: public ICanvasDrawable, public ISerializable
{
public:
	Ellipse(CPoint const& center, double const& radius);
	void Draw(ICanvas& canvas) const override;
	void SaveTo(std::ostream& out) const override;
	void RestoreFrom(std::istream& in) override;
private:
	CPoint m_center;
	double m_radius
};