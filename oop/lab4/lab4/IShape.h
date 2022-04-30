#pragma once
#include <string>
#include "ICanvasDrawable.h"

class CPoint
{
public:
	double x = 0;
	double y = 0;
};

class IShape: virtual public ICanvasDrawable
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
	virtual ~IShape() {};
	//�������� ��� ���� ����� ����������� ���������� ��� �������� ������ +
	//������� ���� � ��������, ����� �� ������ ������ ��� +
};