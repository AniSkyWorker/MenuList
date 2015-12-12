#pragma once

#include "Element.h"

#include <vector>
#include <memory>

namespace GUI
{
	struct Container : public Element
	{
		typedef std::shared_ptr<Container> ptr;

		Container();

		void pack(Element::ptr component);

		virtual bool isSelectable() const;
		virtual void handleEvent(const sf::Event& event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		bool hasSelection() const;
		void select(std::size_t index);
		void selectNext();
		void selectPrevious();

		std::vector<Element::ptr> children;
		int	selected_child;
	};
}

