#include "CControler.h"

CHandler::CHandler(std::istream& input, std::ostream& output, sf::RenderWindow& window)
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

CHandler* CHandler::m_instance = nullptr;

CHandler* CHandler::GetInstance(std::istream& input, std::ostream& output, sf::RenderWindow& window)
{
	if (m_instance == nullptr)
	{
		m_instance = new CHandler(input, output, window);
	}

	return m_instance;
}

void CHandler::ReadShapes() const
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

void CHandler::HandleEvent(sf::Event event)
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
			m_shapeHandler->FillShape(event, m_userInterface->GetCurrentColor());
		}
		else if (typeid(*m_userInterface->GetState()) == typeid(CFillBorderState))
		{
			m_shapeHandler->FillBorder(event, m_userInterface->GetCurrentColor());
		}
		else if (typeid(*m_userInterface->GetState()) == typeid(CWidthBorderState))
		{
			m_shapeHandler->SetWidth(event, m_userInterface->GetCurrentWidth());
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

void CHandler::PrintInfoAboutShapes() const
{
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		m_output << shape->ToString() << std::endl;
	}
}

void CHandler::Draw() const
{
	m_window.clear(CLEAR_WINDOW_COLOR);

	DrawUserInterface();
	DrawShapes();

	m_window.display();
}

void CHandler::DrawShapes() const
{
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		shape->Draw(m_window);
	}
}

void CHandler::DrawUserInterface() const
{
	m_userInterface->Draw();
}