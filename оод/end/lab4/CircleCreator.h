#pragma once
#include "CShapeCreator.h"

class CCircleCreator : public CShapeCreator
{
public:
	CShapeDecorator* CreateShape(std::istringstream& args) override;
};