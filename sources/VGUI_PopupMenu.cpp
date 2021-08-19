#include <VGUI_PopupMenu.h>

#include <VGUI_SurfaceBase.h>

vgui::PopupMenu::PopupMenu(int x, int y, int wide, int tall)
	: vgui::Menu{ x, y, wide, tall }
{
}

vgui::PopupMenu::PopupMenu(int wide, int tall)
	: vgui::Menu{ wide, tall }
{
}

void vgui::PopupMenu::showModal(vgui::Panel* panel)
{
	panel->getSurfaceBase()->createPopup(this);
}