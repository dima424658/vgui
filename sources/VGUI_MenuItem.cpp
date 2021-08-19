#include <VGUI_MenuItem.h>

void vgui::MenuItem::MenuItem(vgui::MenuItem *const this, const char *text)
{
  vgui::Button::Button(this, text, 0, 0);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::MenuItem + 2;
  vgui::Button::setButtonBorderEnabled(this, 0);
  this->_subMenu = 0;
}

void vgui::MenuItem::MenuItem(vgui::MenuItem *const this, const char *text, vgui::Menu *subMenu)
{
  vgui::Button::Button(this, text, 0, 0);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::MenuItem + 2;
  vgui::Button::setButtonBorderEnabled(this, 0);
  this->_subMenu = subMenu;
}

