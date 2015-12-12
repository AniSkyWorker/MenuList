#include "Menu.h"

#include "Button.h"
#include "TextPanel.h"

Menu::Menu()
:GUI_ñontainer()
{
	background_texture.loadFromFile("backgroundtexture.jpg");
	sprite.setTexture(background_texture);

	auto text = std::make_shared<GUI::TextPanel>();
	GUI_ñontainer.pack(text);

	addButton("Play", []() {});
	addButton("Text", []() {});
}
void Menu::addButton(std::string str, buttonAction action)
{
	auto new_button = std::make_shared<GUI::Button>();
	new_button->setPosition(BUTTON_POSITION.x, BUTTON_POSITION.y + GUI_ñontainer.children.size()* RANGE_BETWEEN_BUTTONS);
	new_button->setText(str);
	new_button->setCallback(action);
	GUI_ñontainer.pack(new_button);
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(GUI_ñontainer);
}

void Menu::update()
{
}

void Menu::handleEvent(const sf::Event& event)
{
	GUI_ñontainer.handleEvent(event);
}

