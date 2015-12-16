#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"


struct Application
{
	Application();
	void run();

	void processInput();
	void update();
	void render();

	sf::RenderWindow window;
	Menu menu;
};
