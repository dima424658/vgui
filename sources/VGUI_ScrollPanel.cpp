#include <VGUI_ScrollPanel.h>

void vgui::ScrollPanel::setScrollBarVisible(vgui::ScrollPanel *const this, bool horizontal, bool vertical)
{
  (*((void (__cdecl **)(vgui::ScrollBar *, bool))this->_horizontalScrollBar->_vptr_Panel + 9))(
    this->_horizontalScrollBar,
    horizontal);
  (*((void (__cdecl **)(vgui::ScrollBar *, bool))this->_verticalScrollBar->_vptr_Panel + 9))(
    this->_verticalScrollBar,
    vertical);
  (*((void (__cdecl **)(vgui::ScrollPanel *const))this->_vptr_Panel + 136))(this);
}

void vgui::ScrollPanel::setScrollValue(vgui::ScrollPanel *const this, int horizontal, int vertical)
{
  (*((void (__cdecl **)(vgui::ScrollBar *, int))this->_horizontalScrollBar->_vptr_Panel + 127))(
    this->_horizontalScrollBar,
    horizontal);
  (*((void (__cdecl **)(vgui::ScrollBar *, int))this->_verticalScrollBar->_vptr_Panel + 127))(
    this->_verticalScrollBar,
    vertical);
  (*((void (__cdecl **)(vgui::ScrollPanel *const))this->_vptr_Panel + 137))(this);
}

void vgui::ScrollPanel::getScrollValue(vgui::ScrollPanel *const this, int *const horizontal, int *const vertical)
{
  *horizontal = (*((int (__cdecl **)(vgui::ScrollBar *))this->_horizontalScrollBar->_vptr_Panel + 128))(this->_horizontalScrollBar);
  *vertical = (*((int (__cdecl **)(vgui::ScrollBar *))this->_verticalScrollBar->_vptr_Panel + 128))(this->_verticalScrollBar);
}

void vgui::ScrollPanel::recomputeScroll(vgui::ScrollPanel *const this)
{
  int x; // [esp+18h] [ebp-14h] BYREF
  int y[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::ScrollPanel *const, int *, int *))this->_vptr_Panel + 132))(this, &x, y);
  (*this->_client->_vptr_Panel)(this->_client, -x, -y[0]);
  (*((void (__cdecl **)(vgui::Panel *))this->_clientClip->_vptr_Panel + 12))(this->_clientClip);
}

void vgui::ScrollPanel::setScrollBarAutoVisible(vgui::ScrollPanel *const this, bool horizontal, bool vertical)
{
  this->_autoVisible[0] = horizontal;
  this->_autoVisible[1] = vertical;
  (*((void (**)(void))this->_vptr_Panel + 136))();
}

void vgui::ScrollPanel::recomputeClientSize(vgui::ScrollPanel *const this)
{
  int v1; // ebp
  int v2; // ebx
  bool v3; // cc
  vgui::Panel *v4; // eax
  int (**v5)(...); // edx
  int v6; // esi
  int v7; // edx
  int v8; // eax
  void (__cdecl *v9)(vgui::ScrollBar *, _DWORD, int); // ebx
  int v10; // esi
  int v11; // eax
  void (__cdecl *v12)(vgui::ScrollBar *, int); // ebx
  int v13; // eax
  void (__cdecl *v14)(vgui::ScrollBar *, _DWORD, int); // ebx
  int v15; // esi
  int v16; // eax
  void (__cdecl *v17)(vgui::ScrollBar *, int); // ebx
  int v18; // eax
  int wide; // [esp+1Ch] [ebp-30h]
  int x; // [esp+20h] [ebp-2Ch] BYREF
  int y; // [esp+24h] [ebp-28h] BYREF
  int w; // [esp+28h] [ebp-24h] BYREF
  int t[8]; // [esp+2Ch] [ebp-20h] BYREF

  v1 = 0;
  v2 = 0;
  wide = 0;
  while ( 1 )
  {
    v3 = v2 < (*((int (__cdecl **)(vgui::Panel *))this->_client->_vptr_Panel + 43))(this->_client);
    v4 = this->_client;
    v5 = v4->_vptr_Panel;
    if ( !v3 )
      break;
    v6 = v5[44](v4, v2);
    if ( (*(uint8_t (__cdecl **)(int))(*(_DWORD *)v6 + 40))(v6) )
    {
      (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v6 + 4))(v6, &x, &y);
      (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v6 + 336))(v6, &w, t);
      v7 = w + x;
      x = v7;
      v8 = t[0] + y;
      y += t[0];
      if ( wide >= v7 )
        v7 = wide;
      if ( v1 < v8 )
        v1 = v8;
      ++v2;
      wide = v7;
    }
    else
    {
      ++v2;
    }
  }
  v5[2](v4, wide, v1);
  v9 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD, int))*((_DWORD *)this->_horizontalScrollBar->_vptr_Panel + 130);
  v10 = (*((int (__cdecl **)(vgui::Panel *))this->_client->_vptr_Panel + 6))(this->_client);
  v11 = (*((int (__cdecl **)(vgui::Panel *))this->_clientClip->_vptr_Panel + 6))(this->_clientClip);
  v9(this->_horizontalScrollBar, 0, v10 - v11);
  v12 = (void (__cdecl *)(vgui::ScrollBar *, int))*((_DWORD *)this->_horizontalScrollBar->_vptr_Panel + 131);
  v13 = (*((int (__cdecl **)(vgui::Panel *))this->_client->_vptr_Panel + 6))(this->_client);
  v12(this->_horizontalScrollBar, v13);
  v14 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD, int))*((_DWORD *)this->_verticalScrollBar->_vptr_Panel + 130);
  v15 = (*((int (__cdecl **)(vgui::Panel *))this->_client->_vptr_Panel + 7))(this->_client);
  v16 = (*((int (__cdecl **)(vgui::Panel *))this->_clientClip->_vptr_Panel + 7))(this->_clientClip);
  v14(this->_verticalScrollBar, 0, v15 - v16);
  v17 = (void (__cdecl *)(vgui::ScrollBar *, int))*((_DWORD *)this->_verticalScrollBar->_vptr_Panel + 131);
  v18 = (*((int (__cdecl **)(vgui::Panel *))this->_client->_vptr_Panel + 7))(this->_client);
  v17(this->_verticalScrollBar, v18);
}

