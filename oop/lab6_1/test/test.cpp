#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../lab6_1/CHttpUrl.h"
#include "../lab6_1/CUrlParsingError.h"

TEST_CASE("correct")
{
	SECTION("Parse sample URL from string")
	{
		std::string str("http://www.example.com/docs/document1.html?page=30&lang=en#title");

		REQUIRE_NOTHROW(CHttpUrl(str));
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
	}

	SECTION("Parse sample URL with 3 parameters")
	{
		std::string str("http://www.example.com/docs/document1.html?page=30&lang=en#title");

		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/docs/document1.html?page=30&lang=en#title", Protocol::HTTP));
		CHttpUrl url("www.example.com", "/docs/document1.html?page=30&lang=en#title", Protocol::HTTP);
		REQUIRE(url.GetURL() == str);
	}

	SECTION("Parse sample URL with 4 parameters")
	{
		std::string str("http://www.example.com:8080/path/");
	
		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/path/", Protocol::HTTP, 8080));
		CHttpUrl url("www.example.com", "/path/", Protocol::HTTP, 8080);
		REQUIRE(url.GetURL() == str);
	}

	SECTION("Parse sample URL with 4 parameters, document without /")
	{
		std::string str("http://www.example.com:8080/path/");

		REQUIRE_NOTHROW(CHttpUrl("www.example.com", "/path/", Protocol::HTTP, 8080));
		CHttpUrl url("www.example.com", "path/", Protocol::HTTP, 8080);
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 8080);
		REQUIRE(url.GetDocument() == "/path/");
		REQUIRE(url.GetURL() == str);
	}

	SECTION("Parse URL with port '1'")
	{
		std::string str("https://www.example.com:1/path/");
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 1);
		REQUIRE(url.GetDocument() == "/path/");
	}

	SECTION("Parse URL with port '65535'")
	{
		std::string str("https://www.example.com:65535/path/");
		CHttpUrl url(str);
		REQUIRE(url.GetURL() == str);
		REQUIRE(url.GetProtocol() == Protocol::HTTPS);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 65535);
		REQUIRE(url.GetDocument() == "/path/");
	}

	SECTION("Parse URL with empty document'")
	{
		std::string urlStr("http://www.example.com");
		CHttpUrl url(urlStr);
		REQUIRE(url.GetURL() == urlStr+"/");
		REQUIRE(url.GetProtocol() == Protocol::HTTP);
		REQUIRE(url.GetDomain() == "www.example.com");
		REQUIRE(url.GetPort() == 80);
		REQUIRE(url.GetDocument() == "/");
	}

}

TEST_CASE("incorrect")
{
	SECTION("Parse empty string")
	{
		std::string str("");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid url");
	}

	SECTION("Parse URL with port 0")
	{
		std::string str("http://www.example.com:0/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
	}

	SECTION("Parse URL with port 65536")
	{
		std::string str("http://www.example.com:65536/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
	}

	SECTION("Parse URL with port 75536")
	{
		std::string str("http://www.example.com:75536/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid port");
	}
	SECTION("Parse URL without domain")
	{
		std::string str("http://:0/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid url");
	}
	SECTION("Parse URL with wrong protocol")
	{
		std::string str("ttp://www.example.com:6/example");
		REQUIRE_THROWS_WITH(CHttpUrl(str), "invalid protocol");
	}
}