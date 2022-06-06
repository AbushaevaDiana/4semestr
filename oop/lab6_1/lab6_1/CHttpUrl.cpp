#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex>

CHttpUrl::CHttpUrl(std::string const& url)
{
	std::regex urlRegex(R"(^(.+)://([^/:]+)(:?)([^/]*)(/?.*)$)");
	std::smatch match;

	if (!regex_search(url, match, urlRegex))
	{
		throw CUrlParsingError("invalid url");
	}
	
	std::string protocolString = match[1];
	std::string domain = match[2];
	std::string port = match[4].matched ? match[4].str() : "";
	std::string document = match[5].str();

	m_protocol = ConvertToValidProtocol(protocolString);
	if (domain.empty())
		throw CUrlParsingError("invalid domain");
	m_domain = domain;
	m_port = ConvertToValidPort(port, m_protocol);
	m_document = ConvertToValidDocument(document);
}

CHttpUrl::CHttpUrl(std::string const& domain,
	std::string const& document,
	Protocol protocol)
{
	if (domain.empty())
		throw CUrlParsingError("invalid domain");
	m_domain = domain;
	m_protocol = protocol;
	m_document = ConvertToValidDocument(document);
	std::string port = "";
	m_port = ConvertToValidPort(port, protocol);
	
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
{
	if (domain.empty())
		throw CUrlParsingError("invalid domain");
	m_domain = domain;
	m_protocol = protocol;
	m_document = ConvertToValidDocument(document);
	m_port = port;
}


Protocol ConvertToValidProtocol(std::string const& protocolString)
{
	if (protocolString == "http")
	{
		return Protocol::HTTP;
	}
	if (protocolString == "https")
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError("invalid protocol");
}

unsigned short ConvertToValidPort(const std::string& strPort, const Protocol& protocol)
{
	if (strPort.empty())
	{
		if (protocol == Protocol::HTTP)
		{
			return 80;
		}
		if (protocol == Protocol::HTTP)
		{
			return 443;
		}
	}

	int portNum;
	try
	{
		portNum = std::stoi(strPort);
	}
	catch (const std::exception& e)
	{
		throw CUrlParsingError("invalid port");
	}

	if (portNum <= 0 || portNum > 65535)
	{
		throw CUrlParsingError("invalid port");
	}

	return portNum;
}

std::string ConvertToValidDocument(std::string const& document)
{
	if (document.empty() || document[0] != '/')
	{
		return "/" + document;
	}
	return document;	
}

std::string CHttpUrl::GetURL() const
{
	std::string port;
	if (!((m_protocol == Protocol::HTTP && m_port == 80) || (m_protocol == Protocol::HTTPS && m_port == 443)))
	{
		port = ":" + std::to_string(m_port);
	}
	return GetProtocolLikeString() + "://" + m_domain + port + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::GetProtocolLikeString() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	if (m_protocol == Protocol::HTTPS)
	{
		return "https";
	}
}
