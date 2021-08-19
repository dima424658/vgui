#include <VGUI_TextImage.h>

void vgui::TextImage::init(vgui::TextImage *const this, int textBufferLen, const char *text)
{
  int (**v4)(...); // eax
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  v4 = this->_vptr_Image;
  this->_schemeFont = sf_primary1;
  this->_text = 0;
  this->_font = 0;
  this->_textBufferLen = 0;
  v4[29](this, text);
  (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 25))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::TextImage *const, int, int))this->_vptr_Image + 5))(this, wide, tall[0]);
}

void vgui::TextImage::setFont(vgui::TextImage *const this, vgui::Scheme::SchemeFont schemeFont)
{
  this->_schemeFont = schemeFont;
}

void vgui::TextImage::setFont(vgui::TextImage *const this, vgui::Font *font)
{
  this->_font = font;
}

void vgui::TextImage::getTextSizeWrapped(vgui::TextImage *const this, int *const wideo, int *const tallo)
{
  int v3; // esi
  int j; // edi
  char v5; // bl
  int v6; // ecx
  char *v7; // edx
  char v8; // al
  int v9; // ebx
  int v10; // ebp
  char *v11; // edx
  int v12; // edi
  int v13; // ebx
  int *v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // edx
  char v18; // bl
  int *v19; // [esp+28h] [ebp-94h]
  int x; // [esp+2Ch] [ebp-90h]
  int i; // [esp+34h] [ebp-88h]
  int v22; // [esp+38h] [ebp-84h]
  int y; // [esp+3Ch] [ebp-80h]
  int yAdd; // [esp+40h] [ebp-7Ch]
  int v25; // [esp+44h] [ebp-78h]
  int wide[4]; // [esp+50h] [ebp-6Ch] BYREF
  int a[4]; // [esp+60h] [ebp-5Ch] BYREF
  int b[4]; // [esp+70h] [ebp-4Ch] BYREF
  int c[4]; // [esp+80h] [ebp-3Ch] BYREF
  int tall; // [esp+90h] [ebp-2Ch] BYREF
  int a_0; // [esp+94h] [ebp-28h] BYREF
  int b_0; // [esp+98h] [ebp-24h] BYREF
  int c_0[8]; // [esp+9Ch] [ebp-20h] BYREF

  *wideo = 0;
  *tallo = 0;
  if ( this->_text )
  {
    (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 2))(this, wide, &tall);
    v3 = (*((int (__cdecl **)(vgui::TextImage *const))this->_vptr_Image + 27))(this);
    y = 0;
    x = 0;
    yAdd = (*(int (__cdecl **)(int))(*(_DWORD *)v3 + 16))(v3);
    for ( j = 0; ; ++j )
    {
      while ( 1 )
      {
        v5 = this->_text[j];
        (*(void (__cdecl **)(int, _DWORD, int *, int *, int *))(*(_DWORD *)v3 + 8))(v3, v5, a, b, c);
        if ( !v5 )
          return;
        if ( v5 != 13 )
          break;
LABEL_27:
        ++j;
      }
      if ( v5 != 10 )
      {
        if ( v5 != 32 )
        {
          v6 = b[0] + a[0] + c[0];
          v7 = this->_text;
          v8 = v7[j + 1];
          if ( !v8 || v8 == 10 || v8 == 13 || v8 == 32 )
          {
            v9 = 1;
            v25 = 0;
            v11 = &v7[j];
          }
          else
          {
            v9 = 1;
            v10 = b[0] + a[0] + c[0];
            do
            {
              ++v9;
              (*(void (__cdecl **)(int, _DWORD, int *, int *, int *))(*(_DWORD *)v3 + 8))(v3, v8, &a_0, &b_0, c_0);
              v10 += c_0[0] + b_0 + a_0;
              v11 = &this->_text[j];
              v8 = v11[v9];
            }
            while ( v8 != 10 && v8 && v8 != 32 && v8 != 13 );
            v6 = v10;
            v25 = v9 - 1;
          }
          if ( v6 + x > wide[0] )
          {
            y += yAdd;
            x = 0;
          }
          i = j;
          v12 = x;
          v22 = v9;
          v13 = 0;
          v14 = tallo;
          while ( 1 )
          {
            v19 = v14;
            (*(void (__cdecl **)(int, _DWORD, int *, int *, int *))(*(_DWORD *)v3 + 8))(v3, v11[v13], a, b, c);
            v15 = a[0];
            v16 = c[0] + b[0] + v12 + a[0];
            if ( v16 < *wideo )
              v16 = *wideo;
            *wideo = v16;
            v14 = v19;
            v17 = *v19;
            if ( yAdd + y >= *v19 )
              v17 = yAdd + y;
            ++v13;
            *v19 = v17;
            v12 += c[0] + b[0] + v15;
            if ( v22 <= v13 )
              break;
            v11 = &this->_text[i];
          }
          x = v12;
          j = v25 + i;
          goto LABEL_27;
        }
        v18 = this->_text[j + 1];
        (*(void (__cdecl **)(int, int, int *, int *, int *))(*(_DWORD *)v3 + 8))(v3, 32, a, b, c);
        switch ( v18 )
        {
          case 10:
            goto LABEL_27;
          case 0:
            goto LABEL_27;
          case 13:
            goto LABEL_27;
        }
        x += c[0] + b[0] + a[0];
        if ( x <= wide[0] )
          goto LABEL_27;
      }
      y += yAdd;
      x = 0;
    }
  }
}

