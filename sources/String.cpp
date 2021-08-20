#include <VGUI_String.h>

void vgui::String::String(vgui::String *const this)
{
  this->_text = (char *)"";
}

void vgui::String::String(vgui::String *const this, const char *text)
{
  const char *v2; // esi
  int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // eax
  char *v6; // eax
  unsigned int v7; // edx
  _WORD *v8; // edi
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // eax
  __int16 v12; // ax

  v2 = text;
  if ( *text )
  {
    v3 = 0;
    do
      v4 = ++v3;
    while ( text[v3] );
    v5 = v3 + 1;
  }
  else
  {
    v5 = 1;
    v4 = 0;
  }
  v6 = (char *)operator new[](v5);
  v7 = v4;
  this->_text = v6;
  v8 = v6;
  if ( v4 >= 8 )
  {
    if ( ((uint8_t)v6 & 1) != 0 )
    {
      v7 = v4 - 1;
      v2 = text + 1;
      *v6 = *text;
      v8 = v6 + 1;
    }
    if ( ((uint8_t)v8 & 2) != 0 )
    {
      v12 = *(_WORD *)v2;
      v7 -= 2;
      v2 += 2;
      *v8++ = v12;
    }
    if ( ((uint8_t)v8 & 4) != 0 )
    {
      v11 = *(_DWORD *)v2;
      v7 -= 4;
      v2 += 4;
      *(_DWORD *)v8 = v11;
      v8 += 2;
    }
    v10 = v7;
    LOBYTE(v7) = v7 & 3;
    v10 >>= 2;
    qmemcpy(v8, v2, 4 * v10);
    v2 += 4 * v10;
    v8 += 2 * v10;
  }
  v9 = 0;
  if ( (v7 & 4) != 0 )
  {
    v9 = 2;
    *(_DWORD *)v8 = *(_DWORD *)v2;
  }
  if ( (v7 & 2) != 0 )
  {
    v8[v9] = *(_WORD *)&v2[v9 * 2];
    ++v9;
  }
  if ( (v7 & 1) != 0 )
    LOBYTE(v8[v9]) = v2[v9 * 2];
  this->_text[v4] = 0;
}

void vgui::String::String(vgui::String *const this, const vgui::String *const src)
{
  this->_text = src->_text;
}

void vgui::String::~String(vgui::String *const this)
{
  this->_text = 0;
}

int vgui::String::getCount(vgui::String *const this, const char *text)
{
  int result; // eax

  result = 0;
  if ( *text )
  {
    do
      ++result;
    while ( text[result] );
  }
  return result;
}

int vgui::String::getCount(vgui::String *const this)
{
  int result; // eax

  result = 0;
  if ( *this->_text )
  {
    do
      ++result;
    while ( this->_text[result] );
  }
  return result;
}

bool vgui::String::operator==(vgui::String *const this, vgui::String *p_text)
{
  bool result; // al
  char v3; // dl
  int v4; // edx
  char v5; // al

  result = 0;
  v3 = *this->_text;
  if ( v3 == *p_text->_text )
  {
    result = 1;
    if ( v3 )
    {
      v4 = 0;
      do
      {
        v5 = this->_text[++v4];
        if ( v5 != p_text->_text[v4] )
          return 0;
      }
      while ( v5 );
      result = 1;
    }
  }
  return result;
}

bool vgui::String::operator==(vgui::String *const this, const char *text)
{
  bool result; // al
  char v3; // dl
  int v4; // edx
  char v5; // al

  result = 0;
  v3 = *this->_text;
  if ( v3 == *text )
  {
    result = 1;
    if ( v3 )
    {
      v4 = 0;
      do
      {
        v5 = this->_text[++v4];
        if ( v5 != text[v4] )
          return 0;
      }
      while ( v5 );
      result = 1;
    }
  }
  return result;
}

char vgui::String::operator[](vgui::String *const this, int index)
{
  return this->_text[index];
}

const char *__cdecl vgui::String::getChars(vgui::String *const this)
{
  return this->_text;
}

