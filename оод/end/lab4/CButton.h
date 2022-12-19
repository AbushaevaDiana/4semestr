#pragma once
#include "const.h"
#include "ICommand.h"

class CButton
{
public:
	CButton(sf::Vector2f position, sf::Vector2f size, std::string text = "",
		sf::Color outlineColor = buttonOutlineColor, sf::Color fillColor = buttonFillColor)
	{
		m_rect.setPosition(position);
		m_rect.setSize(size);
		m_rect.setOutlineThickness(buttonOutlineThickness);
		m_rect.setOutlineColor(outlineColor);
		m_rect.setFillColor(fillColor);

		if (m_font.loadFromFile(buttonFontFile))
		{
			m_text.setFont(m_font);
			m_text.setString(text);
			m_text.setFillColor(buttonTextColor);
			m_text.setCharacterSize(buttonTextSize);

			auto rect = m_text.getGlobalBounds();
			sf::Vector2f offset;
			offset.x = (size.x - rect.width) / 2;
			offset.y = (size.y - rect.height) / 2;

			m_text.setPosition({ position.x + offset.x, position.y + offset.y });
		}
	};

	void Draw(sf::RenderWindow& window) const;
	void SetCommand(ICommand* command);
	bool IsPointInButton(sf::Vector2f point) const;
	void PressButton() const;

private:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	sf::Font m_font;

	ICommand* m_command;
};