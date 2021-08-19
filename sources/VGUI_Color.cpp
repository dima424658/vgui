#include <VGUI_Color.h>

void vgui::Color::init(vgui::Color *const this)
{
  this->_color[0] = 0;
  this->_color[1] = 0;
  this->_color[2] = 0;
  this->_color[3] = 0;
  this->_schemeColor = sc_user;
}

void vgui::Color::setColor(vgui::Color *const this, int r, int g, int b, int a)
{
  this->_schemeColor = sc_user;
  this->_color[0] = r;
  this->_color[1] = g;
  this->_color[2] = b;
  this->_color[3] = a;
}

void vgui::Color::setColor(vgui::Color *const this, vgui::Scheme::SchemeColor sc)
{
  this->_schemeColor = sc;
}

void vgui::Color::getColor(vgui::Color *const this, vgui::Scheme::SchemeColor *const sc)
{
  *sc = this->_schemeColor;
}

int vgui::Color::operator[](vgui::Color *const this, int index)
{
  int co[4]; // [esp+20h] [ebp-1Ch] BYREF

  (*((void (__cdecl **)(vgui::Color *const, int *, int *, int *, int *))this->_vptr_Color + 3))(
    this,
    co,
    &co[1],
    &co[2],
    &co[3]);
  return co[index];
}

void vgui::Color::getColor(vgui::Color *const this, int *const r, int *const g, int *const b, int *const a)
{
  vgui::App *v5; // eax
  int v6; // eax

  if ( this->_schemeColor )
  {
    v5 = vgui::App::getInstance();
    v6 = (*((int (__cdecl **)(vgui::App *))v5->_vptr_App + 21))(v5);
    (*(void (__cdecl **)(int, vgui::Scheme::SchemeColor, int *const, int *const, int *const, int *const))(*(_DWORD *)v6 + 4))(
      v6,
      this->_schemeColor,
      r,
      g,
      b,
      a);
  }
  else
  {
    *r = this->_color[0];
    *g = this->_color[1];
    *b = this->_color[2];
    *a = this->_color[3];
  }
}

void vgui::Color::Color(vgui::Color *const this)
{
  this->_vptr_Color = (int (**)(...))(&`vtable for'vgui::Color + 2);
  this->_color[0] = 0;
  this->_color[1] = 0;
  this->_color[2] = 0;
  this->_color[3] = 0;
  this->_schemeColor = sc_user;
}

void vgui::Color::Color(vgui::Color *const this, int r, int g, int b, int a)
{
  this->_vptr_Color = (int (**)(...))(&`vtable for'vgui::Color + 2);
  this->_color[0] = r;
  this->_schemeColor = sc_user;
  this->_color[1] = g;
  this->_color[2] = b;
  this->_color[3] = a;
}

void vgui::Color::Color(vgui::Color *const this, vgui::Scheme::SchemeColor sc)
{
  this->_vptr_Color = (int (**)(...))(&`vtable for'vgui::Color + 2);
  this->_color[0] = 0;
  this->_color[1] = 0;
  this->_color[2] = 0;
  this->_color[3] = 0;
  this->_schemeColor = sc;
}

