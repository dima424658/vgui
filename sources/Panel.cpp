#include <cmath>
#include <cstdio>

#include <VGUI_Panel.h>
#include <VGUI_SurfaceBase.h>
#include <VGUI_App.h>
#include <VGUI_InputSignal.h>
#include <VGUI_BuildGroup.h>
#include <VGUI_Layout.h>
#include <VGUI_FocusNavGroup.h>
#include <VGUI_FocusChangeSignal.h>
#include <VGUI_Border.h>


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
  _size[0] = std::max(wide, _minimumSize[0]);
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
  if (_surfaceBase)
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
  drawSetTextColor(r, g, b, a);
}

void vgui::Panel::drawSetTextColor(int r, int g, int b, int a)
{
  _surfaceBase->drawSetTextColor(r, g, b, a);
}

void vgui::Panel::drawSetTextPos(int x, int y)
{
  _surfaceBase->drawSetTextPos(x, y);
}

void vgui::Panel::drawPrintText(const char* str, int strlen)
{
  _surfaceBase->drawPrintText(str, strlen);
}

void vgui::Panel::drawPrintText(int x, int y, const char* str, int strlen)
{
  _surfaceBase->drawSetTextPos(x, y);
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
  if (_surfaceBase)
    _surfaceBase->drawSetTextureRGBA(id, rgba, wide, tall);
}

void vgui::Panel::drawSetTexture(int id)
{
  _surfaceBase->drawSetTexture(id);
}

void vgui::Panel::drawTexturedRect(int x0, int y0, int x1, int y1)
{
  _surfaceBase->drawTexturedRect(x0, y0, x1, y1);
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
  _childDar.removeElement(child);
}

void vgui::Panel::setSurfaceBaseTraverse(vgui::SurfaceBase* surfaceBase)
{
  _surfaceBase = surfaceBase;

  for (auto i = 0; i < _childDar.getCount(); ++i)
    _childDar[i]->setSurfaceBaseTraverse(surfaceBase);
}

bool vgui::Panel::wasMousePressed(vgui::MouseCode code)
{
  return getApp()->wasMousePressed(code, this);
}

bool vgui::Panel::wasMouseDoublePressed(vgui::MouseCode code)
{
  return getApp()->wasMouseDoublePressed(code, this);
}

bool vgui::Panel::isMouseDown(vgui::MouseCode code)
{
  return getApp()->isMouseDown(code, this);
}

bool vgui::Panel::wasMouseReleased(vgui::MouseCode code)
{
  return getApp()->wasMouseReleased(code, this);
}

bool vgui::Panel::wasKeyPressed(vgui::KeyCode code)
{
  return getApp()->wasKeyPressed(code, this);
}

bool vgui::Panel::isKeyDown(vgui::KeyCode code)
{
  return getApp()->isKeyDown(code, this);
}

bool vgui::Panel::wasKeyTyped(vgui::KeyCode code)
{
  return getApp()->wasKeyTyped(code, this);
}

bool vgui::Panel::wasKeyReleased(vgui::KeyCode code)
{
  return getApp()->wasKeyReleased(code, this);
}

void vgui::Panel::removeInputSignal(vgui::InputSignal* s)
{
  _inputSignalDar.removeElement(s);
}

void vgui::Panel::removeRepaintSignal(vgui::RepaintSignal* s)
{
  _repaintSignalDar.removeElement(s);
}

void vgui::Panel::internalCursorMoved(int x, int y)
{
  if (isCursorNone())
    return;

  if (isBuildGroupEnabled())
  {
    _buildGroup->cursorMoved(x, y, this);
  }
  else
  {
    screenToLocal(x, y);
    for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
      _inputSignalDar[i]->cursorMoved(x, y, this);
  }
}

void vgui::Panel::internalKeyTyped(vgui::KeyCode code)
{
  if (isBuildGroupEnabled())
  {
    _buildGroup->keyTyped(code, this);
  }
  else
  {
    if (code == vgui::KeyCode::KEY_TAB && isAutoFocusNavEnabled())
    {
      if (isKeyDown(vgui::KeyCode::KEY_LSHIFT) || isKeyDown(vgui::KeyCode::KEY_RSHIFT))
        requestFocusPrev();
      else
        requestFocusNext();
    }

    for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
      _inputSignalDar[i]->keyTyped(code, this);
  }
}

