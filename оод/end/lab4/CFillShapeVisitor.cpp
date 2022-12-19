#include "CFillShapeVisitor.h"

void CFillShapeVisitor::VisitShape(CShapeDecorator* shape)
{
	shape->SetFillColor(m_color);
}