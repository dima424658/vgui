#include <VGUI_TextPanel.h>

void vgui::TextPanel::setText(vgui::TextPanel *const this, const char *text)
{
  (*((void (__cdecl **)(vgui::TextImage *))this->_textImage->_vptr_Image + 29))(this->_textImage);
}

void vgui::TextPanel::setFont(vgui::TextPanel *const this, vgui::Scheme::SchemeFont schemeFont)
{
  (*((void (__cdecl **)(vgui::TextImage *))this->_textImage->_vptr_Image + 30))(this->_textImage);
}

void vgui::TextPanel::setFont(vgui::TextPanel *const this, vgui::Font *font)
{
  (*((void (__cdecl **)(vgui::TextImage *))this->_textImage->_vptr_Image + 31))(this->_textImage);
}

void vgui::TextPanel::paint(vgui::TextPanel *const this)
{
  (*((void (__cdecl **)(vgui::TextImage *, vgui::TextPanel *const))this->_textImage->_vptr_Image + 23))(
    this->_textImage,
    this);
}

void vgui::TextPanel::setFgColor(vgui::TextPanel *const this, vgui::Scheme::SchemeColor sc)
{
  void (__cdecl *v2)(vgui::TextImage *, vgui::Color *); // edi
  vgui::Color v3; // [esp+14h] [ebp-18h] BYREF

  vgui::Panel::setFgColor(this, sc);
  v2 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)this->_textImage->_vptr_Image + 3);
  vgui::Color::Color(&v3, sc);
  v2(this->_textImage, &v3);
}

void vgui::TextPanel::setFgColor(vgui::TextPanel *const this, int r, int g, int b, int a)
{
  vgui::TextImage *v5; // eax
  int (**v6)(...); // edx
  int (*v7)(...); // edx
  vgui::Color color; // [esp+38h] [ebp-34h] BYREF
  int v9[6]; // [esp+44h] [ebp-28h] BYREF

  vgui::Panel::setFgColor(this, r, g, b, a);
  vgui::Color::Color(&color, r, g, b, a);
  v5 = this->_textImage;
  v6 = v5->_vptr_Image;
  v9[0] = (int)(&`vtable for'vgui::Color + 2);
  v7 = v6[3];
  v9[1] = *(_DWORD *)color._color;
  v9[2] = color._schemeColor;
  v7(v5, v9);
}

void vgui::TextPanel::setSize(vgui::TextPanel *const this, int wide, int tall)
{
  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::TextPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::TextImage *, int, int))this->_textImage->_vptr_Image + 5))(this->_textImage, wide, tall);
}

void vgui::TextPanel::TextPanel(vgui::TextPanel *const this, const char *text, int x, int y, int wide, int tall)
{
  vgui::TextImage *v6; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TextPanel + 2);
  v6 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v6, text);
  this->_textImage = v6;
  (*((void (__cdecl **)(vgui::TextImage *, int, int))v6->_vptr_Image + 5))(v6, wide, tall);
}

