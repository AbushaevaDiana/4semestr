#pragma once
#include "CShape.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
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
	//bool Draw();

	std::vector<std::string> m_inputStringVector;
	std::vector<std::shared_ptr<IShape>> m_shapesList;

	bool GetInputStringVector(std::istream& input);
	bool AddLineSegment(std::istream& input);
	bool AddTriangle(std::istream& input);
	bool AddCircle(std::istream& input);
	bool AddRectangle(std::istream& input);

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};