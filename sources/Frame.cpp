#include <VGUI_Frame.h>

#include <VGUI_FrameSignal.h>
#include <VGUI_Button.h>

void vgui::Frame::setInternal(bool state)
{
  _internal = state;
}

bool vgui::Frame::isInternal()
{
  return _internal;
}

void vgui::Frame::setMoveable(bool state)
{
  _moveable = state;
}

void vgui::Frame::setSizeable(bool state)
{
  _sizeable = state;
}

bool vgui::Frame::isMoveable()
{
  return _moveable;
}

bool vgui::Frame::isSizeable()
{
  return _sizeable;
}

void vgui::Frame::fireClosingSignal()
{
  for (auto i = 0; i < _frameSignalDar.getCount(); ++i)
    _frameSignalDar[i]->closing(this);
}

void vgui::Frame::fireMinimizingSignal()
{
  for (auto i = 0; i < _frameSignalDar.getCount(); ++i)
    _frameSignalDar[i]->minimizing(this, false);
}

void vgui::Frame::setMenuButtonVisible(bool state)
{
  _menuButton->setVisible(state);
}

void vgui::Frame::setTrayButtonVisible(bool state)
{
  _trayButton->setVisible(state);
}

void vgui::Frame::setMinimizeButtonVisible(bool state)
{
  _minimizeButton->setVisible(state);
}

void vgui::Frame::setMaximizeButtonVisible(bool state)
{
  _maximizeButton->setVisible(state);
}

void vgui::Frame::setCloseButtonVisible(bool state)
{
  _closeButton->setVisible(state);
}

void vgui::Frame::setVisible(bool state)
{
  vgui::Panel::setVisible(state);

  auto parent = getParent();
  if (parent)
    repaint();
}

void vgui::Frame::paintBackground()
{
  int wide, tall;
  int widea, talla;
  vgui::Scheme::SchemeColor color2;

  v1 = _size[0];
  v2 = _size[1];
  v3 = (*((int(__cdecl **)(vgui::Frame *const))_vptr_Panel + 61))(this);
  if ((*(uint8_t(__cdecl **)(int))(*(_DWORD *)v3 + 52))(v3))
  {
    v5 = 6;
    v14 = (*((int(__cdecl **)(vgui::Frame *const))_vptr_Panel + 83))(this);
    v15 = (vgui::Frame *)(*(int(__cdecl **)(int))(*(_DWORD *)v14 + 72))(v14);
    v4 = 8;
    color2 = sc_secondary2;
    if (v15)
    {
      wide = v1;
      v16 = 7;
      tall = v2;
      v17 = 8;
      do
      {
        if (v15 == this)
          v17 = 5;
        if (v15 == this)
          v5 = 3;
        if (v15 == this)
          v16 = 4;
        v15 = (vgui::Frame *)(*((int(__cdecl **)(vgui::Frame *))v15->_vptr_Panel + 8))(v15);
      } while (v15);
      color2 = v16;
      v4 = v17;
      v1 = wide;
      v2 = tall;
    }
  }
  else
  {
    v4 = 8;
    color2 = sc_secondary2;
    v5 = 6;
  }
  (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 93))(this, v4);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 5, 5, v1 - 5, 28);
  (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 93))(this, 2);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 10, v1 - 70, 11);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 15, v1 - 70, 16);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 20, v1 - 70, 21);
  (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 93))(this, v5);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 12, v1 - 70, 13);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 17, v1 - 70, 18);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 120, 22, v1 - 70, 23);
  (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 93))(this, v5);
  widea = v1 - 1;
  v6 = v2 - 1;
  (*((void(__cdecl **)(vgui::Frame *const, int, _DWORD, int, int))_vptr_Panel + 95))(this, 1, 0, v1 - 1, 5);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 1, v2 - 5, v1 - 1, v2);
  (*((void(__cdecl **)(vgui::Frame *const, _DWORD, int, int, int))_vptr_Panel + 95))(this, 0, 1, 5, v2 - 1);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, v1 - 5, 1, v1, v2 - 1);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 5, 5, 6, 6);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, v1 - 6, 5, v1 - 5, 6);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 5, 28, v1 - 5, 29);
  (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 93))(this, 1);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 13, 2, v1 - 13, 3);
  talla = v2 - 2;
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(
      this,
      13,
      v2 - 3,
      v1 - 13,
      v2 - 2);
  v7 = v2 - 13;
  v8 = v2 - 12;
  v20 = v7;
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 2, 13, 3, v7);
  v9 = v20;
  v18 = v1 - 2;
  v21 = v1 - 2;
  v19 = v9;
  v10 = v1 - 3;
  v11 = v1 - 12;
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, v10, 13, v18, v19);
  (*((void(__cdecl **)(vgui::Frame *const, vgui::Scheme::SchemeColor))_vptr_Panel + 93))(this, color2);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 14, 3, v11, 4);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 14, talla, v11, v6);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, 3, 14, 4, v8);
  (*((void(__cdecl **)(vgui::Frame *const, int, int, int, int))_vptr_Panel + 95))(this, v21, 14, widea, v8);
  if (_title)
  {
    (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 97))(this, 1);
    (*((void(__cdecl **)(vgui::Frame *const, int))_vptr_Panel + 99))(this, 1);
    s = _title;
    v13 = strlen(s);
    (*((void(__cdecl **)(vgui::Frame *const, int, int, char *, size_t))_vptr_Panel + 103))(this, 28, 7, s, v13);
  }
}

