#include <VGUI_ScrollBar.h>

void vgui::ScrollBar::setValue(vgui::ScrollBar *const this, int value)
{
  (*((void (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 127))(this->_slider);
}

int vgui::ScrollBar::getValue(vgui::ScrollBar *const this)
{
  return (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 128))(this->_slider);
}

void vgui::ScrollBar::setRange(vgui::ScrollBar *const this, int min, int max)
{
  (*((void (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 131))(this->_slider);
}

void vgui::ScrollBar::fireIntChangeSignal(vgui::ScrollBar *const this)
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
      v4 = (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 128))(this->_slider);
      v3(v2, v4, this);
    }
    while ( this->_intChangeSignalDar._count > v1 );
  }
}

bool vgui::ScrollBar::isVertical(vgui::ScrollBar *const this)
{
  return (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 129))(this->_slider);
}

bool vgui::ScrollBar::hasFullRange(vgui::ScrollBar *const this)
{
  return (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 136))(this->_slider);
}

void vgui::ScrollBar::setButtonPressedScrollValue(vgui::ScrollBar *const this, int value)
{
  this->_buttonPressedScrollValue = value;
}

void vgui::ScrollBar::setRangeWindow(vgui::ScrollBar *const this, int rangeWindow)
{
  (*((void (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 133))(this->_slider);
}

void vgui::ScrollBar::setRangeWindowEnabled(vgui::ScrollBar *const this, bool state)
{
  (*((void (__cdecl **)(vgui::Slider *, bool))this->_slider->_vptr_Panel + 134))(this->_slider, state);
}

void vgui::ScrollBar::validate(vgui::ScrollBar *const this)
{
  vgui::Button *v1; // eax
  int v2; // esi
  vgui::Button *v3; // eax
  char v4; // al
  int v5; // edx
  char v6; // al
  int v7; // edx
  vgui::Button *v8; // [esp+0h] [ebp-2Ch]
  vgui::Button *v9; // [esp+0h] [ebp-2Ch]
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  if ( this->_slider )
  {
    v1 = this->_button[0];
    v2 = 0;
    if ( v1 && (*(uint8_t (__cdecl **)(vgui::Button *))(*(_DWORD *)v1->baseclass_0 + 40))(this->_button[0]) )
    {
      v6 = (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 129))(this->_slider);
      v7 = *(_DWORD *)this->_button[0];
      v9 = this->_button[0];
      if ( v6 )
        v2 = (*(int (__cdecl **)(vgui::Button *))(v7 + 28))(v9);
      else
        v2 = (*(int (__cdecl **)(vgui::Button *))(v7 + 24))(v9);
    }
    v3 = this->_button[1];
    if ( v3 && (*(uint8_t (__cdecl **)(vgui::Button *))(*(_DWORD *)v3->baseclass_0 + 40))(this->_button[1]) )
    {
      v4 = (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 129))(this->_slider);
      v5 = *(_DWORD *)this->_button[1];
      v8 = this->_button[1];
      if ( v4 )
        v2 += (*(int (__cdecl **)(vgui::Button *))(v5 + 28))(v8);
      else
        v2 += (*(int (__cdecl **)(vgui::Button *))(v5 + 24))(v8);
    }
    (*((void (__cdecl **)(vgui::Slider *, int))this->_slider->_vptr_Panel + 137))(this->_slider, v2);
  }
  (*((void (__cdecl **)(vgui::ScrollBar *const, int *, int *))this->_vptr_Panel + 3))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::ScrollBar *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
}

void vgui::ScrollBar::setSlider(vgui::ScrollBar *const this, vgui::Slider *slider)
{
  int (**v2)(...); // eax
  void (__cdecl *v3)(vgui::Slider *, _DWORD *); // esi
  _DWORD *v4; // eax

  if ( this->_slider )
    (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Slider *))this->_vptr_Panel + 19))(this, this->_slider);
  v2 = this->_vptr_Panel;
  this->_slider = slider;
  v2[17](this, slider);
  v3 = (void (__cdecl *)(vgui::Slider *, _DWORD *))*((_DWORD *)this->_slider->_vptr_Panel + 130);
  v4 = operator new(8u);
  v4[1] = this;
  *v4 = &off_47068;
  v3(this->_slider, v4);
  (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
}

