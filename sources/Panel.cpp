#include <VGUI_Panel.h>

void vgui::Panel::setPos(vgui::Panel *const this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

void vgui::Panel::getPos(vgui::Panel *const this, int *const x, int *const y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

void vgui::Panel::setSize(vgui::Panel *const this, int wide, int tall)
{
  int v3; // ebx
  int v4; // edx

  v3 = tall;
  if ( tall < this->_minimumSize[1] )
    v3 = this->_minimumSize[1];
  v4 = this->_minimumSize[0];
  this->_size[1] = v3;
  if ( wide >= v4 )
    v4 = wide;
  this->_size[0] = v4;
}

void vgui::Panel::getSize(vgui::Panel *const this, int *const wide, int *const tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

void vgui::Panel::setBounds(vgui::Panel *const this, int x, int y, int wide, int tall)
{
  (*this->_vptr_Panel)(this, x, y);
  (*((void (__cdecl **)(vgui::Panel *const, int, int))this->_vptr_Panel + 2))(this, wide, tall);
}

void vgui::Panel::getBounds(vgui::Panel *const this, int *const x, int *const y, int *const wide, int *const tall)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

void vgui::Panel::setVisible(vgui::Panel *const this, bool state)
{
  this->_visible = state;
}

bool vgui::Panel::isVisible(vgui::Panel *const this)
{
  return this->_visible;
}

bool vgui::Panel::isVisibleUp(vgui::Panel *const this)
{
  bool result; // al
  vgui::Panel *v2; // eax

  result = 1;
  if ( this )
  {
    result = 0;
    if ( this->_visible )
    {
      v2 = this;
      do
      {
        v2 = (vgui::Panel *)(*((int (__cdecl **)(vgui::Panel *))v2->_vptr_Panel + 8))(v2);
        if ( !v2 )
          return 1;
      }
      while ( v2->_visible );
      result = 0;
    }
  }
  return result;
}

void vgui::Panel::repaint(vgui::Panel *const this)
{
  vgui::SurfaceBase *v1; // eax
  int v2; // ebx
  vgui::RepaintSignal *v3; // eax

  v1 = this->_surfaceBase;
  this->_needsRepaint = 1;
  if ( v1 )
  {
    v1->_needsSwap = 1;
    (*((void (__cdecl **)(vgui::SurfaceBase *, vgui::Panel *const))this->_surfaceBase->_vptr_SurfaceBase + 28))(
      this->_surfaceBase,
      this);
  }
  if ( this->_repaintSignalDar._count > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->_repaintSignalDar._data[v2++];
      (*v3->_vptr_RepaintSignal)(v3, this);
    }
    while ( this->_repaintSignalDar._count > v2 );
  }
}

void vgui::Panel::repaintAll(vgui::Panel *const this)
{
  int v1; // eax

  v1 = (*this->_surfaceBase->_vptr_SurfaceBase)(this->_surfaceBase);
  (*(void (__cdecl **)(int))(*(_DWORD *)v1 + 48))(v1);
}

void vgui::Panel::solve(vgui::Panel *const this)
{
  vgui::Panel *v1; // eax
  int v2; // ecx
  int v3; // edx
  vgui::Panel *v4; // ecx
  int v5; // esi
  int v6; // edi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // edi
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // edi
  int pinset[4]; // [esp+20h] [ebp-2Ch] BYREF

  v1 = this->_parent;
  v2 = this->_pos[0];
  v3 = this->_pos[1];
  this->_loc[0] = v2;
  this->_loc[1] = v3;
  if ( v1 )
  {
    (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))v1->_vptr_Panel + 57))(
      v1,
      pinset,
      &pinset[1],
      &pinset[2],
      &pinset[3]);
    v4 = this->_parent;
    v5 = pinset[1];
    v6 = this->_loc[1];
    v7 = this->_loc[0] + pinset[0] + v4->_loc[0];
    this->_loc[0] = v7;
    v8 = v4->_loc[1];
    this->_clipRect[0] = v7;
    v9 = v5 + v8;
    v10 = this->_size[1];
    v11 = v6 + v9;
    v12 = this->_size[0];
    this->_loc[1] = v11;
    this->_clipRect[1] = v11;
    v13 = v11 + v10;
    v14 = v7 + v12;
    this->_clipRect[2] = v14;
    this->_clipRect[3] = v13;
    if ( v4 )
    {
      v15 = v4->_clipRect[0];
      if ( v7 < v15 )
        this->_clipRect[0] = v15;
      v16 = v4->_clipRect[1];
      if ( v11 < v16 )
        this->_clipRect[1] = v16;
      v17 = v4->_clipRect[2];
      if ( v14 > v17 )
        this->_clipRect[2] = v17;
      v18 = v4->_clipRect[3];
      if ( v13 > v18 )
        this->_clipRect[3] = v18;
    }
  }
  else
  {
    v19 = this->_size[0];
    v20 = this->_size[1];
    this->_clipRect[0] = v2;
    this->_clipRect[1] = v3;
    this->_clipRect[2] = v19 + v2;
    this->_clipRect[3] = v20 + v3;
  }
}

void vgui::Panel::paintTraverse(vgui::Panel *const this)
{
  (*((void (__cdecl **)(vgui::Panel *const, bool))this->_vptr_Panel + 110))(this, this->_needsRepaint);
}

void vgui::Panel::paintBackground(vgui::Panel *const this)
{
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall; // [esp+2Ch] [ebp-20h] BYREF
  int r; // [esp+30h] [ebp-1Ch] BYREF
  int g; // [esp+34h] [ebp-18h] BYREF
  int b; // [esp+38h] [ebp-14h] BYREF
  int a[4]; // [esp+3Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::Panel *const, int *, int *, int *, int *))this->_vptr_Panel + 76))(this, &r, &g, &b, a);
  (*((void (__cdecl **)(vgui::Panel *const, int, int, int, int))this->_vptr_Panel + 94))(this, r, g, b, a[0]);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(this, 0, 0, wide, tall);
}

void vgui::Panel::paintBuildOverlay(vgui::Panel *const this)
{
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *const, int *, int *))this->_vptr_Panel + 3))(this, &wide, tall);
  (*((void (__cdecl **)(vgui::Panel *const, int))this->_vptr_Panel + 93))(this, 1);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(this, 0, 0, wide, 2);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(
    this,
    0,
    tall[0] - 2,
    wide,
    tall[0]);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, int, int, int))this->_vptr_Panel + 95))(this, 0, 2, 2, tall[0] - 2);
  (*((void (__cdecl **)(vgui::Panel *const, int, int, int, int))this->_vptr_Panel + 95))(
    this,
    wide - 2,
    2,
    wide,
    tall[0] - 2);
}

void vgui::Panel::drawSetColor(vgui::Panel *const this, vgui::Scheme::SchemeColor sc)
{
  int v2; // eax
  int v3; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 84))(v2);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, _DWORD, _DWORD, _DWORD))this->_vptr_Panel + 94))(
    this,
    *(_DWORD *)(16 * sc + v3 + 4),
    *(_DWORD *)(16 * sc + v3 + 8),
    *(_DWORD *)(16 * sc + v3 + 12),
    *(_DWORD *)(16 * sc + v3 + 16));
}

void vgui::Panel::drawSetColor(vgui::Panel *const this, int r, int g, int b, int a)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 18))(this->_surfaceBase);
}

void vgui::Panel::drawFilledRect(vgui::Panel *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 19))(this->_surfaceBase);
}

void vgui::Panel::drawOutlinedRect(vgui::Panel *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 20))(this->_surfaceBase);
}

void vgui::Panel::drawSetTextFont(vgui::Panel *const this, vgui::Scheme::SchemeFont sf_0)
{
  int v2; // eax
  int v3; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 84))(v2);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD))this->_vptr_Panel + 98))(this, *(_DWORD *)(v3 + 4 * sf_0 + 148));
}

