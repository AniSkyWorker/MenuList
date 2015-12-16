#include "CheckBox.h"

namespace GUI
{
	CheckBox::CheckBox()
	:callback()
	,sprite()
	{
		font.loadFromFile("sansation.ttf");

		text.setFont(font);
		text.setString("");
		text.setCharacterSize(16);
		sprite.setPosition(BOX_POSITION);
		normal_texture.loadFromFile("buttonnormal.png");
		selected_texture.loadFromFile("buttonpressed.png");
		pressed_texture.loadFromFile("buttonselected1.png");
		sprite.setTexture(normal_texture);
		sprite.setTextureRect(TEXTURE_RECT);
		sf::FloatRect bounds = sprite.getLocalBounds();
		text.setPosition(bounds.width / 2.f, bounds.height / 2.f);
	}

	void CheckBox::setCallback(Callback callback)
	{
		callback = std::move(callback);
	}

	void CheckBox::setText(const std::string& str)
	{
		text.setString(str);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	}

	bool CheckBox::isSelectable() const
	{
		return true;
	}

	void CheckBox::select()
	{
		Element::select();

		sprite.setTexture(selected_texture);
	}

	void CheckBox::deselect()
	{
		Element::deselect();

		sprite.setTexture(normal_texture);
	}

	void CheckBox::activate()
	{
		Element::activate();
		sprite.setTexture(pressed_texture);
		if (callback)
			callback();
	}

	void CheckBox::deactivate()
	{
		Element::deactivate();
		if (isSelected())
			sprite.setTexture(selected_texture);
		else
			sprite.setTexture(normal_texture);
	}

	void CheckBox::handleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			deactivate();
	}

	void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(sprite, states);
		target.draw(text, states);
	}
}