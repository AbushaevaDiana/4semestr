#pragma once
#include "ISpeakable.h"
#include <string>

/* ��������� ��������, ������� �������� (Speak). */
class ISpeakable
{
	virtual std::string Speak() const = 0;
};