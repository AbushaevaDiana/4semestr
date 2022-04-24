#pragma once
#include "CShape.h"
#include "CLineSegment.h"
#include "CTriangel.h"
#include <iostream>
#include <map>
#include <functional>
#include <vector>

class CControler
{
public:
	CControler(std::istream& input, std::ostream& output);
	bool Command();
private:

	bool PrintInfo();
	bool PrintMaxArea();
	bool PrintMinPerimeter();

	std::vector<std::string> m_inputStringVector;
	std::vector<std::shared_ptr<IShape>> m_shapesList;

	bool GetInputStringVector(std::istream& input);
	bool AddLineSegment(std::istream& input);
	bool AddTriangel(std::istream& input);
	// other figures

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};