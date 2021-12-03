#include <VGUI_TextImage.h>

#include <VGUI_Font.h>

void vgui::TextImage::init(int textBufferLen, const char* text)
{
  int wide, tall;

  _text = nullptr;
  _textBufferLen = 0;
  _schemeFont = vgui::Scheme::SchemeFont::sf_primary1;
  _font = nullptr;

  setText(text);
  getTextSize(wide, tall);
  setSize(wide, tall);
}

void vgui::TextImage::setFont(vgui::Scheme::SchemeFont schemeFont)
{
  _schemeFont = schemeFont;
}

void vgui::TextImage::setFont(vgui::Font* font)
{
  _font = font;
}

void vgui::TextImage::getTextSizeWrapped(int& wideo, int& tallo)
{
  int i, j;
  int x = 0, y = 0;
  int y, yAdd;
  int wide, tall;
  int a, a_0;
  int b, b_0;
  int c, c_0;

  wideo = 0;
  tallo = 0;

  if (!_text)
    return;

  getSize(wide, tall);
  auto v3 = getFont();

  yAdd = v3->getTall();

  for (j = 0; j < strlen(_text); ++j)
  {
    while (true)
    {
      v3->getCharABCwide(_text[j], a, b, c);

      if (_text[j] != '\r')
        break;
      ++j;
    }

    if (_text[j] != '\n')
    {
      auto v6 = 0;
      auto v9 = 1;
      if (_text[j] != 32)
      {
        v6 = b + a + c;

        v8 = _text[j + 1];
        if (!v8 || v8 == '\n' || v8 == '\r' || v8 == 32)
        {
          v25 = 0;
          v11 = &_text[j];
        }
        else
        {
          auto v10 = b + a + c;
          do
          {
            ++v9;
            (*(void(__cdecl**)(int, _DWORD, int*, int*, int*))(*(_DWORD*)v3 + 8))(v3, v8, &a_0, &b_0, c_0);
            v10 += c_0[0] + b_0 + a_0;
            v11 = &_text[j];
            v8 = v11[v9];
          } while (v8 != 10 && v8 && v8 != 32 && v8 != 13);
          v6 = v10;
          v25 = v9 - 1;
        }

        if (v6 + x > wide)
        {
          y += yAdd;
          x = 0;
        }

        i = j;
        v12 = x;
        v22 = v9;
        v13 = 0;
        v14 = tallo;
        while (1)
        {
          v19 = v14;
          (*(void(__cdecl**)(int, _DWORD, int*, int*, int*))(*(_DWORD*)v3 + 8))(v3, v11[v13], a, b, c);
          v15 = a;
          v16 = c + b + v12 + a;
          if (v16 < wideo)
            v16 = wideo;
          wideo = v16;
          v14 = v19;
          v17 = *v19;
          if (yAdd + y >= *v19)
            v17 = yAdd + y;
          ++v13;
          *v19 = v17;
          v12 += c + b + v15;
          if (v22 <= v13)
            break;
          v11 = &_text[i];
        }
        x = v12;
        j = v25 + i;
        goto LABEL_27;
      }
      v3->getCharABCwide(32, a, b, c);
      switch (_text[j + 1])
      {
      case 10:
        continue;
      case 0:
        continue;
      case 13:
        continue;
      }

      x += c + b + a;
      if (x <= wide)
        continue;
    }
    y += yAdd;
    x = 0;
  }
}

void vgui::TextImage::getTextSize(int& wide, int& tall)
{
  wide = 0, tall = 0;

  if (_text && getFont())
    getFont()->getTextSize(_text, wide, tall);
}

