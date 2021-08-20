#include <VGUI_App.h>

void vgui::App::externalTick(vgui::App *const this)
{
  (*((void (**)(void))this->_vptr_App + 54))();
}

void vgui::App::run(vgui::App *const this)
{
  this->_running = 1;
  do
    (*((void (__cdecl **)(vgui::App *const))this->_vptr_App + 54))(this);
  while ( this->_running );
  (*((void (__cdecl **)(vgui::App *const, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->_vptr_App + 15))(
    this,
    0,
    0,
    0,
    0,
    0);
}

void vgui::App::stop(vgui::App *const this)
{
  this->_running = 0;
}

void vgui::App::surfaceBaseDeleted(vgui::App *const this, vgui::SurfaceBase *surfaceBase)
{
  int v2; // ecx
  vgui::SurfaceBase **v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  vgui::SurfaceBase **v7; // ecx

  v2 = this->_surfaceBaseDar._count;
  if ( v2 > 0 )
  {
    v3 = this->_surfaceBaseDar._data;
    v4 = 0;
    if ( surfaceBase == *v3 )
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
          v5 = this->_surfaceBaseDar._count - 1;
          if ( v4 >= v5 )
            break;
          v3 = this->_surfaceBaseDar._data;
        }
      }
      this->_surfaceBaseDar._count = v5;
    }
    else
    {
      while ( ++v4 != v2 )
      {
        if ( surfaceBase == v3[v4] )
        {
          if ( v4 < 0 )
            break;
          goto LABEL_8;
        }
      }
    }
  }
  this->_mouseFocus = 0;
  this->_mouseCapture = 0;
  this->_keyFocus = 0;
}

void vgui::App::internalCursorMoved(vgui::App *const this, int x, int y, vgui::SurfaceBase *surfaceBase)
{
  vgui::SurfaceBase *v4; // ebx
  int v5; // eax
  vgui::Panel *v6; // eax

  v4 = surfaceBase;
  v5 = (*surfaceBase->_vptr_SurfaceBase)(surfaceBase);
  (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v5 + 136))(v5, &x, &y);
  if ( !this->_buildMode )
  {
    (*((void (__cdecl **)(vgui::App *const, int, int, vgui::SurfaceBase *))this->_vptr_App + 49))(this, x, y, v4);
    v6 = this->_mouseFocus;
    if ( v6 )
      (*((void (__cdecl **)(vgui::Panel *, int, int))v6->_vptr_Panel + 114))(this->_mouseFocus, x, y);
  }
}

bool vgui::App::wasMousePressed(vgui::App *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  return this->_mousePressed[code];
}

bool vgui::App::wasMouseDoublePressed(vgui::App *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  return this->_mouseDoublePressed[code];
}

bool vgui::App::isMouseDown(vgui::App *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  return this->_mouseDown[code];
}

bool vgui::App::wasMouseReleased(vgui::App *const this, vgui::MouseCode code, vgui::Panel *panel)
{
  return this->_mouseReleased[code];
}

bool vgui::App::wasKeyPressed(vgui::App *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  bool result; // al

  if ( !panel || (result = 0, this->_keyFocus == panel) )
    result = this->_keyPressed[code];
  return result;
}

bool vgui::App::isKeyDown(vgui::App *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  bool result; // al

  if ( !panel || (result = 0, this->_keyFocus == panel) )
    result = this->_keyDown[code];
  return result;
}

bool vgui::App::wasKeyTyped(vgui::App *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  bool result; // al

  if ( !panel || (result = 0, this->_keyFocus == panel) )
    result = this->_keyTyped[code];
  return result;
}

bool vgui::App::wasKeyReleased(vgui::App *const this, vgui::KeyCode code, vgui::Panel *panel)
{
  bool result; // al

  if ( !panel || (result = 0, this->_keyFocus == panel) )
    result = this->_keyReleased[code];
  return result;
}

void vgui::App::setMouseCapture(vgui::App *const this, vgui::Panel *panel)
{
  vgui::Panel *v2; // eax

  if ( panel )
  {
    (*((void (__cdecl **)(vgui::SurfaceBase *, int))panel->_surfaceBase->_vptr_SurfaceBase + 29))(
      panel->_surfaceBase,
      1);
LABEL_3:
    this->_mouseCapture = panel;
    return;
  }
  v2 = this->_mouseCapture;
  if ( !v2 )
    goto LABEL_3;
  (*((void (__cdecl **)(vgui::SurfaceBase *, _DWORD))v2->_surfaceBase->_vptr_SurfaceBase + 29))(v2->_surfaceBase, 0);
  this->_mouseCapture = 0;
}

void vgui::App::requestFocus(vgui::App *const this, vgui::Panel *panel)
{
  this->_wantedKeyFocus = panel;
}

