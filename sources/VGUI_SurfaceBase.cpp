#include <VGUI_SurfaceBase.h>

void vgui::SurfaceBase::requestSwap(vgui::SurfaceBase *const this)
{
  this->_needsSwap = 1;
}

void vgui::SurfaceBase::resetModeInfo(vgui::SurfaceBase *const this)
{
  this->_modeInfoDar._count = 0;
}

int vgui::SurfaceBase::getModeInfoCount(vgui::SurfaceBase *const this)
{
  return this->_modeInfoDar._count;
}

void vgui::SurfaceBase::setEmulatedCursorVisible(vgui::SurfaceBase *const this, bool state)
{
  (*((void (__cdecl **)(vgui::ImagePanel *, bool))this->_emulatedCursor->_vptr_Panel + 9))(this->_emulatedCursor, state);
}

void vgui::SurfaceBase::setEmulatedCursorPos(vgui::SurfaceBase *const this, int x, int y)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int hx; // [esp+18h] [ebp-14h] BYREF
  int hy[4]; // [esp+1Ch] [ebp-10h] BYREF

  v4 = (*this->_vptr_SurfaceBase)(this);
  (*(void (__cdecl **)(int, vgui::ImagePanel *))(*(_DWORD *)v4 + 76))(v4, this->_emulatedCursor);
  v5 = (*this->_vptr_SurfaceBase)(this);
  (*(void (__cdecl **)(int, vgui::ImagePanel *))(*(_DWORD *)v5 + 68))(v5, this->_emulatedCursor);
  v6 = (*this->_vptr_SurfaceBase)(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v6 + 140))(v6, &x, &y);
  if ( this->_currentCursor
    && !(*((uint8_t (__cdecl **)(vgui::ImagePanel *))this->_emulatedCursor->_vptr_Panel + 10))(this->_emulatedCursor) )
  {
    (*this->_currentCursor->_vptr_Cursor)(this->_currentCursor, &hx, hy);
    v8 = x - hx;
    x -= hx;
    v7 = y - hy[0];
    y -= hy[0];
  }
  else
  {
    v7 = y;
    v8 = x;
  }
  (*this->_emulatedCursor->_vptr_Panel)(this->_emulatedCursor, v8, v7);
}

bool vgui::SurfaceBase::getModeInfo(vgui::SurfaceBase *const this, int index, int *const wide, int *const tall, int *const bpp)
{
  bool result; // al

  result = 0;
  if ( index >= 0 && index < this->_modeInfoDar._count )
  {
    sscanf(this->_modeInfoDar._data[index], "%dx%dx%d", wide, tall, bpp);
    result = 1;
  }
  return result;
}

void vgui::SurfaceBase::addModeInfo(vgui::SurfaceBase *const this, int wide, int tall, int bpp)
{
  vgui::Dar<char*> *v4; // ebx
  char *v5; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  char **v9; // edx
  unsigned int v10; // edi
  _BYTE *v11; // eax
  _WORD *v12; // edi
  int v13; // eax
  char **v14; // eax
  char **v15; // [esp+24h] [ebp-128h]
  unsigned int v16; // [esp+28h] [ebp-124h]
  char *buf2; // [esp+2Ch] [ebp-120h]
  char buf[256]; // [esp+30h] [ebp-11Ch] BYREF

  sprintf(buf, "%dx%dx%d", wide, tall, bpp);
  v4 = &this->_modeInfoDar;
  v5 = strdup(buf);
  v6 = this->_modeInfoDar._count;
  v7 = this->_modeInfoDar._capacity;
  buf2 = v5;
  v8 = v6 + 1;
  if ( v6 + 1 <= v7 )
  {
    v9 = this->_modeInfoDar._data;
    goto LABEL_3;
  }
  if ( v7 || (v7 = 1, v10 = 4, v8 > 1) )
  {
    do
      v7 *= 2;
    while ( v8 > v7 );
    v10 = 4 * v7;
  }
  v11 = (_BYTE *)operator new[](v10);
  v9 = (char **)v11;
  if ( !v11 )
    exit(0);
  v16 = v10;
  v12 = v11;
  if ( v16 >= 8 )
  {
    if ( ((uint8_t)v11 & 1) != 0 )
    {
      *v11 = 0;
      v12 = v11 + 1;
      --v16;
    }
    if ( ((uint8_t)v12 & 2) != 0 )
    {
      *v12++ = 0;
      v16 -= 2;
    }
    if ( ((uint8_t)v12 & 4) != 0 )
    {
      *(_DWORD *)v12 = 0;
      v12 += 2;
      v16 -= 4;
    }
    memset(v12, 0, 4 * (v16 >> 2));
    v12 += 2 * (v16 >> 2);
    LOBYTE(v16) = v16 & 3;
  }
  if ( (v16 & 4) == 0 )
  {
    if ( (v16 & 2) == 0 )
      goto LABEL_12;
LABEL_20:
    *v12++ = 0;
    if ( (v16 & 1) == 0 )
      goto LABEL_13;
    goto LABEL_19;
  }
  *(_DWORD *)v12 = 0;
  v12 += 2;
  if ( (v16 & 2) != 0 )
    goto LABEL_20;
LABEL_12:
  if ( (v16 & 1) != 0 )
LABEL_19:
    *(_BYTE *)v12 = 0;
LABEL_13:
  v6 = this->_modeInfoDar._count;
  this->_modeInfoDar._capacity = v7;
  if ( v6 > 0 )
  {
    v13 = 0;
    do
    {
      v9[v13] = this->_modeInfoDar._data[v13];
      ++v13;
      v6 = v4->_count;
    }
    while ( v13 < v4->_count );
  }
  v14 = this->_modeInfoDar._data;
  if ( v14 )
  {
    v15 = v9;
    operator delete[](v14);
    v6 = this->_modeInfoDar._count;
    v9 = v15;
  }
  this->_modeInfoDar._data = v9;
LABEL_3:
  v9[v6] = buf2;
  ++this->_modeInfoDar._count;
}

