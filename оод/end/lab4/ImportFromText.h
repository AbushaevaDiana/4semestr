#pragma once
#include "ImportFrom.h"

class CImportFromText : public CImportFrom
{
public:
	IShapeMemento Import(std::string fileName) override;
};