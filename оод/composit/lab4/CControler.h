#pragma once
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include "CShapeDecorator.h"
#include "IShapeCreator.h"
#include "IShapeComposite.h"

const int WINDOW_WIDTH = 1100;
const int WINDOW_HEIGTH = 900;

class CControler
{
public:
	CControler(std::istream& input, std::ostream& output);
	bool Command();
private:

	bool PrintInfo();
	bool Draw();

	std::vector<std::string> m_inputStringVector;
	std::vector<std::unique_ptr<CShapeComposite>> m_shapesList;

	bool GetInputStringVector(std::istream& input);
	bool AddTriangle(std::istream& input);
	bool AddCircle(std::istream& input);
	bool AddRectangle(std::istream& input);

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};

