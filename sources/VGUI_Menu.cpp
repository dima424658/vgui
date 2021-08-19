#include <VGUI_Menu.h>

void vgui::Menu::addMenuItem(vgui::Menu *const this, vgui::Panel *panel)
{
  (*((void (**)(void))this->_vptr_Panel + 17))();
}

void vgui::Menu::Menu(vgui::Menu *const this, int x, int y, int wide, int tall)
{
  vgui::RaisedBorder *border; // esi
  vgui::StackLayout *v6; // esi

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Menu + 2);
  border = (vgui::RaisedBorder *)operator new(0x38u);
  vgui::RaisedBorder::RaisedBorder(border);
  vgui::Panel::setBorder(this, border);
  v6 = (vgui::StackLayout *)operator new(0xCu);
  vgui::StackLayout::StackLayout(v6, 1, 1);
  vgui::Panel::setLayout(this, v6);
}

void vgui::Menu::Menu(vgui::Menu *const this, int wide, int tall)
{
  vgui::RaisedBorder *v3; // esi
  vgui::StackLayout *v4; // esi

  vgui::Panel::Panel(this, 0, 0, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Menu + 2);
  v3 = (vgui::RaisedBorder *)operator new(0x38u);
  vgui::RaisedBorder::RaisedBorder(v3);
  vgui::Panel::setBorder(this, v3);
  v4 = (vgui::StackLayout *)operator new(0xCu);
  vgui::StackLayout::StackLayout(v4, 1, 1);
  vgui::Panel::setLayout(this, v4);
}

