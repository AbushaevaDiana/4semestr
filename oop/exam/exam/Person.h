#pragma once
#include "ISpeakable.h"
#include <string>

/* �������. �������� ������ � ����� ��������.
����� �������� (�������� ��� ��� � ��� ��������) */
class Person: public ISpeakable
{
public:
	std::string Speak() const override;
private:
	int m_year;
	std::string m_name;
};