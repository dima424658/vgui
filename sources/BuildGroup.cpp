#include <VGUI_BuildGroup.h>

#include <VGUI_Cursor.h>
#include <VGUI_Panel.h>
#include <VGUI_App.h>
#include <VGUI_ChangeSignal.h>
#include <VGUI_Label.h>
#include <VGUI_LineBorder.h>

vgui::BuildGroup::BuildGroup()
    : _enabled{true},
      _snapX{4},
      _snapY{4},
      _currentPanel{nullptr},
      _dragging{false}
{
  _cursor_sizenwse = new vgui::Cursor{vgui::Cursor::DefaultCursor::dc_sizenwse};
  _cursor_sizenesw = new vgui::Cursor{vgui::Cursor::DefaultCursor::dc_sizenesw};
  _cursor_sizewe = new vgui::Cursor{vgui::Cursor::DefaultCursor::dc_sizewe};
  _cursor_sizens = new vgui::Cursor{vgui::Cursor::DefaultCursor::dc_sizens};
  _cursor_sizeall = new vgui::Cursor{vgui::Cursor::DefaultCursor::dc_sizeall};
}

void vgui::BuildGroup::setEnabled(bool state)
{
  if (_enabled != state)
  {
    if (_currentPanel)
    {
      copyPropertiesToClipboard();
      _currentPanel = nullptr;
    }
    _enabled = state;
  }
}

bool vgui::BuildGroup::isEnabled()
{
  return _enabled;
}

void vgui::BuildGroup::cursorMoved(int x, int y, vgui::Panel *panel)
{
  if (_dragging)
  {
    panel->getApp()->getCursorPos(x, y);
    if (_dragMouseCode == MOUSE_RIGHT)
      panel->setSize(x - _dragStartCursorPos[0], y - _dragStartCursorPos[1]);
    else
      panel->setPos(_dragStartPanelPos[0] + x - _dragStartCursorPos[0],
                    _dragStartPanelPos[1] + y - _dragStartCursorPos[1]);

    applySnap(panel);
    panel->repaintParent();
  }
}

void vgui::BuildGroup::mouseReleased(vgui::MouseCode code, vgui::Panel *panel)
{
  _dragging = false;
  panel->getApp()->setMouseCapture(nullptr);
}

void vgui::BuildGroup::keyTyped(vgui::KeyCode code, vgui::Panel *panel) // ???
{
  return;

  char ctrl = 1;
  int x, y;
  int wide, tall;

  if (!panel->isKeyDown(vgui::KeyCode::KEY_LSHIFT))
    ctrl = !panel->isKeyDown(vgui::KeyCode::KEY_RSHIFT);

  int a, b;

  if (code > KEY_LEFT)
    if (code == KEY_DOWN)
    {
      a = _snapY;
      b = 0;
    }
    else
    {
      if (code != KEY_RIGHT)
        return;
      a = _snapX;
      b = 0;
    }

  if (code != KEY_C)
  {
    if (code != KEY_UP)
      return;
    a = 0;
    b = -_snapY;
  }

  if (code == KEY_LEFT)
  {
    a = 0;
    b = -_snapX;
  }

  if (a || b)
  {
    panel->getBounds(x, y, wide, tall);
    if (ctrl)
      panel->setSize(wide + a, tall + b);
    else
      panel->setPos(x + a, y + b);

    applySnap(panel);
    panel->repaint();

    auto parent = panel->getParent();
    if (parent)
      parent->repaint();
  }

  if (panel->isKeyDown(vgui::KeyCode::KEY_LCONTROL) || !panel->isKeyDown(vgui::KeyCode::KEY_RCONTROL))
    copyPropertiesToClipboard();
}

void vgui::BuildGroup::applySnap(vgui::Panel *panel)
{
  int x;
  int y;
  int wide;
  int tall;

  panel->getBounds(x, y, wide, tall);

  x = x / _snapX * _snapX; // ???
  y = _snapY * (y / _snapY);

  panel->setPos(x, y);
  panel->setSize(
      (wide + x) / _snapX * _snapX - x,
      (y + tall) / _snapY * _snapY - y);
}

void vgui::BuildGroup::fireCurrentPanelChangeSignal()
{
  for (auto i = 0; i < _currentPanelChangeSignalDar.getCount(); ++i)
    _currentPanelChangeSignalDar[i]->valueChanged(nullptr);
}

void vgui::BuildGroup::copyPropertiesToClipboard()
{
  const char *src;
  char text[32768];
  char buf[512];

  text[0] = 0;

  for (auto i = 0; i < _panelDar.getCount(); ++i)
  {
    _panelDar[i]->getPersistanceText(buf, 512);

    src = _panelNameDar[i];

    strcat(text, src);
    strcat(text, buf);
  }

  vgui::App::getInstance()->setClipboardText(text, strlen(text));
  vgui::vgui_printf("Copied to clipboard\n");
}

void vgui::BuildGroup::mousePressed(vgui::MouseCode code, vgui::Panel *panel)
{
  int lx, ly;
  int x, y;

  if (code == MOUSE_RIGHT)
  {
    panel->getApp()->getCursorPos(lx, ly);

    panel = new vgui::Label{"Label", lx, ly, 0, 0};
    panel->setBorder(new vgui::LineBorder);
    panel->setParent(panel);
    panel->setBuildGroup(this, "Label");
  }

  _dragMouseCode = code;
  _dragging = true;

  panel->requestFocus();
  panel->getApp()->getCursorPos(x, y);
  _dragStartCursorPos[0] = x;
  _dragStartCursorPos[1] = y;

  panel->getPos(x, y);
  _dragStartPanelPos[0] = x;
  _dragStartPanelPos[1] = y;

  panel->getApp()->setMouseCapture(panel);
  if (_currentPanel != panel)
  {
    _currentPanel = panel;
    copyPropertiesToClipboard(); // ???
  }
}

void vgui::BuildGroup::addCurrentPanelChangeSignal(vgui::ChangeSignal *s)
{
  for(auto i = 0;_currentPanelChangeSignalDar.getCount(); ++i)
      if (s == _currentPanelChangeSignalDar[i])
        return;

  _currentPanelChangeSignalDar.addElement(s);
}

void vgui::BuildGroup::panelAdded(vgui::Panel *panel, const char *panelName)
{
  _panelDar.addElement(panel);
  _panelNameDar.addElement(vgui::vgui_strdup(panelName));
}