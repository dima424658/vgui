#include <VGUI_ListPanel.h>

void vgui::ListPanel::addItem(vgui::ListPanel *const this, vgui::Panel *panel)
{
  vgui::Panel *v3; // edx
  int (__cdecl *v4)(vgui::Panel *, int); // esi
  int v5; // eax
  int v6; // eax
  int x; // [esp+28h] [ebp-24h] BYREF
  int y; // [esp+2Ch] [ebp-20h] BYREF
  int wide; // [esp+30h] [ebp-1Ch] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int vwide; // [esp+38h] [ebp-14h] BYREF
  int vtall[4]; // [esp+3Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))panel->_vptr_Panel + 16))(panel, this->_vpanel);
  (*((void (__cdecl **)(vgui::Panel *, int))this->_vpanel->_vptr_Panel + 46))(this->_vpanel, 1);
  v3 = this->_vpanel;
  v4 = (int (__cdecl *)(vgui::Panel *, int))*((_DWORD *)v3->_vptr_Panel + 44);
  v5 = (*((int (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 43))(v3);
  v6 = v4(this->_vpanel, v5 - 1);
  (*(void (__cdecl **)(int, int *, int *, int *, int *))(*(_DWORD *)v6 + 20))(v6, &x, &y, &wide, &tall);
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_vpanel->_vptr_Panel + 3))(this->_vpanel, &vwide, vtall);
  (*((void (__cdecl **)(vgui::Panel *, int, int))this->_vpanel->_vptr_Panel + 2))(this->_vpanel, vwide, tall + y);
  (*((void (__cdecl **)(vgui::ScrollBar *, _DWORD, int))this->_scroll->_vptr_Panel + 130))(
    this->_scroll,
    0,
    tall + y - this->_size[1]);
}

void vgui::ListPanel::performLayout(vgui::ListPanel *const this)
{
  vgui::Panel *v1; // edx
  int (__cdecl *v2)(vgui::Panel *, int); // esi
  int v3; // eax
  int v4; // eax
  int x; // [esp+28h] [ebp-24h] BYREF
  int y; // [esp+2Ch] [ebp-20h] BYREF
  int wide; // [esp+30h] [ebp-1Ch] BYREF
  int tall; // [esp+34h] [ebp-18h] BYREF
  int vwide; // [esp+38h] [ebp-14h] BYREF
  int vtall[4]; // [esp+3Ch] [ebp-10h] BYREF

  v1 = this->_vpanel;
  v2 = (int (__cdecl *)(vgui::Panel *, int))*((_DWORD *)v1->_vptr_Panel + 44);
  v3 = (*((int (__cdecl **)(vgui::Panel *))v1->_vptr_Panel + 43))(v1);
  v4 = v2(this->_vpanel, v3 - 1);
  if ( v4 )
  {
    (*(void (__cdecl **)(int, int *, int *, int *, int *))(*(_DWORD *)v4 + 20))(v4, &x, &y, &wide, &tall);
    (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_vpanel->_vptr_Panel + 3))(this->_vpanel, &vwide, vtall);
    (*((void (__cdecl **)(vgui::Panel *, int, int))this->_vpanel->_vptr_Panel + 2))(
      this->_vpanel,
      this->_size[0] - 15,
      vtall[0]);
    (*((void (__cdecl **)(vgui::ScrollBar *, int, _DWORD, int, int))this->_scroll->_vptr_Panel + 4))(
      this->_scroll,
      this->_size[0] - 15,
      0,
      15,
      this->_size[1]);
    (*((void (__cdecl **)(vgui::ScrollBar *, _DWORD, int))this->_scroll->_vptr_Panel + 130))(
      this->_scroll,
      0,
      tall + y - this->_size[1]);
  }
}

void vgui::ListPanel::setPixelScroll(vgui::ListPanel *const this, int value)
{
  (*this->_vpanel->_vptr_Panel)(this->_vpanel, 0, value);
  (*((void (__cdecl **)(vgui::ListPanel *const))this->_vptr_Panel + 12))(this);
  (*((void (__cdecl **)(vgui::Panel *))this->_vpanel->_vptr_Panel + 12))(this->_vpanel);
}

void vgui::ListPanel::translatePixelScroll(vgui::ListPanel *const this, int delta)
{
  int x; // [esp+18h] [ebp-14h] BYREF
  int y[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_vpanel->_vptr_Panel + 1))(this->_vpanel, &x, y);
  (*this->_vpanel->_vptr_Panel)(this->_vpanel, 0, y[0] + delta);
  (*((void (__cdecl **)(vgui::ListPanel *const))this->_vptr_Panel + 12))(this);
  (*((void (__cdecl **)(vgui::Panel *))this->_vpanel->_vptr_Panel + 12))(this->_vpanel);
}

void vgui::ListPanel::setSize(vgui::ListPanel *const this, int wide, int tall)
{
  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::ListPanel *const, _DWORD))this->_vptr_Panel + 46))(this, 0);
}

void vgui::ListPanel::addString(vgui::ListPanel *const this, const char *str)
{
  void (__cdecl *v2)(vgui::ListPanel *const, vgui::Label *); // esi
  vgui::Label *v3; // ebp

  v2 = (void (__cdecl *)(vgui::ListPanel *const, vgui::Label *))*((_DWORD *)this->_vptr_Panel + 128);
  v3 = (vgui::Label *)operator new(0xD0u);
  vgui::Label::Label(v3, str, 0, 0, 80, 20);
  v2(this, v3);
}

void vgui::ListPanel::ListPanel(vgui::ListPanel *const this, int x, int y, int wide, int tall)
{
  vgui::Panel *v5; // ebp
  void (__cdecl *v6)(vgui::Panel *, vgui::StackLayout *); // ebp
  vgui::ScrollBar *v7; // ebp
  void (__cdecl *v8)(vgui::ScrollBar *, _DWORD *); // esi
  _DWORD *v9; // eax
  vgui::StackLayout *v10; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ListPanel + 2);
  v5 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v5, 0, 0, wide - 15, 2 * tall);
  this->_vpanel = v5;
  (*((void (__cdecl **)(vgui::Panel *, vgui::ListPanel *const))v5->_vptr_Panel + 16))(v5, this);
  v6 = (void (__cdecl *)(vgui::Panel *, vgui::StackLayout *))*((_DWORD *)this->_vpanel->_vptr_Panel + 45);
  v10 = (vgui::StackLayout *)operator new(0xCu);
  vgui::StackLayout::StackLayout(v10, 1, 0);
  v6(this->_vpanel, v10);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, _DWORD, int, _DWORD))this->_vpanel->_vptr_Panel + 74))(
    this->_vpanel,
    0,
    0,
    100,
    0);
  v7 = (vgui::ScrollBar *)operator new(0xD8u);
  vgui::ScrollBar::ScrollBar(v7, wide - 15, 0, 15, tall, 1);
  this->_scroll = v7;
  (*((void (__cdecl **)(vgui::ScrollBar *, vgui::ListPanel *const))v7->_vptr_Panel + 16))(v7, this);
  v8 = (void (__cdecl *)(vgui::ScrollBar *, _DWORD *))*((_DWORD *)this->_scroll->_vptr_Panel + 129);
  v9 = operator new(8u);
  *v9 = &off_45768;
  v9[1] = this;
  v8(this->_scroll, v9);
}

