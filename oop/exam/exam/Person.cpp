#include "Person.h"

std::string Person::Speak() const
{
	std::string phrase = std::to_string(m_year);
	phrase += " " + m_name;
	return phrase;
}
