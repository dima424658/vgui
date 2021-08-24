#include <VGUI_Panel.h>

#include <VGUI_SurfaceBase.h>
#include <VGUI_App.h>

#include <cmath>

void vgui::Panel::setPos(int x, int y)
{
  _pos[0] = x;
  _pos[1] = y;
}

void vgui::Panel::getPos(int& x, int& y)
{
  x = _pos[0];
  y = _pos[1];
}

void vgui::Panel::setSize(int wide, int tall)
{
  _size[0] = std::max(tall, _minimumSize[0]);
  _size[1] = std::max(tall, _minimumSize[1]);
}

void vgui::Panel::getSize(int& wide, int& tall)
{
  wide = _size[0];
  tall = _size[1];
}

void vgui::Panel::setBounds(int x, int y, int wide, int tall)
{
  setPos(x, y);
  setSize(wide, tall);
}

void vgui::Panel::getBounds(int& x, int& y, int& wide, int& tall)
{
  x = _pos[0];
  y = _pos[1];
  wide = _size[0];
  tall = _size[1];
}

void vgui::Panel::setVisible(bool state)
{
  _visible = state;
}

bool vgui::Panel::isVisible()
{
  return _visible;
}

bool vgui::Panel::isVisibleUp()
{
  vgui::Panel* parent = this;

  while (parent->_visible)
  {
    if (!parent)
      return true;
    parent = parent->getParent();
  }

  return false;
}

void vgui::Panel::repaint()
{
  _needsRepaint = true;
  if (v1)
  {
    _surfaceBase->_needsSwap = true;
    _surfaceBase->invalidate(this);
  }

  for (auto i = 0; i < _repaintSignalDar.getCount(); ++i)
    _repaintSignalDar[i]->panelRepainted(this);
}

void vgui::Panel::repaintAll()
{
  _surfaceBase->getPanel()->repaint();
}

void vgui::Panel::solve()
{
  int pinset[4];

  _loc[0] = _pos[0];
  _loc[1] = _pos[1];

  if (_parent)
  {
    _parent->getInset(pinset[0], pinset[1], pinset[2], pinset[3]);

    _loc[0] += pinset[0] + _parent->_loc[0];
    _loc[1] += pinset[1] + _parent->_loc[1];

    _clipRect[0] = std::max(_loc[0], _parent->_clipRect[0]);
    _clipRect[1] = std::max(_loc[1], _parent->_clipRect[1]);
    _clipRect[2] = std::max(_loc[0] + _size[0], _parent->_clipRect[2]);
    _clipRect[3] = std::max(_loc[1] + _size[1], _parent->_clipRect[3]);
  }
  else
  {
    _clipRect[0] = _pos[0];
    _clipRect[1] = _pos[1];
    _clipRect[2] = _pos[0] + _size[0];
    _clipRect[3] = _pos[1] + _size[1];
  }
}

void vgui::Panel::paintTraverse()
{
  paintTraverse(true);
}

void vgui::Panel::paintBackground()
{
  int wide, tall;
  int r, g, b, a;

  getPaintSize(wide, tall);
  getBgColor(r, g, b, a);
  drawSetColor(r, g, b, a);
  drawFilledRect(0, 0, wide, tall);
}

void vgui::Panel::paintBuildOverlay()
{
  int wide, tall;

  getSize(wide, tall);
  drawSetColor(vgui::Scheme::SchemeColor::sc_black);

  drawFilledRect(0, 0, wide, 2);
  drawFilledRect(0, tall - 2, wide, tall);
  drawFilledRect(0, 2, 2, tall - 2);
  drawFilledRect(wide - 2, 2, wide, tall - 2);
}

void vgui::Panel::drawSetColor(vgui::Scheme::SchemeColor sc)
{
  int r, g, b, a;

  getApp()->getScheme()->getColor(sc, r, g, b, a);
  drawSetColor(r, g, b, a);
}

void vgui::Panel::drawSetColor(int r, int g, int b, int a)
{
  _surfaceBase->drawSetColor(r, g, b, a);
}

void vgui::Panel::drawFilledRect(int x0, int y0, int x1, int y1)
{
  _surfaceBase->drawFilledRect(x0, y0, x1, y1);
}

void vgui::Panel::drawOutlinedRect(int x0, int y0, int x1, int y1)
{
  _surfaceBase->drawOutlinedRect(x0, y0, x1, y1);
}

void vgui::Panel::drawSetTextFont(vgui::Scheme::SchemeFont sf_0)
{
  drawSetTextFont(getApp()->getScheme()->getFont(sf_0));
}

void vgui::Panel::drawSetTextFont(vgui::Font* font)
{
  _surfaceBase->drawSetTextFont(font);
}

void vgui::Panel::drawSetTextColor(vgui::Scheme::SchemeColor sc)
{
  int r, g, b, a;

  getApp()->getScheme()->getColor(sc, r, g, b, a);
  drawSetTextColor(r,g,b,a);
}

void vgui::Panel::drawSetTextColor(int r, int g, int b, int a)
{
  _surfaceBase->drawSetTextColor(r, g, b, a);
}

void vgui::Panel::drawSetTextPos(int x, int y)
{
  _surfaceBase->drawSetTextPos(x,y);
}

void vgui::Panel::drawPrintText(const char* str, int strlen)
{
  _surfaceBase->drawPrintText(str, strlen);
}

void vgui::Panel::drawPrintText(int x, int y, const char* str, int strlen)
{
  _surfaceBase->drawSetTextPos(x,y);
  _surfaceBase->drawPrintText(str, strlen);
}

void vgui::Panel::drawPrintChar(char ch_0)
{
  _surfaceBase->drawPrintText(&ch_0, 1);
}

void vgui::Panel::drawPrintChar(int x, int y, char ch_0)
{
  drawPrintText(x, y, &ch_0, 1);
}

void vgui::Panel::drawSetTextureRGBA(int id, const char* rgba, int wide, int tall)
{
  if(_surfaceBase)
    _surfaceBase->drawSetTextureRGBA(id, rgba, wide, tall);
}

void vgui::Panel::drawSetTexture(int id)
{
  _surfaceBase->drawSetTexture(id);
}

void vgui::Panel::drawTexturedRect(int x0, int y0, int x1, int y1)
{
  _surfaceBase->drawTexturedRect(x0,y0,x1,y1);
}

void vgui::Panel::getAbsExtents(int& x0, int& y0, int& x1, int& y1)
{
  x0 = _loc[0];
  y0 = _loc[1];
  x1 = _size[0] + x0;
  y1 = _size[1] + y0;
}

void vgui::Panel::removeChild(vgui::Panel* child)
{
  int v2; // ebx
  vgui::Panel** v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  vgui::Panel** v7; // ebx

  child->_parent = 0;
  child->_surfaceBase = 0;
  v2 = _childDar._count;
  if (v2 > 0)
  {
    v3 = _childDar._data;
    v4 = 0;
    if (child == *v3)
    {
    LABEL_8:
      v5 = v2 - 1;
      if (v4 < v5)
      {
        v6 = v4;
        while (1)
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = _childDar._count - 1;
          if (v4 >= v5)
            break;
          v3 = _childDar._data;
        }
      }
      _childDar._count = v5;
    }
    else
    {
      while (++v4 != v2)
      {
        if (child == v3[v4])
        {
          if (v4 < 0)
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::setSurfaceBaseTraverse(vgui::SurfaceBase* surfaceBase)
{
  int v2; // ebx
  int v3; // ebx
  vgui::Panel* v4; // eax

  v2 = _childDar._count;
  _surfaceBase = surfaceBase;
  if (v2 > 0)
  {
    v3 = 0;
    do
    {
      v4 = _childDar._data[v3++];
      (*((void(__cdecl**)(vgui::Panel*, vgui::SurfaceBase*))v4->_vptr_Panel + 90))(v4, surfaceBase);
    } while (_childDar._count > v3);
  }
}

bool vgui::Panel::wasMousePressed(vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::MouseCode, vgui::Panel* const))(*(_DWORD*)v2 + 12))(v2, code, this);
}

bool vgui::Panel::wasMouseDoublePressed(vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::MouseCode, vgui::Panel* const))(*(_DWORD*)v2 + 16))(v2, code, this);
}

