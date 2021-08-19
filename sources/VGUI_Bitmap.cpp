#include <VGUI_Bitmap.h>

void vgui::Bitmap::setRGBA(vgui::Bitmap *const this, int x, int y, uchar r, uchar g, uchar b, uchar a)
{
  int wide[4]; // [esp+20h] [ebp-3Ch] BYREF
  int tall[7]; // [esp+30h] [ebp-2Ch] BYREF

  if ( this->_rgba )
  {
    (*((void (__cdecl **)(vgui::Bitmap *const, int *, int *))this->_vptr_Image + 2))(this, wide, tall);
    if ( x >= 0 && x < wide[0] && y >= 0 && y < tall[0] )
    {
      this->_rgba[4 * x + 4 * y * wide[0]] = r;
      this->_rgba[4 * x + 1 + 4 * y * wide[0]] = g;
      this->_rgba[4 * x + 2 + 4 * y * wide[0]] = b;
      this->_rgba[4 * wide[0] * y + 3 + 4 * x] = a;
    }
  }
}

void vgui::Bitmap::paint(vgui::Bitmap *const this, vgui::Panel *panel)
{
  int v2; // eax
  int v3; // eax
  bool v4; // zf
  vgui::Color color; // [esp+24h] [ebp-38h] BYREF
  int wide; // [esp+30h] [ebp-2Ch] BYREF
  int tall; // [esp+34h] [ebp-28h] BYREF
  int r; // [esp+38h] [ebp-24h] BYREF
  int g; // [esp+3Ch] [ebp-20h] BYREF
  int b; // [esp+40h] [ebp-1Ch] BYREF
  int a; // [esp+44h] [ebp-18h] BYREF
  int x; // [esp+48h] [ebp-14h] BYREF
  int y[4]; // [esp+4Ch] [ebp-10h] BYREF

  if ( this->_rgba )
  {
    (*((void (__cdecl **)(vgui::Bitmap *const, int *, int *))this->_vptr_Image + 2))(this, &wide, &tall);
    v2 = this->_id;
    if ( v2 )
    {
      if ( this->_uploaded )
      {
LABEL_4:
        vgui::Color::Color(&color);
        (*((void (__cdecl **)(vgui::Bitmap *const, vgui::Color *))this->_vptr_Image + 4))(this, &color);
        vgui::Color::getColor(&color, &r, &g, &b, &a);
        (*((void (__cdecl **)(vgui::Bitmap *const, int))this->_vptr_Image + 20))(this, this->_id);
        (*((void (__cdecl **)(vgui::Bitmap *const, int, int, int, int))this->_vptr_Image + 7))(this, r, g, b, a);
        (*((void (__cdecl **)(vgui::Bitmap *const, int *, int *))this->_vptr_Image + 1))(this, &x, y);
        (*((void (__cdecl **)(vgui::Bitmap *const, int, int, int, int))this->_vptr_Image + 21))(
          this,
          x,
          y[0],
          x + wide,
          y[0] + tall);
        return;
      }
LABEL_8:
      (*((void (__cdecl **)(vgui::Bitmap *const, int, uchar *, int, int))this->_vptr_Image + 19))(
        this,
        v2,
        this->_rgba,
        wide,
        tall);
      this->_uploaded = 1;
      goto LABEL_4;
    }
    if ( (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 61))(panel) )
    {
      v3 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 61))(panel);
      v2 = (*(int (__cdecl **)(int))(*(_DWORD *)v3 + 60))(v3);
      v4 = !this->_uploaded;
      this->_id = v2;
      if ( !v4 )
        goto LABEL_4;
      goto LABEL_8;
    }
  }
}

void vgui::Bitmap::setSize(vgui::Bitmap *const this, int wide, int tall)
{
  vgui::Image::setSize(this, wide, tall);
  if ( this->_rgba )
    operator delete[]((VFontData *const)this->_rgba);
  this->_rgba = (uchar *)operator new[](4 * wide * tall);
}

void vgui::Bitmap::Bitmap(vgui::Bitmap *const this)
{
  vgui::Image::Image(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::Bitmap + 2);
  this->_rgba = 0;
  this->_id = 0;
  this->_uploaded = 0;
}

