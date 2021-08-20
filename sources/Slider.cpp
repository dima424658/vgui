#include <VGUI_Slider.h>

bool vgui::Slider::isVertical(vgui::Slider *const this)
{
  return this->_vertical;
}

int vgui::Slider::getValue(vgui::Slider *const this)
{
  return this->_value;
}

void vgui::Slider::recomputeNobPosFromValue(vgui::Slider *const this)
{
  int v1; // edx
  int v2; // ecx
  int v3; // esi
  long double v4; // fst7
  long double v5; // fst5
  long double v6; // fst6
  long double v7; // fst7
  long double v8; // fst5
  long double v9; // rt1
  long double v10; // fst6
  long double v11; // fst7
  long double v12; // fst5
  long double v13; // rt2
  long double v14; // fst6
  long double v15; // fst7
  int (**v16)(...); // eax
  float v17; // [esp+14h] [ebp-28h]
  float v18; // [esp+14h] [ebp-28h]
  float v19; // [esp+14h] [ebp-28h]
  float v20; // [esp+14h] [ebp-28h]
  float v21; // [esp+18h] [ebp-24h]
  float v22; // [esp+18h] [ebp-24h]
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v1 = this->_range[0];
  v2 = wide;
  v3 = tall[0];
  v4 = (long double)(this->_range[1] - v1);
  v5 = (long double)this->_rangeWindow;
  if ( v5 < 0.0 )
    v5 = 0.0;
  if ( !this->_rangeWindowEnabled )
    v5 = v4;
  v6 = v5;
  if ( v5 <= 0.0 )
    goto LABEL_9;
  v7 = (long double)(this->_value - v1) / v4;
  if ( this->_vertical )
  {
    v8 = (long double)tall[0];
    v9 = v8 / v6 * v8;
    v10 = v7 * (v8 - v9);
    v11 = v9;
    v17 = v10;
    v21 = v10 + v9;
    this->_nobPos[0] = (int)v17;
    this->_nobPos[1] = (int)v21;
    if ( v3 < (int)v21 )
    {
      v18 = v11;
      this->_nobPos[1] = v3;
      this->_nobPos[0] = v3 - (int)v18;
    }
    goto LABEL_9;
  }
  v12 = (long double)wide;
  v13 = v12 / v6 * v12;
  v14 = v7 * (v12 - v13);
  v15 = v13;
  v19 = v14;
  v22 = v14 + v13;
  this->_nobPos[0] = (int)v19;
  this->_nobPos[1] = (int)v22;
  if ( v2 >= (int)v22 )
  {
LABEL_9:
    (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 12))(this);
    return;
  }
  v20 = v15;
  this->_nobPos[1] = v2;
  v16 = this->_vptr_Panel;
  this->_nobPos[0] = v2 - (int)v20;
  v16[12](this);
}

void vgui::Slider::recomputeValueFromNobPos(vgui::Slider *const this)
{
  int v1; // eax
  int v2; // edx
  long double v3; // fst7
  long double v4; // fst5
  long double v5; // fst7
  long double v6; // fst7
  int v7; // [esp+1Ch] [ebp-30h]
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v1 = this->_range[1];
  v2 = this->_range[0];
  v3 = (long double)(v1 - v2);
  v4 = (long double)this->_rangeWindow;
  if ( v4 < 0.0 )
    v4 = 0.0;
  if ( !this->_rangeWindowEnabled )
    v4 = v3;
  if ( v4 > 0.0 )
  {
    if ( this->_vertical )
      v7 = tall[0];
    else
      v7 = wide;
    v5 = v3 * ((long double)this->_nobPos[0] / ((long double)v7 - (long double)v7 / v4 * (long double)v7));
  }
  else
  {
    v5 = (long double)(this->_value - v2);
  }
  v6 = v5 + (long double)v2 + 0.5;
  if ( (int)(double)v6 <= v1 )
    v1 = (int)(double)v6;
  this->_value = v1;
}

bool vgui::Slider::hasFullRange(vgui::Slider *const this)
{
  long double v1; // fst7
  long double v2; // fst6
  long double v3; // fst7
  bool result; // al
  long double v5; // fst6
  long double v6; // fst6
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v1 = (long double)this->_rangeWindow;
  v2 = 0.0;
  if ( v1 >= 0.0 )
    v2 = v1;
  v3 = v2;
  if ( !this->_rangeWindowEnabled )
    v3 = (long double)(this->_range[1] - this->_range[0]);
  result = 0;
  if ( v3 > 0.0 )
  {
    v5 = (long double)this->_buttonOffset;
    if ( this->_vertical )
      v6 = v5 + (long double)tall[0];
    else
      v6 = v5 + (long double)wide;
    result = v6 >= v3;
  }
  return result;
}

