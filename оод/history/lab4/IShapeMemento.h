#pragma once
#include "CShapeDecorator.h"

class IShapeMemento
{
public:
	IShapeMemento(std::vector<CShapeDecorator*> shapes, std::vector<CShapeDecorator*> selectedShapes)
		: m_shapes(shapes)
		, m_selectedShapes(selectedShapes)
	{
	};

	std::vector<CShapeDecorator*> m_shapes;
	std::vector<CShapeDecorator*> m_selectedShapes;
};