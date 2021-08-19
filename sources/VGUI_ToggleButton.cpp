#include <VGUI_ToggleButton.h>

void vgui::ToggleButton::ToggleButton(vgui::ToggleButton *const this, const char *text, int x, int y, int wide, int tall)
{
  vgui::ButtonController *v6; // eax

  vgui::Button::Button(this, text, x, y, wide, tall);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::ToggleButton + 2;
  v6 = (vgui::ButtonController *)operator new(0xCu);
  v6->_vptr_ButtonController = (int (**)(...))off_49688;
  v6[1]._vptr_ButtonController = (int (**)(...))&off_496C4;
  v6[2]._vptr_ButtonController = (int (**)(...))this;
  vgui::Button::setButtonController(this, v6);
}

void vgui::ToggleButton::ToggleButton(vgui::ToggleButton *const this, const char *text, int x, int y)
{
  vgui::ButtonController *v4; // eax

  vgui::Button::Button(this, text, x, y);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::ToggleButton + 2;
  v4 = (vgui::ButtonController *)operator new(0xCu);
  v4->_vptr_ButtonController = (int (**)(...))off_49688;
  v4[1]._vptr_ButtonController = (int (**)(...))&off_496C4;
  v4[2]._vptr_ButtonController = (int (**)(...))this;
  vgui::Button::setButtonController(this, v4);
}

