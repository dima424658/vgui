#include <VGUI_TextGrid.h>

void vgui::TextGrid::setXY(vgui::TextGrid *const this, int x, int y)
{
  this->_xy[0] = x;
  this->_xy[1] = y;
}

void vgui::TextGrid::paintBackground(vgui::TextGrid *const this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // ebp
  int v10; // edi
  char v11; // bl
  int v12; // [esp+20h] [ebp-4Ch]
  int fwide; // [esp+24h] [ebp-48h]
  int v14; // [esp+28h] [ebp-44h]
  int ftall; // [esp+2Ch] [ebp-40h]
  int abc[3]; // [esp+34h] [ebp-38h] BYREF
  int r; // [esp+40h] [ebp-2Ch] BYREF
  int g; // [esp+44h] [ebp-28h] BYREF
  int b; // [esp+48h] [ebp-24h] BYREF
  int a[8]; // [esp+4Ch] [ebp-20h] BYREF

  vgui::Panel::paintBackground(this);
  v2 = (*((int (__cdecl **)(vgui::TextGrid *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 84))(v2);
  v4 = (*(int (__cdecl **)(int, int))(*(_DWORD *)v3 + 12))(v3, 2);
  (*(void (__cdecl **)(int, int, int *, int *, int *))(*(_DWORD *)v4 + 8))(v4, 87, abc, &abc[1], &abc[2]);
  fwide = abc[2] + abc[1] + abc[0];
  ftall = (*(int (__cdecl **)(int))(*(_DWORD *)v4 + 16))(v4);
  (*((void (__cdecl **)(vgui::TextGrid *const, int))this->_vptr_Panel + 97))(this, 2);
  v5 = this->_gridSize[1];
  if ( v5 <= 0 )
    return;
  v6 = this->_gridSize[0];
  v7 = 0;
  v14 = 0;
  do
  {
    if ( v6 <= 0 )
      goto LABEL_10;
    v8 = v6;
    v9 = 0;
    v10 = 0;
    while ( 1 )
    {
      v11 = this->_grid[7 * v10 + 7 * v7 * v6];
      if ( v11 )
        break;
      ++v10;
      v9 += fwide;
      if ( v10 >= v8 )
        goto LABEL_9;
LABEL_6:
      v6 = v8;
    }
    ++v10;
    v12 = v7;
    (*((void (__cdecl **)(vgui::TextGrid *const, int *, int *, int *, int *))this->_vptr_Panel + 75))(
      this,
      &r,
      &g,
      &b,
      a);
    (*((void (__cdecl **)(vgui::TextGrid *const, int, int, int, int))this->_vptr_Panel + 100))(this, r, g, b, a[0]);
    (*((void (__cdecl **)(vgui::TextGrid *const, int, int, _DWORD))this->_vptr_Panel + 105))(this, v9, v14, v11);
    v8 = this->_gridSize[0];
    v7 = v12;
    v9 += fwide;
    if ( v10 < v8 )
      goto LABEL_6;
LABEL_9:
    v5 = this->_gridSize[1];
    v6 = v8;
LABEL_10:
    ++v7;
    v14 += ftall;
  }
  while ( v7 < v5 );
}

int vgui::TextGrid::printf(vgui::TextGrid *const this, const char *format, ...)
{
  va_list va; // [esp+28h] [ebp+Ch] BYREF

  va_start(va, format);
  return (*((int (__cdecl **)(vgui::TextGrid *const, const char *, char *))this->_vptr_Panel + 130))(this, format, va);
}

int vgui::TextGrid::vprintf(vgui::TextGrid *const this, const char *format, va_list argList)
{
  int v3; // edi
  int v4; // edx
  int v5; // ecx
  int v6; // ebp
  char v7; // al
  int ret; // [esp+1Ch] [ebp-820h]
  char buf[2048]; // [esp+20h] [ebp-81Ch] BYREF

  v3 = 0;
  ret = vsprintf(buf, format, argList);
  while ( 1 )
  {
    v7 = buf[v3];
    if ( !v7 )
      break;
    if ( v7 == 10 )
    {
      ++v3;
      (*((void (__cdecl **)(vgui::TextGrid *const))this->_vptr_Panel + 128))(this);
      if ( v3 == 2048 )
        break;
    }
    else
    {
      v4 = this->_xy[0];
      if ( v4 >= 0 )
      {
        v5 = this->_gridSize[0];
        if ( v4 < v5 )
        {
          v6 = this->_xy[1];
          if ( v6 >= 0 && v6 < this->_gridSize[1] )
          {
            this->_grid[7 * v6 * v5 + 7 * v4] = v7;
            ++this->_xy[0];
          }
        }
      }
      if ( ++v3 == 2048 )
        break;
    }
  }
  (*((void (__cdecl **)(vgui::TextGrid *const))this->_vptr_Panel + 12))(this);
  return ret;
}

void vgui::TextGrid::newLine(vgui::TextGrid *const this)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ebx
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // ebx
  char *v7; // edi
  int v8; // esi
  int v9; // ebx
  int i; // eax
  int v11; // ecx
  char *v12; // ecx
  char *v13; // ebp
  int v14; // eax
  char *v15; // ecx
  bool v16; // cf
  char *v17; // edi
  char *v18; // esi
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // ebx
  char *v22; // edi
  int v23; // ecx
  __int16 v24; // cx
  unsigned int v25; // ecx
  unsigned int v26; // ecx
  int v27; // [esp+0h] [ebp-18h]

  v1 = this->_gridSize[1];
  v2 = this->_xy[1];
  if ( v2 == v1 - 1 )
  {
    if ( v1 > 1 )
    {
      v3 = this->_gridSize[0];
      v4 = this->_xy[0];
      v5 = v3 * v2;
      v6 = v3 - v4;
      v7 = &this->_grid[7 * v4 + 7 * v5];
      if ( v6 >= 8 )
      {
        if ( ((uint8_t)v7 & 1) != 0 )
        {
          *v7 = 0;
          --v6;
          ++v7;
        }
        if ( ((uint8_t)v7 & 2) != 0 )
        {
          *(_WORD *)v7 = 0;
          v6 -= 2;
          v7 += 2;
        }
        if ( ((uint8_t)v7 & 4) != 0 )
        {
          *(_DWORD *)v7 = 0;
          v6 -= 4;
          v7 += 4;
        }
        v26 = v6 >> 2;
        LOBYTE(v6) = v6 & 3;
        memset(v7, 0, 4 * v26);
        v7 += 4 * v26;
      }
      if ( (v6 & 4) != 0 )
      {
        *(_DWORD *)v7 = 0;
        v7 += 4;
      }
      if ( (v6 & 2) != 0 )
      {
        *(_WORD *)v7 = 0;
        v7 += 2;
      }
      if ( (v6 & 1) != 0 )
        *v7 = 0;
      if ( this->_gridSize[1] > 1 )
      {
        v8 = this->_gridSize[0];
        v9 = 1;
        v27 = 0;
        for ( i = 0; ; i = v27 )
        {
          v12 = this->_grid;
          v13 = &v12[v8 * i];
          v14 = 7 * v8;
          v15 = &v12[8 * v8 * v9 - v8 * v9];
          v16 = (unsigned int)(7 * v8) < 8;
          v17 = v13;
          v18 = v15;
          if ( !v16 )
          {
            if ( ((uint8_t)v13 & 1) != 0 )
            {
              v17 = v13 + 1;
              v18 = v15 + 1;
              --v14;
              *v13 = *v15;
            }
            if ( ((uint8_t)v17 & 2) != 0 )
            {
              v24 = *(_WORD *)v18;
              v14 -= 2;
              v18 += 2;
              *(_WORD *)v17 = v24;
              v17 += 2;
            }
            if ( ((uint8_t)v17 & 4) != 0 )
            {
              v23 = *(_DWORD *)v18;
              v14 -= 4;
              v18 += 4;
              *(_DWORD *)v17 = v23;
              v17 += 4;
            }
            v19 = v14;
            LOBYTE(v14) = v14 & 3;
            v19 >>= 2;
            qmemcpy(v17, v18, 4 * v19);
            v18 += 4 * v19;
            v17 += 4 * v19;
          }
          v11 = 0;
          if ( (v14 & 4) != 0 )
          {
            *(_DWORD *)v17 = *(_DWORD *)v18;
            v11 = 4;
          }
          if ( (v14 & 2) != 0 )
          {
            *(_WORD *)&v17[v11] = *(_WORD *)&v18[v11];
            v11 += 2;
          }
          if ( (v14 & 1) != 0 )
            v17[v11] = v18[v11];
          ++v9;
          v27 += 7;
          if ( v9 >= this->_gridSize[1] )
            break;
          v8 = this->_gridSize[0];
        }
      }
      v20 = this->_gridSize[0];
      v21 = 7 * v20;
      v22 = &this->_grid[7 * v20 * this->_xy[1]];
      if ( (unsigned int)(7 * v20) >= 8 )
      {
        if ( ((uint8_t)v22 & 1) != 0 )
        {
          *v22 = 0;
          --v21;
          ++v22;
        }
        if ( ((uint8_t)v22 & 2) != 0 )
        {
          *(_WORD *)v22 = 0;
          v21 -= 2;
          v22 += 2;
        }
        if ( ((uint8_t)v22 & 4) != 0 )
        {
          *(_DWORD *)v22 = 0;
          v21 -= 4;
          v22 += 4;
        }
        v25 = v21 >> 2;
        LOBYTE(v21) = v21 & 3;
        memset(v22, 0, 4 * v25);
        v22 += 4 * v25;
      }
      if ( (v21 & 4) != 0 )
      {
        *(_DWORD *)v22 = 0;
        v22 += 4;
      }
      if ( (v21 & 2) != 0 )
      {
        *(_WORD *)v22 = 0;
        v22 += 2;
      }
      if ( (v21 & 1) != 0 )
        *v22 = 0;
    }
    this->_xy[0] = 0;
  }
  else
  {
    this->_xy[0] = 0;
    this->_xy[1] = v2 + 1;
  }
}

void vgui::TextGrid::setGridSize(vgui::TextGrid *const this, int wide, int tall)
{
  char *v3; // eax
  unsigned int v4; // edx
  _WORD *v5; // edi
  unsigned int v6; // ecx

  if ( tall > 0 && wide > 0 )
  {
    if ( this->_grid )
      operator delete[](this->_grid);
    v3 = (char *)operator new[](7 * tall * wide);
    v4 = 7 * tall * wide;
    this->_grid = v3;
    v5 = v3;
    if ( v4 >= 8 )
    {
      if ( ((uint8_t)v3 & 1) != 0 )
      {
        *v3 = 0;
        v5 = v3 + 1;
        --v4;
      }
      if ( ((uint8_t)v5 & 2) != 0 )
      {
        *v5 = 0;
        v4 -= 2;
        ++v5;
      }
      if ( ((uint8_t)v5 & 4) != 0 )
      {
        *(_DWORD *)v5 = 0;
        v4 -= 4;
        v5 += 2;
      }
      v6 = v4;
      LOBYTE(v4) = v4 & 3;
      v6 >>= 2;
      memset(v5, 0, 4 * v6);
      v5 += 2 * v6;
      if ( (v4 & 4) == 0 )
      {
LABEL_7:
        if ( (v4 & 2) == 0 )
          goto LABEL_8;
        goto LABEL_12;
      }
    }
    else if ( (v4 & 4) == 0 )
    {
      goto LABEL_7;
    }
    *(_DWORD *)v5 = 0;
    v5 += 2;
    if ( (v4 & 2) == 0 )
    {
LABEL_8:
      if ( (v4 & 1) == 0 )
      {
LABEL_9:
        this->_gridSize[0] = wide;
        this->_gridSize[1] = tall;
        return;
      }
LABEL_11:
      *(_BYTE *)v5 = 0;
      this->_gridSize[0] = wide;
      this->_gridSize[1] = tall;
      return;
    }
LABEL_12:
    *v5++ = 0;
    if ( (v4 & 1) == 0 )
      goto LABEL_9;
    goto LABEL_11;
  }
}

void vgui::TextGrid::TextGrid(vgui::TextGrid *const this, int gridWide, int gridTall, int x, int y, int wide, int tall)
{
  char *v7; // eax
  unsigned int v8; // edx
  _WORD *v9; // edi
  unsigned int v10; // ecx

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_grid = 0;
  this->_gridSize[0] = 0;
  this->_gridSize[1] = 0;
  this->_xy[0] = 0;
  this->_xy[1] = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TextGrid + 2);
  vgui::Panel::setBgColor(this, 255, 255, 255, 0);
  vgui::Panel::setFgColor(this, 0, 0, 0, 0);
  if ( gridTall > 0 && gridWide > 0 )
  {
    if ( this->_grid )
      operator delete[]((VFontData *const)this->_grid);
    v7 = (char *)operator new[](7 * gridTall * gridWide);
    v8 = 7 * gridTall * gridWide;
    this->_grid = v7;
    v9 = v7;
    if ( v8 >= 8 )
    {
      if ( ((uint8_t)v7 & 1) != 0 )
      {
        *v7 = 0;
        v9 = v7 + 1;
        --v8;
      }
      if ( ((uint8_t)v9 & 2) != 0 )
      {
        *v9 = 0;
        v8 -= 2;
        ++v9;
      }
      if ( ((uint8_t)v9 & 4) != 0 )
      {
        *(_DWORD *)v9 = 0;
        v8 -= 4;
        v9 += 2;
      }
      v10 = v8;
      LOBYTE(v8) = v8 & 3;
      v10 >>= 2;
      memset(v9, 0, 4 * v10);
      v9 += 2 * v10;
      if ( (v8 & 4) == 0 )
      {
LABEL_7:
        if ( (v8 & 2) == 0 )
          goto LABEL_8;
        goto LABEL_12;
      }
    }
    else if ( (v8 & 4) == 0 )
    {
      goto LABEL_7;
    }
    *(_DWORD *)v9 = 0;
    v9 += 2;
    if ( (v8 & 2) == 0 )
    {
LABEL_8:
      if ( (v8 & 1) == 0 )
      {
LABEL_9:
        this->_gridSize[0] = gridWide;
        this->_gridSize[1] = gridTall;
        return;
      }
LABEL_11:
      *(_BYTE *)v9 = 0;
      this->_gridSize[0] = gridWide;
      this->_gridSize[1] = gridTall;
      return;
    }
LABEL_12:
    *v9++ = 0;
    if ( (v8 & 1) == 0 )
      goto LABEL_9;
    goto LABEL_11;
  }
}

