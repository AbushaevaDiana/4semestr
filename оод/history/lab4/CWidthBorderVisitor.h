#pragma once
#include "IVisitor.h"

class CWidthBorderVisitor : public IVisitor
{
public:
	CWidthBorderVisitor(float width)
		:m_width(width)
	{};

	void VisitShape(CShapeDecorator* shape) override;

private:
	float m_width;
};