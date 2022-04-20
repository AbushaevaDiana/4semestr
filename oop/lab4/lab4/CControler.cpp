#include "CControler.h"
#include <string>
#include <sstream>
#include <iterator> 
#include <algorithm>

//check
bool CControler::AddLineSegment(std::istream& input)
{
	GetInputStringVector(input);

	CPoint startPoint = { stod(m_inputStringVector[0]), stod(m_inputStringVector[1]) };
	CPoint endPoint = { stod(m_inputStringVector[2]), stod(m_inputStringVector[3]) };
	//check
	uint32_t outlineColor = stoul(m_inputStringVector[4], nullptr, 16);
	m_inputStringVector.clear();
	std::shared_ptr<IShape> line = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapesList.push_back(line);
	return true;
};

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
		auto shape = m_shapesList[i];
		m_output << shape->ToSting() << "\n";
	}
	return true;
};

//not done
bool CControler::PrintMaxArea()
{
	if (m_shapesList.empty())
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}

	m_output << "\n Max Area =";

	return true;
};

//not done
bool CControler::PrintMinPerimeter()
{
	if (m_shapesList.empty())
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}

	m_output << "\n Min Perimeter = ";

	return true;
};

bool CControler::GetInputStringVector(std::istream& input)
{
	std::istream_iterator<std::string> doubleStrmEnd;
	copy(std::istream_iterator<std::string>(input), doubleStrmEnd, inserter(m_inputStringVector, m_inputStringVector.begin()));
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

CControler::CControler(std::istream& input, std::ostream& output)
	: m_input(input),
	m_output(output),
	m_shapesList(),
    m_actionMap({
		  { "Info", [this](std::istream& strm) {
			   return PrintInfo();
		   } },
		  { "MaxArea", [this](std::istream& strm) {
			   return PrintMaxArea();
		   } },
		  { "MinPerimeter", [this](std::istream& strm) {
			   return PrintMinPerimeter();
		   } },
		  { "AddLine", [this](std::istream& strm) {
			   return AddLineSegment(strm);
		   } },
		})
{
};