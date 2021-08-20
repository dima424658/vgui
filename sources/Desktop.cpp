#include <VGUI_Desktop.h>

void vgui::Desktop::iconActivated(vgui::Desktop *const this, vgui::DesktopIcon *icon)
{
  int v2; // eax
  void (__cdecl ***v3)(_DWORD, int, int); // eax
  void (__cdecl ***v4)(_DWORD, int, int); // esi
  int v5; // eax

  v2 = (*((int (__cdecl **)(vgui::DesktopIcon *))icon->_vptr_Panel + 130))(icon);
  v3 = (void (__cdecl ***)(_DWORD, int, int))(*(int (__cdecl **)(int))(*(_DWORD *)v2 + 4))(v2);
  v4 = v3;
  if ( v3 )
  {
    (**v3)(v3, this->_cascade[0], this->_cascade[1]);
    ((void (__cdecl *)(void (__cdecl ***)(_DWORD, int, int), vgui::Panel *))(*v4)[16])(v4, this->_foreground);
    (*((void (__cdecl **)(vgui::TaskBar *, void (__cdecl ***)(_DWORD, int, int)))this->_taskBar->_vptr_Panel + 127))(
      this->_taskBar,
      v4);
    ((void (__cdecl *)(void (__cdecl ***)(_DWORD, int, int)))(*v4)[41])(v4);
    v5 = this->_cascade[1];
    this->_cascade[0] += 25;
    v5 += 50;
    this->_cascade[1] = v5;
    if ( v5 > 400 )
    {
      this->_cascade[0] = 50;
      this->_cascade[1] = 50;
    }
  }
}

void vgui::Desktop::arrangeIcons(vgui::Desktop *const this)
{
  int v1; // esi
  int v2; // ebx
  int v3; // ebp
  int v4; // [esp+8h] [ebp-24h]

  if ( this->_desktopIconDar._count > 0 )
  {
    v1 = 0;
    v2 = 10;
    v3 = 15;
    do
    {
      v4 = v2;
      v2 += 60;
      (*this->_desktopIconDar._data[v1]->_vptr_Panel)(this->_desktopIconDar._data[v1], v3, v4);
      if ( v2 > 340 )
      {
        v3 += 50;
        v2 = 10;
      }
      ++v1;
    }
    while ( this->_desktopIconDar._count > v1 );
  }
}

void vgui::Desktop::setSize(vgui::Desktop *const this, int wide, int tall)
{
  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::Desktop *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, _DWORD, int, int))this->_background->_vptr_Panel + 4))(
    this->_background,
    0,
    0,
    wide,
    tall - 36);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, _DWORD, int, int))this->_foreground->_vptr_Panel + 4))(
    this->_foreground,
    0,
    0,
    wide,
    tall - 36);
  (*((void (__cdecl **)(vgui::TaskBar *, _DWORD, int, int, int))this->_taskBar->_vptr_Panel + 4))(
    this->_taskBar,
    0,
    tall - 36,
    wide,
    36);
}