void vgui::Frame::getTitle(char *buf, int bufLen)
{
  vgui::vgui_strcpy(buf, bufLen, _title);
}

void vgui::Frame::setTitle(const char *title)
{
  operator delete(_title);
  _title = vgui::vgui_strdup(title);
  (*((void(__cdecl **)(vgui::Frame *const))_vptr_Panel + 12))(this);
}

void vgui::Frame::setSize(int wide, int tall)
{
  int v3; // esi
  int v4; // edi

  if ((*((int(__cdecl **)(vgui::Frame *const))_vptr_Panel + 6))(this) != wide || (*((int(__cdecl **)(vgui::Frame *const))_vptr_Panel + 7))(this) != tall)
  {
    vgui::Panel::setSize(this, wide, tall);
    v3 = _size[0];
    v4 = _size[1];
    (*((void(__cdecl **)(vgui::Panel *, int, _DWORD, int, int))_topGrip->_vptr_Panel + 4))(
        _topGrip,
        15,
        0,
        v3 - 30,
        5);
    (*((void(__cdecl **)(vgui::Panel *, int, int, int, int))_bottomGrip->_vptr_Panel + 4))(
        _bottomGrip,
        15,
        v4 - 5,
        v3 - 30,
        5);
    (*((void(__cdecl **)(vgui::Panel *, _DWORD, int, int, int))_leftGrip->_vptr_Panel + 4))(
        _leftGrip,
        0,
        15,
        5,
        v4 - 30);
    (*((void(__cdecl **)(vgui::Panel *, int, int, int, int))_rightGrip->_vptr_Panel + 4))(
        _rightGrip,
        v3 - 5,
        15,
        5,
        v4 - 30);
    (*((void(__cdecl **)(vgui::Panel *, _DWORD, _DWORD, int, int))_topLeftGrip->_vptr_Panel + 4))(
        _topLeftGrip,
        0,
        0,
        15,
        15);
    (*((void(__cdecl **)(vgui::Panel *, int, _DWORD, int, int))_topRightGrip->_vptr_Panel + 4))(
        _topRightGrip,
        v3 - 15,
        0,
        15,
        15);
    (*((void(__cdecl **)(vgui::Panel *, _DWORD, int, int, int))_bottomLeftGrip->_vptr_Panel + 4))(
        _bottomLeftGrip,
        0,
        v4 - 15,
        15,
        15);
    (*((void(__cdecl **)(vgui::Panel *, int, int, int, int))_bottomRightGrip->_vptr_Panel + 4))(
        _bottomRightGrip,
        v3 - 15,
        v4 - 15,
        15,
        15);
    (*((void(__cdecl **)(vgui::Panel *, int, int))_captionGrip->_vptr_Panel + 2))(
        _captionGrip,
        v3 - 10,
        23);
    (*((void(__cdecl **)(vgui::Panel *, int, int))_client->_vptr_Panel + 2))(_client, v3 - 10, v4 - 34);
    (**(void(__cdecl ***)(vgui::Button *, int, int))_trayButton)(_trayButton, v3 - 85, 8);
    (**(void(__cdecl ***)(vgui::Button *, int, int))_minimizeButton)(_minimizeButton, v3 - 65, 8);
    (**(void(__cdecl ***)(vgui::Button *, int, int))_maximizeButton)(_maximizeButton, v3 - 45, 8);
    (**(void(__cdecl ***)(vgui::Button *, int, int))_closeButton)(_closeButton, v3 - 25, 8);
    (*((void(__cdecl **)(vgui::Panel *, _DWORD))_client->_vptr_Panel + 46))(_client, 0);
  }
}

