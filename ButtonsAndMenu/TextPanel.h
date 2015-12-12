#pragma once
#include "Element.h"

const sf::Vector2f PANEL_POSITION{ 150, 200 };
const sf::Vector2f PANEL_SIZE{ 300,30 };
const float OUTLINE_THIKNESS = 2.f;
const float CHARACTER_SIZE = 16.f;
const sf::Color NOT_ACTIVE_PANEL_COLOR(0, 0, 0, 150);
const std::string BASIC_PANEL_STRING = "Press Enter and input some text!";
namespace GUI
{
	struct TextPanel : public Element
	{
		typedef std::shared_ptr<TextPanel> ptr;

		TextPanel();

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();

		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent(const sf::Event& event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void setText(std::string str);

		sf::Font font;
		sf::Text text;
		std::string string;
		sf::RectangleShape shape;
		sf::Vector2f PANEL_POSITION { 150, 200 };

		
	};
}