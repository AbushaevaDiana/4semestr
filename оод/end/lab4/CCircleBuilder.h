#pragma once
#include "CBuilder.h"
#include "CCircle.h"

class CCircleBuilder : public CBuilder
{
public:
	CCircleBuilder(std::vector<unsigned int> args)
		:m_centerPoint((float)args[0], (float)args[1])
		, m_radius((float)args[2])
	{
		m_borderThickness = args[3];
		m_borderColor = args[4];
		m_fillColor = args[5];
	}

	void SetShape() override;
	void SetPosition() override;

private:
	sf::Vector2f m_centerPoint;
	float m_radius;
};