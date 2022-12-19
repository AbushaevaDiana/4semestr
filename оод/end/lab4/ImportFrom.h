#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "const.h"
#include "CShapeBuilderCreator.h"
#include "CCircleBuilder.h"
#include "CTriangleBuilder.h"
#include "CRectangleBuilder.h"
#include "CCompositeBuilder.h"
#include "IShapeMemento.h"

class CImportFrom
{
public:
	virtual IShapeMemento Import(std::string fileName) = 0;

protected:
	std::vector<CShapeDecorator*> ReadShapeInfo(std::istream& input);
};
