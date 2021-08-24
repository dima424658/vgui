#include "FooHandler.h"

#include <VGUI_App.h>

void handlers::FooHandler::cursorMoved(int x, int y, vgui::Panel *panel)
{
  auto app = panel->getApp();

  if (_dragging)
  {
    app->getCursorPos(x, y);

    _desktopIcon->setPos(
        _dragOrgPos[0] + x - _dragStart[0],
        _dragOrgPos[1] + y - _dragStart[1]);

    auto parent = _desktopIcon->getParent();
    if (parent)
      parent->requestFocusPrev();
  }
}

void handlers::FooHandler::mousePressed(vgui::MouseCode code, vgui::Panel *panel)
{
  auto app = panel->getApp();

  app->getCursorPos(_dragStart[0], _dragStart[1]);
  app->setMouseCapture(panel);

  _desktopIcon->getPos(_dragOrgPos[0], _dragOrgPos[1]);
  _desktopIcon->requestFocus();
}

void handlers::FooHandler::mouseDoublePressed(vgui::MouseCode code, vgui::Panel *panel)
{
  _desktopIcon->doActivate();
}

void handlers::FooHandler::mouseReleased(vgui::MouseCode code, vgui::Panel *panel)
{
  auto app = panel->getApp();

  _dragging = 0;
  app->setMouseCapture(nullptr);
}

void handlers::FooHandler::cursorEntered(vgui::Panel *panel) {}
void handlers::FooHandler::cursorExited(vgui::Panel *panel) {}
void handlers::FooHandler::mouseWheeled(int delta, vgui::Panel *panel) {}
void handlers::FooHandler::keyPressed(vgui::KeyCode code, vgui::Panel *panel) {}
void handlers::FooHandler::keyTyped(vgui::KeyCode code, vgui::Panel *panel) {}
void handlers::FooHandler::keyReleased(vgui::KeyCode code, vgui::Panel *panel) {}
void handlers::FooHandler::keyFocusTicked(vgui::Panel *panel) {}