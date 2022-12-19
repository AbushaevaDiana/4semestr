#pragma once
#include "CBuilder.h"
#include "CTriangle.h"

class CTriangleBuilder : public CBuilder
{
public:
	CTriangleBuilder(std::vector<unsigned int> args)
		:m_firstVertex((float)args[0], (float)args[1])
		, m_secondVertex((float)args[2], (float)args[3])
		, m_thirdVertex((float)args[4], (float)args[5])
	{
		m_borderThickness = args[6];
		m_borderColor = args[7];
		m_fillColor = args[8];
	}

	void SetShape() override;
	void SetPosition() override;

private:
	sf::Vector2f m_firstVertex;
	sf::Vector2f m_secondVertex;
	sf::Vector2f m_thirdVertex;
};