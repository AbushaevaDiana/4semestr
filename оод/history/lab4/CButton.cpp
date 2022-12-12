#include "CButton.h"

void CButton::Draw(sf::RenderWindow& window) const
{
	window.draw(m_rect);
	window.draw(m_text);
}

void CButton::SetCommand(ICommand* command)
{
	m_command = command;
}

bool CButton::IsPointInButton(sf::Vector2f point) const
{
	return m_rect.getGlobalBounds().contains(point);
}

void CButton::PressButton() const
{
	m_command->Execute();
}