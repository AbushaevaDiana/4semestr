#include "SaveInText.h"

void CSaveInText::Save(std::string fileName, std::vector<CShapeDecorator*> shapes)
{
	std::ofstream output(fileName + ".txt");
	PrintShapeInfo(output, shapes);
}