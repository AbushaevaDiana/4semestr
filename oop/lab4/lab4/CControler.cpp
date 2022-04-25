#include "CControler.h"
#include <string>
#include <sstream>
#include <iterator> 
#include <algorithm>

bool CControler::AddLineSegment(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 5)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid count of line parameters \n";
		return false;
	}
	try 
	{
		CPoint startPoint = { stod(m_inputStringVector[0]), stod(m_inputStringVector[1]) };
		CPoint endPoint = { stod(m_inputStringVector[2]), stod(m_inputStringVector[3]) };
		//nullptr отсутствие указателя, в другой ситуации указатель на позицию, которую обрабатывать после выполнение функции
		uint32_t outlineColor = stoul(m_inputStringVector[4], nullptr, 16);
		m_inputStringVector.clear();
		std::shared_ptr<IShape> line = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
		m_shapesList.push_back(line);
	}
	catch(const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid line data(" << e.what() << ")\n";
		return false;
	}

	return true;
}
bool CControler::AddTriangel(std::istream& input)
{
	GetInputStringVector(input);
	if (m_inputStringVector.size() != 8)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid count of triangel parameters \n";
		return false;
	}
	try
	{
		CPoint vertex1 = { stod(m_inputStringVector[0]), stod(m_inputStringVector[1]) };
		CPoint vertex2 = { stod(m_inputStringVector[2]), stod(m_inputStringVector[3]) };
		CPoint vertex3 = { stod(m_inputStringVector[4]), stod(m_inputStringVector[5]) };
		//nullptr отсутствие указателя, в другой ситуации указатель на позицию, которую обрабатывать после выполнение функции
		uint32_t outlineColor = stoul(m_inputStringVector[6], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[7], nullptr, 16);
		m_inputStringVector.clear();
		std::shared_ptr<IShape> triangel = std::make_shared<CTriangel>(vertex1, vertex2, vertex3, outlineColor, fillColor);
		m_shapesList.push_back(triangel);
	}
	catch (const std::exception& e)
	{
		m_inputStringVector.clear();
		std::cerr << "Invalid triangel data(" << e.what() << ")\n";
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
	try
	{
		CPoint center = { stod(m_inputStringVector[0]), stod(m_inputStringVector[1]) };
		double radius = stod(m_inputStringVector[2]);
		//nullptr отсутствие указателя, в другой ситуации указатель на позицию, которую обрабатывать после выполнение функции
		uint32_t outlineColor = stoul(m_inputStringVector[3], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[4], nullptr, 16);
		m_inputStringVector.clear();
		std::shared_ptr<IShape> circle = std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
		m_shapesList.push_back(circle);
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
	try
	{
		CPoint leftTop = { stod(m_inputStringVector[0]), stod(m_inputStringVector[1]) };
		double heigth = stod(m_inputStringVector[2]);
		double width = stod(m_inputStringVector[3]);
		//nullptr отсутствие указателя, в другой ситуации указатель на позицию, которую обрабатывать после выполнение функции
		uint32_t outlineColor = stoul(m_inputStringVector[4], nullptr, 16);
		uint32_t fillColor = stoul(m_inputStringVector[5], nullptr, 16);
		m_inputStringVector.clear();
		std::shared_ptr<IShape> rectangle = std::make_shared<CRectangle>(leftTop, heigth, width, outlineColor, fillColor);
		m_shapesList.push_back(rectangle);
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
		auto shape = m_shapesList[i];
		m_output << shape->ToString() << "\n";
	}
	return true;
};

bool compForArea(std::shared_ptr<IShape> shape1, std::shared_ptr<IShape> shape2)
{
	if (shape1->GetArea() > shape2->GetArea())
	{
		return true;
	}
	return false;
}

bool CControler::PrintMaxArea()
{
	if (m_shapesList.empty())
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}

	std::vector<std::shared_ptr<IShape>> shapesList = m_shapesList;
	sort(shapesList.begin(), shapesList.end(), compForArea);
	m_output << "\n Max Area: \n" << shapesList[0]->ToString() << "\n";;

	return true;
};

bool compForPerimeter(std::shared_ptr<IShape> shape1, std::shared_ptr<IShape> shape2)
{
	if (shape1->GetPerimeter() < shape2->GetPerimeter())
	{
		return true;
	}
	return false;
}

bool CControler::PrintMinPerimeter()
{
	if (m_shapesList.empty())
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}
	std::vector<std::shared_ptr<IShape>> shapesList = m_shapesList;
	sort(shapesList.begin(), shapesList.end(), compForPerimeter);
	m_output << "\n Min Perimeter: \n" << shapesList[0]->ToString() << "\n";

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
	else
	{
		PrintMaxArea();
		PrintMinPerimeter();
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
		  { "AddTriangel", [this](std::istream& strm) {
			   return AddTriangel(strm);
		   } },
		  { "AddCircle", [this](std::istream& strm) {
			   return AddCircle(strm);
		   } },
		  { "AddRectangle", [this](std::istream& strm) {
			   return AddRectangle(strm);
		   } },
		})
{
};