void vgui::Frame::addFrameSignal(vgui::FrameSignal *s)
{
  int v2;                             // ecx
  vgui::Dar<vgui::FrameSignal *> *v3; // esi
  vgui::FrameSignal **v4;             // edx
  int v5;                             // eax
  int v6;                             // edx
  int v7;                             // eax
  vgui::FrameSignal **v8;             // eax
  unsigned int v9;                    // edi
  _BYTE *v10;                         // eax
  _WORD *v11;                         // edi
  int v12;                            // eax
  int v13;                            // [esp+14h] [ebp-28h]
  vgui::FrameSignal **v14;            // [esp+18h] [ebp-24h]
  unsigned int v15;                   // [esp+1Ch] [ebp-20h]

  v2 = _frameSignalDar._count;
  v3 = &_frameSignalDar;
  if (v2 > 0)
  {
    v4 = _frameSignalDar._data;
    v5 = 0;
    if (s == *v4)
      return;
    while (++v5 != v2)
    {
      if (s == v4[v5])
        return;
    }
  }
  v6 = _frameSignalDar._capacity;
  v7 = v2 + 1;
  if (v2 + 1 > v6)
  {
    if (v6 || (v6 = 1, v9 = 4, v7 > 1))
    {
      do
        v6 *= 2;
      while (v7 > v6);
      v9 = 4 * v6;
    }
    v13 = v6;
    v10 = (_BYTE *)operator new[](v9);
    v14 = (vgui::FrameSignal **)v10;
    if (!v10)
      exit(0);
    v15 = v9;
    v11 = v10;
    if (v15 >= 8)
    {
      if (((uint8_t)v10 & 1) != 0)
      {
        *v10 = 0;
        --v15;
        v11 = v10 + 1;
      }
      if (((uint8_t)v11 & 2) != 0)
      {
        *v11++ = 0;
        v15 -= 2;
      }
      if (((uint8_t)v11 & 4) != 0)
      {
        *(_DWORD *)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ((v15 & 4) != 0)
    {
      *(_DWORD *)v11 = 0;
      v11 += 2;
    }
    if ((v15 & 2) != 0)
      *v11++ = 0;
    if ((v15 & 1) != 0)
      *(_BYTE *)v11 = 0;
    v2 = _frameSignalDar._count;
    _frameSignalDar._capacity = v13;
    if (v2 > 0)
    {
      v12 = 0;
      do
      {
        v14[v12] = _frameSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      } while (v12 < v3->_count);
    }
    if (_frameSignalDar._data)
    {
      operator delete[](_frameSignalDar._data);
      v2 = _frameSignalDar._count;
    }
    v8 = v14;
    _frameSignalDar._data = v14;
  }
  else
  {
    v8 = _frameSignalDar._data;
  }
  v8[v2] = s;
  ++_frameSignalDar._count;
}

void vgui::Frame::Frame(int x, int y, int wide, int tall)
{
  int v5;                                             // eax
  int v6;                                             // edx
  int v7;                                             // edx
  vgui::FrameSignal **v8;                             // edx
  _DWORD *v9;                                         // eax
  void(__cdecl * v10)(vgui::Panel *, vgui::Cursor *); // ebp
  void(__cdecl * v11)(vgui::Panel *, _DWORD *);       // ebp
  _DWORD *v12;                                        // eax
  _DWORD *v13;                                        // eax
  void(__cdecl * v14)(vgui::Panel *, vgui::Cursor *); // ebp
  void(__cdecl * v15)(vgui::Panel *, _DWORD *);       // ebp
  _DWORD *v16;                                        // eax
  vgui::Panel *v17;                                   // ebp
  void(__cdecl * v18)(vgui::Panel *, vgui::Cursor *); // ebp
  void(__cdecl * v19)(vgui::Panel *, _DWORD *);       // ebp
  _DWORD *v20;                                        // eax
  _DWORD *v21;                                        // eax
  _DWORD *v22;                                        // eax
  void(__cdecl * v23)(vgui::Panel *, vgui::Cursor *); // ebp
  void(__cdecl * v24)(vgui::Panel *, _DWORD *);       // ebp
  _DWORD *v25;                                        // eax
  _DWORD *v26;                                        // eax
  void(__cdecl * v27)(vgui::Panel *, _DWORD *);       // edi
  _DWORD *v28;                                        // eax
  vgui::Button *v29;                                  // edi
  vgui::Button *v30;                                  // edi
  void(__cdecl * v31)(vgui::Button *, _DWORD *);      // edi
  _DWORD *v32;                                        // eax
  vgui::Button *v33;                                  // edi
  vgui::Button *v34;                                  // edi
  void(__cdecl * v35)(vgui::Button *, _DWORD *);      // esi
  _DWORD *v36;                                        // eax
  vgui::Button *v37;                                  // esi
  int v38;                                            // [esp+24h] [ebp-28h]
  vgui::Panel *v39;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v40;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v41;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v42;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v43;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v44;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v45;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v46;                                  // [esp+24h] [ebp-28h]
  vgui::Cursor *v47;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v48;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v49;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v50;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v51;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v52;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v53;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v54;                                   // [esp+24h] [ebp-28h]
  vgui::Cursor *v55;                                  // [esp+24h] [ebp-28h]
  vgui::Panel *v56;                                   // [esp+24h] [ebp-28h]
  void(__cdecl * v57)(vgui::Panel *, vgui::Cursor *); // [esp+2Ch] [ebp-20h]
  void(__cdecl * v58)(vgui::Panel *, _DWORD *);       // [esp+2Ch] [ebp-20h]
  void(__cdecl * v59)(vgui::Panel *, vgui::Cursor *); // [esp+2Ch] [ebp-20h]
  void(__cdecl * v60)(vgui::Panel *, _DWORD *);       // [esp+2Ch] [ebp-20h]
  void(__cdecl * v61)(vgui::Panel *, vgui::Cursor *); // [esp+2Ch] [ebp-20h]
  void(__cdecl * v62)(vgui::Panel *, _DWORD *);       // [esp+2Ch] [ebp-20h]
  void(__cdecl * v63)(vgui::Panel *, vgui::Cursor *); // [esp+2Ch] [ebp-20h]
  void(__cdecl * v64)(vgui::Panel *, _DWORD *);       // [esp+2Ch] [ebp-20h]
  void(__cdecl * v65)(vgui::Panel *, vgui::Cursor *); // [esp+2Ch] [ebp-20h]
  void(__cdecl * v66)(vgui::Panel *, _DWORD *);       // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  _frameSignalDar._capacity = 0;
  _vptr_Panel = (int (**)(...))(&`vtable for'vgui::Frame + 2);
  _frameSignalDar._count = 0;
  _frameSignalDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    exit(0);
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = _frameSignalDar._count;
  _frameSignalDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = _frameSignalDar._data[v7];
      ++v7;
    } while (v7 < _frameSignalDar._count);
  }
  v8 = _frameSignalDar._data;
  if ( v8 )
  {
    v38 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v38;
  }
  _frameSignalDar._data = (vgui::FrameSignal **)v5;
  _title = 0;
  _internal = 1;
  _moveable = 1;
  _sizeable = 1;
  operator delete(0);
  _title = vgui::vgui_strdup("Untitled");
  (*((void (__cdecl **)(vgui::Frame *const))_vptr_Panel + 12))(this);
  vgui::Panel::setMinimumSize(this, 64, 33);
  v39 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v39, 15, 0, wide - 30, 5);
  _topGrip = v39;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v39->_vptr_Panel + 16))(v39, this);
  v57 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_topGrip->_vptr_Panel + 36);
  v40 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v40, dc_sizens);
  v57(_topGrip, v40);
  v58 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_topGrip->_vptr_Panel + 28);
  v9 = operator new(0x34u);
  v9[1] = this;
  *((_BYTE *)v9 + 8) = 0;
  *v9 = &off_44128;
  v58(_topGrip, v9);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topGrip->_vptr_Panel + 54))(_topGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topGrip->_vptr_Panel + 55))(_topGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topGrip->_vptr_Panel + 56))(_topGrip, 0);
  v41 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v41, 15, tall - 5, wide - 30, 5);
  _bottomGrip = v41;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v41->_vptr_Panel + 16))(v41, this);
  v10 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_bottomGrip->_vptr_Panel + 36);
  v42 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v42, dc_sizens);
  v10(_bottomGrip, v42);
  v11 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_bottomGrip->_vptr_Panel + 28);
  v12 = operator new(0x34u);
  v12[1] = this;
  *((_BYTE *)v12 + 8) = 0;
  *v12 = &off_44168;
  v11(_bottomGrip, v12);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomGrip->_vptr_Panel + 54))(_bottomGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomGrip->_vptr_Panel + 55))(_bottomGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomGrip->_vptr_Panel + 56))(_bottomGrip, 0);
  v43 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v43, 0, 15, 5, tall - 30);
  _leftGrip = v43;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v43->_vptr_Panel + 16))(v43, this);
  v59 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_leftGrip->_vptr_Panel + 36);
  v44 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v44, dc_sizewe);
  v59(_leftGrip, v44);
  v60 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_leftGrip->_vptr_Panel + 28);
  v13 = operator new(0x34u);
  v13[1] = this;
  *((_BYTE *)v13 + 8) = 0;
  *v13 = &off_441A8;
  v60(_leftGrip, v13);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_leftGrip->_vptr_Panel + 54))(_leftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_leftGrip->_vptr_Panel + 55))(_leftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_leftGrip->_vptr_Panel + 56))(_leftGrip, 0);
  v45 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v45, wide - 5, 15, 5, tall - 30);
  _rightGrip = v45;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v45->_vptr_Panel + 16))(v45, this);
  v14 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_rightGrip->_vptr_Panel + 36);
  v46 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v46, dc_sizewe);
  v14(_rightGrip, v46);
  v15 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_rightGrip->_vptr_Panel + 28);
  v16 = operator new(0x34u);
  v16[1] = this;
  *((_BYTE *)v16 + 8) = 0;
  *v16 = &off_441E8;
  v15(_rightGrip, v16);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_rightGrip->_vptr_Panel + 54))(_rightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_rightGrip->_vptr_Panel + 55))(_rightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_rightGrip->_vptr_Panel + 56))(_rightGrip, 0);
  v17 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v17, 0, 0, 15, 15);
  _topLeftGrip = v17;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v17->_vptr_Panel + 16))(v17, this);
  v18 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_topLeftGrip->_vptr_Panel + 36);
  v47 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v47, dc_sizenwse);
  v18(_topLeftGrip, v47);
  v19 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_topLeftGrip->_vptr_Panel + 28);
  v20 = operator new(0x34u);
  v20[1] = this;
  *((_BYTE *)v20 + 8) = 0;
  *v20 = &off_44228;
  v19(_topLeftGrip, v20);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topLeftGrip->_vptr_Panel + 54))(_topLeftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topLeftGrip->_vptr_Panel + 55))(_topLeftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topLeftGrip->_vptr_Panel + 56))(_topLeftGrip, 0);
  v48 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v48, wide - 15, 0, 15, 15);
  _topRightGrip = v48;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v48->_vptr_Panel + 16))(v48, this);
  v61 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_topRightGrip->_vptr_Panel + 36);
  v49 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v49, dc_sizenesw);
  v61(_topRightGrip, v49);
  v62 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_topRightGrip->_vptr_Panel + 28);
  v21 = operator new(0x34u);
  v21[1] = this;
  *((_BYTE *)v21 + 8) = 0;
  *v21 = &off_44268;
  v62(_topRightGrip, v21);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topRightGrip->_vptr_Panel + 54))(_topRightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topRightGrip->_vptr_Panel + 55))(_topRightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_topRightGrip->_vptr_Panel + 56))(_topRightGrip, 0);
  v50 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v50, 0, tall - 15, 15, 15);
  _bottomLeftGrip = v50;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v50->_vptr_Panel + 16))(v50, this);
  v63 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_bottomLeftGrip->_vptr_Panel + 36);
  v51 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v51, dc_sizenesw);
  v63(_bottomLeftGrip, v51);
  v64 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_bottomLeftGrip->_vptr_Panel + 28);
  v22 = operator new(0x34u);
  v22[1] = this;
  *((_BYTE *)v22 + 8) = 0;
  *v22 = &off_442A8;
  v64(_bottomLeftGrip, v22);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomLeftGrip->_vptr_Panel + 54))(_bottomLeftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomLeftGrip->_vptr_Panel + 55))(_bottomLeftGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomLeftGrip->_vptr_Panel + 56))(_bottomLeftGrip, 0);
  v52 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v52, wide - 15, tall - 15, 15, 15);
  _bottomRightGrip = v52;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v52->_vptr_Panel + 16))(v52, this);
  v23 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_bottomRightGrip->_vptr_Panel + 36);
  v53 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v53, dc_sizenwse);
  v23(_bottomRightGrip, v53);
  v24 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_bottomRightGrip->_vptr_Panel + 28);
  v25 = operator new(0x34u);
  v25[1] = this;
  *((_BYTE *)v25 + 8) = 0;
  *v25 = &off_442E8;
  v24(_bottomRightGrip, v25);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomRightGrip->_vptr_Panel + 54))(_bottomRightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomRightGrip->_vptr_Panel + 55))(_bottomRightGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_bottomRightGrip->_vptr_Panel + 56))(_bottomRightGrip, 0);
  v54 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v54, 5, 5, wide - 10, 23);
  _captionGrip = v54;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v54->_vptr_Panel + 16))(v54, this);
  v65 = (void (__cdecl *)(vgui::Panel *, vgui::Cursor *))*((_DWORD *)_captionGrip->_vptr_Panel + 36);
  v55 = (vgui::Cursor *)operator new(0x14u);
  vgui::Cursor::Cursor(v55, dc_sizeall);
  v65(_captionGrip, v55);
  v66 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_captionGrip->_vptr_Panel + 28);
  v26 = operator new(0x34u);
  v26[1] = this;
  *((_BYTE *)v26 + 8) = 0;
  *v26 = &off_44328;
  v66(_captionGrip, v26);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_captionGrip->_vptr_Panel + 54))(_captionGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_captionGrip->_vptr_Panel + 55))(_captionGrip, 0);
  (*((void (__cdecl **)(vgui::Panel *, _DWORD))_captionGrip->_vptr_Panel + 56))(_captionGrip, 0);
  v56 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v56, 5, 29, wide - 10, tall - 34);
  _client = v56;
  (*((void (__cdecl **)(vgui::Panel *, vgui::Frame *const))v56->_vptr_Panel + 16))(v56, this);
  v27 = (void (__cdecl *)(vgui::Panel *, _DWORD *))*((_DWORD *)_client->_vptr_Panel + 28);
  v28 = operator new(0x34u);
  v28[1] = this;
  *v28 = &off_440E8;
  *((_BYTE *)v28 + 8) = 0;
  v27(_client, v28);
  v29 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v29, ".", wide - 85, 8, 18, 18);
  _trayButton = v29;
  (*(void (__cdecl **)(vgui::Button *, vgui::Frame *const))(*(_DWORD *)v29->baseclass_0 + 64))(v29, this);
  v30 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v30, "2", wide - 65, 8, 18, 18);
  _minimizeButton = v30;
  (*(void (__cdecl **)(vgui::Button *, int))(*(_DWORD *)v30->baseclass_0 + 520))(v30, 4);
  (*(void (__cdecl **)(vgui::Button *, vgui::Frame *const))(*(_DWORD *)_minimizeButton + 64))(
    _minimizeButton,
    this);
  v31 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)_minimizeButton + 576);
  v32 = operator new(8u);
  v32[1] = this;
  *v32 = &off_44360;
  v31(_minimizeButton, v32);
  v33 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v33, "1", wide - 45, 8, 18, 18);
  _maximizeButton = v33;
  (*(void (__cdecl **)(vgui::Button *, int))(*(_DWORD *)v33->baseclass_0 + 520))(v33, 4);
  (*(void (__cdecl **)(vgui::Button *, vgui::Frame *const))(*(_DWORD *)_maximizeButton + 64))(
    _maximizeButton,
    this);
  v34 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v34, "r", wide - 25, 8, 18, 18);
  _closeButton = v34;
  (*(void (__cdecl **)(vgui::Button *, int))(*(_DWORD *)v34->baseclass_0 + 520))(v34, 4);
  (*(void (__cdecl **)(vgui::Button *, vgui::Frame *const))(*(_DWORD *)_closeButton + 64))(
    _closeButton,
    this);
  v35 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)_closeButton + 576);
  v36 = operator new(8u);
  v36[1] = this;
  *v36 = &off_44370;
  v35(_closeButton, v36);
  v37 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v37, "s", 7, 8, 18, 18);
  _menuButton = v37;
  (*(void (__cdecl **)(vgui::Button *, int))(*(_DWORD *)v37->baseclass_0 + 520))(v37, 4);
  (*(void (__cdecl **)(vgui::Button *, vgui::Frame *const))(*(_DWORD *)_menuButton + 64))(_menuButton, this);
}
