#include <VGUI_BuildGroup.h>

void vgui::BuildGroup::setEnabled(vgui::BuildGroup *const this, bool state)
{
  int (**v2)(...); // eax

  if ( this->_enabled != state )
  {
    if ( this->_currentPanel )
    {
      v2 = this->_vptr_BuildGroup;
      this->_currentPanel = 0;
      v2[6](this);
    }
    this->_currentPanel = 0;
  }
  this->_enabled = state;
}

bool vgui::BuildGroup::isEnabled(vgui::BuildGroup *const this)
{
  return this->_enabled;
}

void vgui::BuildGroup::cursorMoved(vgui::BuildGroup *const this, int x, int y, vgui::Panel *panel)
{
  vgui::Panel *v4; // esi
  int v5; // eax
  void (__cdecl **v6)(vgui::Panel *, int, int); // edx

  v4 = panel;
  if ( this->_dragging )
  {
    v5 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 83))(panel);
    (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v5 + 52))(v5, &x, &y);
    v6 = (void (__cdecl **)(vgui::Panel *, int, int))v4->_vptr_Panel;
    if ( this->_dragMouseCode == MOUSE_RIGHT )
      v6[2](v4, x - this->_dragStartCursorPos[0], y - this->_dragStartCursorPos[1]);
    else
      (*v6)(
        v4,
        this->_dragStartPanelPos[0] + x - this->_dragStartCursorPos[0],
        this->_dragStartPanelPos[1] + y - this->_dragStartCursorPos[1]);
    (*((void (__cdecl **)(vgui::BuildGroup *const, vgui::Panel *))this->_vptr_BuildGroup + 5))(this, v4);
    (*((void (__cdecl **)(vgui::Panel *))v4->_vptr_Panel + 67))(v4);
  }
}

void vgui::BuildGroup::mouseReleased(vgui::BuildGroup *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  int v3; // eax

  this->_dragging = 0;
  v3 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 83))(panel);
  (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)v3 + 56))(v3, 0);
}

void vgui::BuildGroup::keyTyped(vgui::BuildGroup *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  char v3; // al
  bool v4; // dl
  bool v5; // cc
  int v6; // esi
  int v7; // ebp
  int (**v8)(...); // eax
  int v9; // eax
  char ctrl; // [esp+2Fh] [ebp-2Dh]
  int x; // [esp+30h] [ebp-2Ch] BYREF
  int y; // [esp+34h] [ebp-28h] BYREF
  int wide; // [esp+38h] [ebp-24h] BYREF
  int tall[4]; // [esp+3Ch] [ebp-20h] BYREF

  ctrl = 1;
  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 25))(panel, 78) )
    ctrl = (*((uint8_t (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 25))(panel, 79) != 0;
  v3 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 25))(panel, 82);
  v4 = 1;
  if ( v3 )
  {
    v5 = code <= KEY_LEFT;
    if ( code != KEY_LEFT )
      goto LABEL_5;
LABEL_13:
    v7 = 0;
    v6 = -this->_snapX;
LABEL_15:
    if ( v6 | v7 )
    {
      (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))panel->_vptr_Panel + 5))(
        panel,
        &x,
        &y,
        &wide,
        tall);
      v8 = panel->_vptr_Panel;
      if ( ctrl )
        v8[2](panel, wide + v6, tall[0] + v7);
      else
        (*v8)(panel, x + v6, y + v7);
      (*((void (__cdecl **)(vgui::BuildGroup *const, vgui::Panel *))this->_vptr_BuildGroup + 5))(this, panel);
      (*((void (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 12))(panel);
      if ( (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 8))(panel) )
      {
        v9 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 8))(panel);
        (*(void (__cdecl **)(int))(*(_DWORD *)v9 + 48))(v9);
      }
    }
    return;
  }
  v4 = (*((uint8_t (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 25))(panel, 83) != 0;
  v5 = code <= KEY_LEFT;
  if ( code == KEY_LEFT )
    goto LABEL_13;
LABEL_5:
  if ( !v5 )
  {
    if ( code == KEY_DOWN )
    {
      v7 = this->_snapY;
      v6 = 0;
    }
    else
    {
      if ( code != KEY_RIGHT )
        return;
      v6 = this->_snapX;
      v7 = 0;
    }
    goto LABEL_15;
  }
  if ( code != KEY_C )
  {
    if ( code != KEY_UP )
      return;
    v6 = 0;
    v7 = -this->_snapY;
    goto LABEL_15;
  }
  if ( v4 )
    (*((void (__cdecl **)(vgui::BuildGroup *const))this->_vptr_BuildGroup + 4))(this);
}

void vgui::BuildGroup::applySnap(vgui::BuildGroup *const this, vgui::Panel *panel)
{
  int v3; // edi
  int (**v4)(...); // edx
  int x; // [esp+20h] [ebp-2Ch] BYREF
  int y; // [esp+24h] [ebp-28h] BYREF
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))panel->_vptr_Panel + 5))(panel, &x, &y, &wide, tall);
  v3 = this->_snapY;
  v4 = panel->_vptr_Panel;
  x = x / this->_snapX * this->_snapX;
  y = v3 * (y / v3);
  (*v4)(panel, x, y);
  (*((void (__cdecl **)(vgui::Panel *, int, int))panel->_vptr_Panel + 2))(
    panel,
    (wide + x) / this->_snapX * this->_snapX - x,
    (y + tall[0]) / this->_snapY * this->_snapY - y);
}

