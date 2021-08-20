#include <VGUI_Font.h>

void vgui::Font::getTextSize(vgui::Font *const this, const char *text, int *const wide, int *const tall)
{
  const char *v4; // ebx
  char v5; // al
  int v6; // edx
  int v7; // eax
  int v8; // [esp+28h] [ebp-34h]
  int v9; // [esp+2Ch] [ebp-30h]
  int a; // [esp+34h] [ebp-28h] BYREF
  int b; // [esp+38h] [ebp-24h] BYREF
  int c[8]; // [esp+3Ch] [ebp-20h] BYREF

  v4 = text;
  *wide = 0;
  *tall = 0;
  if ( text )
  {
    *tall = (*((int (__cdecl **)(vgui::Font *const))this->_vptr_Font + 4))(this);
    v5 = *text;
    if ( *text )
    {
      v6 = 0;
      do
      {
        while ( v5 == 10 )
        {
          ++v4;
          v9 = *tall;
          v7 = (*((int (__cdecl **)(vgui::Font *const))this->_vptr_Font + 4))(this);
          v6 = 0;
          *tall = v9 + v7;
          v5 = *v4;
          if ( !*v4 )
            return;
        }
        v8 = v6;
        (*((void (__cdecl **)(vgui::Font *const, _DWORD, int *, int *, int *))this->_vptr_Font + 2))(
          this,
          v5,
          &a,
          &b,
          c);
        v6 = c[0] + b + a + v8;
        if ( v6 > *wide )
          *wide = v6;
        v5 = *++v4;
      }
      while ( *v4 );
    }
  }
}

int vgui::Font::getId(vgui::Font *const this)
{
  return this->_id;
}

int vgui::Font::getWide(vgui::Font *const this)
{
  return (*((int (__cdecl **)(vgui::BaseFontPlat *))this->_plat->_vptr_BaseFontPlat + 6))(this->_plat);
}

void vgui::Font::getCharRGBA(vgui::Font *const this, int ch, int rgbaX, int rgbaY, int rgbaWide, int rgbaTall, uchar *rgba)
{
  (*((void (__cdecl **)(vgui::BaseFontPlat *))this->_plat->_vptr_BaseFontPlat + 3))(this->_plat);
}

void vgui::Font::getCharABCwide(vgui::Font *const this, int ch, int *const a, int *const b, int *const c)
{
  (*((void (__cdecl **)(vgui::BaseFontPlat *))this->_plat->_vptr_BaseFontPlat + 4))(this->_plat);
}

int vgui::Font::getTall(vgui::Font *const this)
{
  return (*((int (__cdecl **)(vgui::BaseFontPlat *))this->_plat->_vptr_BaseFontPlat + 5))(this->_plat);
}

