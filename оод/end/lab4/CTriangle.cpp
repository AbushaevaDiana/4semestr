#include "CTriangle.h"

float CTriangle::GetArea() const
{
	sf::Vector2f vector1 = { m_secondVertex.x - m_firstVertex.x, m_secondVertex.y - m_firstVertex.y };
	sf::Vector2f vector2 = { m_thirdVertex.x - m_firstVertex.x, m_thirdVertex.y - m_firstVertex.y };
	float result = (vector1.x * vector2.y - vector2.x * vector1.y) / 2;

	return result < 0 ? result * -1 : result;
}

float CTriangle::GetPerimeter() const
{
	return sqrt(pow((m_secondVertex.x - m_firstVertex.x), 2) + pow((m_secondVertex.y - m_firstVertex.y), 2)) +
		sqrt(pow((m_thirdVertex.x - m_firstVertex.x), 2) + pow((m_thirdVertex.y - m_firstVertex.y), 2)) +
		sqrt(pow((m_thirdVertex.x - m_secondVertex.x), 2) + pow((m_thirdVertex.y - m_secondVertex.y), 2));
}

std::string CTriangle::Tostring() const
{
	std::ostringstream strm;
	strm << "Triangle: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

sf::Vector2f CTriangle::GetVertex1() const
{
	return m_firstVertex;
}

sf::Vector2f CTriangle::GetVertex2() const
{
	return m_secondVertex;
}

sf::Vector2f CTriangle::GetVertex3() const
{
	return m_thirdVertex;
}

void CTriangle::SetPosition()
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_shape);

	triangle->setPoint(0, sf::Vector2f(m_firstVertex.x, m_firstVertex.y));
	triangle->setPoint(1, sf::Vector2f(m_secondVertex.x, m_secondVertex.y));
	triangle->setPoint(2, sf::Vector2f(m_thirdVertex.x, m_thirdVertex.y));
}