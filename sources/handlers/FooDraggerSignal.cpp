#include "FooDraggerSignal.hpp"

#include <VGUI_Frame.h>
#include <VGUI_Panel.h>
#include <VGUI_App.h>
#include <VGUI_MouseCode.h>


FooDraggerSignal::FooDraggerSignal(vgui::Frame* frame)
  : _frame{ frame },
  _dragging{ false },
  _dragStart{ 0, 0 },
  _dragOrgPos{ 0, 0 }, _dragOrgPos2{ 0, 0 },
  _dragOrgSize{ 0, 0 }, _dragOrgSize2{ 0, 0 } {}

void FooDraggerSignal::mouseReleased(vgui::MouseCode code, vgui::Panel* panel)
{
  _dragging = false;

  panel->getApp()->setMouseArena(0, 0, 0, 0, false);
  panel->getApp()->setMouseCapture(nullptr);
}

void FooDraggerSignal::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  int x, y;
  int x0, y0;
  int x1, y1;

  auto frame = dynamic_cast<vgui::Frame*>(panel->getParent());
  if (frame && code == vgui::MouseCode::MOUSE_LEFT)
  {
    _dragging = true;

    frame->getApp()->getCursorPos(x, y);
    _dragStart[0] = x;
    _dragStart[1] = y;

    frame->getPos(_dragOrgPos[0], _dragOrgPos[1]);
    frame->getSize(_dragOrgSize[0], _dragOrgSize[1]);

    auto parent = frame->getParent();
    if (parent)
    {
      parent->getPos(_dragOrgPos2[0], _dragOrgPos2[1]);
      parent->getSize(_dragOrgSize2[0], _dragOrgSize2[1]);
      parent->getAbsExtents(x0, y0, x1, y1);
      parent->getApp()->setMouseArena(x0, y0, x1, y1, true);
      parent->removeChild(frame); // ???
      parent->addChild(frame); // ???
    }

    frame->getApp()->setMouseCapture(panel);
    frame->requestFocus();
    frame->repaintAll();
  }
}

void FooDraggerSignal::cursorMoved(int x, int y, vgui::Panel* panel)
{
  if (_dragging)
  {
    if (panel->getParent())
      panel->getParent()->getApp()->getCursorPos(x, y);

    auto frame = dynamic_cast<vgui::Frame*>(panel->getParent());
    if (frame)
    {
      if (frame->isInternal())
      {
        moved(x - _dragStart[0], y - _dragStart[1], true, frame, frame->getParent());
        if (frame->getParent())
          frame->getParent()->repaint();
      }
      else
      {
        auto parent = frame->getParent();
        if (parent)
        {
          moved(x - _dragStart[0], y - _dragStart[1], true, frame, frame->getParent());
        }

        if (parent->getParent())
          parent->getParent()->repaint();

        parent->repaint();
      }
    }
  }
}

void FooDraggerSignal::moved(int, int, bool, vgui::Panel*, vgui::Panel*) {}
