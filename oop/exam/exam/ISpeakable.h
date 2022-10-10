#pragma once
#include "ISpeakable.h"
#include <string>

/* Интерфейс объектов, умеющих говорить (Speak). */
class ISpeakable
{
	virtual std::string Speak() const = 0;
};