#include <VGUI_ImagePanel.h>

void vgui::ImagePanel::setImage(vgui::ImagePanel *const this, vgui::Image *image)
{
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  this->_image = image;
  if ( image )
  {
    (*((void (__cdecl **)(vgui::Image *, int *, int *))image->_vptr_Image + 2))(image, &wide, tall);
    (*((void (__cdecl **)(vgui::ImagePanel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
  }
  (*((void (__cdecl **)(vgui::ImagePanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::ImagePanel::paintBackground(vgui::ImagePanel *const this)
{
  if ( this->_image )
  {
    (*((void (__cdecl **)(vgui::ImagePanel *const, int))this->_vptr_Panel + 93))(this, 2);
    (*((void (__cdecl **)(vgui::Image *, vgui::ImagePanel *const))this->_image->_vptr_Image + 23))(this->_image, this);
  }
}

void vgui::ImagePanel::ImagePanel(vgui::ImagePanel *const this, vgui::Image *image)
{
  int (**v2)(...); // eax
  int v3; // [esp+28h] [ebp-14h] BYREF
  int v4[4]; // [esp+2Ch] [ebp-10h] BYREF

  vgui::Panel::Panel(this, 0, 0, 64, 64);
  v2 = (int (**)(...))(&`vtable for'vgui::ImagePanel + 2);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ImagePanel + 2);
  this->_image = image;
  if ( image )
  {
    (*((void (__cdecl **)(vgui::Image *, int *, int *))image->_vptr_Image + 2))(image, &v3, v4);
    (*((void (__cdecl **)(vgui::ImagePanel *const, int, int))this->_vptr_Panel + 2))(this, v3, v4[0]);
    v2 = this->_vptr_Panel;
  }
  v2[12](this);
}

