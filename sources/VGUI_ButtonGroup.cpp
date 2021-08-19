#include <VGUI_ButtonGroup.h>

void vgui::ButtonGroup::setSelected(vgui::ButtonGroup *const this, vgui::Button *button)
{
  int v2; // esi
  int v3; // ebx
  vgui::Button *v4; // eax

  if ( this->_buttonDar._count > 0 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      v4 = this->_buttonDar._data[v2];
      if ( button != v4 )
        (*(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)v4->baseclass_0 + 560))(v4, 0);
      ++v3;
      ++v2;
    }
    while ( this->_buttonDar._count > v3 );
  }
  (*(void (__cdecl **)(vgui::Button *, int))(*(_DWORD *)button->baseclass_0 + 560))(button, 1);
}

void vgui::ButtonGroup::addButton(vgui::ButtonGroup *const this, vgui::Button *button)
{
  int v2; // ecx
  vgui::Button **v3; // edx
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  vgui::Button **v7; // edx
  unsigned int v8; // edi
  _BYTE *v9; // eax
  _WORD *v10; // edi
  int i; // eax
  vgui::Button **v12; // eax
  vgui::Button **v13; // [esp+18h] [ebp-24h]
  unsigned int v14; // [esp+1Ch] [ebp-20h]

  v2 = this->_buttonDar._count;
  if ( v2 > 0 )
  {
    v3 = this->_buttonDar._data;
    v4 = 0;
    if ( button == *v3 )
      return;
    while ( ++v4 != v2 )
    {
      if ( button == v3[v4] )
        return;
    }
  }
  v5 = this->_buttonDar._capacity;
  v6 = v2 + 1;
  if ( v2 + 1 > v5 )
  {
    if ( v5 || (v5 = 1, v8 = 4, v6 > 1) )
    {
      do
        v5 *= 2;
      while ( v6 > v5 );
      v8 = 4 * v5;
    }
    v9 = (_BYTE *)operator new[](v8);
    v7 = (vgui::Button **)v9;
    if ( !v9 )
      exit(0);
    v14 = v8;
    v10 = v9;
    if ( v14 >= 8 )
    {
      if ( ((uint8_t)v9 & 1) != 0 )
      {
        *v9 = 0;
        v10 = v9 + 1;
        --v14;
      }
      if ( ((uint8_t)v10 & 2) != 0 )
      {
        *v10++ = 0;
        v14 -= 2;
      }
      if ( ((uint8_t)v10 & 4) != 0 )
      {
        *(_DWORD *)v10 = 0;
        v10 += 2;
        v14 -= 4;
      }
      memset(v10, 0, 4 * (v14 >> 2));
      v10 += 2 * (v14 >> 2);
      LOBYTE(v14) = v14 & 3;
      if ( (v14 & 4) == 0 )
      {
LABEL_17:
        if ( (v14 & 2) == 0 )
          goto LABEL_18;
        goto LABEL_26;
      }
    }
    else if ( (v14 & 4) == 0 )
    {
      goto LABEL_17;
    }
    *(_DWORD *)v10 = 0;
    v10 += 2;
    if ( (v14 & 2) == 0 )
    {
LABEL_18:
      if ( (v14 & 1) == 0 )
      {
LABEL_19:
        v2 = this->_buttonDar._count;
        this->_buttonDar._capacity = v5;
        if ( v2 > 0 )
        {
          for ( i = 0; i < v2; ++i )
          {
            v7[i] = this->_buttonDar._data[i];
            v2 = this->_buttonDar._count;
          }
        }
        v12 = this->_buttonDar._data;
        if ( v12 )
        {
          v13 = v7;
          operator delete[](v12);
          v2 = this->_buttonDar._count;
          v7 = v13;
        }
        this->_buttonDar._data = v7;
        goto LABEL_8;
      }
LABEL_25:
      *(_BYTE *)v10 = 0;
      goto LABEL_19;
    }
LABEL_26:
    *v10++ = 0;
    if ( (v14 & 1) == 0 )
      goto LABEL_19;
    goto LABEL_25;
  }
  v7 = this->_buttonDar._data;
LABEL_8:
  v7[v2] = button;
  ++this->_buttonDar._count;
}

