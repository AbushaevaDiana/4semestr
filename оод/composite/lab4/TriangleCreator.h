#pragma once
#include "CShapeCreator.h"

class CTriangleCreator : public CShapeCreator
{
public:
	CShapeDecorator* CreateShape(std::istream& args) override;
};