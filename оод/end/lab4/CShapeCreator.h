#pragma once
#include <memory>
#include <string>
#include "const.h"
#include "CShapeDecorator.h"


class CShapeCreator
{
public:
	virtual CShapeDecorator* CreateShape(std::istringstream& args) = 0;	

protected:
	sf::Color GetColor(uint32_t color);
};