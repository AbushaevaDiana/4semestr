#include "CUserInterface.h"
#include "CCreateCircleCommand.h"
#include "CCreateTriangleCommand.h"
#include "CCreateRectangleCommand.h"
#include "CDragAndDropCommand.h"
#include "CFillShapeCommand.h"
#include "CFillBorderCommand.h"
#include "CWidthBorderCommand.h"
#include "CSetCurrentColorCommand.h"
#include "CSetCurrentWidthCommand.h"

void CUserInterface::DragAndDrop()
{
	m_state->DragAndDrop(this);
}

void CUserInterface::FillShape()
{
	m_state->FillShape(this);
}

void CUserInterface::FillBorder()
{
	m_state->FillBorder(this);
}

void CUserInterface::WidthBorder()
{
	m_state->WidthBorder(this);
}

IState* CUserInterface::GetState() const
{
	return m_state;
}

void CUserInterface::SetState(IState* state)
{
	m_state = state;
}

void CUserInterface::Draw() const
{
	for (const auto& button : m_buttons)
	{
		button->Draw(m_window);
	}
}

std::vector<CButton*> CUserInterface::GetButtons() const
{
	return m_buttons;
}

sf::Color CUserInterface::GetCurrentColor() const
{
	return m_currentColor;
}

void CUserInterface::SetCurrentColor(sf::Color color)
{
	m_currentColor = color;
}

float CUserInterface::GetCurrentWidth() const
{
	return m_currentWidth;
}

void CUserInterface::SetCurrentWidth(float width)
{
	m_currentWidth = width;
}

void CUserInterface::CreateButtons()
{
	CreateButton(new CButton({ 19, 10 }, { 154, 48 }, "Create\ncircle"), new CCreateCircleCommand(this));
	CreateButton(new CButton({ 187, 10 }, { 154, 48 }, "Create\ntriangle"), new CCreateTriangleCommand(this));
	CreateButton(new CButton({ 355, 10 }, { 154, 48 }, "Create\nrectangle"), new CCreateRectangleCommand(this));

	CreateButton(new CButton({ 523, 10 }, { 154, 48 }, "Drag\nand\nDrop"), new CDragAndDropCommand(this));
	CreateButton(new CButton({ 691, 10 }, { 154, 48 }, "Fill\nshape"), new CFillShapeCommand(this));
	CreateButton(new CButton({ 859, 10 }, { 154, 48 }, "Fill\nBorder"), new CFillBorderCommand(this));
	CreateButton(new CButton({ 1027, 10 }, { 154, 48 }, "Width\nBorder"), new CWidthBorderCommand(this));

	CreateButton(new CButton({ 19, 68 }, { 60, 36 }, "Red", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_RED_FILL_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_RED_FILL_COLOR)));
	CreateButton(new CButton({ 93, 68 }, { 60, 36 }, "Red", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_RED_OUTLINE_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_RED_OUTLINE_COLOR)));

	CreateButton(new CButton({ 167, 68 }, { 60, 36 }, "Yellow", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_YELLOW_FILL_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_YELLOW_FILL_COLOR)));
	CreateButton(new CButton({ 241, 68 }, { 60, 36 }, "Yellow", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_YELLOW_OUTLINE_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_YELLOW_OUTLINE_COLOR)));

	CreateButton(new CButton({ 315, 68 }, { 60, 36 }, "Green", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_GREEN_FILL_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_GREEN_FILL_COLOR)));
	CreateButton(new CButton({ 389, 68 }, { 60, 36 }, "Green", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_GREEN_OUTLINE_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_GREEN_OUTLINE_COLOR)));

	CreateButton(new CButton({ 463, 68 }, { 60, 36 }, "Blue", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_BLUE_FILL_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_BLUE_FILL_COLOR)));
	CreateButton(new CButton({ 537, 68 }, { 60, 36 }, "Blue", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_BLUE_OUTLINE_COLOR)),
		new CSetCurrentColorCommand(this, GetColor(DEFAULT_BLUE_OUTLINE_COLOR)));

	CreateButton(new CButton({ 603, 68 }, { 282, 36 }, "Solid", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_GREY_FILL_COLOR)),
		new CSetCurrentWidthCommand(this, DEFAULT_WIDTH));
	CreateButton(new CButton({ 899, 68 }, { 282, 36 }, "Double", BUTTON_OUTLINE_COLOR, GetColor(DEFAULT_GREY_FILL_COLOR)),
		new CSetCurrentWidthCommand(this, DEFAULT_DOUBLE_WIDTH));
}

void CUserInterface::CreateButton(CButton* button, ICommand* command)
{
	button->SetCommand(command);
	m_buttons.push_back(button);
}

sf::Color CUserInterface::GetColor(std::string colorStr)
{
	uint32_t color = std::stoul(colorStr, nullptr, 16);

	uint32_t blue = color % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t red = ((color / 256) / 256) % 256;

	return sf::Color(red, green, blue);
}