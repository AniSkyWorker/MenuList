#include "Element.h"

namespace GUI
{

	Element::Element()
	:is_selected(false)
	,is_active(false)
	{
	}

	Element::~Element()
	{
	}

	bool Element::isSelected() const
	{
		return is_selected;
	}

	void Element::select()
	{
		is_selected = true;
	}

	void Element::deselect()
	{
		is_selected = false;
	}

	bool Element::isActive() const
	{
		return is_active;
	}

	void Element::activate()
	{
		is_active = true;
	}

	void Element::deactivate()
	{
		is_active = false;
	}

}