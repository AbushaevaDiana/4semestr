#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas: virtual public ICanvas
	//����������� � ����������� ������������� ����� ���������
{
public:
	//RenderTarget ������ RenderWindow
	CCanvas(sf::RenderWindow& window);
	//��������� ��� ����������� ����������, ����� ������ ��������� ����������
	~CCanvas() = default;
	void DrawLine(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor) const override;
	void FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor) const override;
	void DrawCircle(const CPoint& centerPoint, double radius, uint32_t outlineColor, uint32_t fillColor) const override;
	//void FillCircle(const CPoint& centerPoint, double radius, uint32_t fillColor) override;
	//������� �� �������, ������ ���������� � �������
	//��� ��������� ������� ���� ������ �� ������ ������ ���(�������������, ���������)
private:
	sf::RenderWindow& m_window;
};

sf::Color GetColor(uint32_t color);
