#include <VGUI_Surface.h>

void vgui::Surface::Surface(vgui::Surface *const this, vgui::Panel *embeddedPanel)
{
  char **v2; // eax
  char **v3; // esi
  int v4; // eax
  int v5; // edx

  vgui::SurfaceBase::SurfaceBase(this, embeddedPanel);
  this->_vptr_SurfaceBase = (int (**)(...))(&`vtable for'vgui::Surface + 2);
  this->_modeInfoDar._count = 0;
  this->_modeInfoDar._capacity = 0;
  this->_modeInfoDar._data = 0;
  v2 = (char **)operator new[](0x10u);
  v3 = v2;
  if ( !v2 )
    exit(0);
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v4 = this->_modeInfoDar._count;
  this->_modeInfoDar._capacity = 4;
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      v3[v5] = this->_modeInfoDar._data[v5];
      ++v5;
    }
    while ( v5 < this->_modeInfoDar._count );
  }
  if ( this->_modeInfoDar._data )
    operator delete[]((VFontData *const)this->_modeInfoDar._data);
  this->_modeInfoDar._data = v3;
  vgui::Surface::createPlat(this);
  vgui::Surface::recreateContext(this);
}

void vgui::Surface::createPopup(vgui::Surface *const this, vgui::Panel *embeddedPanel)
{
  vgui::Surface *v2; // eax

  (*((void (__cdecl **)(vgui::Panel *, _DWORD))embeddedPanel->_vptr_Panel + 16))(embeddedPanel, 0);
  v2 = (vgui::Surface *)operator new(0x3Cu);
  vgui::Surface::Surface(v2, embeddedPanel);
}

bool vgui::Surface::createPlat(vgui::Surface *const this)
{
  return 1;
}

bool vgui::Surface::recreateContext(vgui::Surface *const this)
{
  int v1; // eax
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  v1 = (*this->_vptr_SurfaceBase)(this);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v1 + 12))(v1, &wide, tall);
  return 1;
}

void vgui::Surface::drawOutlinedRect(vgui::Surface *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int, int))this->_vptr_SurfaceBase + 19))(
    this,
    x0,
    y0,
    x1,
    y0 + 1);
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int, int))this->_vptr_SurfaceBase + 19))(
    this,
    x0,
    y1 - 1,
    x1,
    y1);
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int, int))this->_vptr_SurfaceBase + 19))(
    this,
    x0,
    y0 + 1,
    x0 + 1,
    y1 - 1);
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int, int))this->_vptr_SurfaceBase + 19))(
    this,
    x1 - 1,
    y0 + 1,
    x1,
    y1 - 1);
}

int vgui::Surface::createNewTextureID(vgui::Surface *const this)
{
  return vgui::Surface::createNewTextureID(void)::staticBindIndex++;
}

void vgui::Surface::drawSetTexture(vgui::Surface *const this, int id)
{
  `anonymous namespace'::Texture *v2; // eax

  v2 = staticTextureCurrent;
  if ( staticTextureCurrent && id == staticTextureCurrent->_id || (v2 = 0, staticTextureCount <= 0) )
  {
LABEL_9:
    staticTextureCurrent = v2;
    return;
  }
  if ( id != staticTexture[0]._id )
  {
    while ( 1 )
    {
      v2 = (`anonymous namespace'::Texture *)((char *)v2 + 1);
      if ( v2 == (`anonymous namespace'::Texture *)staticTextureCount )
        break;
      if ( id == staticTexture[(_DWORD)v2]._id )
        goto LABEL_10;
    }
    v2 = 0;
    goto LABEL_9;
  }
  v2 = 0;
LABEL_10:
  staticTextureCurrent = &staticTexture[(_DWORD)v2];
}

void vgui::Surface::pushMakeCurrent(vgui::Surface *const this, vgui::Panel *panel, bool useInsets)
{
  int v3; // eax
  int inset[4]; // [esp+20h] [ebp-4Ch] BYREF
  int absThis[4]; // [esp+30h] [ebp-3Ch] BYREF
  int absPanel[4]; // [esp+40h] [ebp-2Ch] BYREF
  int clipRect[4]; // [esp+50h] [ebp-1Ch] BYREF

  (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))panel->_vptr_Panel + 57))(
    panel,
    inset,
    &inset[1],
    &inset[2],
    &inset[3]);
  if ( !useInsets )
    *(_OWORD *)inset = 0LL;
  v3 = (*this->_vptr_SurfaceBase)(this);
  (*(void (__cdecl **)(int, int *, int *, int *, int *))(*(_DWORD *)v3 + 56))(
    v3,
    absThis,
    &absThis[1],
    &absThis[2],
    &absThis[3]);
  (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))panel->_vptr_Panel + 14))(
    panel,
    absPanel,
    &absPanel[1],
    &absPanel[2],
    &absPanel[3]);
  (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))panel->_vptr_Panel + 15))(
    panel,
    clipRect,
    &clipRect[1],
    &clipRect[2],
    &clipRect[3]);
}

