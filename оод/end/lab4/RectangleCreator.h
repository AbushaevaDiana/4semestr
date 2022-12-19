#pragma once
#include "CShapeCreator.h"

class CRectangleCreator : public CShapeCreator
{
public:
	CShapeDecorator* CreateShape(std::istringstream& args) override;
};
