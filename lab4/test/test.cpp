#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab4/CCone.h"
#include "../lab4/CBody.h"
#include "../lab4/CCylinder.h"
#include "../lab4/CParallelepiped.h"
#include "../lab4/CSphere.h"
#include "../lab4/CCompound.h"
#include "../lab4/BodiesContainer.h"

const double ERROR_EXPSILON = 0.0001;

SCENARIO("test sphere body")
{
	CSphere sphere(10, 2);

	REQUIRE(abs(sphere.GetVolume() - 4186.6667) < ERROR_EXPSILON);
	REQUIRE(sphere.GetDensity() == 2);
	REQUIRE(abs(sphere.GetMass() - 8373.3333) < ERROR_EXPSILON);
}

SCENARIO("test cylinder body")
{
	CCylinder cylinder(10, 5, 2);

	REQUIRE(abs(cylinder.GetVolume() - 1570.0) < ERROR_EXPSILON);
	REQUIRE(cylinder.GetDensity() == 2);
	REQUIRE(abs(cylinder.GetMass() - 3140.0) < ERROR_EXPSILON);
}

SCENARIO("test parallelepiped body")
{
	CParallelepiped parallelepiped(10, 5, 7, 2);

	REQUIRE(abs(parallelepiped.GetVolume() - 350.0) < ERROR_EXPSILON);
	REQUIRE(parallelepiped.GetDensity() == 2);
	REQUIRE(abs(parallelepiped.GetMass() - 700.0) < ERROR_EXPSILON);
}

SCENARIO("test cone body")
{
	CCone cone(10, 5, 2);

	REQUIRE(abs(cone.GetVolume() - 523.3333) < ERROR_EXPSILON);
	REQUIRE(cone.GetDensity() == 2);
	REQUIRE(abs(cone.GetMass() - 1046.6666) < ERROR_EXPSILON);
}

SCENARIO("test compound body")
{
	std::shared_ptr<CCompound> compound = std::make_shared<CCompound>();
	WHEN("add child solid body")
	{
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(10, 5, 2);
		compound.get()->AddChildBody(cone);
		REQUIRE(compound.get()->GetChildBodies().size() == 1);
		REQUIRE(abs(compound.get()->GetVolume() - 523.3333) < ERROR_EXPSILON);
		REQUIRE(compound.get()->GetDensity() == 2.0);
		REQUIRE((compound.get()->GetMass() - 1046.6666) < ERROR_EXPSILON);
	}
	WHEN("add some child bodies")
	{
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(10, 5, 2);
		std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(10, 5, 2);
		compound.get()->AddChildBody(cone);
		compound.get()->AddChildBody(cylinder);
		REQUIRE(compound.get()->GetChildBodies().size() == 2);
		REQUIRE(abs(compound.get()->GetVolume() - 2093.3333) < ERROR_EXPSILON);
		REQUIRE(compound.get()->GetDensity() == 2);
		REQUIRE(abs(compound.get()->GetMass() - 4186.6666) < ERROR_EXPSILON);
	}
	WHEN("add compound body with solid body")
	{
		std::shared_ptr<CCompound> addedCompound = std::make_shared<CCompound>();
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(10, 5, 2);
		addedCompound->AddChildBody(cone);
		compound.get()->AddChildBody(addedCompound);
		REQUIRE(addedCompound->GetChildBodies().size() == 1);
		REQUIRE(compound.get()->GetChildBodies().size() == 1);
		REQUIRE(addedCompound.get()->GetVolume() == compound.get()->GetVolume());
		REQUIRE(addedCompound.get()->GetMass() == compound.get()->GetMass());
		REQUIRE(addedCompound.get()->GetDensity() == compound.get()->GetDensity());
	}
	WHEN("check recursive append child")
	{
		std::shared_ptr<CCompound> addedCompound = std::make_shared<CCompound>();
		compound.get()->AddChildBody(addedCompound);
		REQUIRE_THROWS(addedCompound.get()->AddChildBody(compound));
	}
	WHEN("check apppend exist body")
	{
		std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(10, 50);
		compound.get()->AddChildBody(sphere);
		REQUIRE_THROWS(compound.get()->AddChildBody(sphere));
	}
}

SCENARIO("check recursive append compound body")
{
	std::shared_ptr<CCompound> compoundA = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> compoundB = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> compoundC = std::make_shared<CCompound>();

	REQUIRE(compoundA->AddChildBody(compoundB));
	REQUIRE(compoundB->AddChildBody(compoundC));
	REQUIRE_THROWS(compoundC->AddChildBody(compoundA));
}

SCENARIO("test bodies container")
{
	WHEN("add child solid body sphere")
	{
		std::istringstream in("add solid sphere A\n10\n2\ninfo");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
		REQUIRE(container.HandleCommand());
	}
	WHEN("add child solid body cone")
	{
		std::istringstream in("add solid cone A\n10\n10\n10");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
	}
	WHEN("add child solid body cylinder")
	{
		std::istringstream in("add solid cylinder A\n10\n10\n10");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
	}
	WHEN("add child solid body parallelepiped")
	{
		std::istringstream in("add solid parallelepiped A\n10\n10\n10\n10");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
	}
	WHEN("test add exist body")
	{
		std::istringstream in("add solid sphere A\n10\n2\nadd solid cone A");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "Radius: Density: Error: Bodies with name \"A\" already exist\n");
	}
	WHEN("test add solid body with unknown type")
	{
		std::istringstream in("add solid sphere1 A");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "Error: unknown body type sphere1\n");
	}
	WHEN("test append body to compound body")
	{
		std::istringstream in("add solid sphere A\n10\n2\nadd compound B\nappend A to B");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
		REQUIRE(container.HandleCommand());
		REQUIRE(container.HandleCommand());
	}
	WHEN("test append not exist body to compound body")
	{
		std::istringstream in("add compound B\nappend A to B");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "Error: body with name \"A\" does not exist\n");
	}
	WHEN("test append body to not compound body")
	{
		std::istringstream in("add solid sphere A\n10\n2\nadd solid sphere B\n10\n2\nappend A to B");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(container.HandleCommand());
		REQUIRE(container.HandleCommand());
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "Radius: Density: Radius: Density: Error: body with name \"B\" is not compound\n");
	}
	WHEN("get info with empty container")
	{
		std::istringstream in("info");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "no one body was added\n");
	}
	WHEN("input unknown command")
	{
		std::istringstream in("get");
		std::ostringstream out("");
		BodiesContainer container(in, out);
		REQUIRE(!container.HandleCommand());
		REQUIRE(out.str() == "Error: unknown command\n");
	}
}