void vgui::BuildGroup::fireCurrentPanelChangeSignal(vgui::BuildGroup *const this)
{
  int v1; // ebx
  vgui::ChangeSignal *v2; // eax

  if ( this->_currentPanelChangeSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_currentPanelChangeSignalDar._data[v1++];
      (*v2->_vptr_ChangeSignal)(v2, 0);
    }
    while ( this->_currentPanelChangeSignalDar._count > v1 );
  }
}

void vgui::BuildGroup::copyPropertiesToClipboard(vgui::BuildGroup *const this)
{
  int v1; // ebx
  const char *src; // eax
  vgui::App *v3; // eax
  char text[32768]; // [esp+20h] [ebp-821Ch] BYREF
  char buf[512]; // [esp+8020h] [ebp-21Ch] BYREF

  text[0] = 0;
  if ( this->_panelDar._count > 0 )
  {
    v1 = 0;
    do
    {
      (*((void (__cdecl **)(vgui::Panel *, char *, int))this->_panelDar._data[v1]->_vptr_Panel + 69))(
        this->_panelDar._data[v1],
        buf,
        512);
      src = 0;
      if ( this->_panelNameDar._count > v1 )
        src = this->_panelNameDar._data[v1];
      ++v1;
      strcat(text, src);
      strcat(text, buf);
    }
    while ( this->_panelDar._count > v1 );
  }
  v3 = vgui::App::getInstance();
  (*((void (__cdecl **)(vgui::App *, char *, unsigned int))v3->_vptr_App + 27))(v3, text, strlen(text));
  vgui::vgui_printf("Copied to clipboard\n");
}