void vgui::SurfaceBase::SurfaceBase(vgui::SurfaceBase *const this, vgui::Panel *embeddedPanel)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  char **v5; // edx
  vgui::ImagePanel *v6; // esi
  vgui::Panel *v7; // eax
  vgui::App *v8; // eax
  int v9; // [esp+1Ch] [ebp-10h]

  this->_vptr_SurfaceBase = (int (**)(...))(&`vtable for'vgui::SurfaceBase + 2);
  this->_modeInfoDar._count = 0;
  this->_modeInfoDar._capacity = 0;
  this->_modeInfoDar._data = 0;
  v2 = operator new[](0x10u);
  if ( !v2 )
    exit(0);
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  v3 = this->_modeInfoDar._count;
  this->_modeInfoDar._capacity = 4;
  if ( v3 > 0 )
  {
    v4 = 0;
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = this->_modeInfoDar._data[v4];
      ++v4;
    }
    while ( v4 < this->_modeInfoDar._count );
  }
  v5 = this->_modeInfoDar._data;
  if ( v5 )
  {
    v9 = v2;
    operator delete[]((VFontData *const)v5);
    v2 = v9;
  }
  this->_embeddedPanel = embeddedPanel;
  this->_modeInfoDar._data = (char **)v2;
  this->_needsSwap = 1;
  v6 = (vgui::ImagePanel *)operator new(0xC0u);
  vgui::ImagePanel::ImagePanel(v6, 0);
  v6->_vptr_Panel = (int (**)(...))&off_477C8;
  this->_emulatedCursor = v6;
  (*((void (__cdecl **)(vgui::ImagePanel *, _DWORD))v6->_vptr_Panel + 9))(v6, 0);
  v7 = this->_embeddedPanel;
  this->_currentCursor = 0;
  (*((void (__cdecl **)(vgui::Panel *, vgui::SurfaceBase *const))v7->_vptr_Panel + 90))(v7, this);
  v8 = vgui::App::getInstance();
  (*((void (__cdecl **)(vgui::App *, vgui::SurfaceBase *const))v8->_vptr_App + 51))(v8, this);
  (*((void (__cdecl **)(vgui::ImagePanel *, vgui::Panel *))this->_emulatedCursor->_vptr_Panel + 16))(
    this->_emulatedCursor,
    this->_embeddedPanel);
}

void vgui::SurfaceBase::~SurfaceBase(vgui::SurfaceBase *const this)
{
  vgui::App *v1; // eax

  this->_vptr_SurfaceBase = (int (**)(...))(&`vtable for'vgui::SurfaceBase + 2);
  v1 = vgui::App::getInstance();
  (*((void (__cdecl **)(vgui::App *, vgui::SurfaceBase *const))v1->_vptr_App + 52))(v1, this);
}