void vgui::Panel::drawSetTextFont(vgui::Panel *const this, vgui::Font *font)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 21))(this->_surfaceBase);
}

void vgui::Panel::drawSetTextColor(vgui::Panel *const this, vgui::Scheme::SchemeColor sc)
{
  int v2; // eax
  int v3; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 84))(v2);
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD, _DWORD, _DWORD, _DWORD))this->_vptr_Panel + 100))(
    this,
    *(_DWORD *)(16 * sc + v3 + 4),
    *(_DWORD *)(16 * sc + v3 + 8),
    *(_DWORD *)(16 * sc + v3 + 12),
    *(_DWORD *)(16 * sc + v3 + 16));
}

void vgui::Panel::drawSetTextColor(vgui::Panel *const this, int r, int g, int b, int a)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 22))(this->_surfaceBase);
}

void vgui::Panel::drawSetTextPos(vgui::Panel *const this, int x, int y)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 23))(this->_surfaceBase);
}

void vgui::Panel::drawPrintText(vgui::Panel *const this, const char *str, int strlen)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 24))(this->_surfaceBase);
}

void vgui::Panel::drawPrintText(vgui::Panel *const this, int x, int y, const char *str, int strlen)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *, int, int))this->_surfaceBase->_vptr_SurfaceBase + 23))(
    this->_surfaceBase,
    x,
    y);
  (*((void (__cdecl **)(vgui::SurfaceBase *, const char *, int))this->_surfaceBase->_vptr_SurfaceBase + 24))(
    this->_surfaceBase,
    str,
    strlen);
}

void vgui::Panel::drawPrintChar(vgui::Panel *const this, char ch_0)
{
  char v2[16]; // [esp+1Ch] [ebp-10h] BYREF

  v2[0] = ch_0;
  (*((void (__cdecl **)(vgui::SurfaceBase *, char *, int))this->_surfaceBase->_vptr_SurfaceBase + 24))(
    this->_surfaceBase,
    v2,
    1);
}

void vgui::Panel::drawPrintChar(vgui::Panel *const this, int x, int y, char ch_0)
{
  char v4[16]; // [esp+1Ch] [ebp-10h] BYREF

  v4[0] = ch_0;
  (*((void (__cdecl **)(vgui::SurfaceBase *, int, int))this->_surfaceBase->_vptr_SurfaceBase + 23))(
    this->_surfaceBase,
    x,
    y);
  (*((void (__cdecl **)(vgui::SurfaceBase *, char *, int))this->_surfaceBase->_vptr_SurfaceBase + 24))(
    this->_surfaceBase,
    v4,
    1);
}

void vgui::Panel::drawSetTextureRGBA(vgui::Panel *const this, int id, const char *rgba, int wide, int tall)
{
  vgui::SurfaceBase *v5; // eax

  v5 = this->_surfaceBase;
  if ( v5 )
    (*((void (__cdecl **)(vgui::SurfaceBase *))v5->_vptr_SurfaceBase + 25))(this->_surfaceBase);
}

void vgui::Panel::drawSetTexture(vgui::Panel *const this, int id)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 26))(this->_surfaceBase);
}

void vgui::Panel::drawTexturedRect(vgui::Panel *const this, int x0, int y0, int x1, int y1)
{
  (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 27))(this->_surfaceBase);
}

void vgui::Panel::getAbsExtents(vgui::Panel *const this, int *const x0, int *const y0, int *const x1, int *const y1)
{
  *(_QWORD *)x0 = *(_QWORD *)this->_loc;
  *x1 = this->_size[0] + *x0;
  *y1 = this->_size[1] + *y0;
}

void vgui::Panel::removeChild(vgui::Panel *const this, vgui::Panel *child)
{
  int v2; // ebx
  vgui::Panel **v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  vgui::Panel **v7; // ebx

  child->_parent = 0;
  child->_surfaceBase = 0;
  v2 = this->_childDar._count;
  if ( v2 > 0 )
  {
    v3 = this->_childDar._data;
    v4 = 0;
    if ( child == *v3 )
    {
LABEL_8:
      v5 = v2 - 1;
      if ( v4 < v5 )
      {
        v6 = v4;
        while ( 1 )
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = this->_childDar._count - 1;
          if ( v4 >= v5 )
            break;
          v3 = this->_childDar._data;
        }
      }
      this->_childDar._count = v5;
    }
    else
    {
      while ( ++v4 != v2 )
      {
        if ( child == v3[v4] )
        {
          if ( v4 < 0 )
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::setSurfaceBaseTraverse(vgui::Panel *const this, vgui::SurfaceBase *surfaceBase)
{
  int v2; // ebx
  int v3; // ebx
  vgui::Panel *v4; // eax

  v2 = this->_childDar._count;
  this->_surfaceBase = surfaceBase;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->_childDar._data[v3++];
      (*((void (__cdecl **)(vgui::Panel *, vgui::SurfaceBase *))v4->_vptr_Panel + 90))(v4, surfaceBase);
    }
    while ( this->_childDar._count > v3 );
  }
}

bool vgui::Panel::wasMousePressed(vgui::Panel *const this, vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::MouseCode, vgui::Panel *const))(*(_DWORD *)v2 + 12))(v2, code, this);
}

bool vgui::Panel::wasMouseDoublePressed(vgui::Panel *const this, vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::MouseCode, vgui::Panel *const))(*(_DWORD *)v2 + 16))(v2, code, this);
}

bool vgui::Panel::isMouseDown(vgui::Panel *const this, vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::MouseCode, vgui::Panel *const))(*(_DWORD *)v2 + 20))(v2, code, this);
}

bool vgui::Panel::wasMouseReleased(vgui::Panel *const this, vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::MouseCode, vgui::Panel *const))(*(_DWORD *)v2 + 24))(v2, code, this);
}

bool vgui::Panel::wasKeyPressed(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::KeyCode, vgui::Panel *const))(*(_DWORD *)v2 + 28))(v2, code, this);
}

bool vgui::Panel::isKeyDown(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::KeyCode, vgui::Panel *const))(*(_DWORD *)v2 + 32))(v2, code, this);
}

bool vgui::Panel::wasKeyTyped(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::KeyCode, vgui::Panel *const))(*(_DWORD *)v2 + 36))(v2, code, this);
}

bool vgui::Panel::wasKeyReleased(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return (*(int (__cdecl **)(int, vgui::KeyCode, vgui::Panel *const))(*(_DWORD *)v2 + 40))(v2, code, this);
}