void vgui::BuildGroup::mousePressed(vgui::BuildGroup *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  vgui::Panel *v3; // ebx
  int v4; // eax
  int v5; // eax
  int (**v6)(...); // eax
  int v7; // eax
  vgui::Label *v8; // ebp
  vgui::LineBorder *v9; // [esp+28h] [ebp-34h]
  void (__cdecl *v10)(vgui::Label *, vgui::LineBorder *); // [esp+2Ch] [ebp-30h]
  int lx; // [esp+30h] [ebp-2Ch] BYREF
  int ly; // [esp+34h] [ebp-28h] BYREF
  int x; // [esp+38h] [ebp-24h] BYREF
  int y[4]; // [esp+3Ch] [ebp-20h] BYREF

  v3 = panel;
  if ( code == MOUSE_RIGHT )
  {
    v7 = (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 83))(panel);
    (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v7 + 52))(v7, &lx, &ly);
    (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 35))(panel, &lx, &ly);
    v8 = (vgui::Label *)operator new(0xD0u);
    vgui::Label::Label(v8, "Label", lx, ly, 0, 0);
    v10 = *(void (__cdecl **)(vgui::Label *, vgui::LineBorder *))(*(_DWORD *)v8->baseclass_0 + 212);
    v9 = (vgui::LineBorder *)operator new(0x44u);
    vgui::LineBorder::LineBorder(v9);
    v10(v8, v9);
    v3 = (vgui::Panel *)v8;
    (*(void (__cdecl **)(vgui::Label *, vgui::Panel *))(*(_DWORD *)v8->baseclass_0 + 64))(v8, panel);
    (*(void (__cdecl **)(vgui::Label *, vgui::BuildGroup *const, const char *))(*(_DWORD *)v8->baseclass_0 + 256))(
      v8,
      this,
      "Label");
  }
  this->_dragMouseCode = code;
  this->_dragging = 1;
  (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 41))(v3);
  v4 = (*((int (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 83))(v3);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v4 + 52))(v4, &x, y);
  this->_dragStartCursorPos[0] = x;
  this->_dragStartCursorPos[1] = y[0];
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))v3->_vptr_Panel + 1))(v3, &x, y);
  this->_dragStartPanelPos[0] = x;
  this->_dragStartPanelPos[1] = y[0];
  v5 = (*((int (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 83))(v3);
  (*(void (__cdecl **)(int, vgui::Panel *))(*(_DWORD *)v5 + 56))(v5, v3);
  if ( this->_currentPanel != v3 )
  {
    v6 = this->_vptr_BuildGroup;
    this->_currentPanel = v3;
    v6[6](this);
  }
}

void vgui::BuildGroup::addCurrentPanelChangeSignal(vgui::BuildGroup *const this, vgui::ChangeSignal *s)
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

  v2 = this->_currentPanelChangeSignalDar._count;
  v3 = &this->_currentPanelChangeSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_currentPanelChangeSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_currentPanelChangeSignalDar._capacity;
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
    v2 = this->_currentPanelChangeSignalDar._count;
    this->_currentPanelChangeSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_currentPanelChangeSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_currentPanelChangeSignalDar._data )
    {
      operator delete[](this->_currentPanelChangeSignalDar._data);
      v2 = this->_currentPanelChangeSignalDar._count;
    }
    v8 = v14;
    this->_currentPanelChangeSignalDar._data = v14;
  }
  else
  {
    v8 = this->_currentPanelChangeSignalDar._data;
  }
  v8[v2] = s;
  ++this->_currentPanelChangeSignalDar._count;
}