bool vgui::Panel::isMouseDown(vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::MouseCode, vgui::Panel* const))(*(_DWORD*)v2 + 20))(v2, code, this);
}

bool vgui::Panel::wasMouseReleased(vgui::MouseCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::MouseCode, vgui::Panel* const))(*(_DWORD*)v2 + 24))(v2, code, this);
}

bool vgui::Panel::wasKeyPressed(vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::KeyCode, vgui::Panel* const))(*(_DWORD*)v2 + 28))(v2, code, this);
}

bool vgui::Panel::isKeyDown(vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::KeyCode, vgui::Panel* const))(*(_DWORD*)v2 + 32))(v2, code, this);
}

bool vgui::Panel::wasKeyTyped(vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::KeyCode, vgui::Panel* const))(*(_DWORD*)v2 + 36))(v2, code, this);
}

bool vgui::Panel::wasKeyReleased(vgui::KeyCode code)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return (*(int(__cdecl**)(int, vgui::KeyCode, vgui::Panel* const))(*(_DWORD*)v2 + 40))(v2, code, this);
}

void vgui::Panel::removeInputSignal(vgui::InputSignal* s)
{
  int v2; // ecx
  vgui::InputSignal** v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  vgui::InputSignal** v7; // ecx

  v2 = _inputSignalDar._count;
  if (v2 > 0)
  {
    v3 = _inputSignalDar._data;
    v4 = 0;
    if (s == *v3)
    {
    LABEL_8:
      v5 = v2 - 1;
      if (v4 < v5)
      {
        v6 = v4;
        while (1)
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = _inputSignalDar._count - 1;
          if (v4 >= v5)
            break;
          v3 = _inputSignalDar._data;
        }
      }
      _inputSignalDar._count = v5;
    }
    else
    {
      while (++v4 != v2)
      {
        if (s == v3[v4])
        {
          if (v4 < 0)
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::removeRepaintSignal(vgui::RepaintSignal* s)
{
  int v2; // ecx
  vgui::RepaintSignal** v3; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  vgui::RepaintSignal** v7; // ecx

  v2 = _repaintSignalDar._count;
  if (v2 > 0)
  {
    v3 = _repaintSignalDar._data;
    v4 = 0;
    if (s == *v3)
    {
    LABEL_8:
      v5 = v2 - 1;
      if (v4 < v5)
      {
        v6 = v4;
        while (1)
        {
          v7 = &v3[v6++];
          ++v4;
          *v7 = v3[v6];
          v5 = _repaintSignalDar._count - 1;
          if (v4 >= v5)
            break;
          v3 = _repaintSignalDar._data;
        }
      }
      _repaintSignalDar._count = v5;
    }
    else
    {
      while (++v4 != v2)
      {
        if (s == v3[v4])
        {
          if (v4 < 0)
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

void vgui::Panel::internalCursorMoved(int x, int y)
{
  int v3; // esi
  vgui::InputSignal* v4; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this))
  {
    if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
    {
      (*((void(__cdecl**)(vgui::BuildGroup*, int, int, vgui::Panel* const))_buildGroup->_vptr_BuildGroup + 8))(
        _buildGroup,
        x,
        y,
        this);
    }
    else
    {
      (*((void(__cdecl**)(vgui::Panel* const, int*, int*))_vptr_Panel + 35))(this, &x, &y);
      if (_inputSignalDar._count > 0)
      {
        v3 = 0;
        do
        {
          v4 = _inputSignalDar._data[v3++];
          (*v4->_vptr_InputSignal)(v4, x, y, this);
        } while (_inputSignalDar._count > v3);
      }
    }
  }
}

void vgui::Panel::internalKeyTyped(vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal* v3; // eax

  if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
  {
    (*((void(__cdecl**)(vgui::BuildGroup*, vgui::KeyCode, vgui::Panel* const))_buildGroup->_vptr_BuildGroup + 12))(
      _buildGroup,
      code,
      this);
  }
  else
  {
    if (code == KEY_TAB && (*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 51))(this))
    {
      if ((*((uint8_t(__cdecl**)(vgui::Panel* const, int))_vptr_Panel + 25))(this, 78)
        || (*((uint8_t(__cdecl**)(vgui::Panel* const, int))_vptr_Panel + 25))(this, 79))
      {
        (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 48))(this);
      }
      else
      {
        (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 49))(this);
      }
    }
    if (_inputSignalDar._count > 0)
    {
      v2 = 0;
      do
      {
        v3 = _inputSignalDar._data[v2++];
        (*((void(__cdecl**)(vgui::InputSignal*, vgui::KeyCode, vgui::Panel* const))v3->_vptr_InputSignal + 8))(
          v3,
          code,
          this);
      } while (_inputSignalDar._count > v2);
    }
  }
}

void vgui::Panel::internalSetCursor()
{
  vgui::SurfaceBase* v1; // eax
  void(__cdecl * v2)(vgui::SurfaceBase*, int); // esi
  int v3; // eax

  if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
    (*((void(__cdecl**)(vgui::BuildGroup*, vgui::Panel* const))_buildGroup->_vptr_BuildGroup + 13))(
      _buildGroup,
      this);
  v1 = _surfaceBase;
  if (v1)
  {
    v2 = (void(__cdecl*)(vgui::SurfaceBase*, int)) * ((_DWORD*)v1->_vptr_SurfaceBase + 30);
    v3 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 38))(this);
    v2(_surfaceBase, v3);
  }
}

bool vgui::Panel::isWithin(int x, int y)
{
  bool result; // al

  (*((void(__cdecl**)(vgui::Panel* const, int*, int*))_vptr_Panel + 35))(this, &x, &y);
  result = 0;
  if (x >= 0 && y >= 0 && x < _size[0])
    result = y < _size[1];
  return result;
}

void vgui::Panel::localToScreen(int& x, int& y)
{
  *x += _loc[0];
  *y += _loc[1];
}

void vgui::Panel::screenToLocal(int& x, int& y)
{
  *x -= _loc[0];
  *y -= _loc[1];
}

void vgui::Panel::setCursor(vgui::Cursor* cursor)
{
  _schemeCursor = scu_user;
  _cursor = cursor;
}

void vgui::Panel::setCursor(vgui::Scheme::SchemeCursor scu)
{
  _cursor = 0;
  _schemeCursor = scu;
}

void vgui::Panel::setMinimumSize(int wide, int tall)
{
  _minimumSize[0] = wide;
  _minimumSize[1] = tall;
}

void vgui::Panel::requestFocus()
{
  int v1; // eax

  v1 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  (*(void(__cdecl**)(int, vgui::Panel* const))(*(_DWORD*)v1 + 68))(v1, this);
}

bool vgui::Panel::hasFocus()
{
  int v1; // eax

  v1 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  return this == (vgui::Panel* const)(*(int(__cdecl**)(int))(*(_DWORD*)v1 + 72))(v1);
}

void vgui::Panel::getClipRect(int& x0, int& y0, int& x1, int& y1)
{
  *x0 = _clipRect[0];
  *y0 = _clipRect[1];
  *x1 = _clipRect[2];
  *y1 = _clipRect[3];
}

int vgui::Panel::getChildCount()
{
  return _childDar._count;
}

void vgui::Panel::setLayout(vgui::Layout* layout)
{
  _layout = layout;
  (*((void(__cdecl**)(vgui::Panel* const, _DWORD))_vptr_Panel + 46))(this, 0);
}

void vgui::Panel::internalPerformLayout()
{
  vgui::Layout* v1; // eax

  v1 = _layout;
  _needsLayout = 0;
  if (v1)
    (*v1->_vptr_Layout)(v1, this);
  else
    (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 91))(this);
  (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 12))(this);
}

