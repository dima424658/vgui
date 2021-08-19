#include <VGUI_Button.h>

void vgui::Button::setButtonBorderEnabled(vgui::Button *const this, bool state)
{
  this->_buttonBorderEnabled = state;
  (*(void (**)(void))(*(_DWORD *)this->baseclass_0 + 48))();
}

void vgui::Button::setSelectedDirect(vgui::Button *const this, bool state)
{
  this->_selected = state;
  (*(void (**)(void))(*(_DWORD *)this->baseclass_0 + 48))();
}

void vgui::Button::setArmed(vgui::Button *const this, bool state)
{
  this->_armed = state;
  (*(void (**)(void))(*(_DWORD *)this->baseclass_0 + 48))();
}

bool vgui::Button::isArmed(vgui::Button *const this)
{
  return this->_armed;
}

void vgui::Button::doClick(vgui::Button *const this)
{
  (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 556))(this, 1);
  (*(void (__cdecl **)(vgui::Button *const))(*(_DWORD *)this->baseclass_0 + 600))(this);
  (*(void (__cdecl **)(vgui::Button *const, _DWORD))(*(_DWORD *)this->baseclass_0 + 556))(this, 0);
}

bool vgui::Button::isSelected(vgui::Button *const this)
{
  return this->_selected;
}