void vgui::App::repaintAll(vgui::App *const this)
{
  int v1; // ebx
  int v2; // eax
  vgui::SurfaceBase *v3; // edi
  void (__cdecl *v4)(vgui::SurfaceBase *, int); // ebp
  int v5; // eax
  int v6; // eax

  if ( this->_surfaceBaseDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v6 = (*this->_surfaceBaseDar._data[v1]->_vptr_SurfaceBase)(this->_surfaceBaseDar._data[v1]);
      (*(void (__cdecl **)(int))(*(_DWORD *)v6 + 52))(v6);
      if ( this->_surfaceBaseDar._count <= v1 )
      {
        v2 = 1179403647;
        v3 = 0;
        v4 = (void (__cdecl *)(vgui::SurfaceBase *, int))MEMORY[0x464C45EF];
      }
      else
      {
        v3 = this->_surfaceBaseDar._data[v1];
        v2 = (int)v3->_vptr_SurfaceBase;
        v4 = (void (__cdecl *)(vgui::SurfaceBase *, int))*((_DWORD *)v3->_vptr_SurfaceBase + 28);
      }
      ++v1;
      v5 = (*(int (__cdecl **)(vgui::SurfaceBase *))v2)(v3);
      v4(v3, v5);
    }
    while ( this->_surfaceBaseDar._count > v1 );
  }
}

void vgui::App::setScheme(vgui::App *const this, vgui::Scheme *scheme)
{
  if ( scheme )
  {
    this->_scheme = scheme;
    (*((void (**)(void))this->_vptr_App + 19))();
  }
}

void vgui::App::enableBuildMode(vgui::App *const this)
{
  this->_wantedBuildMode = 1;
}

char vgui::App::getKeyCodeChar(vgui::App *const this, vgui::KeyCode code, bool shifted)
{
  char result; // al

  if ( shifted )
    result = 69;
  else
    result = 127;
  return result;
}

void vgui::App::getKeyCodeText(vgui::App *const this, vgui::KeyCode code, char *buf, int buflen)
{
  int v4; // edx
  char v5; // al

  if ( buf && buflen > 0 )
  {
    v4 = 0;
    *buf = 76;
    do
    {
      if ( ++v4 == buflen )
        break;
      v5 = *(_BYTE *)(v4 + 2);
      buf[v4] = v5;
    }
    while ( v5 );
  }
}

void vgui::App::setMouseArena(vgui::App *const this, vgui::Panel *panel)
{
  this->_mouseArenaPanel = panel;
}

void vgui::App::setMouseArena(vgui::App *const this, int x0, int y0, int x1, int y1, bool enabled)
{
  (*((void (__cdecl **)(vgui::App *const, _DWORD))this->_vptr_App + 16))(this, 0);
  (*((void (__cdecl **)(vgui::App *const, int, int, int, int, bool))this->_vptr_App + 30))(
    this,
    x0,
    y0,
    x1,
    y1,
    enabled);
}

void vgui::App::setCursorOveride(vgui::App *const this, vgui::Cursor *cursor)
{
  this->_cursorOveride = cursor;
}

void vgui::App::setMinimumTickMillisInterval(vgui::App *const this, int interval)
{
  this->_minimumTickMillisInterval = interval;
}

void vgui::App::setMouseFocus(vgui::App *const this, vgui::Panel *newMouseFocus)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // edx

  v2 = newMouseFocus;
  v3 = this->_mouseFocus;
  if ( v3 != newMouseFocus )
  {
    this->_oldMouseFocus = v3;
    this->_mouseFocus = newMouseFocus;
    if ( v3 )
    {
      (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 116))(v3);
      v2 = this->_mouseFocus;
    }
    if ( v2 )
      (*((void (__cdecl **)(vgui::Panel *))v2->_vptr_Panel + 115))(v2);
  }
}

