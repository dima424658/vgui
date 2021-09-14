#include <VGUI_Frame.h>

#include <VGUI_App.h>
#include <VGUI_Button.h>
#include <VGUI_FrameSignal.h>
#include <VGUI_SurfaceBase.h>

#include "handlers/FooGripSignals.hpp"
#include "handlers/FooMinimizeButtonHandler.hpp"

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
  auto wide = _size[0],
    tall = _size[1];
  auto widea = wide - 1,
    talla = tall - 2;

  auto color1 = vgui::Scheme::SchemeColor::sc_secondary1;
  auto color2 = vgui::Scheme::SchemeColor::sc_secondary2;
  auto color3 = vgui::Scheme::SchemeColor::sc_secondary3;

  if (getSurfaceBase()->hasFocus())
  {
    auto focusPanel = getApp()->getFocus();
    while (focusPanel)
    {
      if (focusPanel == this)
      {
        color1 = vgui::Scheme::SchemeColor::sc_primary1;
        color2 = vgui::Scheme::SchemeColor::sc_primary2;
        color3 = vgui::Scheme::SchemeColor::sc_primary3;
      }

      focusPanel = focusPanel->getParent();
    }
  }

  drawSetColor(color3);
  drawFilledRect(5, 5, wide - 5, 28);

  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  drawFilledRect(120, 10, wide - 70, 11);
  drawFilledRect(120, 15, wide - 70, 16);
  drawFilledRect(120, 20, wide - 70, 21);

  drawSetColor(color1);
  drawFilledRect(120, 12, wide - 70, 13);
  drawFilledRect(120, 17, wide - 70, 18);
  drawFilledRect(120, 22, wide - 70, 23);

  drawSetColor(color1);
  drawFilledRect(1, 0, widea, 5);
  drawFilledRect(1, tall - 5, widea, tall);
  drawFilledRect(0, 1, 5, tall - 1);
  drawFilledRect(wide - 5, 1, wide, tall - 1);
  drawFilledRect(5, 5, 6, 6);
  drawFilledRect(wide - 6, 5, wide - 5, 6);
  drawFilledRect(5, 28, wide - 5, 29);

  drawSetColor(vgui::Scheme::SchemeColor::sc_black);
  drawFilledRect(13, 2, wide - 13, 3);
  drawFilledRect(13, tall - 3, wide - 13, talla);
  drawFilledRect(2, 13, 3, tall - 13);
  drawFilledRect(wide - 3, 13, wide - 2, tall - 13);

  drawSetColor(color2);
  drawFilledRect(14, 3, wide - 12, 4);
  drawFilledRect(14, talla, wide - 12, tall - 1);
  drawFilledRect(3, 14, 4, tall - 12);
  drawFilledRect(wide - 2, 14, widea, tall - 12);

  if (_title)
  {
    drawSetTextFont(vgui::Scheme::SchemeFont::sf_primary1);
    drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
    drawPrintText(28, 7, _title, strlen(_title));
  }
}

void vgui::Frame::getTitle(char* buf, int bufLen)
{
  vgui::vgui_strcpy(buf, bufLen, _title);
}

void vgui::Frame::setTitle(const char* title)
{
  delete[] _title;
  _title = vgui::vgui_strdup(title);

  repaint();
}

void vgui::Frame::setSize(int wide, int tall)
{
  if (getWide() == wide && getTall() == tall)
    return;

  vgui::Panel::setSize(wide, tall);
  getSize(wide, tall);

  _topGrip->setBounds(15, 0, wide - 30, 5);
  _bottomGrip->setBounds(15, tall - 5, wide - 30, 5);
  _leftGrip->setBounds(0, 15, 5, tall - 30);
  _rightGrip->setBounds(wide - 5, 15, 5, tall - 30);
  _topLeftGrip->setBounds(0, 0, 15, 15);
  _topRightGrip->setBounds(wide - 15, 0, 15, 15);
  _bottomLeftGrip->setBounds(0, tall - 15, 15, 15);
  _bottomRightGrip->setBounds(wide - 15, tall - 15, 15, 15);
  _captionGrip->setSize(wide - 10, 23);
  _client->setSize(wide - 10, tall - 34);
  _trayButton->setPos(wide - 85, 8);
  _minimizeButton->setPos(wide - 65, 8);
  _maximizeButton->setPos(wide - 45, 8);
  _closeButton->setPos(wide - 25, 8);

  _client->invalidateLayout(false);
}

void vgui::Frame::addFrameSignal(vgui::FrameSignal* s)
{
  for (auto i = 0; i < _frameSignalDar.getCount(); ++i)
    if (_frameSignalDar[i] == s)
      return;

  _frameSignalDar.addElement(s);
}