void vgui::BuildGroup::panelAdded(vgui::BuildGroup *const this, vgui::Panel *panel, const char *panelName)
{
  int v3; // ecx
  vgui::Dar<vgui::Panel*> *v4; // esi
  int v5; // ebp
  int v6; // eax
  vgui::Panel **v7; // edx
  vgui::Dar<char*> *v8; // esi
  char *v9; // eax
  int v10; // ecx
  int v11; // ebp
  int v12; // eax
  char **v13; // edx
  unsigned int v14; // edi
  _BYTE *v15; // eax
  _WORD *v16; // edi
  int v17; // eax
  char **v18; // eax
  unsigned int v19; // edi
  _BYTE *v20; // eax
  _WORD *v21; // edi
  int v22; // eax
  vgui::Panel **v23; // eax
  char **v24; // [esp+14h] [ebp-28h]
  vgui::Panel **v25; // [esp+14h] [ebp-28h]
  unsigned int v26; // [esp+18h] [ebp-24h]
  unsigned int v27; // [esp+18h] [ebp-24h]
  char *v28; // [esp+1Ch] [ebp-20h]

  v3 = this->_panelDar._count;
  v4 = &this->_panelDar;
  v5 = this->_panelDar._capacity;
  v6 = v3 + 1;
  if ( v3 + 1 <= v5 )
  {
    v7 = this->_panelDar._data;
    goto LABEL_3;
  }
  if ( v5 || (v5 = 1, v19 = 4, v6 > 1) )
  {
    do
      v5 *= 2;
    while ( v6 > v5 );
    v19 = 4 * v5;
  }
  v20 = (_BYTE *)operator new[](v19);
  v7 = (vgui::Panel **)v20;
  if ( !v20 )
    goto LABEL_61;
  v27 = v19;
  v21 = v20;
  if ( v27 >= 8 )
  {
    if ( ((uint8_t)v20 & 1) != 0 )
    {
      *v20 = 0;
      v21 = v20 + 1;
      --v27;
    }
    if ( ((uint8_t)v21 & 2) != 0 )
    {
      *v21++ = 0;
      v27 -= 2;
    }
    if ( ((uint8_t)v21 & 4) != 0 )
    {
      *(_DWORD *)v21 = 0;
      v21 += 2;
      v27 -= 4;
    }
    memset(v21, 0, 4 * (v27 >> 2));
    v21 += 2 * (v27 >> 2);
    LOBYTE(v27) = v27 & 3;
    if ( (v27 & 4) == 0 )
    {
LABEL_28:
      if ( (v27 & 2) == 0 )
        goto LABEL_29;
LABEL_42:
      *v21++ = 0;
      if ( (v27 & 1) == 0 )
        goto LABEL_30;
      goto LABEL_41;
    }
  }
  else if ( (v27 & 4) == 0 )
  {
    goto LABEL_28;
  }
  *(_DWORD *)v21 = 0;
  v21 += 2;
  if ( (v27 & 2) != 0 )
    goto LABEL_42;
LABEL_29:
  if ( (v27 & 1) != 0 )
LABEL_41:
    *(_BYTE *)v21 = 0;
LABEL_30:
  v3 = this->_panelDar._count;
  this->_panelDar._capacity = v5;
  if ( v3 > 0 )
  {
    v22 = 0;
    do
    {
      v7[v22] = this->_panelDar._data[v22];
      ++v22;
      v3 = v4->_count;
    }
    while ( v22 < v4->_count );
  }
  v23 = this->_panelDar._data;
  if ( v23 )
  {
    v25 = v7;
    operator delete[]((VFontData *const)v23);
    v3 = this->_panelDar._count;
    v7 = v25;
  }
  this->_panelDar._data = v7;
LABEL_3:
  v8 = &this->_panelNameDar;
  v7[v3] = panel;
  ++this->_panelDar._count;
  v9 = vgui::vgui_strdup(panelName);
  v10 = this->_panelNameDar._count;
  v11 = this->_panelNameDar._capacity;
  v28 = v9;
  v12 = v10 + 1;
  if ( v10 + 1 <= v11 )
  {
    v13 = this->_panelNameDar._data;
    goto LABEL_5;
  }
  if ( v11 || (v11 = 1, v14 = 4, v12 > 1) )
  {
    do
      v11 *= 2;
    while ( v12 > v11 );
    v14 = 4 * v11;
  }
  v15 = (_BYTE *)operator new[](v14);
  v13 = (char **)v15;
  if ( !v15 )
LABEL_61:
    exit(0);
  v26 = v14;
  v16 = v15;
  if ( v26 >= 8 )
  {
    if ( ((uint8_t)v15 & 1) != 0 )
    {
      *v15 = 0;
      v16 = v15 + 1;
      --v26;
    }
    if ( ((uint8_t)v16 & 2) != 0 )
    {
      *v16++ = 0;
      v26 -= 2;
    }
    if ( ((uint8_t)v16 & 4) != 0 )
    {
      *(_DWORD *)v16 = 0;
      v16 += 2;
      v26 -= 4;
    }
    memset(v16, 0, 4 * (v26 >> 2));
    v16 += 2 * (v26 >> 2);
    LOBYTE(v26) = v26 & 3;
  }
  if ( (v26 & 4) == 0 )
  {
    if ( (v26 & 2) == 0 )
      goto LABEL_14;
LABEL_37:
    *v16++ = 0;
    if ( (v26 & 1) == 0 )
      goto LABEL_15;
    goto LABEL_36;
  }
  *(_DWORD *)v16 = 0;
  v16 += 2;
  if ( (v26 & 2) != 0 )
    goto LABEL_37;
LABEL_14:
  if ( (v26 & 1) != 0 )
LABEL_36:
    *(_BYTE *)v16 = 0;
LABEL_15:
  v10 = this->_panelNameDar._count;
  this->_panelNameDar._capacity = v11;
  if ( v10 > 0 )
  {
    v17 = 0;
    do
    {
      v13[v17] = this->_panelNameDar._data[v17];
      ++v17;
      v10 = v8->_count;
    }
    while ( v17 < v8->_count );
  }
  v18 = this->_panelNameDar._data;
  if ( v18 )
  {
    v24 = v13;
    operator delete[]((VFontData *const)v18);
    v10 = this->_panelNameDar._count;
    v13 = v24;
  }
  this->_panelNameDar._data = v13;
LABEL_5:
  v13[v10] = v28;
  ++this->_panelNameDar._count;
}

