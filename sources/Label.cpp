#include <VGUI_Label.h>

void vgui::Label::getTextSize(vgui::Label *const this, int *const wide, int *const tall)
{
  (*((void (__cdecl **)(vgui::TextImage *))this->_textImage->_vptr_Image + 2))(this->_textImage);
}

void vgui::Label::getContentSize(vgui::Label *const this, int *const wide, int *const tall)
{
  int v3; // ecx
  int tx0; // [esp+40h] [ebp-3Ch] BYREF
  int ty0; // [esp+44h] [ebp-38h] BYREF
  int tx1; // [esp+48h] [ebp-34h] BYREF
  int ty1; // [esp+4Ch] [ebp-30h] BYREF
  int ix0; // [esp+50h] [ebp-2Ch] BYREF
  int iy0; // [esp+54h] [ebp-28h] BYREF
  int ix1; // [esp+58h] [ebp-24h] BYREF
  int iy1; // [esp+5Ch] [ebp-20h] BYREF
  int minX; // [esp+60h] [ebp-1Ch] BYREF
  int minY; // [esp+64h] [ebp-18h] BYREF
  int maxX; // [esp+68h] [ebp-14h] BYREF
  int maxY[4]; // [esp+6Ch] [ebp-10h] BYREF

  (*(void (__cdecl **)(vgui::Label *const, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *))(*(_DWORD *)this->baseclass_0 + 548))(
    this,
    &tx0,
    &ty0,
    &tx1,
    &ty1,
    &ix0,
    &iy0,
    &ix1,
    &iy1,
    &minX,
    &minY,
    &maxX,
    maxY);
  v3 = minY;
  *wide = maxX - minX;
  *tall = maxY[0] - v3;
}

