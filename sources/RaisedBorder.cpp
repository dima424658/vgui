#include <VGUI_RaisedBorder.h>

void vgui::RaisedBorder::paint(vgui::RaisedBorder *const this, vgui::Panel *panel)
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 3))(panel, &wide, tall);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int))this->_vptr_Image + 6))(this, 2);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, _DWORD, _DWORD, int, int))this->_vptr_Image + 8))(
    this,
    0,
    0,
    wide,
    2);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, _DWORD, int, int, int))this->_vptr_Image + 8))(
    this,
    0,
    2,
    2,
    tall[0]);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int))this->_vptr_Image + 6))(this, 7);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    2,
    tall[0] - 2,
    wide,
    tall[0]);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    wide - 2,
    2,
    wide,
    tall[0] - 1);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int))this->_vptr_Image + 6))(this, 6);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    1,
    tall[0] - 1,
    wide,
    tall[0]);
  (*((void (__cdecl **)(vgui::RaisedBorder *const, int, int, int, int))this->_vptr_Image + 8))(
    this,
    wide - 1,
    1,
    wide,
    tall[0] - 1);
}

void vgui::RaisedBorder::RaisedBorder(vgui::RaisedBorder *const this)
{
  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::RaisedBorder + 2);
  vgui::Border::setInset(this, 2, 2, 2, 2);
}

