#include "ImportFromText.h"

IShapeMemento CImportFromText::Import(std::string fileName)
{
	std::ifstream input(fileName + ".txt");
	return IShapeMemento(ReadShapeInfo(input), {});
}