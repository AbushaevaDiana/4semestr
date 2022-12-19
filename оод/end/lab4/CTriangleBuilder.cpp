#include "CTriangleBuilder.h"

void CTriangleBuilder::SetShape()
{
	m_shape = new CTriangle(new sf::ConvexShape(3), m_firstVertex, m_secondVertex, m_thirdVertex);
}

void CTriangleBuilder::SetPosition()
{
	CTriangle* triangle = static_cast<CTriangle*>(m_shape);
	triangle->SetPosition();
}