#pragma once
#include "ImportFrom.h"

class CImportFromBinary : public CImportFrom
{
public:
	IShapeMemento Import(std::string fileName) override;
};