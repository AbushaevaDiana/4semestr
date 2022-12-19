#pragma once
#include "CBuilder.h"
#include "CRectangle.h"

class CRectangleBuilder : public CBuilder
{
public:
	void SetShape() override;
	void SetPosition() override;

	CRectangleBuilder(std::vector<unsigned int> args)
		:m_leftTop((float)args[0], (float)args[1])
		, m_width((float)args[2])
		, m_height((float)args[3])
	{
		m_borderThickness = args[4];
		m_borderColor = args[5];
		m_fillColor = args[6];
	}

private:
	sf::Vector2f m_leftTop;
	float m_width;
	float m_height;
};