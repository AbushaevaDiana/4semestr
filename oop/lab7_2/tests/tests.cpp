#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab7_2/CMyStack.h"
#include "string.h"

TEST_CASE("CStack int")
{
	CMyStack<int> intStack;

	SECTION("empty stack ")
	{
		CHECK(intStack.IsEmpty());
		CHECK_THROWS(intStack.GetTopElement());
	}

	SECTION("push")
	{
		intStack.Push(2);
		CHECK(!intStack.IsEmpty());
		CHECK(intStack.GetTopElement() == 2);
		intStack.Push(5);
		intStack.Push(1);
        CHECK(intStack.GetTopElement() == 1);
	}
	
	SECTION("pop")
	{
		CHECK(intStack.IsEmpty());
		intStack.Push(2);
		intStack.Push(5);
		intStack.Push(3);
		CHECK(!intStack.IsEmpty());
		intStack.Pop();
		CHECK(!intStack.IsEmpty());
		CHECK(intStack.GetTopElement() == 5);
		intStack.Pop();
		intStack.Pop();
		CHECK_THROWS(intStack.GetTopElement());
		CHECK(intStack.IsEmpty());
	}

	SECTION("clear")
	{
		intStack.Push(2);
		intStack.Push(5);
		intStack.Push(3);
		CHECK(!intStack.IsEmpty());
		intStack.Clear();
		CHECK(intStack.IsEmpty());
	}

	SECTION("copy")
	{
		CMyStack<int> intStack2;
		intStack.Push(2);
		intStack.Push(5);
		intStack.Push(3);
		CHECK(intStack2.IsEmpty());
		intStack2 = intStack;
		CHECK(!intStack2.IsEmpty());
		CHECK(intStack.GetTopElement() == intStack.GetTopElement());
	}
}

TEST_CASE("CStack string")
{
	CMyStack<std::string> strStack;

	SECTION("empty stack")
	{
		CHECK(strStack.IsEmpty());
		CHECK_THROWS(strStack.GetTopElement());
	}

	SECTION("push")
	{
		strStack.Push("2");
		CHECK(!strStack.IsEmpty());
		CHECK(strStack.GetTopElement() == "2");
		strStack.Push("fff");
		strStack.Push("ddd");
		CHECK(strStack.GetTopElement() == "ddd");
	}

	SECTION("pop")
	{
		CHECK(strStack.IsEmpty());
		strStack.Push(" ");
		strStack.Push("dd");
		strStack.Push("dddd");
		CHECK(!strStack.IsEmpty());
		strStack.Pop();
		CHECK(!strStack.IsEmpty());
		CHECK(strStack.GetTopElement() == "dd");
		strStack.Pop();
		strStack.Pop();
		CHECK_THROWS(strStack.GetTopElement());
		CHECK(strStack.IsEmpty());
	}

	SECTION("clear")
	{
		strStack.Push("ggg");
		strStack.Push("dd");
		CHECK(!strStack.IsEmpty());
		strStack.Clear();
		CHECK(strStack.IsEmpty());
	}

	SECTION("copy")
	{
		CMyStack<std::string> strStack2;
		strStack.Push("f");
		strStack.Push("DVDV");
		strStack.Push("ff");
		CHECK(strStack2.IsEmpty());
		strStack2 = strStack;
		CHECK(!strStack2.IsEmpty());
		CHECK(strStack.GetTopElement() == strStack.GetTopElement());
	}
}


