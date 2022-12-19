#include "SaveIn.h"

void CSaveIn::PrintShapeInfo(std::ostream& output, std::vector<CShapeDecorator*> shapes) const
{
	for (const auto& shape : shapes)
	{
		if (typeid(*shape) == typeid(CCircle))
		{
			output << GetCircleInfo(static_cast<CCircle*>(shape));
		}
		else if (typeid(*shape) == typeid(CTriangle))
		{
			output << GetTriangleInfo(static_cast<CTriangle*>(shape));
		}
		else if (typeid(*shape) == typeid(CRectangle))
		{
			output << GetRectangleInfo(static_cast<CRectangle*>(shape));
		}
		else if (typeid(*shape) == typeid(CShapeComposite))
		{
			output << startComposite << std::endl;
			PrintShapeInfo(output, static_cast<CShapeComposite*>(shape)->GetShapes());
			output << endComposite << std::endl;
		}
	}
}

std::string CSaveIn::GetCircleInfo(CCircle* shape) const
{
	sf::Vector2f position = shape->GetPosition();
	float radius = shape->GetRadius();
	sf::Vector2f centerPoint = { position.x + radius, position.y + radius };
	float borderWidth = shape->GetOutlineThickness();
	sf::Color outlineColor = shape->GetOutlineColor();
	sf::Color fillColor = shape->GetFillColor();

	std::stringstream strm;

	strm << circleSaveStr << std::endl
		<< centerPoint.x << " " << centerPoint.y << " "
		<< radius << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}

std::string CSaveIn::GetTriangleInfo(CTriangle* shape) const
{
	sf::Vector2f vertex1 = shape->GetVertex1();
	sf::Vector2f vertex2 = shape->GetVertex2();
	sf::Vector2f vertex3 = shape->GetVertex3();

	sf::Vector2f position = shape->GetPosition();

	vertex1 = { vertex1.x + position.x, vertex1.y + position.y };
	vertex2 = { vertex2.x + position.x, vertex2.y + position.y };
	vertex3 = { vertex3.x + position.x, vertex3.y + position.y };

	float borderWidth = shape->GetOutlineThickness();
	sf::Color outlineColor = shape->GetOutlineColor();
	sf::Color fillColor = shape->GetFillColor();

	std::stringstream strm;

	strm << triangleSaveStr << std::endl
		<< vertex1.x << " " << vertex1.y << " "
		<< vertex2.x << " " << vertex2.y << " "
		<< vertex3.x << " " << vertex3.y << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}

std::string CSaveIn::GetRectangleInfo(CRectangle* shape) const
{
	sf::Vector2f position = shape->GetPosition();
	float width = shape->GetWidth();
	float height = shape->GetHeight();
	float borderWidth = shape->GetOutlineThickness();
	sf::Color outlineColor = shape->GetOutlineColor();
	sf::Color fillColor = shape->GetFillColor();

	std::stringstream strm;

	strm << rectangleSaveStr << std::endl
		<< position.x << " " << position.y << " "
		<< width << " " << height << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}