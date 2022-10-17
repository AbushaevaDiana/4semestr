#pragma once
#include <memory>
#include <string>
#include "CShapeDecorator.h"
#include <string>
#include <sstream>
#include <iterator> 
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>
#include <vector>

int outlineThickness = 5;

struct IShapeCreator
{
public:
	virtual std::unique_ptr<CShapeDecorator> CreateShape(std::vector<std::string>& input) = 0;
	virtual ~IShapeCreator() = default;
};

sf::Color GetColor(uint32_t color);