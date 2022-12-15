#pragma once
#include "CShapeCreator.h"

class CRectangleCreator : public CShapeCreator
{
public:
	CShapeDecorator* CreateShape(std::istream& args) override;
};
