#include "ImportFrom.h"

std::vector<CShapeDecorator*> CImportFrom::ReadShapeInfo(std::istream& input)
{
	std::string str, substr, type;

	CShapeBuilderCreator shapesCreator = CShapeBuilderCreator();
	std::vector<CShapeDecorator*> shapes;
	std::vector<unsigned int> args;

	while (std::getline(input, type))
	{
		if (type == startComposite)
		{
			shapesCreator.SetBuilder(new CCompositeBuilder(ReadShapeInfo(input)));
		}
		else if (type == endComposite)
		{
			return shapes;
		}
		else
		{
			std::getline(input, str);
			std::stringstream stream(str);
			while (stream >> substr)
			{
				args.push_back(std::stoul(substr));
			}

			if (type == circleSaveStr)
			{
				shapesCreator.SetBuilder(new CCircleBuilder(args));
			}
			if (type == triangleSaveStr)
			{
				shapesCreator.SetBuilder(new CTriangleBuilder(args));
			}
			if (type == rectangleSaveStr)
			{
				shapesCreator.SetBuilder(new CRectangleBuilder(args));
			}
		}

		args.clear();
		shapes.push_back(shapesCreator.CreateShape());
	}

	return shapes;
}