#include <VGUI_EditPanel.h>

#include <VGUI_App.h>

#include "handlers/FooDefaultEditPanelSignal.h"

#include <algorithm>

void vgui::EditPanel::paintBackground()
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void(__cdecl**)(vgui::EditPanel* const, int*, int*))_vptr_Panel + 58))(this, &wide, tall);
  (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 93))(this, 2);
  (*((void(__cdecl**)(vgui::EditPanel* const, _DWORD, _DWORD, int, int))_vptr_Panel + 95))(
    this,
    0,
    0,
    wide,
    tall[0]);
}

void vgui::EditPanel::setChar(vgui::Dar<char>* lineDar, int x, char ch_0)
{
  (*((void(__cdecl**)(vgui::EditPanel* const, vgui::Dar<char> *, int, _DWORD, int))_vptr_Panel + 145))(
    this,
    lineDar,
    x,
    ch_0,
    32);
}

int vgui::EditPanel::getLineCount()
{
  return _lineDarDar._count;
}

int vgui::EditPanel::getVisibleLineCount()
{
  vgui::Font* v1; // eax
  int v2; // ebx
  int v4; // eax
  int v5; // eax
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  (*((void(__cdecl**)(vgui::EditPanel* const, int*, int*))_vptr_Panel + 58))(this, &wide, tall);
  v1 = _font;
  if (!v1)
  {
    v4 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 83))(this);
    v5 = (*(int(__cdecl**)(int))(*(_DWORD*)v4 + 84))(v4);
    v1 = (vgui::Font*)(*(int(__cdecl**)(int, int))(*(_DWORD*)v5 + 12))(v5, 1);
  }
  v2 = tall[0];
  return v2 / (*((int(__cdecl**)(vgui::Font*))v1->_vptr_Font + 4))(v1);
}

void vgui::EditPanel::setCursorBlink(bool state)
{
  int v2; // eax

  _cursorBlink = state;
  v2 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 83))(this);
  _cursorNextBlinkTime = (*(int(__cdecl**)(int))(*(_DWORD*)v2 + 92))(v2) + 400;
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

void vgui::EditPanel::paint()
{
  vgui::Font* v1; // esi
  int v2; // ecx
  vgui::Dar<char>* v3; // edx
  int v4; // eax
  int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  void(__cdecl * v10)(vgui::EditPanel* const, int, int, int, int); // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::Dar<char>* v14; // [esp+28h] [ebp-44h]
  vgui::Dar<char>* v15; // [esp+28h] [ebp-44h]
  vgui::Font* v16; // [esp+2Ch] [ebp-40h]
  int yy; // [esp+30h] [ebp-3Ch]
  int j; // [esp+38h] [ebp-34h]
  int cx_0; // [esp+3Ch] [ebp-30h]
  int c; // [esp+44h] [ebp-28h] BYREF
  int b; // [esp+48h] [ebp-24h] BYREF
  int a_0[8]; // [esp+4Ch] [ebp-20h] BYREF

  v1 = _font;
  if (!v1)
  {
    v12 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 83))(this);
    v13 = (*(int(__cdecl**)(int))(*(_DWORD*)v12 + 84))(v12);
    v1 = (vgui::Font*)(*(int(__cdecl**)(int, int))(*(_DWORD*)v13 + 12))(v13, 1);
  }
  (*((void(__cdecl**)(vgui::EditPanel* const, vgui::Font*))_vptr_Panel + 98))(this, v1);
  (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 99))(this, 1);
  if (_lineDarDar._count > 0)
  {
    j = 0;
    v2 = 0;
    yy = 0;
    do
    {
      v3 = _lineDarDar._data[v2];
      v4 = v3->_count;
      if (v3->_count <= 0)
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
          (*((void(__cdecl**)(vgui::EditPanel* const, int, int, int))_vptr_Panel + 105))(this, v6, yy, v7);
          if (_cursor[0] == v5)
          {
            v8 = cx_0;
            if (_cursor[1] == j)
              v8 = v6;
            cx_0 = v8;
          }
          ++v5;
          (*((void(__cdecl**)(vgui::Font*, int, int*, int*, int*))v16->_vptr_Font + 2))(v16, v7, &c, &b, a_0);
          v3 = v14;
          v6 += a_0[0] + b + c;
          v4 = v14->_count;
        } while (v14->_count > v5);
        v1 = v16;
      }
      if (_cursor[1] == j && _cursorBlink)
      {
        if (v4 <= _cursor[0])
        {
          v15 = v3;
          (*((void(__cdecl**)(vgui::Font*, int, int*, int*, int*))v1->_vptr_Font + 2))(v1, 32, a_0, &b, &c);
          cx_0 = v6 + (_cursor[0] - v15->_count) * (c + b + a_0[0]);
        }
        (*((void(__cdecl**)(vgui::EditPanel* const, int, _DWORD, _DWORD, _DWORD))_vptr_Panel + 94))(
          this,
          255,
          0,
          0,
          0);
        v10 = (void(__cdecl*)(vgui::EditPanel* const, int, int, int, int)) * ((_DWORD*)_vptr_Panel + 95);
        v11 = (*((int(__cdecl**)(vgui::Font*))v1->_vptr_Font + 4))(v1);
        v10(this, cx_0 - 1, yy, cx_0 + 1, yy + v11);
      }
      v9 = (*((int(__cdecl**)(vgui::Font*))v1->_vptr_Font + 4))(v1);
      v2 = ++j;
      yy += v9;
    } while (_lineDarDar._count > j);
  }
}

