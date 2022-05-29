#include "CCanvas.h"

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::DrawLine(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor) const
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(static_cast<float>(startPoint.x), static_cast<float>(startPoint.y))),
		sf::Vertex(sf::Vector2f(static_cast<float>(endPoint.x), static_cast<float>(endPoint.y)))
	};

	line[0].color = GetColor(outlineColor);
	line[1].color = GetColor(outlineColor);

	m_window.draw(line, 1, sf::Lines);
}

void CCanvas::FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor) const
{
	sf::ConvexShape polygon;
	polygon.setPointCount(points.size());
	polygon.setFillColor(GetColor(fillColor));

	for (size_t i = 0; i < points.size(); i++)
	{
		polygon.setPoint(i, sf::Vector2f(static_cast<float>(points[i].x), static_cast<float>(points[i].y)));
	}

	m_window.draw(polygon);
}

void CCanvas::DrawCircle(const CPoint& centerPoint, double radius, uint32_t outlineColor, uint32_t fillColor) const
{
	sf::CircleShape circle(static_cast<float>(radius));
	circle.setPosition(static_cast<float>(centerPoint.x), static_cast<float>(centerPoint.y));

	circle.setOutlineColor(GetColor(outlineColor));
	circle.setFillColor(GetColor(fillColor));

	circle.setOutlineThickness(1);

	m_window.draw(circle);
}

/*void CCanvas::FillCircle(const CPoint& centerPoint, double radius, uint32_t fillColor)
{
	sf::CircleShape circle(static_cast<float>(radius));

	circle.setPosition(static_cast<float>(centerPoint.x), static_cast<float>(centerPoint.y));
	circle.setOutlineColor(GetColor(outlineColor));

	m_window.draw(circle);
}*/

sf::Color GetColor(uint32_t color)
{
	uint8_t blue = color % 256;
	uint8_t green = (color / 256) % 256;
	uint8_t red = ((color / 256) / 256) % 256;

	return sf::Color(red, green, blue);
}
