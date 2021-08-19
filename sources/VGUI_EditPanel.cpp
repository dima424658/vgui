#include <VGUI_EditPanel.h>

void vgui::EditPanel::paintBackground(vgui::EditPanel *const this)
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::EditPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 93))(this, 2);
  (*((void (__cdecl **)(vgui::EditPanel *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
    this,
    0,
    0,
    wide,
    tall[0]);
}

void vgui::EditPanel::setChar(vgui::EditPanel *const this, vgui::Dar<char> *lineDar, int x, char ch_0)
{
  (*((void (__cdecl **)(vgui::EditPanel *const, vgui::Dar<char> *, int, _DWORD, int))this->_vptr_Panel + 145))(
    this,
    lineDar,
    x,
    ch_0,
    32);
}

int vgui::EditPanel::getLineCount(vgui::EditPanel *const this)
{
  return this->_lineDarDar._count;
}

int vgui::EditPanel::getVisibleLineCount(vgui::EditPanel *const this)
{
  vgui::Font *v1; // eax
  int v2; // ebx
  int v4; // eax
  int v5; // eax
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::EditPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v1 = this->_font;
  if ( !v1 )
  {
    v4 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 83))(this);
    v5 = (*(int (__cdecl **)(int))(*(_DWORD *)v4 + 84))(v4);
    v1 = (vgui::Font *)(*(int (__cdecl **)(int, int))(*(_DWORD *)v5 + 12))(v5, 1);
  }
  v2 = tall[0];
  return v2 / (*((int (__cdecl **)(vgui::Font *))v1->_vptr_Font + 4))(v1);
}

void vgui::EditPanel::setCursorBlink(vgui::EditPanel *const this, bool state)
{
  int v2; // eax

  this->_cursorBlink = state;
  v2 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 83))(this);
  this->_cursorNextBlinkTime = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 92))(v2) + 400;
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::paint(vgui::EditPanel *const this)
{
  vgui::Font *v1; // esi
  int v2; // ecx
  vgui::Dar<char> *v3; // edx
  int v4; // eax
  int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  void (__cdecl *v10)(vgui::EditPanel *const, int, int, int, int); // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::Dar<char> *v14; // [esp+28h] [ebp-44h]
  vgui::Dar<char> *v15; // [esp+28h] [ebp-44h]
  vgui::Font *v16; // [esp+2Ch] [ebp-40h]
  int yy; // [esp+30h] [ebp-3Ch]
  int j; // [esp+38h] [ebp-34h]
  int cx_0; // [esp+3Ch] [ebp-30h]
  int c; // [esp+44h] [ebp-28h] BYREF
  int b; // [esp+48h] [ebp-24h] BYREF
  int a_0[8]; // [esp+4Ch] [ebp-20h] BYREF

  v1 = this->_font;
  if ( !v1 )
  {
    v12 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 83))(this);
    v13 = (*(int (__cdecl **)(int))(*(_DWORD *)v12 + 84))(v12);
    v1 = (vgui::Font *)(*(int (__cdecl **)(int, int))(*(_DWORD *)v13 + 12))(v13, 1);
  }
  (*((void (__cdecl **)(vgui::EditPanel *const, vgui::Font *))this->_vptr_Panel + 98))(this, v1);
  (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 99))(this, 1);
  if ( this->_lineDarDar._count > 0 )
  {
    j = 0;
    v2 = 0;
    yy = 0;
    do
    {
      v3 = this->_lineDarDar._data[v2];
      v4 = v3->_count;
      if ( v3->_count <= 0 )
      {
        v6 = 0;
        cx_0 = 0;
      }
      else
      {
        v5 = 0;
        v6 = 0;
        cx_0 = 0;
        v16 = v1;
        do
        {
          v7 = v3->_data[v5];
          v14 = v3;
          (*((void (__cdecl **)(vgui::EditPanel *const, int, int, int))this->_vptr_Panel + 105))(this, v6, yy, v7);
          if ( this->_cursor[0] == v5 )
          {
            v8 = cx_0;
            if ( this->_cursor[1] == j )
              v8 = v6;
            cx_0 = v8;
          }
          ++v5;
          (*((void (__cdecl **)(vgui::Font *, int, int *, int *, int *))v16->_vptr_Font + 2))(v16, v7, &c, &b, a_0);
          v3 = v14;
          v6 += a_0[0] + b + c;
          v4 = v14->_count;
        }
        while ( v14->_count > v5 );
        v1 = v16;
      }
      if ( this->_cursor[1] == j && this->_cursorBlink )
      {
        if ( v4 <= this->_cursor[0] )
        {
          v15 = v3;
          (*((void (__cdecl **)(vgui::Font *, int, int *, int *, int *))v1->_vptr_Font + 2))(v1, 32, a_0, &b, &c);
          cx_0 = v6 + (this->_cursor[0] - v15->_count) * (c + b + a_0[0]);
        }
        (*((void (__cdecl **)(vgui::EditPanel *const, int, _DWORD, _DWORD, _DWORD))this->_vptr_Panel + 94))(
          this,
          255,
          0,
          0,
          0);
        v10 = (void (__cdecl *)(vgui::EditPanel *const, int, int, int, int))*((_DWORD *)this->_vptr_Panel + 95);
        v11 = (*((int (__cdecl **)(vgui::Font *))v1->_vptr_Font + 4))(v1);
        v10(this, cx_0 - 1, yy, cx_0 + 1, yy + v11);
      }
      v9 = (*((int (__cdecl **)(vgui::Font *))v1->_vptr_Font + 4))(v1);
      v2 = ++j;
      yy += v9;
    }
    while ( this->_lineDarDar._count > j );
  }
}

