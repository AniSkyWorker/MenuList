#include "Button.h"

namespace GUI
{

	Button::Button()
	:callback()
	,sprite()
	{
		font.loadFromFile("sansation.ttf");
		
		text.setFont(font);
		text.setString("");
		text.setCharacterSize(16);
		normal_texture.loadFromFile("buttonnormal.png");
		selected_texture.loadFromFile("buttonpressed.png");
		pressed_texture.loadFromFile("buttonselected.png");
		sprite.setTexture(normal_texture);

		sf::FloatRect bounds = sprite.getLocalBounds();
		text.setPosition(bounds.width / 2.f, bounds.height / 2.f);
	}

	void Button::setCallback(Callback callback)
	{
		callback = std::move(callback);
	}

	void Button::setText(const std::string& str)
	{
		text.setString(str);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	}


	bool Button::isSelectable() const
	{
		return true;
	}

	void Button::select()
	{
		Element::select();

		sprite.setTexture(selected_texture);
	}

	void Button::deselect()
	{
		Element::deselect();

		sprite.setTexture(normal_texture);
	}

	void Button::activate()
	{
		Element::activate();
		
		sprite.setTexture(pressed_texture);

		if (callback)
			callback();
			
	}

	void Button::deactivate()
	{
		Element::deactivate();

		if (isSelected())
			sprite.setTexture(selected_texture);
		else
			sprite.setTexture(normal_texture);
	}

	void Button::handleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			deactivate();
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(sprite, states);
		target.draw(text, states);
	}
}



