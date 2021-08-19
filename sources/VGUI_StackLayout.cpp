#include <VGUI_StackLayout.h>

void vgui::StackLayout::performLayout(vgui::StackLayout *const this, vgui::Panel *panel)
{
  int v2; // edi
  int v3; // ebx
  int v4; // [esp+2Ch] [ebp-40h]
  int tall[3]; // [esp+30h] [ebp-3Ch] BYREF
  int x; // [esp+3Ch] [ebp-30h] BYREF
  int y; // [esp+40h] [ebp-2Ch] BYREF
  int wide; // [esp+44h] [ebp-28h] BYREF
  int pwide; // [esp+48h] [ebp-24h] BYREF
  int ptall[8]; // [esp+4Ch] [ebp-20h] BYREF

  v2 = 0;
  v3 = 0;
  while ( v2 < (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 43))(panel) )
  {
    v4 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, v2);
    (*(void (__cdecl **)(int, int *, int *, int *, int *))(*(_DWORD *)v4 + 20))(v4, &x, &y, &wide, tall);
    (**(void (__cdecl ***)(int, int, int))v4)(v4, x, v3);
    if ( this->_fitWide )
    {
      (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 58))(panel, &pwide, ptall);
      (*(void (__cdecl **)(int, int, int))(*(_DWORD *)v4 + 8))(v4, pwide, tall[0]);
    }
    ++v2;
    v3 += tall[0] + this->_vgap;
  }
}

void vgui::StackLayout::StackLayout(vgui::StackLayout *const this, int vgap, bool fitWide)
{
  vgui::Layout::Layout(this);
  this->_vptr_Layout = (int (**)(...))(&`vtable for'vgui::StackLayout + 2);
  this->_vgap = vgap;
  this->_fitWide = fitWide;
}