void vgui::Panel::setFocusNavGroup(vgui::FocusNavGroup* focusNavGroup)
{
  _focusNavGroup = focusNavGroup;
  if (focusNavGroup)
    (*focusNavGroup->_vptr_FocusNavGroup)(focusNavGroup, this);
}

void vgui::Panel::requestFocusPrev()
{
  vgui::FocusNavGroup* v1; // eax

  v1 = _focusNavGroup;
  if (v1)
    (*((void(__cdecl**)(vgui::FocusNavGroup*))v1->_vptr_FocusNavGroup + 1))(_focusNavGroup);
}

void vgui::Panel::requestFocusNext()
{
  vgui::FocusNavGroup* v1; // eax

  v1 = _focusNavGroup;
  if (v1)
    (*((void(__cdecl**)(vgui::FocusNavGroup*))v1->_vptr_FocusNavGroup + 2))(_focusNavGroup);
}

void vgui::Panel::internalFocusChanged(bool lost)
{
  vgui::FocusNavGroup* v2; // eax
  int v3; // esi
  vgui::FocusChangeSignal* v4; // eax

  if (!lost)
  {
    v2 = _focusNavGroup;
    if (v2)
      (*((void(__cdecl**)(vgui::FocusNavGroup*, vgui::Panel* const))v2->_vptr_FocusNavGroup + 3))(v2, this);
  }
  if (_focusChangeSignalDar._count > 0)
  {
    v3 = 0;
    do
    {
      v4 = _focusChangeSignalDar._data[v3++];
      (*v4->_vptr_FocusChangeSignal)(v4, lost, this);
    } while (_focusChangeSignalDar._count > v3);
  }
}

bool vgui::Panel::isAutoFocusNavEnabled()
{
  return _autoFocusNavEnabled;
}

void vgui::Panel::setAutoFocusNavEnabled(bool state)
{
  _autoFocusNavEnabled = state;
}

void vgui::Panel::setBorder(vgui::Border* border)
{
  _border = border;
}

void vgui::Panel::getMinimumSize(int& wide, int& tall)
{
  *(_QWORD*)wide = *(_QWORD*)_minimumSize;
}

void vgui::Panel::setPaintBorderEnabled(bool state)
{
  _paintBorderEnabled = state;
}

void vgui::Panel::setPaintBackgroundEnabled(bool state)
{
  _paintBackgroundEnabled = state;
}

void vgui::Panel::setPaintEnabled(bool state)
{
  _paintEnabled = state;
}

void vgui::Panel::getInset(int& left, int& top, int& right, int& bottom)
{
  vgui::Border* v5; // eax

  v5 = _border;
  if (v5)
  {
    (*((void(__cdecl**)(vgui::Border*))v5->_vptr_Image + 25))(_border);
  }
  else
  {
    *left = 0;
    *top = 0;
    *right = 0;
    *bottom = 0;
  }
}

void vgui::Panel::getPaintSize(int& wide, int& tall)
{
  vgui::Border* v3; // eax
  int v4; // edx
  int left; // [esp+20h] [ebp-1Ch] BYREF
  int top; // [esp+24h] [ebp-18h] BYREF
  int right; // [esp+28h] [ebp-14h] BYREF
  int bottom; // [esp+2Ch] [ebp-10h] BYREF

  v3 = _border;
  if (v3)
  {
    (*((void(__cdecl**)(vgui::Border*, int*, int*, int*, int*))v3->_vptr_Image + 25))(
      v3,
      &left,
      &top,
      &right,
      &bottom);
    v4 = top;
    *wide = _size[0] - (right + left);
    *tall = _size[1] - (bottom + v4);
  }
  else
  {
    *(_QWORD*)wide = *(_QWORD*)_size;
  }
}

void vgui::Panel::setPreferredSize(int wide, int tall)
{
  _preferredSize[0] = wide;
  _preferredSize[1] = tall;
}

void vgui::Panel::getPreferredSize(int& wide, int& tall)
{
  *(_QWORD*)wide = *(_QWORD*)_preferredSize;
}

int vgui::Panel::getWide()
{
  return _size[0];
}

int vgui::Panel::getTall()
{
  return _size[1];
}

bool vgui::Panel::isEnabled()
{
  return _enabled;
}

void vgui::Panel::setEnabled(bool state)
{
  _enabled = state;
}

void vgui::Panel::setBuildGroup(vgui::BuildGroup* buildGroup, const char* panelPersistanceName)
{
  _buildGroup = buildGroup;
  (*((void(__cdecl**)(vgui::BuildGroup*, vgui::Panel* const))buildGroup->_vptr_BuildGroup + 7))(buildGroup, this);
}

bool vgui::Panel::isBuildGroupEnabled()
{
  vgui::BuildGroup* v1; // eax
  bool result; // al

  v1 = _buildGroup;
  if (v1)
    result = (*((int(__cdecl**)(vgui::BuildGroup*))v1->_vptr_BuildGroup + 1))(_buildGroup);
  else
    result = 0;
  return result;
}

void vgui::Panel::removeAllChildren()
{
  _childDar._count = 0;
}

void vgui::Panel::repaintParent()
{
  vgui::Panel* v1; // eax

  v1 = _parent;
  if (v1)
    (*((void(__cdecl**)(vgui::Panel*))v1->_vptr_Panel + 12))(_parent);
}

void vgui::Panel::setAsMouseArena(bool state)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  (*(void(__cdecl**)(int, vgui::Panel* const))(*(_DWORD*)v2 + 64))(v2, this);
}

void vgui::Panel::setBgColor(vgui::Color* p_color)
{
  *(_DWORD*)_bgColor._color = *(_DWORD*)p_color->_color;
  _bgColor._schemeColor = p_color->_schemeColor;
}

void vgui::Panel::setFgColor(vgui::Color* p_color)
{
  *(_DWORD*)_fgColor._color = *(_DWORD*)p_color->_color;
  _fgColor._schemeColor = p_color->_schemeColor;
}

void vgui::Panel::getBgColor(vgui::Color& color)
{
  *(_DWORD*)color->_color = *(_DWORD*)_bgColor._color;
  color->_schemeColor = _bgColor._schemeColor;
}

void vgui::Panel::getFgColor(vgui::Color& color)
{
  *(_DWORD*)color->_color = *(_DWORD*)_fgColor._color;
  color->_schemeColor = _fgColor._schemeColor;
}

void vgui::Panel::getVirtualSize(int& wide, int& tall)
{
  (*((void (**)(void))_vptr_Panel + 3))();
}

void vgui::Panel::setLayoutInfo(vgui::LayoutInfo* layoutInfo)
{
  _layoutInfo = layoutInfo;
}

bool vgui::Panel::isCursorNone()
{
  int v1; // eax
  char v2; // dl

  v1 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 38))(this);
  v2 = 1;
  if (v1)
    v2 = (*(int(__cdecl**)(int))(*(_DWORD*)v1 + 12))(v1) == 1;
  return v2;
}

