#include <VGUI_IntLabel.h>

void `non-virtual thunk to'vgui::IntLabel::intChanged(vgui::IntLabel *this, int a2, vgui::Panel *a3)
{
  vgui::IntLabel::intChanged((vgui::IntLabel *)((char *)this - 208), a2, a3);
}

void vgui::IntLabel::intChanged(vgui::IntLabel *const this, int value, vgui::Panel *panel)
{
  (*(void (**)(void))(*(_DWORD *)this->baseclass_0 + 556))();
}

void vgui::IntLabel::paintBackground(vgui::IntLabel *const this)
{
  size_t v2; // eax
  char buf[50]; // [esp+2Eh] [ebp-3Eh] BYREF

  sprintf(buf, "%d", this->_value);
  vgui::Panel::paintBackground((vgui::Panel *const)this);
  (*(void (__cdecl **)(vgui::IntLabel *const, int))(*(_DWORD *)this->baseclass_0 + 388))(this, 1);
  (*(void (__cdecl **)(vgui::IntLabel *const, int))(*(_DWORD *)this->baseclass_0 + 396))(this, 1);
  v2 = strlen(buf);
  (*(void (__cdecl **)(vgui::IntLabel *const, _DWORD, _DWORD, char *, size_t))(*(_DWORD *)this->baseclass_0 + 412))(
    this,
    0,
    0,
    buf,
    v2);
}

void vgui::IntLabel::setValue(vgui::IntLabel *const this, int value)
{
  if ( this->_value != value )
  {
    this->_value = value;
    (*(void (**)(void))(*(_DWORD *)this->baseclass_0 + 48))();
  }
}

void vgui::IntLabel::IntLabel(vgui::IntLabel *const this, int value, int x, int y, int wide, int tall)
{
  vgui::Label::Label(this, 0, x, y, wide, tall);
  this->_vptr_IntChangeSignal = (int (**)(...))(&`vtable for'vgui::IntLabel + 145);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::IntLabel + 2;
  this->_value = 0;
  if ( value )
  {
    this->_value = value;
    vgui::Panel::repaint((vgui::Panel *const)this);
  }
}

