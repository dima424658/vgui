#include <VGUI_HeaderPanel.h>

void vgui::HeaderPanel::setSliderPos(vgui::HeaderPanel *const this, int sliderIndex, int pos)
{
  vgui::Panel *v3; // edx

  v3 = 0;
  if ( sliderIndex >= 0 && sliderIndex < this->_sliderPanelDar._count )
    v3 = this->_sliderPanelDar._data[sliderIndex];
  (*v3->_vptr_Panel)(v3, pos - this->_sliderWide / 2, 0);
  (*((void (__cdecl **)(vgui::HeaderPanel *const, _DWORD))this->_vptr_Panel + 46))(this, 0);
  (*((void (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 132))(this);
  (*((void (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 12))(this);
}

int vgui::HeaderPanel::getSectionCount(vgui::HeaderPanel *const this)
{
  return this->_sectionPanelDar._count;
}

void vgui::HeaderPanel::getSectionExtents(vgui::HeaderPanel *const this, int sectionIndex, int *const x0, int *const x1)
{
  vgui::Panel *v4; // eax
  int v5; // eax
  int v6; // ecx
  int x; // [esp+20h] [ebp-1Ch] BYREF
  int y; // [esp+24h] [ebp-18h] BYREF
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  v4 = 0;
  if ( sectionIndex >= 0 && sectionIndex < this->_sectionPanelDar._count )
    v4 = this->_sectionPanelDar._data[sectionIndex];
  (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))v4->_vptr_Panel + 5))(v4, &x, &y, &wide, tall);
  v5 = x;
  v6 = wide;
  *x0 = x;
  *x1 = v6 + v5;
}

void vgui::HeaderPanel::fireChangeSignal(vgui::HeaderPanel *const this)
{
  int v1; // ebx
  vgui::ChangeSignal *v2; // eax

  (*((void (__cdecl **)(vgui::HeaderPanel *const, int))this->_vptr_Panel + 46))(this, 1);
  if ( this->_changeSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_changeSignalDar._data[v1++];
      (*v2->_vptr_ChangeSignal)(v2, this);
    }
    while ( this->_changeSignalDar._count > v1 );
  }
}

void vgui::HeaderPanel::performLayout(vgui::HeaderPanel *const this)
{
  int v1; // esi
  int i; // ebp
  vgui::Panel *v3; // eax
  int v4; // ebx
  vgui::Panel *v5; // eax
  int v6; // [esp+2Ch] [ebp-30h]
  int x; // [esp+30h] [ebp-2Ch] BYREF
  int y; // [esp+34h] [ebp-28h] BYREF
  int wide; // [esp+38h] [ebp-24h] BYREF
  int tall[8]; // [esp+3Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::HeaderPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, _DWORD, int, int))this->_sectionLayer->_vptr_Panel + 4))(
    this->_sectionLayer,
    0,
    0,
    wide,
    tall[0]);
  if ( this->_sectionPanelDar._count > 0 )
  {
    v1 = 0;
    v6 = 0;
    for ( i = 0; ; i = v4 )
    {
      v3 = 0;
      if ( this->_sliderPanelDar._count > v1 )
        v3 = this->_sliderPanelDar._data[v6];
      (*((void (__cdecl **)(vgui::Panel *, int *, int *))v3->_vptr_Panel + 1))(v3, &x, &y);
      v4 = x + this->_sliderWide / 2;
      v5 = 0;
      if ( this->_sectionPanelDar._count > v1 )
        v5 = this->_sectionPanelDar._data[v6];
      ++v1;
      (*((void (__cdecl **)(vgui::Panel *, int, _DWORD, int, int))v5->_vptr_Panel + 4))(v5, i, 0, v4 - i, tall[0]);
      ++v6;
      if ( this->_sectionPanelDar._count <= v1 )
        break;
    }
  }
}