void vgui::Font::init(vgui::Font *const this, const char *name, void *pFileData, int fileDataLen, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
  char *v12; // eax
  char *v13; // eax
  VFontData *pData; // ebp
  vgui::BaseFontPlat *v15; // esi
  int v16; // eax
  int v17; // ebx
  vgui::BaseFontPlat *v18; // eax
  vgui::FontPlat *v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // eax
  vgui::BaseFontPlat **v23; // esi
  size_t v24; // eax
  char *v25; // eax
  int v26; // ebx
  int v27; // edx
  vgui::BaseFontPlat **v28; // ebp
  int v29; // eax
  int v30; // eax
  unsigned int v31; // edi
  _BYTE *v32; // eax
  unsigned int v33; // edx
  _WORD *v34; // edi
  int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // ebp
  _BYTE *v38; // eax
  _WORD *v39; // edi
  int v40; // eax
  unsigned int v41; // ecx
  vgui::FontPlat *v42; // [esp+30h] [ebp-4Ch]
  FileImageStream_Memory memStream; // [esp+4Ch] [ebp-30h] BYREF

  v12 = strdup(name);
  this->_id = -1;
  this->_name = v12;
  if ( pFileData )
  {
    FileImageStream_Memory::FileImageStream_Memory(&memStream, pFileData, fileDataLen);
    v13 = (char *)operator new(0x414u);
    pData = (VFontData *)(v13 + 4);
    v15 = (vgui::BaseFontPlat *)v13;
    *(_DWORD *)v13 = &`vtable for'vgui::FontPlat_Bitmap + 2;
    VFontData::VFontData((VFontData *const)(v13 + 4));
    v15[260]._vptr_BaseFontPlat = 0;
    if ( LoadVFontDataFrom32BitTGA(&memStream, pData) )
    {
      v24 = strlen(name);
      v25 = (char *)operator new[](v24 + 1);
      v15[260]._vptr_BaseFontPlat = (int (**)(...))v25;
      if ( v25 )
      {
        strcpy(v25, name);
        v26 = staticFontPlatDar._capacity;
        this->_plat = v15;
        v27 = staticFontPlatDar._count;
        v28 = staticFontPlatDar._data;
        v29 = staticFontPlatDar._count + 1;
        if ( staticFontPlatDar._count + 1 <= v26 )
        {
LABEL_17:
          v28[v27] = v15;
          goto LABEL_18;
        }
        if ( v26 || (v26 = 1, v31 = 4, v29 > 1) )
        {
          do
            v26 *= 2;
          while ( v29 > v26 );
          v31 = 4 * v26;
        }
        v32 = (_BYTE *)operator new[](v31);
        v28 = (vgui::BaseFontPlat **)v32;
        if ( v32 )
        {
          v33 = v31;
          v34 = v32;
          if ( v33 >= 8 )
          {
            if ( ((uint8_t)v32 & 1) != 0 )
            {
              *v32 = 0;
              v34 = v32 + 1;
              --v33;
            }
            if ( ((uint8_t)v34 & 2) != 0 )
            {
              *v34 = 0;
              v33 -= 2;
              ++v34;
            }
            if ( ((uint8_t)v34 & 4) != 0 )
            {
              *(_DWORD *)v34 = 0;
              v33 -= 4;
              v34 += 2;
            }
            v36 = v33 >> 2;
            LOBYTE(v33) = v33 & 3;
            memset(v34, 0, 4 * v36);
            v34 += 2 * v36;
          }
          if ( (v33 & 4) != 0 )
          {
            *(_DWORD *)v34 = 0;
            v34 += 2;
          }
          if ( (v33 & 2) != 0 )
            *v34++ = 0;
          if ( (v33 & 1) != 0 )
            *(_BYTE *)v34 = 0;
          v27 = staticFontPlatDar._count;
          staticFontPlatDar._capacity = v26;
          if ( staticFontPlatDar._count > 0 )
          {
            v35 = 0;
            do
            {
              v28[v35] = staticFontPlatDar._data[v35];
              ++v35;
              v27 = staticFontPlatDar._count;
            }
            while ( v35 < staticFontPlatDar._count );
          }
          if ( staticFontPlatDar._data )
          {
            operator delete[]((VFontData *const)staticFontPlatDar._data);
            v27 = staticFontPlatDar._count;
          }
          staticFontPlatDar._data = v28;
          goto LABEL_17;
        }
LABEL_70:
        exit(0);
      }
    }
    (*((void (__cdecl **)(vgui::BaseFontPlat *))v15->_vptr_BaseFontPlat + 1))(v15);
  }
  else
  {
    v16 = staticFontPlatDar._count;
    v17 = 0;
    this->_plat = 0;
    if ( v16 <= 0 )
      goto LABEL_13;
    while ( !(*((uint8_t (__cdecl **)(vgui::BaseFontPlat *, const char *, int, int, _DWORD, int, bool, bool, bool, bool))staticFontPlatDar._data[v17]->_vptr_BaseFontPlat
              + 2))(
               staticFontPlatDar._data[v17],
               name,
               tall,
               wide,
               LODWORD(rotation),
               weight,
               italic,
               underline,
               strikeout,
               symbol) )
    {
      if ( ++v17 >= staticFontPlatDar._count )
      {
        v18 = this->_plat;
        goto LABEL_12;
      }
    }
    v18 = 0;
    if ( staticFontPlatDar._count > v17 )
      v18 = staticFontPlatDar._data[v17];
    this->_plat = v18;
LABEL_12:
    if ( !v18 )
    {
LABEL_13:
      v42 = (vgui::FontPlat *)operator new(0x48Cu);
      vgui::FontPlat::FontPlat(v42, name, tall, wide, rotation, weight, italic, underline, strikeout, symbol);
      v19 = v42;
      v20 = staticFontPlatDar._count;
      v21 = staticFontPlatDar._capacity;
      this->_plat = v42;
      v22 = v20 + 1;
      v23 = staticFontPlatDar._data;
      if ( v20 + 1 > v21 )
      {
        if ( v21 || (v21 = 1, v37 = 4, v22 > 1) )
        {
          do
            v21 *= 2;
          while ( v22 > v21 );
          v37 = 4 * v21;
        }
        v38 = (_BYTE *)operator new[](v37);
        v19 = v42;
        v23 = (vgui::BaseFontPlat **)v38;
        if ( !v38 )
          goto LABEL_70;
        v39 = v38;
        if ( v37 >= 8 )
        {
          if ( ((uint8_t)v38 & 1) != 0 )
          {
            *v38 = 0;
            v39 = v38 + 1;
            --v37;
          }
          if ( ((uint8_t)v39 & 2) != 0 )
          {
            *v39 = 0;
            v37 -= 2;
            ++v39;
          }
          if ( ((uint8_t)v39 & 4) != 0 )
          {
            *(_DWORD *)v39 = 0;
            v37 -= 4;
            v39 += 2;
          }
          v41 = v37 >> 2;
          LOBYTE(v37) = v37 & 3;
          memset(v39, 0, 4 * v41);
          v39 += 2 * v41;
        }
        if ( (v37 & 4) != 0 )
        {
          *(_DWORD *)v39 = 0;
          v39 += 2;
        }
        if ( (v37 & 2) != 0 )
          *v39++ = 0;
        if ( (v37 & 1) != 0 )
          *(_BYTE *)v39 = 0;
        v20 = staticFontPlatDar._count;
        staticFontPlatDar._capacity = v21;
        if ( staticFontPlatDar._count > 0 )
        {
          v40 = 0;
          do
          {
            v23[v40] = staticFontPlatDar._data[v40];
            ++v40;
            v20 = staticFontPlatDar._count;
          }
          while ( v40 < staticFontPlatDar._count );
        }
        if ( staticFontPlatDar._data )
        {
          operator delete[]((VFontData *const)staticFontPlatDar._data);
          v20 = staticFontPlatDar._count;
          v19 = v42;
        }
        staticFontPlatDar._data = v23;
      }
      v23[v20] = v19;
LABEL_18:
      v30 = staticFontId;
      ++staticFontPlatDar._count;
      this->_id = staticFontId;
      staticFontId = v30 + 1;
      return;
    }
  }
}

void vgui::Font::Font(vgui::Font *const this, const char *name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
  this->_vptr_Font = (int (**)(...))(&`vtable for'vgui::Font + 2);
  vgui::Font::init(this, name, 0, 0, tall, wide, rotation, weight, italic, underline, strikeout, symbol);
}

void vgui::Font::Font(vgui::Font *const this, const char *name, void *pFileData, int fileDataLen, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
  this->_vptr_Font = (int (**)(...))(&`vtable for'vgui::Font + 2);
  vgui::Font::init(
    this,
    name,
    pFileData,
    fileDataLen,
    tall,
    wide,
    rotation,
    weight,
    italic,
    underline,
    strikeout,
    symbol);
}

