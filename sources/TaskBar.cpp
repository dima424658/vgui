#include <VGUI_TaskBar.h>

void vgui::TaskBar::performLayout(vgui::TaskBar *const this)
{
  int v1; // esi
  int v2; // edi
  vgui::Button *v3; // ebx
  int wide; // [esp+28h] [ebp-34h] BYREF
  int tall; // [esp+2Ch] [ebp-30h] BYREF
  int tWide; // [esp+30h] [ebp-2Ch] BYREF
  int tTall; // [esp+34h] [ebp-28h] BYREF
  int x; // [esp+38h] [ebp-24h] BYREF
  int y[8]; // [esp+3Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::TaskBar *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_tray->_vptr_Panel + 3))(this->_tray, &tWide, &tTall);
  (*((void (__cdecl **)(vgui::Panel *, int, int, int, int))this->_tray->_vptr_Panel + 4))(
    this->_tray,
    wide - tWide - 3,
    2,
    tWide,
    tall - 4);
  if ( this->_taskButtonDar._count > 0 )
  {
    v1 = 0;
    v2 = 3;
    do
    {
      v3 = this->_taskButtonDar._data[v1++];
      (*(void (__cdecl **)(vgui::Button *, int *, int *, int *, int *))(*(_DWORD *)v3->baseclass_0 + 20))(
        v3,
        &x,
        y,
        &wide,
        &tall);
      (**(void (__cdecl ***)(vgui::Button *, int, int))v3->baseclass_0)(v3, v2, y[0]);
      v2 += wide + 3;
    }
    while ( this->_taskButtonDar._count > v1 );
  }
}

