#pragma once
#include "IShape.h"
#include <optional>

//зачем virtual?
class CShape : virtual public IShape
{
public:
	CShape(uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
protected:
	double GetLineSize(CPoint startLOfLine, CPoint endLOfLine) const;
private:
	uint32_t m_outlineColor;
	//mutable std::optional<double> m_area;
	//mutable std::optional<double> m_perimeter;
};