void vgui::App::init(vgui::App *const this)
{
  vgui::Scheme *v1; // esi
  int (**v2)(...); // eax
  int v3; // eax
  int v4; // ecx
  bool *v5; // eax
  unsigned int v6; // edx
  bool *v7; // eax
  bool *v8; // eax
  int v9; // edx
  unsigned int v10; // ecx
  bool *v11; // eax
  bool *v12; // eax
  int v13; // edx
  unsigned int v14; // ecx
  bool *v15; // eax
  bool *v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  bool *v19; // eax

  this->_externalMain = 0;
  this->_running = 0;
  this->_keyFocus = 0;
  this->_oldMouseFocus = 0;
  this->_mouseFocus = 0;
  this->_mouseCapture = 0;
  this->_wantedKeyFocus = 0;
  vgui::App::_instance = this;
  v1 = (vgui::Scheme *)operator new(0xE0u);
  vgui::Scheme::Scheme(v1);
  this->_mouseArenaPanel = 0;
  v2 = this->_vptr_App;
  this->_scheme = v1;
  this->_buildMode = 0;
  this->_wantedBuildMode = 0;
  this->_cursorOveride = 0;
  v3 = v2[23](this);
  this->_minimumTickMillisInterval = 50;
  v4 = 103;
  *(_WORD *)this->_mousePressed = 0;
  this->_mousePressed[2] = 0;
  *(_WORD *)this->_mouseDoublePressed = 0;
  this->_mouseDoublePressed[2] = 0;
  this->_nextTickMillis = v3;
  v5 = this->_keyPressed;
  *(_WORD *)this->_mouseDown = 0;
  this->_mouseDown[2] = 0;
  *(_WORD *)this->_mouseReleased = 0;
  this->_mouseReleased[2] = 0;
  if ( (((_BYTE)this + 52) & 1) != 0 )
  {
    v5 = &this->_keyPressed[1];
    v4 = 102;
    this->_keyPressed[0] = 0;
    if ( (((_BYTE)this + 53) & 2) == 0 )
      goto LABEL_3;
LABEL_57:
    *(_WORD *)v5 = 0;
    v4 -= 2;
    v5 += 2;
    goto LABEL_3;
  }
  if ( ((uint8_t)v5 & 2) != 0 )
    goto LABEL_57;
LABEL_3:
  v6 = 0;
  do
  {
    *(_DWORD *)&v5[v6] = 0;
    *(_DWORD *)&v5[v6 + 4] = 0;
    *(_DWORD *)&v5[v6 + 8] = 0;
    *(_DWORD *)&v5[v6 + 12] = 0;
    v6 += 16;
  }
  while ( v6 < (v4 & 0xFFFFFFF0) );
  v7 = &v5[v6];
  if ( (v4 & 8) != 0 )
  {
    *(_DWORD *)v7 = 0;
    *((_DWORD *)v7 + 1) = 0;
    v7 += 8;
  }
  if ( (v4 & 4) != 0 )
  {
    *(_DWORD *)v7 = 0;
    v7 += 4;
  }
  if ( (v4 & 2) != 0 )
  {
    *(_WORD *)v7 = 0;
    v7 += 2;
  }
  if ( (v4 & 1) != 0 )
    *v7 = 0;
  v8 = this->_keyTyped;
  v9 = 103;
  if ( (((_BYTE)this - 101) & 1) != 0 )
  {
    this->_keyTyped[0] = 0;
    v8 = &this->_keyTyped[1];
    v9 = 102;
  }
  if ( ((uint8_t)v8 & 2) != 0 )
  {
    *(_WORD *)v8 = 0;
    v9 -= 2;
    v8 += 2;
  }
  v10 = 0;
  do
  {
    *(_DWORD *)&v8[v10] = 0;
    *(_DWORD *)&v8[v10 + 4] = 0;
    *(_DWORD *)&v8[v10 + 8] = 0;
    *(_DWORD *)&v8[v10 + 12] = 0;
    v10 += 16;
  }
  while ( v10 < (v9 & 0xFFFFFFF0) );
  v11 = &v8[v10];
  if ( (v9 & 8) != 0 )
  {
    *(_DWORD *)v11 = 0;
    *((_DWORD *)v11 + 1) = 0;
    v11 += 8;
  }
  if ( (v9 & 4) != 0 )
  {
    *(_DWORD *)v11 = 0;
    v11 += 4;
  }
  if ( (v9 & 2) != 0 )
  {
    *(_WORD *)v11 = 0;
    v11 += 2;
  }
  if ( (v9 & 1) != 0 )
    *v11 = 0;
  v12 = this->_keyDown;
  v13 = 103;
  if ( (((_BYTE)this + 2) & 1) != 0 )
  {
    this->_keyDown[0] = 0;
    v12 = &this->_keyDown[1];
    v13 = 102;
  }
  if ( ((uint8_t)v12 & 2) != 0 )
  {
    *(_WORD *)v12 = 0;
    v13 -= 2;
    v12 += 2;
  }
  v14 = 0;
  do
  {
    *(_DWORD *)&v12[v14] = 0;
    *(_DWORD *)&v12[v14 + 4] = 0;
    *(_DWORD *)&v12[v14 + 8] = 0;
    *(_DWORD *)&v12[v14 + 12] = 0;
    v14 += 16;
  }
  while ( v14 < (v13 & 0xFFFFFFF0) );
  v15 = &v12[v14];
  if ( (v13 & 8) != 0 )
  {
    *(_DWORD *)v15 = 0;
    *((_DWORD *)v15 + 1) = 0;
    v15 += 8;
  }
  if ( (v13 & 4) != 0 )
  {
    *(_DWORD *)v15 = 0;
    v15 += 4;
  }
  if ( (v13 & 2) != 0 )
  {
    *(_WORD *)v15 = 0;
    v15 += 2;
  }
  if ( (v13 & 1) != 0 )
    *v15 = 0;
  v16 = this->_keyReleased;
  v17 = 103;
  if ( (((_BYTE)this + 105) & 1) != 0 )
  {
    this->_keyReleased[0] = 0;
    v16 = &this->_keyReleased[1];
    v17 = 102;
  }
  if ( ((uint8_t)v16 & 2) != 0 )
  {
    *(_WORD *)v16 = 0;
    v17 -= 2;
    v16 += 2;
  }
  v18 = 0;
  do
  {
    *(_DWORD *)&v16[v18 + 4] = 0;
    *(_DWORD *)&v16[v18 + 8] = 0;
    *(_DWORD *)&v16[v18] = 0;
    *(_DWORD *)&v16[v18 + 12] = 0;
    v18 += 16;
  }
  while ( v18 < (v17 & 0xFFFFFFF0) );
  v19 = &v16[v18];
  if ( (v17 & 8) != 0 )
  {
    *(_DWORD *)v19 = 0;
    *((_DWORD *)v19 + 1) = 0;
    v19 += 8;
  }
  if ( (v17 & 4) != 0 )
  {
    *(_DWORD *)v19 = 0;
    v19 += 4;
  }
  if ( (v17 & 2) != 0 )
  {
    *(_WORD *)v19 = 0;
    v19 += 2;
  }
  if ( (v17 & 1) != 0 )
    *v19 = 0;
}