void vgui::Label::setFont(vgui::Label *const this, vgui::Scheme::SchemeFont schemeFont)
{
  (*((void (__cdecl **)(vgui::TextImage *, vgui::Scheme::SchemeFont))this->_textImage->_vptr_Image + 30))(
    this->_textImage,
    schemeFont);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setImage(vgui::Label *const this, vgui::Image *image)
{
  int v2; // eax

  v2 = *(_DWORD *)this->baseclass_0;
  this->_image = image;
  (*(void (__cdecl **)(vgui::Label *const))(v2 + 552))(this);
  if ( image )
    (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setText(vgui::Label *const this, int textBufferLen, const char *text)
{
  (*((void (__cdecl **)(vgui::TextImage *, int, const char *))this->_textImage->_vptr_Image + 28))(
    this->_textImage,
    textBufferLen,
    text);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::computeAlignment(vgui::Label *const this, int *const tx0, int *const ty0, int *const tx1, int *const ty1, int *const ix0, int *const iy0, int *const ix1, int *const iy1, int *const minX, int *const minY, int *const maxX, int *const maxY)
{
  vgui::Label *v13; // edx
  vgui::Image *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int offX; // [esp+1Ch] [ebp-60h]
  int offY; // [esp+20h] [ebp-5Ch]
  int v32; // [esp+24h] [ebp-58h]
  int v33; // [esp+24h] [ebp-58h]
  int v34; // [esp+28h] [ebp-54h]
  int wide[4]; // [esp+30h] [ebp-4Ch] BYREF
  int tall[4]; // [esp+40h] [ebp-3Ch] BYREF
  int tWide; // [esp+50h] [ebp-2Ch] BYREF
  int tTall; // [esp+54h] [ebp-28h] BYREF
  int iWide; // [esp+58h] [ebp-24h] BYREF
  int iTall[8]; // [esp+5Ch] [ebp-20h] BYREF

  (*(void (__cdecl **)(vgui::Label *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 232))(this, wide, tall);
  (*(void (__cdecl **)(vgui::Label *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 528))(this, &tWide, &tTall);
  v13 = this;
  iWide = 0;
  iTall[0] = 0;
  v14 = this->_image;
  if ( v14 )
  {
    (*((void (__cdecl **)(vgui::Image *, int *, int *))v14->_vptr_Image + 2))(this->_image, &iWide, iTall);
    v15 = iWide;
    v13 = this;
    v32 = iTall[0];
  }
  else
  {
    v32 = 0;
    v15 = 0;
  }
  *ix0 = 0;
  *iy0 = 0;
  *ix1 = v15;
  *iy1 = v32;
  *tx0 = 0;
  *ty0 = 0;
  v16 = tWide;
  *tx1 = tWide;
  v34 = v16;
  v17 = tTall;
  *ty1 = tTall;
  v18 = v13->_textAlignment;
  v33 = v17;
  if ( v18 <= 8 )
  {
    v19 = 1 << v18;
    if ( ((1 << v18) & 0x124) != 0 )
    {
      *tx0 = *ix1;
      v18 = v13->_textAlignment;
    }
    else if ( (v19 & 0x92) != 0 )
    {
      *tx0 = (*ix1 - *ix0) / 2 - (*tx1 - *tx0) / 2;
      v18 = v13->_textAlignment;
    }
    else if ( (v19 & 0x49) != 0 )
    {
      *tx0 = *ix0 - v34;
      v18 = v13->_textAlignment;
    }
    if ( v18 <= 8 )
    {
      v20 = 1 << v18;
      if ( ((1 << v18) & 0x1C0) != 0 )
      {
        *ty0 = *iy1;
      }
      else if ( (v20 & 0x38) != 0 )
      {
        *ty0 = (*iy1 - *iy0) / 2 - (*ty1 - *ty0) / 2;
      }
      else if ( (v20 & 7) != 0 )
      {
        *ty0 = *iy0 - v33;
      }
    }
  }
  *tx1 = *tx0 + v34;
  *ty1 = *ty0 + v33;
  *minX = *tx0;
  *minY = *ty0;
  v21 = *ix0;
  if ( *minX <= *ix0 )
    v21 = *minX;
  *minX = v21;
  v22 = *iy0;
  if ( *minY <= *iy0 )
    v22 = *minY;
  *minY = v22;
  *maxX = *tx1;
  *maxY = *ty1;
  v23 = *ix1;
  if ( *maxX >= *ix1 )
    v23 = *maxX;
  *maxX = v23;
  v24 = *iy1;
  if ( *maxY >= *iy1 )
    v24 = *maxY;
  *maxY = v24;
  *tx0 -= *minX;
  *ty0 -= *minY;
  *tx1 -= *minX;
  *ty1 -= *minY;
  *ix0 -= *minX;
  *iy0 -= *minY;
  *ix1 -= *minX;
  *iy1 -= *minY;
  *maxX -= *minX;
  *maxY -= *minY;
  *minX = 0;
  *minY = 0;
  v25 = v13->_contentAlignment;
  if ( v25 <= 8 )
  {
    v26 = 1 << v25;
    if ( ((1 << v25) & 0x124) != 0 )
    {
      offX = wide[0] + *minX - *maxX;
    }
    else
    {
      v29 = (1 << v25) & 0x92;
      if ( (v26 & 0x92) != 0 )
      {
        offX = wide[0] / 2 - (*maxX - *minX) / 2;
      }
      else
      {
        if ( (v26 & 0x49) == 0 )
          v29 = 0;
        offX = v29;
      }
    }
    v27 = 1 << v25;
    if ( ((1 << v25) & 0x1C0) != 0 )
    {
      offY = tall[0] - *maxY;
    }
    else
    {
      v28 = (1 << v25) & 0x38;
      if ( (v27 & 0x38) != 0 )
      {
        offY = tall[0] / 2 - *maxY / 2;
      }
      else
      {
        if ( (v27 & 7) == 0 )
          v28 = 0;
        offY = v28;
      }
    }
  }
  *tx0 += offX;
  *ty0 += offY;
  *tx1 += offX;
  *ty1 += offY;
  *ix0 += offX;
  *iy0 += offY;
  *ix1 += offX;
  *iy1 += offY;
  *minX += offX;
  *minY += offY;
  *maxX += offX;
  *maxY += offY;
  *minX -= 4;
  *minY -= 4;
  *maxX += 4;
  *maxY += 4;
}

void vgui::Label::paint(vgui::Label *const this)
{
  vgui::Image *v1; // eax
  vgui::TextImage *v2; // eax
  int tx0; // [esp+40h] [ebp-3Ch] BYREF
  int ty0; // [esp+44h] [ebp-38h] BYREF
  int tx1; // [esp+48h] [ebp-34h] BYREF
  int ty1; // [esp+4Ch] [ebp-30h] BYREF
  int ix0; // [esp+50h] [ebp-2Ch] BYREF
  int iy0; // [esp+54h] [ebp-28h] BYREF
  int ix1; // [esp+58h] [ebp-24h] BYREF
  int iy1; // [esp+5Ch] [ebp-20h] BYREF
  int minX; // [esp+60h] [ebp-1Ch] BYREF
  int minY; // [esp+64h] [ebp-18h] BYREF
  int maxX; // [esp+68h] [ebp-14h] BYREF
  int maxY[4]; // [esp+6Ch] [ebp-10h] BYREF

  (*(void (__cdecl **)(vgui::Label *const, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *, int *))(*(_DWORD *)this->baseclass_0 + 548))(
    this,
    &tx0,
    &ty0,
    &tx1,
    &ty1,
    &ix0,
    &iy0,
    &ix1,
    &iy1,
    &minX,
    &minY,
    &maxX,
    maxY);
  v1 = this->_image;
  if ( v1 )
  {
    (*v1->_vptr_Image)(this->_image, ix0, iy0);
    (*((void (__cdecl **)(vgui::Image *, vgui::Label *const))this->_image->_vptr_Image + 23))(this->_image, this);
  }
  v2 = this->_textImage;
  if ( v2 )
  {
    (*v2->_vptr_Image)(this->_textImage, tx0, ty0);
    (*((void (__cdecl **)(vgui::TextImage *, vgui::Label *const))this->_textImage->_vptr_Image + 23))(
      this->_textImage,
      this);
  }
  if ( (*(uint8_t (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 168))(this) )
  {
    (*(void (__cdecl **)(vgui::Label *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 4);
    (*(void (__cdecl **)(vgui::Label *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 384))(
      this,
      tx0,
      ty0,
      tx1,
      ty1);
  }
}

void vgui::Label::setTextAlignment(vgui::Label *const this, vgui::Label::Alignment alignment)
{
  this->_textAlignment = alignment;
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setContentAlignment(vgui::Label *const this, vgui::Label::Alignment alignment)
{
  this->_contentAlignment = alignment;
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::recomputeMinimumSize(vgui::Label *const this)
{
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*(void (__cdecl **)(vgui::Label *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 532))(this, &wide, tall);
  (*(void (__cdecl **)(vgui::Label *const, int, int))(*(_DWORD *)this->baseclass_0 + 236))(this, wide, tall[0]);
  if ( this->_contentFitted )
    (*(void (__cdecl **)(vgui::Label *const, int, int))(*(_DWORD *)this->baseclass_0 + 8))(this, wide, tall[0]);
}

void vgui::Label::setFont(vgui::Label *const this, vgui::Font *font)
{
  (*((void (__cdecl **)(vgui::TextImage *, vgui::Font *))this->_textImage->_vptr_Image + 31))(this->_textImage, font);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setContentFitted(vgui::Label *const this, bool state)
{
  this->_contentFitted = state;
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 552))(this);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setFgColor(vgui::Label *const this, vgui::Scheme::SchemeColor sc)
{
  void (__cdecl *v2)(vgui::TextImage *, vgui::Color *); // edi
  vgui::Color v3; // [esp+14h] [ebp-18h] BYREF

  vgui::Panel::setFgColor((vgui::Panel *const)this, sc);
  v2 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)this->_textImage->_vptr_Image + 3);
  vgui::Color::Color(&v3, sc);
  v2(this->_textImage, &v3);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setFgColor(vgui::Label *const this, int r, int g, int b, int a)
{
  vgui::TextImage *v5; // eax
  int (**v6)(...); // edx
  int (*v7)(...); // edx
  vgui::Color color; // [esp+38h] [ebp-34h] BYREF
  int v9[6]; // [esp+44h] [ebp-28h] BYREF

  vgui::Panel::setFgColor((vgui::Panel *const)this, r, g, b, a);
  vgui::Color::Color(&color, r, g, b, a);
  v5 = this->_textImage;
  v6 = v5->_vptr_Image;
  v9[0] = (int)(&`vtable for'vgui::Color + 2);
  v7 = v6[3];
  v9[1] = *(_DWORD *)color._color;
  v9[2] = color._schemeColor;
  v7(v5, v9);
  (*(void (__cdecl **)(vgui::Label *const))(*(_DWORD *)this->baseclass_0 + 48))(this);
}

void vgui::Label::setText(vgui::Label *const this, const char *format, ...)
{
  char buf[4096]; // [esp+10h] [ebp-100Ch] BYREF
  va_list __varargs; // [esp+1028h] [ebp+Ch] BYREF

  va_start(__varargs, format);
  vsnprintf(buf, 0x1000u, format, __varargs);
  buf[4095] = 0;
  (*(void (__cdecl **)(vgui::Label *const, unsigned int, char *))(*(_DWORD *)this->baseclass_0 + 512))(
    this,
    strlen(buf) + 1,
    buf);
}

void vgui::Label::init(vgui::Label *const this, int textBufferLen, const char *text, bool textFitted)
{
  vgui::TextImage *v4; // ebp
  void (__cdecl *v5)(vgui::TextImage *, vgui::Color *); // [esp+1Ch] [ebp-30h]
  vgui::Color v6; // [esp+24h] [ebp-28h] BYREF

  this->_contentFitted = textFitted;
  this->_textAlignment = a_center_0;
  this->_contentAlignment = a_center_0;
  v4 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v4, textBufferLen, text);
  this->_textImage = v4;
  v5 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)v4->_vptr_Image + 3);
  vgui::Color::Color(&v6, sc_black);
  v5(this->_textImage, &v6);
  this->_image = 0;
  (*(void (__cdecl **)(vgui::Label *const, int, const char *))(*(_DWORD *)this->baseclass_0 + 512))(
    this,
    textBufferLen,
    text);
}

void vgui::Label::Label(vgui::Label *const this, int textBufferLen, const char *text, int x, int y, int wide, int tall)
{
  vgui::TextImage *v7; // ebp
  int v8; // eax
  void (__cdecl *v9)(vgui::TextImage *, vgui::Color *); // [esp+2Ch] [ebp-30h]
  vgui::Color v10; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel((vgui::Panel *const)this, x, y, wide, tall);
  this->_textAlignment = a_center_0;
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Label + 2;
  this->_contentFitted = 0;
  this->_contentAlignment = a_center_0;
  v7 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v7, textBufferLen, text);
  this->_textImage = v7;
  v9 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)v7->_vptr_Image + 3);
  vgui::Color::Color(&v10, sc_black);
  v9(this->_textImage, &v10);
  v8 = *(_DWORD *)this->baseclass_0;
  this->_image = 0;
  (*(void (__cdecl **)(vgui::Label *const, int, const char *))(v8 + 512))(this, textBufferLen, text);
}

void vgui::Label::Label(vgui::Label *const this, const char *text, int x, int y, int wide, int tall)
{
  size_t v6; // eax
  int textBufferLen; // edi
  vgui::TextImage *v8; // ebp
  void (__cdecl *v9)(vgui::TextImage *, vgui::Color *); // [esp+2Ch] [ebp-30h]
  vgui::Color v10; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel((vgui::Panel *const)this, x, y, wide, tall);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Label + 2;
  v6 = strlen(text);
  this->_textAlignment = a_center_0;
  this->_contentAlignment = a_center_0;
  this->_contentFitted = 0;
  textBufferLen = v6 + 1;
  v8 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v8, textBufferLen, text);
  this->_textImage = v8;
  v9 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)v8->_vptr_Image + 3);
  vgui::Color::Color(&v10, sc_black);
  v9(this->_textImage, &v10);
  this->_image = 0;
  (*(void (__cdecl **)(vgui::Label *const, int, const char *))(*(_DWORD *)this->baseclass_0 + 512))(
    this,
    textBufferLen,
    text);
}

void vgui::Label::Label(vgui::Label *const this, const char *text, int x, int y)
{
  size_t v4; // eax
  int textBufferLen; // edi
  vgui::TextImage *v6; // ebp
  int v7; // eax
  void (__cdecl *v8)(vgui::TextImage *, vgui::Color *); // [esp+2Ch] [ebp-30h]
  vgui::Color v9; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel((vgui::Panel *const)this, x, y, 10, 10);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Label + 2;
  v4 = strlen(text);
  this->_contentFitted = 1;
  textBufferLen = v4 + 1;
  this->_textAlignment = a_center_0;
  this->_contentAlignment = a_center_0;
  v6 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v6, textBufferLen, text);
  this->_textImage = v6;
  v8 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)v6->_vptr_Image + 3);
  vgui::Color::Color(&v9, sc_black);
  v8(this->_textImage, &v9);
  v7 = *(_DWORD *)this->baseclass_0;
  this->_image = 0;
  (*(void (__cdecl **)(vgui::Label *const, int, const char *))(v7 + 512))(this, textBufferLen, text);
}

void vgui::Label::Label(vgui::Label *const this, const char *text)
{
  size_t v2; // eax
  int v3; // edi
  vgui::TextImage *v4; // ebp
  void (__cdecl *v5)(vgui::TextImage *, vgui::Color *); // [esp+2Ch] [ebp-30h]
  vgui::Color v6; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel((vgui::Panel *const)this, 0, 0, 10, 10);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Label + 2;
  v2 = strlen(text);
  this->_contentFitted = 1;
  v3 = v2 + 1;
  this->_textAlignment = a_center_0;
  this->_contentAlignment = a_center_0;
  v4 = (vgui::TextImage *)operator new(0x48u);
  vgui::TextImage::TextImage(v4, v3, text);
  this->_textImage = v4;
  v5 = (void (__cdecl *)(vgui::TextImage *, vgui::Color *))*((_DWORD *)v4->_vptr_Image + 3);
  vgui::Color::Color(&v6, sc_black);
  v5(this->_textImage, &v6);
  this->_image = 0;
  (*(void (__cdecl **)(vgui::Label *const, int, const char *))(*(_DWORD *)this->baseclass_0 + 512))(this, v3, text);
}