void vgui::TextImage::getTextSize(vgui::TextImage *const this, int *const wide, int *const tall)
{
  int v3; // eax

  *wide = 0;
  *tall = 0;
  if ( this->_text )
  {
    v3 = (*((int (__cdecl **)(vgui::TextImage *const))this->_vptr_Image + 27))(this);
    if ( v3 )
      (*(void (__cdecl **)(int, char *, int *const, int *const))(*(_DWORD *)v3 + 12))(v3, this->_text, wide, tall);
  }
}

void vgui::TextImage::paint(vgui::TextImage *const this, vgui::Panel *panel)
{
  vgui::TextImage *v2; // edi
  int v3; // ebp
  int v4; // esi
  char v5; // bl
  char *v6; // edx
  int v7; // ecx
  char v8; // al
  int v9; // ebx
  int v10; // edi
  vgui::TextImage *v11; // ebp
  int v12; // ebx
  int v13; // eax
  int v14; // esi
  int v15; // edi
  char v16; // bl
  int v17; // [esp+24h] [ebp-A8h]
  int i; // [esp+28h] [ebp-A4h]
  int ia; // [esp+28h] [ebp-A4h]
  int y; // [esp+2Ch] [ebp-A0h]
  int v21; // [esp+30h] [ebp-9Ch]
  int x; // [esp+34h] [ebp-98h]
  int v23; // [esp+38h] [ebp-94h]
  int yAdd; // [esp+3Ch] [ebp-90h]
  vgui::Color color; // [esp+44h] [ebp-88h] BYREF
  int wide[4]; // [esp+50h] [ebp-7Ch] BYREF
  int a_0[4]; // [esp+60h] [ebp-6Ch] BYREF
  int b_0[4]; // [esp+70h] [ebp-5Ch] BYREF
  int c[4]; // [esp+80h] [ebp-4Ch] BYREF
  int tall; // [esp+90h] [ebp-3Ch] BYREF
  int r; // [esp+94h] [ebp-38h] BYREF
  int g; // [esp+98h] [ebp-34h] BYREF
  int b; // [esp+9Ch] [ebp-30h] BYREF
  int a; // [esp+A0h] [ebp-2Ch] BYREF
  int a_1; // [esp+A4h] [ebp-28h] BYREF
  int b_1; // [esp+A8h] [ebp-24h] BYREF
  int c_0[8]; // [esp+ACh] [ebp-20h] BYREF

  v2 = this;
  (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 2))(this, wide, &tall);
  if ( this->_text )
  {
    v3 = 0;
    vgui::Color::Color(&color);
    (*((void (__cdecl **)(vgui::TextImage *const, vgui::Color *))this->_vptr_Image + 4))(this, &color);
    vgui::Color::getColor(&color, &r, &g, &b, &a);
    (*((void (__cdecl **)(vgui::TextImage *const, int, int, int, int))this->_vptr_Image + 13))(this, r, g, b, a);
    v4 = (*((int (__cdecl **)(vgui::TextImage *const))this->_vptr_Image + 27))(this);
    (*((void (__cdecl **)(vgui::TextImage *const, int))this->_vptr_Image + 11))(this, v4);
    y = 0;
    x = 0;
    yAdd = (*(int (__cdecl **)(int))(*(_DWORD *)v4 + 16))(v4);
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = v2->_text[v3];
        (*(void (__cdecl **)(int, _DWORD, int *, int *, int *))(*(_DWORD *)v4 + 8))(v4, v5, a_0, b_0, c);
        if ( !v5 )
          return;
        if ( v5 != 13 )
          break;
LABEL_23:
        ++v3;
      }
      if ( v5 != 10 )
      {
        if ( v5 != 32 )
        {
          v6 = v2->_text;
          v7 = b_0[0] + a_0[0] + c[0];
          v8 = v6[v3 + 1];
          if ( !v8 || v8 == 10 || v8 == 32 || v8 == 13 )
          {
            v9 = 1;
            v23 = 0;
          }
          else
          {
            i = (int)v2;
            v9 = 1;
            v10 = b_0[0] + a_0[0] + c[0];
            do
            {
              ++v9;
              (*(void (__cdecl **)(int, _DWORD, int *, int *, int *))(*(_DWORD *)v4 + 8))(v4, v8, &a_1, &b_1, c_0);
              v10 += c_0[0] + b_1 + a_1;
              v6 = *(char **)(i + 36);
              v8 = v6[v9 + v3];
            }
            while ( v8 != 10 && v8 && v8 != 32 && v8 != 13 );
            v7 = v10;
            v2 = (vgui::TextImage *)i;
            v23 = v9 - 1;
          }
          if ( v7 + x > wide[0] )
          {
            y += yAdd;
            x = 0;
          }
          ia = v3;
          v11 = v2;
          v21 = v9;
          v12 = 0;
          v13 = v4;
          v14 = x;
          while ( 1 )
          {
            v15 = v6[ia + v12++];
            v17 = v13;
            (*(void (__cdecl **)(int, int, int *, int *, int *))(*(_DWORD *)v13 + 8))(v13, v15, a_0, b_0, c);
            (*((void (__cdecl **)(vgui::TextImage *, int, int, int))v11->_vptr_Image + 18))(v11, v14, y, v15);
            v13 = v17;
            v14 += c[0] + b_0[0] + a_0[0];
            if ( v21 <= v12 )
              break;
            v6 = v11->_text;
          }
          x = v14;
          v2 = v11;
          v4 = v17;
          v3 = v23 + ia;
          goto LABEL_23;
        }
        v16 = v2->_text[v3 + 1];
        (*(void (__cdecl **)(int, int, int *, int *, int *))(*(_DWORD *)v4 + 8))(v4, 32, a_0, b_0, c);
        switch ( v16 )
        {
          case 10:
            goto LABEL_23;
          case 0:
            goto LABEL_23;
          case 13:
            goto LABEL_23;
        }
        x += c[0] + b_0[0] + a_0[0];
        if ( x <= wide[0] )
          goto LABEL_23;
      }
      ++v3;
      y += yAdd;
      x = 0;
    }
  }
}