void vgui::App::reset(vgui::App *const this)
{
  void (__cdecl *v1)(vgui::App *const, vgui::Scheme *); // esi
  vgui::Scheme *v2; // edi

  this->_mouseArenaPanel = 0;
  this->_tickSignalDar._count = 0;
  this->_keyFocus = 0;
  this->_mouseFocus = 0;
  this->_mouseCapture = 0;
  this->_wantedKeyFocus = 0;
  this->_buildMode = 0;
  this->_wantedBuildMode = 0;
  vgui::Font_Reset();
  v1 = (void (__cdecl *)(vgui::App *const, vgui::Scheme *))*((_DWORD *)this->_vptr_App + 20);
  v2 = (vgui::Scheme *)operator new(0xE0u);
  vgui::Scheme::Scheme(v2);
  v1(this, v2);
}

void vgui::App::updateMouseFocus(vgui::App *const this, int x, int y, vgui::SurfaceBase *surfaceBase)
{
  int (**v4)(...); // edx
  int v5; // eax
  int v6; // eax
  vgui::Panel *xa; // [esp+34h] [ebp+8h]

  if ( this->_mouseCapture )
  {
    v4 = this->_vptr_App;
    xa = this->_mouseCapture;
LABEL_3:
    v4[50](this, xa);
    return;
  }
  if ( (*((uint8_t (__cdecl **)(vgui::SurfaceBase *, int, int))surfaceBase->_vptr_SurfaceBase + 14))(
         surfaceBase,
         x,
         y) )
  {
    v5 = (*surfaceBase->_vptr_SurfaceBase)(surfaceBase);
    v6 = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)v5 + 132))(v5, x, y);
    if ( v6 )
    {
      v4 = this->_vptr_App;
      xa = (vgui::Panel *)v6;
      goto LABEL_3;
    }
  }
}

void vgui::App::internalMousePressed(vgui::App *const this, vgui::MouseCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // eax

  this->_mousePressed[code] = 1;
  this->_mouseDown[code] = 1;
  if ( !this->_buildMode )
  {
    v3 = this->_mouseFocus;
    if ( v3 )
      (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 117))(v3);
  }
}

void vgui::App::internalMouseDoublePressed(vgui::App *const this, vgui::MouseCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // eax

  this->_mouseDoublePressed[code] = 1;
  if ( !this->_buildMode )
  {
    v3 = this->_mouseFocus;
    if ( v3 )
      (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 118))(v3);
  }
}

void vgui::App::internalMouseReleased(vgui::App *const this, vgui::MouseCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // eax

  this->_mouseReleased[code] = 1;
  this->_mouseDown[code] = 0;
  if ( !this->_buildMode )
  {
    v3 = this->_mouseFocus;
    if ( v3 )
      (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 119))(v3);
  }
}

void vgui::App::internalMouseWheeled(vgui::App *const this, int delta, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // eax

  if ( !this->_buildMode )
  {
    v3 = this->_keyFocus;
    if ( v3 )
      (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 120))(v3);
  }
}

void vgui::App::internalKeyPressed(vgui::App *const this, vgui::KeyCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // edx

  if ( code >= KEY_0 && code <= KEY_F12 )
  {
    this->_keyPressed[code] = 1;
    this->_keyDown[code] = 1;
    if ( !this->_buildMode )
    {
      v3 = this->_keyFocus;
      if ( v3 )
        (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 121))(v3);
    }
  }
}

void vgui::App::internalKeyTyped(vgui::App *const this, vgui::KeyCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // edx

  if ( code >= KEY_0 && code <= KEY_F12 )
  {
    this->_keyTyped[code] = 1;
    if ( !this->_buildMode )
    {
      v3 = this->_keyFocus;
      if ( v3 )
        (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 122))(v3);
    }
  }
}

void vgui::App::internalKeyReleased(vgui::App *const this, vgui::KeyCode code, vgui::SurfaceBase *surfaceBase)
{
  vgui::Panel *v3; // edx

  if ( code >= KEY_0 && code <= KEY_F12 )
  {
    this->_keyReleased[code] = 1;
    this->_keyDown[code] = 0;
    if ( !this->_buildMode )
    {
      v3 = this->_keyFocus;
      if ( v3 )
        (*((void (__cdecl **)(vgui::Panel *))v3->_vptr_Panel + 123))(v3);
    }
  }
}

