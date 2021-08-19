#include <VGUI_MenuItem.h>

vgui::MenuItem::MenuItem(const char *text)
	: vgui::Button(text, 0, 0),
	_subMenu{nullptr}
{
setButtonBorderEnabled(false);
}

vgui::MenuItem::MenuItem(const char *text, vgui::Menu *subMenu)
	: vgui::Button(text, 0, 0),
	_subMenu{ subMenu }
{
	setButtonBorderEnabled(false);
}