void vgui::TextImage::setText(vgui::TextImage *const this, const char *text)
{
  size_t v2; // eax

  v2 = strlen(text);
  (*((void (__cdecl **)(vgui::TextImage *const, size_t, const char *))this->_vptr_Image + 28))(this, v2 + 1, text);
}

void vgui::TextImage::setText(vgui::TextImage *const this, int textBufferLen, const char *text)
{
  int dstLen; // edx
  char *dst; // eax
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  dstLen = this->_textBufferLen;
  dst = this->_text;
  if ( dstLen < textBufferLen )
  {
    operator delete(this->_text);
    this->_textBufferLen = textBufferLen;
    dst = (char *)operator new[](textBufferLen);
    this->_text = dst;
    if ( !dst )
    {
      this->_textBufferLen = 0;
      goto LABEL_4;
    }
    dstLen = this->_textBufferLen;
    goto LABEL_3;
  }
  if ( dst )
LABEL_3:
    vgui::vgui_strcpy(dst, dstLen, text);
LABEL_4:
  (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 25))(this, &wide, tall);
  vgui::Image::setSize(this, wide, tall[0]);
}

void vgui::TextImage::TextImage(vgui::TextImage *const this, int textBufferLen, const char *text)
{
  int v4; // [esp+18h] [ebp-14h] BYREF
  int v5[4]; // [esp+1Ch] [ebp-10h] BYREF

  vgui::Image::Image(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::TextImage + 2);
  this->_schemeFont = sf_primary1;
  this->_text = 0;
  this->_font = 0;
  this->_textBufferLen = 0;
  vgui::TextImage::setText(this, text);
  (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 25))(this, &v4, v5);
  (*((void (__cdecl **)(vgui::TextImage *const, int, int))this->_vptr_Image + 5))(this, v4, v5[0]);
}

void vgui::TextImage::TextImage(vgui::TextImage *const this, const char *text)
{
  int v3; // [esp+18h] [ebp-14h] BYREF
  int v4[4]; // [esp+1Ch] [ebp-10h] BYREF

  vgui::Image::Image(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::TextImage + 2);
  this->_schemeFont = sf_primary1;
  this->_text = 0;
  this->_font = 0;
  this->_textBufferLen = 0;
  vgui::TextImage::setText(this, text);
  (*((void (__cdecl **)(vgui::TextImage *const, int *, int *))this->_vptr_Image + 25))(this, &v3, v4);
  (*((void (__cdecl **)(vgui::TextImage *const, int, int))this->_vptr_Image + 5))(this, v3, v4[0]);
}

