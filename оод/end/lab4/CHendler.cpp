#include "CHendler.h"

CHendler::CHendler(std::istream& input, std::ostream& output, sf::RenderWindow& window)
	: m_input(input)
	, m_output(output)
	, m_window(window)
	, m_actionMap({
		  { "circle", [this](std::istringstream& args) {
			   return m_shapeHendler->CreateCircle(args);
		   } },
		  { "triangle", [this](std::istringstream& args) {
			   return m_shapeHendler->CreateTriangle(args);
		   } },
		  { "rectangle", [this](std::istringstream& args) {
			   return m_shapeHendler->CreateRectangle(args);
		   } }
		})
{
	m_shapeHendler = new CShapeHendler();
	m_fileHendler = new CFileHendler(fileSaveImport, m_shapeHendler, new CSaveInText(), new CImportFromText());
	m_userInterface = new CUserInterface(new CDragAndDropState(), m_window, m_shapeHendler);
}

CHendler* CHendler::m_instance = nullptr;

CHendler* CHendler::GetInstance(std::istream& input, std::ostream& output, sf::RenderWindow& window)
{
	if (m_instance == nullptr)
	{
		m_instance = new CHendler(input, output, window);
	}

	return m_instance;
}

void CHendler::ReadShapes() const
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

void CHendler::HandleEvent(sf::Event event)
{
	auto position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
	m_shapeHendler->SetCursorPosition(position);

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
		m_shapeHendler->CompletionOfMove();
		break;
	}
	case sf::Event::KeyPressed:
	{
		HandleKeyPressed(event);
		break;
	}
	}

	m_shapeHendler->Moving();
	Draw();
}

void CHendler::HandleMouseButtonPressed(sf::Event event) const
{
	if (typeid(*m_userInterface->GetState()) == typeid(CDragAndDropState))
	{
		m_shapeHendler->DragAndDrop(event);
	}
	else if (typeid(*m_userInterface->GetState()) == typeid(CFillShapeState))
	{
		m_shapeHendler->Accept(new CFillShapeVisitor(m_userInterface->GetCurrentColor()), event);
	}
	else if (typeid(*m_userInterface->GetState()) == typeid(CFillBorderState))
	{
		m_shapeHendler->Accept(new CFillBorderVisitor(m_userInterface->GetCurrentColor()), event);
	}
	else if (typeid(*m_userInterface->GetState()) == typeid(CWidthBorderState))
	{
		m_shapeHendler->Accept(new CWidthBorderVisitor(m_userInterface->GetCurrentWidth()), event);
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
}

void CHendler::HandleKeyPressed(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			m_shapeHendler->GroupShapes();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			m_shapeHendler->UngroupShapes();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			m_shapeHendler->UndoHistory();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SaveShapes();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			ImportShapes();
		}
	}
}

void CHendler::SaveShapes()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		m_fileHendler->m_saveIn = new CSaveInText();
		m_fileHendler->Save();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		m_fileHendler->m_saveIn = new CSaveInBinary();
		m_fileHendler->Save();
	}
}

void CHendler::ImportShapes()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		m_fileHendler->m_importFrom = new CImportFromText();
		m_fileHendler->Import();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		m_fileHendler->m_importFrom = new CImportFromBinary();
		m_fileHendler->Import();
	}
}

void CHendler::PrintInfoAboutShapes() const
{
	auto shapes = m_shapeHendler->GetShapes();
	for (const auto& shape : shapes)
	{
		m_output << shape->Tostring() << std::endl;
	}
}

void CHendler::Draw() const
{
	m_window.clear(clearWindow);

	DrawUserInterface();
	DrawShapes();

	m_window.display();
}

void CHendler::DrawShapes() const
{
	auto shapes = m_shapeHendler->GetShapes();
	for (const auto& shape : shapes)
	{
		shape->Draw(m_window);
	}
}

void CHendler::DrawUserInterface() const
{
	m_userInterface->Draw();
}