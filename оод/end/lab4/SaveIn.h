#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CShapeComposite.h"

class CSaveIn
{
public:
	virtual void Save(std::string fileName, std::vector<CShapeDecorator*> shapes) = 0;

protected:
	void PrintShapeInfo(std::ostream& output, std::vector<CShapeDecorator*> sahpes) const;

private:
	std::string GetCircleInfo(CCircle* shape) const;
	std::string GetTriangleInfo(CTriangle* shape) const;
	std::string GetRectangleInfo(CRectangle* shape) const;
};