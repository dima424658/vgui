#include <VGUI_LineBorder.h>

void vgui::LineBorder::init(vgui::LineBorder *const this, int thickness, vgui::Color *p_color)
{
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 24))(
    this,
    thickness,
    thickness,
    thickness,
    thickness);
  *(_DWORD *)this->_color._color = *(_DWORD *)p_color->_color;
  this->_color._schemeColor = p_color->_schemeColor;
}

void vgui::LineBorder::paint(vgui::LineBorder *const this, vgui::Panel *panel)
{
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall; // [esp+2Ch] [ebp-20h] BYREF
  int r; // [esp+30h] [ebp-1Ch] BYREF
  int g; // [esp+34h] [ebp-18h] BYREF
  int b; // [esp+38h] [ebp-14h] BYREF
  int a[4]; // [esp+3Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 3))(panel, &wide, &tall);
  vgui::Color::getColor(&this->_color, &r, &g, &b, a);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 7))(this, r, g, b, a[0]);
  (*((void (__cdecl **)(vgui::LineBorder *const, _DWORD, _DWORD, int, int))this->_vptr_Image + 8))(
    this,
    0,
    0,
    wide,
    this->_inset[1]);
  (*((void (__cdecl **)(vgui::LineBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    tall - this->_inset[3],
    wide,
    tall);
  (*((void (__cdecl **)(vgui::LineBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    this->_inset[1],
    this->_inset[0],
    tall - this->_inset[3]);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    wide - this->_inset[2],
    this->_inset[1],
    wide,
    tall - this->_inset[3]);
}

void vgui::LineBorder::LineBorder(vgui::LineBorder *const this)
{
  vgui::Color v1; // [esp+24h] [ebp-18h] BYREF

  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::LineBorder + 2);
  vgui::Color::Color(&this->_color);
  vgui::Color::Color(&v1, 0, 0, 0, 0);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 24))(this, 1, 1, 1, 1);
  *(_DWORD *)this->_color._color = *(_DWORD *)v1._color;
  this->_color._schemeColor = v1._schemeColor;
}

void vgui::LineBorder::LineBorder(vgui::LineBorder *const this, int thickness)
{
  vgui::Color v2; // [esp+24h] [ebp-18h] BYREF

  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::LineBorder + 2);
  vgui::Color::Color(&this->_color);
  vgui::Color::Color(&v2, 0, 0, 0, 0);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 24))(
    this,
    thickness,
    thickness,
    thickness,
    thickness);
  *(_DWORD *)this->_color._color = *(_DWORD *)v2._color;
  this->_color._schemeColor = v2._schemeColor;
}

void vgui::LineBorder::LineBorder(vgui::LineBorder *const this, vgui::Color color)
{
  vgui::Scheme::SchemeColor v2; // esi
  int v3; // [esp+28h] [ebp-14h]

  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::LineBorder + 2);
  vgui::Color::Color(&this->_color);
  v2 = *((_DWORD *)color._vptr_Color + 2);
  v3 = *((_DWORD *)color._vptr_Color + 1);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 24))(this, 1, 1, 1, 1);
  this->_color._schemeColor = v2;
  *(_DWORD *)this->_color._color = v3;
}

void vgui::LineBorder::LineBorder(vgui::LineBorder *const this, int thickness, vgui::Color color)
{
  vgui::Scheme::SchemeColor v3; // edi
  int v4; // [esp+28h] [ebp-14h]

  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::LineBorder + 2);
  vgui::Color::Color(&this->_color);
  v3 = *((_DWORD *)color._vptr_Color + 2);
  v4 = *((_DWORD *)color._vptr_Color + 1);
  (*((void (__cdecl **)(vgui::LineBorder *const, int, int, int, int))this->_vptr_Image + 24))(
    this,
    thickness,
    thickness,
    thickness,
    thickness);
  this->_color._schemeColor = v3;
  *(_DWORD *)this->_color._color = v4;
}