void vgui::Panel::internalSetCursor()
{
  if (_surfaceBase)
  {
    if (isBuildGroupEnabled())
      _surfaceBase->setCursor(_buildGroup->getCursor(this)); // ???
    else
      _surfaceBase->setCursor(getCursor());
  }
}

bool vgui::Panel::isWithin(int x, int y)
{
  screenToLocal(x, y);

  return x >= 0 && y >= 0 && x < _size[0] && y < _size[1];
}

void vgui::Panel::localToScreen(int& x, int& y)
{
  x += _loc[0];
  y += _loc[1];
}

void vgui::Panel::screenToLocal(int& x, int& y)
{
  x -= _loc[0];
  y -= _loc[1];
}

void vgui::Panel::setCursor(vgui::Cursor* cursor)
{
  _schemeCursor = vgui::Scheme::SchemeCursor::scu_user;
  _cursor = cursor;
}

void vgui::Panel::setCursor(vgui::Scheme::SchemeCursor scu)
{
  _cursor = nullptr;
  _schemeCursor = scu;
}

void vgui::Panel::setMinimumSize(int wide, int tall)
{
  _minimumSize[0] = wide;
  _minimumSize[1] = tall;
}

void vgui::Panel::requestFocus()
{
  getApp()->requestFocus(this);
}

bool vgui::Panel::hasFocus()
{
  return this == getApp()->getFocus();
}

void vgui::Panel::getClipRect(int& x0, int& y0, int& x1, int& y1)
{
  x0 = _clipRect[0];
  y0 = _clipRect[1];
  x1 = _clipRect[2];
  y1 = _clipRect[3];
}

int vgui::Panel::getChildCount()
{
  return _childDar.getCount();
}

void vgui::Panel::setLayout(vgui::Layout* layout)
{
  _layout = layout;
  invalidateLayout(false);
}

void vgui::Panel::internalPerformLayout()
{
  _needsLayout = false;

  if (_layout)
    _layout->performLayout(this);
  else
    performLayout();

  repaint();
}

void vgui::Panel::setFocusNavGroup(vgui::FocusNavGroup* focusNavGroup)
{
  _focusNavGroup = focusNavGroup;
  if (focusNavGroup)
    _focusNavGroup->addPanel(this);
}

void vgui::Panel::requestFocusPrev()
{
  if (_focusNavGroup)
    _focusNavGroup->requestFocusPrev();
}

void vgui::Panel::requestFocusNext()
{
  if (_focusNavGroup)
    _focusNavGroup->requestFocusNext();
}

void vgui::Panel::internalFocusChanged(bool lost)
{
  if (!lost && _focusNavGroup)
    _focusNavGroup->setCurrentPanel(this);

  for (auto i = 0; i < _focusChangeSignalDar.getCount(); ++i)
    _focusChangeSignalDar[i]->focusChanged(lost, this);
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
  wide = _minimumSize[0];
  tall = _minimumSize[1];
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
  if (_border)
    _border->getInset(left, top, right, bottom);
  else
  {
    left = 0;
    top = 0;
    right = 0;
    bottom = 0;
  }
}

void vgui::Panel::getPaintSize(int& wide, int& tall)
{
  int left, top, right, bottom;

  if (_border)
  {
    getInset(left, top, right, bottom);
    wide = _size[0] - (right + left);
    tall = _size[1] - (bottom + top);
  }
  else
  {
    wide = _size[0];
    tall = _size[1];
  }
}

void vgui::Panel::setPreferredSize(int wide, int tall)
{
  _preferredSize[0] = wide;
  _preferredSize[1] = tall;
}

void vgui::Panel::getPreferredSize(int& wide, int& tall)
{
  wide = _preferredSize[0];
  tall = _preferredSize[1];
}

int vgui::Panel::getWide()
{
  return _size[0];
}

int vgui::Panel::getTall()
{
  return _size[1];
}

vgui::Panel* vgui::Panel::getParent()
{
  return _parent;
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
  _buildGroup->panelAdded(this, panelPersistanceName);
}

bool vgui::Panel::isBuildGroupEnabled()
{
  if (_buildGroup)
    return _buildGroup->isEnabled();
  else
    return false;
}