void vgui::App::start(vgui::App *const this)
{
  int v1; // ebx
  vgui::SurfaceBase *v2; // eax

  if ( !this->_externalMain )
  {
    (*((void (__cdecl **)(vgui::App *const))this->_vptr_App + 39))(this);
    if ( this->_surfaceBaseDar._count > 0 )
    {
      v1 = 0;
      do
      {
        v2 = this->_surfaceBaseDar._data[v1++];
        (*((void (__cdecl **)(vgui::SurfaceBase *))v2->_vptr_SurfaceBase + 10))(v2);
      }
      while ( v1 < this->_surfaceBaseDar._count );
    }
  }
}

void vgui::App::internalTick(vgui::App *const this)
{
  int v1; // ebp
  char v2; // bl
  int v3; // edi
  vgui::SurfaceBase *v4; // eax
  vgui::SurfaceBase *v5; // eax
  vgui::Panel *v6; // eax
  int v7; // ebx
  vgui::TickSignal *v8; // eax
  void *v9; // eax
  bool *v10; // eax
  int v11; // ecx
  unsigned int v12; // edx
  bool *v13; // eax
  bool *v14; // eax
  int v15; // edx
  unsigned int v16; // ecx
  bool *v17; // eax
  bool *v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  bool *v21; // eax
  int v22; // edx
  int v23; // ebx
  vgui::Panel *v24; // eax
  vgui::Panel *v25; // ecx
  int v26; // ebx
  int v27; // eax
  vgui::SurfaceBase *v28; // eax
  vgui::Panel *v29; // eax
  int (__cdecl ***v30)(_DWORD); // eax
  int v31; // eax
  int v32; // eax
  int v33; // [esp+20h] [ebp-3Ch] BYREF
  int v34; // [esp+24h] [ebp-38h] BYREF
  int v35; // [esp+28h] [ebp-34h] BYREF
  int v36; // [esp+2Ch] [ebp-30h] BYREF
  int v37; // [esp+30h] [ebp-2Ch] BYREF
  int v38; // [esp+34h] [ebp-28h] BYREF
  int v39; // [esp+38h] [ebp-24h] BYREF
  int v40[8]; // [esp+3Ch] [ebp-20h] BYREF

  if ( (*((int (__cdecl **)(vgui::App *const))this->_vptr_App + 23))(this) >= this->_nextTickMillis )
  {
    (*((void (__cdecl **)(vgui::App *const))this->_vptr_App + 53))(this);
    (*((void (__cdecl **)(vgui::App *const, int *, int *))this->_vptr_App + 13))(this, &v37, &v38);
    if ( this->_surfaceBaseDar._count <= 0 )
      goto LABEL_82;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    do
    {
      (*((void (__cdecl **)(vgui::App *const, int, int, vgui::SurfaceBase *))this->_vptr_App + 49))(
        this,
        v37,
        v38,
        this->_surfaceBaseDar._data[v1]);
      v4 = 0;
      if ( this->_surfaceBaseDar._count > v3 )
        v4 = this->_surfaceBaseDar._data[v1];
      if ( (*((uint8_t (__cdecl **)(vgui::SurfaceBase *, int, int))v4->_vptr_SurfaceBase + 14))(v4, v37, v38) )
        v2 = 1;
      v5 = 0;
      if ( this->_surfaceBaseDar._count > v3 )
        v5 = this->_surfaceBaseDar._data[v1];
      ++v3;
      ++v1;
      (*((void (__cdecl **)(vgui::SurfaceBase *, int, int))v5->_vptr_SurfaceBase + 7))(v5, v37, v38);
    }
    while ( v3 < this->_surfaceBaseDar._count );
    if ( !v2 )
LABEL_82:
      (*((void (__cdecl **)(vgui::App *const, _DWORD))this->_vptr_App + 50))(this, 0);
    v6 = this->_mouseFocus;
    if ( v6 )
      (*((void (__cdecl **)(vgui::Panel *))v6->_vptr_Panel + 126))(this->_mouseFocus);
    if ( this->_tickSignalDar._count > 0 )
    {
      v7 = 0;
      do
      {
        v8 = this->_tickSignalDar._data[v7++];
        (*v8->_vptr_TickSignal)(v8);
      }
      while ( v7 < this->_tickSignalDar._count );
    }
    v9 = this->_keyFocus;
    if ( v9 )
      goto LABEL_18;
    if ( this->_surfaceBaseDar._count > 0 )
      v9 = *this->_surfaceBaseDar._data;
    v32 = (**(int (__cdecl ***)(void *))v9)(v9);
    (*(void (__cdecl **)(int))(*(_DWORD *)v32 + 164))(v32);
    v9 = this->_keyFocus;
    if ( v9 )
LABEL_18:
      (*(void (__cdecl **)(void *))(*(_DWORD *)v9 + 496))(v9);
    v10 = this->_keyPressed;
    v11 = 103;
    this->_mousePressed[0] = 0;
    this->_mouseDoublePressed[0] = 0;
    this->_mouseReleased[0] = 0;
    this->_mousePressed[1] = 0;
    this->_mouseDoublePressed[1] = 0;
    this->_mouseReleased[1] = 0;
    this->_mousePressed[2] = 0;
    this->_mouseDoublePressed[2] = 0;
    this->_mouseReleased[2] = 0;
    if ( (((_BYTE)this + 52) & 1) != 0 )
    {
      this->_keyPressed[0] = 0;
      v10 = &this->_keyPressed[1];
      v11 = 102;
    }
    if ( ((uint8_t)v10 & 2) != 0 )
    {
      *(_WORD *)v10 = 0;
      v11 -= 2;
      v10 += 2;
    }
    v12 = 0;
    do
    {
      *(_DWORD *)&v10[v12 + 4] = 0;
      *(_DWORD *)&v10[v12] = 0;
      *(_DWORD *)&v10[v12 + 8] = 0;
      *(_DWORD *)&v10[v12 + 12] = 0;
      v12 += 16;
    }
    while ( v12 < (v11 & 0xFFFFFFF0) );
    v13 = &v10[v12];
    if ( (v11 & 8) != 0 )
    {
      *(_DWORD *)v13 = 0;
      *((_DWORD *)v13 + 1) = 0;
      v13 += 8;
    }
    if ( (v11 & 4) != 0 )
    {
      *(_DWORD *)v13 = 0;
      v13 += 4;
    }
    if ( (v11 & 2) != 0 )
    {
      *(_WORD *)v13 = 0;
      v13 += 2;
    }
    if ( (v11 & 1) != 0 )
      *v13 = 0;
    v14 = this->_keyTyped;
    v15 = 103;
    if ( (((_BYTE)this - 101) & 1) != 0 )
    {
      this->_keyTyped[0] = 0;
      v14 = &this->_keyTyped[1];
      v15 = 102;
    }
    if ( ((uint8_t)v14 & 2) != 0 )
    {
      *(_WORD *)v14 = 0;
      v15 -= 2;
      v14 += 2;
    }
    v16 = 0;
    do
    {
      *(_DWORD *)&v14[v16 + 4] = 0;
      *(_DWORD *)&v14[v16] = 0;
      *(_DWORD *)&v14[v16 + 8] = 0;
      *(_DWORD *)&v14[v16 + 12] = 0;
      v16 += 16;
    }
    while ( v16 < (v15 & 0xFFFFFFF0) );
    v17 = &v14[v16];
    if ( (v15 & 8) != 0 )
    {
      *(_DWORD *)v17 = 0;
      *((_DWORD *)v17 + 1) = 0;
      v17 += 8;
    }
    if ( (v15 & 4) != 0 )
    {
      *(_DWORD *)v17 = 0;
      v17 += 4;
    }
    if ( (v15 & 2) != 0 )
    {
      *(_WORD *)v17 = 0;
      v17 += 2;
    }
    if ( (v15 & 1) != 0 )
      *v17 = 0;
    v18 = this->_keyReleased;
    v19 = 103;
    if ( (((_BYTE)this + 105) & 1) != 0 )
    {
      this->_keyReleased[0] = 0;
      v18 = &this->_keyReleased[1];
      v19 = 102;
    }
    if ( ((uint8_t)v18 & 2) != 0 )
    {
      *(_WORD *)v18 = 0;
      v19 -= 2;
      v18 += 2;
    }
    v20 = 0;
    do
    {
      *(_DWORD *)&v18[v20 + 4] = 0;
      *(_DWORD *)&v18[v20] = 0;
      *(_DWORD *)&v18[v20 + 8] = 0;
      *(_DWORD *)&v18[v20 + 12] = 0;
      v20 += 16;
    }
    while ( v20 < (v19 & 0xFFFFFFF0) );
    v21 = &v18[v20];
    if ( (v19 & 8) != 0 )
    {
      *(_DWORD *)v21 = 0;
      *((_DWORD *)v21 + 1) = 0;
      v21 += 8;
    }
    if ( (v19 & 4) != 0 )
    {
      *(_DWORD *)v21 = 0;
      v21 += 4;
    }
    if ( (v19 & 2) != 0 )
    {
      *(_WORD *)v21 = 0;
      v21 += 2;
    }
    if ( (v19 & 1) != 0 )
      *v21 = 0;
    v22 = this->_surfaceBaseDar._count;
    v23 = 0;
    if ( v22 > 0 )
    {
      while ( !(*((uint8_t (__cdecl **)(vgui::SurfaceBase *))this->_surfaceBaseDar._data[v23]->_vptr_SurfaceBase
                + 13))(this->_surfaceBaseDar._data[v23]) )
      {
        v22 = this->_surfaceBaseDar._count;
        if ( ++v23 >= v22 )
          goto LABEL_66;
      }
      v22 = this->_surfaceBaseDar._count;
    }
LABEL_66:
    if ( v22 == v23 )
    {
      this->_wantedKeyFocus = 0;
      v24 = 0;
    }
    else
    {
      v24 = this->_wantedKeyFocus;
    }
    v25 = this->_keyFocus;
    if ( v24 != v25 )
    {
      if ( v25 )
      {
        (*((void (__cdecl **)(vgui::Panel *, int))v25->_vptr_Panel + 125))(v25, 1);
        (*((void (__cdecl **)(vgui::Panel *))this->_keyFocus->_vptr_Panel + 12))(this->_keyFocus);
        v24 = this->_wantedKeyFocus;
      }
      if ( v24 )
      {
        (*((void (__cdecl **)(vgui::Panel *, _DWORD))v24->_vptr_Panel + 125))(v24, 0);
        (*((void (__cdecl **)(vgui::Panel *))this->_wantedKeyFocus->_vptr_Panel + 12))(this->_wantedKeyFocus);
        v22 = this->_surfaceBaseDar._count;
        v24 = this->_wantedKeyFocus;
      }
      else
      {
        v22 = this->_surfaceBaseDar._count;
      }
    }
    this->_keyFocus = v24;
    this->_buildMode = this->_wantedBuildMode;
    if ( v22 > 0 )
    {
      v26 = 0;
      do
      {
        v27 = (*this->_surfaceBaseDar._data[v26]->_vptr_SurfaceBase)(this->_surfaceBaseDar._data[v26]);
        (*(void (__cdecl **)(int))(*(_DWORD *)v27 + 352))(v27);
        v28 = 0;
        if ( this->_surfaceBaseDar._count > v26 )
          v28 = this->_surfaceBaseDar._data[v26];
        ++v26;
        (*((void (__cdecl **)(vgui::SurfaceBase *))v28->_vptr_SurfaceBase + 34))(v28);
      }
      while ( v26 < this->_surfaceBaseDar._count );
    }
    v29 = this->_mouseArenaPanel;
    if ( v29 )
    {
      v30 = (int (__cdecl ***)(_DWORD))(*((int (__cdecl **)(vgui::Panel *))v29->_vptr_Panel + 61))(this->_mouseArenaPanel);
      if ( v30 )
      {
        v31 = (**v30)(v30);
        (*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v31 + 4))(v31, &v39, v40);
        (*((void (__cdecl **)(vgui::Panel *, int *, int *, int *, int *))this->_mouseArenaPanel->_vptr_Panel + 14))(
          this->_mouseArenaPanel,
          &v33,
          &v34,
          &v35,
          &v36);
        (*((void (__cdecl **)(vgui::App *const, int, int, int, int, int))this->_vptr_App + 30))(
          this,
          v33 + v39,
          v34 + v40[0],
          v39 + v35,
          v40[0] + v36,
          1);
      }
    }
    this->_nextTickMillis = this->_minimumTickMillisInterval
                          + (*((int (__cdecl **)(vgui::App *const))this->_vptr_App + 23))(this);
  }
}

