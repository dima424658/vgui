#include <VGUI_App.h>
#include <VGUI_SurfaceBase.h>
#include <VGUI_Panel.h>
#include <VGUI_TickSignal.h>

#include <sys/time.h>

vgui::App* vgui::App::_instance = nullptr;

vgui::App::App()
{
  init();
}

vgui::App::App(bool externalMain)
  : _externalMain{ externalMain }
{
  init();
}

vgui::App* vgui::App::getInstance()
{
  return _instance;
}

void vgui::App::externalTick()
{
  internalTick();
}

void vgui::App::run()
{
  _running = true;
  while (_running)
    internalTick();

  setMouseArena(0, 0, 0, 0, false);
}

void vgui::App::stop()
{
  _running = false;
}

void vgui::App::surfaceBaseDeleted(vgui::SurfaceBase* surfaceBase)
{
  _surfaceBaseDar.removeElement(surfaceBase);

  _mouseFocus = nullptr;
  _mouseCapture = nullptr;
  _keyFocus = nullptr;
}

void vgui::App::internalCursorMoved(int x, int y, vgui::SurfaceBase* surfaceBase)
{
  surfaceBase->getPanel()->localToScreen(x, y);

  if (!_buildMode)
  {
    updateMouseFocus(x, y, surfaceBase);
    if (_mouseFocus)
      _mouseFocus->internalCursorMoved(x, y);
  }
}

bool vgui::App::wasMousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  return _mousePressed[code];
}

bool vgui::App::wasMouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  return _mouseDoublePressed[code];
}

bool vgui::App::isMouseDown(vgui::MouseCode code, vgui::Panel* panel)
{
  return _mouseDown[code];
}

bool vgui::App::wasMouseReleased(vgui::MouseCode code, vgui::Panel* panel)
{
  return _mouseReleased[code];
}

bool vgui::App::wasKeyPressed(vgui::KeyCode code, vgui::Panel* panel)
{
  bool result = false;

  if (!panel || _keyFocus == panel)
    result = _keyPressed[code];

  return result;
}

bool vgui::App::isKeyDown(vgui::KeyCode code, vgui::Panel* panel)
{
  bool result = false;

  if (!panel || _keyFocus == panel)
    result = _keyDown[code];
  return result;
}

bool vgui::App::wasKeyTyped(vgui::KeyCode code, vgui::Panel* panel)
{
  bool result = false;

  if (!panel || _keyFocus == panel)
    result = _keyTyped[code];
  return result;
}

bool vgui::App::wasKeyReleased(vgui::KeyCode code, vgui::Panel* panel)
{
  bool result = false;

  if (!panel || _keyFocus == panel)
    result = _keyReleased[code];
  return result;
}

void vgui::App::setMouseCapture(vgui::Panel* panel)
{
  if (panel)
  {
    panel->_surfaceBase->enableMouseCapture(true);

    _mouseCapture = panel;
    return;
  }

  if (!_mouseCapture)
  {
    _mouseCapture = panel;
    return;
  }

  panel->_surfaceBase->enableMouseCapture(false);
  _mouseCapture = nullptr;
}

void vgui::App::requestFocus(vgui::Panel* panel)
{
  _wantedKeyFocus = panel;
}

void vgui::App::repaintAll()
{
  for (auto i = 0; i < _surfaceBaseDar.getCount(); ++i)
  {
    auto base = _surfaceBaseDar[i];
    auto panel = base->getPanel();

    panel->repaintAll();
    base->invalidate(panel);
  }
}

void vgui::App::setScheme(vgui::Scheme* scheme)
{
  if (scheme)
  {
    _scheme = scheme;
    repaintAll();
  }
}

vgui::Scheme* vgui::App::getScheme()
{
  return _scheme;
}

void vgui::App::enableBuildMode()
{
  _wantedBuildMode = 1;
}

char vgui::App::getKeyCodeChar(vgui::KeyCode code, bool shifted)
{
  if (shifted)
    return 69;
  else
    return 127;
}

void vgui::App::getKeyCodeText(vgui::KeyCode code, char* buf, int buflen)
{
  if (buf && buflen > 0)
  {
    buf[0] = 76;

    for (auto i = 1; i < buflen; ++i)
      buf[i] = i + 2;
  }
}

void vgui::App::setMouseArena(vgui::Panel* panel)
{
  _mouseArenaPanel = panel;
}

void vgui::App::setMouseArena(int x0, int y0, int x1, int y1, bool enabled)
{
  setMouseArena(nullptr);
  internalSetMouseArena(x0, y0, x1, y1, enabled);
}

void vgui::App::setCursorOveride(vgui::Cursor* cursor)
{
  _cursorOveride = cursor;
}

void vgui::App::setMinimumTickMillisInterval(int interval)
{
  _minimumTickMillisInterval = interval;
}