void vgui::Panel::removeInputSignal(vgui::Panel *const this, vgui::InputSignal *s)
{
  int v2; // ecx
  vgui::InputSignal **v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  vgui::InputSignal **v7; // ecx

  v2 = this->_inputSignalDar._count;
  if ( v2 > 0 )
  {
    v3 = this->_inputSignalDar._data;
    v4 = 0;
    if ( s == *v3 )
    {
LABEL_8:
      v5 = v2 - 1;
      if ( v4 < v5 )
      {
        v6 = v4;
        while ( 1 )
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = this->_inputSignalDar._count - 1;
          if ( v4 >= v5 )
            break;
          v3 = this->_inputSignalDar._data;
        }
      }
      this->_inputSignalDar._count = v5;
    }
    else
    {
      while ( ++v4 != v2 )
      {
        if ( s == v3[v4] )
        {
          if ( v4 < 0 )
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::removeRepaintSignal(vgui::Panel *const this, vgui::RepaintSignal *s)
{
  int v2; // ecx
  vgui::RepaintSignal **v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  vgui::RepaintSignal **v7; // ecx

  v2 = this->_repaintSignalDar._count;
  if ( v2 > 0 )
  {
    v3 = this->_repaintSignalDar._data;
    v4 = 0;
    if ( s == *v3 )
    {
LABEL_8:
      v5 = v2 - 1;
      if ( v4 < v5 )
      {
        v6 = v4;
        while ( 1 )
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = this->_repaintSignalDar._count - 1;
          if ( v4 >= v5 )
            break;
          v3 = this->_repaintSignalDar._data;
        }
      }
      this->_repaintSignalDar._count = v5;
    }
    else
    {
      while ( ++v4 != v2 )
      {
        if ( s == v3[v4] )
        {
          if ( v4 < 0 )
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::internalCursorMoved(vgui::Panel *const this, int x, int y)
{
  int v3; // esi
  vgui::InputSignal *v4; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this) )
  {
    if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
    {
      (*((void (__cdecl **)(vgui::BuildGroup *, int, int, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup + 8))(
        this->_buildGroup,
        x,
        y,
        this);
    }
    else
    {
      (*((void (__cdecl **)(vgui::Panel *const, int *, int *))this->_vptr_Panel + 35))(this, &x, &y);
      if ( this->_inputSignalDar._count > 0 )
      {
        v3 = 0;
        do
        {
          v4 = this->_inputSignalDar._data[v3++];
          (*v4->_vptr_InputSignal)(v4, x, y, this);
        }
        while ( this->_inputSignalDar._count > v3 );
      }
    }
  }
}

void vgui::Panel::internalKeyTyped(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal *v3; // eax

  if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
  {
    (*((void (__cdecl **)(vgui::BuildGroup *, vgui::KeyCode, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup + 12))(
      this->_buildGroup,
      code,
      this);
  }
  else
  {
    if ( code == KEY_TAB && (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 51))(this) )
    {
      if ( (*((uint8_t (__cdecl **)(vgui::Panel *const, int))this->_vptr_Panel + 25))(this, 78)
        || (*((uint8_t (__cdecl **)(vgui::Panel *const, int))this->_vptr_Panel + 25))(this, 79) )
      {
        (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 48))(this);
      }
      else
      {
        (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 49))(this);
      }
    }
    if ( this->_inputSignalDar._count > 0 )
    {
      v2 = 0;
      do
      {
        v3 = this->_inputSignalDar._data[v2++];
        (*((void (__cdecl **)(vgui::InputSignal *, vgui::KeyCode, vgui::Panel *const))v3->_vptr_InputSignal + 8))(
          v3,
          code,
          this);
      }
      while ( this->_inputSignalDar._count > v2 );
    }
  }
}

void vgui::Panel::internalSetCursor(vgui::Panel *const this)
{
  vgui::SurfaceBase *v1; // eax
  void (__cdecl *v2)(vgui::SurfaceBase *, int); // esi
  int v3; // eax

  if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
    (*((void (__cdecl **)(vgui::BuildGroup *, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup + 13))(
      this->_buildGroup,
      this);
  v1 = this->_surfaceBase;
  if ( v1 )
  {
    v2 = (void (__cdecl *)(vgui::SurfaceBase *, int))*((_DWORD *)v1->_vptr_SurfaceBase + 30);
    v3 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 38))(this);
    v2(this->_surfaceBase, v3);
  }
}

bool vgui::Panel::isWithin(vgui::Panel *const this, int x, int y)
{
  bool result; // al

  (*((void (__cdecl **)(vgui::Panel *const, int *, int *))this->_vptr_Panel + 35))(this, &x, &y);
  result = 0;
  if ( x >= 0 && y >= 0 && x < this->_size[0] )
    result = y < this->_size[1];
  return result;
}

void vgui::Panel::localToScreen(vgui::Panel *const this, int *const x, int *const y)
{
  *x += this->_loc[0];
  *y += this->_loc[1];
}

void vgui::Panel::screenToLocal(vgui::Panel *const this, int *const x, int *const y)
{
  *x -= this->_loc[0];
  *y -= this->_loc[1];
}

void vgui::Panel::setCursor(vgui::Panel *const this, vgui::Cursor *cursor)
{
  this->_schemeCursor = scu_user;
  this->_cursor = cursor;
}

void vgui::Panel::setCursor(vgui::Panel *const this, vgui::Scheme::SchemeCursor scu)
{
  this->_cursor = 0;
  this->_schemeCursor = scu;
}

void vgui::Panel::setMinimumSize(vgui::Panel *const this, int wide, int tall)
{
  this->_minimumSize[0] = wide;
  this->_minimumSize[1] = tall;
}

void vgui::Panel::requestFocus(vgui::Panel *const this)
{
  int v1; // eax

  v1 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  (*(void (__cdecl **)(int, vgui::Panel *const))(*(_DWORD *)v1 + 68))(v1, this);
}

bool vgui::Panel::hasFocus(vgui::Panel *const this)
{
  int v1; // eax

  v1 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  return this == (vgui::Panel *const)(*(int (__cdecl **)(int))(*(_DWORD *)v1 + 72))(v1);
}

void vgui::Panel::getClipRect(vgui::Panel *const this, int *const x0, int *const y0, int *const x1, int *const y1)
{
  *x0 = this->_clipRect[0];
  *y0 = this->_clipRect[1];
  *x1 = this->_clipRect[2];
  *y1 = this->_clipRect[3];
}

int vgui::Panel::getChildCount(vgui::Panel *const this)
{
  return this->_childDar._count;
}

void vgui::Panel::setLayout(vgui::Panel *const this, vgui::Layout *layout)
{
  this->_layout = layout;
  (*((void (__cdecl **)(vgui::Panel *const, _DWORD))this->_vptr_Panel + 46))(this, 0);
}

void vgui::Panel::internalPerformLayout(vgui::Panel *const this)
{
  vgui::Layout *v1; // eax

  v1 = this->_layout;
  this->_needsLayout = 0;
  if ( v1 )
    (*v1->_vptr_Layout)(v1, this);
  else
    (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 91))(this);
  (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 12))(this);
}

void vgui::Panel::setFocusNavGroup(vgui::Panel *const this, vgui::FocusNavGroup *focusNavGroup)
{
  this->_focusNavGroup = focusNavGroup;
  if ( focusNavGroup )
    (*focusNavGroup->_vptr_FocusNavGroup)(focusNavGroup, this);
}

void vgui::Panel::requestFocusPrev(vgui::Panel *const this)
{
  vgui::FocusNavGroup *v1; // eax

  v1 = this->_focusNavGroup;
  if ( v1 )
    (*((void (__cdecl **)(vgui::FocusNavGroup *))v1->_vptr_FocusNavGroup + 1))(this->_focusNavGroup);
}

void vgui::Panel::requestFocusNext(vgui::Panel *const this)
{
  vgui::FocusNavGroup *v1; // eax

  v1 = this->_focusNavGroup;
  if ( v1 )
    (*((void (__cdecl **)(vgui::FocusNavGroup *))v1->_vptr_FocusNavGroup + 2))(this->_focusNavGroup);
}

void vgui::Panel::internalFocusChanged(vgui::Panel *const this, bool lost)
{
  vgui::FocusNavGroup *v2; // eax
  int v3; // esi
  vgui::FocusChangeSignal *v4; // eax

  if ( !lost )
  {
    v2 = this->_focusNavGroup;
    if ( v2 )
      (*((void (__cdecl **)(vgui::FocusNavGroup *, vgui::Panel *const))v2->_vptr_FocusNavGroup + 3))(v2, this);
  }
  if ( this->_focusChangeSignalDar._count > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->_focusChangeSignalDar._data[v3++];
      (*v4->_vptr_FocusChangeSignal)(v4, lost, this);
    }
    while ( this->_focusChangeSignalDar._count > v3 );
  }
}

bool vgui::Panel::isAutoFocusNavEnabled(vgui::Panel *const this)
{
  return this->_autoFocusNavEnabled;
}

void vgui::Panel::setAutoFocusNavEnabled(vgui::Panel *const this, bool state)
{
  this->_autoFocusNavEnabled = state;
}

void vgui::Panel::setBorder(vgui::Panel *const this, vgui::Border *border)
{
  this->_border = border;
}

void vgui::Panel::getMinimumSize(vgui::Panel *const this, int *const wide, int *const tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_minimumSize;
}

void vgui::Panel::setPaintBorderEnabled(vgui::Panel *const this, bool state)
{
  this->_paintBorderEnabled = state;
}

void vgui::Panel::setPaintBackgroundEnabled(vgui::Panel *const this, bool state)
{
  this->_paintBackgroundEnabled = state;
}

void vgui::Panel::setPaintEnabled(vgui::Panel *const this, bool state)
{
  this->_paintEnabled = state;
}

void vgui::Panel::getInset(vgui::Panel *const this, int *const left, int *const top, int *const right, int *const bottom)
{
  vgui::Border *v5; // eax

  v5 = this->_border;
  if ( v5 )
  {
    (*((void (__cdecl **)(vgui::Border *))v5->_vptr_Image + 25))(this->_border);
  }
  else
  {
    *left = 0;
    *top = 0;
    *right = 0;
    *bottom = 0;
  }
}

void vgui::Panel::getPaintSize(vgui::Panel *const this, int *const wide, int *const tall)
{
  vgui::Border *v3; // eax
  int v4; // edx
  int left; // [esp+20h] [ebp-1Ch] BYREF
  int top; // [esp+24h] [ebp-18h] BYREF
  int right; // [esp+28h] [ebp-14h] BYREF
  int bottom; // [esp+2Ch] [ebp-10h] BYREF

  v3 = this->_border;
  if ( v3 )
  {
    (*((void (__cdecl **)(vgui::Border *, int *, int *, int *, int *))v3->_vptr_Image + 25))(
      v3,
      &left,
      &top,
      &right,
      &bottom);
    v4 = top;
    *wide = this->_size[0] - (right + left);
    *tall = this->_size[1] - (bottom + v4);
  }
  else
  {
    *(_QWORD *)wide = *(_QWORD *)this->_size;
  }
}

void vgui::Panel::setPreferredSize(vgui::Panel *const this, int wide, int tall)
{
  this->_preferredSize[0] = wide;
  this->_preferredSize[1] = tall;
}

void vgui::Panel::getPreferredSize(vgui::Panel *const this, int *const wide, int *const tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_preferredSize;
}

int vgui::Panel::getWide(vgui::Panel *const this)
{
  return this->_size[0];
}

int vgui::Panel::getTall(vgui::Panel *const this)
{
  return this->_size[1];
}

bool vgui::Panel::isEnabled(vgui::Panel *const this)
{
  return this->_enabled;
}

void vgui::Panel::setEnabled(vgui::Panel *const this, bool state)
{
  this->_enabled = state;
}

void vgui::Panel::setBuildGroup(vgui::Panel *const this, vgui::BuildGroup *buildGroup, const char *panelPersistanceName)
{
  this->_buildGroup = buildGroup;
  (*((void (__cdecl **)(vgui::BuildGroup *, vgui::Panel *const))buildGroup->_vptr_BuildGroup + 7))(buildGroup, this);
}

bool vgui::Panel::isBuildGroupEnabled(vgui::Panel *const this)
{
  vgui::BuildGroup *v1; // eax
  bool result; // al

  v1 = this->_buildGroup;
  if ( v1 )
    result = (*((int (__cdecl **)(vgui::BuildGroup *))v1->_vptr_BuildGroup + 1))(this->_buildGroup);
  else
    result = 0;
  return result;
}

void vgui::Panel::removeAllChildren(vgui::Panel *const this)
{
  this->_childDar._count = 0;
}

void vgui::Panel::repaintParent(vgui::Panel *const this)
{
  vgui::Panel *v1; // eax

  v1 = this->_parent;
  if ( v1 )
    (*((void (__cdecl **)(vgui::Panel *))v1->_vptr_Panel + 12))(this->_parent);
}

void vgui::Panel::setAsMouseArena(vgui::Panel *const this, bool state)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  (*(void (__cdecl **)(int, vgui::Panel *const))(*(_DWORD *)v2 + 64))(v2, this);
}

void vgui::Panel::setBgColor(vgui::Panel *const this, vgui::Color *p_color)
{
  *(_DWORD *)this->_bgColor._color = *(_DWORD *)p_color->_color;
  this->_bgColor._schemeColor = p_color->_schemeColor;
}

void vgui::Panel::setFgColor(vgui::Panel *const this, vgui::Color *p_color)
{
  *(_DWORD *)this->_fgColor._color = *(_DWORD *)p_color->_color;
  this->_fgColor._schemeColor = p_color->_schemeColor;
}

void vgui::Panel::getBgColor(vgui::Panel *const this, vgui::Color *const color)
{
  *(_DWORD *)color->_color = *(_DWORD *)this->_bgColor._color;
  color->_schemeColor = this->_bgColor._schemeColor;
}

void vgui::Panel::getFgColor(vgui::Panel *const this, vgui::Color *const color)
{
  *(_DWORD *)color->_color = *(_DWORD *)this->_fgColor._color;
  color->_schemeColor = this->_fgColor._schemeColor;
}

void vgui::Panel::getVirtualSize(vgui::Panel *const this, int *const wide, int *const tall)
{
  (*((void (**)(void))this->_vptr_Panel + 3))();
}

void vgui::Panel::setLayoutInfo(vgui::Panel *const this, vgui::LayoutInfo *layoutInfo)
{
  this->_layoutInfo = layoutInfo;
}

bool vgui::Panel::isCursorNone(vgui::Panel *const this)
{
  int v1; // eax
  char v2; // dl

  v1 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 38))(this);
  v2 = 1;
  if ( v1 )
    v2 = (*(int (__cdecl **)(int))(*(_DWORD *)v1 + 12))(v1) == 1;
  return v2;
}

void vgui::Panel::getBgColor(vgui::Panel *const this, int *const r, int *const g, int *const b, int *const a)
{
  vgui::Color::getColor(&this->_bgColor, r, g, b, a);
}

void vgui::Panel::getFgColor(vgui::Panel *const this, int *const r, int *const g, int *const b, int *const a)
{
  vgui::Color::getColor(&this->_fgColor, r, g, b, a);
}

void vgui::Panel::setBgColor(vgui::Panel *const this, int r, int g, int b, int a)
{
  vgui::Color::setColor(&this->_bgColor, r, g, b, a);
}

void vgui::Panel::setFgColor(vgui::Panel *const this, int r, int g, int b, int a)
{
  vgui::Color::setColor(&this->_fgColor, r, g, b, a);
}

void vgui::Panel::setBgColor(vgui::Panel *const this, vgui::Scheme::SchemeColor sc)
{
  vgui::Color::setColor(&this->_bgColor, sc);
}

void vgui::Panel::setFgColor(vgui::Panel *const this, vgui::Scheme::SchemeColor sc)
{
  vgui::Color::setColor(&this->_fgColor, sc);
}

void vgui::Panel::getPersistanceText(vgui::Panel *const this, char *buf, int bufLen)
{
  int x; // [esp+20h] [ebp-1Ch] BYREF
  int y; // [esp+24h] [ebp-18h] BYREF
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void (__cdecl **)(vgui::Panel *const, int *, int *, int *, int *))this->_vptr_Panel + 5))(
    this,
    &x,
    &y,
    &wide,
    tall);
  sprintf(buf, "->setBounds(%d,%d,%d,%d);\n", x, y, wide, tall[0]);
}

