#include <VGUI_TabPanel.h>

void vgui::TabPanel::setSelectedTab(vgui::TabPanel *const this, vgui::Panel *tab)
{
  int v2; // ebx
  vgui::Panel *v3; // eax

  if ( tab )
  {
    v2 = 0;
    if ( this->_selectedTab != tab )
    {
      while ( v2 < (*((int (__cdecl **)(vgui::Panel *))this->_tabArea->_vptr_Panel + 43))(this->_tabArea) )
      {
        if ( tab == (vgui::Panel *)(*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(
                                     this->_tabArea,
                                     v2) )
        {
          (*((void (__cdecl **)(vgui::Panel *, _DWORD))this->_selectedPanel->_vptr_Panel + 9))(this->_selectedPanel, 0);
          v3 = (vgui::Panel *)(*((int (__cdecl **)(vgui::Panel *, int))this->_clientArea->_vptr_Panel + 44))(
                                this->_clientArea,
                                v2);
          this->_selectedPanel = v3;
          (*((void (__cdecl **)(vgui::Panel *, int))v3->_vptr_Panel + 9))(v3, 1);
          this->_selectedTab = tab;
          break;
        }
        ++v2;
      }
      (*((void (__cdecl **)(vgui::TabPanel *const))this->_vptr_Panel + 130))(this);
    }
  }
}

void vgui::TabPanel::recomputeLayoutTop(vgui::TabPanel *const this)
{
  int v1; // edi
  int v2; // esi
  int v3; // edi
  void (__cdecl ***v4)(_DWORD, int, int); // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // ebp
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // eax
  void (__cdecl ***v18)(_DWORD, int, int); // eax
  bool v19; // cc
  vgui::Panel *v20; // eax
  int (**v21)(...); // edx
  int v22; // eax
  int v23; // esi
  int v24; // eax
  int v25; // eax
  int j; // [esp+4h] [ebp-A8h]
  int ja; // [esp+4h] [ebp-A8h]
  int jb; // [esp+4h] [ebp-A8h]
  int jc; // [esp+4h] [ebp-A8h]
  int v30; // [esp+24h] [ebp-88h]
  int extra2; // [esp+28h] [ebp-84h]
  int i; // [esp+2Ch] [ebp-80h]
  int v33; // [esp+30h] [ebp-7Ch]
  int maxx; // [esp+34h] [ebp-78h]
  int x[4]; // [esp+40h] [ebp-6Ch] BYREF
  int y[4]; // [esp+50h] [ebp-5Ch] BYREF
  int tall[4]; // [esp+60h] [ebp-4Ch] BYREF
  int wide; // [esp+70h] [ebp-3Ch] BYREF
  int paintWide; // [esp+74h] [ebp-38h] BYREF
  int paintTall; // [esp+78h] [ebp-34h] BYREF
  int ww; // [esp+7Ch] [ebp-30h] BYREF
  int tt; // [esp+80h] [ebp-2Ch] BYREF
  int xx; // [esp+84h] [ebp-28h] BYREF
  int yy; // [esp+88h] [ebp-24h] BYREF
  int miny[8]; // [esp+8Ch] [ebp-20h] BYREF

  x[0] = 0;
  y[0] = 0;
  (*((void (__cdecl **)(vgui::TabPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &paintWide, &paintTall);
  v1 = paintWide;
  x[0] = 5;
  v2 = (*((int (__cdecl **)(vgui::Panel *))this->_tabArea->_vptr_Panel + 43))(this->_tabArea) - 1;
  if ( v2 >= 0 )
  {
    maxx = v1 - 5;
    v3 = 0;
    do
    {
      v5 = (*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, v2);
      (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v5 + 240))(v5, &wide, tall);
      v6 = (*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, v2);
      (*(void (__cdecl **)(int, int, int))(*(_DWORD *)v6 + 8))(v6, wide, tall[0]);
      if ( x[0] + wide <= maxx )
      {
        ++v3;
      }
      else
      {
        if ( v3 )
        {
          extra2 = (maxx - x[0]) / v3;
          v7 = v3 * extra2;
          v8 = v2 + v3;
          v30 = v8;
          if ( v8 > v2 )
          {
            v9 = 0;
            i = v2;
            v33 = extra2 + maxx - x[0] - v7;
            do
            {
              v10 = extra2;
              if ( v8 == v30 )
                v10 = v33;
              v11 = (*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, v8);
              (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v11 + 240))(v11, &ww, &tt);
              v12 = (*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, v8);
              (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v12 + 4))(v12, &xx, &yy);
              ja = v8--;
              v13 = (*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, ja);
              v14 = v9 + xx;
              v9 += v10;
              (*(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)v13 + 16))(v13, v14, yy, v10 + ww, tt);
            }
            while ( v8 != i );
            v2 = i;
          }
        }
        x[0] = 5;
        v3 = 1;
        maxx -= 5;
        y[0] += 4 - tall[0];
      }
      j = v2--;
      v4 = (void (__cdecl ***)(_DWORD, int, int))(*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel
                                                  + 44))(
                                                   this->_tabArea,
                                                   j);
      (**v4)(v4, x[0], y[0]);
      x[0] += wide - 1;
    }
    while ( v2 != -1 );
  }
  v15 = 0;
  v16 = (*((int (__cdecl **)(vgui::Panel *, _DWORD))this->_tabArea->_vptr_Panel + 44))(this->_tabArea, 0);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v16 + 4))(v16, x, miny);
  while ( 1 )
  {
    v19 = v15 < (*((int (__cdecl **)(vgui::Panel *))this->_tabArea->_vptr_Panel + 43))(this->_tabArea);
    v20 = this->_tabArea;
    v21 = v20->_vptr_Panel;
    if ( !v19 )
      break;
    v17 = v21[44](v20, v15);
    (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v17 + 4))(v17, x, y);
    jb = v15++;
    v18 = (void (__cdecl ***)(_DWORD, int, int))(*((int (__cdecl **)(vgui::Panel *, int))this->_tabArea->_vptr_Panel + 44))(
                                                  this->_tabArea,
                                                  jb);
    (**v18)(v18, x[0], y[0] - miny[0]);
  }
  v22 = v21[44](v20, 0);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v22 + 12))(v22, &wide, tall);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, int, int, int))this->_tabArea->_vptr_Panel + 4))(
    this->_tabArea,
    0,
    5,
    paintWide,
    tall[0] - miny[0]);
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_tabArea->_vptr_Panel + 3))(this->_tabArea, &wide, tall);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD, int, int, int))this->_clientArea->_vptr_Panel + 4))(
    this->_clientArea,
    0,
    tall[0] + 4,
    paintWide,
    paintTall - tall[0] - 5);
  v23 = 0;
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))this->_clientArea->_vptr_Panel + 3))(
    this->_clientArea,
    &wide,
    tall);
  while ( v23 < (*((int (__cdecl **)(vgui::Panel *))this->_clientArea->_vptr_Panel + 43))(this->_clientArea) )
  {
    v24 = (*((int (__cdecl **)(vgui::Panel *, int))this->_clientArea->_vptr_Panel + 44))(this->_clientArea, v23);
    (*(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)v24 + 16))(v24, 5, 5, wide - 10, tall[0] - 10);
    jc = v23++;
    v25 = (*((int (__cdecl **)(vgui::Panel *, int))this->_clientArea->_vptr_Panel + 44))(this->_clientArea, jc);
    (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)v25 + 184))(v25, 0);
  }
}