void vgui::EditPanel::doCursorUp(vgui::EditPanel *const this)
{
  int v1; // ebp
  int (__cdecl *v2)(vgui::EditPanel *const, int, int, int); // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx

  v1 = this->_cursor[0];
  v2 = (int (__cdecl *)(vgui::EditPanel *const, int, int, int))*((_DWORD *)this->_vptr_Panel + 149);
  v3 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1] - 1);
  v4 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  v5 = v2(this, v4, v3, v1);
  v6 = this->_cursor[1];
  this->_cursor[0] = v5;
  v7 = 0;
  v8 = v6 - 1;
  if ( v8 >= 0 )
    v7 = v8;
  this->_cursor[1] = v7;
  (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 140))(this, 1);
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorDown(vgui::EditPanel *const this)
{
  int v2; // esi
  int (__cdecl *v3)(vgui::EditPanel *const, int, int, int); // edi
  int v4; // ebp
  int v5; // eax
  int v6; // eax
  int v7; // [esp+1Ch] [ebp-20h]

  v2 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 139))(this);
  v3 = (int (__cdecl *)(vgui::EditPanel *const, int, int, int))*((_DWORD *)this->_vptr_Panel + 149);
  v7 = this->_cursor[0];
  v4 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1] + 1);
  v5 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  this->_cursor[0] = v3(this, v5, v4, v7);
  if ( v2 > (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 138))(this) )
    v2 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 138))(this);
  v6 = this->_cursor[1] + 1;
  if ( v2 > v6 )
  {
    this->_cursor[1] = v6;
    (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 140))(this, 1);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorLeft(vgui::EditPanel *const this)
{
  int v1; // eax

  v1 = 0;
  if ( this->_cursor[0] - 1 >= 0 )
    v1 = this->_cursor[0] - 1;
  this->_cursor[0] = v1;
  (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 140))(this, 1);
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorRight(vgui::EditPanel *const this)
{
  int (**v1)(...); // eax

  v1 = this->_vptr_Panel;
  ++this->_cursor[0];
  v1[140](this, 1);
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorToStartOfLine(vgui::EditPanel *const this)
{
  this->_cursor[0] = 0;
  (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 140))(this, 1);
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorToEndOfLine(vgui::EditPanel *const this)
{
  int *v1; // eax

  v1 = (int *)(*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  if ( v1 )
  {
    this->_cursor[0] = *v1;
    (*((void (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 140))(this, 1);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorInsertChar(vgui::EditPanel *const this, char ch_0)
{
  int v2; // edi

  v2 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  if ( v2 )
  {
    (*((void (__cdecl **)(vgui::EditPanel *const, int, int, int))this->_vptr_Panel + 148))(
      this,
      v2,
      this->_cursor[0],
      1);
    (*((void (__cdecl **)(vgui::EditPanel *const, int, int, _DWORD))this->_vptr_Panel + 146))(
      this,
      v2,
      this->_cursor[0],
      ch_0);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 130))(this);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorBackspace(vgui::EditPanel *const this)
{
  int *v1; // esi
  int *v2; // eax
  int *v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  vgui::Dar<char> **v11; // ecx
  vgui::Dar<char> **v12; // esi
  int v13; // [esp+1Ch] [ebp-20h]

  v1 = (int *)(*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  if ( v1 )
  {
    if ( this->_cursor[0] )
    {
      (*((void (__cdecl **)(vgui::EditPanel *const, int *, int, int))this->_vptr_Panel + 147))(
        this,
        v1,
        this->_cursor[0],
        1);
      (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 129))(this);
    }
    else
    {
      v2 = (int *)(*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(
                    this,
                    this->_cursor[1] - 1);
      v3 = v2;
      if ( !v2 )
        return;
      v13 = *v2;
      if ( *v1 > 0 )
      {
        v4 = 0;
        do
        {
          v5 = *(char *)(v1[2] + v4);
          v6 = v4 + v13;
          ++v4;
          (*((void (__cdecl **)(vgui::EditPanel *const, int *, int, int))this->_vptr_Panel + 146))(this, v3, v6, v5);
        }
        while ( *v1 > v4 );
      }
      v7 = this->_cursor[1];
      if ( v7 >= 0 )
      {
        v8 = this->_lineDarDar._count;
        if ( v7 < v8 )
        {
          v9 = v8 - 1;
          if ( v7 < v9 )
          {
            v10 = v7;
            do
            {
              v11 = this->_lineDarDar._data;
              ++v7;
              v12 = &v11[v10++];
              *v12 = v11[v10];
              v9 = this->_lineDarDar._count - 1;
            }
            while ( v7 < v9 );
          }
          this->_lineDarDar._count = v9;
        }
      }
      (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 127))(this);
      this->_cursor[0] = v13;
    }
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorDelete(vgui::EditPanel *const this)
{
  int v1; // esi

  v1 = (*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  if ( v1 )
  {
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 130))(this);
    (*((void (__cdecl **)(vgui::EditPanel *const, int, int, int))this->_vptr_Panel + 147))(
      this,
      v1,
      this->_cursor[0],
      1);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 129))(this);
    (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::setFont(vgui::EditPanel *const this, vgui::Font *font)
{
  this->_font = font;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

void vgui::EditPanel::doCursorPrintf(vgui::EditPanel *const this, char *format, ...)
{
  int v2; // edi
  char v3; // al
  char buf[8192]; // [esp+10h] [ebp-200Ch] BYREF
  va_list __varargs; // [esp+2028h] [ebp+Ch] BYREF

  va_start(__varargs, format);
  v2 = 0;
  vsprintf(buf, format, __varargs);
  while ( 1 )
  {
    v3 = buf[v2];
    if ( !v3 )
      break;
    if ( v3 == 10 )
    {
      ++v2;
      (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 135))(this);
      if ( v2 == 0x2000 )
        break;
    }
    else
    {
      ++v2;
      (*((void (__cdecl **)(vgui::EditPanel *const, _DWORD))this->_vptr_Panel + 133))(this, v3);
      if ( v2 == 0x2000 )
        break;
    }
  }
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

int vgui::EditPanel::spatialCharOffsetBetweenTwoLines(vgui::EditPanel *const this, vgui::Dar<char> *srcDar, vgui::Dar<char> *dstDar, int x)
{
  vgui::Dar<char> *v4; // ecx
  int i; // ebx
  vgui::Font *v6; // edi
  int v7; // esi
  int v8; // ebp
  vgui::Dar<char> *v9; // ebx
  int v10; // eax
  int v11; // ebp
  int v12; // eax
  int v13; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp+44h] [ebp-28h] BYREF
  int v19; // [esp+48h] [ebp-24h] BYREF
  int v20[8]; // [esp+4Ch] [ebp-20h] BYREF

  v4 = srcDar;
  i = x;
  if ( dstDar && srcDar )
  {
    v6 = this->_font;
    if ( !v6 )
    {
      v15 = (*((int (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 83))(this);
      v16 = (*(int (__cdecl **)(int))(*(_DWORD *)v15 + 84))(v15);
      v17 = (*(int (__cdecl **)(int, int))(*(_DWORD *)v16 + 12))(v16, 1);
      v4 = srcDar;
      v6 = (vgui::Font *)v17;
    }
    v7 = 0;
    if ( x )
    {
      v8 = 0;
      v9 = v4;
      do
      {
        v10 = 32;
        if ( v9->_count > v8 )
          v10 = v9->_data[v8];
        ++v8;
        (*((void (__cdecl **)(vgui::Font *, int, int *, int *, int *))v6->_vptr_Font + 2))(v6, v10, &v18, &v19, v20);
        v7 += v20[0] + v19 + v18;
      }
      while ( x != v8 );
    }
    v11 = 0;
    for ( i = 0; ; ++i )
    {
      v12 = 32;
      if ( dstDar->_count > i )
        v12 = dstDar->_data[i];
      (*((void (__cdecl **)(vgui::Font *, int, int *, int *, int *))v6->_vptr_Font + 2))(v6, v12, v20, &v19, &v18);
      v13 = v11 + (v18 + v20[0] + v19) / 2;
      if ( v7 < v13 && v7 >= v11 )
        break;
      if ( v13 <= v7 && v18 + v19 + v11 + v20[0] > v7 )
        return i + 1;
      v11 += v18 + v20[0] + v19;
    }
  }
  return i;
}

void vgui::EditPanel::shiftLineRight(vgui::EditPanel *const this, vgui::Dar<char> *lineDar, int x, int count)
{
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-20h]

  if ( x >= 0 && count >= 0 )
  {
    v4 = lineDar->_count;
    v5 = lineDar->_count - 1;
    if ( x <= v5 )
    {
      while ( 1 )
      {
        v6 = 0;
        if ( v4 > v5 )
          v6 = lineDar->_data[v5];
        v8 = v6;
        v7 = v5 + count;
        --v5;
        (*((void (__cdecl **)(vgui::EditPanel *const, vgui::Dar<char> *, int, int))this->_vptr_Panel + 146))(
          this,
          lineDar,
          v7,
          v8);
        if ( x > v5 )
          break;
        v4 = lineDar->_count;
      }
    }
  }
}

void vgui::EditPanel::getText(vgui::EditPanel *const this, int lineIndex, int offset, char *buf, int bufLen)
{
  int v5; // edx
  vgui::Dar<char> *v6; // esi
  int v7; // ecx
  int v8; // ebx
  char v9; // al
  int v10; // eax

  v5 = offset;
  if ( lineIndex >= 0 && lineIndex < this->_lineDarDar._count )
  {
    v6 = this->_lineDarDar._data[lineIndex];
    v7 = 0;
    v8 = v6->_count;
    if ( v6->_count > offset && bufLen > 1 )
    {
      v7 = 1;
      while ( 1 )
      {
        v9 = 0;
        if ( v5 >= 0 && v8 > v5 )
          v9 = v6->_data[v5];
        buf[v5++ - offset] = v9;
        v10 = v7;
        v8 = v6->_count;
        if ( v5 >= v6->_count )
          break;
        if ( ++v7 == bufLen )
        {
          v7 = v10;
          break;
        }
      }
    }
    buf[v7] = 0;
  }
}

void vgui::EditPanel::shiftLineLeft(vgui::EditPanel *const this, vgui::Dar<char> *lineDar, int x, int count)
{
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax

  v4 = x;
  if ( x > 0 )
  {
    v5 = lineDar->_count;
    if ( x <= lineDar->_count && count >= 0 )
    {
      if ( x < v5 )
      {
        v6 = x - count;
        do
        {
          if ( v6 >= 0 )
          {
            v7 = 0;
            if ( v4 >= 0 )
              v7 = lineDar->_data[v4];
            (*((void (__cdecl **)(vgui::EditPanel *const, vgui::Dar<char> *, int, int))this->_vptr_Panel + 146))(
              this,
              lineDar,
              v6,
              v7);
            v5 = lineDar->_count;
          }
          ++v4;
          ++v6;
        }
        while ( v4 < v5 );
      }
      v8 = v5 - count;
      if ( v8 >= 0 && v8 <= lineDar->_capacity )
        lineDar->_count = v8;
    }
  }
}

void vgui::EditPanel::setChar(vgui::EditPanel *const this, vgui::Dar<char> *lineDar, int x, char ch_0, char fill)
{
  int v5; // edx
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edi
  _BYTE *v9; // eax
  _WORD *v10; // edi
  int v11; // edi
  int v12; // eax
  int v13; // [esp+1Ch] [ebp-30h]
  int i; // [esp+20h] [ebp-2Ch]
  unsigned int v15; // [esp+28h] [ebp-24h]
  char *v16; // [esp+2Ch] [ebp-20h]

  if ( lineDar && x >= 0 )
  {
    i = lineDar->_count;
    if ( x < lineDar->_count )
      goto LABEL_16;
    v5 = lineDar->_capacity;
    v6 = x + 1;
    if ( x + 1 > v5 )
    {
      if ( v5 || (v5 = 1, v8 = 1, v6 > 1) )
      {
        do
          v5 *= 2;
        while ( v6 > v5 );
        v8 = v5;
      }
      v13 = v5;
      v9 = (_BYTE *)operator new[](v8);
      v16 = v9;
      if ( !v9 )
        exit(0);
      v15 = v8;
      v10 = v9;
      if ( v15 >= 8 )
      {
        if ( ((uint8_t)v9 & 1) != 0 )
        {
          *v9 = 0;
          --v15;
          v10 = v9 + 1;
        }
        if ( ((uint8_t)v10 & 2) != 0 )
        {
          *v10++ = 0;
          v15 -= 2;
        }
        if ( ((uint8_t)v10 & 4) != 0 )
        {
          *(_DWORD *)v10 = 0;
          v10 += 2;
          v15 -= 4;
        }
        memset(v10, 0, 4 * (v15 >> 2));
        v10 += 2 * (v15 >> 2);
        LOBYTE(v15) = v15 & 3;
      }
      if ( (v15 & 4) != 0 )
      {
        *(_DWORD *)v10 = 0;
        v10 += 2;
      }
      if ( (v15 & 2) != 0 )
        *v10++ = 0;
      if ( (v15 & 1) != 0 )
        *(_BYTE *)v10 = 0;
      v11 = lineDar->_count;
      lineDar->_capacity = v13;
      if ( v11 > 0 )
      {
        v12 = 0;
        do
        {
          v16[v12] = lineDar->_data[v12];
          ++v12;
        }
        while ( v12 < lineDar->_count );
      }
      if ( lineDar->_data )
        operator delete[](lineDar->_data);
      lineDar->_data = v16;
    }
    if ( v6 >= 0 && v6 <= lineDar->_capacity )
      lineDar->_count = v6;
    else
      v6 = lineDar->_count;
    if ( x > i )
    {
      v7 = i;
      do
      {
        if ( v7 >= 0 && v7 < v6 )
        {
          lineDar->_data[v7] = fill;
          v6 = lineDar->_count;
        }
        ++v7;
      }
      while ( v7 != x );
    }
    if ( x < v6 )
LABEL_16:
      lineDar->_data[x] = ch_0;
  }
}

void vgui::EditPanel::doCursorNewLine(vgui::EditPanel *const this)
{
  int *v1; // ebp
  vgui::Dar<char> *v2; // eax
  vgui::Dar<char> *v3; // esi
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // ecx
  VFontData *v7; // edx
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  vgui::Dar<char> **v11; // edi
  int v12; // edi
  int i; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // edi
  _BYTE *v18; // eax
  vgui::Dar<vgui::Dar<char>*> *v19; // edx
  _WORD *v20; // edi
  int v21; // ecx
  vgui::Dar<char> **v22; // edi
  int v23; // edx
  int v24; // eax
  unsigned int v25; // edi
  int v26; // eax
  _BYTE *v27; // eax
  vgui::Dar<vgui::Dar<char>*> *v28; // edx
  _WORD *v29; // edi
  int v30; // ecx
  int v31; // [esp+Ch] [ebp-40h]
  _DWORD *v32; // [esp+1Ch] [ebp-30h]
  int v33; // [esp+20h] [ebp-2Ch]
  int v34; // [esp+20h] [ebp-2Ch]
  vgui::Dar<char> **lineDar; // [esp+24h] [ebp-28h]
  vgui::Dar<char> **lineDara; // [esp+24h] [ebp-28h]
  unsigned int v37; // [esp+28h] [ebp-24h]
  int v38; // [esp+28h] [ebp-24h]
  unsigned int v39; // [esp+2Ch] [ebp-20h]

  v1 = (int *)(*((int (__cdecl **)(vgui::EditPanel *const, int))this->_vptr_Panel + 144))(this, this->_cursor[1]);
  if ( !v1 )
    return;
  v2 = (vgui::Dar<char> *)operator new(0xCu);
  v2->_count = 0;
  v3 = v2;
  v2->_capacity = 0;
  v2->_data = 0;
  v4 = (_DWORD *)operator new[](4u);
  if ( !v4 )
    goto LABEL_86;
  *v4 = 0;
  v5 = v3->_count;
  v3->_capacity = 4;
  if ( v5 > 0 )
  {
    v6 = 0;
    do
    {
      *((_BYTE *)v4 + v6) = v3->_data[v6];
      ++v6;
    }
    while ( v6 < v3->_count );
  }
  v7 = (VFontData *)v3->_data;
  if ( v7 )
  {
    v32 = v4;
    operator delete[](v7);
    v4 = v32;
  }
  v3->_data = (char *)v4;
  v33 = this->_cursor[1] + 1;
  if ( v33 < 0 )
    goto LABEL_15;
  v8 = this->_lineDarDar._count;
  if ( v33 > v8 )
    goto LABEL_15;
  v9 = this->_lineDarDar._capacity;
  v10 = v8 + 1;
  if ( v33 != v8 && v8 )
  {
    v38 = this->_lineDarDar._capacity;
    if ( v10 > v9 )
    {
      if ( v38 || (v38 = 1, v25 = 4, v10 > 1) )
      {
        v26 = v38;
        do
          v26 *= 2;
        while ( v10 > v26 );
        v38 = v26;
        v25 = 4 * v26;
      }
      v27 = (_BYTE *)operator new[](v25);
      v28 = &this->_lineDarDar;
      lineDara = (vgui::Dar<char> **)v27;
      if ( !v27 )
        goto LABEL_86;
      v39 = v25;
      v29 = v27;
      if ( v39 >= 8 )
      {
        if ( ((uint8_t)v27 & 1) != 0 )
        {
          *v27 = 0;
          --v39;
          v29 = v27 + 1;
        }
        if ( ((uint8_t)v29 & 2) != 0 )
        {
          *v29++ = 0;
          v39 -= 2;
        }
        if ( ((uint8_t)v29 & 4) != 0 )
        {
          *(_DWORD *)v29 = 0;
          v29 += 2;
          v39 -= 4;
        }
        memset(v29, 0, 4 * (v39 >> 2));
        v29 += 2 * (v39 >> 2);
        LOBYTE(v39) = v39 & 3;
      }
      if ( (v39 & 4) != 0 )
      {
        *(_DWORD *)v29 = 0;
        v29 += 2;
      }
      if ( (v39 & 2) != 0 )
        *v29++ = 0;
      if ( (v39 & 1) != 0 )
        *(_BYTE *)v29 = 0;
      v8 = this->_lineDarDar._count;
      this->_lineDarDar._capacity = v38;
      if ( v8 > 0 )
      {
        v30 = 0;
        do
        {
          lineDara[v30] = this->_lineDarDar._data[v30];
          ++v30;
          v8 = v28->_count;
        }
        while ( v30 < v28->_count );
      }
      if ( this->_lineDarDar._data )
      {
        operator delete[]((VFontData *const)this->_lineDarDar._data);
        v8 = this->_lineDarDar._count;
      }
      this->_lineDarDar._data = lineDara;
      v22 = lineDara;
    }
    else
    {
      v22 = this->_lineDarDar._data;
    }
    v22[v8] = v3;
    v23 = this->_lineDarDar._count;
    this->_lineDarDar._count = v23 + 1;
    if ( v33 < v23 )
    {
      v24 = v23;
      do
      {
        --v23;
        this->_lineDarDar._data[v24] = this->_lineDarDar._data[v24 - 1];
        --v24;
      }
      while ( v33 < v23 );
    }
    this->_lineDarDar._data[v33] = v3;
    goto LABEL_15;
  }
  v34 = this->_lineDarDar._capacity;
  if ( v10 > v9 )
  {
    if ( v34 || (v34 = 1, v17 = 4, v10 > 1) )
    {
      v16 = v34;
      do
        v16 *= 2;
      while ( v10 > v16 );
      v34 = v16;
      v17 = 4 * v16;
    }
    v18 = (_BYTE *)operator new[](v17);
    v19 = &this->_lineDarDar;
    lineDar = (vgui::Dar<char> **)v18;
    if ( v18 )
    {
      v37 = v17;
      v20 = v18;
      if ( v37 >= 8 )
      {
        if ( ((uint8_t)v18 & 1) != 0 )
        {
          *v18 = 0;
          --v37;
          v20 = v18 + 1;
        }
        if ( ((uint8_t)v20 & 2) != 0 )
        {
          *v20++ = 0;
          v37 -= 2;
        }
        if ( ((uint8_t)v20 & 4) != 0 )
        {
          *(_DWORD *)v20 = 0;
          v20 += 2;
          v37 -= 4;
        }
        memset(v20, 0, 4 * (v37 >> 2));
        v20 += 2 * (v37 >> 2);
        LOBYTE(v37) = v37 & 3;
      }
      if ( (v37 & 4) != 0 )
      {
        *(_DWORD *)v20 = 0;
        v20 += 2;
      }
      if ( (v37 & 2) != 0 )
        *v20++ = 0;
      if ( (v37 & 1) != 0 )
        *(_BYTE *)v20 = 0;
      v8 = this->_lineDarDar._count;
      this->_lineDarDar._capacity = v34;
      if ( v8 > 0 )
      {
        v21 = 0;
        do
        {
          lineDar[v21] = this->_lineDarDar._data[v21];
          ++v21;
          v8 = v19->_count;
        }
        while ( v21 < v19->_count );
      }
      if ( this->_lineDarDar._data )
      {
        operator delete[]((VFontData *const)this->_lineDarDar._data);
        v8 = this->_lineDarDar._count;
      }
      this->_lineDarDar._data = lineDar;
      v11 = lineDar;
      goto LABEL_14;
    }
LABEL_86:
    exit(0);
  }
  v11 = this->_lineDarDar._data;
LABEL_14:
  v11[v8] = v3;
  ++this->_lineDarDar._count;
LABEL_15:
  v12 = this->_cursor[0];
  if ( v12 < *v1 )
  {
    for ( i = this->_cursor[0]; ; i = this->_cursor[0] )
    {
      v14 = 0;
      if ( v12 >= 0 )
        v14 = *(char *)(v1[2] + v12);
      v31 = v14;
      v15 = v12++;
      (*((void (__cdecl **)(vgui::EditPanel *const, vgui::Dar<char> *, int, int))this->_vptr_Panel + 146))(
        this,
        v3,
        v15 - i,
        v31);
      if ( *v1 <= v12 )
        break;
    }
    v12 = this->_cursor[0];
  }
  if ( v12 >= 0 && v1[1] >= v12 )
    *v1 = v12;
  this->_cursor[0] = 0;
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 128))(this);
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
}

void vgui::EditPanel::EditPanel(vgui::EditPanel *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  vgui::Dar<vgui::Dar<char>*> *v6; // ebx
  int v7; // ecx
  int v8; // edx
  vgui::Dar<char> **v9; // edx
  int (**v10)(...); // eax
  int v11; // eax
  vgui::InputSignal *s; // eax
  vgui::Dar<char> *v13; // eax
  vgui::Dar<char> *v14; // ebp
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // ecx
  VFontData *v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  vgui::Dar<char> **v22; // eax
  unsigned int v23; // edi
  _BYTE *v24; // eax
  _WORD *v25; // edi
  int v26; // eax
  int v27; // [esp+24h] [ebp-28h]
  _DWORD *v28; // [esp+24h] [ebp-28h]
  int v29; // [esp+24h] [ebp-28h]
  vgui::Dar<char> **v30; // [esp+28h] [ebp-24h]
  unsigned int v31; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::EditPanel + 2);
  this->_lineDarDar._count = 0;
  this->_lineDarDar._capacity = 0;
  this->_lineDarDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    goto LABEL_43;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  v6 = &this->_lineDarDar;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v7 = this->_lineDarDar._count;
  this->_lineDarDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v8) = this->_lineDarDar._data[v8];
      ++v8;
    }
    while ( v8 < v6->_count );
  }
  v9 = this->_lineDarDar._data;
  if ( v9 )
  {
    v27 = v5;
    operator delete[]((VFontData *const)v9);
    v5 = v27;
  }
  this->_lineDarDar._data = (vgui::Dar<char> **)v5;
  this->_font = 0;
  v10 = this->_vptr_Panel;
  this->_cursor[0] = 0;
  this->_cursor[1] = 0;
  this->_cursorBlink = 1;
  v11 = v10[83](this);
  this->_cursorNextBlinkTime = (*(int (__cdecl **)(int))(*(_DWORD *)v11 + 92))(v11) + 400;
  (*((void (__cdecl **)(vgui::EditPanel *const))this->_vptr_Panel + 12))(this);
  s = (vgui::InputSignal *)operator new(8u);
  s->_vptr_InputSignal = (int (**)(...))&off_439E8;
  s[1]._vptr_InputSignal = (int (**)(...))this;
  vgui::Panel::addInputSignal(this, s);
  if ( !this->_lineDarDar._count )
  {
    v13 = (vgui::Dar<char> *)operator new(0xCu);
    v13->_count = 0;
    v14 = v13;
    v13->_capacity = 0;
    v13->_data = 0;
    v15 = (_DWORD *)operator new[](4u);
    if ( v15 )
    {
      *v15 = 0;
      v16 = v14->_count;
      v14->_capacity = 4;
      if ( v16 > 0 )
      {
        v17 = 0;
        do
        {
          *((_BYTE *)v15 + v17) = v14->_data[v17];
          ++v17;
        }
        while ( v17 < v14->_count );
      }
      v18 = (VFontData *)v14->_data;
      if ( v18 )
      {
        v28 = v15;
        operator delete[](v18);
        v15 = v28;
      }
      v14->_data = (char *)v15;
      v19 = this->_lineDarDar._count;
      v20 = this->_lineDarDar._capacity;
      v21 = v19 + 1;
      if ( v19 + 1 <= v20 )
      {
        v22 = this->_lineDarDar._data;
LABEL_16:
        v22[v19] = v14;
        ++this->_lineDarDar._count;
        return;
      }
      if ( v20 || (v20 = 1, v23 = 4, v21 > 1) )
      {
        do
          v20 *= 2;
        while ( v21 > v20 );
        v23 = 4 * v20;
      }
      v29 = v20;
      v24 = (_BYTE *)operator new[](v23);
      v30 = (vgui::Dar<char> **)v24;
      if ( v24 )
      {
        v31 = v23;
        v25 = v24;
        if ( v31 >= 8 )
        {
          if ( ((uint8_t)v24 & 1) != 0 )
          {
            *v24 = 0;
            --v31;
            v25 = v24 + 1;
          }
          if ( ((uint8_t)v25 & 2) != 0 )
          {
            *v25++ = 0;
            v31 -= 2;
          }
          if ( ((uint8_t)v25 & 4) != 0 )
          {
            *(_DWORD *)v25 = 0;
            v25 += 2;
            v31 -= 4;
          }
          memset(v25, 0, 4 * (v31 >> 2));
          v25 += 2 * (v31 >> 2);
          LOBYTE(v31) = v31 & 3;
        }
        if ( (v31 & 4) != 0 )
        {
          *(_DWORD *)v25 = 0;
          v25 += 2;
        }
        if ( (v31 & 2) != 0 )
          *v25++ = 0;
        if ( (v31 & 1) != 0 )
          *(_BYTE *)v25 = 0;
        v19 = this->_lineDarDar._count;
        this->_lineDarDar._capacity = v29;
        if ( v19 > 0 )
        {
          v26 = 0;
          do
          {
            v30[v26] = this->_lineDarDar._data[v26];
            ++v26;
            v19 = v6->_count;
          }
          while ( v26 < v6->_count );
        }
        if ( this->_lineDarDar._data )
        {
          operator delete[]((VFontData *const)this->_lineDarDar._data);
          v19 = this->_lineDarDar._count;
        }
        v22 = v30;
        this->_lineDarDar._data = v30;
        goto LABEL_16;
      }
    }
LABEL_43:
    exit(0);
  }
}

void vgui::EditPanel::getCursorBlink(vgui::EditPanel *const this, bool *const blink, int *const nextBlinkTime)
{
  *blink = this->_cursorBlink;
  *nextBlinkTime = this->_cursorNextBlinkTime;
}

