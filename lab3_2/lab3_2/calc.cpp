#include "calc.h"

Calculator::Calculator()
{
}

bool Calculator::AddVar(const std::string& name)
{
	auto it = m_varsMap.find(name);
	if (it == m_varsMap.end())
	{
		m_varsMap.insert({ name, NAN });
		return true;
	}
	
	return false;
}

bool Calculator::LetVar(const std::string& name, double value)
{
	auto it = m_varsMap.find(name);
	if (it != m_varsMap.end())
	{
		m_varsMap[name] = value;
		return true;
	}
	return false;
}
