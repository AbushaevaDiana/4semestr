#include "CShapeHandler.h"

void CShapeHandler::CreateCircle(std::istringstream& args)
{
	CCircleCreator creator;
	CShapeDecorator* circle = creator.CreateShape(args);
	m_shapes.push_back(circle);
}

void CShapeHandler::CreateTriangle(std::istringstream& args)
{
	CTriangleCreator creator;
	CShapeDecorator* triangle = creator.CreateShape(args);
	m_shapes.push_back(triangle);
}

void CShapeHandler::CreateRectangle(std::istringstream& args)
{
	CRectangleCreator creator;
	CShapeDecorator* rectangle = creator.CreateShape(args);
	m_shapes.push_back(rectangle);
}

void CShapeHandler::SelectingShape(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (const auto& shape : m_shapes)
		{
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				for (const auto& shape : m_selectedShapes)
				{
					ClearSelectedShapes(shape);
				}
			}

			if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
			{
				if (shape->GetSelect())
				{
					ResetSelectingShape(shape);
				}
				else
				{
					SetSelectingShape(shape);
				}

				break;
			}
		}
	}
}

void CShapeHandler::SetSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(true);
	m_selectedShapes.push_back(shape);
}

void CShapeHandler::ResetSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	auto it = find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
	m_selectedShapes.erase(it);
}

void CShapeHandler::ClearSelectedShapes(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	m_selectedShapes.clear();
}

void CShapeHandler::SetCursorPosition(sf::Vector2f position)
{
	m_cursorPosition = position;
}

void CShapeHandler::PreparingForMove(sf::Event event)
{
	for (const auto& shape : m_shapes)
	{
		sf::Vector2f clickPosition = { (float)event.mouseButton.x, (float)event.mouseButton.y };
		if (shape->IsPointInShape(clickPosition) && shape->GetSelect())
		{

			m_isMove = true;
			m_cursorOffset.x = m_cursorPosition.x - shape->GetPosition().x;
			m_cursorOffset.y = m_cursorPosition.y - shape->GetPosition().y;
			break;
		}
	}
}

void CShapeHandler::Moving()
{
	if (m_selectedShapes.size() == 1 && m_isMove)
	{
		m_selectedShapes.back()->SetPosition({
			m_cursorPosition.x - m_cursorOffset.x,
			m_cursorPosition.y - m_cursorOffset.y
			});
	}
}

void CShapeHandler::CompletionOfMove()
{
	m_isMove = false;
}

void CShapeHandler::HandleKeyPressed(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			GroupShapes();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			UngroupShapes();
		}

	}
}

void CShapeHandler::GroupShapes()
{
	if (m_selectedShapes.size() > 1)
	{

		CShapeComposite* compositeShape = new CShapeComposite();

		std::vector<CShapeDecorator*> copySelectedShapes = m_selectedShapes;

		for (const auto& shape : copySelectedShapes)
		{
			compositeShape->Add(shape);
			auto it = find(m_shapes.begin(), m_shapes.end(), shape);
			m_shapes.erase(it);
			ResetSelectingShape(shape);
		}

		SetSelectingShape(compositeShape);
		m_shapes.push_back(compositeShape);
	}
}

void CShapeHandler::UngroupShapes()
{
	if (m_selectedShapes.size() == 1 && dynamic_cast<CShapeComposite*>(m_selectedShapes.back()))
	{

		CShapeComposite* compositeShape = static_cast<CShapeComposite*>(m_selectedShapes.back());

		std::vector<CShapeDecorator*> compositeShapes = compositeShape->GetShapes();

		auto it = find(m_shapes.begin(), m_shapes.end(), m_selectedShapes.back());
		m_shapes.erase(it);
		ResetSelectingShape(m_selectedShapes.back());

		for (const auto& shape : compositeShapes)
		{
			SetSelectingShape(shape);
			m_shapes.push_back(shape);
		}
	}
}

std::vector<CShapeDecorator*> CShapeHandler::GetShapes()
{
	return m_shapes;
}

void CShapeHandler::AddShape(CShapeDecorator* shape)
{
	m_shapes.push_back(shape);
}

void CShapeHandler::DragAndDrop(sf::Event event)
{
	SelectingShape(event);
	PreparingForMove(event);
}

void CShapeHandler::FillShape(sf::Event event, sf::Color color)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetFillColor(color);
		}
	}
}

void CShapeHandler::FillBorder(sf::Event event, sf::Color color)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetOutlineColor(color);
		}
	}
}

void CShapeHandler::SetWidth(sf::Event event, float width)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetOutlineThickness(width);
		}
	}
}

std::vector<CShapeDecorator*> CShapeHandler::CopyShapes(std::vector<CShapeDecorator*> shapes)
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