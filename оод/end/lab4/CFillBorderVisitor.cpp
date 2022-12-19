#include "CFillBorderVisitor.h"

void CFillBorderVisitor::VisitShape(CShapeDecorator* shape)
{
	shape->SetOutlineColor(m_color);
}