void vgui::ScrollPanel::validate(vgui::ScrollPanel *const this)
{
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::ScrollBar *, int))this->_horizontalScrollBar->_vptr_Panel + 132))(
    this->_horizontalScrollBar,
    1);
  (*((void (__cdecl **)(vgui::ScrollBar *, int))this->_verticalScrollBar->_vptr_Panel + 132))(
    this->_verticalScrollBar,
    1);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int *, int *))this->_vptr_Panel + 3))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
}

void vgui::ScrollPanel::setSize(vgui::ScrollPanel *const this, int wide, int tall)
{
  char v3; // al
  int v4; // esi
  vgui::ScrollBar *v5; // edx
  void (__cdecl *v6)(vgui::ScrollBar *, int, _DWORD, int, int); // edi
  int v7; // eax
  vgui::ScrollBar *v8; // edx
  void (__cdecl *v9)(vgui::ScrollBar *, _DWORD, int, int, int); // esi
  int v10; // eax
  int v11; // esi
  vgui::ScrollBar *v12; // edx
  void (__cdecl *v13)(vgui::ScrollBar *, int); // esi
  uint8_t v14; // al
  vgui::ScrollBar *v15; // edx
  void (__cdecl *v16)(vgui::ScrollBar *, int); // esi
  uint8_t v17; // al

  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::ScrollPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  if ( this->_autoVisible[0] )
  {
    v15 = this->_horizontalScrollBar;
    v16 = (void (__cdecl *)(vgui::ScrollBar *, int))*((_DWORD *)v15->_vptr_Panel + 9);
    v17 = (*((int (__cdecl **)(vgui::ScrollBar *))v15->_vptr_Panel + 134))(v15);
    v16(this->_horizontalScrollBar, v17 ^ 1);
  }
  if ( this->_autoVisible[1] )
  {
    v12 = this->_verticalScrollBar;
    v13 = (void (__cdecl *)(vgui::ScrollBar *, int))*((_DWORD *)v12->_vptr_Panel + 9);
    v14 = (*((int (__cdecl **)(vgui::ScrollBar *))v12->_vptr_Panel + 134))(v12);
    v13(this->_verticalScrollBar, v14 ^ 1);
  }
  if ( (*((uint8_t (__cdecl **)(vgui::ScrollBar *))this->_verticalScrollBar->_vptr_Panel + 10))(this->_verticalScrollBar) )
  {
    v11 = wide;
    wide = v11
         - (*((int (__cdecl **)(vgui::ScrollBar *))this->_verticalScrollBar->_vptr_Panel + 6))(this->_verticalScrollBar);
  }
  v3 = (*((int (__cdecl **)(vgui::ScrollBar *))this->_horizontalScrollBar->_vptr_Panel + 10))(this->_horizontalScrollBar);
  v4 = tall;
  if ( v3 )
  {
    v4 -= (*((int (__cdecl **)(vgui::ScrollBar *))this->_horizontalScrollBar->_vptr_Panel + 7))(this->_horizontalScrollBar);
    tall = v4;
  }
  v5 = this->_verticalScrollBar;
  v6 = (void (__cdecl *)(vgui::ScrollBar *, int, _DWORD, int, int))*((_DWORD *)v5->_vptr_Panel + 4);
  v7 = (*((int (__cdecl **)(vgui::ScrollBar *))v5->_vptr_Panel + 6))(v5);
  v6(this->_verticalScrollBar, wide, 0, v7, v4);
  v8 = this->_horizontalScrollBar;
  v9 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD, int, int, int))*((_DWORD *)v8->_vptr_Panel + 4);
  v10 = (*((int (__cdecl **)(vgui::ScrollBar *))v8->_vptr_Panel + 7))(v8);
  v9(this->_horizontalScrollBar, 0, tall, wide, v10);
  (*((void (__cdecl **)(vgui::Panel *, int, int))this->_clientClip->_vptr_Panel + 2))(this->_clientClip, wide, tall);
  (*((void (__cdecl **)(vgui::ScrollPanel *const))this->_vptr_Panel + 133))(this);
  (*((void (__cdecl **)(vgui::ScrollPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::ScrollPanel::ScrollPanel(vgui::ScrollPanel *const this, int x, int y, int wide, int tall)
{
  vgui::Panel *v6; // ecx
  vgui::ScrollBar *v7; // ebp
  void (__cdecl *v8)(vgui::ScrollBar *, _DWORD *); // ebp
  _DWORD *v9; // eax
  vgui::ScrollBar *v10; // ebp
  void (__cdecl *v11)(vgui::ScrollBar *, _DWORD *); // esi
  _DWORD *v12; // eax
  vgui::Panel *v13; // [esp+28h] [ebp-34h]
  vgui::Panel *v14; // [esp+28h] [ebp-34h]
  void (__cdecl *v15)(vgui::Panel *, vgui::Color *); // [esp+2Ch] [ebp-30h]
  vgui::Color v16; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ScrollPanel + 2);
  vgui::Panel::setPaintBorderEnabled(this, 1);
  vgui::Panel::setPaintBackgroundEnabled(this, 0);
  vgui::Panel::setPaintEnabled(this, 0);
  v13 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v13, 0, 0, wide - 16, tall - 16);
  this->_clientClip = v13;
  (*((void (__cdecl **)(vgui::Panel *, vgui::ScrollPanel *const))v13->_vptr_Panel + 16))(v13, this);
  v15 = (void (__cdecl *)(vgui::Panel *, vgui::Color *))*((_DWORD *)this->_clientClip->_vptr_Panel + 77);
  vgui::Color::Color(&v16, 0, 128, 0, 0);
  v15(this->_clientClip, &v16);
  (*((void (__cdecl **)(vgui::Panel *, int))this->_clientClip->_vptr_Panel + 54))(this->_clientClip, 1);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_clientClip->_vptr_Panel + 55))(this->_clientClip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_clientClip->_vptr_Panel + 56))(this->_clientClip, 0);
  v14 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v14, 0, 0, 2 * wide, 2 * tall);
  v6 = this->_clientClip;
  this->_client = v14;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))v14->_vptr_Panel + 16))(v14, v6);
  (*((void (__cdecl **)(vgui::Panel *, int))this->_client->_vptr_Panel + 54))(this->_client, 1);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_client->_vptr_Panel + 55))(this->_client, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_client->_vptr_Panel + 56))(this->_client, 0);
  v7 = (vgui::ScrollBar *)operator new(0xD8u);
  vgui::ScrollBar::ScrollBar(v7, 0, tall - 16, wide - 16, 16, 0);
  this->_horizontalScrollBar = v7;
  (*((void (__cdecl **)(vgui::ScrollBar *, vgui::ScrollPanel *const))v7->_vptr_Panel + 16))(v7, this);
  v8 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD *))*((_DWORD *)this->_horizontalScrollBar->_vptr_Panel + 129);
  v9 = operator new(8u);
  v9[1] = this;
  *v9 = &off_47388;
  v8(this->_horizontalScrollBar, v9);
  (*((void (__cdecl **)(vgui::ScrollBar *, _DWORD))this->_horizontalScrollBar->_vptr_Panel + 9))(
    this->_horizontalScrollBar,
    0);
  v10 = (vgui::ScrollBar *)operator new(0xD8u);
  vgui::ScrollBar::ScrollBar(v10, wide - 16, 0, 16, tall - 16, 1);
  this->_verticalScrollBar = v10;
  (*((void (__cdecl **)(vgui::ScrollBar *, vgui::ScrollPanel *const))v10->_vptr_Panel + 16))(v10, this);
  v11 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD *))*((_DWORD *)this->_verticalScrollBar->_vptr_Panel + 129);
  v12 = operator new(8u);
  v12[1] = this;
  *v12 = &off_47388;
  v11(this->_verticalScrollBar, v12);
  (*((void (__cdecl **)(vgui::ScrollBar *, _DWORD))this->_verticalScrollBar->_vptr_Panel + 9))(
    this->_verticalScrollBar,
    0);
  this->_autoVisible[0] = 1;
  this->_autoVisible[1] = 1;
  vgui::ScrollPanel::validate(this);
}

