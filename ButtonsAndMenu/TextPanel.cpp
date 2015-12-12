#include "TextPanel.h"

namespace GUI
{
	TextPanel::TextPanel()
	{
		font.loadFromFile("sansation.ttf");
		text.setFont(font);

		shape.setPosition(PANEL_POSITION);
		shape.setSize(PANEL_SIZE);

		shape.setFillColor(NOT_ACTIVE_PANEL_COLOR);
		shape.setOutlineColor(sf::Color::Red);
		shape.setOutlineThickness(OUTLINE_THIKNESS);

		text.setPosition(shape.getPosition());
		text.setCharacterSize(CHARACTER_SIZE);
		text.setColor(sf::Color::White);
	}

	void TextPanel::setText (std::string str)
	{
		text.setString(str);
	}


	bool TextPanel::isSelectable() const
	{
		return true;
	}

	void TextPanel::select()
	{
		Element::select();
		setText(BASIC_PANEL_STRING);
		shape.setOutlineColor(sf::Color::Green);
	}

	void TextPanel::deselect()
	{
		Element::deselect();
		shape.setOutlineColor(sf::Color::Red);
		setText("");
	}

	void TextPanel::activate()
	{
		Element::activate();
		setText("");
		shape.setFillColor(sf::Color::Black);
	}

	void TextPanel::deactivate()
	{
		Element::deactivate();
		shape.setFillColor(NOT_ACTIVE_PANEL_COLOR);
		setText(BASIC_PANEL_STRING);
	}

	void TextPanel::handleEvent(const sf::Event& event)
	{
		
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
		{
			deactivate();
			string.clear();
		}
		else if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == 8 && !string.empty())
			{
				string.pop_back();
			}
			else if (event.text.unicode >= 32 && event.text.unicode <= 126
				&& text.getGlobalBounds().width < shape.getSize().x - 3)
			{
				string.push_back(static_cast<char>(event.text.unicode));
			}
			setText(string);
		}
	}

	void TextPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(shape, states);
		if (isActive() || isSelected())
		{
			target.draw(text, states);
		}
	}
}

