#include <VGUI_PopupMenu.h>

void vgui::PopupMenu::showModal(vgui::PopupMenu *const this, vgui::Panel *panel)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 61))(panel);
  (*(void (__cdecl **)(int, vgui::PopupMenu *const))(*(_DWORD *)v2 + 48))(v2, this);
}

void vgui::PopupMenu::PopupMenu(vgui::PopupMenu *const this, int x, int y, int wide, int tall)
{
  vgui::Menu::Menu(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::PopupMenu + 2);
}

void vgui::PopupMenu::PopupMenu(vgui::PopupMenu *const this, int wide, int tall)
{
  vgui::Menu::Menu(this, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::PopupMenu + 2);
}

