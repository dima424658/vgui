#include <VGUI_CheckButton.h>

void vgui::CheckButton::paintBackground(vgui::CheckButton *const this)
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*(void (__cdecl **)(vgui::CheckButton *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 232))(this, &wide, tall);
  (*(void (__cdecl **)(vgui::CheckButton *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 8);
  (*(void (__cdecl **)(vgui::CheckButton *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    0,
    0,
    wide,
    tall[0]);
}

void vgui::CheckButton::CheckButton(vgui::CheckButton *const this, const char *text, int x, int y, int wide, int tall)
{
  vgui::Image *v6; // esi

  vgui::ToggleButton::ToggleButton(this, text, x, y, wide, tall);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::CheckButton + 2;
  vgui::Label::setTextAlignment(this, a_east_0);
  v6 = (vgui::Image *)operator new(0x28u);
  vgui::Image::Image(v6);
  v6[1]._vptr_Image = (int (**)(...))this;
  v6->_vptr_Image = (int (**)(...))&off_42FE8;
  vgui::Image::setSize(v6, 20, 20);
  vgui::Label::setImage(this, v6);
}

void vgui::CheckButton::CheckButton(vgui::CheckButton *const this, const char *text, int x, int y)
{
  vgui::Image *v4; // esi
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  vgui::ToggleButton::ToggleButton(this, text, x, y);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::CheckButton + 2;
  vgui::Label::setTextAlignment(this, a_east_0);
  v4 = (vgui::Image *)operator new(0x28u);
  vgui::Image::Image(v4);
  v4[1]._vptr_Image = (int (**)(...))this;
  v4->_vptr_Image = (int (**)(...))&off_42FE8;
  vgui::Image::setSize(v4, 20, 20);
  vgui::Label::setImage(this, v4);
  vgui::Label::getContentSize(this, &wide, tall);
  vgui::Panel::setSize((vgui::Panel *const)this, wide, tall[0]);
}

