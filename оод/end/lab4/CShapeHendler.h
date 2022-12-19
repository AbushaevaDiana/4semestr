#pragma once
#include <iostream>
#include <stack>
#include "CShapeDecorator.h"
#include "CShapeComposite.h"
#include "CircleCreator.h"
#include "TriangleCreator.h"
#include "RectangleCreator.h"
#include "IVisitor.h"
#include "IShapeMemento.h"

class CShapeHendler
{
public:
	void CreateCircle(std::istringstream& args);
	void CreateTriangle(std::istringstream& args);
	void CreateRectangle(std::istringstream& args);

	void SetCursorPosition(sf::Vector2f position);

	void Moving();
	void CompletionOfMove();

	void DragAndDrop(sf::Event event);
	void Accept(IVisitor* visitor, sf::Event event);

	std::vector<CShapeDecorator*> GetShapes();
	void AddShape(CShapeDecorator* shape);

	void HandleKeyPressed(sf::Event event);

	IShapeMemento GetState();
	void RestoreState(const IShapeMemento& shapeMemento);
	void SaveHistory();
	void UndoHistory();

	void GroupShapes();
	void UngroupShapes();

private:
	void SelectingShape(sf::Event event);
	void SetSelectingShape(CShapeDecorator* shape);
	void ResetSelectingShape(CShapeDecorator* shape);
	void ClearSelectedShapes(CShapeDecorator* shape);

	void PreparingForMove(sf::Event event);

	static std::vector<CShapeDecorator*> CopyShapes(std::vector<CShapeDecorator*> shapes);

	std::vector<CShapeDecorator*> m_shapes;
	std::vector<CShapeDecorator*> m_selectedShapes;

	sf::Vector2f m_cursorPosition;
	sf::Vector2f  m_cursorOffset;
	bool m_isMove;

	std::stack<IShapeMemento> m_history = std::stack<IShapeMemento>{};
};