void vgui::Desktop::addIcon(vgui::Desktop *const this, vgui::DesktopIcon *icon)
{
  vgui::Dar<vgui::DesktopIcon*> *v3; // ebx
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  vgui::DesktopIcon **v7; // eax
  unsigned int v8; // edi
  _BYTE *v9; // eax
  _WORD *v10; // edi
  int v11; // eax
  int v12; // [esp+14h] [ebp-28h]
  vgui::DesktopIcon **v13; // [esp+18h] [ebp-24h]
  unsigned int v14; // [esp+1Ch] [ebp-20h]

  (*((void (__cdecl **)(vgui::DesktopIcon *, vgui::Desktop *const))icon->_vptr_Panel + 129))(icon, this);
  (*((void (__cdecl **)(vgui::DesktopIcon *, vgui::Panel *))icon->_vptr_Panel + 16))(icon, this->_foreground);
  v3 = &this->_desktopIconDar;
  (*icon->_vptr_Panel)(icon, 10, 10);
  v4 = this->_desktopIconDar._count;
  v5 = this->_desktopIconDar._capacity;
  v6 = v4 + 1;
  if ( v4 + 1 <= v5 )
  {
    v7 = this->_desktopIconDar._data;
    goto LABEL_3;
  }
  if ( v5 || (v5 = 1, v8 = 4, v6 > 1) )
  {
    do
      v5 *= 2;
    while ( v6 > v5 );
    v8 = 4 * v5;
  }
  v12 = v5;
  v9 = (_BYTE *)operator new[](v8);
  v13 = (vgui::DesktopIcon **)v9;
  if ( !v9 )
    exit(0);
  v14 = v8;
  v10 = v9;
  if ( v14 >= 8 )
  {
    if ( ((uint8_t)v9 & 1) != 0 )
    {
      *v9 = 0;
      --v14;
      v10 = v9 + 1;
    }
    if ( ((uint8_t)v10 & 2) != 0 )
    {
      *v10++ = 0;
      v14 -= 2;
    }
    if ( ((uint8_t)v10 & 4) != 0 )
    {
      *(_DWORD *)v10 = 0;
      v10 += 2;
      v14 -= 4;
    }
    memset(v10, 0, 4 * (v14 >> 2));
    v10 += 2 * (v14 >> 2);
    LOBYTE(v14) = v14 & 3;
  }
  if ( (v14 & 4) == 0 )
  {
    if ( (v14 & 2) == 0 )
      goto LABEL_12;
LABEL_20:
    *v10++ = 0;
    if ( (v14 & 1) == 0 )
      goto LABEL_13;
    goto LABEL_19;
  }
  *(_DWORD *)v10 = 0;
  v10 += 2;
  if ( (v14 & 2) != 0 )
    goto LABEL_20;
LABEL_12:
  if ( (v14 & 1) != 0 )
LABEL_19:
    *(_BYTE *)v10 = 0;
LABEL_13:
  v4 = this->_desktopIconDar._count;
  this->_desktopIconDar._capacity = v12;
  if ( v4 > 0 )
  {
    v11 = 0;
    do
    {
      v13[v11] = this->_desktopIconDar._data[v11];
      ++v11;
      v4 = v3->_count;
    }
    while ( v11 < v3->_count );
  }
  if ( this->_desktopIconDar._data )
  {
    operator delete[](this->_desktopIconDar._data);
    v4 = this->_desktopIconDar._count;
  }
  v7 = v13;
  this->_desktopIconDar._data = v13;
LABEL_3:
  v7[v4] = icon;
  ++this->_desktopIconDar._count;
}

void vgui::Desktop::Desktop(vgui::Desktop *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::DesktopIcon **v8; // edx
  vgui::Panel *v9; // esi
  vgui::Panel *v10; // esi
  vgui::TaskBar *v11; // esi
  int v12; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_desktopIconDar._count = 0;
  this->_desktopIconDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Desktop + 2);
  this->_desktopIconDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    exit(0);
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_desktopIconDar._count;
  this->_desktopIconDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_desktopIconDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_desktopIconDar._count );
  }
  v8 = this->_desktopIconDar._data;
  if ( v8 )
  {
    v12 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v12;
  }
  this->_desktopIconDar._data = (vgui::DesktopIcon **)v5;
  vgui::Panel::setBgColor(this, 0, 128, 128, 0);
  vgui::Panel::setPaintBorderEnabled(this, 0);
  vgui::Panel::setPaintBackgroundEnabled(this, 0);
  vgui::Panel::setPaintEnabled(this, 0);
  v9 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v9, 0, 0, wide, tall - 36);
  this->_background = v9;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Desktop *const))v9->_vptr_Panel + 16))(v9, this);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, int, int, _DWORD))this->_background->_vptr_Panel + 74))(
    this->_background,
    0,
    128,
    128,
    0);
  v10 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v10, 0, 0, wide, tall - 36);
  this->_foreground = v10;
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))v10->_vptr_Panel + 54))(v10, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_foreground->_vptr_Panel + 55))(this->_foreground, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_foreground->_vptr_Panel + 56))(this->_foreground, 0);
  (*((void (__cdecl **)(vgui::Panel *, vgui::Desktop *const))this->_foreground->_vptr_Panel + 16))(
    this->_foreground,
    this);
  v11 = (vgui::TaskBar *)operator new(0xD8u);
  vgui::TaskBar::TaskBar(v11, 0, tall - 36, wide, 36);
  this->_taskBar = v11;
  (*((void (__cdecl **)(vgui::TaskBar *, vgui::Desktop *const))v11->_vptr_Panel + 16))(v11, this);
  this->_cascade[0] = 50;
  this->_cascade[1] = 50;
}

