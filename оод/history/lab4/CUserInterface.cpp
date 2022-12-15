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
	CreateButton(new CButton({ 19, 60 }, { 154, 48 }, "Create\ntriangle"), new CCreateTriangleCommand(this));
	CreateButton(new CButton({ 19, 110 }, { 154, 48 }, "Create\nrectangle"), new CCreateRectangleCommand(this));

	CreateButton(new CButton({ 965, 10 }, { 154, 48 }, "Drag\nand\nDrop"), new CDragAndDropCommand(this));
	CreateButton(new CButton({ 178, 10 }, { 154, 48 }, "Fill\nshape"), new CFillShapeCommand(this));
	CreateButton(new CButton({ 327, 10 }, { 154, 48 }, "Fill\nBorder"), new CFillBorderCommand(this));
	CreateButton(new CButton({ 678, 10 }, { 154, 48 }, "Width\nBorder"), new CWidthBorderCommand(this));

	CreateButton(new CButton({ 178, 68 }, { 120, 36 }, "Ligth Yellow", buttonOutlineColor, GetColor(ligthYellowColor)),
		new CSetCurrentColorCommand(this, GetColor(ligthYellowColor)));
	CreateButton(new CButton({ 178, 107 }, { 120, 36 }, "Yellow", buttonOutlineColor, GetColor(yellowColor)),
		new CSetCurrentColorCommand(this, GetColor(yellowColor)));

	CreateButton(new CButton({ 303, 68 }, { 120, 36 }, "Ligth Green", buttonOutlineColor, GetColor(ligthGreenColor)),
		new CSetCurrentColorCommand(this, GetColor(ligthGreenColor)));
	CreateButton(new CButton({ 303, 107 }, { 120, 36 }, "Green", buttonOutlineColor, GetColor(greenColor)),
		new CSetCurrentColorCommand(this, GetColor(greenColor)));

	CreateButton(new CButton({ 428, 68 }, { 120, 36 }, "Ligth Blue", buttonOutlineColor, GetColor(ligthBlueColor)),
		new CSetCurrentColorCommand(this, GetColor(ligthBlueColor)));
	CreateButton(new CButton({ 428, 107 }, { 120, 36 }, "Blue", buttonOutlineColor, GetColor(blueColor)),
		new CSetCurrentColorCommand(this, GetColor(blueColor)));

	CreateButton(new CButton({ 553, 68 }, { 120, 36 }, "Ligth Red", buttonOutlineColor, GetColor(ligthRedColor)),
		new CSetCurrentColorCommand(this, GetColor(ligthRedColor)));
	CreateButton(new CButton({ 553, 107 }, { 120, 36 }, "Red", buttonOutlineColor, GetColor(redColor)),
		new CSetCurrentColorCommand(this, GetColor(redColor)));

	CreateButton(new CButton({ 678, 68 }, { 282, 36 }, "Solid", buttonOutlineColor, GetColor(ligthGreyColor)),
		new CSetCurrentWidthCommand(this, defaultWidth));
	CreateButton(new CButton({ 678, 107 }, { 282, 36 }, "Double", buttonOutlineColor, GetColor(ligthGreyColor)),
		new CSetCurrentWidthCommand(this, doubleWidth));
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