void vgui::TabPanel::setSize(vgui::TabPanel *const this, int wide, int tall)
{
  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::TabPanel *const))this->_vptr_Panel + 130))(this);
}

void vgui::TabPanel::recomputeLayout(vgui::TabPanel *const this)
{
  if ( (*((int (__cdecl **)(vgui::Panel *))this->_tabArea->_vptr_Panel + 43))(this->_tabArea) )
  {
    if ( this->_tabPlacement == tp_top )
      (*((void (__cdecl **)(vgui::TabPanel *const))this->_vptr_Panel + 129))(this);
    (*((void (__cdecl **)(vgui::TabPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::TabPanel::TabPanel(vgui::TabPanel *const this, int x, int y, int wide, int tall)
{
  vgui::Panel *v5; // ebp
  void (__cdecl *v6)(vgui::Panel *, vgui::Border *); // edi
  vgui::Border *v7; // eax
  unsigned int i; // edx
  _DWORD *v9; // edx
  vgui::Panel *v10; // edi
  void (__cdecl *v11)(vgui::Panel *, vgui::Border *); // ebx
  vgui::Border *v12; // eax
  unsigned int j; // edx
  _DWORD *v14; // edx
  vgui::ButtonGroup *v15; // eax
  vgui::ButtonGroup *v16; // ebx
  vgui::Button **v17; // eax
  vgui::Button **v18; // edi
  int v19; // eax
  int v20; // edx
  vgui::Border *v21; // [esp+2Ch] [ebp-20h]
  vgui::Border *v22; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_tabPlacement = tp_top;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TabPanel + 2);
  v5 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v5, 5, 5, wide - 10, tall - 10);
  this->_clientArea = v5;
  (*((void (__cdecl **)(vgui::Panel *, vgui::TabPanel *const))v5->_vptr_Panel + 16))(v5, this);
  v6 = (void (__cdecl *)(vgui::Panel *, vgui::Border *))*((_DWORD *)this->_clientArea->_vptr_Panel + 53);
  v7 = (vgui::Border *)operator new(0x38u);
  for ( i = 0; i < 12; i += 4 )
  {
    v7->_pos[i] = 0;
    *(int (***)(...))((char *)&v7->_vptr_Image + i * 4) = 0;
    v7->_pos[i + 1] = 0;
    v7->_size[i] = 0;
  }
  v9 = (int (***)(...))((char *)&v7->_vptr_Image + i * 4);
  *v9 = 0;
  v9[1] = 0;
  v21 = v7;
  vgui::Border::Border(v7);
  v21->_vptr_Image = (int (**)(...))&off_48088;
  v6(this->_clientArea, v21);
  v10 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v10, 5, 5, wide, 5);
  this->_tabArea = v10;
  (*((void (__cdecl **)(vgui::Panel *, vgui::TabPanel *const))v10->_vptr_Panel + 16))(v10, this);
  v11 = (void (__cdecl *)(vgui::Panel *, vgui::Border *))*((_DWORD *)this->_tabArea->_vptr_Panel + 53);
  v12 = (vgui::Border *)operator new(0x38u);
  for ( j = 0; j < 12; j += 4 )
  {
    *(int (***)(...))((char *)&v12->_vptr_Image + j * 4) = 0;
    v12->_pos[j] = 0;
    v12->_pos[j + 1] = 0;
    v12->_size[j] = 0;
  }
  v14 = (int (***)(...))((char *)&v12->_vptr_Image + j * 4);
  *v14 = 0;
  v14[1] = 0;
  v22 = v12;
  vgui::Border::Border(v12);
  v22->_vptr_Image = (int (**)(...))&off_48108;
  v11(this->_tabArea, v22);
  this->_selectedTab = 0;
  this->_selectedPanel = 0;
  v15 = (vgui::ButtonGroup *)operator new(0x10u);
  v15->_buttonDar._count = 0;
  v16 = v15;
  v15->_buttonDar._capacity = 0;
  v15->_buttonDar._data = 0;
  v15->_vptr_ButtonGroup = (int (**)(...))(&`vtable for'vgui::ButtonGroup + 2);
  v17 = (vgui::Button **)operator new[](0x10u);
  v18 = v17;
  if ( !v17 )
    exit(0);
  *v17 = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v19 = v16->_buttonDar._count;
  v16->_buttonDar._capacity = 4;
  if ( v19 > 0 )
  {
    v20 = 0;
    do
    {
      v18[v20] = v16->_buttonDar._data[v20];
      ++v20;
    }
    while ( v20 < v16->_buttonDar._count );
  }
  if ( v16->_buttonDar._data )
    operator delete[]((VFontData *const)v16->_buttonDar._data);
  v16->_buttonDar._data = v18;
  this->_buttonGroup = v16;
}

