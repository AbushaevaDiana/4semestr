#include "CControler.h"
#include <typeinfo>

CControler::CControler(std::istream& input, std::ostream& output, sf::RenderWindow& window)
	: m_input(input)
	, m_output(output)
	, m_window(window)
	, m_actionMap({
		  { "circle", [this](std::istream& args) {
			   return CreateCircle(args);
		   } },
		  { "triangle", [this](std::istream& args) {
			   return CreateTriangle(args);
		   } },
		  { "rectangle", [this](std::istream& args) {
			   return CreateRectangle(args);
		   } }
		})
{
}

void CControler::ReadShapes() const
{
	std::string commandLine;

	while (getline(m_input, commandLine))
	{
		std::istringstream strm(commandLine);

		std::string action;
		strm >> action;

		auto it = m_actionMap.find(action);
		if (it != m_actionMap.end())
		{
			it->second(strm);
		}
	}
}

void CControler::DrawShapes() const
{
	m_window.clear(sf::Color::White);

	for (const auto& shape : m_shapes)
	{
		shape->Draw(m_window);
	}

	m_window.display();
}

void CControler::HandleEvent(sf::Event event)
{
	m_cursorPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));

	switch (event.type)
	{
		case sf::Event::Closed:
		{
			m_window.close();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			HandleMouseButtonPressed(event);
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			m_isMove = false;
			break;
		}
		case sf::Event::KeyPressed:
		{
			HandleKeyPressed(event);
			break;
		}
	}

	Moving();
	DrawShapes();
}


void CControler::PrintInfoAboutShapes() const
{
	for (const auto& shape : m_shapes)
	{
		m_output << shape->ToString() << std::endl;
	}
}

void CControler::CreateCircle(std::istream& args)
{
	CCircleCreator creator;
	auto circle = creator.CreateShape(args);
	m_shapes.push_back(std::move(circle));
}

void CControler::CreateTriangle(std::istream& args)
{
	CTriangleCreator creator;
	auto triangle = creator.CreateShape(args);
	m_shapes.push_back(std::move(triangle));
}

void CControler::CreateRectangle(std::istream& args)
{
	CRectangleCreator creator;
	auto rectangle = creator.CreateShape(args);
	m_shapes.push_back(std::move(rectangle));
}

void CControler::HandleMouseButtonPressed(sf::Event event)
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
					AddSelectingShape(shape);	
					PreparingForMove(shape);
				}

				break;
			}
		}
	}
}

void CControler::AddSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(true);
	m_selectedShapes.push_back(shape);
}

void CControler::ResetSelectingShape(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	auto it = find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
	m_selectedShapes.erase(it);
}

void CControler::ClearSelectedShapes(CShapeDecorator* shape)
{
	shape->SetSelect(false);
	m_selectedShapes.clear();
}

void CControler::PreparingForMove(CShapeDecorator* shape)
{
	m_isMove = true;
	m_cursorOffset.x = m_cursorPosition.x - shape->GetPosition().x;
	m_cursorOffset.y = m_cursorPosition.y - shape->GetPosition().y;
}

void CControler::Moving() const
{
	if (m_selectedShapes.size() == 1 && m_isMove)
	{
		m_selectedShapes.back()->SetPosition({
			m_cursorPosition.x - m_cursorOffset.x,
			m_cursorPosition.y - m_cursorOffset.y
		});
	}
}

void CControler::HandleKeyPressed(sf::Event event)
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

void CControler::GroupShapes()
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

		AddSelectingShape(compositeShape);
		m_shapes.push_back(compositeShape);
	}
}

void CControler::UngroupShapes()
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
			AddSelectingShape(shape);
			m_shapes.push_back(shape);
		}
	}
}