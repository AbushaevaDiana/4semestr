#include "IShapeComposite.h"

CShapeComposite::CShapeComposite(std::unique_ptr<CShapeDecorator> shape, float width, float heigth, sf::Vector2f leftTop) :
	CShapeDecorator(std::move(shape), sf::Color::Blue, sf::Color::Blue),
	m_width(width),
	m_heigth(heigth),
	m_shapes({ std::move(shape) })
{
};