void vgui::EditPanel::doCursorUp()
{
  int v1; // ebp
  int(__cdecl * v2)(vgui::EditPanel* const, int, int, int); // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx

  v1 = _cursor[0];
  v2 = (int(__cdecl*)(vgui::EditPanel* const, int, int, int)) * ((_DWORD*)_vptr_Panel + 149);
  v3 = (*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1] - 1);
  v4 = (*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1]);
  v5 = v2(this, v4, v3, v1);
  v6 = _cursor[1];
  _cursor[0] = v5;
  v7 = 0;
  v8 = v6 - 1;
  if (v8 >= 0)
    v7 = v8;
  _cursor[1] = v7;
  (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 140))(this, 1);
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorDown()
{
  int v2; // esi
  int(__cdecl * v3)(vgui::EditPanel* const, int, int, int); // edi
  int v4; // ebp
  int v5; // eax
  int v6; // eax
  int v7; // [esp+1Ch] [ebp-20h]

  v2 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 139))(this);
  v3 = (int(__cdecl*)(vgui::EditPanel* const, int, int, int)) * ((_DWORD*)_vptr_Panel + 149);
  v7 = _cursor[0];
  v4 = (*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1] + 1);
  v5 = (*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1]);
  _cursor[0] = v3(this, v5, v4, v7);
  if (v2 > (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 138))(this))
    v2 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 138))(this);
  v6 = _cursor[1] + 1;
  if (v2 > v6)
  {
    _cursor[1] = v6;
    (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 140))(this, 1);
    (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorLeft()
{
  int v1; // eax

  v1 = 0;
  if (_cursor[0] - 1 >= 0)
    v1 = _cursor[0] - 1;
  _cursor[0] = v1;
  (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 140))(this, 1);
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorRight()
{
  int (**v1)(...); // eax

  v1 = _vptr_Panel;
  ++_cursor[0];
  v1[140](this, 1);
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorToStartOfLine()
{
  _cursor[0] = 0;
  (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 140))(this, 1);
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

void vgui::EditPanel::doCursorToEndOfLine()
{
  int* v1; // eax

  v1 = (int*)(*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1]);
  if (v1)
  {
    _cursor[0] = *v1;
    (*((void(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 140))(this, 1);
    (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorInsertChar(char ch_0)
{
  int v2; // edi

  v2 = (*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1]);
  if (v2)
  {
    (*((void(__cdecl**)(vgui::EditPanel* const, int, int, int))_vptr_Panel + 148))(
      this,
      v2,
      _cursor[0],
      1);
    (*((void(__cdecl**)(vgui::EditPanel* const, int, int, _DWORD))_vptr_Panel + 146))(
      this,
      v2,
      _cursor[0],
      ch_0);
    (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 130))(this);
    (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorBackspace()
{
  int* v1; // esi
  int* v2; // eax
  int* v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  vgui::Dar<char>** v11; // ecx
  vgui::Dar<char>** v12; // esi
  int v13; // [esp+1Ch] [ebp-20h]

  v1 = (int*)(*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(this, _cursor[1]);
  if (v1)
  {
    if (_cursor[0])
    {
      (*((void(__cdecl**)(vgui::EditPanel* const, int*, int, int))_vptr_Panel + 147))(
        this,
        v1,
        _cursor[0],
        1);
      (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 129))(this);
    }
    else
    {
      v2 = (int*)(*((int(__cdecl**)(vgui::EditPanel* const, int))_vptr_Panel + 144))(
        this,
        _cursor[1] - 1);
      v3 = v2;
      if (!v2)
        return;
      v13 = *v2;
      if (*v1 > 0)
      {
        v4 = 0;
        do
        {
          v5 = *(char*)(v1[2] + v4);
          v6 = v4 + v13;
          ++v4;
          (*((void(__cdecl**)(vgui::EditPanel* const, int*, int, int))_vptr_Panel + 146))(this, v3, v6, v5);
        } while (*v1 > v4);
      }
      v7 = _cursor[1];
      if (v7 >= 0)
      {
        v8 = _lineDarDar._count;
        if (v7 < v8)
        {
          v9 = v8 - 1;
          if (v7 < v9)
          {
            v10 = v7;
            do
            {
              v11 = _lineDarDar._data;
              ++v7;
              v12 = &v11[v10++];
              *v12 = v11[v10];
              v9 = _lineDarDar._count - 1;
            } while (v7 < v9);
          }
          _lineDarDar._count = v9;
        }
      }
      (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 127))(this);
      _cursor[0] = v13;
    }
    (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
  }
}

void vgui::EditPanel::doCursorDelete()
{
  auto line = getLine(_cursor[1]);
  if(line)
  {
    doCursorRight();
    shiftLineLeft(line, _cursor[0], 1);
    doCursorLeft();
    repaint();
  }
}

void vgui::EditPanel::setFont(vgui::Font* font)
{
  _font = font;
  repaint();
}

void vgui::EditPanel::doCursorPrintf(char* format, ...)
{
  int v2; // edi
  char v3; // al
  char buf[8192]; // [esp+10h] [ebp-200Ch] BYREF
  va_list __varargs; // [esp+2028h] [ebp+Ch] BYREF

  va_start(__varargs, format);
  v2 = 0;
  vsprintf(buf, format, __varargs);
  while (1)
  {
    v3 = buf[v2];
    if (!v3)
      break;
    if (v3 == 10)
    {
      ++v2;
      (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 135))(this);
      if (v2 == 0x2000)
        break;
    }
    else
    {
      ++v2;
      (*((void(__cdecl**)(vgui::EditPanel* const, _DWORD))_vptr_Panel + 133))(this, v3);
      if (v2 == 0x2000)
        break;
    }
  }
  (*((void(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 12))(this);
}

int vgui::EditPanel::spatialCharOffsetBetweenTwoLines(vgui::Dar<char>* srcDar, vgui::Dar<char>* dstDar, int x)
{
  vgui::Dar<char>* v4; // ecx
  int i; // ebx
  vgui::Font* v6; // edi
  int v7; // esi
  int v8; // ebp
  vgui::Dar<char>* v9; // ebx
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
  if (dstDar && srcDar)
  {
    v6 = _font;
    if (!v6)
    {
      v15 = (*((int(__cdecl**)(vgui::EditPanel* const))_vptr_Panel + 83))(this);
      v16 = (*(int(__cdecl**)(int))(*(_DWORD*)v15 + 84))(v15);
      v17 = (*(int(__cdecl**)(int, int))(*(_DWORD*)v16 + 12))(v16, 1);
      v4 = srcDar;
      v6 = (vgui::Font*)v17;
    }
    v7 = 0;
    if (x)
    {
      v8 = 0;
      v9 = v4;
      do
      {
        v10 = 32;
        if (v9->_count > v8)
          v10 = v9->_data[v8];
        ++v8;
        (*((void(__cdecl**)(vgui::Font*, int, int*, int*, int*))v6->_vptr_Font + 2))(v6, v10, &v18, &v19, v20);
        v7 += v20[0] + v19 + v18;
      } while (x != v8);
    }
    v11 = 0;
    for (i = 0; ; ++i)
    {
      v12 = 32;
      if (dstDar->_count > i)
        v12 = dstDar->_data[i];
      (*((void(__cdecl**)(vgui::Font*, int, int*, int*, int*))v6->_vptr_Font + 2))(v6, v12, v20, &v19, &v18);
      v13 = v11 + (v18 + v20[0] + v19) / 2;
      if (v7 < v13 && v7 >= v11)
        break;
      if (v13 <= v7 && v18 + v19 + v11 + v20[0] > v7)
        return i + 1;
      v11 += v18 + v20[0] + v19;
    }
  }
  return i;
}

void vgui::EditPanel::shiftLineRight(vgui::Dar<char>* lineDar, int x, int count)
{
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-20h]

  if (x >= 0 && count >= 0)
  {
    v4 = lineDar->_count;
    v5 = lineDar->_count - 1;
    if (x <= v5)
    {
      while (1)
      {
        v6 = 0;
        if (v4 > v5)
          v6 = lineDar->_data[v5];
        v8 = v6;
        v7 = v5 + count;
        --v5;
        (*((void(__cdecl**)(vgui::EditPanel* const, vgui::Dar<char> *, int, int))_vptr_Panel + 146))(
          this,
          lineDar,
          v7,
          v8);
        if (x > v5)
          break;
        v4 = lineDar->_count;
      }
    }
  }
}

void vgui::EditPanel::getText(int lineIndex, int offset, char* buf, int bufLen)
{
  auto line = _lineDarDar[lineIndex];

  if(lineIndex < 0 || lineIndex >= _lineDarDar.getCount() || offset < 0 || offset >= line->getCount())
    return;

  for(auto i = offset; i < std::min(bufLen, line->getCount()); ++i)
    buf[i - offset] = (*line)[i];

  if(buf && buflen)
    buf[0] = '\0';
}

void vgui::EditPanel::shiftLineLeft(vgui::Dar<char>* lineDar, int x, int count)
{
  if (x <= 0 || count < 0)
    return;

  for (auto i = x; i < lineDar->getCount(); ++i)
    if (i - count >= 0)
      setChar(lineDar, i - count, (*lineDar)[i]);

  if (lineDar->getCount() >= count)
    lineDar->setCount(lineDar->getCount() - count);
}

void vgui::EditPanel::setChar(vgui::Dar<char>* lineDar, int x, char ch_0, char fill)
{
  if (!lineDar || x < 0)
    return;

  if(x < lineDar->getCount())
    (*lineDar)[x] = ch_0;
  else
  {
    auto i = lineDar->getCount();
    lineDar->setCount(x + 1);

    for(; i < x; ++i)
      (*lineDar)[i] = fill;
    
    (*lineDar)[x] = ch_0;
  }
}

void vgui::EditPanel::doCursorNewLine()
{
  vgui::Dar<char>* newLineDar;

  if (!getLine(_cursor[1]))
    return;

  auto oldLineDar = _lineDarDar[_cursor[1]]);

  newLineDar = new vgui::Dar<char>(oldLineDar->getCount() - _cursor[0]);
  newLineDar->setCount(oldLineDar->getCount() - _cursor[0]);

  std::copy(&((*oldLineDar)[_cursor[0]]), &((*oldLineDar)[0]) + oldLineDar->getCount(), &((*newLineDar)[0]));
  oldLineDar->setCount(_cursor[0]);

  _lineDarDar.insertElementAt(newLineDar, _cursor[1]);
  _cursor[0] = 0;

  doCursorDown();
  repaint();
}

vgui::EditPanel::EditPanel(int x, int y, int wide, int tall)
  :vgui::Panel{ x, y, wide, tall },
  _font{ nullptr },
  _cursor{ 0, 0 },
  _cursorBlink{ true },
  _cursorNextBlinkTime{ getApp()->getTimeMillis() + 400 }
{
  repaint();

  s = new FooDefaultEditPanelSignal{ this };
  addInputSignal(s);
}

void vgui::EditPanel::getCursorBlink(bool* const blink, int* const nextBlinkTime)
{
  *blink = _cursorBlink;
  *nextBlinkTime = _cursorNextBlinkTime;
}