#include <VGUI_TextEntry.h>

void vgui::TextEntry::resetCursorBlink(vgui::TextEntry *const this)
{
  int (**v1)(...); // eax
  int v2; // eax

  v1 = this->_vptr_Panel;
  this->_cursorBlink = 0;
  v2 = v1[83](this);
  this->_cursorNextBlinkTime = this->_cursorBlinkRate + (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 92))(v2);
}

void vgui::TextEntry::setTextHidden(vgui::TextEntry *const this, bool bHideText)
{
  this->_hideText = bHideText;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

int vgui::TextEntry::cursorToPixelSpace(vgui::TextEntry *const this, int cursorPos)
{
  vgui::Font *v2; // edi
  int v3; // ebp
  int v4; // esi
  int (*v5)(...); // edx
  int v6; // eax
  int (**v7)(...); // eax
  int v9; // eax
  int v10; // eax
  int a[4]; // [esp+20h] [ebp-4Ch] BYREF
  int b[4]; // [esp+30h] [ebp-3Ch] BYREF
  int c[11]; // [esp+40h] [ebp-2Ch] BYREF

  v2 = this->_font;
  if ( !v2 )
  {
    v9 = (*((int (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 83))(this);
    v10 = (*(int (__cdecl **)(int))(*(_DWORD *)v9 + 84))(v9);
    v2 = (vgui::Font *)(*(int (__cdecl **)(int, int))(*(_DWORD *)v10 + 12))(v10, 1);
  }
  v3 = 0;
  if ( this->_lineDar._count > 0 && cursorPos )
  {
    v4 = 0;
    do
    {
      v7 = v2->_vptr_Font;
      if ( this->_hideText )
      {
        v7[2](v2, 42, a, b, c);
      }
      else
      {
        v5 = v7[2];
        v6 = 0;
        if ( v4 >= 0 )
          v6 = this->_lineDar._data[v4];
        v5(v2, v6, a, b, c);
      }
      ++v4;
      v3 += c[0] + b[0] + a[0];
    }
    while ( this->_lineDar._count > v4 && cursorPos != v4 );
  }
  return v3;
}

void vgui::TextEntry::paintBackground(vgui::TextEntry *const this)
{
  vgui::Font *v1; // esi
  int v2; // edi
  char v3; // dl
  int (**v4)(...); // eax
  int v5; // esi
  int v6; // edx
  int (**v7)(...); // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int x0; // [esp+28h] [ebp-24h] BYREF
  int x1[8]; // [esp+2Ch] [ebp-20h] BYREF

  v1 = this->_font;
  if ( !v1 )
  {
    v9 = (*((int (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 83))(this);
    v10 = (*(int (__cdecl **)(int))(*(_DWORD *)v9 + 84))(v9);
    v1 = (vgui::Font *)(*(int (__cdecl **)(int, int))(*(_DWORD *)v10 + 12))(v10, 1);
  }
  v2 = (*((int (__cdecl **)(vgui::Font *))v1->_vptr_Font + 4))(v1);
  v3 = (*((int (__cdecl **)(vgui::TextEntry *const, int *, int *))this->_vptr_Panel + 148))(this, &x0, x1);
  v4 = this->_vptr_Panel;
  if ( v3 )
  {
    v4[93](this, 2);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      0,
      x0,
      v2 + 1);
    (*((void (__cdecl **)(vgui::TextEntry *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      x1[0],
      0,
      this->_size[0],
      v2 + 1);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, _DWORD, int, _DWORD))this->_vptr_Panel + 94))(
      this,
      0,
      0,
      200,
      0);
    (*((void (__cdecl **)(vgui::TextEntry *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      x0,
      0,
      x1[0],
      v2 + 1);
  }
  else
  {
    v4[93](this, 2);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      0,
      this->_size[0],
      this->_size[1]);
  }
  (*((void (__cdecl **)(vgui::TextEntry *const, vgui::Font *))this->_vptr_Panel + 98))(this, v1);
  (*((void (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 99))(this, 1);
  (*((void (__cdecl **)(vgui::TextEntry *const, int, _DWORD))this->_vptr_Panel + 101))(this, 3, 0);
  if ( this->_lineDar._count > 0 )
  {
    v5 = 0;
    do
    {
      while ( 1 )
      {
        v7 = this->_vptr_Panel;
        if ( this->_hideText )
          break;
        v6 = this->_lineDar._data[v5++];
        v7[104](this, v6);
        if ( this->_lineDar._count <= v5 )
          goto LABEL_10;
      }
      ++v5;
      v7[104](this, 42);
    }
    while ( this->_lineDar._count > v5 );
  }
LABEL_10:
  if ( (*((uint8_t (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 42))(this) )
  {
    (*((void (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 93))(this, 1);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      0,
      this->_size[0],
      1);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      this->_size[1] - 1,
      this->_size[0],
      this->_size[1]);
    (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
      this,
      0,
      1,
      1,
      this->_size[1] - 1);
    (*((void (__cdecl **)(vgui::TextEntry *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      this->_size[0] - 1,
      1,
      this->_size[0],
      this->_size[1] - 1);
    if ( !this->_cursorBlink )
    {
      v8 = (*((int (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 149))(this, this->_cursorPos);
      (*((void (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 93))(this, 1);
      (*((void (__cdecl **)(vgui::TextEntry *const, int, int, int, int))this->_vptr_Panel + 95))(
        this,
        v8 + 3,
        2,
        v8 + 4,
        v2 - 1);
    }
  }
}

void `non-virtual thunk to'vgui::TextEntry::cursorMoved(vgui::TextEntry *this, int a2, int a3, vgui::Panel *a4)
{
  vgui::TextEntry::cursorMoved((vgui::TextEntry *)((char *)this - 188), a2, a3, a4);
}

void `non-virtual thunk to'vgui::TextEntry::cursorEntered(vgui::TextEntry *this, vgui::Panel *a2)
{
  vgui::TextEntry::cursorEntered((vgui::TextEntry *)((char *)this - 188), a2);
}

void `non-virtual thunk to'vgui::TextEntry::cursorExited(vgui::TextEntry *this, vgui::Panel *a2)
{
  vgui::TextEntry::cursorExited((vgui::TextEntry *)((char *)this - 188), a2);
}

void `non-virtual thunk to'vgui::TextEntry::mousePressed(vgui::TextEntry *this, vgui::MouseCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::mousePressed((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void vgui::TextEntry::mousePressed(vgui::TextEntry *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 41))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void `non-virtual thunk to'vgui::TextEntry::mouseDoublePressed(vgui::TextEntry *this, vgui::MouseCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::mouseDoublePressed((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void `non-virtual thunk to'vgui::TextEntry::mouseReleased(vgui::TextEntry *this, vgui::MouseCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::mouseReleased((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void `non-virtual thunk to'vgui::TextEntry::mouseWheeled(vgui::TextEntry *this, int a2, vgui::Panel *a3)
{
  vgui::TextEntry::mouseWheeled((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void `non-virtual thunk to'vgui::TextEntry::keyPressed(vgui::TextEntry *this, vgui::KeyCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::keyPressed((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void `non-virtual thunk to'vgui::TextEntry::keyTyped(vgui::TextEntry *this, vgui::KeyCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::keyTyped((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void vgui::TextEntry::keyTyped(vgui::TextEntry *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  bool v3; // bl
  int v4; // ebx
  int (__cdecl *v5)(int, vgui::KeyCode, _BOOL4); // ebp
  char v6; // dl
  _BOOL4 v7; // eax
  char v8; // al
  int (**v9)(...); // eax

  v3 = 1;
  if ( !(*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 78) )
    v3 = (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 79) != 0;
  if ( (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 82)
    || (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 83) )
  {
    if ( code == KEY_C )
    {
      (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 138))(this);
    }
    else if ( code == KEY_V )
    {
LABEL_17:
      (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 139))(this);
    }
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
      case KEY_TAB:
      case KEY_LSHIFT:
      case KEY_RSHIFT:
        break;
      case KEY_BACKSPACE:
        (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 135))(this);
        break;
      case KEY_INSERT:
        if ( v3 )
          goto LABEL_17;
        break;
      case KEY_DELETE:
        v9 = this->_vptr_Panel;
        if ( v3 )
          v9[141](this);
        else
          v9[136](this);
        break;
      case KEY_HOME:
        (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 132))(this);
        break;
      case KEY_END:
        (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 133))(this);
        break;
      case KEY_LEFT:
        (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 130))(this);
        break;
      case KEY_RIGHT:
        (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 131))(this);
        break;
      default:
        v4 = (*((int (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 83))(this);
        v5 = *(int (__cdecl **)(int, vgui::KeyCode, _BOOL4))(*(_DWORD *)v4 + 96);
        v6 = (*((int (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 78);
        v7 = 1;
        if ( !v6 )
          v7 = (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 79) != 0;
        v8 = v5(v4, code, v7);
        if ( v8 )
          (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD))this->_vptr_Panel + 134))(this, v8);
        break;
    }
  }
  this->_select[1] = this->_cursorPos;
  if ( code == KEY_ENTER )
    (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 146))(this);
}

void `non-virtual thunk to'vgui::TextEntry::keyReleased(vgui::TextEntry *this, vgui::KeyCode a2, vgui::Panel *a3)
{
  vgui::TextEntry::keyReleased((vgui::TextEntry *)((char *)this - 188), a2, a3);
}

void `non-virtual thunk to'vgui::TextEntry::keyFocusTicked(vgui::TextEntry *this, vgui::Panel *a2)
{
  vgui::TextEntry::keyFocusTicked((vgui::TextEntry *)((char *)this - 188), a2);
}

void vgui::TextEntry::keyFocusTicked(vgui::TextEntry *const this, vgui::Panel *panel)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx

  v2 = (*((int (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 92))(v2);
  if ( v3 > this->_cursorNextBlinkTime )
  {
    v4 = this->_cursorBlinkRate;
    this->_cursorBlink ^= 1u;
    this->_cursorNextBlinkTime = v4 + v3;
    (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
  }
}

void vgui::TextEntry::doGotoLeft(vgui::TextEntry *const this)
{
  int v1; // eax

  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 150))(this);
  v1 = 0;
  if ( this->_cursorPos - 1 >= 0 )
    v1 = this->_cursorPos - 1;
  this->_cursorPos = v1;
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void vgui::TextEntry::doGotoRight(vgui::TextEntry *const this)
{
  int v1; // edx
  int v2; // eax

  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 150))(this);
  v1 = this->_lineDar._count;
  v2 = this->_cursorPos + 1;
  this->_cursorPos = v2;
  if ( v2 > v1 )
    this->_cursorPos = v1;
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void vgui::TextEntry::doGotoFirstOfLine(vgui::TextEntry *const this)
{
  int (**v1)(...); // eax

  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 150))(this);
  v1 = this->_vptr_Panel;
  this->_cursorPos = 0;
  v1[129](this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void vgui::TextEntry::doGotoEndOfLine(vgui::TextEntry *const this)
{
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 150))(this);
  this->_cursorPos = this->_lineDar._count;
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void vgui::TextEntry::doInsertChar(vgui::TextEntry *const this, char ch_0)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int i; // esi
  int v6; // ecx
  int v7; // eax
  int (**v8)(...); // eax

  v2 = this->_lineDar._count;
  v3 = v2 + 1;
  if ( v2 + 1 >= 0 && v3 <= this->_lineDar._capacity )
  {
    this->_lineDar._count = v3;
    ++v2;
  }
  v4 = this->_cursorPos;
  for ( i = v2 - 1; v4 <= i; v4 = this->_cursorPos )
  {
    v6 = i + 1;
    v7 = 0;
    if ( i >= 0 && this->_lineDar._count > i )
      v7 = this->_lineDar._data[i];
    --i;
    (*((void (__cdecl **)(vgui::TextEntry *const, int, int))this->_vptr_Panel + 145))(this, v7, v6);
  }
  (*((void (__cdecl **)(vgui::TextEntry *const, _DWORD, int))this->_vptr_Panel + 145))(this, ch_0, v4);
  v8 = this->_vptr_Panel;
  ++this->_cursorPos;
  v8[129](this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
}

void vgui::TextEntry::doSelectNone(vgui::TextEntry *const this)
{
  this->_select[0] = -1;
  (*((void (**)(void))this->_vptr_Panel + 12))();
}

bool vgui::TextEntry::getSelectedRange(vgui::TextEntry *const this, int *const cx0, int *const cx1)
{
  bool result; // al
  int v4; // ebx
  int v5; // ecx
  int v6; // ebx

  result = 0;
  v4 = this->_select[0];
  if ( v4 != -1 )
  {
    *cx0 = v4;
    result = 1;
    v5 = this->_select[1];
    *cx1 = v5;
    v6 = *cx0;
    if ( v5 < *cx0 )
    {
      *cx0 = v5;
      *cx1 = v6;
    }
  }
  return result;
}

void vgui::TextEntry::doCopySelected(vgui::TextEntry *const this)
{
  int v1; // ecx
  int v2; // ebx
  int v3; // edx
  char v4; // al
  int (**v5)(...); // eax
  int v6; // eax
  char buf[256]; // [esp+10h] [ebp-12Ch] BYREF
  int x0[4]; // [esp+110h] [ebp-2Ch] BYREF
  int x1[7]; // [esp+120h] [ebp-1Ch] BYREF

  if ( (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int *, int *))this->_vptr_Panel + 147))(this, x0, x1) )
  {
    v1 = x1[0];
    v2 = 0;
    v3 = x0[0];
    do
    {
      if ( v3 >= v1 )
        break;
      v4 = 0;
      if ( v3 >= 0 && v3 < this->_lineDar._count )
        v4 = this->_lineDar._data[v3];
      buf[v2++] = v4;
      ++v3;
    }
    while ( v2 != 199 );
    v5 = this->_vptr_Panel;
    buf[v2] = 0;
    v6 = v5[83](this);
    (*(void (__cdecl **)(int, char *, int))(*(_DWORD *)v6 + 108))(v6, buf, v2);
  }
}

void vgui::TextEntry::doPaste(vgui::TextEntry *const this)
{
  int v1; // eax
  int v2; // eax
  int v3; // ebp
  int v4; // edi
  int v5; // edx
  char buf[256]; // [esp+10h] [ebp-11Ch] BYREF

  v1 = (*((int (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 83))(this);
  v2 = (*(int (__cdecl **)(int, _DWORD, char *, int))(*(_DWORD *)v1 + 112))(v1, 0, buf, 256);
  if ( v2 > 1 )
  {
    v3 = v2 - 1;
    v4 = 0;
    do
    {
      v5 = buf[v4++];
      (*((void (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 134))(this, v5);
    }
    while ( v4 != v3 );
  }
}

void vgui::TextEntry::doPasteSelected(vgui::TextEntry *const this)
{
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 141))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 139))(this);
}

void vgui::TextEntry::getText(vgui::TextEntry *const this, int offset, char *buf, int bufLen)
{
  int v4; // edx
  char *v5; // ecx
  char *v6; // ebx
  char v7; // al

  v4 = offset;
  if ( buf )
  {
    if ( offset < bufLen - 1 )
    {
      *buf = 0;
      if ( offset < this->_lineDar._count )
      {
        v5 = buf + 1;
        v6 = buf;
        do
        {
          v7 = 0;
          if ( v4 >= 0 )
            v7 = this->_lineDar._data[v4];
          ++v4;
          *v6 = v7;
          if ( v4 >= bufLen - 1 )
            break;
          *v5 = 0;
          v6 = v5++;
        }
        while ( this->_lineDar._count > v4 );
      }
    }
    buf[bufLen - 1] = 0;
  }
}

void vgui::TextEntry::fireActionSignal(vgui::TextEntry *const this)
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

void vgui::TextEntry::setFont(vgui::TextEntry *const this, vgui::Font *font)
{
  this->_font = font;
}

void vgui::TextEntry::selectCheck(vgui::TextEntry *const this)
{
  if ( (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 78)
    || (*((uint8_t (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 25))(this, 79) )
  {
    if ( this->_select[0] == -1 )
      this->_select[0] = this->_cursorPos;
  }
  else
  {
    this->_select[0] = -1;
  }
}

bool vgui::TextEntry::getSelectedPixelRange(vgui::TextEntry *const this, int *const cx0, int *const cx1)
{
  char v3; // al
  bool v4; // dl
  int v5; // eax

  v3 = (*((int (__cdecl **)(vgui::TextEntry *const, int *const, int *const))this->_vptr_Panel + 147))(this, cx0, cx1);
  v4 = 0;
  if ( v3 )
  {
    *cx0 = (*((int (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 149))(this, *cx0);
    v5 = (*((int (__cdecl **)(vgui::TextEntry *const, int))this->_vptr_Panel + 149))(this, *cx1);
    v4 = 1;
    *cx1 = v5;
  }
  return v4;
}

void vgui::TextEntry::doDelete(vgui::TextEntry *const this)
{
  int v1; // eax
  int v2; // ebx
  int i; // ebx
  int v4; // ecx
  int v5; // eax
  int v6; // eax

  v1 = this->_lineDar._count;
  if ( v1 )
  {
    v2 = this->_cursorPos;
    if ( v1 != v2 )
    {
      for ( i = v2 + 1; i < v1; v1 = this->_lineDar._count )
      {
        v4 = i - 1;
        v5 = 0;
        if ( i >= 0 )
          v5 = this->_lineDar._data[i];
        ++i;
        (*((void (__cdecl **)(vgui::TextEntry *const, int, int))this->_vptr_Panel + 145))(this, v5, v4);
      }
      v6 = v1 - 1;
      if ( v6 >= 0 && v6 <= this->_lineDar._capacity )
        this->_lineDar._count = v6;
      (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
      (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
    }
  }
}

void vgui::TextEntry::doBackspace(vgui::TextEntry *const this)
{
  int v1; // ebx
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int (**v6)(...); // eax

  v1 = this->_cursorPos;
  if ( v1 )
  {
    v2 = this->_lineDar._count;
    if ( v2 )
    {
      while ( v1 < v2 )
      {
        v3 = v1 - 1;
        v4 = 0;
        if ( v1 >= 0 )
          v4 = this->_lineDar._data[v1];
        ++v1;
        (*((void (__cdecl **)(vgui::TextEntry *const, int, int))this->_vptr_Panel + 145))(this, v4, v3);
        v2 = this->_lineDar._count;
      }
      v5 = v2 - 1;
      if ( v5 >= 0 && v5 <= this->_lineDar._capacity )
        this->_lineDar._count = v5;
      v6 = this->_vptr_Panel;
      --this->_cursorPos;
      v6[129](this);
      (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
    }
  }
}

void vgui::TextEntry::addActionSignal(vgui::TextEntry *const this, vgui::ActionSignal *s)
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

void vgui::TextEntry::setCharAt(vgui::TextEntry *const this, char ch_0, int index)
{
  vgui::TextEntry *v3; // edx
  vgui::Dar<char> *v4; // ebx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // edi
  _BYTE *v8; // eax
  char *v9; // ebp
  _WORD *v10; // edi
  int v11; // eax
  int v12; // ecx
  char *v13; // ecx
  unsigned int v14; // [esp+18h] [ebp-24h]

  v3 = this;
  if ( index < 0 )
    return;
  v4 = &this->_lineDar;
  v5 = this->_lineDar._capacity;
  v6 = index + 1;
  if ( index + 1 <= v5 )
  {
    if ( index >= this->_lineDar._count )
      return;
LABEL_20:
    v3->_lineDar._data[index] = ch_0;
    return;
  }
  if ( v5 || (v5 = 1, v7 = 1, v6 > 1) )
  {
    do
      v5 *= 2;
    while ( v6 > v5 );
    v7 = v5;
  }
  v8 = (_BYTE *)operator new[](v7);
  v3 = this;
  v9 = v8;
  if ( !v8 )
    exit(0);
  v14 = v7;
  v10 = v8;
  if ( v14 >= 8 )
  {
    if ( ((uint8_t)v8 & 1) != 0 )
    {
      *v8 = 0;
      v10 = v8 + 1;
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
  }
  if ( (v14 & 4) != 0 )
  {
    *(_DWORD *)v10 = 0;
    v10 += 2;
    if ( (v14 & 2) == 0 )
    {
LABEL_11:
      if ( (v14 & 1) == 0 )
        goto LABEL_12;
      goto LABEL_21;
    }
  }
  else if ( (v14 & 2) == 0 )
  {
    goto LABEL_11;
  }
  *v10++ = 0;
  if ( (v14 & 1) != 0 )
LABEL_21:
    *(_BYTE *)v10 = 0;
LABEL_12:
  v11 = this->_lineDar._count;
  this->_lineDar._capacity = v5;
  if ( v11 > 0 )
  {
    v12 = 0;
    do
    {
      v9[v12] = this->_lineDar._data[v12];
      ++v12;
      v11 = v4->_count;
    }
    while ( v12 < v4->_count );
  }
  v13 = this->_lineDar._data;
  if ( v13 )
  {
    operator delete[](v13);
    v3 = this;
    v11 = this->_lineDar._count;
  }
  v3->_lineDar._data = v9;
  if ( index < v11 )
    goto LABEL_20;
}

void vgui::TextEntry::setText(vgui::TextEntry *const this, const char *text, int textLen)
{
  vgui::TextEntry *v3; // edx
  int v4; // esi
  vgui::Dar<char> *v5; // ebx
  unsigned int v6; // edi
  _BYTE *v7; // eax
  char *v8; // ebp
  _WORD *v9; // edi
  int v10; // eax
  int v11; // ecx
  char *v12; // eax
  vgui::TextEntry *v13; // ebp
  int v14; // eax
  int v15; // esi
  int v16; // edx
  unsigned int v17; // edi
  _BYTE *v18; // eax
  char *v19; // edx
  _DWORD *v20; // edi
  int v21; // ecx
  char *v22; // ecx
  char *v23; // [esp+18h] [ebp-34h]
  unsigned int v24; // [esp+1Ch] [ebp-30h]
  int v25; // [esp+1Ch] [ebp-30h]
  unsigned int v26; // [esp+20h] [ebp-2Ch]
  char v27; // [esp+2Bh] [ebp-21h]

  v3 = this;
  this->_lineDar._count = 0;
  if ( text )
  {
    v4 = this->_lineDar._capacity;
    v5 = &this->_lineDar;
    if ( textLen > v4 )
    {
      if ( v4 || (v4 = 1, v6 = 1, textLen > 1) )
      {
        do
          v4 *= 2;
        while ( textLen > v4 );
        v6 = v4;
      }
      v7 = (_BYTE *)operator new[](v6);
      v3 = this;
      v8 = v7;
      if ( !v7 )
LABEL_60:
        exit(0);
      v24 = v6;
      v9 = v7;
      if ( v24 >= 8 )
      {
        if ( ((uint8_t)v7 & 1) != 0 )
        {
          *v7 = 0;
          v9 = v7 + 1;
          --v24;
        }
        if ( ((uint8_t)v9 & 2) != 0 )
        {
          *v9++ = 0;
          v24 -= 2;
        }
        if ( ((uint8_t)v9 & 4) != 0 )
        {
          *(_DWORD *)v9 = 0;
          v9 += 2;
          v24 -= 4;
        }
        memset(v9, 0, 4 * (v24 >> 2));
        v9 += 2 * (v24 >> 2);
        LOBYTE(v24) = v24 & 3;
      }
      if ( (v24 & 4) != 0 )
      {
        *(_DWORD *)v9 = 0;
        v9 += 2;
      }
      if ( (v24 & 2) != 0 )
        *v9++ = 0;
      if ( (v24 & 1) != 0 )
        *(_BYTE *)v9 = 0;
      v10 = this->_lineDar._count;
      this->_lineDar._capacity = v4;
      if ( v10 > 0 )
      {
        v11 = 0;
        do
        {
          v8[v11] = this->_lineDar._data[v11];
          ++v11;
        }
        while ( v11 < v5->_count );
      }
      v12 = this->_lineDar._data;
      if ( v12 )
      {
        operator delete[](v12);
        v3 = this;
      }
      v3->_lineDar._data = v8;
    }
    if ( textLen > 0 )
    {
      v13 = v3;
      v25 = 0;
      while ( 1 )
      {
        v14 = v13->_lineDar._count;
        v15 = v13->_lineDar._capacity;
        v27 = text[v25];
        v16 = v14 + 1;
        if ( v14 + 1 > v15 )
          break;
        v19 = v13->_lineDar._data;
LABEL_42:
        v19[v14] = v27;
        ++v13->_lineDar._count;
        (*((void (__cdecl **)(vgui::TextEntry *, _DWORD, int))v13->_vptr_Panel + 145))(v13, text[v25], v25);
        if ( ++v25 == textLen )
        {
          v3 = v13;
          goto LABEL_44;
        }
      }
      if ( v15 || (v15 = 1, v17 = 1, v16 > 1) )
      {
        do
          v15 *= 2;
        while ( v16 > v15 );
        v17 = v15;
      }
      v18 = (_BYTE *)operator new[](v17);
      v19 = v18;
      if ( !v18 )
        goto LABEL_60;
      v26 = v17;
      v20 = v18;
      if ( v26 < 8 )
      {
LABEL_30:
        if ( (v26 & 4) != 0 )
          *v20++ = 0;
        if ( (v26 & 2) != 0 )
        {
          *(_WORD *)v20 = 0;
          v20 = (_DWORD *)((char *)v20 + 2);
        }
        if ( (v26 & 1) != 0 )
          *(_BYTE *)v20 = 0;
        v13->_lineDar._capacity = v15;
        v14 = v5->_count;
        if ( v5->_count > 0 )
        {
          v21 = 0;
          do
          {
            v19[v21] = this->_lineDar._data[v21];
            ++v21;
            v14 = v5->_count;
          }
          while ( v21 < v5->_count );
        }
        v22 = v13->_lineDar._data;
        if ( v22 )
        {
          v23 = v19;
          operator delete[](v22);
          v14 = v13->_lineDar._count;
          v19 = v23;
        }
        v13->_lineDar._data = v19;
        goto LABEL_42;
      }
      if ( ((uint8_t)v18 & 1) != 0 )
      {
        *v18 = 0;
        v20 = v18 + 1;
        --v26;
        if ( ((unsigned int)(v18 + 1) & 2) == 0 )
        {
LABEL_48:
          if ( ((uint8_t)v20 & 4) == 0 )
          {
LABEL_49:
            memset(v20, 0, 4 * (v26 >> 2));
            v20 += v26 >> 2;
            LOBYTE(v26) = v26 & 3;
            goto LABEL_30;
          }
LABEL_59:
          *v20++ = 0;
          v26 -= 4;
          goto LABEL_49;
        }
      }
      else if ( ((uint8_t)v18 & 2) == 0 )
      {
        goto LABEL_48;
      }
      *(_WORD *)v20 = 0;
      v20 = (_DWORD *)((char *)v20 + 2);
      v26 -= 2;
      if ( ((uint8_t)v20 & 4) == 0 )
        goto LABEL_49;
      goto LABEL_59;
    }
  }
LABEL_44:
  (*((void (__cdecl **)(vgui::TextEntry *))v3->_vptr_Panel + 133))(v3);
}

void vgui::TextEntry::TextEntry(vgui::TextEntry *const this, const char *text, int x, int y, int wide, int tall)
{
  char *v6; // eax
  int v7; // ecx
  int v8; // ecx
  char *v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  vgui::ActionSignal **v13; // edx
  int (**v14)(...); // eax
  int v15; // eax
  int textLen; // eax
  vgui::FocusChangeSignal *v17; // eax
  char *v18; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_lineDar._count = 0;
  this->_lineDar._capacity = 0;
  this->_vptr_InputSignal = (int (**)(...))(&`vtable for'vgui::TextEntry + 166);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TextEntry + 2);
  this->_lineDar._data = 0;
  v6 = (char *)operator new[](4u);
  if ( !v6 )
    goto LABEL_14;
  *(_DWORD *)v6 = 0;
  v7 = this->_lineDar._count;
  this->_lineDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      v6[v8] = this->_lineDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_lineDar._count );
  }
  v9 = this->_lineDar._data;
  if ( v9 )
  {
    v18 = v6;
    operator delete[]((VFontData *const)v9);
    v6 = v18;
  }
  this->_lineDar._data = v6;
  this->_actionSignalDar._count = 0;
  this->_actionSignalDar._capacity = 0;
  this->_actionSignalDar._data = 0;
  v10 = operator new[](0x10u);
  if ( !v10 )
LABEL_14:
    exit(0);
  *(_DWORD *)v10 = 0;
  *(_DWORD *)(v10 + 4) = 0;
  *(_DWORD *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 12) = 0;
  v11 = this->_actionSignalDar._count;
  this->_actionSignalDar._capacity = 4;
  if ( v11 > 0 )
  {
    v12 = 0;
    do
    {
      *(_DWORD *)(v10 + 4 * v12) = this->_actionSignalDar._data[v12];
      ++v12;
    }
    while ( v12 < this->_actionSignalDar._count );
  }
  v13 = this->_actionSignalDar._data;
  if ( v13 )
  {
    v19 = v10;
    operator delete[]((VFontData *const)v13);
    v10 = v19;
  }
  this->_actionSignalDar._data = (vgui::ActionSignal **)v10;
  this->_font = 0;
  this->_cursorPos = 0;
  this->_cursorBlinkRate = 400;
  v14 = this->_vptr_Panel;
  this->_select[1] = -1;
  this->_select[0] = -1;
  this->_hideText = 0;
  this->_cursorBlink = 0;
  v15 = v14[83](this);
  this->_cursorNextBlinkTime = this->_cursorBlinkRate + (*(int (__cdecl **)(int))(*(_DWORD *)v15 + 92))(v15);
  textLen = strlen(text);
  vgui::TextEntry::setText(this, text, textLen);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 150))(this);
  this->_cursorPos = this->_lineDar._count;
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::TextEntry *const))this->_vptr_Panel + 12))(this);
  vgui::Panel::addInputSignal(this, &this->vgui::InputSignal);
  v17 = (vgui::FocusChangeSignal *)operator new(8u);
  v17->_vptr_FocusChangeSignal = (int (**)(...))&off_48B58;
  v17[1]._vptr_FocusChangeSignal = (int (**)(...))this;
  vgui::Panel::addFocusChangeSignal(this, v17);
}

