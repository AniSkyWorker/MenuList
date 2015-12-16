#pragma once

#include "Element.h"
#include <vector>
#include <string>
#include <memory>
#include <functional>

const sf::Vector2f BOX_POSITION{ 150,130 };
const sf::IntRect TEXTURE_RECT{ 75,0,50,50 };

namespace GUI
{
	struct CheckBox : public Element
	{
		typedef std::shared_ptr<CheckBox> ptr;
		typedef std::function<void()> Callback;

		CheckBox();
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