#include "CCompositeBuilder.h"

void CCompositeBuilder::SetShape()
{
	CShapeComposite* compositeShape = new CShapeComposite();

	for (const auto& shape : m_shapes)
	{
		compositeShape->Add(shape);
	}

	m_shape = compositeShape;
}

void CCompositeBuilder::SetPosition()
{
}

void CCompositeBuilder::SetBorderColor()
{
}

void CCompositeBuilder::SetBorderThickness()
{
}

void CCompositeBuilder::SetFillColor()
{
}