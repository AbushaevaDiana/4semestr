#pragma once
#include "IVisitor.h"

class CFillShapeVisitor : public IVisitor
{
public:
	CFillShapeVisitor(sf::Color color)
		:m_color(color)
	{};

	void VisitShape(CShapeDecorator* shape) override;

private:
	sf::Color m_color;
};