void vgui::Panel::getBgColor(int& r, int& g, int& b, int& a)
{
  vgui::Color::getColor(&_bgColor, r, g, b, a);
}

void vgui::Panel::getFgColor(int& r, int& g, int& b, int& a)
{
  vgui::Color::getColor(&_fgColor, r, g, b, a);
}

void vgui::Panel::setBgColor(int r, int g, int b, int a)
{
  vgui::Color::setColor(&_bgColor, r, g, b, a);
}

void vgui::Panel::setFgColor(int r, int g, int b, int a)
{
  vgui::Color::setColor(&_fgColor, r, g, b, a);
}

void vgui::Panel::setBgColor(vgui::Scheme::SchemeColor sc)
{
  vgui::Color::setColor(&_bgColor, sc);
}

void vgui::Panel::setFgColor(vgui::Scheme::SchemeColor sc)
{
  vgui::Color::setColor(&_fgColor, sc);
}

void vgui::Panel::getPersistanceText(char* buf, int bufLen)
{
  int x; // [esp+20h] [ebp-1Ch] BYREF
  int y; // [esp+24h] [ebp-18h] BYREF
  int wide; // [esp+28h] [ebp-14h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-10h] BYREF

  (*((void(__cdecl**)(vgui::Panel* const, int*, int*, int*, int*))_vptr_Panel + 5))(
    this,
    &x,
    &y,
    &wide,
    tall);
  sprintf(buf, "->setBounds(%d,%d,%d,%d);\n", x, y, wide, tall[0]);
}

void vgui::Panel::invalidateLayout(bool layoutNow)
{
  _needsLayout = 1;
  if (layoutNow)
    (*((void (**)(void))_vptr_Panel + 92))();
}

void vgui::Panel::setAsMouseCapture(bool state)
{
  int v2; // eax

  v2 = (*((int(__cdecl**)(vgui::Panel* const))_vptr_Panel + 83))(this);
  if (state)
    (*(void(__cdecl**)(int, vgui::Panel* const))(*(_DWORD*)v2 + 56))(v2, this);
  else
    (*(void(__cdecl**)(int, _DWORD))(*(_DWORD*)v2 + 56))(v2, 0);
}

void vgui::Panel::paintTraverse(bool repaint)
{
  bool v3; // cc
  int v4; // edi
  vgui::Panel* v5; // eax
  vgui::SurfaceBase* v6; // eax
  vgui::Border* v7; // eax

  if (_visible)
  {
    if (_needsRepaint)
      repaint = 1;
    v3 = _clipRect[2] <= _clipRect[0];
    _needsRepaint = 0;
    if (v3 || _clipRect[3] <= _clipRect[1])
    {
      repaint = 0;
    }
    else if (repaint && (_paintBorderEnabled || _paintBackgroundEnabled || _paintEnabled))
    {
      (*((void(__cdecl**)(vgui::SurfaceBase*, vgui::Panel* const, int))_surfaceBase->_vptr_SurfaceBase + 32))(
        _surfaceBase,
        this,
        1);
      v7 = _border;
      if (v7 && _paintBorderEnabled)
        (*((void(__cdecl**)(vgui::Border*, vgui::Panel* const))v7->_vptr_Image + 23))(v7, this);
      if (_paintBackgroundEnabled)
        (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 111))(this);
      if (_paintEnabled)
        (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 112))(this);
      (*((void(__cdecl**)(vgui::SurfaceBase*, vgui::Panel* const))_surfaceBase->_vptr_SurfaceBase + 33))(
        _surfaceBase,
        this);
    }
    if (_childDar._count > 0)
    {
      v4 = 0;
      do
      {
        v5 = _childDar._data[v4++];
        (*((void(__cdecl**)(vgui::Panel*, bool))v5->_vptr_Panel + 110))(v5, repaint);
      } while (v4 < _childDar._count);
    }
    if (repaint
      && (*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
      && (*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 42))(this))
    {
      (*((void(__cdecl**)(vgui::SurfaceBase*, vgui::Panel* const, _DWORD))_surfaceBase->_vptr_SurfaceBase + 32))(
        _surfaceBase,
        this,
        0);
      (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 113))(this);
      (*((void(__cdecl**)(vgui::SurfaceBase*, vgui::Panel* const))_surfaceBase->_vptr_SurfaceBase + 33))(
        _surfaceBase,
        this);
    }
    v6 = _surfaceBase;
    if (v6->_needsSwap && this == (vgui::Panel* const)(*v6->_vptr_SurfaceBase)(_surfaceBase))
    {
      _surfaceBase->_needsSwap = 0;
      (*((void(__cdecl**)(vgui::SurfaceBase*))_surfaceBase->_vptr_SurfaceBase + 31))(_surfaceBase);
    }
  }
}

void vgui::Panel::solveTraverse()
{
  int v1; // ebx
  vgui::Panel* v2; // eax

  if (_visible)
  {
    (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 109))(this);
    if (_needsLayout)
      (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 92))(this);
    (*((void(__cdecl**)(vgui::Panel* const))_vptr_Panel + 109))(this);
    if (_childDar._count > 0)
    {
      v1 = 0;
      do
      {
        v2 = _childDar._data[v1++];
        (*((void(__cdecl**)(vgui::Panel*))v2->_vptr_Panel + 88))(v2);
      } while (v1 < _childDar._count);
    }
  }
}

void vgui::Panel::internalKeyFocusTicked()
{
  int v1; // esi
  vgui::InputSignal* v2; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v1 = 0;
    do
    {
      v2 = _inputSignalDar._data[v1++];
      (*((void(__cdecl**)(vgui::InputSignal*, vgui::Panel* const))v2->_vptr_InputSignal + 10))(v2, this);
    } while (v1 < _inputSignalDar._count);
  }
}

void vgui::Panel::internalKeyReleased(vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v2 = 0;
    do
    {
      v3 = _inputSignalDar._data[v2++];
      (*((void(__cdecl**)(vgui::InputSignal*, vgui::KeyCode, vgui::Panel* const))v3->_vptr_InputSignal + 9))(
        v3,
        code,
        this);
    } while (v2 < _inputSignalDar._count);
  }
}

void vgui::Panel::internalKeyPressed(vgui::KeyCode code)
{
  int v2; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v2 = 0;
    do
    {
      v3 = _inputSignalDar._data[v2++];
      (*((void(__cdecl**)(vgui::InputSignal*, vgui::KeyCode, vgui::Panel* const))v3->_vptr_InputSignal + 7))(
        v3,
        code,
        this);
    } while (v2 < _inputSignalDar._count);
  }
}

void vgui::Panel::internalMouseWheeled(int delta)
{
  int v2; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v2 = 0;
    do
    {
      v3 = _inputSignalDar._data[v2++];
      (*((void(__cdecl**)(vgui::InputSignal*, int, vgui::Panel* const))v3->_vptr_InputSignal + 6))(v3, delta, this);
    } while (v2 < _inputSignalDar._count);
  }
}

