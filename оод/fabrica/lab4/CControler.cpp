#include "CControler.h"
#include <string>
#include <sstream>
#include <iterator> 
#include <algorithm>
#include "CircleCreator.h"
#include "RectangleCreator.h"
#include "TriangleCreator.h"

std::string const invalidTriangleParameters = "Invalid count of Triangle parameters \n";
std::string const errorTriangle = " - Invalid Triangle data\n";
std::string const invalidCircleParameters = "Invalid count of circle parameters \n";
std::string const invalidRadius = "Invalid radius\n";
std::string const errorCircle = " - Invalid Circle data\n";
std::string const errorRectangle = " - Invalid Rectangle data\n";
std::string const emptyList = "\nEmpty shape list, add at least one shape\n";
std::string const invalidRectangleParameters = "Invalid count of rectangle parameters \n";
std::string const invalidHeigthWidth = "Invalid heigth or width\n";
std::string const unknown = "\nUnknown shape / command\n";




bool CControler::AddTriangle(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 8)
	{
		m_inputStringVector.clear();
		std::cerr << invalidTriangleParameters;
		return false;
	}
	try
	{
		TriangleCreator creator;
		auto shape = creator.CreateShape(m_inputStringVector);
		m_shapesList.push_back(std::move(shape));

	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << e.what() << errorCircle;
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
		std::cerr << invalidCircleParameters;
		return false;
	}
	if (stof(m_inputStringVector[2]) <= 0)
	{
		m_inputStringVector.clear();
		std::cerr << invalidRadius;
		return false;
	}
	try
	{
		CircleCreator creator;
		auto shape = creator.CreateShape(m_inputStringVector);
		m_shapesList.push_back(std::move(shape));
	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << e.what() << errorCircle;
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
		std::cerr << invalidRectangleParameters;
		return false;
	}
	if ((stof(m_inputStringVector[2]) <= 0) || (stof(m_inputStringVector[3]) <= 0))
	{
		m_inputStringVector.clear();
		std::cerr << invalidHeigthWidth;
		return false;
	}
	try
	{
		RectangleCreator creator;
		auto shape = creator.CreateShape(m_inputStringVector);
		m_shapesList.push_back(std::move(shape));
	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << e.what() << errorRectangle;
		return false;
	}

	return true;
}
;

bool CControler::PrintInfo()
{
	if (m_shapesList.empty())
	{
		m_output << emptyList;
		return false;
	}

	m_output << "\nShapes:\n";

	for (auto i = 0; i < m_shapesList.size(); i++)
	{
		auto& shape = m_shapesList[i];
		m_output << shape->ToString() << std::endl;
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
		m_output << unknown;
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