void vgui::BuildGroup::BuildGroup(vgui::BuildGroup *const this)
{
  int v1; // eax
  int v2; // edx
  int v3; // edx
  vgui::ChangeSignal **v4; // edx
  vgui::Panel **v5; // eax
  vgui::Panel **v6; // edi
  int v7; // eax
  int v8; // edx
  char **v9; // eax
  char **v10; // edi
  int v11; // eax
  int v12; // edx
  vgui::Cursor *v13; // esi
  vgui::Cursor *v14; // esi
  vgui::Cursor *v15; // esi
  vgui::Cursor *v16; // esi
  vgui::Cursor *v17; // esi
  int v18; // [esp+1Ch] [ebp-10h]

  this->_vptr_BuildGroup = (int (**)(...))(&`vtable for'vgui::BuildGroup + 2);
  this->_currentPanelChangeSignalDar._count = 0;
  this->_currentPanelChangeSignalDar._capacity = 0;
  this->_currentPanelChangeSignalDar._data = 0;
  v1 = operator new[](0x10u);
  if ( !v1 )
    goto LABEL_20;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  v2 = this->_currentPanelChangeSignalDar._count;
  this->_currentPanelChangeSignalDar._capacity = 4;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(v1 + 4 * v3) = this->_currentPanelChangeSignalDar._data[v3];
      ++v3;
    }
    while ( v3 < this->_currentPanelChangeSignalDar._count );
  }
  v4 = this->_currentPanelChangeSignalDar._data;
  if ( v4 )
  {
    v18 = v1;
    operator delete[]((VFontData *const)v4);
    v1 = v18;
  }
  this->_currentPanelChangeSignalDar._data = (vgui::ChangeSignal **)v1;
  this->_panelDar._count = 0;
  this->_panelDar._capacity = 0;
  this->_panelDar._data = 0;
  v5 = (vgui::Panel **)operator new[](0x10u);
  v6 = v5;
  if ( !v5 )
    goto LABEL_20;
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v7 = this->_panelDar._count;
  this->_panelDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      v6[v8] = this->_panelDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_panelDar._count );
  }
  if ( this->_panelDar._data )
    operator delete[]((VFontData *const)this->_panelDar._data);
  this->_panelDar._data = v6;
  this->_panelNameDar._count = 0;
  this->_panelNameDar._capacity = 0;
  this->_panelNameDar._data = 0;
  v9 = (char **)operator new[](0x10u);
  v10 = v9;
  if ( !v9 )
LABEL_20:
    exit(0);
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v11 = this->_panelNameDar._count;
  this->_panelNameDar._capacity = 4;
  if ( v11 > 0 )
  {
    v12 = 0;
    do
    {
      v10[v12] = this->_panelNameDar._data[v12];
      ++v12;
    }
    while ( v12 < this->_panelNameDar._count );
  }
  if ( this->_panelNameDar._data )
    operator delete[]((VFontData *const)this->_panelNameDar._data);
  this->_panelNameDar._data = v10;
  this->_enabled = 0;
  this->_snapX = 4;
  this->_snapY = 4;
  v13 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v13, dc_sizenwse);
  this->_cursor_sizenwse = v13;
  v14 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v14, dc_sizenesw);
  this->_cursor_sizenesw = v14;
  v15 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v15, dc_sizewe);
  this->_cursor_sizewe = v15;
  v16 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v16, dc_sizens);
  this->_cursor_sizens = v16;
  v17 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v17, dc_sizeall);
  this->_cursor_sizeall = v17;
  this->_currentPanel = 0;
  this->_dragging = 0;
}