void vgui::Panel::invalidateLayout(vgui::Panel *const this, bool layoutNow)
{
  this->_needsLayout = 1;
  if ( layoutNow )
    (*((void (**)(void))this->_vptr_Panel + 92))();
}

void vgui::Panel::setAsMouseCapture(vgui::Panel *const this, bool state)
{
  int v2; // eax

  v2 = (*((int (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 83))(this);
  if ( state )
    (*(void (__cdecl **)(int, vgui::Panel *const))(*(_DWORD *)v2 + 56))(v2, this);
  else
    (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)v2 + 56))(v2, 0);
}

void vgui::Panel::paintTraverse(vgui::Panel *const this, bool repaint)
{
  bool v3; // cc
  int v4; // edi
  vgui::Panel *v5; // eax
  vgui::SurfaceBase *v6; // eax
  vgui::Border *v7; // eax

  if ( this->_visible )
  {
    if ( this->_needsRepaint )
      repaint = 1;
    v3 = this->_clipRect[2] <= this->_clipRect[0];
    this->_needsRepaint = 0;
    if ( v3 || this->_clipRect[3] <= this->_clipRect[1] )
    {
      repaint = 0;
    }
    else if ( repaint && (this->_paintBorderEnabled || this->_paintBackgroundEnabled || this->_paintEnabled) )
    {
      (*((void (__cdecl **)(vgui::SurfaceBase *, vgui::Panel *const, int))this->_surfaceBase->_vptr_SurfaceBase + 32))(
        this->_surfaceBase,
        this,
        1);
      v7 = this->_border;
      if ( v7 && this->_paintBorderEnabled )
        (*((void (__cdecl **)(vgui::Border *, vgui::Panel *const))v7->_vptr_Image + 23))(v7, this);
      if ( this->_paintBackgroundEnabled )
        (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 111))(this);
      if ( this->_paintEnabled )
        (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 112))(this);
      (*((void (__cdecl **)(vgui::SurfaceBase *, vgui::Panel *const))this->_surfaceBase->_vptr_SurfaceBase + 33))(
        this->_surfaceBase,
        this);
    }
    if ( this->_childDar._count > 0 )
    {
      v4 = 0;
      do
      {
        v5 = this->_childDar._data[v4++];
        (*((void (__cdecl **)(vgui::Panel *, bool))v5->_vptr_Panel + 110))(v5, repaint);
      }
      while ( v4 < this->_childDar._count );
    }
    if ( repaint
      && (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
      && (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 42))(this) )
    {
      (*((void (__cdecl **)(vgui::SurfaceBase *, vgui::Panel *const, _DWORD))this->_surfaceBase->_vptr_SurfaceBase + 32))(
        this->_surfaceBase,
        this,
        0);
      (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 113))(this);
      (*((void (__cdecl **)(vgui::SurfaceBase *, vgui::Panel *const))this->_surfaceBase->_vptr_SurfaceBase + 33))(
        this->_surfaceBase,
        this);
    }
    v6 = this->_surfaceBase;
    if ( v6->_needsSwap && this == (vgui::Panel *const)(*v6->_vptr_SurfaceBase)(this->_surfaceBase) )
    {
      this->_surfaceBase->_needsSwap = 0;
      (*((void (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBase->_vptr_SurfaceBase + 31))(this->_surfaceBase);
    }
  }
}

