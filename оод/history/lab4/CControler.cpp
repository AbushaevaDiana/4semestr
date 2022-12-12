#include "CControler.h"

CControler::CControler(std::istream& input, std::ostream& output, sf::RenderWindow& window)
	: m_input(input)
	, m_output(output)
	, m_window(window)
	, m_actionMap({
		  { "circle", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateCircle(args);
		   } },
		  { "triangle", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateTriangle(args);
		   } },
		  { "rectangle", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateRectangle(args);
		   } }
		})
{
	m_shapeHandler = new CShapeHandler();
	m_userInterface = new CUserInterface(new CDragAndDropState(), m_window, m_shapeHandler);
}

CControler* CControler::m_instance = nullptr;

CControler* CControler::GetInstance(std::istream& input, std::ostream& output, sf::RenderWindow& window)
{
	if (m_instance == nullptr)
	{
		m_instance = new CControler(input, output, window);
	}

	return m_instance;
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

void CControler::HandleEvent(sf::Event event)
{
	auto position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
	m_shapeHandler->SetCursorPosition(position);

	switch (event.type)
	{
	case sf::Event::Closed:
	{
		m_window.close();
		break;
	}
	case sf::Event::MouseButtonPressed:
	{
		if (typeid(*m_userInterface->GetState()) == typeid(CDragAndDropState))
		{
			m_shapeHandler->DragAndDrop(event);
		}
		else if (typeid(*m_userInterface->GetState()) == typeid(CFillShapeState))
		{
			m_shapeHandler->Accept(new CFillShapeVisitor(m_userInterface->GetCurrentColor()), event);
		}
		else if (typeid(*m_userInterface->GetState()) == typeid(CFillBorderState))
		{
			m_shapeHandler->Accept(new CFillBorderVisitor(m_userInterface->GetCurrentColor()), event);
		}
		else if (typeid(*m_userInterface->GetState()) == typeid(CWidthBorderState))
		{
			m_shapeHandler->Accept(new CWidthBorderVisitor(m_userInterface->GetCurrentWidth()), event);
		}

		auto buttons = m_userInterface->GetButtons();
		for (const auto& button : buttons)
		{
			if (button->IsPointInButton({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
			{
				button->PressButton();
				break;
			}
		}

		break;
	}
	case sf::Event::MouseButtonReleased:
	{
		m_shapeHandler->CompletionOfMove();
		break;
	}
	case sf::Event::KeyPressed:
	{
		m_shapeHandler->HandleKeyPressed(event);
		break;
	}
	}

	m_shapeHandler->Moving();
	Draw();
}

void CControler::PrintInfoAboutShapes() const
{
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		m_output << shape->Tostring() << std::endl;
	}
}

void CControler::Draw() const
{
	m_window.clear(clearWindow);

	DrawUserInterface();
	DrawShapes();

	m_window.display();
}

void CControler::DrawShapes() const
{
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		shape->Draw(m_window);
	}
}

void CControler::DrawUserInterface() const
{
	m_userInterface->Draw();
}