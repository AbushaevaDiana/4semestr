#include "SaveInBinary.h"

void CSaveInBinary::Save(std::string fileName, std::vector<CShapeDecorator*> shapes)
{
	std::ostringstream strm;
	PrintShapeInfo(strm, shapes);

	std::ofstream output(fileName + ".bin", std::ios::out | std::ios::binary);
	output << strm.str().c_str();
}