void vgui::App::surfaceBaseCreated(vgui::App *const this, vgui::SurfaceBase *surfaceBase)
{
  int v2; // ecx
  vgui::Dar<vgui::SurfaceBase*> *v3; // esi
  vgui::SurfaceBase **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::SurfaceBase **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::SurfaceBase **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_surfaceBaseDar._count;
  v3 = &this->_surfaceBaseDar;
  if ( v2 > 0 )
  {
    v4 = this->_surfaceBaseDar._data;
    v5 = 0;
    if ( surfaceBase == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( surfaceBase == v4[v5] )
        return;
    }
  }
  v6 = this->_surfaceBaseDar._capacity;
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
    v14 = (vgui::SurfaceBase **)v10;
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
    v2 = this->_surfaceBaseDar._count;
    this->_surfaceBaseDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_surfaceBaseDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_surfaceBaseDar._data )
    {
      operator delete[](this->_surfaceBaseDar._data);
      v2 = this->_surfaceBaseDar._count;
    }
    v8 = v14;
    this->_surfaceBaseDar._data = v14;
  }
  else
  {
    v8 = this->_surfaceBaseDar._data;
  }
  v8[v2] = surfaceBase;
  ++this->_surfaceBaseDar._count;
}

void vgui::App::addTickSignal(vgui::App *const this, vgui::TickSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::TickSignal*> *v3; // esi
  vgui::TickSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::TickSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::TickSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_tickSignalDar._count;
  v3 = &this->_tickSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_tickSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_tickSignalDar._capacity;
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
    v14 = (vgui::TickSignal **)v10;
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
    v2 = this->_tickSignalDar._count;
    this->_tickSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_tickSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_tickSignalDar._data )
    {
      operator delete[](this->_tickSignalDar._data);
      v2 = this->_tickSignalDar._count;
    }
    v8 = v14;
    this->_tickSignalDar._data = v14;
  }
  else
  {
    v8 = this->_tickSignalDar._data;
  }
  v8[v2] = s;
  ++this->_tickSignalDar._count;
}

