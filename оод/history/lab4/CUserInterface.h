#pragma once
#include <SFML/Graphics.hpp>
#include "IState.h"
#include "CButton.h"
#include "CShapeHandler.h"

class IState;

class CUserInterface
{
public:
	CUserInterface(IState* state, sf::RenderWindow& window, CShapeHandler* shapeHandler)
		: m_state(state)
		, m_window(window)
		, m_shapeHandler(shapeHandler)
	{
		CreateButtons();
	}

	void DragAndDrop();
	void FillShape();
	void FillBorder();
	void WidthBorder();

	IState* GetState() const;
	void SetState(IState* state);

	void Draw() const;

	std::vector<CButton*> GetButtons() const;

	sf::Color GetCurrentColor() const;
	void SetCurrentColor(sf::Color color);
	float GetCurrentWidth() const;
	void SetCurrentWidth(float width);

	CShapeHandler* m_shapeHandler;

private:
	void CreateButtons();
	void CreateButton(CButton* button, ICommand* command);
	sf::Color GetColor(std::string colorStr);

	sf::RenderWindow& m_window;
	std::vector<CButton*> m_buttons;
	IState* m_state;
	sf::Color m_currentColor = defaultColor;
	float m_currentWidth = defaultWidth;
};