void vgui::Slider::fireIntChangeSignal(vgui::Slider *const this)
{
  int v1; // esi
  vgui::IntChangeSignal *v2; // edi
  int (*v3)(...); // ebp
  int v4; // eax

  if ( this->_intChangeSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_intChangeSignalDar._data[v1++];
      v3 = *v2->_vptr_IntChangeSignal;
      v4 = (*((int (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 128))(this);
      v3(v2, v4, this);
    }
    while ( this->_intChangeSignalDar._count > v1 );
  }
}

void vgui::Slider::paintBackground(vgui::Slider *const this)
{
  int (**v1)(...); // eax
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  v1 = this->_vptr_Panel;
  if ( this->_vertical )
  {
    v1[93](this, 6);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(this, 0, 0, wide, 1);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      tall[0] - 1,
      wide,
      tall[0]);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      1,
      1,
      tall[0] - 1);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      wide - 1,
      1,
      wide,
      tall[0] - 1);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 7);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(this, 1, 1, wide - 1, 2);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(this, 1, 2, 3, tall[0] - 1);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      2,
      this->_nobPos[1],
      wide - 1,
      this->_nobPos[1] + 1);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 8);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      2,
      2,
      wide - 1,
      tall[0] - 1);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 3);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      this->_nobPos[0],
      wide,
      this->_nobPos[0] + 1);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      this->_nobPos[1],
      wide,
      this->_nobPos[1] + 1);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      this->_nobPos[0] + 1,
      1,
      this->_nobPos[1]);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      wide - 1,
      this->_nobPos[0] + 1,
      wide,
      this->_nobPos[1]);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 5);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      1,
      this->_nobPos[0] + 1,
      wide - 1,
      this->_nobPos[0] + 2);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      1,
      this->_nobPos[0] + 2,
      2,
      this->_nobPos[1]);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 4);
    (*((void (__cdecl **)(vgui::Slider *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      2,
      this->_nobPos[0] + 2,
      wide - 1,
      this->_nobPos[1]);
  }
  else
  {
    v1[93](this, 8);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      0,
      wide,
      tall[0]);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 1);
    (*((void (__cdecl **)(vgui::Slider *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 96))(
      this,
      0,
      0,
      wide,
      tall[0]);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 4);
    (*((void (__cdecl **)(vgui::Slider *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      this->_nobPos[0],
      0,
      this->_nobPos[1],
      tall[0]);
    (*((void (__cdecl **)(vgui::Slider *const, int))this->_vptr_Panel + 93))(this, 1);
    (*((void (__cdecl **)(vgui::Slider *const, int, _DWORD, int, int))this->_vptr_Panel + 96))(
      this,
      this->_nobPos[0],
      0,
      this->_nobPos[1],
      tall[0]);
  }
}

void vgui::Slider::setRange(vgui::Slider *const this, int min, int max)
{
  int v3; // eax

  v3 = min;
  this->_range[0] = min;
  if ( max >= min )
    v3 = max;
  this->_range[1] = v3;
}

void vgui::Slider::getRange(vgui::Slider *const this, int *const min, int *const max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

void vgui::Slider::privateCursorMoved(vgui::Slider *const this, int x, int y, vgui::Panel *panel)
{
  int v4; // eax
  int v5; // edi
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // esi
  bool v11; // cc
  int wide[4]; // [esp+10h] [ebp-2Ch] BYREF
  int tall[4]; // [esp+20h] [ebp-1Ch] BYREF

  if ( !this->_dragging )
    return;
  v4 = (*((int (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 83))(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v4 + 52))(v4, &x, &y);
  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 35))(this, &x, &y);
  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 58))(this, wide, tall);
  if ( this->_vertical )
  {
    v10 = this->_dragStartPos[1];
    v8 = tall[0];
    v6 = y - v10 + this->_nobDragStartPos[0];
    v7 = this->_nobDragStartPos[1] + y - v10;
    v11 = v7 <= tall[0];
    this->_nobPos[0] = v6;
    this->_nobPos[1] = v7;
    if ( v11 )
      goto LABEL_5;
    goto LABEL_4;
  }
  v5 = this->_dragStartPos[0];
  v6 = x - v5 + this->_nobDragStartPos[0];
  v7 = this->_nobDragStartPos[1] + x - v5;
  v8 = wide[0];
  this->_nobPos[0] = v6;
  this->_nobPos[1] = v7;
  if ( v7 > v8 )
  {
LABEL_4:
    v9 = v6 - v7;
    v7 = v8;
    v6 = v8 + v9;
    this->_nobPos[0] = v6;
    this->_nobPos[1] = v8;
  }
LABEL_5:
  if ( v6 < 0 )
  {
    this->_nobPos[1] = v7 - v6;
    this->_nobPos[0] = 0;
  }
  (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 139))(this);
  (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 12))(this);
  (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 143))(this);
}