void vgui::Panel::removeAllChildren()
{
  _childDar.removeAll();
}

void vgui::Panel::repaintParent()
{
  if (_parent)
    _parent->repaint();
}

void vgui::Panel::setAsMouseArena(bool state)
{
  getApp()->setMouseArena(this);
}

void vgui::Panel::setBgColor(vgui::Color p_color)
{
  _bgColor = p_color;
}

void vgui::Panel::setFgColor(vgui::Color p_color)
{
  _fgColor = p_color;
}

void vgui::Panel::getBgColor(vgui::Color& color)
{
  color = _bgColor;
}

void vgui::Panel::getFgColor(vgui::Color& color)
{
  color = _fgColor;
}

void vgui::Panel::getVirtualSize(int& wide, int& tall)
{
  getSize(wide, tall);
}

void vgui::Panel::setLayoutInfo(vgui::LayoutInfo* layoutInfo)
{
  _layoutInfo = layoutInfo;
}

bool vgui::Panel::isCursorNone()
{
  auto cursor = getCursor();
  if (cursor)
    return cursor->getDefaultCursor() == vgui::Cursor::DefaultCursor::dc_none;

  return true;
}

void vgui::Panel::getBgColor(int& r, int& g, int& b, int& a)
{
  _bgColor.getColor(r, g, b, a);
}

void vgui::Panel::getFgColor(int& r, int& g, int& b, int& a)
{
  _fgColor.getColor(r, g, b, a);
}

void vgui::Panel::setBgColor(int r, int g, int b, int a)
{
  _bgColor.setColor(r, g, b, a);
}

void vgui::Panel::setFgColor(int r, int g, int b, int a)
{
  _fgColor.setColor(r, g, b, a);
}

void vgui::Panel::setBgColor(vgui::Scheme::SchemeColor sc)
{
  _bgColor.setColor(sc);
}

void vgui::Panel::setFgColor(vgui::Scheme::SchemeColor sc)
{
  _fgColor.setColor(sc);
}

void vgui::Panel::getPersistanceText(char* buf, int bufLen)
{
  int x, y;
  int wide, tall;

  getBounds(x, y, wide, tall);
  std::sprintf(buf, "->setBounds(%d,%d,%d,%d);\n", x, y, wide, tall);
}

void vgui::Panel::invalidateLayout(bool layoutNow)
{
  _needsLayout = true;
  if (layoutNow)
    internalPerformLayout();
}

void vgui::Panel::setAsMouseCapture(bool state)
{
  if (state)
    getApp()->setMouseCapture(this);
  else
    getApp()->setMouseCapture(nullptr);
}

void vgui::Panel::paintTraverse(bool repaint)
{
  if (_visible)
  {
    if (_needsRepaint)
      repaint = true;

    _needsRepaint = false;
    if (_clipRect[2] <= _clipRect[0] || _clipRect[3] <= _clipRect[1])
      repaint = false;
    else if (repaint && (_paintBorderEnabled || _paintBackgroundEnabled || _paintEnabled))
    {
      _surfaceBase->pushMakeCurrent(this, true);

      if (_border && _paintBorderEnabled)
        _border->doPaint(this);

      if (_paintBackgroundEnabled)
        paintBackground();

      if (_paintEnabled)
        paint();

      _surfaceBase->popMakeCurrent(this);
    }

    for (auto i = 0; i < _childDar.getCount(); ++i)
      _childDar[i]->paintTraverse(repaint);

    if (repaint && isBuildGroupEnabled() && hasFocus())
    {
      _surfaceBase->pushMakeCurrent(this, false);
      paintBuildOverlay();
      _surfaceBase->popMakeCurrent(this);
    }

    if (_surfaceBase->_needsSwap && _surfaceBase->getPanel() == this)
    {
      _surfaceBase->_needsSwap = false;
      _surfaceBase->swapBuffers();
    }
  }
}

void vgui::Panel::solveTraverse()
{
  if (_visible)
  {
    solve();
    if (_needsLayout)
      internalPerformLayout();

    solve();

    for (auto i = 0; i < _childDar.getCount(); ++i)
      _childDar[i]->solveTraverse();
  }
}

