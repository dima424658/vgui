#include <VGUI_Menu.h>

#include <VGUI_RaisedBorder.h>
#include <VGUI_StackLayout.h>
#include <VGUI_Panel.h>

vgui::Menu::Menu(int x, int y, int wide, int tall)
	: vgui::Panel::Panel(x, y, wide, tall)
{
	auto border = new vgui::RaisedBorder;
	auto layout = new vgui::StackLayout{ 1, true };

	setBorder(border);
	setLayout(layout);
}

vgui::Menu::Menu(int wide, int tall)
	: vgui::Panel::Panel(0, 0, wide, tall)
{
	auto border = new vgui::RaisedBorder;
	auto layout = new vgui::StackLayout{ 1, true };

	setBorder(border);
	setLayout(layout);
}

void vgui::Menu::addMenuItem(vgui::Panel* panel)
{
	addChild(panel);
}