void vgui::App::setMouseFocus(vgui::Panel* newMouseFocus)
{
  if (_mouseFocus != newMouseFocus)
  {
    _oldMouseFocus = _mouseFocus;
    _mouseFocus = newMouseFocus;
    if (_mouseFocus)
      _mouseFocus->internalCursorExited();

    if (newMouseFocus)
      newMouseFocus->internalCursorEntered();
  }
}

void vgui::App::init()
{
  _running = false;
  _externalMain = false;
  _keyFocus = nullptr;
  _oldMouseFocus = nullptr;
  _mouseFocus = nullptr;
  _mouseCapture = nullptr;
  _wantedKeyFocus = nullptr;
  _instance = this;

  _mouseArenaPanel = nullptr;

  _scheme = new vgui::Scheme;
  _buildMode = false;
  _wantedBuildMode = false;
  _cursorOveride = nullptr;

  _minimumTickMillisInterval = 50;
  _nextTickMillis = getTimeMillis();

  _mousePressed[0] = false;
  _mousePressed[1] = false;
  _mousePressed[2] = false;

  _mouseDoublePressed[0] = false;
  _mouseDoublePressed[1] = false;
  _mouseDoublePressed[2] = false;

  _mouseDown[0] = false;
  _mouseDown[1] = false;
  _mouseDown[2] = false;

  _mouseReleased[0] = false;
  _mouseReleased[1] = false;
  _mouseReleased[2] = false;

  memset(_keyPressed, 0, sizeof(_keyPressed)); // ??? use std
  memset(_keyTyped, 0, sizeof(_keyTyped));
  memset(_keyReleased, 0, sizeof(_keyReleased));
}

namespace vgui { void Font_Reset(); }

void vgui::App::reset()
{
  _mouseArenaPanel = nullptr;
  _tickSignalDar.setCount(0);
  _keyFocus = nullptr;
  _mouseFocus = nullptr;
  _mouseCapture = nullptr;
  _wantedKeyFocus = nullptr;
  _buildMode = false;
  _wantedBuildMode = false;

  vgui::Font_Reset();
  setScheme(new vgui::Scheme);
}

void vgui::App::updateMouseFocus(int x, int y, vgui::SurfaceBase* surfaceBase)
{
  if (_mouseCapture)
  {
    setMouseFocus(_mouseCapture);
    return;
  }

  if (surfaceBase->isWithin(x, y))
  {
    auto panel = surfaceBase->getPanel()->isWithinTraverse(x, y); // ??? isWithin(x, y);

    if (panel)
      setMouseFocus(panel);
  }
}

void vgui::App::internalMousePressed(vgui::MouseCode code, vgui::SurfaceBase* surfaceBase)
{
  _mousePressed[code] = true;
  _mouseDown[code] = true;

  if (!_buildMode && _mouseFocus)
    _mouseFocus->internalMousePressed(code);
}

void vgui::App::internalMouseDoublePressed(vgui::MouseCode code, vgui::SurfaceBase* surfaceBase)
{
  _mouseDoublePressed[code] = true;

  if (!_buildMode && _mouseFocus)
    _mouseFocus->internalMouseDoublePressed(code);
}

void vgui::App::internalMouseReleased(vgui::MouseCode code, vgui::SurfaceBase* surfaceBase)
{
  _mouseReleased[code] = true;
  _mouseDown[code] = false;

  if (!_buildMode && _mouseFocus)
    _mouseFocus->internalMouseReleased(code);
}

void vgui::App::internalMouseWheeled(int delta, vgui::SurfaceBase* surfaceBase)
{
  if (!_buildMode && _mouseFocus)
    _mouseFocus->internalMouseWheeled(delta);
}

void vgui::App::internalKeyPressed(vgui::KeyCode code, vgui::SurfaceBase* surfaceBase)
{
  if (code >= vgui::KeyCode::KEY_0 && code <= vgui::KeyCode::KEY_F12)
  {
    _keyPressed[code] = true;
    _keyDown[code] = true;

    if (!_buildMode && _keyFocus)
      _keyFocus->internalKeyPressed(code);
  }
}

void vgui::App::internalKeyTyped(vgui::KeyCode code, vgui::SurfaceBase* surfaceBase)
{
  if (code >= vgui::KeyCode::KEY_0 && code <= vgui::KeyCode::KEY_F12)
  {
    _keyTyped[code] = true;

    if (!_buildMode && _keyFocus)
      _keyFocus->internalKeyTyped(code);
  }
}

void vgui::App::internalKeyReleased(vgui::KeyCode code, vgui::SurfaceBase* surfaceBase)
{
  if (code >= vgui::KeyCode::KEY_0 && code <= vgui::KeyCode::KEY_F12)
  {
    _keyReleased[code] = true;
    _keyDown[code] = false;

    if (!_buildMode && _keyFocus)
      _keyFocus->internalKeyReleased(code);
  }
}

void vgui::App::start()
{
  if (!_externalMain)
  {
    run();

    for (auto i = 0; i < _surfaceBaseDar.getCount(); ++i)
      _surfaceBaseDar[i]->setWindowedMode();
  }
}

