#include <VGUI_Desktop.h>

#include <VGUI_TaskBar.h>
#include <VGUI_DesktopIcon.h>
#include <VGUI_MiniApp.h>
#include <VGUI_Frame.h>

void vgui::Desktop::iconActivated(vgui::DesktopIcon* icon)
{
  auto frame = icon->getMiniApp()->createInstance();
  if (frame)
  {
    frame->setPos(_cascade[0], _cascade[1]);
    frame->setParent(_foreground);
    _taskBar->addFrame(frame);
    frame->requestFocus();

    _cascade[0] += 25;
    _cascade[1] += 50;
    if (_cascade[1] > 400)
    {
      _cascade[0] = 50;
      _cascade[1] = 50;
    }
  }
}

void vgui::Desktop::arrangeIcons()
{
  int offsetX = 15, offsetY = 10;

  for (auto i = 0; i < _desktopIconDar.getCount(); ++i)
  {
    offsetY += 60;
    _desktopIconDar[i]->setPos(offsetX, offsetY);

    if (offsetY > 340)
    {
      offsetX += 50;
      offsetY = 10;
    }
  }
}

void vgui::Desktop::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);

  getPaintSize(wide, tall);
  _background->setBounds(0, 0, wide, tall - 36);
  _foreground->setBounds(0, 0, wide, tall - 36);
  _taskBar->setBounds(0, tall - 36, wide, 36);
}

void vgui::Desktop::addIcon(vgui::DesktopIcon* icon)
{
  icon->setDesktop(this);
  icon->setParent(_foreground);
  icon->setPos(10, 10);

  _desktopIconDar.addElement(icon);
}

vgui::Desktop::Desktop(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _cascade{ 50, 50 }
{
  setBgColor(0, 128, 128, 0);
  setPaintBorderEnabled(false);
  setPaintBackgroundEnabled(false);
  setPaintEnabled(false);

  _background = new vgui::Panel{ 0, 0, wide, tall - 36 };
  _background->setParent(this);
  _background->setBgColor(0, 128, 128, 0);

  _foreground = new vgui::Panel{ 0, 0, wide, tall - 36 };
  _foreground->setPaintBorderEnabled(false);
  _foreground->setPaintBackgroundEnabled(false);
  _foreground->setPaintEnabled(false);
  _foreground->setParent(this);

  _taskBar = new vgui::TaskBar{ 0, tall - 36, wide, 36 };
  _taskBar->setParent(this);
}

vgui::Panel* vgui::Desktop::getBackground()
{
  return _background;
}

vgui::Panel* vgui::Desktop::getForeground()
{
  return _foreground;
}