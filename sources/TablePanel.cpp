#include <VGUI_TablePanel.h>

void vgui::TablePanel::setCellEditingEnabled(vgui::TablePanel *const this, bool state)
{
  this->_cellEditingEnabled = state;
}

void vgui::TablePanel::setGridSize(vgui::TablePanel *const this, int wide, int tall)
{
  this->_gridWide = wide;
  this->_gridTall = tall;
}

void vgui::TablePanel::setGridVisible(vgui::TablePanel *const this, bool horizontal, bool vertical)
{
  this->_gridVisible[0] = horizontal;
  this->_gridVisible[1] = horizontal;
}

int vgui::TablePanel::getColumnCount(vgui::TablePanel *const this)
{
  return this->_columnDar._count;
}

void vgui::TablePanel::setColumnExtents(vgui::TablePanel *const this, int column, int x0, int x1)
{
  int v4; // ecx

  v4 = x1;
  if ( column >= 0 && column < this->_columnDar._count )
  {
    v4 = (x0 << 12) + x1;
    this->_columnDar._data[column] = v4;
  }
  (*((void (__thiscall **)(int, vgui::TablePanel *const))this->_vptr_Panel + 12))(v4, this);
}

void vgui::TablePanel::setSelectedCell(vgui::TablePanel *const this, int column, int row)
{
  if ( this->_selectedCell[0] != column || this->_selectedCell[1] != row )
  {
    (*((void (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 12))(this);
    (*((void (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 140))(this);
  }
  this->_selectedCell[0] = column;
  this->_selectedCell[1] = row;
}

void vgui::TablePanel::getSelectedCell(vgui::TablePanel *const this, int *const column, int *const row)
{
  *(_QWORD *)column = *(_QWORD *)this->_selectedCell;
}

void vgui::TablePanel::setColumnSelectionEnabled(vgui::TablePanel *const this, bool state)
{
  this->_columnSelectionEnabled = state;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

void vgui::TablePanel::setRowSelectionEnabled(vgui::TablePanel *const this, bool state)
{
  this->_rowSelectionEnabled = state;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

void vgui::TablePanel::setCellSectionEnabled(vgui::TablePanel *const this, bool state)
{
  this->_cellSelectionEnabled = state;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

void vgui::TablePanel::setEditableCell(vgui::TablePanel *const this, int column, int row)
{
  vgui::Panel *v3; // eax

  if ( this->_editableCell[0] != column || this->_editableCell[1] != row )
  {
    (*((void (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 140))(this);
    v3 = (vgui::Panel *)(*((int (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 144))(
                          this,
                          column,
                          row);
    this->_editableCellPanel = v3;
    if ( v3 )
      (*((void (__cdecl **)(vgui::Panel *, vgui::TablePanel *const))v3->_vptr_Panel + 16))(v3, this);
  }
  this->_editableCell[0] = column;
  this->_editableCell[1] = row;
}

void vgui::TablePanel::stopCellEditing(vgui::TablePanel *const this)
{
  vgui::Panel *v1; // eax

  v1 = this->_editableCellPanel;
  if ( v1 )
  {
    (*((void (__cdecl **)(vgui::Panel *, _DWORD))v1->_vptr_Panel + 16))(this->_editableCellPanel, 0);
    this->_editableCellPanel = 0;
    this->_editableCell[0] = -1;
    this->_editableCell[1] = -1;
  }
}

void vgui::TablePanel::getVirtualSize(vgui::TablePanel *const this, int *const wide, int *const tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_virtualSize;
}

void vgui::TablePanel::paint(vgui::TablePanel *const this)
{
  int v1; // esi
  int v2; // edi
  int v3; // esi
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // ebp
  int v9; // edx
  int v10; // esi
  int v11; // edi
  bool v12; // dl
  bool v13; // al
  int v14; // eax
  int v15; // eax
  vgui::Panel *v16; // eax
  int v17; // eax
  int j; // [esp+4h] [ebp-88h]
  int v19; // [esp+24h] [ebp-68h]
  bool cellSelected; // [esp+28h] [ebp-64h]
  void (__cdecl *cellSelecteda)(int, int, int, int, int); // [esp+28h] [ebp-64h]
  void (__cdecl *cellSelectedb)(vgui::Panel *, int, int, int, int); // [esp+28h] [ebp-64h]
  int v23; // [esp+2Ch] [ebp-60h]
  int x0; // [esp+30h] [ebp-5Ch]
  int i; // [esp+34h] [ebp-58h]
  int x1gap; // [esp+38h] [ebp-54h]
  int x0gap; // [esp+3Ch] [ebp-50h]
  vgui::Color fgColor; // [esp+4Ch] [ebp-40h] BYREF
  int wide; // [esp+58h] [ebp-34h] BYREF
  int tall; // [esp+5Ch] [ebp-30h] BYREF
  int r; // [esp+60h] [ebp-2Ch] BYREF
  int g; // [esp+64h] [ebp-28h] BYREF
  int b; // [esp+68h] [ebp-24h] BYREF
  int a[8]; // [esp+6Ch] [ebp-20h] BYREF

  x1gap = this->_gridWide - (this->_gridWide / 2 - 1);
  x0gap = this->_gridWide / 2 - 1;
  (*((void (__cdecl **)(vgui::TablePanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  vgui::Color::Color(&fgColor);
  (*((void (__cdecl **)(vgui::TablePanel *const, vgui::Color *))this->_vptr_Panel + 80))(this, &fgColor);
  vgui::Color::getColor(&fgColor, &r, &g, &b, a);
  if ( this->_gridVisible[1] )
  {
    v1 = 0;
    if ( this->_columnDar._count > 0 )
    {
      v2 = 0;
      do
      {
        v3 = this->_columnDar._data[v2++];
        v1 = v3 & 0xFFF;
        (*((void (__cdecl **)(vgui::TablePanel *const, int, int, int, int))this->_vptr_Panel + 94))(this, r, g, b, a[0]);
        (*((void (__cdecl **)(vgui::TablePanel *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
          this,
          v1 - x1gap,
          0,
          x0gap + v1,
          tall);
      }
      while ( this->_columnDar._count > v2 );
    }
  }
  if ( this->_gridVisible[0] )
  {
    v4 = 0;
    v5 = 0;
    while ( v4 < (*((int (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 141))(this) )
    {
      (*((void (__cdecl **)(vgui::TablePanel *const, int, int, int, int))this->_vptr_Panel + 94))(this, r, g, b, a[0]);
      (*((void (__cdecl **)(vgui::TablePanel *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
        this,
        0,
        v5,
        v1,
        v5 + this->_gridTall);
      j = v4++;
      v5 += this->_gridTall + (*((int (__cdecl **)(vgui::TablePanel *const, int))this->_vptr_Panel + 142))(this, j);
    }
  }
  v6 = this->_columnDar._count;
  this->_virtualSize[0] = 0;
  this->_virtualSize[1] = 0;
  if ( v6 > 0 )
  {
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      x0 = x0gap + ((this->_columnDar._data[v8] >> 12) & 0xFFF);
      v9 = (this->_columnDar._data[v8] & 0xFFF) - x1gap;
      v23 = v9;
      if ( v9 > v7 )
        this->_virtualSize[0] = v9;
      v10 = 0;
      v11 = this->_gridTall;
      for ( i = v9 - x0; v10 < (*((int (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 141))(this); ++v10 )
      {
        v12 = 0;
        if ( this->_columnSelectionEnabled )
          v12 = v8 == this->_selectedCell[0];
        v13 = 0;
        if ( this->_rowSelectionEnabled )
          v13 = v10 == this->_selectedCell[1];
        cellSelected = 0;
        if ( this->_cellSelectionEnabled && this->_selectedCell[0] == v8 )
          cellSelected = v10 == this->_selectedCell[1];
        if ( this->_editableCell[0] == v8 && this->_editableCell[1] == v10 )
        {
          v16 = this->_editableCellPanel;
          if ( v16 )
          {
            cellSelectedb = (void (__cdecl *)(vgui::Panel *, int, int, int, int))*((_DWORD *)v16->_vptr_Panel + 4);
            v17 = (*((int (__cdecl **)(vgui::TablePanel *const, int))this->_vptr_Panel + 142))(this, v10);
            cellSelectedb(this->_editableCellPanel, x0, v11, i, v17);
            (*((void (__cdecl **)(vgui::Panel *))this->_editableCellPanel->_vptr_Panel + 12))(this->_editableCellPanel);
            (*((void (__cdecl **)(vgui::Panel *))this->_editableCellPanel->_vptr_Panel + 88))(this->_editableCellPanel);
          }
        }
        else
        {
          v14 = (*((int (__cdecl **)(vgui::TablePanel *const, int, int, bool, bool, bool))this->_vptr_Panel + 143))(
                  this,
                  v8,
                  v10,
                  v12,
                  v13,
                  cellSelected);
          if ( v14 )
          {
            v19 = v14;
            (*(void (__cdecl **)(int, vgui::TablePanel *const))(*(_DWORD *)v14 + 64))(v14, this);
            cellSelecteda = *(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)v19 + 16);
            v15 = (*((int (__cdecl **)(vgui::TablePanel *const, int))this->_vptr_Panel + 142))(this, v10);
            cellSelecteda(v19, x0, v11, i, v15);
            (*(void (__cdecl **)(int))(*(_DWORD *)v19 + 48))(v19);
            (*(void (__cdecl **)(int))(*(_DWORD *)v19 + 352))(v19);
            (*(void (__cdecl **)(int))(*(_DWORD *)v19 + 356))(v19);
            (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)v19 + 64))(v19, 0);
          }
        }
        v11 += this->_gridTall + (*((int (__cdecl **)(vgui::TablePanel *const, int))this->_vptr_Panel + 142))(this, v10);
        if ( v11 > this->_virtualSize[1] )
          this->_virtualSize[1] = v23;
      }
      if ( this->_columnDar._count <= ++v8 )
        break;
      v7 = this->_virtualSize[0];
    }
  }
}

void vgui::TablePanel::setHeaderPanel(vgui::TablePanel *const this, vgui::HeaderPanel *header)
{
  void (__cdecl *v2)(vgui::HeaderPanel *, _DWORD *); // edi
  _DWORD *v3; // eax

  v2 = (void (__cdecl *)(vgui::HeaderPanel *, _DWORD *))*((_DWORD *)header->_vptr_Panel + 131);
  v3 = operator new(0x10u);
  v3[3] = this;
  *v3 = &`vtable for'vgui::FooVGuiTablePanelHandler + 2;
  v3[1] = &`vtable for'vgui::FooVGuiTablePanelHandler + 17;
  v3[2] = &`vtable for'vgui::FooVGuiTablePanelHandler + 30;
  v2(header, v3);
  (*((void (__cdecl **)(vgui::HeaderPanel *))header->_vptr_Panel + 132))(header);
  (*((void (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::TablePanel::privateMousePressed(vgui::TablePanel *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  if ( this->_cellEditingEnabled )
  {
    (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 133))(
      this,
      this->_mouseOverCell[0],
      this->_mouseOverCell[1]);
    (*((void (__cdecl **)(vgui::TablePanel *const))this->_vptr_Panel + 41))(this);
  }
}

void vgui::TablePanel::privateMouseDoublePressed(vgui::TablePanel *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  int v3; // [esp+18h] [ebp-14h] BYREF
  int v4[4]; // [esp+1Ch] [ebp-10h] BYREF

  if ( this->_cellEditingEnabled )
  {
    (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 133))(
      this,
      this->_mouseOverCell[0],
      this->_mouseOverCell[1]);
    (*((void (__cdecl **)(vgui::TablePanel *const, int *, int *))this->_vptr_Panel + 134))(this, &v3, v4);
    (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 139))(this, v3, v4[0]);
  }
}

void vgui::TablePanel::privateKeyTyped(vgui::TablePanel *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  int v3; // eax
  int v4; // eax
  int v5[4]; // [esp+10h] [ebp-2Ch] BYREF
  int v6[7]; // [esp+20h] [ebp-1Ch] BYREF

  if ( this->_cellEditingEnabled )
  {
    (*((void (__cdecl **)(vgui::TablePanel *const, int *, int *))this->_vptr_Panel + 134))(this, v5, v6);
    switch ( code )
    {
      case KEY_ENTER:
        (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 139))(this, v5[0], v6[0]);
        return;
      case KEY_UP:
        v4 = --v6[0];
        if ( v6[0] < 0 )
        {
          v6[0] = 0;
          v4 = 0;
        }
        goto LABEL_6;
      case KEY_LEFT:
        v3 = --v5[0];
        if ( v5[0] < 0 )
        {
          v5[0] = 0;
          v3 = 0;
        }
        goto LABEL_4;
      case KEY_DOWN:
        v4 = ++v6[0];
LABEL_6:
        (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 133))(this, v5[0], v4);
        return;
      case KEY_RIGHT:
        v3 = ++v5[0];
LABEL_4:
        (*((void (__cdecl **)(vgui::TablePanel *const, int, int))this->_vptr_Panel + 133))(this, v3, v6[0]);
        break;
      default:
        return;
    }
  }
}

void vgui::TablePanel::setColumnCount(vgui::TablePanel *const this, int columnCount)
{
  int v2; // esi
  unsigned int v3; // edi
  _BYTE *v4; // eax
  int *v5; // edx
  _WORD *v6; // edi
  int v7; // eax
  int v8; // eax
  int *v9; // eax
  int *v10; // [esp+18h] [ebp-24h]
  unsigned int v11; // [esp+1Ch] [ebp-20h]

  v2 = this->_columnDar._capacity;
  if ( columnCount <= v2 )
    goto LABEL_2;
  if ( v2 || (v2 = 1, v3 = 4, columnCount > 1) )
  {
    do
      v2 *= 2;
    while ( columnCount > v2 );
    v3 = 4 * v2;
  }
  v4 = (_BYTE *)operator new[](v3);
  v5 = (int *)v4;
  if ( !v4 )
    exit(0);
  v11 = v3;
  v6 = v4;
  if ( v11 >= 8 )
  {
    if ( ((uint8_t)v4 & 1) != 0 )
    {
      *v4 = 0;
      v6 = v4 + 1;
      --v11;
    }
    if ( ((uint8_t)v6 & 2) != 0 )
    {
      *v6++ = 0;
      v11 -= 2;
    }
    if ( ((uint8_t)v6 & 4) != 0 )
    {
      *(_DWORD *)v6 = 0;
      v6 += 2;
      v11 -= 4;
    }
    memset(v6, 0, 4 * (v11 >> 2));
    v6 += 2 * (v11 >> 2);
    LOBYTE(v11) = v11 & 3;
    if ( (v11 & 4) == 0 )
    {
LABEL_13:
      if ( (v11 & 2) == 0 )
        goto LABEL_14;
LABEL_22:
      *v6++ = 0;
      if ( (v11 & 1) == 0 )
        goto LABEL_15;
      goto LABEL_21;
    }
  }
  else if ( (v11 & 4) == 0 )
  {
    goto LABEL_13;
  }
  *(_DWORD *)v6 = 0;
  v6 += 2;
  if ( (v11 & 2) != 0 )
    goto LABEL_22;
LABEL_14:
  if ( (v11 & 1) != 0 )
LABEL_21:
    *(_BYTE *)v6 = 0;
LABEL_15:
  v7 = this->_columnDar._count;
  this->_columnDar._capacity = v2;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      v5[v8] = this->_columnDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_columnDar._count );
  }
  v9 = this->_columnDar._data;
  if ( v9 )
  {
    v10 = v5;
    operator delete[](v9);
    v5 = v10;
  }
  this->_columnDar._data = v5;
LABEL_2:
  if ( columnCount >= 0 && columnCount <= this->_columnDar._capacity )
    this->_columnDar._count = columnCount;
}

void vgui::TablePanel::TablePanel(vgui::TablePanel *const this, int x, int y, int wide, int tall, int columnCount)
{
  int *v6; // eax
  int v7; // edx
  vgui::Dar<int> *v8; // esi
  int v9; // edi
  int v10; // ecx
  VFontData *v11; // ecx
  int v12; // ebp
  vgui::Panel *v13; // esi
  vgui::InputSignal *v14; // eax
  unsigned int v15; // edi
  _BYTE *v16; // eax
  _WORD *v17; // edi
  int v18; // edi
  int v19; // eax
  VFontData *v20; // eax
  int v21; // [esp+20h] [ebp-3Ch]
  int *v22; // [esp+24h] [ebp-38h]
  unsigned int v23; // [esp+28h] [ebp-34h]
  int *v24; // [esp+2Ch] [ebp-30h]
  vgui::Color p_color; // [esp+34h] [ebp-28h] BYREF

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_columnDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TablePanel + 2);
  this->_columnDar._count = 0;
  this->_columnDar._data = 0;
  v6 = (int *)operator new[](0x10u);
  v7 = columnCount;
  if ( !v6 )
    goto LABEL_40;
  *v6 = 0;
  v6[1] = 0;
  v8 = &this->_columnDar;
  v6[2] = 0;
  v6[3] = 0;
  v9 = this->_columnDar._count;
  this->_columnDar._capacity = 4;
  if ( v9 > 0 )
  {
    v10 = 0;
    do
    {
      v6[v10] = this->_columnDar._data[v10];
      ++v10;
    }
    while ( v10 < v8->_count );
  }
  v11 = (VFontData *)this->_columnDar._data;
  if ( v11 )
  {
    v22 = v6;
    operator delete[](v11);
    v7 = columnCount;
    v6 = v22;
  }
  this->_gridWide = 2;
  v12 = this->_columnDar._capacity;
  this->_columnDar._data = v6;
  this->_gridTall = 2;
  this->_gridVisible[0] = 0;
  this->_gridVisible[1] = 0;
  if ( v7 > v12 )
  {
    if ( v12 || (v12 = 1, v15 = 4, v7 > 1) )
    {
      do
        v12 *= 2;
      while ( v7 > v12 );
      v15 = 4 * v12;
    }
    v21 = v7;
    v16 = (_BYTE *)operator new[](v15);
    v7 = v21;
    v24 = (int *)v16;
    if ( v16 )
    {
      v23 = v15;
      v17 = v16;
      if ( v23 >= 8 )
      {
        if ( ((uint8_t)v16 & 1) != 0 )
        {
          *v16 = 0;
          --v23;
          v17 = v16 + 1;
        }
        if ( ((uint8_t)v17 & 2) != 0 )
        {
          *v17++ = 0;
          v23 -= 2;
        }
        if ( ((uint8_t)v17 & 4) != 0 )
        {
          *(_DWORD *)v17 = 0;
          v17 += 2;
          v23 -= 4;
        }
        memset(v17, 0, 4 * (v23 >> 2));
        v17 += 2 * (v23 >> 2);
        LOBYTE(v23) = v23 & 3;
        if ( (v23 & 4) == 0 )
        {
LABEL_19:
          if ( (v23 & 2) == 0 )
            goto LABEL_20;
          goto LABEL_28;
        }
      }
      else if ( (v23 & 4) == 0 )
      {
        goto LABEL_19;
      }
      *(_DWORD *)v17 = 0;
      v17 += 2;
      if ( (v23 & 2) == 0 )
      {
LABEL_20:
        if ( (v23 & 1) == 0 )
        {
LABEL_21:
          v18 = this->_columnDar._count;
          this->_columnDar._capacity = v12;
          if ( v18 > 0 )
          {
            v19 = 0;
            do
            {
              v24[v19] = this->_columnDar._data[v19];
              ++v19;
            }
            while ( v19 < v8->_count );
          }
          v20 = (VFontData *)this->_columnDar._data;
          if ( v20 )
          {
            operator delete[](v20);
            v7 = v21;
          }
          this->_columnDar._data = v24;
          goto LABEL_8;
        }
LABEL_27:
        *(_BYTE *)v17 = 0;
        goto LABEL_21;
      }
LABEL_28:
      *v17++ = 0;
      if ( (v23 & 1) == 0 )
        goto LABEL_21;
      goto LABEL_27;
    }
LABEL_40:
    exit(0);
  }
LABEL_8:
  if ( v7 >= 0 && v7 <= this->_columnDar._capacity )
    this->_columnDar._count = v7;
  vgui::Color::Color(&p_color, sc_black);
  vgui::Panel::setFgColor(this, &p_color);
  this->_selectedCell[0] = -1;
  this->_selectedCell[1] = -1;
  v13 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v13);
  this->_mouseOverCell[0] = 0;
  this->_mouseOverCell[1] = 0;
  this->_fakeInputPanel = v13;
  this->_editableCell[0] = -1;
  this->_editableCell[1] = -1;
  this->_virtualSize[0] = wide;
  this->_editableCellPanel = 0;
  this->_columnSelectionEnabled = 0;
  this->_rowSelectionEnabled = 1;
  this->_cellSelectionEnabled = 1;
  this->_virtualSize[1] = tall;
  this->_cellEditingEnabled = 1;
  v14 = (vgui::InputSignal *)operator new(0x10u);
  v14[3]._vptr_InputSignal = (int (**)(...))this;
  v14->_vptr_InputSignal = (int (**)(...))(&`vtable for'vgui::FooVGuiTablePanelHandler + 2);
  v14[1]._vptr_InputSignal = (int (**)(...))(&`vtable for'vgui::FooVGuiTablePanelHandler + 17);
  v14[2]._vptr_InputSignal = (int (**)(...))(&`vtable for'vgui::FooVGuiTablePanelHandler + 30);
  vgui::Panel::addInputSignal(this, v14 + 1);
}

