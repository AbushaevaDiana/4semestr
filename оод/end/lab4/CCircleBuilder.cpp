#include "CCircleBuilder.h"

void CCircleBuilder::SetShape()
{
	m_shape = new CCircle(new sf::CircleShape(m_radius), m_radius);
}

void CCircleBuilder::SetPosition()
{
	m_shape->SetPosition({ m_centerPoint.x - m_radius, m_centerPoint.y - m_radius });
}