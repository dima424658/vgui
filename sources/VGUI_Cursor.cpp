#include <VGUI_Cursor.h>

void vgui::Cursor::privateInit(vgui::Cursor *const this, vgui::Bitmap *bitmap, int hotspotX, int hotspotY)
{
  this->_bitmap = bitmap;
  this->_hotspot[0] = hotspotX;
  this->_hotspot[1] = hotspotY;
}

vgui::Cursor::DefaultCursor vgui::Cursor::getDefaultCursor(vgui::Cursor *const this)
{
  return this->_dc;
}

void vgui::Cursor::getHotspot(vgui::Cursor *const this, int *const x, int *const y)
{
  *(_QWORD *)x = *(_QWORD *)this->_hotspot;
}

void vgui::Cursor::Cursor(vgui::Cursor *const this, vgui::Bitmap *bitmap, int hotspotX, int hotspotY)
{
  this->_vptr_Cursor = (int (**)(...))(&`vtable for'vgui::Cursor + 2);
  this->_bitmap = bitmap;
  this->_dc = dc_user;
  this->_hotspot[0] = hotspotX;
  this->_hotspot[1] = hotspotY;
}

void vgui::Cursor::Cursor(vgui::Cursor *const this, vgui::Cursor::DefaultCursor dc)
{
  vgui::Bitmap *v2; // eax
  vgui::Cursor::DefaultCursor v3; // esi
  vgui::Bitmap *v4; // edi
  int (**v5)(...); // eax
  int v6; // esi
  int tall; // [esp+8h] [ebp-34h]
  int hx; // [esp+28h] [ebp-14h] BYREF
  int hy[4]; // [esp+2Ch] [ebp-10h] BYREF

  this->_vptr_Cursor = (int (**)(...))(&`vtable for'vgui::Cursor + 2);
  this->_dc = dc;
  v2 = (vgui::Bitmap *)operator new(0x38u);
  v3 = this->_dc;
  v4 = v2;
  vgui::Bitmap::Bitmap(v2);
  v5 = (int (**)(...))&off_4A128;
  v4->_vptr_Image = (int (**)(...))&off_4A128;
  if ( v3 != dc_none )
  {
    v4[1]._vptr_Image = (int (**)(...))&byte_8;
    v4[1]._pos[0] = 8;
    v6 = 0;
    vgui::Bitmap::setSize(v4, 16, 16);
    do
    {
      vgui::Bitmap::setRGBA(v4, 0, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 1, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 2, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 3, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 4, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 5, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 6, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 7, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 8, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 9, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 10, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 11, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 12, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 13, v6, 0, 0, 0, 0);
      vgui::Bitmap::setRGBA(v4, 14, v6, 0, 0, 0, 0);
      tall = v6++;
      vgui::Bitmap::setRGBA(v4, 15, tall, 0, 0, 0, 0);
    }
    while ( v6 != 16 );
    vgui::Bitmap::setRGBA(v4, 0, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 1, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 2, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 3, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 4, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 5, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 6, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 7, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 9, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 10, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 11, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 12, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 13, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 14, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 15, 8, 0, 0xFFu, 0, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 0, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 1, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 2, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 3, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 4, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 5, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 6, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 7, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 8, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 9, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 10, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 11, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 12, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 13, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 14, 0, 0, 0xFFu, 0xFFu);
    vgui::Bitmap::setRGBA(v4, 8, 15, 0, 0, 0xFFu, 0xFFu);
    v5 = v4->_vptr_Image;
  }
  v5[25](v4, (int)&hx, (int)hy);
  vgui::Cursor::privateInit(this, v4, hx, hy[0]);
}

