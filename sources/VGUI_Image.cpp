#include <VGUI_Image.h>

void vgui::Image::setPos(vgui::Image *const this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

void vgui::Image::getPos(vgui::Image *const this, int *const x, int *const y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

void vgui::Image::getSize(vgui::Image *const this, int *const wide, int *const tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

void vgui::Image::setSize(vgui::Image *const this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

void vgui::Image::drawSetColor(vgui::Image *const this, vgui::Scheme::SchemeColor sc)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 93))(this->_panel);
}

void vgui::Image::drawSetColor(vgui::Image *const this, int r, int g, int b, int a)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 94))(this->_panel);
}

void vgui::Image::drawFilledRect(vgui::Image *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::Panel *, int, int, int, int))this->_panel->_vptr_Panel + 95))(
    this->_panel,
    x0 + this->_pos[0],
    y0 + this->_pos[1],
    this->_pos[0] + x1,
    this->_pos[1] + y1);
}

void vgui::Image::drawOutlinedRect(vgui::Image *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::Panel *, int, int, int, int))this->_panel->_vptr_Panel + 96))(
    this->_panel,
    x0 + this->_pos[0],
    y0 + this->_pos[1],
    this->_pos[0] + x1,
    this->_pos[1] + y1);
}

void vgui::Image::drawSetTextFont(vgui::Image *const this, vgui::Scheme::SchemeFont sf)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 97))(this->_panel);
}

void vgui::Image::drawSetTextFont(vgui::Image *const this, vgui::Font *font)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 98))(this->_panel);
}

void vgui::Image::drawSetTextColor(vgui::Image *const this, vgui::Scheme::SchemeColor sc)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 99))(this->_panel);
}

void vgui::Image::drawSetTextColor(vgui::Image *const this, int r, int g, int b, int a)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 100))(this->_panel);
}

void vgui::Image::drawSetTextPos(vgui::Image *const this, int x, int y)
{
  (*((void (__cdecl **)(vgui::Panel *, int, int))this->_panel->_vptr_Panel + 101))(
    this->_panel,
    this->_pos[0] + x,
    this->_pos[1] + y);
}

void vgui::Image::drawPrintText(vgui::Image *const this, const char *str, int strlen)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 102))(this->_panel);
}

void vgui::Image::drawPrintText(vgui::Image *const this, int x, int y, const char *str, int strlen)
{
  (*((void (__cdecl **)(vgui::Panel *, int, int))this->_panel->_vptr_Panel + 103))(
    this->_panel,
    this->_pos[0] + x,
    this->_pos[1] + y);
}

void vgui::Image::drawPrintChar(vgui::Image *const this, char ch)
{
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_panel->_vptr_Panel + 104))(this->_panel, ch);
}

void vgui::Image::drawPrintChar(vgui::Image *const this, int x, int y, char ch_0)
{
  (*((void (__cdecl **)(vgui::Panel *, int, int, _DWORD))this->_panel->_vptr_Panel + 105))(
    this->_panel,
    this->_pos[0] + x,
    this->_pos[1] + y,
    ch_0);
}

void vgui::Image::drawSetTextureRGBA(vgui::Image *const this, int id, const char *rgba, int wide, int tall)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 106))(this->_panel);
}

void vgui::Image::drawSetTexture(vgui::Image *const this, int id)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 107))(this->_panel);
}

void vgui::Image::drawTexturedRect(vgui::Image *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::Panel *))this->_panel->_vptr_Panel + 108))(this->_panel);
}

void vgui::Image::doPaint(vgui::Image *const this, vgui::Panel *panel)
{
  int (**v2)(...); // edx

  v2 = this->_vptr_Image;
  this->_panel = panel;
  v2[22](this, panel);
  this->_panel = 0;
}

void vgui::Image::setColor(vgui::Image *const this, vgui::Color *p_color)
{
  *(_DWORD *)this->_color._color = *(_DWORD *)p_color->_color;
  this->_color._schemeColor = p_color->_schemeColor;
}

void vgui::Image::getColor(vgui::Image *const this, vgui::Color *const color)
{
  *(_DWORD *)color->_color = *(_DWORD *)this->_color._color;
  color->_schemeColor = this->_color._schemeColor;
}

void vgui::Image::Image(vgui::Image *const this)
{
  vgui::Color v1; // [esp+24h] [ebp-18h] BYREF

  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::Image + 2);
  vgui::Color::Color(&this->_color);
  this->_panel = 0;
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  vgui::Color::Color(&v1, 255, 255, 255, 0);
  *(_DWORD *)this->_color._color = *(_DWORD *)v1._color;
  this->_color._schemeColor = v1._schemeColor;
}