void vgui::App::App(vgui::App *const this)
{
  int v1; // eax
  int v2; // edx
  int v3; // edx
  vgui::SurfaceBase **v4; // edx
  vgui::TickSignal **v5; // eax
  vgui::TickSignal **v6; // edi
  int v7; // edx
  int v8; // [esp+1Ch] [ebp-10h]

  this->_vptr_App = (int (**)(...))(&`vtable for'vgui::App + 2);
  this->_surfaceBaseDar._count = 0;
  this->_surfaceBaseDar._capacity = 0;
  this->_surfaceBaseDar._data = 0;
  v1 = operator new[](0x10u);
  if ( !v1 )
    goto LABEL_14;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  v2 = this->_surfaceBaseDar._count;
  this->_surfaceBaseDar._capacity = 4;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(v1 + 4 * v3) = this->_surfaceBaseDar._data[v3];
      ++v3;
    }
    while ( v3 < this->_surfaceBaseDar._count );
  }
  v4 = this->_surfaceBaseDar._data;
  if ( v4 )
  {
    v8 = v1;
    operator delete[]((VFontData *const)v4);
    v1 = v8;
  }
  this->_surfaceBaseDar._data = (vgui::SurfaceBase **)v1;
  this->_tickSignalDar._count = 0;
  this->_tickSignalDar._capacity = 0;
  this->_tickSignalDar._data = 0;
  v5 = (vgui::TickSignal **)operator new[](0x10u);
  v6 = v5;
  if ( !v5 )
LABEL_14:
    exit(0);
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  this->_tickSignalDar._capacity = 4;
  if ( this->_tickSignalDar._count > 0 )
  {
    v7 = 0;
    do
    {
      v5[v7] = this->_tickSignalDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_tickSignalDar._count );
  }
  if ( this->_tickSignalDar._data )
    operator delete[]((VFontData *const)this->_tickSignalDar._data);
  this->_tickSignalDar._data = v6;
  vgui::App::init(this);
}

void vgui::App::App(vgui::App *const this, bool externalMain)
{
  int v2; // eax
  int v3; // edx
  int v4; // edx
  vgui::SurfaceBase **v5; // edx
  vgui::TickSignal **v6; // eax
  vgui::TickSignal **v7; // ebp
  int v8; // eax
  int v9; // edx
  int v10; // [esp+1Ch] [ebp-20h]

  this->_vptr_App = (int (**)(...))(&`vtable for'vgui::App + 2);
  this->_surfaceBaseDar._count = 0;
  this->_surfaceBaseDar._capacity = 0;
  this->_surfaceBaseDar._data = 0;
  v2 = operator new[](0x10u);
  if ( !v2 )
    goto LABEL_14;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  v3 = this->_surfaceBaseDar._count;
  this->_surfaceBaseDar._capacity = 4;
  if ( v3 > 0 )
  {
    v4 = 0;
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = this->_surfaceBaseDar._data[v4];
      ++v4;
    }
    while ( v4 < this->_surfaceBaseDar._count );
  }
  v5 = this->_surfaceBaseDar._data;
  if ( v5 )
  {
    v10 = v2;
    operator delete[]((VFontData *const)v5);
    v2 = v10;
  }
  this->_surfaceBaseDar._data = (vgui::SurfaceBase **)v2;
  this->_tickSignalDar._count = 0;
  this->_tickSignalDar._capacity = 0;
  this->_tickSignalDar._data = 0;
  v6 = (vgui::TickSignal **)operator new[](0x10u);
  v7 = v6;
  if ( !v6 )
LABEL_14:
    exit(0);
  *v6 = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  v8 = this->_tickSignalDar._count;
  this->_tickSignalDar._capacity = 4;
  if ( v8 > 0 )
  {
    v9 = 0;
    do
    {
      v7[v9] = this->_tickSignalDar._data[v9];
      ++v9;
    }
    while ( v9 < this->_tickSignalDar._count );
  }
  if ( this->_tickSignalDar._data )
    operator delete[]((VFontData *const)this->_tickSignalDar._data);
  this->_tickSignalDar._data = v7;
  vgui::App::init(this);
  this->_externalMain = externalMain;
}

