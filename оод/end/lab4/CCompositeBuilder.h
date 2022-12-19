#pragma once
#include "const.h"
#include "CBuilder.h"
#include "CShapeComposite.h"

class CCompositeBuilder : public CBuilder
{
public:
	CCompositeBuilder(std::vector<CShapeDecorator*> shapes)
		:m_shapes(shapes)
	{
		m_borderThickness = 5;
		m_borderColor = 1887209727;
		m_fillColor = 3032272127;
	}

	void SetShape() override;
	void SetPosition() override;

	void SetBorderThickness() override;
	void SetBorderColor() override;
	void SetFillColor() override;

private:
	std::vector<CShapeDecorator*> m_shapes;
};