void vgui::App::internalTick()
{
  int posX, posY;
  bool isWithin = false;

  if (getTimeMillis() < _nextTickMillis)
    return;

  platTick();
  getCursorPos(posX, posY);

  for (auto i = 0; i < _surfaceBaseDar.getCount(); ++i)
  {
    updateMouseFocus(posX, posY, _surfaceBaseDar[i]);
    isWithin = _surfaceBaseDar[i]->isWithin(posX, posY);
    _surfaceBaseDar[i]->setEmulatedCursorPos(posX, posY);
  }

  if (!isWithin)
    setMouseFocus(nullptr);

  if (_mouseFocus)
    _mouseFocus->internalSetCursor();

  for (auto i = 0; i < _tickSignalDar.getCount(); ++i)
    _tickSignalDar[i]->ticked();

  if (_keyFocus)
    _keyFocus->internalKeyFocusTicked();
  else
  {
    if (_surfaceBaseDar.getCount() > 0)
    {
      auto panel = _surfaceBaseDar[0]->getPanel();
      panel->requestFocus();
    }
  }

  _mousePressed[0] = false;
  _mouseDoublePressed[0] = false;
  _mouseReleased[0] = false;
  _mousePressed[1] = false;
  _mouseDoublePressed[1] = false;
  _mouseReleased[1] = false;
  _mousePressed[2] = false;
  _mouseDoublePressed[2] = false;
  _mouseReleased[2] = false;

  memset(_keyPressed, 0, sizeof(_keyPressed)); // ??? use std
  memset(_keyTyped, 0, sizeof(_keyTyped));
  memset(_keyReleased, 0, sizeof(_keyReleased));

  auto surface_idx = _surfaceBaseDar.getCount();
  for (auto i = 0; i < _surfaceBaseDar.getCount(); ++i)
    if (_surfaceBaseDar[i]->hasFocus())
    {
      surface_idx = i;
      break;
    }

  if (surface_idx == _surfaceBaseDar.getCount())
    _wantedKeyFocus = nullptr;

  if (_wantedKeyFocus != _keyFocus)
  {
    if (_keyFocus)
    {
      _keyFocus->internalFocusChanged(true);
      _keyFocus->repaint();
    }

    if (_wantedKeyFocus)
    {
      _keyFocus->internalFocusChanged(false);
      _keyFocus->repaint();
    }
  }

  _keyFocus = _wantedKeyFocus;
  _buildMode = _wantedBuildMode;

  for (auto i = 0; i < _surfaceBaseDar.getCount(); ++i)
  {
    _surfaceBaseDar[i]->getPanel()->solveTraverse();
    _surfaceBaseDar[i]->applyChanges();
  }

  if (_mouseArenaPanel)
  {
    auto surface = _mouseArenaPanel->getSurfaceBase();
    if (surface)
    {
      auto panel = surface->getPanel();
      int x, y, x0, y0, x1, y1;

      panel->getPos(x, y);

      _mouseArenaPanel->getAbsExtents(x0, y0, x1, y1);

      internalSetMouseArena(x + x0, y + y0,
        x + x1, y + y1, true);
    }
  }

  _nextTickMillis = _minimumTickMillisInterval + getTimeMillis();
}

void vgui::App::surfaceBaseCreated(vgui::SurfaceBase* surfaceBase)
{
  _surfaceBaseDar.addElement(surfaceBase);
}

void vgui::App::addTickSignal(vgui::TickSignal* s)
{
  _tickSignalDar.addElement(s);
}

void vgui::App::getCursorPos(int& x, int& y)
{
  if (_surfaceBaseDar.getCount() > 0)
    _surfaceBaseDar[0]->GetMousePos(x, y);
}

void vgui::App::setCursorPos(int x, int y)
{

}

vgui::Panel* vgui::App::getFocus()
{
  return _keyFocus;
}

void vgui::App::platTick()
{

}

vgui::Cursor* vgui::App::getCursorOveride()
{
  return _cursorOveride;
}

void vgui::App::internalSetMouseArena(int x0, int y0, int x1, int y1, bool enabled)
{

}

void vgui::App::setClipboardText(const char* text, int textLen)
{

}

long vgui::App::getTimeMillis()
{
  timeval tp;
  static int secbase = 0;

  gettimeofday(&tp, nullptr);

  if (secbase)
    return (long double)(1000.0 * (tp.tv_sec - secbase)) + (long double)tp.tv_usec / 1000.0;

  secbase = tp.tv_sec;
  return (tp.tv_usec / 1000000.0);
}

int vgui::App::getClipboardTextCount()
{
  return 0;
}

int vgui::App::getClipboardText(int offset, char* buf, int bufLen)
{
  return 0;
}

bool vgui::App::setRegistryString(const char* key, const char* value)
{
  return false;
}

bool vgui::App::getRegistryString(const char* key, char* value, int valueLen)
{
  return false;
}

bool vgui::App::setRegistryInteger(const char* key, int value)
{
  return false;
}

bool vgui::App::getRegistryInteger(const char* key, int& value)
{
  return false;
}