void vgui::App::getCursorPos(vgui::App *const this, int *const x, int *const y)
{
  vgui::SurfaceBase *v3; // eax

  v3 = 0;
  if ( this->_surfaceBaseDar._count > 0 )
    v3 = *this->_surfaceBaseDar._data;
  (*((void (__cdecl **)(vgui::SurfaceBase *))v3->_vptr_SurfaceBase + 16))(v3);
}

int vgui::App::getTimeMillis(vgui::App *const this)
{
  timeval tp; // [esp+30h] [ebp-1Ch] BYREF

  gettimeofday(&tp, 0);
  if ( vgui::App::getTimeMillis(void)::secbase )
    return (__int64)((long double)(1000 * (tp.tv_sec - vgui::App::getTimeMillis(void)::secbase))
                   + (long double)tp.tv_usec / 1000.0);
  vgui::App::getTimeMillis(void)::secbase = tp.tv_sec;
  return (int)(double)((long double)tp.tv_usec / 1000000.0);
}

int vgui::App::getClipboardTextCount(vgui::App *const this)
{
  return 0;
}

int vgui::App::getClipboardText(vgui::App *const this, int offset, char *buf, int bufLen)
{
  return 0;
}

bool vgui::App::setRegistryString(vgui::App *const this, const char *key, const char *value)
{
  return 0;
}

bool vgui::App::getRegistryString(vgui::App *const this, const char *key, char *value, int valueLen)
{
  return 0;
}

bool vgui::App::setRegistryInteger(vgui::App *const this, const char *key, int value)
{
  return 0;
}

bool vgui::App::getRegistryInteger(vgui::App *const this, const char *key, int *const value)
{
  return 0;
}

