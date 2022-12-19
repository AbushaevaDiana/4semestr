#include "CRectangleBuilder.h"

void CRectangleBuilder::SetShape()
{
	m_shape = new CRectangle(new sf::RectangleShape({ m_width, m_height }), m_width, m_height);
}

void CRectangleBuilder::SetPosition()
{
	m_shape->SetPosition(m_leftTop);
}