#include <detail/FooHandler.h>

#include <VGUI_App.h>

void detail::FooHandler::cursorMoved(int x, int y, vgui::Panel *panel)
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

void detail::FooHandler::cursorEntered(vgui::Panel *panel)
{
}

void detail::FooHandler::cursorExited(vgui::Panel *panel)
{
}

void detail::FooHandler::mousePressed(vgui::MouseCode code, vgui::Panel *panel)
{
  auto app = panel->getApp();

  app->getCursorPos(_dragStart[0], _dragStart[1]);
  app->setMouseCapture(panel);

  _desktopIcon->getPos(_dragOrgPos[0], _dragOrgPos[1]);
  _desktopIcon->requestFocus();
}

void detail::FooHandler::mouseDoublePressed(vgui::MouseCode code, vgui::Panel *panel)
{
  _desktopIcon->doActivate();
}

void detail::FooHandler::mouseReleased(vgui::MouseCode code, vgui::Panel *panel)
{
  auto app = panel->getApp();

  _dragging = 0;
  app->setMouseCapture(nullptr);
}

void detail::FooHandler::mouseWheeled(int delta, vgui::Panel *panel)
{
}

void detail::FooHandler::keyPressed(vgui::KeyCode code, vgui::Panel *panel)
{
}

void detail::FooHandler::keyTyped(vgui::KeyCode code, vgui::Panel *panel)
{
}

void detail::FooHandler::keyReleased(vgui::KeyCode code, vgui::Panel *panel)
{
}

void detail::FooHandler::keyFocusTicked(vgui::Panel *panel)
{
}