void vgui::Button::paintBackground(vgui::Button *const this)
{
  bool v1; // zf
  int v2; // eax
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*(void (__cdecl **)(vgui::Button *const, int *, int *))(*(_DWORD *)this->baseclass_0 + 232))(this, &wide, tall);
  v1 = (*(uint8_t (__cdecl **)(vgui::Button *const))(*(_DWORD *)this->baseclass_0 + 568))(this) == 0;
  v2 = *(_DWORD *)this->baseclass_0;
  if ( v1 )
  {
    (*(void (__cdecl **)(vgui::Button *const, int))(v2 + 372))(this, 8);
    (*(void (__cdecl **)(vgui::Button *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      0,
      0,
      wide,
      tall[0]);
    if ( this->_buttonBorderEnabled )
    {
      (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 6);
      (*(void (__cdecl **)(vgui::Button *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        0,
        0,
        *(_DWORD *)&this->baseclass_0[12] - 1,
        1);
      (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        2,
        *(_DWORD *)&this->baseclass_0[16] - 2,
        *(_DWORD *)&this->baseclass_0[12] - 1,
        *(_DWORD *)&this->baseclass_0[16] - 1);
      (*(void (__cdecl **)(vgui::Button *const, _DWORD, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        0,
        1,
        1,
        *(_DWORD *)&this->baseclass_0[16] - 1);
      (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        *(_DWORD *)&this->baseclass_0[12] - 2,
        2,
        *(_DWORD *)&this->baseclass_0[12] - 1,
        *(_DWORD *)&this->baseclass_0[16] - 2);
      (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 2);
      (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        1,
        1,
        *(_DWORD *)&this->baseclass_0[12] - 2,
        2);
      (*(void (__cdecl **)(vgui::Button *const, int, int, _DWORD, _DWORD))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        1,
        *(_DWORD *)&this->baseclass_0[16] - 1,
        *(_DWORD *)&this->baseclass_0[12],
        *(_DWORD *)&this->baseclass_0[16]);
      (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        1,
        2,
        2,
        *(_DWORD *)&this->baseclass_0[16] - 2);
      (*(void (__cdecl **)(vgui::Button *const, int, int, _DWORD, int))(*(_DWORD *)this->baseclass_0 + 380))(
        this,
        *(_DWORD *)&this->baseclass_0[12] - 1,
        1,
        *(_DWORD *)&this->baseclass_0[12],
        *(_DWORD *)&this->baseclass_0[16] - 1);
    }
  }
  else
  {
    (*(void (__cdecl **)(vgui::Button *const, int))(v2 + 372))(this, 7);
    (*(void (__cdecl **)(vgui::Button *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      0,
      0,
      wide,
      tall[0]);
  }
  if ( (*(uint8_t (__cdecl **)(vgui::Button *const))(*(_DWORD *)this->baseclass_0 + 584))(this) )
  {
    (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 2);
    (*(void (__cdecl **)(vgui::Button *const, _DWORD, _DWORD, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      0,
      0,
      wide,
      2);
    (*(void (__cdecl **)(vgui::Button *const, _DWORD, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      0,
      2,
      2,
      tall[0]);
    (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 7);
    (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      2,
      tall[0] - 2,
      wide,
      tall[0]);
    (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      wide - 2,
      2,
      wide,
      tall[0] - 1);
    (*(void (__cdecl **)(vgui::Button *const, int))(*(_DWORD *)this->baseclass_0 + 372))(this, 6);
    (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      1,
      tall[0] - 1,
      wide,
      tall[0]);
    (*(void (__cdecl **)(vgui::Button *const, int, int, int, int))(*(_DWORD *)this->baseclass_0 + 380))(
      this,
      wide - 1,
      1,
      wide,
      tall[0] - 1);
  }
}

void vgui::Button::setButtonGroup(vgui::Button *const this, vgui::ButtonGroup *buttonGroup)
{
  this->_buttonGroup = buttonGroup;
  if ( buttonGroup )
    (*buttonGroup->_vptr_ButtonGroup)(buttonGroup, this);
}

bool vgui::Button::isMouseClickEnabled(vgui::Button *const this, vgui::MouseCode code)
{
  return (this->_mouseClickMask >> (code + 1)) & 1;
}

void vgui::Button::fireActionSignal(vgui::Button *const this)
{
  int v1; // ebx
  vgui::ActionSignal *v2; // eax

  if ( this->_actionSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_actionSignalDar._data[v1++];
      (*v2->_vptr_ActionSignal)(v2, this);
    }
    while ( this->_actionSignalDar._count > v1 );
  }
}

void vgui::Button::setButtonController(vgui::Button *const this, vgui::ButtonController *buttonController)
{
  vgui::ButtonController *v2; // eax

  v2 = this->_buttonController;
  if ( v2 )
    (*((void (__cdecl **)(vgui::ButtonController *, vgui::Button *const))v2->_vptr_ButtonController + 1))(v2, this);
  this->_buttonController = buttonController;
  (*buttonController->_vptr_ButtonController)(buttonController, this);
}

void vgui::Button::setSelected(vgui::Button *const this, bool state)
{
  vgui::ButtonGroup *v2; // edx

  v2 = this->_buttonGroup;
  if ( v2 )
    (*((void (__cdecl **)(vgui::ButtonGroup *, vgui::Button *const))v2->_vptr_ButtonGroup + 1))(v2, this);
  else
    (*(void (__thiscall **)(vgui::Button *const, vgui::Button *const, bool))(*(_DWORD *)this->baseclass_0 + 560))(
      this,
      this,
      state);
}

void vgui::Button::setMouseClickEnabled(vgui::Button *const this, vgui::MouseCode code, bool state)
{
  char v3; // cl

  v3 = code + 1;
  if ( state )
    this->_mouseClickMask |= 1 << v3;
  else
    this->_mouseClickMask &= __ROL4__(-2, v3);
}

void vgui::Button::addActionSignal(vgui::Button *const this, vgui::ActionSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::ActionSignal*> *v3; // esi
  vgui::ActionSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::ActionSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::ActionSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  if ( s )
  {
    v2 = this->_actionSignalDar._count;
    v3 = &this->_actionSignalDar;
    if ( v2 > 0 )
    {
      v4 = this->_actionSignalDar._data;
      v5 = 0;
      if ( s == *v4 )
        return;
      while ( ++v5 != v2 )
      {
        if ( s == v4[v5] )
          return;
      }
    }
    v6 = this->_actionSignalDar._capacity;
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
      v14 = (vgui::ActionSignal **)v10;
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
      v2 = this->_actionSignalDar._count;
      this->_actionSignalDar._capacity = v13;
      if ( v2 > 0 )
      {
        v12 = 0;
        do
        {
          v14[v12] = this->_actionSignalDar._data[v12];
          ++v12;
          v2 = v3->_count;
        }
        while ( v12 < v3->_count );
      }
      if ( this->_actionSignalDar._data )
      {
        operator delete[](this->_actionSignalDar._data);
        v2 = this->_actionSignalDar._count;
      }
      v8 = v14;
      this->_actionSignalDar._data = v14;
    }
    else
    {
      v8 = this->_actionSignalDar._data;
    }
    v8[v2] = s;
    ++this->_actionSignalDar._count;
  }
}

void vgui::Button::init(vgui::Button *const this)
{
  int v1; // eax
  void (__cdecl *v2)(vgui::Button *const, _DWORD *); // esi
  _DWORD *v3; // eax

  this->_mouseClickMask = 0;
  this->_buttonController = 0;
  this->_buttonGroup = 0;
  v1 = *(_DWORD *)this->baseclass_0;
  this->_armed = 0;
  this->_selected = 0;
  this->_buttonBorderEnabled = 1;
  (*(void (__cdecl **)(vgui::Button *const, _DWORD, int))(v1 + 592))(this, 0, 1);
  v2 = *(void (__cdecl **)(vgui::Button *const, _DWORD *))(*(_DWORD *)this->baseclass_0 + 604);
  v3 = operator new(0xCu);
  v3[2] = this;
  *v3 = off_42BE8;
  v3[1] = &off_42C24;
  v2(this, v3);
}

void vgui::Button::Button(vgui::Button *const this, const char *text, int x, int y, int wide, int tall)
{
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  vgui::ActionSignal **v9; // edx
  int v10; // eax
  void (__cdecl *v11)(vgui::Button *const, _DWORD *); // esi
  _DWORD *v12; // eax
  int v13; // [esp+2Ch] [ebp-10h]

  vgui::Label::Label(this, text, x, y, wide, tall);
  this->_actionSignalDar._count = 0;
  this->_actionSignalDar._capacity = 0;
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Button + 2;
  this->_actionSignalDar._data = 0;
  v6 = operator new[](0x10u);
  if ( !v6 )
    exit(0);
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 0;
  v7 = this->_actionSignalDar._count;
  this->_actionSignalDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      *(_DWORD *)(v6 + 4 * v8) = this->_actionSignalDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_actionSignalDar._count );
  }
  v9 = this->_actionSignalDar._data;
  if ( v9 )
  {
    v13 = v6;
    operator delete[]((VFontData *const)v9);
    v6 = v13;
  }
  this->_actionSignalDar._data = (vgui::ActionSignal **)v6;
  this->_buttonController = 0;
  this->_buttonGroup = 0;
  v10 = *(_DWORD *)this->baseclass_0;
  this->_mouseClickMask = 0;
  this->_armed = 0;
  this->_selected = 0;
  this->_buttonBorderEnabled = 1;
  (*(void (__cdecl **)(vgui::Button *const, _DWORD, int))(v10 + 592))(this, 0, 1);
  v11 = *(void (__cdecl **)(vgui::Button *const, _DWORD *))(*(_DWORD *)this->baseclass_0 + 604);
  v12 = operator new(0xCu);
  *v12 = off_42BE8;
  v12[1] = &off_42C24;
  v12[2] = this;
  v11(this, v12);
}

void vgui::Button::Button(vgui::Button *const this, const char *text, int x, int y)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  vgui::ActionSignal **v7; // edx
  int v8; // eax
  void (__cdecl *v9)(vgui::Button *const, _DWORD *); // esi
  _DWORD *v10; // eax
  int v11; // [esp+1Ch] [ebp-10h]

  vgui::Label::Label(this, text, x, y);
  this->_actionSignalDar._count = 0;
  this->_actionSignalDar._capacity = 0;
  *(_DWORD *)this->baseclass_0 = &`vtable for'vgui::Button + 2;
  this->_actionSignalDar._data = 0;
  v4 = operator new[](0x10u);
  if ( !v4 )
    exit(0);
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  v5 = this->_actionSignalDar._count;
  this->_actionSignalDar._capacity = 4;
  if ( v5 > 0 )
  {
    v6 = 0;
    do
    {
      *(_DWORD *)(v4 + 4 * v6) = this->_actionSignalDar._data[v6];
      ++v6;
    }
    while ( v6 < this->_actionSignalDar._count );
  }
  v7 = this->_actionSignalDar._data;
  if ( v7 )
  {
    v11 = v4;
    operator delete[]((VFontData *const)v7);
    v4 = v11;
  }
  this->_actionSignalDar._data = (vgui::ActionSignal **)v4;
  this->_mouseClickMask = 0;
  this->_buttonController = 0;
  this->_buttonGroup = 0;
  v8 = *(_DWORD *)this->baseclass_0;
  this->_armed = 0;
  this->_selected = 0;
  this->_buttonBorderEnabled = 1;
  (*(void (__cdecl **)(vgui::Button *const, _DWORD, int))(v8 + 592))(this, 0, 1);
  v9 = *(void (__cdecl **)(vgui::Button *const, _DWORD *))(*(_DWORD *)this->baseclass_0 + 604);
  v10 = operator new(0xCu);
  *v10 = off_42BE8;
  v10[1] = &off_42C24;
  v10[2] = this;
  v9(this, v10);
}

