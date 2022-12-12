#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab4/CControler.h"
#include "../lab4/CShape.h"
#include "../lab4/CSolidShape.h"
#include "../lab4/CLineSegment.h"
#include "../lab4/CTriangle.h"
#include "../lab4/CCircle.h"
#include "../lab4/CRectangle.h"
#include "../lab4/ICanvasDrawable.h"
#include "../lab4/ICanvas.h"
#include "../lab4/CCanvas.h"


TEST_CASE("LineSegment")
{
	SECTION("Object creation - LineSegment")
	{
		CPoint start = { 0.0, 0.0 };
		CPoint end = { 1.1, 0.0 };
		uint32_t lineColor = 16711680;
		CLineSegment lineSegment(start, end, lineColor);

		std::string str = ">Line:\n  startPoint(0, 0)\n  endPoint(1.1, 0)\n  perimeter: 1.1\n  area: 0\n  line color: ff0000\n";

		REQUIRE(lineSegment.GetArea() == 0.0);
		REQUIRE(lineSegment.GetPerimeter() == 1.1);
		REQUIRE(lineSegment.ToString() == str);
		REQUIRE(lineSegment.GetStartPoint().x == start.x);
		REQUIRE(lineSegment.GetStartPoint().y == start.y);
		REQUIRE(lineSegment.GetEndPoint().x == end.x);
		REQUIRE(lineSegment.GetEndPoint().y == end.y);
		REQUIRE(lineSegment.GetOutlineColor() == lineColor);
	}

}

TEST_CASE("Triangle")
{
	SECTION("Object creation - Triangle")
	{
		CPoint vertex1 = { 0.0, 0.0 };
		CPoint vertex2 = { 3.0, 0.0 };
		CPoint vertex3 = { 0.0, 4.0 };
		uint32_t lineColor = 16711680;
		uint32_t fillColor = 16711680;
		double area = 6;
		double perimeter = 12;
		CTriangle Triangle(vertex1, vertex2, vertex3, lineColor, fillColor);

		std::string str = ">Triangle:\n  vertex1(0, 0)\n  vertex2(3, 0)\n  vertex3(0, 4)\n  perimeter: 12\n  area: 6\n  fill color: ff0000\n  line color: ff0000\n";

		REQUIRE(Triangle.GetArea() == area);
		REQUIRE(Triangle.GetPerimeter() == perimeter);
		REQUIRE(Triangle.ToString() == str);
		REQUIRE(Triangle.GetVertex1().x == vertex1.x);
		REQUIRE(Triangle.GetVertex1().y == vertex1.y);
		REQUIRE(Triangle.GetVertex2().x == vertex2.x);
		REQUIRE(Triangle.GetVertex2().y == vertex2.y);
		REQUIRE(Triangle.GetVertex3().x == vertex3.x);
		REQUIRE(Triangle.GetVertex3().y == vertex3.y);
		REQUIRE(Triangle.GetOutlineColor() == lineColor);
		REQUIRE(Triangle.GetFillColor() == fillColor);
	}

}

TEST_CASE("Circle")
{
	SECTION("Object creation - Circle")
	{
		CPoint center = { 1.0, 1.0 };
		double radius = 1;
		uint32_t lineColor = 16711680;
		uint32_t fillColor = 16711680;
		double area = pow(radius, 2) * M_PI;
		double perimeter = M_PI * 2 * radius;
		CCircle circle(center, radius, lineColor, fillColor);

		std::string str = ">Circle:\n  center(1, 1)\n  radius: 1\n  perimeter: 6.28319\n  area: 3.14159\n  fill color: ff0000\n  line color: ff0000\n";

		REQUIRE(circle.GetArea() == area);
		REQUIRE(circle.GetPerimeter() == perimeter);
		REQUIRE(circle.ToString() == str);
		REQUIRE(circle.GetCenter().x == center.x);
		REQUIRE(circle.GetCenter().y == center.y);
		REQUIRE(circle.GetRadius() == radius);
		REQUIRE(circle.GetOutlineColor() == lineColor);
		REQUIRE(circle.GetFillColor() == fillColor);
	}

}