void vgui::Panel::solveTraverse(vgui::Panel *const this)
{
  int v1; // ebx
  vgui::Panel *v2; // eax

  if ( this->_visible )
  {
    (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 109))(this);
    if ( this->_needsLayout )
      (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 92))(this);
    (*((void (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 109))(this);
    if ( this->_childDar._count > 0 )
    {
      v1 = 0;
      do
      {
        v2 = this->_childDar._data[v1++];
        (*((void (__cdecl **)(vgui::Panel *))v2->_vptr_Panel + 88))(v2);
      }
      while ( v1 < this->_childDar._count );
    }
  }
}

void vgui::Panel::internalKeyFocusTicked(vgui::Panel *const this)
{
  int v1; // esi
  vgui::InputSignal *v2; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_inputSignalDar._data[v1++];
      (*((void (__cdecl **)(vgui::InputSignal *, vgui::Panel *const))v2->_vptr_InputSignal + 10))(v2, this);
    }
    while ( v1 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::internalKeyReleased(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->_inputSignalDar._data[v2++];
      (*((void (__cdecl **)(vgui::InputSignal *, vgui::KeyCode, vgui::Panel *const))v3->_vptr_InputSignal + 9))(
        v3,
        code,
        this);
    }
    while ( v2 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::internalKeyPressed(vgui::Panel *const this, vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->_inputSignalDar._data[v2++];
      (*((void (__cdecl **)(vgui::InputSignal *, vgui::KeyCode, vgui::Panel *const))v3->_vptr_InputSignal + 7))(
        v3,
        code,
        this);
    }
    while ( v2 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::internalMouseWheeled(vgui::Panel *const this, int delta)
{
  int v2; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this->_inputSignalDar._data[v2++];
      (*((void (__cdecl **)(vgui::InputSignal *, int, vgui::Panel *const))v3->_vptr_InputSignal + 6))(v3, delta, this);
    }
    while ( v2 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::internalMouseReleased(vgui::Panel *const this, vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this) )
  {
    if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
    {
      (*((void (__cdecl **)(vgui::BuildGroup *, vgui::MouseCode, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup
       + 10))(
        this->_buildGroup,
        code,
        this);
    }
    else
    {
      for ( i = 0; this->_inputSignalDar._count > i; ++i )
      {
        v3 = this->_inputSignalDar._data[i];
        (*((void (__cdecl **)(vgui::InputSignal *, vgui::MouseCode, vgui::Panel *const))v3->_vptr_InputSignal + 5))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalMouseDoublePressed(vgui::Panel *const this, vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this) )
  {
    if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
    {
      (*((void (__cdecl **)(vgui::BuildGroup *, vgui::MouseCode, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup
       + 11))(
        this->_buildGroup,
        code,
        this);
    }
    else
    {
      for ( i = 0; this->_inputSignalDar._count > i; ++i )
      {
        v3 = this->_inputSignalDar._data[i];
        (*((void (__cdecl **)(vgui::InputSignal *, vgui::MouseCode, vgui::Panel *const))v3->_vptr_InputSignal + 4))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalMousePressed(vgui::Panel *const this, vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal *v3; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this) )
  {
    if ( (*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this) )
    {
      (*((void (__cdecl **)(vgui::BuildGroup *, vgui::MouseCode, vgui::Panel *const))this->_buildGroup->_vptr_BuildGroup
       + 9))(
        this->_buildGroup,
        code,
        this);
    }
    else
    {
      for ( i = 0; this->_inputSignalDar._count > i; ++i )
      {
        v3 = this->_inputSignalDar._data[i];
        (*((void (__cdecl **)(vgui::InputSignal *, vgui::MouseCode, vgui::Panel *const))v3->_vptr_InputSignal + 3))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalCursorExited(vgui::Panel *const this)
{
  int v1; // esi
  vgui::InputSignal *v2; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this)
    && !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_inputSignalDar._data[v1++];
      (*((void (__cdecl **)(vgui::InputSignal *, vgui::Panel *const))v2->_vptr_InputSignal + 2))(v2, this);
    }
    while ( v1 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::internalCursorEntered(vgui::Panel *const this)
{
  int v1; // esi
  vgui::InputSignal *v2; // eax

  if ( !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 87))(this)
    && !(*((uint8_t (__cdecl **)(vgui::Panel *const))this->_vptr_Panel + 65))(this)
    && this->_inputSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_inputSignalDar._data[v1++];
      (*((void (__cdecl **)(vgui::InputSignal *, vgui::Panel *const))v2->_vptr_InputSignal + 1))(v2, this);
    }
    while ( v1 < this->_inputSignalDar._count );
  }
}

void vgui::Panel::addInputSignal(vgui::Panel *const this, vgui::InputSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::InputSignal*> *v3; // esi
  vgui::InputSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::InputSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::InputSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_inputSignalDar._count;
  v3 = &this->_inputSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_inputSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_inputSignalDar._capacity;
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
    v14 = (vgui::InputSignal **)v10;
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
    v2 = this->_inputSignalDar._count;
    this->_inputSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_inputSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_inputSignalDar._data )
    {
      operator delete[](this->_inputSignalDar._data);
      v2 = this->_inputSignalDar._count;
    }
    v8 = v14;
    this->_inputSignalDar._data = v14;
  }
  else
  {
    v8 = this->_inputSignalDar._data;
  }
  v8[v2] = s;
  ++this->_inputSignalDar._count;
}

void vgui::Panel::addRepaintSignal(vgui::Panel *const this, vgui::RepaintSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::RepaintSignal*> *v3; // esi
  vgui::RepaintSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::RepaintSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::RepaintSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_repaintSignalDar._count;
  v3 = &this->_repaintSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_repaintSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_repaintSignalDar._capacity;
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
    v14 = (vgui::RepaintSignal **)v10;
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
    v2 = this->_repaintSignalDar._count;
    this->_repaintSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_repaintSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_repaintSignalDar._data )
    {
      operator delete[](this->_repaintSignalDar._data);
      v2 = this->_repaintSignalDar._count;
    }
    v8 = v14;
    this->_repaintSignalDar._data = v14;
  }
  else
  {
    v8 = this->_repaintSignalDar._data;
  }
  v8[v2] = s;
  ++this->_repaintSignalDar._count;
}

void vgui::Panel::addFocusChangeSignal(vgui::Panel *const this, vgui::FocusChangeSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::FocusChangeSignal*> *v3; // esi
  vgui::FocusChangeSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::FocusChangeSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::FocusChangeSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_focusChangeSignalDar._count;
  v3 = &this->_focusChangeSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_focusChangeSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_focusChangeSignalDar._capacity;
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
    v14 = (vgui::FocusChangeSignal **)v10;
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
    v2 = this->_focusChangeSignalDar._count;
    this->_focusChangeSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_focusChangeSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_focusChangeSignalDar._data )
    {
      operator delete[](this->_focusChangeSignalDar._data);
      v2 = this->_focusChangeSignalDar._count;
    }
    v8 = v14;
    this->_focusChangeSignalDar._data = v14;
  }
  else
  {
    v8 = this->_focusChangeSignalDar._data;
  }
  v8[v2] = s;
  ++this->_focusChangeSignalDar._count;
}

void vgui::Panel::setParent(vgui::Panel *const this, vgui::Panel *newParent)
{
  vgui::Panel *v2; // esi
  vgui::Panel *v3; // eax
  vgui::Dar<vgui::Panel*> *v4; // ebp
  int v5; // ecx
  vgui::Panel **v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  vgui::Panel **v10; // eax
  unsigned int v11; // edi
  _BYTE *v12; // eax
  _WORD *v13; // edi
  int v14; // eax
  int v15; // [esp+14h] [ebp-28h]
  vgui::Panel **v16; // [esp+18h] [ebp-24h]
  unsigned int v17; // [esp+1Ch] [ebp-20h]

  v2 = newParent;
  v3 = this->_parent;
  if ( v3 )
    (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *const))v3->_vptr_Panel + 19))(v3, this);
  if ( newParent )
  {
    this->_parent = newParent;
    v4 = &newParent->_childDar;
    v5 = newParent->_childDar._count;
    if ( v5 > 0 )
    {
      v6 = newParent->_childDar._data;
      v7 = 0;
      if ( this == *v6 )
      {
LABEL_12:
        (*((void (__cdecl **)(vgui::Panel *const, vgui::SurfaceBase *))this->_vptr_Panel + 90))(this, v2->_surfaceBase);
        return;
      }
      while ( ++v7 != v5 )
      {
        if ( this == v6[v7] )
          goto LABEL_12;
      }
    }
    v8 = newParent->_childDar._capacity;
    v9 = v5 + 1;
    if ( v5 + 1 > v8 )
    {
      if ( v8 || (v8 = 1, v11 = 4, v9 > 1) )
      {
        do
          v8 *= 2;
        while ( v9 > v8 );
        v11 = 4 * v8;
      }
      v15 = v8;
      v12 = (_BYTE *)operator new[](v11);
      v16 = (vgui::Panel **)v12;
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
      v5 = newParent->_childDar._count;
      newParent->_childDar._capacity = v15;
      if ( v5 > 0 )
      {
        v14 = 0;
        do
        {
          v16[v14] = newParent->_childDar._data[v14];
          ++v14;
          v5 = v4->_count;
        }
        while ( v14 < v4->_count );
      }
      if ( newParent->_childDar._data )
      {
        operator delete[](newParent->_childDar._data);
        v5 = newParent->_childDar._count;
      }
      v10 = v16;
      newParent->_childDar._data = v16;
    }
    else
    {
      v10 = newParent->_childDar._data;
    }
    v10[v5] = this;
    ++newParent->_childDar._count;
    v2 = this->_parent;
    goto LABEL_12;
  }
}

void vgui::Panel::insertChildAt(vgui::Panel *const this, vgui::Panel *child, int index)
{
  int v3; // edx
  int v4; // ecx
  vgui::Panel **v5; // edi
  int v6; // eax
  vgui::Panel *v7; // eax
  int v8; // eax
  vgui::Dar<vgui::Panel*> *v9; // ebp
  int v10; // ecx
  int v11; // edx
  vgui::Panel **v12; // edi
  unsigned int v13; // edi
  _BYTE *v14; // eax
  _WORD *v15; // edi
  int v16; // edx
  vgui::Panel **v17; // edi
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  int v21; // eax
  _BYTE *v22; // eax
  _WORD *v23; // edi
  int v24; // ecx
  vgui::Panel **v25; // ecx
  int v26; // [esp+10h] [ebp-2Ch]
  int v27; // [esp+10h] [ebp-2Ch]
  vgui::Panel **v28; // [esp+14h] [ebp-28h]
  int v29; // [esp+14h] [ebp-28h]
  unsigned int v30; // [esp+18h] [ebp-24h]
  unsigned int v31; // [esp+18h] [ebp-24h]
  vgui::Panel **v32; // [esp+1Ch] [ebp-20h]

  v3 = index;
  v4 = this->_childDar._count;
  if ( v4 <= 0 )
    goto LABEL_6;
  v5 = this->_childDar._data;
  v6 = 0;
  if ( child != *v5 )
  {
    while ( ++v6 != v4 )
    {
      if ( child == v5[v6] )
        return;
    }
LABEL_6:
    v7 = child->_parent;
    if ( v7 )
    {
      (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))v7->_vptr_Panel + 19))(v7, child);
      v3 = index;
    }
    child->_parent = this;
    if ( v3 < 0 )
      goto LABEL_15;
    v8 = this->_childDar._count;
    if ( v3 > v8 )
      goto LABEL_15;
    v9 = &this->_childDar;
    v10 = v8 + 1;
    if ( v3 == v8 || !v8 )
    {
      v11 = this->_childDar._capacity;
      if ( v10 <= v11 )
      {
        v12 = this->_childDar._data;
LABEL_14:
        v12[v8] = child;
        ++this->_childDar._count;
LABEL_15:
        (*((void (__cdecl **)(vgui::Panel *, vgui::SurfaceBase *))child->_vptr_Panel + 90))(child, this->_surfaceBase);
        return;
      }
      if ( v11 || (v11 = 1, v13 = 4, v10 > 1) )
      {
        do
          v11 *= 2;
        while ( v10 > v11 );
        v13 = 4 * v11;
      }
      v26 = v11;
      v14 = (_BYTE *)operator new[](v13);
      v28 = (vgui::Panel **)v14;
      if ( v14 )
      {
        v30 = v13;
        v15 = v14;
        if ( v30 >= 8 )
        {
          if ( ((uint8_t)v14 & 1) != 0 )
          {
            *v14 = 0;
            --v30;
            v15 = v14 + 1;
          }
          if ( ((uint8_t)v15 & 2) != 0 )
          {
            *v15++ = 0;
            v30 -= 2;
          }
          if ( ((uint8_t)v15 & 4) != 0 )
          {
            *(_DWORD *)v15 = 0;
            v15 += 2;
            v30 -= 4;
          }
          memset(v15, 0, 4 * (v30 >> 2));
          v15 += 2 * (v30 >> 2);
          LOBYTE(v30) = v30 & 3;
        }
        if ( (v30 & 4) != 0 )
        {
          *(_DWORD *)v15 = 0;
          v15 += 2;
        }
        if ( (v30 & 2) != 0 )
          *v15++ = 0;
        if ( (v30 & 1) != 0 )
          *(_BYTE *)v15 = 0;
        v8 = this->_childDar._count;
        this->_childDar._capacity = v26;
        if ( v8 > 0 )
        {
          v16 = 0;
          do
          {
            v28[v16] = this->_childDar._data[v16];
            ++v16;
            v8 = v9->_count;
          }
          while ( v16 < v9->_count );
        }
        if ( this->_childDar._data )
        {
          operator delete[](this->_childDar._data);
          v8 = this->_childDar._count;
        }
        this->_childDar._data = v28;
        v12 = v28;
        goto LABEL_14;
      }
LABEL_74:
      exit(0);
    }
    v29 = this->_childDar._capacity;
    if ( v10 > v29 )
    {
      if ( v29 || (v29 = 1, v20 = 4, v10 > 1) )
      {
        v21 = v29;
        do
          v21 *= 2;
        while ( v10 > v21 );
        v29 = v21;
        v20 = 4 * v21;
      }
      v27 = v3;
      v22 = (_BYTE *)operator new[](v20);
      v3 = v27;
      v32 = (vgui::Panel **)v22;
      if ( !v22 )
        goto LABEL_74;
      v31 = v20;
      v23 = v22;
      if ( v31 >= 8 )
      {
        if ( ((uint8_t)v22 & 1) != 0 )
        {
          *v22 = 0;
          --v31;
          v23 = v22 + 1;
        }
        if ( ((uint8_t)v23 & 2) != 0 )
        {
          *v23++ = 0;
          v31 -= 2;
        }
        if ( ((uint8_t)v23 & 4) != 0 )
        {
          *(_DWORD *)v23 = 0;
          v23 += 2;
          v31 -= 4;
        }
        memset(v23, 0, 4 * (v31 >> 2));
        v23 += 2 * (v31 >> 2);
        LOBYTE(v31) = v31 & 3;
      }
      if ( (v31 & 4) != 0 )
      {
        *(_DWORD *)v23 = 0;
        v23 += 2;
      }
      if ( (v31 & 2) != 0 )
        *v23++ = 0;
      if ( (v31 & 1) != 0 )
        *(_BYTE *)v23 = 0;
      v8 = this->_childDar._count;
      this->_childDar._capacity = v29;
      if ( v8 > 0 )
      {
        v24 = 0;
        do
        {
          v32[v24] = this->_childDar._data[v24];
          ++v24;
          v8 = v9->_count;
        }
        while ( v24 < v9->_count );
      }
      v25 = this->_childDar._data;
      if ( v25 )
      {
        operator delete[](v25);
        v8 = this->_childDar._count;
        v3 = v27;
      }
      this->_childDar._data = v32;
      v17 = v32;
    }
    else
    {
      v17 = this->_childDar._data;
    }
    v17[v8] = child;
    v18 = this->_childDar._count;
    this->_childDar._count = v18 + 1;
    if ( v3 < v18 )
    {
      v19 = v18;
      do
      {
        --v18;
        this->_childDar._data[v19] = this->_childDar._data[v19 - 1];
        --v19;
      }
      while ( v18 != v3 );
    }
    this->_childDar._data[v3] = child;
    goto LABEL_15;
  }
}

