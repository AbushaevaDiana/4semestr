#pragma once
#include "ISolidShape.h"
#include "CShape.h"
#include <optional>

class CSolidShape: virtual public ISolidShape, public CShape
{
	//виртуальное наследование: разобраться, использовать только там, где нужно
	//в каких случаях нужен свой деструктор
public:
	CSolidShape(uint32_t outlineColor, uint32_t fillColor);
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
	~CSolidShape() {};
private:
	uint32_t m_fillColor;
};