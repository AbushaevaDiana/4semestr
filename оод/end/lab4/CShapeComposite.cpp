#include "CShapeComposite.h"

float CShapeComposite::GetArea() const
{
	float area = 0;

	for (const auto& shape : m_shapes)
	{
		area += shape->GetArea();
	}

	return area;
}

float CShapeComposite::GetPerimeter() const
{
	float perimeter = 0;

	for (const auto& shape : m_shapes)
	{
		perimeter += shape->GetPerimeter();
	}

	return perimeter;
}

std::string CShapeComposite::Tostring() const
{
	std::ostringstream strm;

	strm << "Composite shape: "
		<< "Area: " << GetArea() << "; "
		<< "Perimeter: " << GetPerimeter();

	return strm.str();
}

void CShapeComposite::SetOutlineThickness(float thickness) const
{
	for (const auto& shape : m_shapes)
	{
		shape->SetOutlineThickness(thickness);
	}
}

void CShapeComposite::SetOutlineColor(sf::Color color) const
{
	for (const auto& shape : m_shapes)
	{
		shape->SetOutlineColor(color);
	}
}

void CShapeComposite::SetFillColor(sf::Color color) const
{
	for (const auto& shape : m_shapes)
	{
		shape->SetFillColor(color);
	}
}

void CShapeComposite::SetPosition(sf::Vector2f position) const
{
	sf::Vector2f offset;
	offset.x = position.x - GetPosition().x;
	offset.y = position.y - GetPosition().y;

	for (const auto& shape : m_shapes)
	{
		shape->SetPosition({ offset.x + shape->GetPosition().x, shape->GetPosition().y + offset.y });
	}
}

sf::Vector2f CShapeComposite::GetPosition() const
{
	sf::FloatRect bounds = GetGlobalBounds();
	return { bounds.left, bounds.top };
}

void CShapeComposite::Draw(sf::RenderWindow& window) const
{
	if (m_selected)
	{
		sf::FloatRect bounds = GetGlobalBounds();
		window.draw(GetBounds({ bounds.left, bounds.top }, { bounds.width, bounds.height }));
	}

	for (const auto& shape : m_shapes)
	{
		shape->Draw(window);
	}
}

sf::FloatRect CShapeComposite::GetGlobalBounds() const
{
	sf::FloatRect firstShapeBounds = m_shapes.front()->GetGlobalBounds();
	sf::Vector2f min, max;
	min.x = firstShapeBounds.left;
	min.y = firstShapeBounds.top;
	max.x = min.x + firstShapeBounds.width;
	max.y = min.y + firstShapeBounds.height;

	for (const auto& shape : m_shapes)
	{
		sf::FloatRect bounds = shape->GetGlobalBounds();

		if (bounds.left < min.x)
		{
			min.x = bounds.left;
		}
		if (bounds.top < min.y)
		{
			min.y = bounds.top;
		}
		if ((bounds.left + bounds.width) > max.x)
		{
			max.x = bounds.left + bounds.width;
		}
		if ((bounds.top + bounds.height) > max.y)
		{
			max.y = bounds.top + bounds.height;
		}
	}

	return sf::FloatRect(min.x, min.y, abs(max.x - min.x), abs(max.y - min.y));
}

void CShapeComposite::Add(CShapeDecorator* shape)
{
	m_shapes.push_back(shape);
}

void CShapeComposite::Remove(CShapeDecorator* shape)
{
	auto it = find(m_shapes.begin(), m_shapes.end(), shape);
	if (it != m_shapes.end())
	{
		m_shapes.erase(it);
	}
}

std::vector<CShapeDecorator*> CShapeComposite::GetShapes() const
{
	return m_shapes;
}

std::vector<CShapeDecorator*> CShapeComposite::CopyShapes(std::vector<CShapeDecorator*> shapes)
{
	std::vector<CShapeDecorator*> copyShapes;

	for (const auto& shape : shapes)
	{
		if (typeid(*shape) == typeid(CCircle))
		{
			CCircle* circleDecorator = new CCircle(*(CCircle*)shape);
			copyShapes.push_back(circleDecorator);
		}
		else if (typeid(*shape) == typeid(CTriangle))
		{
			CTriangle* triangleDecorator = new CTriangle(*(CTriangle*)shape);
			copyShapes.push_back(triangleDecorator);
		}
		else if (typeid(*shape) == typeid(CRectangle))
		{
			CRectangle* rectangleDecorator = new CRectangle(*(CRectangle*)shape);
			copyShapes.push_back(rectangleDecorator);
		}
		else if (typeid(*shape) == typeid(CShapeComposite))
		{
			CShapeComposite* compositeShapeDecorator = new CShapeComposite(*(CShapeComposite*)shape);
			copyShapes.push_back(compositeShapeDecorator);
		}
	}

	return copyShapes;
}