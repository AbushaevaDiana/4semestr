#pragma once
#include "ISpeakable.h"
#include <string>

/* Человек. Обладает именем и годом рождения.
может говорить (называет своё имя и год рождения) */
class Person: public ISpeakable
{
public:
	std::string Speak() const override;
private:
	int m_year;
	std::string m_name;
};