void vgui::Panel::addChild(vgui::Panel *const this, vgui::Panel *child)
{
  vgui::Panel *v2; // eax
  vgui::Dar<vgui::Panel*> *v3; // ebp
  int v4; // ecx
  vgui::Panel **v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  vgui::Panel **v9; // eax
  unsigned int v10; // edi
  _BYTE *v11; // eax
  _WORD *v12; // edi
  int v13; // eax
  int v14; // [esp+14h] [ebp-28h]
  vgui::Panel **v15; // [esp+18h] [ebp-24h]
  unsigned int v16; // [esp+1Ch] [ebp-20h]

  v2 = child->_parent;
  if ( v2 )
    (*((void (__cdecl **)(vgui::Panel *, vgui::Panel *))v2->_vptr_Panel + 19))(v2, child);
  child->_parent = this;
  v3 = &this->_childDar;
  v4 = this->_childDar._count;
  if ( v4 > 0 )
  {
    v5 = this->_childDar._data;
    v6 = 0;
    if ( child == *v5 )
      goto LABEL_11;
    while ( ++v6 != v4 )
    {
      if ( child == v5[v6] )
        goto LABEL_11;
    }
  }
  v7 = this->_childDar._capacity;
  v8 = v4 + 1;
  if ( v4 + 1 > v7 )
  {
    if ( v7 || (v7 = 1, v10 = 4, v8 > 1) )
    {
      do
        v7 *= 2;
      while ( v8 > v7 );
      v10 = 4 * v7;
    }
    v14 = v7;
    v11 = (_BYTE *)operator new[](v10);
    v15 = (vgui::Panel **)v11;
    if ( !v11 )
      exit(0);
    v16 = v10;
    v12 = v11;
    if ( v16 >= 8 )
    {
      if ( ((uint8_t)v11 & 1) != 0 )
      {
        *v11 = 0;
        --v16;
        v12 = v11 + 1;
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
    if ( (v16 & 4) != 0 )
    {
      *(_DWORD *)v12 = 0;
      v12 += 2;
    }
    if ( (v16 & 2) != 0 )
      *v12++ = 0;
    if ( (v16 & 1) != 0 )
      *(_BYTE *)v12 = 0;
    v4 = this->_childDar._count;
    this->_childDar._capacity = v14;
    if ( v4 > 0 )
    {
      v13 = 0;
      do
      {
        v15[v13] = this->_childDar._data[v13];
        ++v13;
        v4 = v3->_count;
      }
      while ( v13 < v3->_count );
    }
    if ( this->_childDar._data )
    {
      operator delete[](this->_childDar._data);
      v4 = this->_childDar._count;
    }
    v9 = v15;
    this->_childDar._data = v15;
  }
  else
  {
    v9 = this->_childDar._data;
  }
  v9[v4] = child;
  ++this->_childDar._count;
LABEL_11:
  (*((void (__cdecl **)(vgui::Panel *, vgui::SurfaceBase *))child->_vptr_Panel + 90))(child, this->_surfaceBase);
}

void vgui::Panel::init(vgui::Panel *const this, int x, int y, int wide, int tall)
{
  int (**v6)(...); // eax

  this->_loc[0] = 0;
  this->_pos[0] = x;
  this->_loc[1] = 0;
  this->_needsRepaint = 0;
  this->_parent = 0;
  this->_pos[1] = y;
  this->_surfaceBase = 0;
  this->_visible = 1;
  this->_minimumSize[0] = 0;
  this->_size[0] = wide;
  this->_minimumSize[1] = 0;
  this->_cursor = 0;
  this->_schemeCursor = scu_arrow;
  this->_size[1] = tall;
  this->_border = 0;
  this->_buildGroup = 0;
  this->_layoutInfo = 0;
  v6 = this->_vptr_Panel;
  this->_layout = 0;
  this->_needsLayout = 1;
  this->_focusNavGroup = 0;
  this->_enabled = 1;
  this->_paintBorderEnabled = 1;
  this->_paintBackgroundEnabled = 1;
  this->_paintEnabled = 1;
  v6[71](this, 1);
  (*((void (__cdecl **)(vgui::Panel *const, int))this->_vptr_Panel + 72))(this, 8);
  (*((void (__cdecl **)(vgui::Panel *const, int))this->_vptr_Panel + 52))(this, 1);
}

void vgui::Panel::Panel(vgui::Panel *const this)
{
  int v1; // eax
  int v2; // edi
  int v3; // edx
  vgui::Panel **v4; // edx
  vgui::InputSignal **v5; // eax
  vgui::InputSignal **v6; // edi
  int v7; // ecx
  int v8; // edx
  vgui::RepaintSignal **v9; // eax
  vgui::RepaintSignal **v10; // edi
  int v11; // edx
  int v12; // edx
  vgui::FocusChangeSignal **v13; // eax
  vgui::FocusChangeSignal **v14; // edi
  int v15; // edx
  int v16; // [esp+2Ch] [ebp-10h]

  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Panel + 2);
  this->_childDar._count = 0;
  this->_childDar._capacity = 0;
  this->_childDar._data = 0;
  v1 = operator new[](0x10u);
  if ( !v1 )
    goto LABEL_26;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  v2 = this->_childDar._count;
  this->_childDar._capacity = 4;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(v1 + 4 * v3) = this->_childDar._data[v3];
      ++v3;
    }
    while ( v3 < this->_childDar._count );
  }
  v4 = this->_childDar._data;
  if ( v4 )
  {
    v16 = v1;
    operator delete[]((VFontData *const)v4);
    v1 = v16;
  }
  this->_childDar._data = (vgui::Panel **)v1;
  this->_inputSignalDar._count = 0;
  this->_inputSignalDar._capacity = 0;
  this->_inputSignalDar._data = 0;
  v5 = (vgui::InputSignal **)operator new[](0x10u);
  v6 = v5;
  if ( !v5 )
    goto LABEL_26;
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v7 = this->_inputSignalDar._count;
  this->_inputSignalDar._capacity = 4;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      v5[v8] = this->_inputSignalDar._data[v8];
      ++v8;
    }
    while ( v8 < this->_inputSignalDar._count );
  }
  if ( this->_inputSignalDar._data )
    operator delete[]((VFontData *const)this->_inputSignalDar._data);
  this->_inputSignalDar._data = v6;
  this->_repaintSignalDar._count = 0;
  this->_repaintSignalDar._capacity = 0;
  this->_repaintSignalDar._data = 0;
  v9 = (vgui::RepaintSignal **)operator new[](0x10u);
  v10 = v9;
  if ( !v9 )
    goto LABEL_26;
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v11 = this->_repaintSignalDar._count;
  this->_repaintSignalDar._capacity = 4;
  if ( v11 > 0 )
  {
    v12 = 0;
    do
    {
      v9[v12] = this->_repaintSignalDar._data[v12];
      ++v12;
    }
    while ( v12 < this->_repaintSignalDar._count );
  }
  if ( this->_repaintSignalDar._data )
    operator delete[]((VFontData *const)this->_repaintSignalDar._data);
  this->_focusChangeSignalDar._count = 0;
  this->_focusChangeSignalDar._capacity = 0;
  this->_repaintSignalDar._data = v10;
  this->_focusChangeSignalDar._data = 0;
  v13 = (vgui::FocusChangeSignal **)operator new[](0x10u);
  v14 = v13;
  if ( !v13 )
