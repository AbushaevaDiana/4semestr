#pragma once
#include "CBuilder.h"

class CShapeBuilderCreator
{
public:
	void SetBuilder(CBuilder* builder);
	CShapeDecorator* CreateShape();

private:
	CBuilder* m_builder;
};