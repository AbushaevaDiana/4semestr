#pragma once
#include "IShape.h"


class ISolidShape: virtual public IShape
{
	virtual uint32_t GetFillColor() const = 0;
};