void vgui::HeaderPanel::privateCursorMoved(vgui::HeaderPanel *const this, int x, int y, vgui::Panel *panel)
{
  int v4; // eax

  if ( this->_dragging )
  {
    v4 = (*((int (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 83))(this);
    (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v4 + 52))(v4, &x, &y);
    (*((void (__cdecl **)(vgui::HeaderPanel *const, int *, int *))this->_vptr_Panel + 35))(this, &x, &y);
    (*((void (__cdecl **)(vgui::HeaderPanel *const, int, int))this->_vptr_Panel + 128))(
      this,
      this->_dragSliderIndex,
      this->_dragSliderStartPos + x - this->_dragSliderStartX);
    (*((void (__cdecl **)(vgui::HeaderPanel *const, _DWORD))this->_vptr_Panel + 46))(this, 0);
    (*((void (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::HeaderPanel::privateMousePressed(vgui::HeaderPanel *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebp
  int mx; // [esp+10h] [ebp-4h] BYREF
  int my; // [esp+14h] [ebp+0h] BYREF
  int x; // [esp+18h] [ebp+4h] BYREF
  int y[7]; // [esp+1Ch] [ebp+8h] BYREF

  v3 = (*((int (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 83))(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v3 + 52))(v3, &mx, &my);
  (*((void (__cdecl **)(vgui::HeaderPanel *const, int *, int *))this->_vptr_Panel + 35))(this, &mx, &my);
  v4 = this->_sliderPanelDar._count;
  if ( v4 > 0 )
  {
    v5 = 0;
    while ( panel != this->_sliderPanelDar._data[v5] )
    {
      if ( ++v5 == v4 )
        return;
    }
    (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 1))(panel, &x, y);
    v6 = this->_sliderWide;
    v7 = x;
    this->_dragging = 1;
    this->_dragSliderIndex = v5;
    this->_dragSliderStartPos = v7 + v6 / 2;
    this->_dragSliderStartX = mx;
    (*((void (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 81))(panel, 1);
  }
}

void vgui::HeaderPanel::privateMouseReleased(vgui::HeaderPanel *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  this->_dragging = 0;
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))panel->_vptr_Panel + 81))(panel, 0);
}

void vgui::HeaderPanel::addChangeSignal(vgui::HeaderPanel *const this, vgui::ChangeSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::ChangeSignal*> *v3; // esi
  vgui::ChangeSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::ChangeSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::ChangeSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_changeSignalDar._count;
  v3 = &this->_changeSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_changeSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_changeSignalDar._capacity;
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
    v14 = (vgui::ChangeSignal **)v10;
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
    v2 = this->_changeSignalDar._count;
    this->_changeSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_changeSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_changeSignalDar._data )
    {
      operator delete[](this->_changeSignalDar._data);
      v2 = this->_changeSignalDar._count;
    }
    v8 = v14;
    this->_changeSignalDar._data = v14;
  }
  else
  {
    v8 = this->_changeSignalDar._data;
  }
  v8[v2] = s;
  ++this->_changeSignalDar._count;
}

void vgui::HeaderPanel::addSectionPanel(vgui::HeaderPanel *const this, vgui::Panel *panel)
{
  int v2; // eax
  int v3; // ecx
  int v4; // esi
  vgui::Panel *v5; // eax
  int v6; // ebp
  int v7; // eax
  vgui::Dar<vgui::Panel*> *v8; // esi
  vgui::Panel **v9; // edx
  int v10; // edx
  vgui::Panel *v11; // esi
  void (__cdecl *v12)(vgui::Panel *, _DWORD *); // edi
  _DWORD *v13; // eax
  void (__cdecl *v14)(vgui::Panel *, int); // edi
  int v15; // eax
  int v16; // eax
  vgui::Dar<vgui::Panel*> *v17; // ebp
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  vgui::Panel **v22; // eax
  int (**v23)(...); // eax
  unsigned int v24; // edi
  _BYTE *v25; // eax
  _WORD *v26; // edi
  int v27; // eax
  vgui::Panel **v28; // eax
  unsigned int v29; // edi
  _BYTE *v30; // eax
  _WORD *v31; // edi
  int v32; // eax
  vgui::Panel **v33; // [esp+24h] [ebp-38h]
  int v34; // [esp+24h] [ebp-38h]
  vgui::Panel **v35; // [esp+28h] [ebp-34h]
  unsigned int v36; // [esp+2Ch] [ebp-30h]
  unsigned int v37; // [esp+2Ch] [ebp-30h]
  int x; // [esp+30h] [ebp-2Ch] BYREF
  int y; // [esp+34h] [ebp-28h] BYREF
  int wide; // [esp+38h] [ebp-24h] BYREF
  int tall[8]; // [esp+3Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::HeaderPanel *const, int))this->_vptr_Panel + 46))(this, 1);
  v2 = this->_sectionPanelDar._count;
  x = 0;
  v3 = v2;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->_sectionPanelDar._data[v4++];
      (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))v5->_vptr_Panel + 5))(v5, &x, &y, &wide, tall);
      x += wide + this->_sliderWide;
      v2 = this->_sectionPanelDar._count;
    }
    while ( v2 > v4 );
    v3 = this->_sectionPanelDar._count;
  }
  v6 = this->_sectionPanelDar._capacity;
  v7 = v2 + 1;
  v8 = &this->_sectionPanelDar;
  if ( v7 <= v6 )
  {
    v9 = this->_sectionPanelDar._data;
    goto LABEL_7;
  }
  if ( v6 || (v6 = 1, v24 = 4, v7 > 1) )
  {
    do
      v6 *= 2;
    while ( v7 > v6 );
    v24 = 4 * v6;
  }
  v25 = (_BYTE *)operator new[](v24);
  v9 = (vgui::Panel **)v25;
  if ( !v25 )
    goto LABEL_64;
  v36 = v24;
  v26 = v25;
  if ( v36 >= 8 )
  {
    if ( ((uint8_t)v25 & 1) != 0 )
    {
      *v25 = 0;
      v26 = v25 + 1;
      --v36;
    }
    if ( ((uint8_t)v26 & 2) != 0 )
    {
      *v26++ = 0;
      v36 -= 2;
    }
    if ( ((uint8_t)v26 & 4) != 0 )
    {
      *(_DWORD *)v26 = 0;
      v26 += 2;
      v36 -= 4;
    }
    memset(v26, 0, 4 * (v36 >> 2));
    v26 += 2 * (v36 >> 2);
    LOBYTE(v36) = v36 & 3;
  }
  if ( (v36 & 4) == 0 )
  {
    if ( (v36 & 2) == 0 )
      goto LABEL_18;
LABEL_46:
    *v26++ = 0;
    if ( (v36 & 1) == 0 )
      goto LABEL_19;
    goto LABEL_45;
  }
  *(_DWORD *)v26 = 0;
  v26 += 2;
  if ( (v36 & 2) != 0 )
    goto LABEL_46;