TEST_CASE("Rectangle")
{
	SECTION("Object creation - Rectangle")
	{
		CPoint leftTop = { 0.0, 0.0 };
		CPoint rigthBottom = { 2.0, 2.0 };
		double heigth = 2;
		double width = 2;
		uint32_t lineColor = 16711680;
		uint32_t fillColor = 16711680;
		double area = 4;
		double perimeter = 8;
		CRectangle rectangle(leftTop, heigth, width, lineColor, fillColor);

		std::string str = ">Rectangle:\n  leftTop(0, 0)\n  heigth: 2\n  width: 2\n  perimeter: 8\n  area: 4\n  fill color: ff0000\n  line color: ff0000\n";

		REQUIRE(rectangle.GetArea() == area);
		REQUIRE(rectangle.GetPerimeter() == perimeter);
		REQUIRE(rectangle.ToString() == str);
		REQUIRE(rectangle.GetLeftTop().x == leftTop.x);
		REQUIRE(rectangle.GetLeftTop().y == leftTop.y);
		REQUIRE(rectangle.GetRightBottom().x == rigthBottom.x);
		REQUIRE(rectangle.GetRightBottom().y == rigthBottom.y);
		REQUIRE(rectangle.GetWidth() == width);
		REQUIRE(rectangle.GetHeigth() == heigth);
		REQUIRE(rectangle.GetOutlineColor() == lineColor);
		REQUIRE(rectangle.GetFillColor() == fillColor);
	}

}

TEST_CASE("Controler")
{
	SECTION("Info with empty vectorOfShapes")
	{
		std::string inStr = "Info\n";
		std::string outStr = "\nEmpty shape list, add at least one shape\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CControler controler(input, output);

		controler.Command();

		REQUIRE(outStr == output.str());
	}
	SECTION("Add line and print Info")
	{
		std::string inStr = "AddLine 0.0 0.0 1.1 0.0 ff0000\nInfo\n";
		std::string outStr = "\nShapes:\n>Line:\n  startPoint(0, 0)\n  endPoint(1.1, 0)\n  perimeter: 1.1\n  area: 0\n  line color: ff0000\n\n";

		std::istringstream input(inStr);
		std::ostringstream output;

		CControler controler(input, output);

		controler.Command();
		controler.Command();

		REQUIRE(outStr == output.str());
	}
	SECTION("Add shapes and eof")
	{
		std::string inStr = "AddLine 0.0 0.0 1.1 0.0 ff0000\nAddRectangle 0.0 0.0 1.0 2.0 ff0000 ff0000\nAddTriangle 0.0 0.0 3.0 0.0 0.0 4.0 ff0000 ff0000\n^Z";
		std::string outStr = "\n Max Area: \n>Triangle:\n  vertex1(0, 0)\n  vertex2(3, 0)\n  vertex3(0, 4)\n  perimeter: 12\n  area: 6\n  fill color: ff0000\n  line color: ff0000\n";
		outStr += "\n\n Min Perimeter: \n>Line:\n  startPoint(0, 0)\n  endPoint(1.1, 0)\n  perimeter: 1.1\n  area: 0\n  line color: ff0000\n\n";
		std::istringstream input(inStr);
		std::ostringstream output;

		CControler controler(input, output);

		for (auto i = 0; i < 4; i++)
		{
			controler.Command();
		}
		
		REQUIRE(outStr == output.str());
	}
	SECTION("Add invalid shapes")
	{
		std::string inStr = "addLine 0.0 0.0 1.1 0.0 ff0000\nAddRectangle 0.0 0.0 -1.0 2.0 ff0000 ff0000\n";
		std::string outStr = "\nUnknown shape / command\n";
		std::istringstream input(inStr);
		std::ostringstream output;

		CControler controler(input, output);

		for (auto i = 0; i < 2; i++)
		{
			controler.Command();
		}

		REQUIRE(outStr == output.str());
	}

}