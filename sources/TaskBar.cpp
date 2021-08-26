#include <VGUI_TaskBar.h>

#include <VGUI_RaisedBorder.h>
#include <VGUI_LoweredBorder.h>
#include <VGUI_Button.h>
#include <VGUI_Frame.h>

#include "handlers/FooClock.h"
#include "handlers/FooTaskBarButtonHandler.h"

void vgui::TaskBar::performLayout()
{
  int wide, tall;
  int tWide, tTall;
  int x, y;
  int offset = 3;

  getPaintSize(wide, tall);
  _tray->getSize(tWide, tTall);
  _tray->setBounds(wide - tWide - 3, 2, tWide, tall - 4);

  for (auto i = 0; i < _taskButtonDar.getCount(); ++i)
  {
    _taskButtonDar[i]->getBounds(x, y, wide, tall);
    setPos(offset, y);
    offset += wide + 3;
  }
}

void vgui::TaskBar::addFrame(vgui::Frame* frame)
{
  char buf[256];

  _frameDar.addElement(frame);
  frame->getTitle(buf, 256);

  auto button = new vgui::Button{ buf, 2, 2 };
  auto handler = new FooTaskBarButtonHandler{ frame, button };

  button->setParent(this);
  button->addActionSignal(handler);
  frame->addFrameSignal(handler);
  frame->addFocusChangeSignal(handler);
  
  _taskButtonDar.addElement(button);

  invalidateLayout(false);
}

vgui::TaskBar::TaskBar(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  setBorder(new vgui::RaisedBorder);

  _tray = new vgui::Panel{ 100, 0, 120, 26 };
  _tray->setBorder(new vgui::LoweredBorder);
  _tray->setParent(this);
  _tray->addChild(new FooClock{ 25, 2, 85, 20 });
}