void vgui::ScrollBar::setButton(vgui::ScrollBar *const this, vgui::Button *button, int index)
{
  int v3; // esi
  void (__cdecl *v4)(int, _DWORD *); // ebp
  _DWORD *v5; // eax

  v3 = index + 44;
  if ( this->_button[index] )
    (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 19))(this, this->_button[index]);
  this->_size[v3] = (int)button;
  (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 17))(this, button);
  v4 = *(void (__cdecl **)(int, _DWORD *))(*(_DWORD *)this->_size[v3] + 576);
  v5 = operator new(0xCu);
  v5[1] = this;
  v5[2] = index;
  *v5 = &off_47078;
  v4(this->_size[v3], v5);
  (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
}

void vgui::ScrollBar::setSize(vgui::ScrollBar *const this, int wide, int tall)
{
  char v3; // al
  vgui::Slider *v4; // ecx

  vgui::Panel::setSize(this, wide, tall);
  if ( this->_slider && this->_button[0] && this->_button[1] )
  {
    (*((void (__cdecl **)(vgui::ScrollBar *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
    v3 = (*((int (__cdecl **)(vgui::Slider *))this->_slider->_vptr_Panel + 129))(this->_slider);
    v4 = this->_slider;
    if ( v3 )
    {
      (*((void (__cdecl **)(vgui::Slider *, _DWORD, int, int, int))v4->_vptr_Panel + 4))(
        this->_slider,
        0,
        wide,
        wide,
        tall - 2 * wide);
      (*(void (__cdecl **)(vgui::Button *, _DWORD, _DWORD, int, int))(*(_DWORD *)this->_button[0] + 16))(
        this->_button[0],
        0,
        0,
        wide,
        wide);
      (*(void (__cdecl **)(vgui::Button *, _DWORD, int, int, int))(*(_DWORD *)this->_button[1] + 16))(
        this->_button[1],
        0,
        tall - wide,
        wide,
        wide);
    }
    else
    {
      (*((void (__cdecl **)(vgui::Slider *, int, _DWORD, int, int))v4->_vptr_Panel + 4))(
        this->_slider,
        tall,
        0,
        wide - 2 * tall,
        tall);
      (*(void (__cdecl **)(vgui::Button *, _DWORD, _DWORD, int, int))(*(_DWORD *)this->_button[0] + 16))(
        this->_button[0],
        0,
        0,
        tall,
        tall);
      (*(void (__cdecl **)(vgui::Button *, int, _DWORD, int, int))(*(_DWORD *)this->_button[1] + 16))(
        this->_button[1],
        wide - tall,
        0,
        tall,
        tall);
    }
  }
}

void vgui::ScrollBar::doButtonPressed(vgui::ScrollBar *const this, int buttonIndex)
{
  vgui::Slider *v2; // edx
  void (__cdecl *v3)(vgui::Slider *, int); // esi
  int v4; // eax
  int v5; // eax

  v2 = this->_slider;
  v3 = (void (__cdecl *)(vgui::Slider *, int))*((_DWORD *)v2->_vptr_Panel + 127);
  v4 = (*((int (__cdecl **)(vgui::Slider *))v2->_vptr_Panel + 128))(v2);
  if ( buttonIndex )
    v5 = this->_buttonPressedScrollValue + v4;
  else
    v5 = v4 - this->_buttonPressedScrollValue;
  v3(this->_slider, v5);
}

void vgui::ScrollBar::addIntChangeSignal(vgui::ScrollBar *const this, vgui::IntChangeSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::IntChangeSignal*> *v3; // ebp
  vgui::IntChangeSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::IntChangeSignal **v8; // eax
  void (__cdecl *v9)(vgui::Slider *, _DWORD *); // ebx
  _DWORD *v10; // eax
  unsigned int v11; // edi
  _BYTE *v12; // eax
  _WORD *v13; // edi
  int v14; // eax
  int v15; // [esp+14h] [ebp-28h]
  vgui::IntChangeSignal **v16; // [esp+18h] [ebp-24h]
  unsigned int v17; // [esp+1Ch] [ebp-20h]

  v2 = this->_intChangeSignalDar._count;
  v3 = &this->_intChangeSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_intChangeSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      goto LABEL_9;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        goto LABEL_9;
    }
  }
  v6 = this->_intChangeSignalDar._capacity;
  v7 = v2 + 1;
  if ( v2 + 1 > v6 )
  {
    if ( v6 || (v6 = 1, v11 = 4, v7 > 1) )
    {
      do
        v6 *= 2;
      while ( v7 > v6 );
      v11 = 4 * v6;
    }
    v15 = v6;
    v12 = (_BYTE *)operator new[](v11);
    v16 = (vgui::IntChangeSignal **)v12;
    if ( !v12 )
      exit(0);
    v17 = v11;
    v13 = v12;
    if ( v17 >= 8 )
    {
      if ( ((uint8_t)v12 & 1) != 0 )
      {
        *v12 = 0;
        --v17;
        v13 = v12 + 1;
      }
      if ( ((uint8_t)v13 & 2) != 0 )
      {
        *v13++ = 0;
        v17 -= 2;
      }
      if ( ((uint8_t)v13 & 4) != 0 )
      {
        *(_DWORD *)v13 = 0;
        v13 += 2;
        v17 -= 4;
      }
      memset(v13, 0, 4 * (v17 >> 2));
      v13 += 2 * (v17 >> 2);
      LOBYTE(v17) = v17 & 3;
    }
    if ( (v17 & 4) != 0 )
    {
      *(_DWORD *)v13 = 0;
      v13 += 2;
    }
    if ( (v17 & 2) != 0 )
      *v13++ = 0;
    if ( (v17 & 1) != 0 )
      *(_BYTE *)v13 = 0;
    v2 = this->_intChangeSignalDar._count;
    this->_intChangeSignalDar._capacity = v15;
    if ( v2 > 0 )
    {
      v14 = 0;
      do
      {
        v16[v14] = this->_intChangeSignalDar._data[v14];
        ++v14;
        v2 = v3->_count;
      }
      while ( v14 < v3->_count );
    }
    if ( this->_intChangeSignalDar._data )
    {
      operator delete[]((VFontData *const)this->_intChangeSignalDar._data);
      v2 = this->_intChangeSignalDar._count;
    }
    v8 = v16;
    this->_intChangeSignalDar._data = v16;
  }
  else
  {
    v8 = this->_intChangeSignalDar._data;
  }
  v8[v2] = s;
  ++this->_intChangeSignalDar._count;
LABEL_9:
  v9 = (void (__cdecl *)(vgui::Slider *, _DWORD *))*((_DWORD *)this->_slider->_vptr_Panel + 130);
  v10 = operator new(8u);
  *v10 = &off_47068;
  v10[1] = this;
  v9(this->_slider, v10);
}

void vgui::ScrollBar::ScrollBar(vgui::ScrollBar *const this, int x, int y, int wide, int tall, bool vertical)
{
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  vgui::IntChangeSignal **v9; // edx
  vgui::Slider *v10; // esi
  int (**v11)(...); // eax
  void (__cdecl *v12)(vgui::Slider *, _DWORD *); // esi
  _DWORD *v13; // eax
  vgui::Button *v14; // eax
  int (**v15)(...); // edx
  _DWORD *v16; // eax
  vgui::Button *v17; // eax
  int (**v18)(...); // edx
  void (__cdecl *v19)(vgui::Button *, _DWORD *); // esi
  _DWORD *v20; // eax
  vgui::Slider *v21; // esi
  int (**v22)(...); // eax
  void (__cdecl *v23)(vgui::Slider *, _DWORD *); // esi
  _DWORD *v24; // eax
  vgui::Button *v25; // esi
  int (**v26)(...); // eax
  void (__cdecl *v27)(vgui::Button *, _DWORD *); // esi
  _DWORD *v28; // eax
  vgui::Button *v29; // esi
  int (**v30)(...); // eax
  int v31; // [esp+28h] [ebp-24h]
  vgui::Button *v32; // [esp+28h] [ebp-24h]
  vgui::Button *v33; // [esp+28h] [ebp-24h]
  void (__cdecl *v34)(vgui::Button *, _DWORD *); // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_intChangeSignalDar._count = 0;
  this->_intChangeSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ScrollBar + 2);
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
    v31 = v6;
    operator delete[]((VFontData *const)v9);
    v6 = v31;
  }
  this->_intChangeSignalDar._data = (vgui::IntChangeSignal **)v6;
  this->_button[0] = 0;
  this->_slider = 0;
  this->_button[1] = 0;
  if ( vertical )
  {
    v21 = (vgui::Slider *)operator new(0xFCu);
    vgui::Slider::Slider(v21, 0, wide - 1, wide, tall - 2 * wide + 2, 1);
    if ( this->_slider )
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Slider *))this->_vptr_Panel + 19))(this, this->_slider);
    v22 = this->_vptr_Panel;
    this->_slider = v21;
    v22[17](this, v21);
    v23 = (void (__cdecl *)(vgui::Slider *, _DWORD *))*((_DWORD *)this->_slider->_vptr_Panel + 130);
    v24 = operator new(8u);
    *v24 = &off_47068;
    v24[1] = this;
    v23(this->_slider, v24);
    (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
    v25 = (vgui::Button *)operator new(0xF0u);
    vgui::Button::Button(v25, "", 0, 0, wide, wide);
    if ( this->_button[0] )
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 19))(this, this->_button[0]);
    v26 = this->_vptr_Panel;
    this->_button[0] = v25;
    v26[17](this, v25);
    v27 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_button[0] + 576);
    v28 = operator new(0xCu);
    *v28 = &off_47078;
    v28[1] = this;
    v28[2] = 0;
    v27(this->_button[0], v28);
    (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
    v29 = (vgui::Button *)operator new(0xF0u);
    vgui::Button::Button(v29, "", 0, tall - wide, wide, wide);
    if ( this->_button[1] )
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 19))(this, this->_button[1]);
    v30 = this->_vptr_Panel;
    this->_button[1] = v29;
    v30[17](this, v29);
  }
  else
  {
    v10 = (vgui::Slider *)operator new(0xFCu);
    vgui::Slider::Slider(v10, tall, 0, wide - 2 * tall, tall, 0);
    if ( this->_slider )
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Slider *))this->_vptr_Panel + 19))(this, this->_slider);
    v11 = this->_vptr_Panel;
    this->_slider = v10;
    v11[17](this, v10);
    v12 = (void (__cdecl *)(vgui::Slider *, _DWORD *))*((_DWORD *)this->_slider->_vptr_Panel + 130);
    v13 = operator new(8u);
    *v13 = &off_47068;
    v13[1] = this;
    v12(this->_slider, v13);
    (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
    v32 = (vgui::Button *)operator new(0xF0u);
    vgui::Button::Button(v32, "", 0, 0, tall + 1, tall + 1);
    v14 = v32;
    if ( this->_button[0] )
    {
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 19))(this, this->_button[0]);
      v14 = v32;
    }
    v15 = this->_vptr_Panel;
    this->_button[0] = v14;
    v15[17](this, v14);
    v34 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_button[0] + 576);
    v16 = operator new(0xCu);
    *v16 = &off_47078;
    v16[1] = this;
    v16[2] = 0;
    v34(this->_button[0], v16);
    (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
    v33 = (vgui::Button *)operator new(0xF0u);
    vgui::Button::Button(v33, "", wide - tall, 0, tall + 1, tall + 1);
    v17 = v33;
    if ( this->_button[1] )
    {
      (*((void (__cdecl **)(vgui::ScrollBar *const, vgui::Button *))this->_vptr_Panel + 19))(this, this->_button[1]);
      v17 = v33;
    }
    v18 = this->_vptr_Panel;
    this->_button[1] = v17;
    v18[17](this, v17);
  }
  v19 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_button[1] + 576);
  v20 = operator new(0xCu);
  v20[1] = this;
  *v20 = &off_47078;
  v20[2] = 1;
  v19(this->_button[1], v20);
  (*((void (__cdecl **)(vgui::ScrollBar *const))this->_vptr_Panel + 141))(this);
  vgui::Panel::setPaintBorderEnabled(this, 1);
  vgui::Panel::setPaintBackgroundEnabled(this, 1);
  vgui::Panel::setPaintEnabled(this, 1);
  this->_buttonPressedScrollValue = 15;
  vgui::ScrollBar::validate(this);
}

