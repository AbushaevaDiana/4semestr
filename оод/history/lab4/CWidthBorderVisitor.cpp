#include "CWidthBorderVisitor.h"

void CWidthBorderVisitor::VisitShape(CShapeDecorator* shape)
{
	shape->SetOutlineThickness(m_width);
}