void vgui::Panel::internalMouseReleased(vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this))
  {
    if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
    {
      (*((void(__cdecl**)(vgui::BuildGroup*, vgui::MouseCode, vgui::Panel* const))_buildGroup->_vptr_BuildGroup
        + 10))(
          _buildGroup,
          code,
          this);
    }
    else
    {
      for (i = 0; _inputSignalDar._count > i; ++i)
      {
        v3 = _inputSignalDar._data[i];
        (*((void(__cdecl**)(vgui::InputSignal*, vgui::MouseCode, vgui::Panel* const))v3->_vptr_InputSignal + 5))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalMouseDoublePressed(vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this))
  {
    if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
    {
      (*((void(__cdecl**)(vgui::BuildGroup*, vgui::MouseCode, vgui::Panel* const))_buildGroup->_vptr_BuildGroup
        + 11))(
          _buildGroup,
          code,
          this);
    }
    else
    {
      for (i = 0; _inputSignalDar._count > i; ++i)
      {
        v3 = _inputSignalDar._data[i];
        (*((void(__cdecl**)(vgui::InputSignal*, vgui::MouseCode, vgui::Panel* const))v3->_vptr_InputSignal + 4))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalMousePressed(vgui::MouseCode code)
{
  int i; // edi
  vgui::InputSignal* v3; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this))
  {
    if ((*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this))
    {
      (*((void(__cdecl**)(vgui::BuildGroup*, vgui::MouseCode, vgui::Panel* const))_buildGroup->_vptr_BuildGroup
        + 9))(
          _buildGroup,
          code,
          this);
    }
    else
    {
      for (i = 0; _inputSignalDar._count > i; ++i)
      {
        v3 = _inputSignalDar._data[i];
        (*((void(__cdecl**)(vgui::InputSignal*, vgui::MouseCode, vgui::Panel* const))v3->_vptr_InputSignal + 3))(
          v3,
          code,
          this);
      }
    }
  }
}

void vgui::Panel::internalCursorExited()
{
  int v1; // esi
  vgui::InputSignal* v2; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this)
    && !(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v1 = 0;
    do
    {
      v2 = _inputSignalDar._data[v1++];
      (*((void(__cdecl**)(vgui::InputSignal*, vgui::Panel* const))v2->_vptr_InputSignal + 2))(v2, this);
    } while (v1 < _inputSignalDar._count);
  }
}

void vgui::Panel::internalCursorEntered()
{
  int v1; // esi
  vgui::InputSignal* v2; // eax

  if (!(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 87))(this)
    && !(*((uint8_t(__cdecl**)(vgui::Panel* const))_vptr_Panel + 65))(this)
    && _inputSignalDar._count > 0)
  {
    v1 = 0;
    do
    {
      v2 = _inputSignalDar._data[v1++];
      (*((void(__cdecl**)(vgui::InputSignal*, vgui::Panel* const))v2->_vptr_InputSignal + 1))(v2, this);
    } while (v1 < _inputSignalDar._count);
  }
}

void vgui::Panel::addInputSignal(vgui::InputSignal* s)
{
  int v2; // ecx
  vgui::Dar<vgui::InputSignal*>* v3; // esi
  vgui::InputSignal** v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::InputSignal** v8; // eax
  unsigned int v9; // edi
  _BYTE* v10; // eax
  _WORD* v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::InputSignal** v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = _inputSignalDar._count;
  v3 = &_inputSignalDar;
  if (v2 > 0)
  {
    v4 = _inputSignalDar._data;
    v5 = 0;
    if (s == *v4)
      return;
    while (++v5 != v2)
    {
      if (s == v4[v5])
        return;
    }
  }
  v6 = _inputSignalDar._capacity;
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
    v10 = (_BYTE*)operator new [](v9);
    v14 = (vgui::InputSignal**)v10;
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
        *(_DWORD*)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ((v15 & 4) != 0)
    {
      *(_DWORD*)v11 = 0;
      v11 += 2;
    }
    if ((v15 & 2) != 0)
      *v11++ = 0;
    if ((v15 & 1) != 0)
      *(_BYTE*)v11 = 0;
    v2 = _inputSignalDar._count;
    _inputSignalDar._capacity = v13;
    if (v2 > 0)
    {
      v12 = 0;
      do
      {
        v14[v12] = _inputSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      } while (v12 < v3->_count);
    }
    if (_inputSignalDar._data)
    {
      operator delete [](_inputSignalDar._data);
      v2 = _inputSignalDar._count;
    }
    v8 = v14;
    _inputSignalDar._data = v14;
  }
  else
  {
    v8 = _inputSignalDar._data;
  }
  v8[v2] = s;
  ++_inputSignalDar._count;
}

void vgui::Panel::addRepaintSignal(vgui::RepaintSignal* s)
{
  int v2; // ecx
  vgui::Dar<vgui::RepaintSignal*>* v3; // esi
  vgui::RepaintSignal** v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::RepaintSignal** v8; // eax
  unsigned int v9; // edi
  _BYTE* v10; // eax
  _WORD* v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::RepaintSignal** v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = _repaintSignalDar._count;
  v3 = &_repaintSignalDar;
  if (v2 > 0)
  {
    v4 = _repaintSignalDar._data;
    v5 = 0;
    if (s == *v4)
      return;
    while (++v5 != v2)
    {
      if (s == v4[v5])
        return;
    }
  }
  v6 = _repaintSignalDar._capacity;
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
    v10 = (_BYTE*)operator new [](v9);
    v14 = (vgui::RepaintSignal**)v10;
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
        *(_DWORD*)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ((v15 & 4) != 0)
    {
      *(_DWORD*)v11 = 0;
      v11 += 2;
    }
    if ((v15 & 2) != 0)
      *v11++ = 0;
    if ((v15 & 1) != 0)
      *(_BYTE*)v11 = 0;
    v2 = _repaintSignalDar._count;
    _repaintSignalDar._capacity = v13;
    if (v2 > 0)
    {
      v12 = 0;
      do
      {
        v14[v12] = _repaintSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      } while (v12 < v3->_count);
    }
    if (_repaintSignalDar._data)
    {
      operator delete [](_repaintSignalDar._data);
      v2 = _repaintSignalDar._count;
    }
    v8 = v14;
    _repaintSignalDar._data = v14;
  }
  else
  {
    v8 = _repaintSignalDar._data;
  }
  v8[v2] = s;
  ++_repaintSignalDar._count;
}

void vgui::Panel::addFocusChangeSignal(vgui::FocusChangeSignal* s)
{
  int v2; // ecx
  vgui::Dar<vgui::FocusChangeSignal*>* v3; // esi
  vgui::FocusChangeSignal** v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::FocusChangeSignal** v8; // eax
  unsigned int v9; // edi
  _BYTE* v10; // eax
  _WORD* v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::FocusChangeSignal** v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = _focusChangeSignalDar._count;
  v3 = &_focusChangeSignalDar;
  if (v2 > 0)
  {
    v4 = _focusChangeSignalDar._data;
    v5 = 0;
    if (s == *v4)
      return;
    while (++v5 != v2)
    {
      if (s == v4[v5])
        return;
    }
  }
  v6 = _focusChangeSignalDar._capacity;
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
    v10 = (_BYTE*)operator new [](v9);
    v14 = (vgui::FocusChangeSignal**)v10;
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
        *(_DWORD*)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ((v15 & 4) != 0)
    {
      *(_DWORD*)v11 = 0;
      v11 += 2;
    }
    if ((v15 & 2) != 0)
      *v11++ = 0;
    if ((v15 & 1) != 0)
      *(_BYTE*)v11 = 0;
    v2 = _focusChangeSignalDar._count;
    _focusChangeSignalDar._capacity = v13;
    if (v2 > 0)
    {
      v12 = 0;
      do
      {
        v14[v12] = _focusChangeSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      } while (v12 < v3->_count);
    }
    if (_focusChangeSignalDar._data)
    {
      operator delete [](_focusChangeSignalDar._data);
      v2 = _focusChangeSignalDar._count;
    }
    v8 = v14;
    _focusChangeSignalDar._data = v14;
  }
  else
  {
    v8 = _focusChangeSignalDar._data;
  }
  v8[v2] = s;
  ++_focusChangeSignalDar._count;
}

