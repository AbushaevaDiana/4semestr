#pragma once
#include "IVisitor.h"

class CFillBorderVisitor : public IVisitor
{
public:
	CFillBorderVisitor(sf::Color color)
		:m_color(color)
	{};

	void VisitShape(CShapeDecorator* shape) override;

private:
	sf::Color m_color;
};