void vgui::Surface::drawSetTextFont(vgui::Surface *const this, vgui::Font *font)
{
  if ( font )
    (*((void (__cdecl **)(vgui::BaseFontPlat *, vgui::SurfacePlat *))font->_plat->_vptr_BaseFontPlat + 7))(
      font->_plat,
      this->_plat);
}

bool vgui::Surface::hasFocus(vgui::Surface *const this)
{
  return 1;
}

int vgui::Surface::getModeInfoCount(vgui::Surface *const this)
{
  (*((void (__cdecl **)(vgui::Surface *const))this->_vptr_SurfaceBase + 2))(this);
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int))this->_vptr_SurfaceBase + 17))(this, 640, 480, 16);
  (*((void (__cdecl **)(vgui::Surface *const, int, int, int))this->_vptr_SurfaceBase + 17))(this, 800, 600, 16);
  return vgui::SurfaceBase::getModeInfoCount(this);
}

void vgui::Surface::drawSetTextureRGBA(vgui::Surface *const this, int id, const char *rgba, int wide, int tall)
{
  int v5; // eax
  int v6; // ebx

  if ( !staticTextureCurrent || id != staticTextureCurrent->_id )
  {
    if ( staticTextureCount <= 0 )
      goto LABEL_9;
    v5 = 0;
    if ( id != staticTexture[0]._id )
    {
      while ( ++v5 != staticTextureCount )
      {
        if ( id == staticTexture[v5]._id )
          return;
      }
      if ( staticTextureCount <= 127 )
      {
LABEL_9:
        v6 = staticTextureCount++;
        staticTexture[v6]._id = id;
      }
    }
  }
}

void vgui::Surface::setCursor(vgui::Surface *const this, vgui::Cursor *cursor)
{
  vgui::ImagePanel *v2; // eax
  void (__cdecl *v3)(vgui::ImagePanel *, int); // edi
  int v4; // eax

  this->_currentCursor = cursor;
  v2 = this->_emulatedCursor;
  if ( cursor )
  {
    v3 = (void (__cdecl *)(vgui::ImagePanel *, int))*((_DWORD *)v2->_vptr_Panel + 127);
    v4 = (*((int (__cdecl **)(vgui::Cursor *))cursor->_vptr_Cursor + 2))(cursor);
    v3(this->_emulatedCursor, v4);
    (*((void (__cdecl **)(vgui::Cursor *))cursor->_vptr_Cursor + 3))(cursor);
  }
  else
  {
    (*((void (__cdecl **)(vgui::ImagePanel *, _DWORD))v2->_vptr_Panel + 127))(v2, 0);
  }
}

bool vgui::Surface::setFullscreenMode(vgui::Surface *const this, int wide, int tall, int bpp)
{
  vgui::SurfacePlat *v4; // edx
  bool v5; // bl

  v4 = this->_plat;
  if ( !v4->isFullscreen
    || v4->fullscreenInfo[0] != wide
    || v4->fullscreenInfo[1] != tall
    || (v5 = 1, v4->fullscreenInfo[2] != bpp) )
  {
    v5 = 0;
    if ( !this->_modeInfoDar._count )
      (*((void (__cdecl **)(vgui::Surface *const))this->_vptr_SurfaceBase + 3))(this);
  }
  return v5;
}

