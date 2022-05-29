#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas: virtual public ICanvas
	//разобраться с виртуальным наследованием уметь обьяснить
{
public:
	//RenderTarget вместо RenderWindow
	CCanvas(sf::RenderWindow& window);
	//прочитать про собственный деструктор, зачем писать дефолтный деструктор
	~CCanvas() = default;
	void DrawLine(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor) const override;
	void FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor) const override;
	void DrawCircle(const CPoint& centerPoint, double radius, uint32_t outlineColor, uint32_t fillColor) const override;
	//void FillCircle(const CPoint& centerPoint, double radius, uint32_t fillColor) override;
	//сделать по заданию, УБРАТЬ КОМЕНТАРИИ С ЗАЛИВКИ
	//при изменение размера окна фигуры не должны терять вид(растягиваться, плющиться)
private:
	sf::RenderWindow& m_window;
};

sf::Color GetColor(uint32_t color);
