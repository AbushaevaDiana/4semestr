#pragma once
#include <iostream>
#include <sstream>
#include <functional>
#include "const.h"
#include "CShapeDecorator.h"
#include "CShapeComposite.h"
#include "CircleCreator.h"
#include "TriangleCreator.h"
#include "RectangleCreator.h"

class CControler
{
public:
	CControler(std::istream& input, std::ostream& output, sf::RenderWindow& window);

	void ReadShapes() const;
	void DrawShapes() const;
	void HandleEvent(sf::Event event);
	void PrintInfoAboutShapes() const;

private:
	void CreateCircle(std::istream& args);
	void CreateTriangle(std::istream& args);
	void CreateRectangle(std::istream& args);

	void HandleMouseButtonPressed(sf::Event event);
	void AddSelectingShape(CShapeDecorator* shape);
	void ResetSelectingShape(CShapeDecorator* shape);
	void ClearSelectedShapes(CShapeDecorator* shape);

	void PreparingForMove(CShapeDecorator* shape);
	void Moving() const;

	void HandleKeyPressed(sf::Event event);
	void GroupShapes();
	void UngroupShapes();


	using Handler = std::function<void(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	const ActionMap m_actionMap;

	std::istream& m_input;
	std::ostream& m_output;
	std::vector<CShapeDecorator*> m_shapes;
	std::vector<CShapeDecorator*> m_selectedShapes;

	sf::RenderWindow& m_window;
	sf::Vector2f m_cursorPosition;
	sf::Vector2f m_cursorOffset;
	bool m_isMove = false;
};