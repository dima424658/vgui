#include <VGUI_FlowLayout.h>

void vgui::FlowLayout::performLayout(vgui::FlowLayout *const this, vgui::Panel *panel)
{
  int v2; // edi
  int v3; // ebx
  int i; // [esp+4h] [ebp-38h]
  int v5; // [esp+2Ch] [ebp-10h]
  int x; // [esp+30h] [ebp-Ch] BYREF
  int y; // [esp+34h] [ebp-8h] BYREF
  int wide; // [esp+38h] [ebp-4h] BYREF
  int tall[7]; // [esp+3Ch] [ebp+0h] BYREF

  v2 = 0;
  v3 = 0;
  while ( v2 < (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 43))(panel) )
  {
    i = v2++;
    v5 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, i);
    (*(void (__cdecl **)(int, int *, int *, int *, int *))(*(_DWORD *)v5 + 20))(v5, &x, &y, &wide, tall);
    (**(void (__cdecl ***)(int, int, int))v5)(v5, v3, y);
    v3 += wide + this->_hgap;
  }
}

void vgui::FlowLayout::FlowLayout(vgui::FlowLayout *const this, int hgap)
{
  vgui::Layout::Layout(this);
  this->_vptr_Layout = (int (**)(...))(&`vtable for'vgui::FlowLayout + 2);
  this->_hgap = hgap;
}

