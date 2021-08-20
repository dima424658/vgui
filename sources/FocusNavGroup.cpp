#include <VGUI_FocusNavGroup.h>

void vgui::FocusNavGroup::setCurrentPanel(vgui::FocusNavGroup *const this, vgui::Panel *panel)
{
  int v2; // edx
  int v3; // eax

  v2 = this->_panelDar._count;
  if ( v2 > 0 )
  {
    v3 = 0;
    while ( panel != this->_panelDar._data[v3] )
    {
      if ( ++v3 == v2 )
        return;
    }
    this->_currentIndex = v3;
  }
}

void vgui::FocusNavGroup::requestFocusNext(vgui::FocusNavGroup *const this)
{
  int v1; // edx
  int v2; // ecx

  v1 = this->_panelDar._count;
  if ( v1 )
  {
    v2 = this->_currentIndex + 1;
    this->_currentIndex = v2;
    if ( v1 > v2 )
    {
      if ( v2 < 0 )
        goto LABEL_4;
    }
    else
    {
      v2 = 0;
      this->_currentIndex = 0;
      if ( v1 <= 0 )
      {
LABEL_4:
        MEMORY[0x464C4623](v2, 0);
        return;
      }
    }
    (*((void (__cdecl **)(vgui::Panel *))this->_panelDar._data[v2]->_vptr_Panel + 41))(this->_panelDar._data[v2]);
  }
}

void vgui::FocusNavGroup::requestFocusPrev(vgui::FocusNavGroup *const this)
{
  int v1; // ecx
  vgui::Panel *v2; // ebx
  int v3; // edx

  v1 = this->_panelDar._count;
  if ( v1 )
  {
    v2 = 0;
    v3 = this->_currentIndex - 1;
    this->_currentIndex = v3;
    if ( v3 >= 0 || (v3 = v1 - 1, this->_currentIndex = v1 - 1, v1 - 1 >= 0) )
    {
      if ( v1 > v3 )
        v2 = this->_panelDar._data[v3];
      (*((void (__cdecl **)(vgui::Panel *))v2->_vptr_Panel + 41))(v2);
    }
    else
    {
      MEMORY[0x464C4623](v1, 0);
    }
  }
}

void vgui::FocusNavGroup::addPanel(vgui::FocusNavGroup *const this, vgui::Panel *panel)
{
  int v2; // ecx
  vgui::Dar<vgui::Panel*> *v3; // esi
  vgui::Panel **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::Panel **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::Panel **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_panelDar._count;
  v3 = &this->_panelDar;
  if ( v2 > 0 )
  {
    v4 = this->_panelDar._data;
    v5 = 0;
    if ( panel == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( panel == v4[v5] )
        return;
    }
  }
  v6 = this->_panelDar._capacity;
  v7 = v2 + 1;
  if ( v2 + 1 > v6 )
  {
    if ( v6 || (v6 = 1, v9 = 4, v7 > 1) )
    {
      do
        v6 *= 2;
      while ( v7 > v6 );
      v9 = 4 * v6;
    }
    v13 = v6;
    v10 = (_BYTE *)operator new[](v9);
    v14 = (vgui::Panel **)v10;
    if ( !v10 )
      exit(0);
    v15 = v9;
    v11 = v10;
    if ( v15 >= 8 )
    {
      if ( ((uint8_t)v10 & 1) != 0 )
      {
        *v10 = 0;
        --v15;
        v11 = v10 + 1;
      }
      if ( ((uint8_t)v11 & 2) != 0 )
      {
        *v11++ = 0;
        v15 -= 2;
      }
      if ( ((uint8_t)v11 & 4) != 0 )
      {
        *(_DWORD *)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ( (v15 & 4) != 0 )
    {
      *(_DWORD *)v11 = 0;
      v11 += 2;
    }
    if ( (v15 & 2) != 0 )
      *v11++ = 0;
    if ( (v15 & 1) != 0 )
      *(_BYTE *)v11 = 0;
    v2 = this->_panelDar._count;
    this->_panelDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_panelDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_panelDar._data )
    {
      operator delete[](this->_panelDar._data);
      v2 = this->_panelDar._count;
    }
    v8 = v14;
    this->_panelDar._data = v14;
  }
  else
  {
    v8 = this->_panelDar._data;
  }
  v8[v2] = panel;
  ++this->_panelDar._count;
}

void vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *const this)
{
  int v1; // eax
  int v2; // edx
  int v3; // edx
  vgui::Panel **v4; // edx
  int v5; // [esp+1Ch] [ebp-10h]

  this->_vptr_FocusNavGroup = (int (**)(...))(&`vtable for'vgui::FocusNavGroup + 2);
  this->_panelDar._count = 0;
  this->_panelDar._capacity = 0;
  this->_panelDar._data = 0;
  v1 = operator new[](0x10u);
  if ( !v1 )
    exit(0);
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  v2 = this->_panelDar._count;
  this->_panelDar._capacity = 4;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(v1 + 4 * v3) = this->_panelDar._data[v3];
      ++v3;
    }
    while ( v3 < this->_panelDar._count );
  }
  v4 = this->_panelDar._data;
  if ( v4 )
  {
    v5 = v1;
    operator delete[](v4);
    v1 = v5;
  }
  this->_panelDar._data = (vgui::Panel **)v1;
  this->_currentIndex = 0;
}

