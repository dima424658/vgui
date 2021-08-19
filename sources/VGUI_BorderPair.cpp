#include <VGUI_BorderPair.h>

void vgui::BorderPair::doPaint(vgui::BorderPair *const this, vgui::Panel *panel)
{
  vgui::Border *v2; // eax
  vgui::Border *v3; // eax

  v2 = this->_border[0];
  if ( v2 )
    (*((void (__cdecl **)(vgui::Border *, vgui::Panel *))v2->_vptr_Image + 23))(v2, panel);
  v3 = this->_border[1];
  if ( v3 )
    (*((void (__cdecl **)(vgui::Border *, vgui::Panel *))v3->_vptr_Image + 23))(v3, panel);
}

void vgui::BorderPair::paint(vgui::BorderPair *const this, vgui::Panel *panel)
{
  vgui::Border *v2; // eax
  vgui::Border *v3; // eax

  v2 = this->_border[0];
  if ( v2 )
    (*((void (__cdecl **)(vgui::Border *, vgui::Panel *))v2->_vptr_Image + 22))(v2, panel);
  v3 = this->_border[1];
  if ( v3 )
    (*((void (__cdecl **)(vgui::Border *, vgui::Panel *))v3->_vptr_Image + 22))(v3, panel);
}

void vgui::BorderPair::BorderPair(vgui::BorderPair *const this, vgui::Border *border0, vgui::Border *border1)
{
  vgui::Border::Border(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::BorderPair + 2);
  this->_border[0] = border0;
  this->_border[1] = border1;
}