vgui::Frame::Frame(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _internal{ true },
  _moveable{ true },
  _sizeable{ true },
  _title{ vgui::vgui_strdup("Untitled") }
{
  repaint();
  setMinimumSize(64, 33);

  _topGrip = new vgui::Panel{ 15, 0, wide - 30, 5 };
  _topGrip->setParent(this);
  _topGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizens });
  _topGrip->addInputSignal(new FooTopGripSignal{ this });
  _topGrip->setPaintBorderEnabled(false);
  _topGrip->setPaintBackgroundEnabled(false);
  _topGrip->setPaintEnabled(false);

  _bottomGrip = new vgui::Panel{ 15, tall - 5, wide - 30, 5 };
  _bottomGrip->setParent(this);
  _bottomGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizens });
  _bottomGrip->addInputSignal(new FooBottomGripSignal{ this });
  _bottomGrip->setPaintBorderEnabled(false);
  _bottomGrip->setPaintBackgroundEnabled(false);
  _bottomGrip->setPaintEnabled(false);

  _leftGrip = new vgui::Panel{ 0, 15, 5, tall - 30 };
  _leftGrip->setParent(this);
  _leftGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizewe });
  _leftGrip->addInputSignal(new FooBottomGripSignal{ this });
  _leftGrip->setPaintBorderEnabled(false);
  _leftGrip->setPaintBackgroundEnabled(false);
  _leftGrip->setPaintEnabled(false);

  _rightGrip = new vgui::Panel{ wide - 5, 15, 5, tall - 30 };
  _rightGrip->setParent(this);
  _rightGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizewe });
  _rightGrip->addInputSignal(new FooBottomGripSignal{ this });
  _rightGrip->setPaintBorderEnabled(false);
  _rightGrip->setPaintBackgroundEnabled(false);
  _rightGrip->setPaintEnabled(false);

  _topLeftGrip = new vgui::Panel{ 0, 0, 15, 15 };
  _topLeftGrip->setParent(this);
  _topLeftGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenwse });
  _topLeftGrip->addInputSignal(new FooTopLeftGripSignal{ this });
  _topLeftGrip->setPaintBorderEnabled(false);
  _topLeftGrip->setPaintBackgroundEnabled(false);
  _topLeftGrip->setPaintEnabled(false);

  _topRightGrip = new vgui::Panel{ wide - 15, 0, 15, 15 };
  _topRightGrip->setParent(this);
  _topRightGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenesw });
  _topRightGrip->addInputSignal(new FooTopRightGripSignal{ this });
  _topRightGrip->setPaintBorderEnabled(false);
  _topRightGrip->setPaintBackgroundEnabled(false);
  _topRightGrip->setPaintEnabled(false);

  _bottomLeftGrip = new vgui::Panel{ 0, tall - 15, 15, 15 };
  _bottomLeftGrip->setParent(this);
  _bottomLeftGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenesw });
  _bottomLeftGrip->addInputSignal(new FooBottomLeftGripSignal{ this });
  _bottomLeftGrip->setPaintBorderEnabled(false);
  _bottomLeftGrip->setPaintBackgroundEnabled(false);
  _bottomLeftGrip->setPaintEnabled(false);

  _bottomRightGrip = new vgui::Panel{ wide - 15, tall - 15, 15, 15 };
  _bottomRightGrip->setParent(this);
  _bottomRightGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenwse });
  _bottomRightGrip->addInputSignal(new FooBottomRightGripSignal{ this });
  _bottomRightGrip->setPaintBorderEnabled(false);
  _bottomRightGrip->setPaintBackgroundEnabled(false);
  _bottomRightGrip->setPaintEnabled(false);

  _captionGrip = new vgui::Panel{ 5, 5, wide - 10, 23 };
  _captionGrip->setParent(this);
  _captionGrip->setCursor(new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizeall });
  _captionGrip->addInputSignal(new FooCaptionGripSignal{ this });
  _captionGrip->setPaintBorderEnabled(false);
  _captionGrip->setPaintBackgroundEnabled(false);
  _captionGrip->setPaintEnabled(false);

  _client = new vgui::Panel{ 5, 29, wide - 10, tall - 34 };
  _client->setParent(this);
  _client->addInputSignal(new FooDraggerSignal{ this });


  _trayButton = new vgui::Button{ ".", wide - 85, 8, 18, 18 };
  _trayButton->setParent(this);

  _minimizeButton = new vgui::Button{ "2", wide - 65, 8, 18, 18 };
  _minimizeButton->setFont(vgui::Scheme::SchemeFont::sf_secondary1);
  _minimizeButton->setParent(this);
  _minimizeButton->addActionSignal(new FooMinimizeButtonHandler{ this });

  _maximizeButton = new vgui::Button{ "1", wide - 45, 8, 18, 18 };
  _maximizeButton->setFont(vgui::Scheme::SchemeFont::sf_secondary1);
  _maximizeButton->setParent(this);

  _closeButton = new vgui::Button{ "r", wide - 25, 8, 18, 18 };
  _closeButton->setFont(vgui::Scheme::SchemeFont::sf_secondary1);
  _closeButton->setParent(this);
  _closeButton->addActionSignal(new FooCloseButtonHandler{ this });

  _menuButton = new vgui::Button{ "s", 7, 8, 18, 18 };
  _menuButton->setFont(vgui::Scheme::SchemeFont::sf_secondary1);
  _menuButton->setParent(this);
}
