#pragma once
#include "SaveIn.h"

class CSaveInBinary : public CSaveIn
{
public:
	void Save(std::string fileName, std::vector<CShapeDecorator*> shapes) override;
};