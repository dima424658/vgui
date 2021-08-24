#include <VGUI_ToggleButton.h>

#include "handlers/FooDefaultToggleButtonController.h"

vgui::ToggleButton::ToggleButton(const char* text, int x, int y, int wide, int tall)
	: vgui::Button{ text, x, y, wide, tall }
{
	auto controller = new handlers::FooDefaultToggleButtonController{this};
	setButtonController(controller);
}

vgui::ToggleButton::ToggleButton(const char* text, int x, int y)
	: vgui::Button{ text, x, y }
{
	auto controller = new handlers::FooDefaultToggleButtonController{this};
	setButtonController(controller);
}