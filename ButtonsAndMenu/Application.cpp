#include "Application.h"

Application::Application()
:window(sf::VideoMode(640, 480), "Menus", sf::Style::Close)
,menu()
{
}

void Application::run()
{
	while (window.isOpen())
	{
		processInput();
		update();
		render();
	}
}

void Application::processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		menu.handleEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Application::update()
{
	menu.update();
}

void Application::render()
{
	window.clear();
	menu.draw(window);
	window.display();
}
