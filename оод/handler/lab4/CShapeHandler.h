#pragma once
#include <iostream>
#include "CShapeDecorator.h"
#include "CShapeComposite.h"
#include "CircleCreator.h"
#include "TriangleCreator.h"
#include "RectangleCreator.h"

class CShapeHandler
{
public:
	void CreateCircle(std::istringstream& args);
	void CreateTriangle(std::istringstream& args);
	void CreateRectangle(std::istringstream& args);

	void SetCursorPosition(sf::Vector2f position);

	void Moving();
	void CompletionOfMove();

	void DragAndDrop(sf::Event event);
	void FillShape(sf::Event event, sf::Color color);
	void FillBorder(sf::Event event, sf::Color color);
	void SetWidth(sf::Event event, float width);

	std::vector<CShapeDecorator*> GetShapes();
	void AddShape(CShapeDecorator* shape);

	void HandleKeyPressed(sf::Event event);

private:
	void SelectingShape(sf::Event event);
	void SetSelectingShape(CShapeDecorator* shape);
	void ResetSelectingShape(CShapeDecorator* shape);
	void ClearSelectedShapes(CShapeDecorator* shape);

	void PreparingForMove(sf::Event event);

	void GroupShapes();
	void UngroupShapes();

	static std::vector<CShapeDecorator*> CopyShapes(std::vector<CShapeDecorator*> shapes);

	std::vector<CShapeDecorator*> m_shapes;
	std::vector<CShapeDecorator*> m_selectedShapes;

	sf::Vector2f m_cursorPosition;
	sf::Vector2f  m_cursorOffset;
	bool m_isMove;

};