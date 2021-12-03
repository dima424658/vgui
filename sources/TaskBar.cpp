#include <ctime>
#include <cstring>
#include <cstdio>

#include <VGUI_Panel.h>
#include <VGUI_TaskBar.h>
#include <VGUI_RaisedBorder.h>
#include <VGUI_LoweredBorder.h>
#include <VGUI_Button.h>
#include <VGUI_Frame.h>
#include <VGUI_App.h>
#include <VGUI_TickSignal.h>
#include <VGUI_ActionSignal.h>
#include <VGUI_FrameSignal.h>
#include <VGUI_FocusChangeSignal.h>

namespace
{
  class FooClock : public vgui::Panel, public vgui::TickSignal
  {
  private:
    int _hour, _minute, _second;
  public:
    FooClock(int x, int y, int wide, int tall) : vgui::Panel{ x, y, wide, tall } { getApp()->addTickSignal(this); }

    void paintBackground()
    {
      char buf[50];

      if (_hour > 12)
        std::sprintf(buf, "%d:%.2d:%.2d PM", _hour - 12, _minute, _second);
      else
        std::sprintf(buf, "%d:%.2d:%.2d AM", _hour, _minute, _second);

      paintBackground();

      drawSetTextFont(vgui::Scheme::SchemeFont::sf_primary1);
      drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
      drawPrintText(0, 0, buf, std::strlen(buf));
    }

    void ticked()
    {
      auto aclock = std::time(nullptr);

      auto lc = localtime(&aclock);
      if (_hour != lc->tm_hour || _minute != lc->tm_min || _second != lc->tm_sec)
      {
        _second = lc->tm_sec;
        _hour = lc->tm_hour;
        _minute = lc->tm_min;
        repaint();
      }
    }
  };

  class FooTaskBarButtonHandler : public vgui::ActionSignal, public vgui::FrameSignal, public vgui::FocusChangeSignal
  {
  private:
    vgui::Frame* _frame;
    vgui::Button* _button;

  public:
    FooTaskBarButtonHandler(vgui::Frame* frame, vgui::Button* button) : _frame{ frame }, _button{ button } {}
    void closing(vgui::Frame* frame) {}
    void focusChanged(bool lost, vgui::Panel* panel) { _button->setSelected(!lost); }
    void actionPerformed(vgui::Panel* panel) { _frame->setVisible(true);_frame->requestFocus(); }

    void minimizing(vgui::Frame* frame, bool toTray)
    {
      _frame->setVisible(false);
      _frame->getApp()->requestFocus(nullptr);
    }
  };
}

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