void vgui::TextImage::paint(vgui::Panel* panel)
{
  vgui::TextImage* v2; // edi
  int v3; // ebp
  int v4; // esi
  char v5; // bl
  char* v6; // edx
  int v7; // ecx
  char v8; // al
  int v9; // ebx
  int v10; // edi
  vgui::TextImage* v11; // ebp
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
  (*((void(__cdecl**)(vgui::TextImage* const, int*, int*))_vptr_Image + 2))(this, wide, &tall);
  if (_text)
  {
    v3 = 0;
    vgui::Color::Color(&color);
    (*((void(__cdecl**)(vgui::TextImage* const, vgui::Color*))_vptr_Image + 4))(this, &color);
    vgui::Color::getColor(&color, &r, &g, &b, &a);
    (*((void(__cdecl**)(vgui::TextImage* const, int, int, int, int))_vptr_Image + 13))(this, r, g, b, a);
    v4 = (*((int(__cdecl**)(vgui::TextImage* const))_vptr_Image + 27))(this);
    (*((void(__cdecl**)(vgui::TextImage* const, int))_vptr_Image + 11))(this, v4);
    y = 0;
    x = 0;
    yAdd = (*(int(__cdecl**)(int))(*(_DWORD*)v4 + 16))(v4);
    while (1)
    {
      while (1)
      {
        v5 = v2->_text[v3];
        (*(void(__cdecl**)(int, _DWORD, int*, int*, int*))(*(_DWORD*)v4 + 8))(v4, v5, a_0, b_0, c);
        if (!v5)
          return;
        if (v5 != 13)
          break;
      LABEL_23:
        ++v3;
      }
      if (v5 != 10)
      {
        if (v5 != 32)
        {
          v6 = v2->_text;
          v7 = b_0[0] + a_0[0] + c[0];
          v8 = v6[v3 + 1];
          if (!v8 || v8 == 10 || v8 == 32 || v8 == 13)
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
              (*(void(__cdecl**)(int, _DWORD, int*, int*, int*))(*(_DWORD*)v4 + 8))(v4, v8, &a_1, &b_1, c_0);
              v10 += c_0[0] + b_1 + a_1;
              v6 = *(char**)(i + 36);
              v8 = v6[v9 + v3];
            } while (v8 != 10 && v8 && v8 != 32 && v8 != 13);
            v7 = v10;
            v2 = (vgui::TextImage*)i;
            v23 = v9 - 1;
          }
          if (v7 + x > wide[0])
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
          while (1)
          {
            v15 = v6[ia + v12++];
            v17 = v13;
            (*(void(__cdecl**)(int, int, int*, int*, int*))(*(_DWORD*)v13 + 8))(v13, v15, a_0, b_0, c);
            (*((void(__cdecl**)(vgui::TextImage*, int, int, int))v11->_vptr_Image + 18))(v11, v14, y, v15);
            v13 = v17;
            v14 += c[0] + b_0[0] + a_0[0];
            if (v21 <= v12)
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
        (*(void(__cdecl**)(int, int, int*, int*, int*))(*(_DWORD*)v4 + 8))(v4, 32, a_0, b_0, c);
        switch (v16)
        {
        case 10:
          goto LABEL_23;
        case 0:
          goto LABEL_23;
        case 13:
          goto LABEL_23;
        }
        x += c[0] + b_0[0] + a_0[0];
        if (x <= wide[0])
          goto LABEL_23;
      }
      ++v3;
      y += yAdd;
      x = 0;
    }
  }
}

void vgui::TextImage::setText(const char* text)
{
  setText(std::strlen(text) + 1, text);
}

void vgui::TextImage::setText(int textBufferLen, const char* text)
{
  int dstLen;
  char* dst;
  int wide, tall;

  dstLen = _textBufferLen;
  dst = _text;
  if (dstLen < textBufferLen)
  {
    delete [] _text;
    _textBufferLen = textBufferLen;
    dst = new char[textBufferLen];
    _text = dst;

    if (!dst)
      _textBufferLen = 0;

    dstLen = _textBufferLen;
  }

  if (dst)
    vgui::vgui_strcpy(dst, dstLen, text);

  getTextSize(wide, tall);
  setSize(wide, tall);
}

vgui::TextImage::TextImage(int textBufferLen, const char* text)
{
  init(textBufferLen, text);
}

vgui::TextImage::TextImage(const char* text)
{
  init(0, text);
}