void vgui::Panel::internalKeyFocusTicked()
{
  if (isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->keyFocusTicked(this);
}

void vgui::Panel::internalKeyReleased(vgui::KeyCode code)
{
  if (isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->keyReleased(code, this);
}

void vgui::Panel::internalKeyPressed(vgui::KeyCode code)
{
  if (isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->keyPressed(code, this);
}

void vgui::Panel::internalMouseWheeled(int delta)
{
  if (isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->mouseWheeled(delta, this);
}

void vgui::Panel::internalMouseReleased(vgui::MouseCode code)
{
  if (isCursorNone())
    return;

  if (isBuildGroupEnabled())
    _buildGroup->mouseReleased(code, this);
  else
    for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
      _inputSignalDar[i]->mouseReleased(code, this);
}

void vgui::Panel::internalMouseDoublePressed(vgui::MouseCode code)
{
  if (isCursorNone())
    return;

  if (isBuildGroupEnabled())
    _buildGroup->mouseDoublePressed(code, this);
  else
    for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
      _inputSignalDar[i]->mouseDoublePressed(code, this);
}

void vgui::Panel::internalMousePressed(vgui::MouseCode code)
{
  if (isCursorNone())
    return;

  if (isBuildGroupEnabled())
    _buildGroup->mousePressed(code, this);
  else
    for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
      _inputSignalDar[i]->mousePressed(code, this);
}

void vgui::Panel::internalCursorExited()
{
  if (isCursorNone() || isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->cursorExited(this);
}

void vgui::Panel::internalCursorEntered()
{
  if (isCursorNone() || isBuildGroupEnabled())
    return;

  for (auto i = 0; i < _inputSignalDar.getCount(); ++i)
    _inputSignalDar[i]->cursorEntered(this);
}

void vgui::Panel::addInputSignal(vgui::InputSignal* s)
{
  _inputSignalDar.addElement(s);
}

void vgui::Panel::addRepaintSignal(vgui::RepaintSignal* s)
{
  _repaintSignalDar.addElement(s);
}

void vgui::Panel::addFocusChangeSignal(vgui::FocusChangeSignal* s)
{
  _focusChangeSignalDar.addElement(s);
}

void vgui::Panel::setParent(vgui::Panel* newParent)
{
  if (_parent)
    removeChild(this);

  if (newParent)
  {
    _parent = newParent;
    _parent->addChild(this);
    setSurfaceBaseTraverse(_parent->_surfaceBase);
  }
}

void vgui::Panel::insertChildAt(vgui::Panel* child, int index)
{
  if (child->_parent)
    child->_parent->removeChild(child);

  _childDar.insertElementAt(child, index);
  child->setSurfaceBaseTraverse(_surfaceBase);
}

void vgui::Panel::addChild(vgui::Panel* child)
{
  if (child->_parent)
    child->_parent->removeChild(child);

  addChild(child);
  child->setSurfaceBaseTraverse(_surfaceBase);
}

void vgui::Panel::init(int x, int y, int wide, int tall)
{
  _loc[0] = 0;
  _loc[1] = 0;

  _pos[0] = x;
  _pos[1] = y;

  _minimumSize[0] = 0;
  _minimumSize[1] = 0;

  _size[0] = wide;
  _size[1] = tall;

  _needsRepaint = false;
  _parent = nullptr;
  _surfaceBase = nullptr;
  _visible = true;

  _cursor = nullptr;
  _schemeCursor = vgui::Scheme::SchemeCursor::scu_arrow;

  _border = nullptr;
  _buildGroup = nullptr;
  _layoutInfo = nullptr;
  
  _layout = nullptr;
  _needsLayout = true;
  _focusNavGroup = nullptr;
  _enabled = true;
  _paintBorderEnabled = true;
  _paintBackgroundEnabled = true;
  _paintEnabled = true;
  setFgColor(vgui::Scheme::SchemeColor::sc_black);
  setBgColor(vgui::Scheme::SchemeColor::sc_secondary3);
  setAutoFocusNavEnabled(true);
}

vgui::Panel::Panel()
{
  vgui::Panel::init(0, 0, 64, 64);
}

vgui::Panel::Panel(int x, int y, int wide, int tall)
{
  vgui::Panel::init(x, y, wide, tall);
}