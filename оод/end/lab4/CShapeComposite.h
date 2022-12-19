#pragma once
#include <iomanip>
#include <sstream>
#include "CShapeDecorator.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"

class CShapeComposite : public CShapeDecorator
{
public:
	CShapeComposite()
	{
	}

	CShapeComposite(const CShapeComposite& src)
	{
		m_shapes = CopyShapes(src.m_shapes);
	}

	float GetArea() const override;
	float GetPerimeter() const override;
	std::string Tostring() const override;

	void SetOutlineThickness(float thickness) const override;
	void SetOutlineColor(sf::Color color) const override;
	void SetFillColor(sf::Color color) const override;

	void SetPosition(sf::Vector2f position) const override;
	sf::Vector2f GetPosition() const override;

	void Draw(sf::RenderWindow& window) const override;

	sf::FloatRect GetGlobalBounds() const override;

	void Add(CShapeDecorator* shape);
	void Remove(CShapeDecorator* shape);
	std::vector<CShapeDecorator*> GetShapes() const;

protected:
	std::vector<CShapeDecorator*> m_shapes;

private:
	std::vector<CShapeDecorator*> CopyShapes(std::vector<CShapeDecorator*> shapes);
};