void vgui::Panel::setParent(vgui::Panel* newParent)
{
  vgui::Panel* v2; // esi
  vgui::Panel* v3; // eax
  vgui::Dar<vgui::Panel*>* v4; // ebp
  int v5; // ecx
  vgui::Panel** v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  vgui::Panel** v10; // eax
  unsigned int v11; // edi
  _BYTE* v12; // eax
  _WORD* v13; // edi
  int v14; // eax
  int v15; // [esp+14h] [ebp-28h]
  vgui::Panel** v16; // [esp+18h] [ebp-24h]
  unsigned int v17; // [esp+1Ch] [ebp-20h]

  v2 = newParent;
  v3 = _parent;
  if (v3)
    (*((void(__cdecl**)(vgui::Panel*, vgui::Panel* const))v3->_vptr_Panel + 19))(v3, this);
  if (newParent)
  {
    _parent = newParent;
    v4 = &newParent->_childDar;
    v5 = newParent->_childDar._count;
    if (v5 > 0)
    {
      v6 = newParent->_childDar._data;
      v7 = 0;
      if (this == *v6)
      {
      LABEL_12:
        (*((void(__cdecl**)(vgui::Panel* const, vgui::SurfaceBase*))_vptr_Panel + 90))(this, v2->_surfaceBase);
        return;
      }
      while (++v7 != v5)
      {
        if (this == v6[v7])
          goto LABEL_12;
      }
    }
    v8 = newParent->_childDar._capacity;
    v9 = v5 + 1;
    if (v5 + 1 > v8)
    {
      if (v8 || (v8 = 1, v11 = 4, v9 > 1))
      {
        do
          v8 *= 2;
        while (v9 > v8);
        v11 = 4 * v8;
      }
      v15 = v8;
      v12 = (_BYTE*)operator new [](v11);
      v16 = (vgui::Panel**)v12;
      if (!v12)
        exit(0);
      v17 = v11;
      v13 = v12;
      if (v17 >= 8)
      {
        if (((uint8_t)v12 & 1) != 0)
        {
          *v12 = 0;
          --v17;
          v13 = v12 + 1;
        }
        if (((uint8_t)v13 & 2) != 0)
        {
          *v13++ = 0;
          v17 -= 2;
        }
        if (((uint8_t)v13 & 4) != 0)
        {
          *(_DWORD*)v13 = 0;
          v13 += 2;
          v17 -= 4;
        }
        memset(v13, 0, 4 * (v17 >> 2));
        v13 += 2 * (v17 >> 2);
        LOBYTE(v17) = v17 & 3;
      }
      if ((v17 & 4) != 0)
      {
        *(_DWORD*)v13 = 0;
        v13 += 2;
      }
      if ((v17 & 2) != 0)
        *v13++ = 0;
      if ((v17 & 1) != 0)
        *(_BYTE*)v13 = 0;
      v5 = newParent->_childDar._count;
      newParent->_childDar._capacity = v15;
      if (v5 > 0)
      {
        v14 = 0;
        do
        {
          v16[v14] = newParent->_childDar._data[v14];
          ++v14;
          v5 = v4->_count;
        } while (v14 < v4->_count);
      }
      if (newParent->_childDar._data)
      {
        operator delete [](newParent->_childDar._data);
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
    v2 = _parent;
    goto LABEL_12;
  }
}

void vgui::Panel::insertChildAt(vgui::Panel* child, int index)
{
  int v3; // edx
  int v4; // ecx
  vgui::Panel** v5; // edi
  int v6; // eax
  vgui::Panel* v7; // eax
  int v8; // eax
  vgui::Dar<vgui::Panel*>* v9; // ebp
  int v10; // ecx
  int v11; // edx
  vgui::Panel** v12; // edi
  unsigned int v13; // edi
  _BYTE* v14; // eax
  _WORD* v15; // edi
  int v16; // edx
  vgui::Panel** v17; // edi
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  int v21; // eax
  _BYTE* v22; // eax
  _WORD* v23; // edi
  int v24; // ecx
  vgui::Panel** v25; // ecx
  int v26; // [esp+10h] [ebp-2Ch]
  int v27; // [esp+10h] [ebp-2Ch]
  vgui::Panel** v28; // [esp+14h] [ebp-28h]
  int v29; // [esp+14h] [ebp-28h]
  unsigned int v30; // [esp+18h] [ebp-24h]
  unsigned int v31; // [esp+18h] [ebp-24h]
  vgui::Panel** v32; // [esp+1Ch] [ebp-20h]

  v3 = index;
  v4 = _childDar._count;
  if (v4 <= 0)
    goto LABEL_6;
  v5 = _childDar._data;
  v6 = 0;
  if (child != *v5)
  {
    while (++v6 != v4)
    {
      if (child == v5[v6])
        return;
    }
  LABEL_6:
    v7 = child->_parent;
    if (v7)
    {
      (*((void(__cdecl**)(vgui::Panel*, vgui::Panel*))v7->_vptr_Panel + 19))(v7, child);
      v3 = index;
    }
    child->_parent = this;
    if (v3 < 0)
      goto LABEL_15;
    v8 = _childDar._count;
    if (v3 > v8)
      goto LABEL_15;
    v9 = &_childDar;
    v10 = v8 + 1;
    if (v3 == v8 || !v8)
    {
      v11 = _childDar._capacity;
      if (v10 <= v11)
      {
        v12 = _childDar._data;
      LABEL_14:
        v12[v8] = child;
        ++_childDar._count;
      LABEL_15:
        (*((void(__cdecl**)(vgui::Panel*, vgui::SurfaceBase*))child->_vptr_Panel + 90))(child, _surfaceBase);
        return;
      }
      if (v11 || (v11 = 1, v13 = 4, v10 > 1))
      {
        do
          v11 *= 2;
        while (v10 > v11);
        v13 = 4 * v11;
      }
      v26 = v11;
      v14 = (_BYTE*)operator new [](v13);
      v28 = (vgui::Panel**)v14;
      if (v14)
      {
        v30 = v13;
        v15 = v14;
        if (v30 >= 8)
        {
          if (((uint8_t)v14 & 1) != 0)
          {
            *v14 = 0;
            --v30;
            v15 = v14 + 1;
          }
          if (((uint8_t)v15 & 2) != 0)
          {
            *v15++ = 0;
            v30 -= 2;
          }
          if (((uint8_t)v15 & 4) != 0)
          {
            *(_DWORD*)v15 = 0;
            v15 += 2;
            v30 -= 4;
          }
          memset(v15, 0, 4 * (v30 >> 2));
          v15 += 2 * (v30 >> 2);
          LOBYTE(v30) = v30 & 3;
        }
        if ((v30 & 4) != 0)
        {
          *(_DWORD*)v15 = 0;
          v15 += 2;
        }
        if ((v30 & 2) != 0)
          *v15++ = 0;
        if ((v30 & 1) != 0)
          *(_BYTE*)v15 = 0;
        v8 = _childDar._count;
        _childDar._capacity = v26;
        if (v8 > 0)
        {
          v16 = 0;
          do
          {
            v28[v16] = _childDar._data[v16];
            ++v16;
            v8 = v9->_count;
          } while (v16 < v9->_count);
        }
        if (_childDar._data)
        {
          operator delete [](_childDar._data);
          v8 = _childDar._count;
        }
        _childDar._data = v28;
        v12 = v28;
        goto LABEL_14;
      }
    LABEL_74:
      exit(0);
    }
    v29 = _childDar._capacity;
    if (v10 > v29)
    {
      if (v29 || (v29 = 1, v20 = 4, v10 > 1))
      {
        v21 = v29;
        do
          v21 *= 2;
        while (v10 > v21);
        v29 = v21;
        v20 = 4 * v21;
      }
      v27 = v3;
      v22 = (_BYTE*)operator new [](v20);
      v3 = v27;
      v32 = (vgui::Panel**)v22;
      if (!v22)
        goto LABEL_74;
      v31 = v20;
      v23 = v22;
      if (v31 >= 8)
      {
        if (((uint8_t)v22 & 1) != 0)
        {
          *v22 = 0;
          --v31;
          v23 = v22 + 1;
        }
        if (((uint8_t)v23 & 2) != 0)
        {
          *v23++ = 0;
          v31 -= 2;
        }
        if (((uint8_t)v23 & 4) != 0)
        {
          *(_DWORD*)v23 = 0;
          v23 += 2;
          v31 -= 4;
        }
        memset(v23, 0, 4 * (v31 >> 2));
        v23 += 2 * (v31 >> 2);
        LOBYTE(v31) = v31 & 3;
      }
      if ((v31 & 4) != 0)
      {
        *(_DWORD*)v23 = 0;
        v23 += 2;
      }
      if ((v31 & 2) != 0)
        *v23++ = 0;
      if ((v31 & 1) != 0)
        *(_BYTE*)v23 = 0;
      v8 = _childDar._count;
      _childDar._capacity = v29;
      if (v8 > 0)
      {
        v24 = 0;
        do
        {
          v32[v24] = _childDar._data[v24];
          ++v24;
          v8 = v9->_count;
        } while (v24 < v9->_count);
      }
      v25 = _childDar._data;
      if (v25)
      {
        operator delete [](v25);
        v8 = _childDar._count;
        v3 = v27;
      }
      _childDar._data = v32;
      v17 = v32;
    }
    else
    {
      v17 = _childDar._data;
    }
    v17[v8] = child;
    v18 = _childDar._count;
    _childDar._count = v18 + 1;
    if (v3 < v18)
    {
      v19 = v18;
      do
      {
        --v18;
        _childDar._data[v19] = _childDar._data[v19 - 1];
        --v19;
      } while (v18 != v3);
    }
    _childDar._data[v3] = child;
    goto LABEL_15;
  }
}

void vgui::Panel::addChild(vgui::Panel* child)
{
  vgui::Panel* v2; // eax
  vgui::Dar<vgui::Panel*>* v3; // ebp
  int v4; // ecx
  vgui::Panel** v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  vgui::Panel** v9; // eax
  unsigned int v10; // edi
  _BYTE* v11; // eax
  _WORD* v12; // edi
  int v13; // eax
  int v14; // [esp+14h] [ebp-28h]
  vgui::Panel** v15; // [esp+18h] [ebp-24h]
  unsigned int v16; // [esp+1Ch] [ebp-20h]

  v2 = child->_parent;
  if (v2)
    (*((void(__cdecl**)(vgui::Panel*, vgui::Panel*))v2->_vptr_Panel + 19))(v2, child);
  child->_parent = this;
  v3 = &_childDar;
  v4 = _childDar._count;
  if (v4 > 0)
  {
    v5 = _childDar._data;
    v6 = 0;
    if (child == *v5)
      goto LABEL_11;
    while (++v6 != v4)
    {
      if (child == v5[v6])
        goto LABEL_11;
    }
  }
  v7 = _childDar._capacity;
  v8 = v4 + 1;
  if (v4 + 1 > v7)
  {
    if (v7 || (v7 = 1, v10 = 4, v8 > 1))
    {
      do
        v7 *= 2;
      while (v8 > v7);
      v10 = 4 * v7;
    }
    v14 = v7;
    v11 = (_BYTE*)operator new [](v10);
    v15 = (vgui::Panel**)v11;
    if (!v11)
      exit(0);
    v16 = v10;
    v12 = v11;
    if (v16 >= 8)
    {
      if (((uint8_t)v11 & 1) != 0)
      {
        *v11 = 0;
        --v16;
        v12 = v11 + 1;
      }
      if (((uint8_t)v12 & 2) != 0)
      {
        *v12++ = 0;
        v16 -= 2;
      }
      if (((uint8_t)v12 & 4) != 0)
      {
        *(_DWORD*)v12 = 0;
        v12 += 2;
        v16 -= 4;
      }
      memset(v12, 0, 4 * (v16 >> 2));
      v12 += 2 * (v16 >> 2);
      LOBYTE(v16) = v16 & 3;
    }
    if ((v16 & 4) != 0)
    {
      *(_DWORD*)v12 = 0;
      v12 += 2;
    }
    if ((v16 & 2) != 0)
      *v12++ = 0;
    if ((v16 & 1) != 0)
      *(_BYTE*)v12 = 0;
    v4 = _childDar._count;
    _childDar._capacity = v14;
    if (v4 > 0)
    {
      v13 = 0;
      do
      {
        v15[v13] = _childDar._data[v13];
        ++v13;
        v4 = v3->_count;
      } while (v13 < v3->_count);
    }
    if (_childDar._data)
    {
      operator delete [](_childDar._data);
      v4 = _childDar._count;
    }
    v9 = v15;
    _childDar._data = v15;
  }
  else
  {
    v9 = _childDar._data;
  }
  v9[v4] = child;
  ++_childDar._count;
LABEL_11:
  (*((void(__cdecl**)(vgui::Panel*, vgui::SurfaceBase*))child->_vptr_Panel + 90))(child, _surfaceBase);
}

void vgui::Panel::init(int x, int y, int wide, int tall)
{
  int (**v6)(...); // eax

  _loc[0] = 0;
  _pos[0] = x;
  _loc[1] = 0;
  _needsRepaint = 0;
  _parent = 0;
  _pos[1] = y;
  _surfaceBase = 0;
  _visible = 1;
  _minimumSize[0] = 0;
  _size[0] = wide;
  _minimumSize[1] = 0;
  _cursor = 0;
  _schemeCursor = scu_arrow;
  _size[1] = tall;
  _border = 0;
  _buildGroup = 0;
  _layoutInfo = 0;
  v6 = _vptr_Panel;
  _layout = 0;
  _needsLayout = 1;
  _focusNavGroup = 0;
  _enabled = 1;
  _paintBorderEnabled = 1;
  _paintBackgroundEnabled = 1;
  _paintEnabled = 1;
  v6[71](this, 1);
  (*((void(__cdecl**)(vgui::Panel* const, int))_vptr_Panel + 72))(this, 8);
  (*((void(__cdecl**)(vgui::Panel* const, int))_vptr_Panel + 52))(this, 1);
}

void vgui::Panel::Panel()
{
  int v1; // eax
  int v2; // edi
  int v3; // edx
  vgui::Panel** v4; // edx
  vgui::InputSignal** v5; // eax
  vgui::InputSignal** v6; // edi
  int v7; // ecx
  int v8; // edx
  vgui::RepaintSignal** v9; // eax
  vgui::RepaintSignal** v10; // edi
  int v11; // edx
  int v12; // edx
  vgui::FocusChangeSignal** v13; // eax
  vgui::FocusChangeSignal** v14; // edi
  int v15; // edx
  int v16; // [esp+2Ch] [ebp-10h]

  _vptr_Panel = (int (**)(...))(&`vtable for'vgui::Panel + 2);
    _childDar._count = 0;
  _childDar._capacity = 0;
  _childDar._data = 0;
  v1 = operator new [](0x10u);
  if (!v1)
    goto LABEL_26;
  *(_DWORD*)v1 = 0;
  *(_DWORD*)(v1 + 4) = 0;
  *(_DWORD*)(v1 + 8) = 0;
  *(_DWORD*)(v1 + 12) = 0;
  v2 = _childDar._count;
  _childDar._capacity = 4;
  if (v2 > 0)
  {
    v3 = 0;
    do
    {
      *(_DWORD*)(v1 + 4 * v3) = _childDar._data[v3];
      ++v3;
    } while (v3 < _childDar._count);
  }
  v4 = _childDar._data;
  if (v4)
  {
    v16 = v1;
    operator delete []((VFontData* const)v4);
    v1 = v16;
  }
  _childDar._data = (vgui::Panel**)v1;
  _inputSignalDar._count = 0;
  _inputSignalDar._capacity = 0;
  _inputSignalDar._data = 0;
  v5 = (vgui::InputSignal**)operator new [](0x10u);
  v6 = v5;
  if (!v5)
    goto LABEL_26;
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v7 = _inputSignalDar._count;
  _inputSignalDar._capacity = 4;
  if (v7 > 0)
  {
    v8 = 0;
    do
    {
      v5[v8] = _inputSignalDar._data[v8];
      ++v8;
    } while (v8 < _inputSignalDar._count);
  }
  if (_inputSignalDar._data)
    operator delete []((VFontData* const)_inputSignalDar._data);
  _inputSignalDar._data = v6;
  _repaintSignalDar._count = 0;
  _repaintSignalDar._capacity = 0;
  _repaintSignalDar._data = 0;
  v9 = (vgui::RepaintSignal**)operator new [](0x10u);
  v10 = v9;
  if (!v9)
    goto LABEL_26;
  *v9 = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v11 = _repaintSignalDar._count;
  _repaintSignalDar._capacity = 4;
  if (v11 > 0)
  {
    v12 = 0;
    do
    {
      v9[v12] = _repaintSignalDar._data[v12];
      ++v12;
    } while (v12 < _repaintSignalDar._count);
  }
  if (_repaintSignalDar._data)
    operator delete []((VFontData* const)_repaintSignalDar._data);
  _focusChangeSignalDar._count = 0;
  _focusChangeSignalDar._capacity = 0;
  _repaintSignalDar._data = v10;
  _focusChangeSignalDar._data = 0;
  v13 = (vgui::FocusChangeSignal**)operator new [](0x10u);
  v14 = v13;
  if (!v13)
    LABEL_26:
  exit(0);
  *v13 = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  _focusChangeSignalDar._capacity = 4;
  if (_focusChangeSignalDar._count > 0)
  {
    v15 = 0;
    do
    {
      v13[v15] = _focusChangeSignalDar._data[v15];
      ++v15;
    } while (v15 < _focusChangeSignalDar._count);
  }
  if (_focusChangeSignalDar._data)
    operator delete []((VFontData* const)_focusChangeSignalDar._data);
  _focusChangeSignalDar._data = v14;
  vgui::Color::Color(&_fgColor);
  vgui::Color::Color(&_bgColor);
  vgui::Panel::init(this, 0, 0, 64, 64);
}

void vgui::Panel::Panel(int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // edx
  int v7; // edx
  vgui::Panel** v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  vgui::InputSignal** v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  vgui::RepaintSignal** v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  vgui::FocusChangeSignal** v20; // edx
  int v21; // [esp+14h] [ebp-28h]
  int v22; // [esp+14h] [ebp-28h]
  int v23; // [esp+14h] [ebp-28h]
  int v24; // [esp+14h] [ebp-28h]

  _vptr_Panel = (int (**)(...))(&`vtable for'vgui::Panel + 2);
    _childDar._count = 0;
  _childDar._capacity = 0;
  _childDar._data = 0;
  v5 = operator new [](0x10u);
  if (!v5)
    goto LABEL_26;
  *(_DWORD*)v5 = 0;
  *(_DWORD*)(v5 + 4) = 0;
  *(_DWORD*)(v5 + 8) = 0;
  *(_DWORD*)(v5 + 12) = 0;
  v6 = _childDar._count;
  _childDar._capacity = 4;
  if (v6 > 0)
  {
    v7 = 0;
    do
    {
      *(_DWORD*)(v5 + 4 * v7) = _childDar._data[v7];
      ++v7;
    } while (v7 < _childDar._count);
  }
  v8 = _childDar._data;
  if (v8)
  {
    v21 = v5;
    operator delete []((VFontData* const)v8);
    v5 = v21;
  }
  _childDar._data = (vgui::Panel**)v5;
  _inputSignalDar._count = 0;
  _inputSignalDar._capacity = 0;
  _inputSignalDar._data = 0;
  v9 = operator new [](0x10u);
  if (!v9)
    goto LABEL_26;
  *(_DWORD*)v9 = 0;
  *(_DWORD*)(v9 + 4) = 0;
  *(_DWORD*)(v9 + 8) = 0;
  *(_DWORD*)(v9 + 12) = 0;
  v10 = _inputSignalDar._count;
  _inputSignalDar._capacity = 4;
  if (v10 > 0)
  {
    v11 = 0;
    do
    {
      *(_DWORD*)(v9 + 4 * v11) = _inputSignalDar._data[v11];
      ++v11;
    } while (v11 < _inputSignalDar._count);
  }
  v12 = _inputSignalDar._data;
  if (v12)
  {
    v22 = v9;
    operator delete []((VFontData* const)v12);
    v9 = v22;
  }
  _inputSignalDar._data = (vgui::InputSignal**)v9;
  _repaintSignalDar._count = 0;
  _repaintSignalDar._capacity = 0;
  _repaintSignalDar._data = 0;
  v13 = operator new [](0x10u);
  if (!v13)
    goto LABEL_26;
  *(_DWORD*)v13 = 0;
  *(_DWORD*)(v13 + 4) = 0;
  *(_DWORD*)(v13 + 8) = 0;
  *(_DWORD*)(v13 + 12) = 0;
  v14 = _repaintSignalDar._count;
  _repaintSignalDar._capacity = 4;
  if (v14 > 0)
  {
    v15 = 0;
    do
    {
      *(_DWORD*)(v13 + 4 * v15) = _repaintSignalDar._data[v15];
      ++v15;
    } while (v15 < _repaintSignalDar._count);
  }
  v16 = _repaintSignalDar._data;
  if (v16)
  {
    v23 = v13;
    operator delete []((VFontData* const)v16);
    v13 = v23;
  }
  _repaintSignalDar._data = (vgui::RepaintSignal**)v13;
  _focusChangeSignalDar._count = 0;
  _focusChangeSignalDar._capacity = 0;
  _focusChangeSignalDar._data = 0;
  v17 = operator new [](0x10u);
  if (!v17)
    LABEL_26:
  exit(0);
  *(_DWORD*)v17 = 0;
  *(_DWORD*)(v17 + 4) = 0;
  *(_DWORD*)(v17 + 8) = 0;
  *(_DWORD*)(v17 + 12) = 0;
  v18 = _focusChangeSignalDar._count;
  _focusChangeSignalDar._capacity = 4;
  if (v18 > 0)
  {
    v19 = 0;
    do
    {
      *(_DWORD*)(v17 + 4 * v19) = _focusChangeSignalDar._data[v19];
      ++v19;
    } while (v19 < _focusChangeSignalDar._count);
  }
  v20 = _focusChangeSignalDar._data;
  if (v20)
  {
    v24 = v17;
    operator delete []((VFontData* const)v20);
    v17 = v24;
  }
  _focusChangeSignalDar._data = (vgui::FocusChangeSignal**)v17;
  vgui::Color::Color(&_fgColor);
  vgui::Color::Color(&_bgColor);
  vgui::Panel::init(this, x, y, wide, tall);
}

