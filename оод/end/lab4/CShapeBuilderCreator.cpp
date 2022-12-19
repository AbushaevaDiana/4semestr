#include "CShapeBuilderCreator.h"

void CShapeBuilderCreator::SetBuilder(CBuilder* builder)
{
	m_builder = builder;
}

CShapeDecorator* CShapeBuilderCreator::CreateShape()
{
	m_builder->SetShape();
	m_builder->SetPosition();
	m_builder->SetBorderThickness();
	m_builder->SetBorderColor();
	m_builder->SetFillColor();

	return m_builder->GetShape();
}