LABEL_26:
    exit(0);
  *v13 = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  this->_focusChangeSignalDar._capacity = 4;
  if ( this->_focusChangeSignalDar._count > 0 )
  {
    v15 = 0;
    do
    {
      v13[v15] = this->_focusChangeSignalDar._data[v15];
      ++v15;
    }
    while ( v15 < this->_focusChangeSignalDar._count );
  }
  if ( this->_focusChangeSignalDar._data )
    operator delete[]((VFontData *const)this->_focusChangeSignalDar._data);
  this->_focusChangeSignalDar._data = v14;
  vgui::Color::Color(&this->_fgColor);
  vgui::Color::Color(&this->_bgColor);
  vgui::Panel::init(this, 0, 0, 64, 64);
}

void vgui::Panel::Panel(vgui::Panel *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // edx
  int v7; // edx
  vgui::Panel **v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  vgui::InputSignal **v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  vgui::RepaintSignal **v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  vgui::FocusChangeSignal **v20; // edx
  int v21; // [esp+14h] [ebp-28h]
  int v22; // [esp+14h] [ebp-28h]
  int v23; // [esp+14h] [ebp-28h]
  int v24; // [esp+14h] [ebp-28h]

  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::Panel + 2);
  this->_childDar._count = 0;
  this->_childDar._capacity = 0;
  this->_childDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    goto LABEL_26;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_childDar._count;
  this->_childDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_childDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_childDar._count );
  }
  v8 = this->_childDar._data;
  if ( v8 )
  {
    v21 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v21;
  }
  this->_childDar._data = (vgui::Panel **)v5;
  this->_inputSignalDar._count = 0;
  this->_inputSignalDar._capacity = 0;
  this->_inputSignalDar._data = 0;
  v9 = operator new[](0x10u);
  if ( !v9 )
    goto LABEL_26;
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = 0;
  v10 = this->_inputSignalDar._count;
  this->_inputSignalDar._capacity = 4;
  if ( v10 > 0 )
  {
    v11 = 0;
    do
    {
      *(_DWORD *)(v9 + 4 * v11) = this->_inputSignalDar._data[v11];
      ++v11;
    }
    while ( v11 < this->_inputSignalDar._count );
  }
  v12 = this->_inputSignalDar._data;
  if ( v12 )
  {
    v22 = v9;
    operator delete[]((VFontData *const)v12);
    v9 = v22;
  }
  this->_inputSignalDar._data = (vgui::InputSignal **)v9;
  this->_repaintSignalDar._count = 0;
  this->_repaintSignalDar._capacity = 0;
  this->_repaintSignalDar._data = 0;
  v13 = operator new[](0x10u);
  if ( !v13 )
    goto LABEL_26;
  *(_DWORD *)v13 = 0;
  *(_DWORD *)(v13 + 4) = 0;
  *(_DWORD *)(v13 + 8) = 0;
  *(_DWORD *)(v13 + 12) = 0;
  v14 = this->_repaintSignalDar._count;
  this->_repaintSignalDar._capacity = 4;
  if ( v14 > 0 )
  {
    v15 = 0;
    do
    {
      *(_DWORD *)(v13 + 4 * v15) = this->_repaintSignalDar._data[v15];
      ++v15;
    }
    while ( v15 < this->_repaintSignalDar._count );
  }
  v16 = this->_repaintSignalDar._data;
  if ( v16 )
  {
    v23 = v13;
    operator delete[]((VFontData *const)v16);
    v13 = v23;
  }
  this->_repaintSignalDar._data = (vgui::RepaintSignal **)v13;
  this->_focusChangeSignalDar._count = 0;
  this->_focusChangeSignalDar._capacity = 0;
  this->_focusChangeSignalDar._data = 0;
  v17 = operator new[](0x10u);
  if ( !v17 )
LABEL_26:
    exit(0);
  *(_DWORD *)v17 = 0;
  *(_DWORD *)(v17 + 4) = 0;
  *(_DWORD *)(v17 + 8) = 0;
  *(_DWORD *)(v17 + 12) = 0;
  v18 = this->_focusChangeSignalDar._count;
  this->_focusChangeSignalDar._capacity = 4;
  if ( v18 > 0 )
  {
    v19 = 0;
    do
    {
      *(_DWORD *)(v17 + 4 * v19) = this->_focusChangeSignalDar._data[v19];
      ++v19;
    }
    while ( v19 < this->_focusChangeSignalDar._count );
  }
  v20 = this->_focusChangeSignalDar._data;
  if ( v20 )
  {
    v24 = v17;
    operator delete[]((VFontData *const)v20);
    v17 = v24;
  }
  this->_focusChangeSignalDar._data = (vgui::FocusChangeSignal **)v17;
  vgui::Color::Color(&this->_fgColor);
  vgui::Color::Color(&this->_bgColor);
  vgui::Panel::init(this, x, y, wide, tall);
}

