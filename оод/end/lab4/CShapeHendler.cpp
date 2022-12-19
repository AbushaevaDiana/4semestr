#include "CShapeHendler.h"

void CShapeHendler::CreateCircle(std::istringstream& args)
{
	CCircleCreator creator;
	CShapeDecorator* circle = creator.CreateShape(args);
	m_shapes.push_back(circle);
}

void CShapeHendler::CreateTriangle(std::istringstream& args)
{
	CTriangleCreator creator;
	CShapeDecorator* triangle = creator.CreateShape(args);
	m_shapes.push_back(triangle);
}

void CShapeHendler::CreateRectangle(std::istringstream& args)
{
	CRectangleCreator creator;
	CShapeDecorator* rectangle = creator.CreateShape(args);
	m_shapes.push_back(rectangle);
}

void CShapeHendler::SelectingShape(sf::Event event)
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

void CShapeHendler::SetSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(true);
	m_selectedShapes.push_back(shape);
}

void CShapeHendler::ResetSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	auto it = find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
	m_selectedShapes.erase(it);
}

void CShapeHendler::ClearSelectedShapes(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	m_selectedShapes.clear();
}

void CShapeHendler::SetCursorPosition(sf::Vector2f position)
{
	m_cursorPosition = position;
}

void CShapeHendler::PreparingForMove(sf::Event event)
{
	for (const auto& shape : m_shapes)
	{
		sf::Vector2f clickPosition = { (float)event.mouseButton.x, (float)event.mouseButton.y };
		if (shape->IsPointInShape(clickPosition) && shape->GetSelect())
		{
			SaveHistory();

			m_isMove = true;
			m_cursorOffset.x = m_cursorPosition.x - shape->GetPosition().x;
			m_cursorOffset.y = m_cursorPosition.y - shape->GetPosition().y;
			break;
		}
	}
}

void CShapeHendler::Moving()
{
	if (m_selectedShapes.size() == 1 && m_isMove)
	{
		m_selectedShapes.back()->SetPosition({
			m_cursorPosition.x - m_cursorOffset.x,
			m_cursorPosition.y - m_cursorOffset.y
			});
	}
}

void CShapeHendler::CompletionOfMove()
{
	m_isMove = false;
}

void CShapeHendler::HandleKeyPressed(sf::Event event)
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			UndoHistory();
		}
	}
}

void CShapeHendler::GroupShapes()
{
	if (m_selectedShapes.size() > 1)
	{
		SaveHistory();

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

void CShapeHendler::UngroupShapes()
{
	if (m_selectedShapes.size() == 1 && dynamic_cast<CShapeComposite*>(m_selectedShapes.back()))
	{
		SaveHistory();

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

std::vector<CShapeDecorator*> CShapeHendler::GetShapes()
{
	return m_shapes;
}

void CShapeHendler::AddShape(CShapeDecorator* shape)
{
	m_shapes.push_back(shape);
}

void CShapeHendler::DragAndDrop(sf::Event event)
{
	SelectingShape(event);
	PreparingForMove(event);
}

void CShapeHendler::Accept(IVisitor* visitor, sf::Event event)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			SaveHistory();

			visitor->VisitShape(shape);
			break;
		}
	}
}

IShapeMemento CShapeHendler::GetState()
{
	std::vector<CShapeDecorator*> copyShapes = CopyShapes(m_shapes);
	std::vector<CShapeDecorator*> copySelectedShapes = CopyShapes(m_selectedShapes);

	return IShapeMemento(copyShapes, copySelectedShapes);
}

void CShapeHendler::RestoreState(const IShapeMemento& shapeMemento)
{
	m_shapes = shapeMemento.m_shapes;
	m_selectedShapes = shapeMemento.m_selectedShapes;

	m_cursorPosition = { 0, 0 };
	m_cursorOffset = { 0, 0 };
	m_isMove = false;
}

void CShapeHendler::SaveHistory()
{
	m_history.push(GetState());
}

void CShapeHendler::UndoHistory()
{
	if (m_history.size() > 0)
	{
		RestoreState(m_history.top());
		m_history.pop();
	}
}

std::vector<CShapeDecorator*> CShapeHendler::CopyShapes(std::vector<CShapeDecorator*> shapes)
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