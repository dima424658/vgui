#include <VGUI_EtchedBorder.h>

void vgui::EtchedBorder::paint(vgui::EtchedBorder *const this, vgui::Panel *panel)
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 3))(panel, &wide, tall);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, int))this->_vptr_Image + 6))(this, 2);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, _DWORD, int, int))this->_vptr_Image + 8))(
    this,
    0,
    0,
    wide,
    2);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    tall[0] - 2,
    wide,
    tall[0]);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    2,
    2,
    tall[0] - 2);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    wide - 2,
    2,
    wide,
    tall[0] - 2);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, int))this->_vptr_Image + 6))(this, 7);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, _DWORD, int, int))this->_vptr_Image + 8))(
    this,
    0,
    0,
    wide - 1,
    1);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    tall[0] - 2,
    wide - 1,
    tall[0] - 1);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    1,
    1,
    tall[0] - 2);
  (*((void (__cdecl **)(vgui::EtchedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    wide - 2,
    1,
    wide - 1,
    tall[0] - 2);
}

void vgui::EtchedBorder::EtchedBorder(vgui::EtchedBorder *const this)
{
  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::EtchedBorder + 2);
  vgui::Border::setInset(this, 2, 2, 2, 2);
}

