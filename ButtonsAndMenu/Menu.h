#pragma once

#include "Container.h"
#include <SFML\Graphics.hpp>
#include <functional>

const sf::Vector2f BUTTON_POSITION{ 200,200 };
const float RANGE_BETWEEN_BUTTONS = 50.f;

struct Menu
{
	typedef std::function<void()> buttonAction;
	enum Button
	{
		Play,
		Exit,
	};
	Menu();

	virtual void draw(sf::RenderWindow& window);
	void update();
	void handleEvent(const sf::Event& event);
	void addButton(std::string str, buttonAction action);

	GUI::Container GUI_ñontainer;
	
	sf::Texture	background_texture;
	sf::Sprite sprite;
};
 
