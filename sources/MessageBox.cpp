#include <VGUI_MessageBox.h>

void vgui::MessageBox::fireActionSignal(vgui::MessageBox *const this)
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

void vgui::MessageBox::performLayout(vgui::MessageBox *const this)
{
  int v2; // eax
  vgui::Label *v3; // edx
  int v4; // kr00_4
  int v5; // ebp
  int v6; // esi
  int v7; // eax
  vgui::Button *v8; // edx
  void (__cdecl *v9)(vgui::Button *, int, int); // edi
  int v10; // ebp
  int v11; // esi
  int v12; // eax
  void (__cdecl *v13)(vgui::Label *, int, int); // [esp+1Ch] [ebp-30h]
  int v14; // [esp+1Ch] [ebp-30h]
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall[8]; // [esp+2Ch] [ebp-20h] BYREF

  v2 = (*((int (__cdecl **)(vgui::MessageBox *const))this->_vptr_Panel + 129))(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v2 + 12))(v2, &wide, tall);
  v3 = this->_messageLabel;
  v13 = **(void (__cdecl ***)(vgui::Label *, int, int))v3->baseclass_0;
  v4 = tall[0];
  v5 = (*(int (__cdecl **)(vgui::Label *))(*(_DWORD *)v3->baseclass_0 + 28))(v3);
  v6 = wide / 2;
  v7 = (*(int (__cdecl **)(vgui::Label *))(*(_DWORD *)this->_messageLabel + 24))(this->_messageLabel);
  v13(this->_messageLabel, v6 - v7 / 2, v4 / 2 - v5 / 2 - 20);
  v8 = this->_okButton;
  v14 = tall[0];
  v9 = **(void (__cdecl ***)(vgui::Button *, int, int))v8->baseclass_0;
  v10 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)v8->baseclass_0 + 28))(v8);
  v11 = wide / 2;
  v12 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_okButton + 24))(this->_okButton);
  v9(this->_okButton, v11 - v12 / 2, v14 - v10 - 10);
}

void vgui::MessageBox::addActionSignal(vgui::MessageBox *const this, vgui::ActionSignal *s)
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

void vgui::MessageBox::MessageBox(vgui::MessageBox *const this, const char *title, const char *text, int x, int y)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::ActionSignal **v8; // edx
  vgui::Label *v9; // esi
  void (__cdecl *v10)(vgui::Label *, vgui::Panel *); // esi
  vgui::Panel *v11; // eax
  vgui::Button *v12; // esi
  void (__cdecl *v13)(vgui::Button *, vgui::Panel *); // esi
  vgui::Panel *v14; // eax
  void (__cdecl *v15)(vgui::Button *, _DWORD *); // esi
  _DWORD *v16; // eax
  int v17; // [esp+2Ch] [ebp-20h]
  int wide; // [esp+38h] [ebp-14h] BYREF
  int tall[4]; // [esp+3Ch] [ebp-10h] BYREF

  vgui::Frame::Frame(this, x, y, 64, 64);
  this->_actionSignalDar._count = 0;
  this->_actionSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::MessageBox + 2);
  this->_actionSignalDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    exit(0);
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_actionSignalDar._count;
  this->_actionSignalDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_actionSignalDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_actionSignalDar._count );
  }
  v8 = this->_actionSignalDar._data;
  if ( v8 )
  {
    v17 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v17;
  }
  this->_actionSignalDar._data = (vgui::ActionSignal **)v5;
  vgui::Frame::setTitle(this, title);
  vgui::Frame::setMenuButtonVisible(this, 0);
  vgui::Frame::setTrayButtonVisible(this, 0);
  vgui::Frame::setMinimizeButtonVisible(this, 0);
  vgui::Frame::setMaximizeButtonVisible(this, 0);
  vgui::Frame::setCloseButtonVisible(this, 0);
  vgui::Frame::setSizeable(this, 0);
  v9 = (vgui::Label *)operator new(0xD0u);
  vgui::Label::Label(v9, text);
  this->_messageLabel = v9;
  v10 = *(void (__cdecl **)(vgui::Label *, vgui::Panel *))(*(_DWORD *)v9->baseclass_0 + 64);
  v11 = vgui::Frame::getClient(this);
  v10(this->_messageLabel, v11);
  v12 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v12, "Ok", 10, 10);
  this->_okButton = v12;
  v13 = *(void (__cdecl **)(vgui::Button *, vgui::Panel *))(*(_DWORD *)v12->baseclass_0 + 64);
  v14 = vgui::Frame::getClient(this);
  v13(this->_okButton, v14);
  v15 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_okButton + 576);
  v16 = operator new(8u);
  v16[1] = this;
  *v16 = &off_46228;
  v15(this->_okButton, v16);
  (*(void (__cdecl **)(vgui::Label *, int *, int *))(*(_DWORD *)this->_messageLabel + 12))(
    this->_messageLabel,
    &wide,
    tall);
  vgui::Frame::setSize(this, wide + 100, tall[0] + 100);
}

