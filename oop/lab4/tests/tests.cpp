#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab4/CControler.h"
#include "../lab4/CShape.h"
#include "../lab4/CSolidShape.h"
#include "../lab4/CLineSegment.h"
#include "../lab4/CTriangel.h"

TEST_CASE("LineSegment")
{
	SECTION("Object creation")
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
	}

}

TEST_CASE("Contriler")
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

}