LABEL_18:
  if ( (v36 & 1) != 0 )
LABEL_45:
    *(_BYTE *)v26 = 0;
LABEL_19:
  v3 = this->_sectionPanelDar._count;
  this->_sectionPanelDar._capacity = v6;
  if ( v3 > 0 )
  {
    v27 = 0;
    do
    {
      v9[v27] = this->_sectionPanelDar._data[v27];
      ++v27;
      v3 = v8->_count;
    }
    while ( v27 < v8->_count );
  }
  v28 = this->_sectionPanelDar._data;
  if ( v28 )
  {
    v33 = v9;
    operator delete[]((VFontData *const)v28);
    v3 = this->_sectionPanelDar._count;
    v9 = v33;
  }
  this->_sectionPanelDar._data = v9;
LABEL_7:
  v9[v3] = panel;
  v10 = x;
  ++this->_sectionPanelDar._count;
  (*panel->_vptr_Panel)(panel, v10, 0);
  (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))panel->_vptr_Panel + 16))(panel, this->_sectionLayer);
  (*((void (__cdecl **)(vgui::Panel *, int, int, int, int))panel->_vptr_Panel + 4))(panel, x, y, wide, tall[0]);
  (*((void (__cdecl **)(vgui::HeaderPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v11 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v11, 0, 0, this->_sliderWide, tall[0]);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))v11->_vptr_Panel + 54))(v11, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))v11->_vptr_Panel + 55))(v11, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))v11->_vptr_Panel + 56))(v11, 0);
  (*v11->_vptr_Panel)(v11, wide + x, 0);
  v12 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)v11->_vptr_Panel + 28);
  v13 = operator new(8u);
  *v13 = &off_449A8;
  v13[1] = this;
  v12(v11, v13);
  v14 = (void (__cdecl *)(vgui::Panel *, int))*((_DWORD *)v11->_vptr_Panel + 36);
  v15 = (*((int (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 83))(this);
  v16 = (*(int (__cdecl **)(int))(*(_DWORD *)v15 + 84))(v15);
  v17 = &this->_sliderPanelDar;
  v18 = (*(int (__cdecl **)(int, int))(*(_DWORD *)v16 + 20))(v16, 9);
  v14(v11, v18);
  (*((void (__cdecl **)(vgui::Panel *, vgui::HeaderPanel *const))v11->_vptr_Panel + 16))(v11, this);
  v19 = this->_sliderPanelDar._count;
  v20 = this->_sliderPanelDar._capacity;
  v21 = v19 + 1;
  if ( v19 + 1 <= v20 )
  {
    v22 = this->_sliderPanelDar._data;
    goto LABEL_9;
  }
  if ( v20 || (v20 = 1, v29 = 4, v21 > 1) )
  {
    do
      v20 *= 2;
    while ( v21 > v20 );
    v29 = 4 * v20;
  }
  v34 = v20;
  v30 = (_BYTE *)operator new[](v29);
  v35 = (vgui::Panel **)v30;
  if ( !v30 )
LABEL_64:
    exit(0);
  v37 = v29;
  v31 = v30;
  if ( v37 >= 8 )
  {
    if ( ((uint8_t)v30 & 1) != 0 )
    {
      *v30 = 0;
      --v37;
      v31 = v30 + 1;
    }
    if ( ((uint8_t)v31 & 2) != 0 )
    {
      *v31++ = 0;
      v37 -= 2;
    }
    if ( ((uint8_t)v31 & 4) != 0 )
    {
      *(_DWORD *)v31 = 0;
      v31 += 2;
      v37 -= 4;
    }
    memset(v31, 0, 4 * (v37 >> 2));
    v31 += 2 * (v37 >> 2);
    LOBYTE(v37) = v37 & 3;
  }
  if ( (v37 & 4) == 0 )
  {
    if ( (v37 & 2) == 0 )
      goto LABEL_33;
LABEL_41:
    *v31++ = 0;
    if ( (v37 & 1) == 0 )
      goto LABEL_34;
    goto LABEL_40;
  }
  *(_DWORD *)v31 = 0;
  v31 += 2;
  if ( (v37 & 2) != 0 )
    goto LABEL_41;
LABEL_33:
  if ( (v37 & 1) != 0 )
LABEL_40:
    *(_BYTE *)v31 = 0;
LABEL_34:
  v19 = this->_sliderPanelDar._count;
  this->_sliderPanelDar._capacity = v34;
  if ( v19 > 0 )
  {
    v32 = 0;
    do
    {
      v35[v32] = this->_sliderPanelDar._data[v32];
      ++v32;
      v19 = v17->_count;
    }
    while ( v32 < v17->_count );
  }
  if ( this->_sliderPanelDar._data )
  {
    operator delete[]((VFontData *const)this->_sliderPanelDar._data);
    v19 = this->_sliderPanelDar._count;
  }
  v22 = v35;
  this->_sliderPanelDar._data = v35;
LABEL_9:
  v22[v19] = v11;
  v23 = this->_vptr_Panel;
  ++this->_sliderPanelDar._count;
  v23[46](this, 0);
  (*((void (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 132))(this);
  (*((void (__cdecl **)(vgui::HeaderPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::HeaderPanel::HeaderPanel(vgui::HeaderPanel *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::Panel **v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  vgui::Panel **v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  vgui::ChangeSignal **v16; // edx
  vgui::Panel *v17; // esi
  int v18; // [esp+2Ch] [ebp-20h]
  int v19; // [esp+2Ch] [ebp-20h]
  int v20; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_sliderPanelDar._count = 0;
  this->_sliderPanelDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::HeaderPanel + 2);
  this->_sliderPanelDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    goto LABEL_20;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_sliderPanelDar._count;
  this->_sliderPanelDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_sliderPanelDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_sliderPanelDar._count );
  }
  v8 = this->_sliderPanelDar._data;
  if ( v8 )
  {
    v18 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v18;
  }
  this->_sliderPanelDar._data = (vgui::Panel **)v5;
  this->_sectionPanelDar._count = 0;
  this->_sectionPanelDar._capacity = 0;
  this->_sectionPanelDar._data = 0;
  v9 = operator new[](0x10u);
  if ( !v9 )
    goto LABEL_20;
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = 0;
  v10 = this->_sectionPanelDar._count;
  this->_sectionPanelDar._capacity = 4;
  if ( v10 > 0 )
  {
    v11 = 0;
    do
    {
      *(_DWORD *)(v9 + 4 * v11) = this->_sectionPanelDar._data[v11];
      ++v11;
    }
    while ( v11 < this->_sectionPanelDar._count );
  }
  v12 = this->_sectionPanelDar._data;
  if ( v12 )
  {
    v19 = v9;
    operator delete[]((VFontData *const)v12);
    v9 = v19;
  }
  this->_sectionPanelDar._data = (vgui::Panel **)v9;
  this->_changeSignalDar._count = 0;
  this->_changeSignalDar._capacity = 0;
  this->_changeSignalDar._data = 0;
  v13 = operator new[](0x10u);
  if ( !v13 )
LABEL_20:
    exit(0);
  *(_DWORD *)v13 = 0;
  *(_DWORD *)(v13 + 4) = 0;
  *(_DWORD *)(v13 + 8) = 0;
  *(_DWORD *)(v13 + 12) = 0;
  v14 = this->_changeSignalDar._count;
  this->_changeSignalDar._capacity = 4;
  if ( v14 > 0 )
  {
    v15 = 0;
    do
    {
      *(_DWORD *)(v13 + 4 * v15) = this->_changeSignalDar._data[v15];
      ++v15;
    }
    while ( v15 < this->_changeSignalDar._count );
  }
  v16 = this->_changeSignalDar._data;
  if ( v16 )
  {
    v20 = v13;
    operator delete[]((VFontData *const)v16);
    v13 = v20;
  }
  this->_changeSignalDar._data = (vgui::ChangeSignal **)v13;
  this->_sliderWide = 11;
  this->_dragging = 0;
  v17 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v17, 0, 0, wide, tall);
  this->_sectionLayer = v17;
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))v17->_vptr_Panel + 54))(v17, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_sectionLayer->_vptr_Panel + 55))(this->_sectionLayer, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_sectionLayer->_vptr_Panel + 56))(this->_sectionLayer, 0);
  (*((void (__cdecl **)(vgui::Panel *, vgui::HeaderPanel *const))this->_sectionLayer->_vptr_Panel + 16))(
    this->_sectionLayer,
    this);
}

