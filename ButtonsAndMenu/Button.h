#pragma once
#include "Element.h"

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace GUI
{
	struct Button : public Element
	{
		typedef std::shared_ptr<Button> ptr;
		typedef std::function<void()> Callback;

		Button();

		void setCallback(Callback callback);
		void setText(const std::string& text);

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();

		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent(const sf::Event& event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


		Callback callback;
		sf::Font font;
		sf::Texture	normal_texture;
		sf::Texture	selected_texture;
		sf::Texture	pressed_texture;
		sf::Sprite sprite;
		sf::Text text;
	};
}

