#pragma once
#include <string>
#include "ICanvasDrawable.h"

class IShape: virtual public ICanvasDrawable
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
	virtual ~IShape() {};
	//выяснить для чего нужен виртуальный деструктор для базового класса +
	//сделать файл с фигурами, чтобы не писать каждый раз +
};