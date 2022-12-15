#pragma once
#include "CShapeCreator.h"

class CCircleCreator : public CShapeCreator
{
public:
	CShapeDecorator* CreateShape(std::istream& args) override;
};