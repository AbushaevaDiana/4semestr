#pragma once
#include "IShapeCreator.h"

class CircleCreator: public IShapeCreator
{
public:
	std::unique_ptr<CShapeDecorator> CreateShape(std::vector<std::string>& input) override;
};