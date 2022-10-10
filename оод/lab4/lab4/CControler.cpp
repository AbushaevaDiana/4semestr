#include "CControler.h"
#include <string>
#include <sstream>
#include <iterator> 
#include <algorithm>

bool CControler::AddTriangle(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 8)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid count of Triangle parameters \n";
		return false;
	}
	try
	{
		sf::Vector2f vertex1 = { stof(m_inputStringVector[0]), stof(m_inputStringVector[1]) };
		sf::Vector2f vertex2 = { stof(m_inputStringVector[2]), stof(m_inputStringVector[3]) };
		sf::Vector2f vertex3 = { stof(m_inputStringVector[4]), stof(m_inputStringVector[5]) };
		uint32_t outlineColor = stoul(m_inputStringVector[6], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[7], nullptr, 16);
		m_inputStringVector.clear();

		auto triangle = std::make_unique<sf::ConvexShape>();

		triangle->setPointCount(3);
		triangle->setPoint(0, vertex1);
		triangle->setPoint(1, vertex2);
		triangle->setPoint(2, vertex3);
		triangle->setOutlineThickness(5);
		triangle->setOutlineColor(GetColor(outlineColor));
		triangle->setFillColor(GetColor(fillColor));

		auto shape = std::make_unique<CTriangle>(std::move(triangle), vertex1, vertex2, vertex3, GetColor(fillColor), GetColor(outlineColor));
		m_shapesList.push_back(std::move(shape));

	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid Triangle data(" << e.what() << ")\n";
		return false;
	}

	return true;
}
bool CControler::AddCircle(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 5)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid count of circle parameters \n";
		return false;
	}
	if (stof(m_inputStringVector[2]) <= 0)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid radius\n";
		return false;
	}
	try
	{
		sf::Vector2f center = { stof(m_inputStringVector[0]), stof(m_inputStringVector[1]) };
		float radius = stof(m_inputStringVector[2]);
		uint32_t outlineColor = stoul(m_inputStringVector[3], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[4], nullptr, 16);
		m_inputStringVector.clear();

		auto circle = std::make_unique<sf::CircleShape>();

		circle->setPosition({100,  100});
		circle->setRadius(80);
		circle->setOutlineThickness(5);
		circle->setOutlineColor(GetColor(outlineColor));
		circle->setFillColor(GetColor(fillColor));

		auto shape = std::make_unique<CCircle>(std::move(circle), center, radius, GetColor(fillColor), GetColor(outlineColor));
		m_shapesList.push_back(std::move(shape));
	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid circle data(" << e.what() << ")\n";
		return false;
	}

	return true;
}
bool CControler::AddRectangle(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 6)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid count of rectangle parameters \n";
		return false;
	}
	if ((stof(m_inputStringVector[2]) <= 0) || (stof(m_inputStringVector[3]) <= 0))
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid heigth or width\n";
		return false;
	}
	try
	{
		sf::Vector2f leftTop = { stof(m_inputStringVector[0]), stof(m_inputStringVector[1]) };
		float heigth = stof(m_inputStringVector[2]);
		float width = stof(m_inputStringVector[3]);
		uint32_t outlineColor = stoul(m_inputStringVector[4], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[5], nullptr, 16);
		m_inputStringVector.clear();

		auto rectangle = std::make_unique<sf::RectangleShape>();

		rectangle->setSize({ width, heigth });
		rectangle->setPosition(leftTop);
		rectangle->setOutlineThickness(5);
		rectangle->setOutlineColor(GetColor(outlineColor));
		rectangle->setFillColor(GetColor(fillColor));

		auto shape = std::make_unique<CRectangle>(std::move(rectangle), leftTop, heigth, width, GetColor(fillColor), GetColor(outlineColor));
		m_shapesList.push_back(std::move(shape));
	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid rectangle data(" << e.what() << ")\n";
		return false;
	}

	return true;
}
;

bool CControler::PrintInfo()
{
	if (m_shapesList.empty())
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}

	m_output << "\nShapes:\n";

	for (auto i = 0; i < m_shapesList.size(); i++)
	{
		auto& shape = m_shapesList[i];
		m_output << shape->ToString() << "\n";
	}
	return true;
};

bool CControler::GetInputStringVector(std::istream& input)
{
	std::istream_iterator<std::string> floatStrmEnd;
	copy(std::istream_iterator<std::string>(input), floatStrmEnd, inserter(m_inputStringVector, m_inputStringVector.begin()));
	return true;
}

bool CControler::Command()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	if (!m_input.eof())
	{
		m_output << "\nUnknown shape / command\n";
	}

	return false;
}

bool CControler::Draw()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), "Shapes");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);

		for (auto i = 0; i < m_shapesList.size(); i++)
		{
			auto& shape = m_shapesList[i];
			shape->Draw(window);
		}

		window.display();
	}

	return true;
}

CControler::CControler(std::istream& input, std::ostream& output)
	: m_input(input),
	m_output(output),
	m_shapesList(),
	m_actionMap({
		  { "Info", [this](std::istream& strm) {
			   return PrintInfo();
		   } },
		  { "AddTriangle", [this](std::istream& strm) {
			   return AddTriangle(strm);
		   } },
		  { "AddCircle", [this](std::istream& strm) {
			   return AddCircle(strm);
		   } },
		  { "AddRectangle", [this](std::istream& strm) {
			   return AddRectangle(strm);
		   } },
		  { "Draw", [this](std::istream& strm) {
			   return Draw();
		   } },
		})
{
};

sf::Color GetColor(uint32_t color)
{
	uint8_t blue = color % 256;
	uint8_t green = (color / 256) % 256;
	uint8_t red = ((color / 256) / 256) % 256;

	return sf::Color(red, green, blue);
}