void vgui::Slider::privateMousePressed(vgui::Slider *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  int v3; // eax
  int (**v4)(...); // eax
  int v5; // eax
  int x[4]; // [esp+10h] [ebp-2Ch] BYREF
  int y[4]; // [esp+20h] [ebp-1Ch] BYREF

  v3 = (*((int (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 83))(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v3 + 52))(v3, x, y);
  (*((void (__cdecl **)(vgui::Slider *const, int *, int *))this->_vptr_Panel + 35))(this, x, y);
  if ( this->_vertical )
  {
    if ( this->_nobPos[0] > y[0] || y[0] >= this->_nobPos[1] )
      return;
LABEL_7:
    v4 = this->_vptr_Panel;
    this->_dragging = 1;
    v5 = v4[83](this);
    (*(void (__cdecl **)(int, vgui::Slider *const))(*(_DWORD *)v5 + 56))(v5, this);
    *(_QWORD *)this->_nobDragStartPos = *(_QWORD *)this->_nobPos;
    this->_dragStartPos[0] = x[0];
    this->_dragStartPos[1] = y[0];
    return;
  }
  if ( this->_nobPos[0] <= x[0] && x[0] < this->_nobPos[1] )
    goto LABEL_7;
}

void vgui::Slider::privateMouseReleased(vgui::Slider *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  int (**v3)(...); // edx
  int v4; // eax

  v3 = this->_vptr_Panel;
  this->_dragging = 0;
  v4 = v3[83](this);
  (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)v4 + 56))(v4, 0);
}

void vgui::Slider::getNobPos(vgui::Slider *const this, int *const min, int *const max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

void vgui::Slider::setRangeWindow(vgui::Slider *const this, int rangeWindow)
{
  this->_rangeWindow = rangeWindow;
}

void vgui::Slider::setRangeWindowEnabled(vgui::Slider *const this, bool state)
{
  this->_rangeWindowEnabled = state;
}

void vgui::Slider::setButtonOffset(vgui::Slider *const this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

void vgui::Slider::setSize(vgui::Slider *const this, int wide, int tall)
{
  vgui::Panel::setSize((vgui::Panel *const)this, wide, tall);
  (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 138))(this);
}

void vgui::Slider::setValue(vgui::Slider *const this, int value)
{
  int v2; // edx
  int v3; // esi
  int v4; // eax

  v2 = value;
  v3 = this->_value;
  if ( value < this->_range[0] )
    v2 = this->_range[0];
  v4 = this->_range[1];
  if ( v2 <= v4 )
    v4 = v2;
  this->_value = v4;
  (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 138))(this);
  if ( this->_value != v3 )
    (*((void (__cdecl **)(vgui::Slider *const))this->_vptr_Panel + 143))(this);
}

void vgui::Slider::addIntChangeSignal(vgui::Slider *const this, vgui::IntChangeSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::IntChangeSignal*> *v3; // esi
  vgui::IntChangeSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::IntChangeSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::IntChangeSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_intChangeSignalDar._count;
  v3 = &this->_intChangeSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_intChangeSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_intChangeSignalDar._capacity;
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
    v14 = (vgui::IntChangeSignal **)v10;
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
    v2 = this->_intChangeSignalDar._count;
    this->_intChangeSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_intChangeSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_intChangeSignalDar._data )
    {
      operator delete[](this->_intChangeSignalDar._data);
      v2 = this->_intChangeSignalDar._count;
    }
    v8 = v14;
    this->_intChangeSignalDar._data = v14;
  }
  else
  {
    v8 = this->_intChangeSignalDar._data;
  }
  v8[v2] = s;
  ++this->_intChangeSignalDar._count;
}

void vgui::Slider::Slider(vgui::Slider *const this, int x, int y, int wide, int tall, bool vertical)
{
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  vgui::IntChangeSignal **v9; // edx
  vgui::InputSignal *v10; // eax
  int v11; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel((vgui::Panel *const)this, x, y, wide, tall);
  this->_intChangeSignalDar._count = 0;
  this->_intChangeSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Slider + 2);
  this->_intChangeSignalDar._data = 0;
  v6 = operator new[](0x10u);
  if ( !v6 )
    exit(0);
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 0;
  v7 = this->_intChangeSignalDar._count;
  this->_intChangeSignalDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      *(_DWORD *)(v6 + 4 * v8) = this->_intChangeSignalDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_intChangeSignalDar._count );
  }
  v9 = this->_intChangeSignalDar._data;
  if ( v9 )
  {
    v11 = v6;
    operator delete[]((VFontData *const)v9);
    v6 = v11;
  }
  this->_intChangeSignalDar._data = (vgui::IntChangeSignal **)v6;
  this->_range[1] = 299;
  this->_vertical = vertical;
  this->_rangeWindow = 0;
  this->_value = 0;
  this->_range[0] = 0;
  this->_buttonOffset = 0;
  this->_dragging = 0;
  this->_rangeWindowEnabled = 0;
  vgui::Slider::recomputeNobPosFromValue(this);
  v10 = (vgui::InputSignal *)operator new(8u);
  v10->_vptr_InputSignal = (int (**)(...))&off_47648;
  v10[1]._vptr_InputSignal = (int (**)(...))this;
  vgui::Panel::addInputSignal((vgui::Panel *const)this, v10);
}