void vgui::TaskBar::addFrame(vgui::TaskBar *const this, vgui::Frame *frame)
{
  int v2; // ecx
  vgui::Dar<vgui::Frame*> *v3; // ebp
  int v4; // edx
  int v5; // eax
  vgui::Frame **v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  vgui::Dar<vgui::Button*> *v9; // esi
  int v10; // ecx
  int v11; // ebp
  vgui::Button *v12; // edx
  int v13; // eax
  vgui::Button **v14; // eax
  int (**v15)(...); // eax
  unsigned int v16; // edi
  _BYTE *v17; // eax
  _WORD *v18; // edi
  int v19; // eax
  vgui::Button **v20; // eax
  unsigned int v21; // edi
  _BYTE *v22; // eax
  _WORD *v23; // edi
  int v24; // eax
  vgui::Button *button; // [esp+14h] [ebp-128h]
  vgui::Button *buttona; // [esp+14h] [ebp-128h]
  vgui::Button **v27; // [esp+18h] [ebp-124h]
  vgui::Frame **v28; // [esp+18h] [ebp-124h]
  unsigned int v29; // [esp+1Ch] [ebp-120h]
  unsigned int v30; // [esp+1Ch] [ebp-120h]
  char buf[256]; // [esp+20h] [ebp-11Ch] BYREF

  v2 = this->_frameDar._count;
  v3 = &this->_frameDar;
  v4 = this->_frameDar._capacity;
  v5 = v2 + 1;
  if ( v2 + 1 <= v4 )
  {
    v6 = this->_frameDar._data;
    goto LABEL_3;
  }
  if ( v4 || (v4 = 1, v21 = 4, v5 > 1) )
  {
    do
      v4 *= 2;
    while ( v5 > v4 );
    v21 = 4 * v4;
  }
  buttona = (vgui::Button *)v4;
  v22 = (_BYTE *)operator new[](v21);
  v28 = (vgui::Frame **)v22;
  if ( !v22 )
    goto LABEL_61;
  v30 = v21;
  v23 = v22;
  if ( v30 >= 8 )
  {
    if ( ((uint8_t)v22 & 1) != 0 )
    {
      *v22 = 0;
      --v30;
      v23 = v22 + 1;
    }
    if ( ((uint8_t)v23 & 2) != 0 )
    {
      *v23++ = 0;
      v30 -= 2;
    }
    if ( ((uint8_t)v23 & 4) != 0 )
    {
      *(_DWORD *)v23 = 0;
      v23 += 2;
      v30 -= 4;
    }
    memset(v23, 0, 4 * (v30 >> 2));
    v23 += 2 * (v30 >> 2);
    LOBYTE(v30) = v30 & 3;
    if ( (v30 & 4) == 0 )
    {
LABEL_28:
      if ( (v30 & 2) == 0 )
        goto LABEL_29;
LABEL_42:
      *v23++ = 0;
      if ( (v30 & 1) == 0 )
        goto LABEL_30;
      goto LABEL_41;
    }
  }
  else if ( (v30 & 4) == 0 )
  {
    goto LABEL_28;
  }
  *(_DWORD *)v23 = 0;
  v23 += 2;
  if ( (v30 & 2) != 0 )
    goto LABEL_42;
LABEL_29:
  if ( (v30 & 1) != 0 )
LABEL_41:
    *(_BYTE *)v23 = 0;
LABEL_30:
  v2 = this->_frameDar._count;
  this->_frameDar._capacity = (int)buttona;
  if ( v2 > 0 )
  {
    v24 = 0;
    do
    {
      v28[v24] = this->_frameDar._data[v24];
      ++v24;
      v2 = v3->_count;
    }
    while ( v24 < v3->_count );
  }
  if ( this->_frameDar._data )
  {
    operator delete[]((VFontData *const)this->_frameDar._data);
    v2 = this->_frameDar._count;
  }
  v6 = v28;
  this->_frameDar._data = v28;
LABEL_3:
  v6[v2] = frame;
  ++this->_frameDar._count;
  (*((void (__cdecl **)(vgui::Frame *, char *, int))frame->_vptr_Panel + 131))(frame, buf, 256);
  button = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(button, buf, 2, 2);
  v7 = operator new(0x14u);
  *v7 = &off_48968;
  v8 = v7;
  v7[1] = &off_48980;
  v7[2] = &off_48990;
  v7[4] = frame;
  v7[3] = button;
  (*(void (__cdecl **)(vgui::Button *, vgui::TaskBar *const))(*(_DWORD *)button->baseclass_0 + 64))(button, this);
  (*(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)button->baseclass_0 + 576))(button, v8);
  (*((void (__cdecl **)(vgui::Frame *, _DWORD *))frame->_vptr_Panel + 136))(frame, v8 + 1);
  v9 = &this->_taskButtonDar;
  (*((void (__cdecl **)(vgui::Frame *, _DWORD *))frame->_vptr_Panel + 50))(frame, v8 + 2);
  v10 = this->_taskButtonDar._count;
  v11 = this->_taskButtonDar._capacity;
  v12 = button;
  v13 = v10 + 1;
  if ( v10 + 1 <= v11 )
  {
    v14 = this->_taskButtonDar._data;
    goto LABEL_5;
  }
  if ( v11 || (v11 = 1, v16 = 4, v13 > 1) )
  {
    do
      v11 *= 2;
    while ( v13 > v11 );
    v16 = 4 * v11;
  }
  v17 = (_BYTE *)operator new[](v16);
  v12 = button;
  v27 = (vgui::Button **)v17;
  if ( !v17 )
LABEL_61:
    exit(0);
  v29 = v16;
  v18 = v17;
  if ( v29 >= 8 )
  {
    if ( ((uint8_t)v17 & 1) != 0 )
    {
      *v17 = 0;
      --v29;
      v18 = v17 + 1;
    }
    if ( ((uint8_t)v18 & 2) != 0 )
    {
      *v18++ = 0;
      v29 -= 2;
    }
    if ( ((uint8_t)v18 & 4) != 0 )
    {
      *(_DWORD *)v18 = 0;
      v18 += 2;
      v29 -= 4;
    }
    memset(v18, 0, 4 * (v29 >> 2));
    v18 += 2 * (v29 >> 2);
    LOBYTE(v29) = v29 & 3;
  }
  if ( (v29 & 4) == 0 )
  {
    if ( (v29 & 2) == 0 )
      goto LABEL_14;
LABEL_37:
    *v18++ = 0;
    if ( (v29 & 1) == 0 )
      goto LABEL_15;
    goto LABEL_36;
  }
  *(_DWORD *)v18 = 0;
  v18 += 2;
  if ( (v29 & 2) != 0 )
    goto LABEL_37;
