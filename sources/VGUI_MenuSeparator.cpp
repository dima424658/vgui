#include <VGUI_MenuSeparator.h>

void vgui::MenuSeparator::paintBackground(vgui::MenuSeparator *const this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // ebp
  int x0; // [esp+2Ch] [ebp-30h]
  int textWide; // [esp+30h] [ebp-2Ch] BYREF
  int wide; // [esp+34h] [ebp-28h] BYREF
  int tall; // [esp+38h] [ebp-24h] BYREF
  int textTall[8]; // [esp+3Ch] [ebp-20h] BYREF

  (*(void (__cdecl **)(vgui::MenuSeparator *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 232))(
    this,
    &wide,
    &tall);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 8);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    0,
    0,
    wide,
    tall);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 528))(
    this,
    &textWide,
    textTall);
  v2 = textWide;
  if ( textWide > 0 )
  {
    v2 = textWide + 4;
    textWide += 4;
  }
  v3 = v2 / 2;
  v4 = wide / 2 + v3;
  x0 = wide / 2 - v3;
  v5 = textTall[0] / 2;
  v6 = textTall[0] / 2 - 1;
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 6);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    2,
    v6,
    x0,
    v5);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    v4,
    v6,
    wide - 2,
    v5);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 2);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    2,
    v5,
    x0,
    v5 + 1);
  (*(void (__cdecl **)(vgui::MenuSeparator *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
    this,
    v4,
    v5,
    wide - 2,
    v5 + 1);
}

void vgui::MenuSeparator::MenuSeparator(vgui::MenuSeparator *const this, const char *text)
{
  vgui::Label::Label(this, text);
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::MenuSeparator + 2;
  vgui::Label::setFont(this, sf_primary3);
}

