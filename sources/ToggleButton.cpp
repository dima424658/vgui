#include <VGUI_ToggleButton.h>

#include <VGUI_ButtonController.h>

vgui::ToggleButton::ToggleButton(const char* text, int x, int y, int wide, int tall)
	: vgui::Button{ text, x, y, wide, tall }
{
	vgui::ButtonController* controller; // eax

	controller = (vgui::ButtonController*)operator new(0xCu);
	controller->_vptr_ButtonController = (int (**)(...))off_49688; // FooDefaultToggleButtonController::addSignals
	controller[1]._vptr_ButtonController = (int (**)(...)) & off_496C4; // FooDefaultToggleButtonController::cursorMoved
	controller[2]._vptr_ButtonController = (int (**)(...))this;

	setButtonController(controller);
}

vgui::ToggleButton::ToggleButton(const char* text, int x, int y)
	: vgui::Button{ text, x, y }
{
	vgui::ButtonController* controller; // eax

	controller = (vgui::ButtonController*)operator new(0xCu);
	controller->_vptr_ButtonController = (int (**)(...))off_49688;
	controller[1]._vptr_ButtonController = (int (**)(...)) & off_496C4;
	controller[2]._vptr_ButtonController = (int (**)(...))this;

	setButtonController(controller);
}

/*
void __cdecl FooDefaultToggleButtonController::addSignals(vgui::Button* button)
{
(*(void(__cdecl**)(vgui::Button*, vgui::InputSignal*))(*(_DWORD*)button->baseclass_0 + 112))(
	button,
	&this->vgui::InputSignal);
}

//----- (0003D5F0) --------------------------------------------------------
void __cdecl `non-virtual thunk to'`anonymous namespace'::FooDefaultToggleButtonController::cursorMoved(_anonymous_namespace_::FooDefaultToggleButtonController * this, int a2, int a3, vgui::Panel * a4)
{
	`anonymous namespace'::FooDefaultToggleButtonController::cursorMoved(
		(`anonymous namespace'::FooDefaultToggleButtonController *const)((char *)this - 4),
			a2,
			a3,
			a4);
}
*/