LABEL_14:
  if ( (v29 & 1) != 0 )
LABEL_36:
    *(_BYTE *)v18 = 0;
LABEL_15:
  v10 = this->_taskButtonDar._count;
  this->_taskButtonDar._capacity = v11;
  if ( v10 > 0 )
  {
    v19 = 0;
    do
    {
      v27[v19] = this->_taskButtonDar._data[v19];
      ++v19;
      v10 = v9->_count;
    }
    while ( v19 < v9->_count );
  }
  v20 = this->_taskButtonDar._data;
  if ( v20 )
  {
    operator delete[]((VFontData *const)v20);
    v10 = this->_taskButtonDar._count;
    v12 = button;
  }
  v14 = v27;
  this->_taskButtonDar._data = v27;
LABEL_5:
  v14[v10] = v12;
  v15 = this->_vptr_Panel;
  ++this->_taskButtonDar._count;
  v15[46](this, 0);
}

void vgui::TaskBar::TaskBar(vgui::TaskBar *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::Frame **v8; // edx
  vgui::Button **v9; // eax
  vgui::Button **v10; // edi
  int v11; // edx
  vgui::RaisedBorder *border; // esi
  vgui::Panel *v13; // esi
  void (__cdecl *v14)(vgui::Panel *, vgui::LoweredBorder *); // esi
  vgui::LoweredBorder *v15; // edi
  vgui::Panel *v16; // esi
  vgui::App *v17; // eax
  int v18; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_frameDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TaskBar + 2);
  this->_frameDar._count = 0;
  this->_frameDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    goto LABEL_14;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_frameDar._count;
  this->_frameDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_frameDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_frameDar._count );
  }
  v8 = this->_frameDar._data;
  if ( v8 )
  {
    v18 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v18;
  }
  this->_taskButtonDar._data = 0;
  this->_frameDar._data = (vgui::Frame **)v5;
  this->_taskButtonDar._count = 0;
  this->_taskButtonDar._capacity = 0;
  v9 = (vgui::Button **)operator new[](0x10u);
  v10 = v9;
  if ( !v9 )
LABEL_14:
    exit(0);
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  this->_taskButtonDar._capacity = 4;
  if ( this->_taskButtonDar._count > 0 )
  {
    v11 = 0;
    do
    {
      v9[v11] = this->_taskButtonDar._data[v11];
      ++v11;
    }
    while ( v11 < this->_taskButtonDar._count );
  }
  if ( this->_taskButtonDar._data )
    operator delete[]((VFontData *const)this->_taskButtonDar._data);
  this->_taskButtonDar._data = v10;
  border = (vgui::RaisedBorder *)operator new(0x38u);
  vgui::RaisedBorder::RaisedBorder(border);
  vgui::Panel::setBorder(this, border);
  v13 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v13, 100, 0, 120, 26);
  this->_tray = v13;
  v14 = (void (__cdecl *)(vgui::Panel *, vgui::LoweredBorder *))*((_DWORD *)v13->_vptr_Panel + 53);
  v15 = (vgui::LoweredBorder *)operator new(0x38u);
  vgui::LoweredBorder::LoweredBorder(v15);
  v14(this->_tray, v15);
  (*((void (__cdecl **)(vgui::Panel *, vgui::TaskBar *const))this->_tray->_vptr_Panel + 16))(this->_tray, this);
  v16 = (vgui::Panel *)operator new(0xCCu);
  vgui::Panel::Panel(v16, 25, 2, 85, 20);
  v16[1]._vptr_Panel = (int (**)(...))&off_48950;
  v16[1]._pos[0] = 0;
  v16[1]._pos[1] = 0;
  v16->_vptr_Panel = (int (**)(...))&off_48748;
  v16[1]._size[0] = 0;
  v17 = vgui::Panel::getApp(v16);
  (*((void (__cdecl **)(vgui::App *, vgui::Panel *))v17->_vptr_App + 11))(v17, v16 + 1);
  (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))v16->_vptr_Panel + 16))(v16, this->_tray);
}

