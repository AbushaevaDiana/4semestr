#include "ImportFromBinary.h"

IShapeMemento CImportFromBinary::Import(std::string fileName)
{
	std::fstream input(fileName + ".bin", std::ios::out | std::ios::binary | std::ios::in);
	std::string result;

	char ch[1];
	while (input.read(ch, 1))
	{
		result += ch[0];
	}

	std::stringstream strm(result);
	return IShapeMemento(ReadShapeInfo(strm), {});
}